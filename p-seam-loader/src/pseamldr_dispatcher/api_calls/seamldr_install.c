// Copyright (C) 2023 Intel Corporation                                          
//                                                                               
// Permission is hereby granted, free of charge, to any person obtaining a copy  
// of this software and associated documentation files (the "Software"),         
// to deal in the Software without restriction, including without limitation     
// the rights to use, copy, modify, merge, publish, distribute, sublicense,      
// and/or sell copies of the Software, and to permit persons to whom             
// the Software is furnished to do so, subject to the following conditions:      
//                                                                               
// The above copyright notice and this permission notice shall be included       
// in all copies or substantial portions of the Software.                        
//                                                                               
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS       
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL      
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES             
// OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE            
// OR OTHER DEALINGS IN THE SOFTWARE.                                            
//                                                                               
// SPDX-License-Identifier: MIT
/**
 * @file seamldr_update.c
 * @brief SEAMLDR.UPDATE API handler
 */
#include "../../../include/pseamldr_basic_defs.h"
#include "pseamldr_api_defs.h"
#include "pseamldr_api_handlers.h"
#include "x86_defs/x86_defs.h"
#include "memory_handlers/keyhole_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"
#include "accessors/ia32_accessors.h"
#include "seam_sigstruct.h"
#include "x86_defs/msr_defs.h"
#include "data_structures/pseamldr_data_types.h"
#include "memory_handlers/seam_memory_map.h"
#include "data_structures/seam_vmcs_setup.h"
#include "crypto/intel_key_hash.h"
#include "helpers/elf.h"

static uint64_t required_seam_module_code_region_size(seamldr_params_t* seamldr_params)
{
    UNUSED(seamldr_params);
    return SEAMRR_MODULE_CODE_REGION_SIZE;
}

static bool_t check_seam_sigstruct(seam_sigstruct_t* seam_sigstruct)
{
    // Following checks required for SEAM Sigstruct:
    // - Reserved fields are zero
    // - Key size is supported key size
    // - Exponent is supported exponent
    // - Header Type, Header Length, Header Version, and module type are correct
    // - Module Vendor is 0x8086
    // - All fields marked as "must be" have the specified values/sizes

    IF_RARE (!pseamldr_memcmp_to_zero(seam_sigstruct->reserved0, sizeof(seam_sigstruct->reserved0)) ||
             !pseamldr_memcmp_to_zero(seam_sigstruct->reserved1, sizeof(seam_sigstruct->reserved1)) ||
             !pseamldr_memcmp_to_zero(seam_sigstruct->reserved2, sizeof(seam_sigstruct->reserved2)) ||
             !pseamldr_memcmp_to_zero(seam_sigstruct->reserved3, sizeof(seam_sigstruct->reserved3))
            )
    {
        TDX_ERROR("SEAM sigstruct reserved fields are not zero\n");
        return false;
    }

    IF_RARE (seam_sigstruct->header_type != SEAM_SIGSTRUCT_HEADER_TYPE_GENERIC_FW ||
             seam_sigstruct->header_length != SEAM_SIGSTRUCT_HEADER_LENGTH_DWORDS ||
             seam_sigstruct->header_version != SEAM_SIGSTRUCT_HEADER_VERSION)
    {
        TDX_ERROR("SEAM sigstruct header = 0x%lx or header len = 0x%lx or version = 0x%lx are unsupported\n",
                seam_sigstruct->header_type, seam_sigstruct->header_length, seam_sigstruct->header_version);
        return false;
    }

    IF_RARE (seam_sigstruct->key_size != SEAM_SIGSTRUCT_KEY_SIZE_DWORDS ||
             seam_sigstruct->exponent_size != SEAM_SIGSTRUCT_EXPONENT_SIZE_DWORDS ||
             seam_sigstruct->modulus_size != SEAM_SIGSTRUCT_MODULUS_SIZE_DWORDS)
    {
        TDX_ERROR("SEAM sigstruct key = %d, exponent = %d or modulus size = %d, are unsupported\n",
                seam_sigstruct->key_size, seam_sigstruct->exponent_size, seam_sigstruct->modulus_size);
        return false;
    }

    IF_RARE (seam_sigstruct->module_vendor != SEAM_SIGSTRUCT_INTEL_MODULE_VENDOR ||
             seam_sigstruct->module_type.reserved != 0 ||
             seam_sigstruct->attributes != 0)
    {
        TDX_ERROR("SEAM sigstruct module vendor = 0x%lx, type = 0x%llx or attributes 0x%lx not supported\n",
                seam_sigstruct->module_vendor, seam_sigstruct->module_type.raw, seam_sigstruct->attributes);
        return false;
    }

    IF_RARE (seam_sigstruct->size != SEAM_SIGSTRUCT_SIZE_DWORDS)
    {
        TDX_ERROR("SEAM sigstruct size = 0x%lx is unsupported\n", seam_sigstruct->size);
        return false;
    }

    IF_RARE (seam_sigstruct->cpuid_table_size > SEAM_SIGSTRUCT_MAX_CPUID_TABLE_SIZE)
    {
        TDX_ERROR("SEAM sigstruct unsupported CPUID table size = %d\n", seam_sigstruct->cpuid_table_size);
        return false;
    }

    IF_RARE (seam_sigstruct->exponent != SEAM_SIGSTRUCT_RSA_EXPONENT)
    {
        TDX_ERROR("SEAM sigstruct RSA exponent = 0x%lx is unsupported\n", seam_sigstruct->exponent);
        return false;
    }

    IF_RARE (seam_sigstruct->min_update_hv > seam_sigstruct->module_hv)
    {
        TDX_ERROR("Min update HV %d is larger than module HV %d\n",
                seam_sigstruct->min_update_hv, seam_sigstruct->module_hv);
        return false;
    }

    IF_RARE (seam_sigstruct->gdt_idt_offset % _4KB)
    {
        TDX_ERROR("GDT-IDT table offset is not 4KB aligned - 0x%llx\n", seam_sigstruct->gdt_idt_offset);
        return false;
    }

    IF_RARE (((seam_sigstruct->gdt_idt_offset == 0) && (seam_sigstruct->fault_wrapper_offset != 0)) ||
             ((seam_sigstruct->gdt_idt_offset != 0) && (seam_sigstruct->fault_wrapper_offset == 0)))
    {
        TDX_ERROR("GDT-IDT table offset is 0x%llx, while fault wrapper offset is 0x%llx\n",
                seam_sigstruct->gdt_idt_offset, seam_sigstruct->fault_wrapper_offset);
        return false;
    }

    return true;
}

