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
 * @file helpers.c
 * @brief Common PSEAMLDR API flow helper functions
 */

#include "helpers.h"

#include "../../../include/pseamldr_api_defs.h"
#include "x86_defs/vmcs_defs.h"
#include "x86_defs/msr_defs.h"

#include "accessors/ia32_accessors.h"
#include "accessors/vt_accessors.h"
#include "memory_handlers/keyhole_manager.h"
#include "seam_sigstruct.h"
#include "crypto/sha384.h"
#include "x86_defs/mktme.h"

uint64_t get_num_addressable_lps_on_socket(void)
{
    uint32_t eax, ebx, ecx, edx;
    cpu_cache_params_t cpu_cache_params;

    ia32_safe_cpuid(CPUID_DET_CACHE_PARAMS_LEAF, CPUID_DET_CACHE_PARAMS_SUBLEAF, &eax, &ebx, &ecx, &edx);

    cpu_cache_params.raw = eax;
    uint64_t num_addr_lps = cpu_cache_params.max_num_of_lps_sharing_cache + 1;

    // If not a power of 2
    if (num_addr_lps & (num_addr_lps - 1))
    {
        // Round up to the nearest power of 2:
        num_addr_lps = BIT(bit_scan_reverse64(num_addr_lps) + 1);
    }

    return num_addr_lps;
}

uint32_t get_current_lpid(void)
{
    uint32_t eax, ebx, ecx, edx;

    ia32_safe_cpuid(CPUID_GET_TOPOLOGY_LEAF, 0, &eax, &ebx, &ecx, &edx);

    return edx;
}

uint32_t get_current_pkgid(void)
{
    uint32_t eax, ebx, ecx, edx;

    ia32_safe_cpuid(CPUID_GET_TOPOLOGY_LEAF, 0, &eax, &ebx, &ecx, &edx);

    uint32_t pkg_id = edx >> get_pseamldr_data()->x2apic_pkg_id_shift_count;

    pseamldr_sanity_check (pkg_id < MAX_PKGS, SCEC_HELPERS_SOURCE, 15);

    return pkg_id;
}

uint32_t get_current_domainid(void)
{
    return get_current_pkgid();
}

void basic_memset(uint64_t dst, uint64_t dst_bytes, uint8_t val, uint64_t nbytes)
{
    pseamldr_sanity_check (dst_bytes >= nbytes, SCEC_HELPERS_SOURCE, 2);

   _ASM_VOLATILE_ ("rep; stosb;"
                    :
                    :"c"(nbytes), "a"(val), "D"(dst)
                    :"memory");
}

void basic_memset_to_zero(void * dst, uint64_t nbytes)
{
    basic_memset((uint64_t)dst, nbytes, 0, nbytes);
}

static bool_t shared_hpa_check(pa_t hpa)
{
    pseamldr_data_t* pseamldr_data = get_pseamldr_data();

    // 1) Check that no bits above MAX_PA are set

    if (!is_pa_smaller_than_max_pa(hpa.raw))
    {
        return false;
    }

    // 2) Check that the provided HPA is outside SEAMRR.
    // This check is correct because it is called from shared_hpa_check_with_pwr_2_alignment,
    // after we know that the HPA is aligned on the size of the of structure that it points on.
    // Which means that we can check only if the address itself is in the range of SEAMRR,
    // and don't need to check the whole structure range.

    if (is_addr_in_range(get_addr_from_pa(hpa), pseamldr_data->system_info.seamrr_base,
                                                pseamldr_data->system_info.seamrr_size))
    {
        return false;
    }

    // 3) Check that HKID bits in the HPA are in the range configured for shared HKIDs

    if ((uint64_t)get_hkid_from_pa(hpa) >= pseamldr_data->system_info.private_hkid_min)
    {
        return false;
    }

    return true;
}

bool_t shared_hpa_check_with_pwr_2_alignment(pa_t hpa, uint64_t size)
{
    if (!is_addr_aligned_pwr_of_2(hpa.raw, size))
    {
        return false;
    }

    return shared_hpa_check(hpa);
}

