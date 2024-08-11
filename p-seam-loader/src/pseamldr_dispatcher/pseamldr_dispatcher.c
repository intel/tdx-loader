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
 * @file pseamldr_dispatcher.c
 * @brief VMM dispatcher and return sequence
 */
#include "pseamldr_dispatcher.h"

#include "../../include/pseamldr_api_handlers.h"
#include "data_structures/pseamldr_data.h"
#include "accessors/ia32_accessors.h"
#include "accessors/vt_accessors.h"
#include "accessors/data_accessors.h"
#include "x86_defs/vmcs_defs.h"
#include "debug/tdx_debug.h"
#include "helpers/helpers.h"
#include "x86_defs/msr_defs.h"
#include "x86_defs/x86_defs.h"

static void pseamldr_initialize_system_values(pseamldr_data_t* pseamldr_data)
{
    uint32_t eax, ebx, ecx, edx;

    ia32_safe_cpuid(CPUID_GET_MAX_PA_LEAF, 0, &eax, &ebx, &ecx, &edx);

    pseamldr_data->system_info.max_pa = eax & CPUID_MAX_PA_BITS;

    pseamldr_sanity_check((pseamldr_data->system_info.max_pa <= 64) &&
                          (pseamldr_data->system_info.max_pa > 0), SCEC_VMM_DISPATCHER_SOURCE, 10);

    uint64_t seamrr_base = ia32_rdmsr(IA32_SEAMRR_BASE_MSR_ADDR) & IA32_SEAMRR_BASE_AND_MASK_MASK;
    uint64_t seamrr_mask = ia32_rdmsr(IA32_SEAMRR_MASK_MSR_ADDR) & IA32_SEAMRR_BASE_AND_MASK_MASK;
    uint64_t seamrr_size = mask_to_size(seamrr_mask);

    pseamldr_data->system_info.seamrr_base = seamrr_base;
    pseamldr_data->system_info.seamrr_size = seamrr_size;

    ia32_tme_activate_t           ia32_tme_activate;
    ia32_tme_keyid_partitioning_t ia32_tme_keyid_partitioning;

    ia32_tme_keyid_partitioning.raw = ia32_rdmsr(IA32_MKTME_KEYID_PARTITIONING_MSR_ADDR);

    pseamldr_data->system_info.private_hkid_min = ia32_tme_keyid_partitioning.num_mktme_kids + 1;
    pseamldr_data->system_info.num_tdx_hkids    = ia32_tme_keyid_partitioning.num_tdx_priv_kids;

    ia32_tme_activate.raw   = ia32_rdmsr(IA32_TME_ACTIVATE_MSR_ADDR);

    pseamldr_data->system_info.ia32_tme_activate.raw = ia32_tme_activate.raw;

    uint64_t hkid_start_bit = pseamldr_data->system_info.max_pa - ia32_tme_activate.mk_tme_keyid_bits;

    pseamldr_sanity_check(hkid_start_bit <= (pseamldr_data->system_info.max_pa - 1), SCEC_VMM_DISPATCHER_SOURCE, 11);

    uint64_t hkid_mask = BITS(pseamldr_data->system_info.max_pa - 1, hkid_start_bit);

    pseamldr_data->system_info.hkid_mask = hkid_mask;

    init_keyhole_state();

    // Initialize the package ID shift count
    uint32_t prev_level_type = LEVEL_TYPE_INVALID;
    cpuid_topology_shift_t shift;
    cpuid_topology_level_t level;
    uint32_t shift_count = (uint32_t)-1; //Initialized to invalid value.
    uint32_t subleaf = 0;

    do
    {
        ia32_safe_cpuid(CPUID_GET_TOPOLOGY_LEAF, subleaf, &shift.raw, &ebx, &level.raw, &edx);

        if (level.level_type == LEVEL_TYPE_INVALID)
        {
            // Make sure we have at least one valid subleaf
            pseamldr_sanity_check(subleaf > 0, SCEC_VMM_DISPATCHER_SOURCE, 12);
        }
        else
        {
            // Checks that level type higher than the last one
            // (initialized to INVALID, which is 0) but does not reach the max.
            pseamldr_sanity_check((level.level_type > prev_level_type) && (level.level_type < (uint32_t)LEVEL_TYPE_MAX) &&
                                  (subleaf <= CPUID_GET_TOPOLOGY_MAX_SUBLEAF),
                                  SCEC_VMM_DISPATCHER_SOURCE, 13);

            shift_count = shift.shift_count;
        }

        prev_level_type = level.level_type;

        subleaf++;

    } while (level.level_type != (uint32_t)LEVEL_TYPE_INVALID);

    pseamldr_sanity_check(shift_count != (uint32_t)-1, SCEC_VMM_DISPATCHER_SOURCE, 13);

    pseamldr_data->x2apic_pkg_id_shift_count = shift_count;

    pseamldr_data->system_info.initialized = true;
}