static bool_t check_cpuid_support(seam_sigstruct_t* seam_sigstruct)
{
    p_sysinfo_table_t* p_sysinfo_table = get_psysinfo_table();

    // - The list of all the CPUs in the platform is in P_SYS_INFO_TABLE.SOCKET_CPUID_TABLE.
    // - The list of all the CPUs that this module can be loaded on is in TMP_SIGSTRUCT.CPUID_TABLE.
    // - The comparison is done with the low 4 bits (stepping number) masked off.

    bool_t cpuid_found = false;

    for (uint32_t i = 0; i < p_sysinfo_table->tot_num_sockets; i++)
    {
        for (uint32_t j = 0; j < seam_sigstruct->cpuid_table_size; j++)
        {
            if ((p_sysinfo_table->socket_cpuid_table[i].raw & ~CPUID_FMS_STEPPING_MASK) ==
                (seam_sigstruct->cpuid_table[j] & ~CPUID_FMS_STEPPING_MASK))
            {
                cpuid_found = true;
                break;
            }
        }

        if (!cpuid_found)
        {
            return false;
        }
        else
        {
            cpuid_found = false;
        }
    }

    return true;
}

static bool_t verify_seam_sigstruct_signature(seam_sigstruct_t* seam_sigstruct)
{
    // Verify the TMP_SIGSTRUCT.SIGNATURE field using RSA-3072 with TMP_SIGSTRUCT.EXPONENT as exponent
    // and TMP_SIGSTRUCT.MODULUS as key. The signature verification will check for EMSA-PKCS1-v1.5
    // format with DER encoding of the "Digest Info" (as in PKCS#1 v2.1).
    // The Digest Info must match the DER encoding for SHA-384.

    // Clear the MODULUS, EXPONENT, and SIGNATURE fields of TMP_SIGSTRUCT,
    // compute the SHA-384 hash of TMP_SIGSTRUCT, and compare the result with the hash value
    // recorded in encoded message from the decrypted SIGNATURE field.

    uint8_t modulus[SIGSTRUCT_MODULUS_SIZE];
    uint32_t exponent;
    uint8_t signature[SIGSTRUCT_SIGNATURE_SIZE];

    pseamldr_memcpy(modulus, sizeof(modulus), seam_sigstruct->modulus, SIGSTRUCT_MODULUS_SIZE);
    pseamldr_memcpy(signature, sizeof(signature), seam_sigstruct->signature, SIGSTRUCT_SIGNATURE_SIZE);
    exponent = seam_sigstruct->exponent;

    uint8_t comp_sigs[sizeof(seam_sigstruct_t) - SEAM_SIGSTRUCT_SIG_SIZE];

    pseamldr_memcpy(comp_sigs, sizeof(comp_sigs), seam_sigstruct, SEAM_SIGSTRUCT_HEADER_SIZE);

    pseamldr_memcpy(&comp_sigs[SEAM_SIGSTRUCT_HEADER_SIZE], sizeof(comp_sigs) - SEAM_SIGSTRUCT_HEADER_SIZE,
                    &seam_sigstruct->seamhash, SEAM_SIGSTRUCT_BODY_SIZE);

    bool_t is_valid = false;

    if (rsa_verify_signature(signature, (const uint8_t*)comp_sigs, sizeof(comp_sigs),
                             exponent, modulus, &is_valid) != 0)
    {
        FATAL_ERROR();
    }

    return is_valid;
}