api_error_type check_and_map_aligned_shared_hpa(pa_t hpa, uint64_t alignment, mapping_type_t mapping_type, void** la)
{
    bool_t errc;

    errc = shared_hpa_check_with_pwr_2_alignment(hpa, alignment);

    if (errc != true)
    {
        return PSEAMLDR_EBADPARAM;
    }

    *la = map_pa((void*)hpa.full_pa, mapping_type);

    return PSEAMLDR_SUCCESS;
}

bool_t is_addr_in_range(uint64_t addr, uint64_t base, uint64_t size)
{
    pseamldr_sanity_check(base <= (base + size), SCEC_HELPERS_SOURCE, 10);

    return ((addr >= base) && (addr < (base + size)));
}

void seamextend_read(seamextend_t* seamextend_dst)
{
    seamextend_t* tmp_buf = &get_pseamldr_data()->seamextend_tmp_buf;
    uint64_t buffer_pa = translate_module_data_va_to_pa((uint64_t)tmp_buf);

    ia32_wrmsr(IA32_SEAMEXTEND_MSR_ADDR, buffer_pa | 0x1);

    pseamldr_memcpy(seamextend_dst, sizeof(seamextend_t), tmp_buf, sizeof(seamextend_t));
}

void seamextend_write(seamextend_t* seamextend_src)
{
    seamextend_t* tmp_buf = &get_pseamldr_data()->seamextend_tmp_buf;
    pseamldr_memcpy(tmp_buf, sizeof(seamextend_t), seamextend_src, sizeof(seamextend_t));

    uint64_t buffer_pa = translate_module_data_va_to_pa((uint64_t)tmp_buf);

    ia32_wrmsr(IA32_SEAMEXTEND_MSR_ADDR, buffer_pa);
}

bool_t safe_memcmp(const void * a, const void * b, uint64_t nbytes)
{
    volatile uint8_t result = 0;

    volatile uint8_t* a_8 = (uint8_t*)a;
    volatile uint8_t* b_8 = (uint8_t*)b;

    for (uint64_t i = 0; i < nbytes; i++)
    {
        result |= (a_8[i] ^ b_8[i]);
    }

    return (result == 0);
}

bool_t compute_and_verify_hash(const uint8_t* message, uint32_t message_len, const uint8_t* expected_hash)
{
    uint64_t calculated_hash[SIZE_OF_SHA384_HASH_IN_QWORDS];

    if (sha384_generate_hash(message, message_len, calculated_hash) != 0)
    {
        FATAL_ERROR();
    }

    return safe_memcmp(calculated_hash, expected_hash, SIZE_OF_SHA384_HASH_IN_BYTES);
}