_STATIC_INLINE_ void sys_control_msr_handling(pseamldr_data_t* pseamldr_data)
{
    // Write IA32_PRED_CMD = 0x1 (IBPB).
    ia32_pred_cmd_t pred_cmd = { .raw = 0 };
    pred_cmd.ibpb = 1;
    ia32_wrmsr(IA32_PRED_CMD_MSR_ADDR, pred_cmd.raw);

    // Save IA32_SPEC_CTRL and write IA32_SPEC_CTRL = 0x4 (SSBD).
    pseamldr_data->vmm_spec_ctrl.raw = ia32_rdmsr(IA32_SPEC_CTRL_MSR_ADDR);
    ia32_spec_ctrl_t spec_ctrl = { .raw = 0 };
    spec_ctrl.ssbd = 1;
    ia32_wrmsr(IA32_SPEC_CTRL_MSR_ADDR, spec_ctrl.raw);
}

_STATIC_INLINE_ bool_t generate_canary(pseamldr_data_t* pseamldr_data)
{
    if (!ia32_rdrand64(&pseamldr_data->canary))
    {
        return false;
    }

    if (pseamldr_data->canary == 0)
    {
        return false;
    }

    ia32_vmwrite(VMX_HOST_FS_BASE_ENCODE, (uint64_t)pseamldr_data);

    return true;
}

void pseamldr_dispatcher(void)
{
    // Must be first thing to do before accessing data or sysinfo table
    pseamldr_data_t* pseamldr_data = init_data_fast_ref_ptrs();

    TDX_LOG("PSEAMLDR Module entry start\n");

    vm_vmexit_exit_reason_t exit_reason;
    ia32_vmread(VMX_VM_EXIT_REASON_ENCODE, &exit_reason.raw);

    pseamldr_sanity_check(exit_reason.basic_reason == VMEXIT_REASON_SEAMCALL, SCEC_VMM_DISPATCHER_SOURCE, 2);

    sys_control_msr_handling(pseamldr_data);

    // Must be the next thing to do after initializing the data pointers above
    // and the SPEC_CTRL MSR
    IF_RARE (!pseamldr_data->canary)
    {
        if (!generate_canary(pseamldr_data))
        {
            TDX_ERROR("Not enough entropy to generate stack canary - PSEAMLDR_EUNSPECERR\n");
            pseamldr_data->vmm_regs.rax = PSEAMLDR_EUNSPECERR;
            goto EXIT;
        }
    }

    IF_RARE (!pseamldr_data->system_info.initialized)
    {
        pseamldr_initialize_system_values(pseamldr_data);
    }

    // Get leaf code from RAX in local data (saved on entry)
    uint64_t leaf_opcode = pseamldr_data->vmm_regs.rax;

    TDX_LOG("Leaf_opcode = 0x%llx\n", leaf_opcode);

    uint128_t xmms[16]; // SSE state backup for crypto

    store_xmms_in_buffer(xmms);

    // switch over leaf opcodes
    switch (leaf_opcode)
    {
    case SEAMLDR_INFO_LEAF:
    {
        pseamldr_data->vmm_regs.rax = seamldr_info(pseamldr_data->vmm_regs.rcx);
        break;
    }
    case SEAMLDR_INSTALL_LEAF:
    {
        pseamldr_data->vmm_regs.rax = seamldr_install(pseamldr_data->vmm_regs.rcx);
        break;
    }
    case SEAMLDR_SHUTDOWN_LEAF:
    {
        pseamldr_data->vmm_regs.rax = seamldr_shutdown();
        break;
    }
    case SEAMLDR_SEAMINFO_LEAF:
    {
        pseamldr_data->vmm_regs.rax = seamldr_seaminfo(pseamldr_data->vmm_regs.rcx);
        break;
    }
    case SEAMLDR_CLEANUP_LEAF:
    {
        pseamldr_data->vmm_regs.rax = seamldr_cleanup();
        break;
    }
#ifdef DEBUGFEATURE_TDX_DBG_TRACE
    case TDDEBUGCONFIG_LEAF:
    {
        pseamldr_data->vmm_regs.rax = td_debug_config(pseamldr_data->vmm_regs.rcx, pseamldr_data->vmm_regs.rdx,
                                                   pseamldr_data->vmm_regs.r8);
        break;
    }
#endif

    default:
    {
        TDX_ERROR("Unknown leaf - PSEAMLDR_EBADPARAM\n");
        pseamldr_data->vmm_regs.rax = PSEAMLDR_EBADPARAM;
        goto EXIT;
    }
    }

EXIT:

    load_xmms_from_buffer(xmms);
    basic_memset_to_zero(xmms, sizeof(xmms));

    // No return after calling the post dispatching operations
    // Eventually call SEAMRET
    pseamldr_post_dispatching();
}


void pseamldr_post_dispatching(void)
{
    advance_guest_rip();

    // Restore IA32_SPEC_CTRL
    ia32_wrmsr(IA32_SPEC_CTRL_MSR_ADDR, get_pseamldr_data()->vmm_spec_ctrl.raw);

    TDX_LOG("pseamldr_post_dispatching - preparing to do SEAMRET\n");

    pseamldr_exit_point(); // Restore GPRs and SEAMRET

    // Shouldn't reach here:

    pseamldr_sanity_check(0, SCEC_VMM_DISPATCHER_SOURCE, 0);
}