static api_error_type verify_manifest(pseamldr_data_t* pseamldr_data, seamldr_params_t* seamldr_params,
                                      seam_sigstruct_t* seam_sigstruct)
{
    IF_RARE (!check_seam_sigstruct(seam_sigstruct))
    {
        TDX_ERROR("Incorrect SEAM sigstruct field values!\n");
        return PSEAMLDR_EBADSIG;
    }

    lfence();

    // Compute the SHA-384 hash of the SEAM module signers key (TMP_SIGSTRUCT.MODULUS).
    // If the result is not equal to the INTEL_SIGNER_KEY_HASH constant, then set ERROR_CODE = EBADSIG
    IF_RARE (!compute_and_verify_hash(seam_sigstruct->modulus, SIGSTRUCT_MODULUS_SIZE, intel_key_hash))
    {
        TDX_ERROR("Incorrect SEAM module signers key (modulus)!\n");
        return PSEAMLDR_EBADSIG;
    }

    // If the new module is declared as debug-signed (i.e. TMP_SIGSTRUCT.MODULE_TYPE[31] == 1),
    // but the NPK_ACTIVE bit in SGX_DEBUG_MODE MSR (0x503) is not set, then set ERROR_CODE = EBADSIG
    IF_RARE (seam_sigstruct->module_type.is_debug_signed)
    {
        ia32_sgx_debug_mode_t sgx_debug_mode;
        sgx_debug_mode.raw = ia32_rdmsr(IA32_SGX_DEBUG_MODE_MSR_ADDR);

        if (!sgx_debug_mode.debug_unlock_mode)
        {
            TDX_ERROR("Debug module type is set, but platform is not debug-unlocked\n");
            return PSEAMLDR_EBADSIG;
        }
    }

    uint8_t new_module_svn = seam_sigstruct->seamsvn.seam_minor_svn;
    uint8_t new_module_version = seam_sigstruct->seamsvn.seam_major_svn;

    uint8_t current_module_svn = pseamldr_data->seamextend_snapshot.tee_tcb_svn.seam_minor_svn;
    uint8_t current_module_version = pseamldr_data->seamextend_snapshot.tee_tcb_svn.seam_major_svn;

    // Prevent loading a TDX module with a major version of 0.
    IF_RARE (new_module_version == 0)
    {
        TDX_ERROR("Unable to load TDX module with major version of 0!\n");
        return PSEAMLDR_EUNSUPPORTED;
    }

    // If the requested scenario is UPDATE (i.e. TMP_PARAMS.SCENARIO == 1), do:
    if (seamldr_params->scenario == SEAMLDR_SCENARIO_UPDATE)
    {
        // If the modules are of different TDX versions (i.e if TMP_CURRENT_VERSION != TMP_MODULE_VERSION)
        // then set ERROR_CODE = EUNSUPPORTED and go to "Update End".
        IF_RARE (new_module_version != current_module_version)
        {
            TDX_ERROR("Different module major versions - %d and %d\n", current_module_version, new_module_version);
            return PSEAMLDR_EUNSUPPORTED;
        }

        // If the new module has smaller minor SEAM SVN than the minor SEAM SVN of the currently loaded module
        // (i.e. TMP_MINOR_SVN < TMP_CURRENT_SVN), then set ERROR_CODE = EBADSIG and go to "Update End".
        IF_RARE (new_module_svn < current_module_svn)
        {
            TDX_ERROR("New module has smaller SEAM SVN than of the current module\n");
            return PSEAMLDR_EBADSIG;
        }
    }
    else // SEAMLDR_SCENARIO_LOAD
    {
        bool_t keys_or_caches_dirty = false;

        for (uint32_t i = 0; i < MAX_PKGS; i++)
        {
            keys_or_caches_dirty |= pseamldr_data->key_dirty[i];
        }

        for (uint32_t i = 0; i < MAX_NUM_OF_WBINVD_DOMAINS; i++)
        {
            keys_or_caches_dirty |= pseamldr_data->cache_dirty[i];
        }

        IF_RARE (keys_or_caches_dirty)
        {
            // Set error code to ECLEANUPREQ and fail if current module and new module have different svn major version
            // re-loads across major versions are always potentially a downgrade
            IF_RARE (current_module_version != new_module_version)
            {
                TDX_ERROR("Different module major versions - %d and %d - cleanup required\n",
                          current_module_version, new_module_version);
                return PSEAMLDR_ECLEANUPREQ;
            }

            // Set error code to ECLEANUPREQ and fail if current module's minor svn > new module
            // prevent downgrade
            IF_RARE (new_module_svn < current_module_svn)
            {
                TDX_ERROR("New module has smaller SEAM SVN than of the current module - cleanup required\n");
                return PSEAMLDR_ECLEANUPREQ;
            }
        }
    }

    // Check GDT/IDT table and fault-wrapper table to be within the module size
    uint32_t module_size = (uint32_t)(seamldr_params->num_module_pages * SEAM_MODULE_PAGE_SIZE);
    IF_RARE (seam_sigstruct->gdt_idt_offset &&
             (seam_sigstruct->gdt_idt_offset > (module_size - _4KB)))
    {
        TDX_ERROR("GDT IDT offset 0x%lx doesn't fix the image size 0x%lx\n",
                  seam_sigstruct->gdt_idt_offset, module_size);
        return PSEAMLDR_EBADSIG;
    }

    uint32_t exception_table_size = NUM_OF_EXCEPTION_VECTORS * SEAM_MODULE_EXCEPTION_HANDLER_SIZE;
    IF_RARE (seam_sigstruct->fault_wrapper_offset &&
             (seam_sigstruct->fault_wrapper_offset > (module_size - exception_table_size)))
    {
        TDX_ERROR("Fault wrepper offset 0x%lx doesn't fix the image size 0x%lx\n",
                  seam_sigstruct->fault_wrapper_offset, module_size);
        return PSEAMLDR_EBADSIG;
    }

    // If the new module is restricted to a limited set of CPUs (i.e. TMP_SIGSTRUCT.CPUID_TABLE_SIZE > 0),
    // and it can’t run on all the CPU in the platform, then set ERROR_CODE = EUNSUPCPU
    IF_RARE ((seam_sigstruct->cpuid_table_size > 0) && !check_cpuid_support(seam_sigstruct))
    {
        TDX_ERROR("CPUID list is unsupported\n");
        return PSEAMLDR_EUNSUPCPU;
    }

    // If the new module is declared as production-signed (i.e TMP_SIGSTRUCT.MODULE_TYPE[31] == 0)
    // and is not restricted to a limited set of CPUs (i.e TMP_SIGSTRUCT.CPUID_TABLE_SIZE == 0),
    // then set ERROR_CODE = EBADSIG.
    IF_RARE (!seam_sigstruct->module_type.is_debug_signed && !seam_sigstruct->cpuid_table_size)
    {
        TDX_ERROR("Production module doesn't have CPUID list\n");
        return PSEAMLDR_EBADSIG;
    }

    IF_RARE (!verify_seam_sigstruct_signature(seam_sigstruct))
    {
        TDX_ERROR("Signature verification failed!\n");
        return PSEAMLDR_EBADSIG;
    }

    return PSEAMLDR_SUCCESS;
}

