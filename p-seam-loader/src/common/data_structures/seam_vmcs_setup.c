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
 * @file seam_vmcs_setup.c
 * @brief SEAM VMCS setup
 */

#include "x86_defs/msr_defs.h"
#include "x86_defs/vmcs_defs.h"
#include "data_structures/pseamldr_data_types.h"
#include "accessors/ia32_accessors.h"
#include "helpers/helpers.h"
#include "seam_vmcs_setup.h"


void setup_seam_vmcs(uint64_t vmcs_la_base, memory_constants_t* mem_consts, uint64_t rip_offset)
{
    ia32_vmx_basic_t vmx_basic;
    uint32_t pinbased_ctls, procbased_ctls, exit_ctls, entry_ctls;
    uint64_t cr0_fixed0, cr0_fixed1, cr0_mustbe1;
    uint64_t cr4_fixed0, cr4_fixed1, cr4_mustbe1;

    vmx_basic.raw = ia32_rdmsr(IA32_VMX_BASIC_MSR_ADDR);

    pinbased_ctls = (uint32_t)(ia32_rdmsr(IA32_VMX_TRUE_PINBASED_CTLS_MSR_ADDR) & BIT_MASK_32BITS);
    procbased_ctls = (uint32_t)(ia32_rdmsr(IA32_VMX_TRUE_PROCBASED_CTLS_MSR_ADDR) & BIT_MASK_32BITS);
    exit_ctls = (uint32_t)(ia32_rdmsr(IA32_VMX_TRUE_EXIT_CTLS_MSR_ADDR) & BIT_MASK_32BITS);
    entry_ctls = (uint32_t)(ia32_rdmsr(IA32_VMX_TRUE_ENTRY_CTLS_MSR_ADDR) & BIT_MASK_32BITS);

    cr0_fixed0 = ia32_rdmsr(IA32_VMX_CR0_FIXED0_MSR_ADDR);
    cr0_fixed1 = ia32_rdmsr(IA32_VMX_CR0_FIXED1_MSR_ADDR);
    cr0_mustbe1 = cr0_fixed1 & cr0_fixed0;
    cr4_fixed0 = ia32_rdmsr(IA32_VMX_CR4_FIXED0_MSR_ADDR);
    cr4_fixed1 = ia32_rdmsr(IA32_VMX_CR4_FIXED1_MSR_ADDR);
    cr4_mustbe1 = cr4_fixed1 & cr4_fixed0;

    wr_guest_rip(vmcs_la_base, SEAM_VMCS_NON_CANONICAL_RIP);
    wr_host_cr0(vmcs_la_base, SEAM_VMCS_CR0_BITS | cr0_mustbe1);
    wr_gost_cr3(vmcs_la_base, mem_consts->pml4_physbase);
    wr_host_cr4(vmcs_la_base, SEAM_VMCS_CR4_BITS | cr4_mustbe1);
    wr_host_cs_selector(vmcs_la_base, SEAM_VMCS_CS_SELECTOR);
    wr_host_ss_selector(vmcs_la_base, SEAM_VMCS_SS_SELECTOR);
    wr_host_fs_selector(vmcs_la_base, SEAM_VMCS_FS_SELECTOR);
    wr_host_gs_selector(vmcs_la_base, SEAM_VMCS_GS_SELECTOR);
    wr_host_tr_selector(vmcs_la_base, SEAM_VMCS_TR_SELECTOR);
    wr_host_ia32_pat(vmcs_la_base, SEAM_VMCS_PAT_MSR_VALUE);
    wr_host_ia32_s_cet(vmcs_la_base, SEAM_VMCS_S_CET_MSR_VALUE);
    wr_host_ia32_efer(vmcs_la_base, SEAM_VMCS_EFER_MSR_VALUE);

    exit_ctls |= SEAM_VMCS_EXIT_CTLS_VALUE;
    exit_ctls &= ((ia32_rdmsr(IA32_VMX_TRUE_EXIT_CTLS_MSR_ADDR) >> 32) & BIT_MASK_32BITS);

    wr_vm_exit_control(vmcs_la_base, exit_ctls);

    entry_ctls |= SEAM_VMCS_ENTRY_CTLS_VALUE;

    entry_ctls &= ((ia32_rdmsr(IA32_VMX_TRUE_ENTRY_CTLS_MSR_ADDR) >> 32) & BIT_MASK_32BITS);

    wr_vm_entry_control(vmcs_la_base, entry_ctls);

    wr_vm_execution_control_pin_based(vmcs_la_base, pinbased_ctls);
    wr_vm_execution_control_proc_based(vmcs_la_base, procbased_ctls);

    wr_host_rip(vmcs_la_base, mem_consts->code_region_linbase + rip_offset);
    wr_host_fs_base(vmcs_la_base, mem_consts->sysinfo_table_linbase);

    wr_host_idtr_base(vmcs_la_base, mem_consts->idt_linbase);
    wr_host_gdtr_base(vmcs_la_base, mem_consts->gdt_linbase);

    uint64_t host_rsp_first_lp = mem_consts->stack_region_linbase + mem_consts->data_stack_size - 8;
    uint64_t host_ssp_first_lp = mem_consts->stack_region_linbase + mem_consts->lp_stack_size - 8;
    uint64_t host_gsbase_first_lp = mem_consts->data_region_linbase;

    host_gsbase_first_lp += mem_consts->handoff_data_size;

    wr_host_rsp(vmcs_la_base, host_rsp_first_lp);
    wr_host_ssp(vmcs_la_base, host_ssp_first_lp);
    wr_host_gs_base(vmcs_la_base, host_gsbase_first_lp);
    wr_vmcs_revision_id(vmcs_la_base, vmx_basic.vmcs_revision_id);

    uint64_t vmcs_size = vmx_basic.vmcs_region_size;

    for (uint64_t i = 1; i < mem_consts->num_addressable_lps; i++)
    {
        uint64_t current_vmcs_la = vmcs_la_base + (i * PAGE_SIZE_IN_BYTES);
        pseamldr_memcpy((void*)current_vmcs_la, vmcs_size, (void*)vmcs_la_base, vmcs_size);
        wr_host_rsp(current_vmcs_la, host_rsp_first_lp + (i * mem_consts->lp_stack_size));
        wr_host_ssp(current_vmcs_la, host_ssp_first_lp + (i * mem_consts->lp_stack_size));
        wr_host_gs_base(current_vmcs_la, host_gsbase_first_lp + (i* mem_consts->local_data_size));
    }
}