void ia32_safe_cpuid(uint32_t leaf, uint32_t subleaf, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
{    
    uint64_t misc_enable = 0;
   
    if (leaf > 2)
    {
        misc_enable = ia32_rdmsr(IA32_MISC_ENABLE_MSR_ADDR);
        if ((misc_enable & IA32_MISC_ENABLE_BOOT_NT4_BIT) != 0) 
        {
            ia32_wrmsr(IA32_MISC_ENABLE_MSR_ADDR, (misc_enable & ~IA32_MISC_ENABLE_BOOT_NT4_BIT));
        }
    }    

    ia32_cpuid(leaf, subleaf, eax, ebx, ecx, edx);
    
    if ((leaf > 2) && ((misc_enable & IA32_MISC_ENABLE_BOOT_NT4_BIT) != 0))
    {
        ia32_wrmsr(IA32_MISC_ENABLE_MSR_ADDR, misc_enable);
    }          
}

static void clear_movss_sti_blocking(void)
{
    vmx_guest_inter_state_t guest_inter_state;
    ia32_vmread(VMX_GUEST_INTERRUPTIBILITY_ENCODE, &guest_inter_state.raw);

    if (guest_inter_state.blocking_by_mov_ss != 0 || guest_inter_state.blocking_by_sti != 0)
    {
        guest_inter_state.blocking_by_mov_ss = 0;
        guest_inter_state.blocking_by_sti = 0;
        ia32_vmwrite(VMX_GUEST_INTERRUPTIBILITY_ENCODE, guest_inter_state.raw);
    }
}

static void set_guest_pde_bs(void)
{
    ia32_rflags_t rflags;
    ia32_vmread(VMX_GUEST_RFLAGS_ENCODE, &rflags.raw);

    ia32_debugctl_t debugctl;
    ia32_vmread(VMX_GUEST_IA32_DEBUGCTLMSR_FULL_ENCODE, &debugctl.raw);

    pending_debug_exception_t pde;
    ia32_vmread(VMX_GUEST_PND_DEBUG_EXCEPTION_ENCODE, &pde.raw);

    pde.bs = (rflags.tf == 1 && debugctl.btf == 0) ? 1 : 0;
    ia32_vmwrite(VMX_GUEST_PND_DEBUG_EXCEPTION_ENCODE, pde.raw);
}

void advance_guest_rip(void)
{
    current_vmcs_guest_rip_advance(0);

    clear_movss_sti_blocking();
    set_guest_pde_bs();
}

uint32_t get_num_of_remaining_updates(void)
{
    uint32_t num_remaining_updates;
    uint64_t last_entry, seamdb_size, result;
    uint256_t last_entry_nonce;

    result = ia32_seamops_seamdb_getref(&last_entry, &last_entry_nonce, &seamdb_size);
    IF_RARE (result != SEAMOPS_SUCCESS)
    {
        num_remaining_updates = (uint32_t)seamdb_size;
    }
    else
    {
        num_remaining_updates = (uint32_t)(seamdb_size - (last_entry + 1));
    }

    return num_remaining_updates;
}

api_error_type program_mktme_keys(uint16_t hkid)
{
    mktme_key_program_t mktme_key_program;
    api_error_type      return_val = PSEAMLDR_EUNSPECERR;
    uint64_t            pconfig_return_code;

    basic_memset_to_zero(&mktme_key_program, sizeof(mktme_key_program_t));

    // set the command, hkid as keyid and encryption algorithm
    mktme_key_program.keyid_ctrl.command = MKTME_KEYID_SET_KEY_RANDOM;
    mktme_key_program.keyid = hkid;

    if (get_psysinfo_table()->tdx_ac)
    {
        if (get_pseamldr_data()->system_info.ia32_tme_activate.algs_aes_xts_256)
        {
            mktme_key_program.keyid_ctrl.enc_algo = AES_XTS_256;
        }
        else
        {
            mktme_key_program.keyid_ctrl.enc_algo = AES_XTS_128;
        }
    }
    else
    {
        if (get_pseamldr_data()->system_info.ia32_tme_activate.algs_aes_xts_256_with_integrity)
        {
            mktme_key_program.keyid_ctrl.enc_algo = AES_XTS_256_WITH_INTEGRITY;
        }
        else
        {
            mktme_key_program.keyid_ctrl.enc_algo = AES_XTS_128_WITH_INTEGRITY;
        }
    }

    // Execute the PCONFIG instruction with the updated struct and return
    pconfig_return_code = ia32_mktme_key_program(&mktme_key_program);

    if (pconfig_return_code != MKTME_PROG_SUCCESS)
    {
        TDX_ERROR("pconfig_return_code = %llx\n", pconfig_return_code);
        if (pconfig_return_code == MKTME_ENTROPY_ERROR)
        {
            return_val = PSEAMLDR_ENOENTROPY;
            TDX_ERROR("Failed to generate a key for the MKTME engine\n");
            goto EXIT;
        }
        else
        {
            // unexpected - FATAL ERROR
            FATAL_ERROR();
        }
    }

    return_val = PSEAMLDR_SUCCESS;
EXIT:
    return return_val;
}