static api_error_type check_seamldr_params(pseamldr_data_t* pseamldr_data, seamldr_params_t* seamldr_params)
{
    // Following checks required for SEAMLDR params:
    // - Reserved fields are zero
    // - The SCENARIO field is either LOAD or UPDATE
    // - All physical address pointers are valid input addresses (as defined for RCX)
    // - The NUM_MODULE_PAGES is within bounds

    IF_RARE (seamldr_params->version != 0)
    {
        TDX_ERROR("Seamldr params version field is incorrect\n");
        return PSEAMLDR_EBADPARAM;
    }
    
    IF_RARE (!pseamldr_memcmp_to_zero(seamldr_params->reserved, sizeof(seamldr_params->reserved)))
    {
        TDX_ERROR("Seamldr params reserved fields are not zero\n");
        return PSEAMLDR_EBADPARAM;
    }

    IF_RARE ((seamldr_params->scenario != SEAMLDR_SCENARIO_LOAD) &&
             (seamldr_params->scenario != SEAMLDR_SCENARIO_UPDATE))
    {
        TDX_ERROR("Seamldr params unknown scenario - %d\n", seamldr_params->scenario);
        return PSEAMLDR_EBADPARAM;
    }

    uint64_t max_module_pages = SEAMLDR_PARAMS_MAX_MODULE_PAGES_V0;

    IF_RARE ((seamldr_params->num_module_pages < SEAMLDR_PARAMS_MIN_MODULE_PAGES) ||
             (seamldr_params->num_module_pages > max_module_pages))
    {
        TDX_ERROR("Seamldr params num of module pages - %d, exceed min/max - %d/%d\n",
                seamldr_params->num_module_pages, SEAMLDR_PARAMS_MIN_MODULE_PAGES, max_module_pages);
        return PSEAMLDR_EBADPARAM;
    }

    lfence();

    for (uint32_t i = 0; i < seamldr_params->num_module_pages; i++)
    {
        IF_RARE (!shared_hpa_check_with_pwr_2_alignment((pa_t)seamldr_params->mod_pages_pa_list[i], _4KB))
        {
            TDX_ERROR("Invalid physical address - 0x%llx of module page %d\n",
                    seamldr_params->mod_pages_pa_list[i], i);
            return PSEAMLDR_EBADPARAM;
        }
    }

    IF_RARE (!shared_hpa_check_with_pwr_2_alignment((pa_t)seamldr_params->sigstruct_pa, _4KB))
    {
        TDX_ERROR("Invalid physical address - 0x%llx of the sigstruct\n", seamldr_params->sigstruct_pa);
        return PSEAMLDR_EBADPARAM;
    }

    // If the requested scenario is update and there’s no current SEAM module
    // (i.e. TMP_PARAMS.SCENARIO == UPDATE && SEAMEXTEND_SNAPSHOT.SEAM_READY == 0),
    IF_RARE ((seamldr_params->scenario == SEAMLDR_SCENARIO_UPDATE) &&
             !pseamldr_data->seamextend_snapshot.seam_ready)
    {
        TDX_ERROR("Seamldr params have update scenario, but there's no current SEAM module\n");
        return PSEAMLDR_EBADPARAM;
    }

    return PSEAMLDR_SUCCESS;
}

static api_error_type initialize_memory_constants(pseamldr_data_t* pseamldr_data, seamldr_params_t* seamldr_params,
                                                 seam_sigstruct_t* seam_sigstruct, memory_constants_t* mem_consts)
{
    p_sysinfo_table_t* p_sysinfo_table = get_psysinfo_table();

    // Generate 13-bit random number for address space linear randomization using RDSEED instruction:
    // - ASLR_RAND = (RDSEED & 0x7FFC) << 32
    // - If no entropy found, then set ERROR_CODE = EUNSPECERR
    uint64_t rdrand, aslr_mask;

    IF_RARE (!ia32_rdrand64(&rdrand))
    {
        TDX_ERROR("Insufficient entropy to generate random ASLR number\n");
        return PSEAMLDR_ENOENTROPY;
    }

    aslr_mask = (rdrand & ASLR_BIT_MASK) << 32;

    // If TMP_MODULE_VERSION == 0 (i.e doesn't support TD Preserving) then set TMP_TD_PRESERVE_SUPPORTED = 0, else 1
    if (seam_sigstruct->seamsvn.seam_major_svn == TDX_MODULE_1_0_MAJOR_SVN)
    {
        mem_consts->td_preserving_supported = false;
    }
    else
    {
        mem_consts->td_preserving_supported = true;
    }

    // Set C_NUM_ADDR_LP = num_addr_lp_per_skt * P_SYS_INFO_TABLE.TOT_NUM_SOCKETS
    mem_consts->num_addressable_lps = get_num_addressable_lps_on_socket() *
                                                         p_sysinfo_table->tot_num_sockets;

    mem_consts->module_physlimit = p_sysinfo_table->p_seamldr_range_base;

    // SEAMCFG region:
    // SYS_INFO_TABLE and SEAM VMCS array
    mem_consts->sysinfo_table_linbase = LINEAR_BASE_SYSINFO_TABLE | aslr_mask;
    // SYSINFO table
    mem_consts->seamcfg_region_size = _4KB;
    mem_consts->vmcs_region_size = _4KB * mem_consts->num_addressable_lps;

    // Code region:
    mem_consts->code_region_size = seamldr_params->num_module_pages * _4KB;
    mem_consts->code_region_linbase = LINEAR_BASE_CODE_REGION | aslr_mask;
    mem_consts->code_region_physbase = mem_consts->module_physlimit -
                                       required_seam_module_code_region_size(seamldr_params);

    // Data region:
    mem_consts->local_data_size = (seam_sigstruct->num_tls_pages + 1) * _4KB;
    mem_consts->global_data_size = (seam_sigstruct->num_global_data_pages + 1) * _4KB;
    mem_consts->data_region_size = (mem_consts->local_data_size * mem_consts->num_addressable_lps) +
                                    mem_consts->global_data_size;

    if (mem_consts->td_preserving_supported)
    {
        mem_consts->handoff_data_size = (seam_sigstruct->num_handoff_pages + 1) * _4KB;
    }
    else
    {
        mem_consts->handoff_data_size = 0;
    }

    mem_consts->data_region_size += mem_consts->handoff_data_size;

    mem_consts->data_region_linbase = LINEAR_BASE_DATA_REGION | aslr_mask;
    mem_consts->data_region_physbase = pseamldr_data->system_info.seamrr_base +
                                       _4KB + mem_consts->vmcs_region_size; // Physical SYSINFO table and VMCS's

    // Stack region:
    mem_consts->data_stack_size = (seam_sigstruct->num_stack_pages + 1) * _4KB;
    mem_consts->shadow_stack_size = _4KB;
    mem_consts->lp_stack_size = mem_consts->shadow_stack_size + mem_consts->data_stack_size;
    mem_consts->stack_region_size  = mem_consts->lp_stack_size * mem_consts->num_addressable_lps;
    mem_consts->stack_region_linbase = LINEAR_BASE_STACK_REGION | aslr_mask;
    mem_consts->stack_region_physbase = mem_consts->code_region_physbase - mem_consts->stack_region_size;

    // Keyhole region:
    uint64_t keyhole_size = (seam_sigstruct->num_keyhole_pages + 1) * _4KB;
    mem_consts->keyhole_region_size = keyhole_size * mem_consts->num_addressable_lps;
    mem_consts->keyhole_region_linbase = LINEAR_BASE_KEYHOLE_REGION | aslr_mask;

    // Keyhole edit region:
    mem_consts->keyedit_region_size = ROUND_UP((mem_consts->keyhole_region_size / _4KB) * sizeof(ia32e_pxe_t), _4KB);
    mem_consts->keyedit_region_linbase = LINEAR_BASE_KEYEDIT_REION | aslr_mask;

    // Page tables:
    mem_consts->paging_structure_size = _4KB * (
            page_tables_needed_to_map(mem_consts->seamcfg_region_size) +
            page_tables_needed_to_map(mem_consts->stack_region_size) +
            page_tables_needed_to_map(mem_consts->data_region_size) +
            page_tables_needed_to_map(mem_consts->keyhole_region_size) +
            page_tables_needed_to_map(mem_consts->keyedit_region_size) +
            page_tables_needed_to_map(mem_consts->code_region_size) +
            1 // One PML4 page table
            );

    // GDT/IDT setup:
    if ((seam_sigstruct->gdt_idt_offset != 0) && (seam_sigstruct->fault_wrapper_offset != 0))
    {
        mem_consts->idt_linbase = mem_consts->code_region_linbase + seam_sigstruct->gdt_idt_offset;
        mem_consts->gdt_linbase = mem_consts->idt_linbase + _2KB;
        mem_consts->fault_wrapper_linbase = mem_consts->code_region_linbase + seam_sigstruct->fault_wrapper_offset;
    }
    else
    {
        mem_consts->idt_linbase = 0;
        mem_consts->gdt_linbase = 0;
    }

    // If the size of the SEAM range part dedicated to SEAM module (i.e. C_MODULE_PHYSLIMIT – SEAMRR.BASE)
    // is smaller than the minimum size required to load and map the new SEAM module
    // and prepare to execution, then set ERROR_CODE = ENOMEM

    uint64_t min_required_size = mem_consts->seamcfg_region_size +
                                 mem_consts->vmcs_region_size +
                                 mem_consts->stack_region_size +
                                 mem_consts->data_region_size +
                                 mem_consts->paging_structure_size +
                                 required_seam_module_code_region_size(seamldr_params);

    IF_RARE ((mem_consts->module_physlimit - pseamldr_data->system_info.seamrr_base) < min_required_size)
    {
        TDX_ERROR("Not enough memory to load, map and prepare new SEAM module\n");
        TDX_ERROR("Available size = 0x%llx , minimal required = 0x%llx\n",
                (mem_consts->module_physlimit - pseamldr_data->system_info.seamrr_base), min_required_size);
        return PSEAMLDR_ENOMEM;
    }

    return PSEAMLDR_SUCCESS;
}

static api_error_type seam_module_load_and_verify(pseamldr_data_t* pseamldr_data, p_sysinfo_table_t* p_sysinfo_table,
                                                  seamldr_params_t* seamldr_params, seam_sigstruct_t* seam_sigstruct,
                                                  memory_constants_t* mem_consts)
{
    uint64_t code_region_start_la;

    code_region_start_la = p_sysinfo_table->module_region_base + pseamldr_data->system_info.seamrr_size
                           - p_sysinfo_table->p_seamldr_range_size
                           - required_seam_module_code_region_size(seamldr_params);

    // Copy and measure SEAM module image pages to the last 2M of the SEAM range
    for (uint64_t i = 0; i < seamldr_params->num_module_pages; i++)
    {
        void* src_page_la = map_pa((void*)seamldr_params->mod_pages_pa_list[i], TDX_RANGE_RO);
        void* dst_page_la = (void*)(code_region_start_la + (i * SEAM_MODULE_PAGE_SIZE));

        pseamldr_memcpy(dst_page_la, SEAM_MODULE_PAGE_SIZE, src_page_la, SEAM_MODULE_PAGE_SIZE);
        free_la(src_page_la);
    }

    // Measure the image (in SEAM range) using SHA-384.
    // If the result is not equal to TMP_SIGSTRUCT.SEAMHASH then set ERROR_CODE = EBADHASH.
    uint32_t module_size = (uint32_t)(seamldr_params->num_module_pages * SEAM_MODULE_PAGE_SIZE);
    IF_RARE (!compute_and_verify_hash((const uint8_t*)code_region_start_la, module_size, seam_sigstruct->seamhash))
    {
        TDX_ERROR("Incorrect SEAM module hash!\n");
        return PSEAMLDR_EBADHASH;
    }

    // Perform ELF relocation on loaded SEAM module
    IF_RARE (!relocate_elf_image(code_region_start_la, module_size, mem_consts->code_region_linbase))
    {
        TDX_ERROR("Seam module image relocation failed\n");
        return PSEAMLDR_EBADPARAM;
    }

    // Fix-up the IDT entries with addresses of the exception wrappers:
    if (seam_sigstruct->gdt_idt_offset != 0)
    {
        for (uint16_t vector = 0; vector < NUM_OF_EXCEPTION_VECTORS; vector++)
        {
            uint64_t exception_handler_linaddr = mem_consts->fault_wrapper_linbase +
                                    (vector * SEAM_MODULE_EXCEPTION_HANDLER_SIZE);
            uint64_t idt_entry_la = code_region_start_la + seam_sigstruct->gdt_idt_offset +
                                    (vector * sizeof(ia32_idt_gate_descriptor));

            ia32_idt_gate_descriptor* idt_entry_p = (ia32_idt_gate_descriptor*)idt_entry_la;
            idt_entry_p->offset_low   = exception_handler_linaddr & BIT_MASK_16BITS;
            idt_entry_p->offset_high  = (exception_handler_linaddr >> 16) & BIT_MASK_16BITS;
            idt_entry_p->offset_upper = (exception_handler_linaddr >> 32) & BIT_MASK_32BITS;
        }
    }

    return PSEAMLDR_SUCCESS;
}

static void setup_system_information(pseamldr_data_t* pseamldr_data, p_sysinfo_table_t* p_sysinfo_table,
                                     memory_constants_t* mem_consts)
{
    // Copy MCHECK information from P_SYS_INFO_TABLE to SYS_INFO_TABLE
    sysinfo_table_t* sysinfo_table = (sysinfo_table_t*)p_sysinfo_table->module_region_base;

    pseamldr_memcpy(sysinfo_table, SYSINFO_TABLE_MCHECK_DATA_SIZE, p_sysinfo_table, SYSINFO_TABLE_MCHECK_DATA_SIZE);

    sysinfo_table->code_rgn_base = mem_consts->code_region_linbase;
    sysinfo_table->code_rgn_size = mem_consts->code_region_size;
    sysinfo_table->data_rgn_base = mem_consts->data_region_linbase;
    sysinfo_table->data_rgn_size = mem_consts->data_region_size;
    sysinfo_table->stack_rgn_base = mem_consts->stack_region_linbase;
    sysinfo_table->stack_rgn_size = mem_consts->stack_region_size;
    sysinfo_table->keyhole_rgn_base = mem_consts->keyhole_region_linbase;
    sysinfo_table->keyhole_rgn_size = mem_consts->keyhole_region_size;
    sysinfo_table->keyhole_edit_rgn_base = mem_consts->keyedit_region_linbase;
    sysinfo_table->keyhole_edit_rgn_size = mem_consts->keyedit_region_size;
    sysinfo_table->num_stack_pages = (mem_consts->data_stack_size / _4KB) - 1;
    sysinfo_table->num_tls_pages = (mem_consts->local_data_size / _4KB) - 1;

    UNUSED(pseamldr_data);
}

static api_error_type init_seam_range_on_update(pseamldr_data_t* pseamldr_data, p_sysinfo_table_t* p_sysinfo_table,
                                                memory_constants_t* mem_consts)
{
    if (pseamldr_data->num_remaining_updates == 0)
    {
        TDX_ERROR("P-SEAMLDR ran out of available updates!\n");
        return PSEAMLDR_EBADCALL;
    }

    sysinfo_table_t* sysinfo_table = (sysinfo_table_t*)p_sysinfo_table->module_region_base;

    // Let HANDOFF_DATA = first 8 bytes at physical address C_DATA_REGION_PHYSBASE
    uint64_t data_region_start_la = p_sysinfo_table->module_region_base +
                                      (mem_consts->data_region_physbase - pseamldr_data->system_info.seamrr_base);

    handoff_data_header_t* handoff_data = (handoff_data_header_t*)data_region_start_la;
    uint64_t handoff_size = handoff_data->size + sizeof(handoff_data_header_t);

    if (!handoff_data->valid ||
        (handoff_size > ((sysinfo_table->num_handoff_pages + 1) * _4KB)) ||
        (handoff_data->hv < pseamldr_data->seam_sigstruct_snapshot.min_update_hv) ||
        (handoff_data->hv > pseamldr_data->seam_sigstruct_snapshot.module_hv))
    {
        TDX_ERROR("Bad handoff data! 0x%llx\n", *((uint64_t*)handoff_data));
        return PSEAMLDR_EBADHANDOFF;
    }

    // Clear the entire module range (using regular REP-STOSB), except handoff data area
    // Using MOVDIR64B is not required here since the area was already initialized
    uint64_t bytes_before_handoff = (uint64_t)handoff_data - (uint64_t)p_sysinfo_table->module_region_base;
    basic_memset_to_zero((void*)p_sysinfo_table->module_region_base, bytes_before_handoff);

    uint64_t module_range_size = mem_consts->module_physlimit - pseamldr_data->system_info.seamrr_base;
    uint64_t bytes_after_handoff = module_range_size - bytes_before_handoff - handoff_size;
    uint64_t range_after_handoff = p_sysinfo_table->module_region_base + bytes_before_handoff + handoff_size;

    basic_memset_to_zero((void*)range_after_handoff, bytes_after_handoff);

    return PSEAMLDR_SUCCESS;
}

_STATIC_INLINE_ void fill_seamextend_structure(seamextend_t* seamextend, seam_sigstruct_t* sigstruct,
                                               bool_t seam_ready)
{
    seamextend->tee_tcb_svn.current_seam_svn = sigstruct->seamsvn.raw;
    pseamldr_memcpy(seamextend->mrseam, sizeof(seamextend->mrseam), sigstruct->seamhash, sizeof(sigstruct->seamhash));
    basic_memset_to_zero(seamextend->mrsigner, sizeof(seamextend->mrsigner));
    seamextend->attributes = 0;
    seamextend->seam_ready = seam_ready ? 1 : 0;
    seamextend->valid = 0x1FF;
}

_STATIC_INLINE_ void zero_seamextend_structure(seamextend_t* seamextend)
{
    seamextend->tee_tcb_svn.current_seam_svn = 0;
    basic_memset_to_zero(seamextend->mrseam, sizeof(seamextend->mrseam));
    basic_memset_to_zero(seamextend->mrsigner, sizeof(seamextend->mrsigner));
    seamextend->attributes = 0;
    seamextend->seam_ready = 0;
    seamextend->valid = 0;
}

static api_error_type install_epilogue(api_error_type flow_status, uint64_t rec_status,
                                       pseamldr_data_t* pseamldr_data, p_sysinfo_table_t* p_sysinfo_table)
{
    IF_COMMON (flow_status == PSEAMLDR_SUCCESS)
    {
        ALIGN(256) seamextend_t seamextend_copy;

        pseamldr_memcpy(&seamextend_copy, sizeof(seamextend_copy),
                        &pseamldr_data->seamextend_snapshot, sizeof(pseamldr_data->seamextend_snapshot));

        fill_seamextend_structure(&seamextend_copy, &pseamldr_data->seam_sigstruct_snapshot, false);

        seamextend_write(&seamextend_copy);

        uint64_t result = SEAMOPS_ENTROPY_ERROR;

        for (uint32_t i = 0; i < MAX_NUMBER_OF_SEAMDB_INSERT_RETRIES; i++)
        {
            TDX_LOG("Attempt number %d to do SEAMBD_INSERT\n", i);
            result = ia32_seamops_seamdb_insert();

            if (result != SEAMOPS_SUCCESS)
            {
                TDX_WARN("SEAMBD_INSERT attempt %d failed! 0x%llx\n", i, result);
            }
            else
            {
                break;
            }
        }

        IF_RARE (result != SEAMOPS_SUCCESS)
        {
            TDX_ERROR("Not enough entropy to insert new SEAMDB entry\n");
            return PSEAMLDR_ENOENTROPY;
        }
        else // SEAMDB is updated
        {
            seamextend_copy.seam_ready = 1;
            seamextend_write(&seamextend_copy);

            sysinfo_table_t* sysinfo_table = (sysinfo_table_t*)p_sysinfo_table->module_region_base;

            sysinfo_table->module_hv     = pseamldr_data->seam_sigstruct_snapshot.module_hv;
            sysinfo_table->min_update_hv = pseamldr_data->seam_sigstruct_snapshot.min_update_hv;
            sysinfo_table->no_downgrade  = pseamldr_data->seam_sigstruct_snapshot.no_downgrade;
            sysinfo_table->num_handoff_pages = pseamldr_data->seam_sigstruct_snapshot.num_handoff_pages;

            pseamldr_data->num_remaining_updates--;
        }

        // Set KEY_DIRTY on all existing packages
        for (uint32_t i = 0; i < MAX_PKGS; i++)
        {
            if (pseamldr_data->max_pkg_lps[i])
            {
                pseamldr_data->key_dirty[i] = true;
            }
        }

        // Set CACHE_DIRTY on all existing cache domains
        for (uint32_t i = 0; i < MAX_NUM_OF_WBINVD_DOMAINS; i++)
        {
            if (pseamldr_data->max_domain_lps[i])
            {
                pseamldr_data->cache_dirty[i] = true;
            }
        }

        // Set NEXT_BLOCK_TO_FLUSH to all 0's
        basic_memset_to_zero(pseamldr_data->next_block_to_flush, sizeof(pseamldr_data->next_block_to_flush));
        // Set NEXT_KID_TO_CONFIG to all 0's
        basic_memset_to_zero(pseamldr_data->next_kid_to_config, sizeof(pseamldr_data->next_kid_to_config));
    }
    else
    {
        if (rec_status == PSEAMLDR_UNRECOVERABLE_ERROR)
        {
            zero_seamextend_structure(&pseamldr_data->seamextend_snapshot);
        }

        seamextend_write(&pseamldr_data->seamextend_snapshot);
    }

    return flow_status;
}

api_error_type seamldr_install(uint64_t seamldr_params_pa)
{
    pseamldr_data_t             * pseamldr_data = get_pseamldr_data();
    p_sysinfo_table_t           * p_sysinfo_table = get_psysinfo_table();
    seamldr_params_t            * seamldr_params_la = NULL;
    seamldr_params_t              seamldr_params;
    seam_sigstruct_t            * seam_sigstruct_la = NULL;
    uint32_t                      lpid;
    memory_constants_t            mem_consts;

    uint64_t                      rec_status = PSEAMLDR_RECOVERABLE_ERROR;
    api_error_type                return_value = PSEAMLDR_EUNSPECERR;

    lpid = get_current_lpid();

    // If X2APICID = CPUID.1FH.0:EDX >= MIN_LP_BITMAP_SIZE, then fatal error
    IF_RARE (lpid >= MAX_NUM_OF_LPS)
    {
        TDX_ERROR("Incorrect LPID=%d, bigger than defined max num of LP's=%d\n", lpid, MAX_NUM_OF_LPS);
        return_value = PSEAMLDR_EUNSPECERR;
        goto EXIT;
    }

    // If SEAMLDR.SHUTDOWN session already started (i.e. bitcount(SHUTDOWN_BITMAP) > 0),
    // then set RAX = EBADCALL, RDX = 0 and return.
    IF_RARE (pseamldr_data->lps_in_shutdown != 0)
    {
        TDX_ERROR("Shutdown process started, can't update\n");
        return_value = PSEAMLDR_EBADCALL;
        goto EXIT;
    }

    // Return EBADCALL if CURRENT_FLOW is not INSTALL or READY
    IF_RARE ((pseamldr_data->current_flow != PSEAMLDR_STATE_READY) &&
             (pseamldr_data->current_flow != PSEAMLDR_STATE_INSTALL))
    {
        TDX_ERROR("Incorrect current flow - %d, not READY or INSTALL\n", pseamldr_data->current_flow);
        return_value = PSEAMLDR_EBADCALL;
        goto EXIT;
    }


    // If this API was already invoked on this LP in the current update session,
    // then set RAX = EBADCALL, RDX = 0 and return
    // Mark this LP as invoked in the current update session
    IF_RARE (bit_test_and_set(pseamldr_data->update_bitmap, lpid))
    {
        TDX_ERROR("Update already occurred on this LPID=%d\n", lpid);
        return_value = PSEAMLDR_EBADCALL;
        goto EXIT;
    }

    // If this is the first LP on which this API is invoked
    // then capture the value of SEAMEXTEND register in SEAMEXTEND_SNAPSHOT,
    // and block further SEAMCALLs to the old SEAM module
    // (by clearing the SEAM_READY field in the SEAMEXTEND register).
    IF_RARE (pseamldr_data->lps_in_update == 0)
    {
        seamextend_read(&pseamldr_data->seamextend_snapshot);
        uint8_t seam_ready_original = pseamldr_data->seamextend_snapshot.seam_ready;
        pseamldr_data->seamextend_snapshot.seam_ready = 0;
        seamextend_write(&pseamldr_data->seamextend_snapshot);
        pseamldr_data->seamextend_snapshot.seam_ready = seam_ready_original;

        pseamldr_data->current_flow = PSEAMLDR_STATE_INSTALL;
    }

    pseamldr_data->lps_in_update++;

    // Perform INIT phase
    if (!pseamldr_data->init_done)
    {
        uint32_t pkg_id = get_current_pkgid();

        if (pseamldr_data->max_pkg_lps[pkg_id] == 0)
        {
            ia32_core_thread_count_t core_thread_count = { .raw = ia32_rdmsr(IA32_CORE_THREAD_COUNT_MSR_ADDR) };
            pseamldr_data->max_pkg_lps[pkg_id] = core_thread_count.lps_in_package;
            pseamldr_data->max_domain_lps[pkg_id] = core_thread_count.lps_in_package;
        }
    }

    // Evict the SEAM module’s VMCS associated with this LP from the VMCS cache
    // (by executing VMCLEAR with physical address SEAMRR.BASE + 4K + CPUID.B.0:EDX * 4K).
    // This helps ensure that old cached SEAM VMCS won’t later be evicted and corrupt SEAM VMCS in memory.
    if (pseamldr_data->module_range_initialized)
    {
        uint64_t current_seam_vmcs_pa = pseamldr_data->system_info.seamrr_base + _4KB + (lpid * _4KB);
        ia32_vmclear((vmcs_ptr_t*)current_seam_vmcs_pa);
    }

    // If this is not the last LP on which this API is invoked then set RAX = RDX = 0 and return.
    IF_COMMON (pseamldr_data->lps_in_update < p_sysinfo_table->tot_num_lps)
    {
        return_value = PSEAMLDR_SUCCESS;
        goto EXIT;
    }

    // The following steps apply only to the last LP:
    pseamldr_data->init_done = true;

    // ************************ Input checks ************************
    // Check SEAMLDR PARAMS input PA
    return_value = check_and_map_aligned_shared_hpa((pa_t)seamldr_params_pa, SEAMLDR_PARAMS_SIZE,
                                                    TDX_RANGE_RO, (void**)&seamldr_params_la);
    IF_RARE (return_value != PSEAMLDR_SUCCESS)
    {
        TDX_ERROR("Seamldr Params PA is not a valid/aligned shared HPA pa=0x%llx\n", seamldr_params_pa);
        goto UPDATE_END;
    }

    pseamldr_memcpy(&seamldr_params, sizeof(seamldr_params_t), seamldr_params_la, sizeof(seamldr_params_t));

    return_value = check_seamldr_params(pseamldr_data, &seamldr_params);
    IF_RARE (return_value != PSEAMLDR_SUCCESS)
    {
        TDX_ERROR("Seamldr params invalid\n");
        goto UPDATE_END;
    }

    // ******************* Manifest verification *******************
    // Sigstruct PA is verified at this point
    seam_sigstruct_la = map_pa((void*)seamldr_params.sigstruct_pa, TDX_RANGE_RO);
    pseamldr_memcpy(&pseamldr_data->seam_sigstruct_snapshot, sizeof(seam_sigstruct_t), seam_sigstruct_la, sizeof(seam_sigstruct_t));

    return_value = verify_manifest(pseamldr_data, &seamldr_params, &pseamldr_data->seam_sigstruct_snapshot);
    IF_RARE (return_value != PSEAMLDR_SUCCESS)
    {
        TDX_ERROR("Manifest invalid\n");
        goto UPDATE_END;
    }

    // ******************* Memory initialization *******************
    return_value = initialize_memory_constants(pseamldr_data, &seamldr_params, &pseamldr_data->seam_sigstruct_snapshot, &mem_consts);
    IF_RARE (return_value != PSEAMLDR_SUCCESS)
    {
        TDX_ERROR("Memory constants calculation failed\n");
        goto UPDATE_END;
    }

    if ((seamldr_params.scenario == SEAMLDR_SCENARIO_LOAD) || !mem_consts.td_preserving_supported)
    {
        ia32_seamops_seamdb_clear();
        pseamldr_data->num_remaining_updates = get_num_of_remaining_updates();
        // Clear the entire module range
        zero_area_cacheline((void*)p_sysinfo_table->module_region_base,
                mem_consts.module_physlimit - pseamldr_data->system_info.seamrr_base);
    }
    else
    {
        return_value = init_seam_range_on_update(pseamldr_data, p_sysinfo_table, &mem_consts);
        IF_RARE (return_value != PSEAMLDR_SUCCESS)
        {
            TDX_ERROR("Couldn't init SEAM range on update\n");
            goto UPDATE_END;
        }
    }
    // Serialize the instruction flow to prevent speculation around conditioned
    // zero_area_cacheline above
    movdir64b_serialize();

    // Remember that the module range was initialized once
    pseamldr_data->module_range_initialized = true;
    // Set UNRECOVERABLE = 1 (memory has been modified).
    rec_status = PSEAMLDR_UNRECOVERABLE_ERROR;

    // Memory map
    return_value = seam_module_memory_map(pseamldr_data, &mem_consts);
    IF_RARE (return_value != PSEAMLDR_SUCCESS)
    {
        TDX_ERROR("Memory mapping failed\n");
        goto UPDATE_END;
    }

    // Image load and verify
    return_value = seam_module_load_and_verify(pseamldr_data, p_sysinfo_table,
                             &seamldr_params, &pseamldr_data->seam_sigstruct_snapshot, &mem_consts);
    IF_RARE (return_value != PSEAMLDR_SUCCESS)
    {
        TDX_ERROR("Seam module load and verification failed\n");
        goto UPDATE_END;
    }

    // System information setup
    setup_system_information(pseamldr_data, p_sysinfo_table, &mem_consts);

    // SEAM VMCS setup
    setup_seam_vmcs(p_sysinfo_table->module_region_base + _4KB, &mem_consts, pseamldr_data->seam_sigstruct_snapshot.rip_offset);

    // All done!
    return_value = PSEAMLDR_SUCCESS;

UPDATE_END:

    return_value = install_epilogue(return_value, rec_status, pseamldr_data, p_sysinfo_table);

    basic_memset_to_zero(pseamldr_data->update_bitmap, sizeof(pseamldr_data->update_bitmap));
    pseamldr_data->lps_in_update = 0;

    pseamldr_data->current_flow = PSEAMLDR_STATE_READY;

EXIT:

    pseamldr_data->vmm_regs.rdx = (return_value == PSEAMLDR_SUCCESS) ? 0 : rec_status;

    IF_RARE (seamldr_params_la != NULL)
    {
        free_la(seamldr_params_la);
    }

    IF_RARE (seam_sigstruct_la != NULL)
    {
        free_la(seam_sigstruct_la);
    }

    return return_value;
}
