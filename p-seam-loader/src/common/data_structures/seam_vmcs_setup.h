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
 * @file seam_vmcs_setup.h
 * @brief SEAM VMCS definitions
 */
#ifndef SRC_COMMON_DATA_STRUCTURES_SEAM_VMCS_SETUP_H_
#define SRC_COMMON_DATA_STRUCTURES_SEAM_VMCS_SETUP_H_

#include "../../../include/pseamldr_basic_defs.h"
#include "../../../include/pseamldr_basic_types.h"
#include "pseamldr_data.h"

#define SEAM_VMCS_NON_CANONICAL_RIP  0x1000000000000000ULL
#define SEAM_VMCS_CR0_BITS           (CR0_PE | CR0_ET | CR0_NE | CR0_WP | CR0_PG)
#define SEAM_VMCS_CR4_BITS           (CR4_DE | CR4_PAE | CR4_PGE | CR4_OSFXSR | CR4_OSXMMEXCPT | \
                                      CR4_VMXE | CR4_FSGSBASE | CR4_OSXSAVE | CR4_SMEP | CR4_SMAP | CR4_CET)
#define SEAM_VMCS_CS_SELECTOR        0x8U
#define SEAM_VMCS_SS_SELECTOR        0x10U
#define SEAM_VMCS_FS_SELECTOR        0x18U
#define SEAM_VMCS_GS_SELECTOR        0x18U
#define SEAM_VMCS_TR_SELECTOR        0x20U
#define SEAM_VMCS_PAT_MSR_VALUE      0x0006060606060606ULL
#define SEAM_VMCS_S_CET_MSR_VALUE    (IA32_S_CET_SH_STK_EN_BIT | IA32_S_CET_ENDBR_EN_BIT | IA32_S_CET_NO_TRACK_EN_BIT)
#define SEAM_VMCS_EFER_MSR_VALUE     (IA32_EFER_LME_BIT | IA32_EFER_LMA_BIT | IA32_EFER_NXE_BIT)

#define SEAM_VMCS_EXIT_CTLS_VALUE    (VM_EXIT_CTRL_SAVE_DEBUG_CTRL | VM_EXIT_CTRL_HOST_ADDR_SPACE_SIZE | \
                                      VM_EXIT_CTRL_SAVE_IA32_PAT | VM_EXIT_CTRL_LOAD_IA32_PAT | \
                                      VM_EXIT_CTRL_SAVE_IA32_EFER | VM_EXIT_CTRL_LOAD_IA32_EFER | \
                                      VM_EXIT_CTRL_CONCEAL_VMX_FROM_PT | VM_EXIT_CTRL_CLEAR_IA32_RTIT_CTL | \
                                      VM_EXIT_CTRL_CLEAR_LBR_CTL | VM_EXIT_CTRL_LOAD_CET_HOST_STATE | \
                                      VM_EXIT_CTRL_LOAD_IA32_PERF_GLOBAL_CTL | VM_EXIT_CTRL_SAVE_IA32_PERF_GLOBAL_CTL)

#define SEAM_VMCS_ENTRY_CTLS_VALUE   (VM_ENTRY_CTRL_LOAD_DEBUG_CTRL | VM_ENTRY_CTRL_LOAD_IA32_PERF_GLOBAL_CTL | \
                                      VM_ENTRY_CTRL_LOAD_IA32_PAT | VM_ENTRY_CTRL_LOAD_IA32_EFER | \
                                      VM_ENTRY_CTRL_CONCEAL_VMX_FROM_PT | VM_ENTRY_CTRL_LOAD_IA32_RTIT_CTL | \
                                      VM_ENTRY_CTRL_LOAD_UINV | VM_ENTRY_CTRL_LOAD_GUEST_CET_STATE | \
                                      VM_ENTRY_CTRL_LOAD_LBR_CTL | VM_ENTRY_CTRL_LOAD_IA32_PKRS)

void setup_seam_vmcs(uint64_t vmcs_la_base, memory_constants_t* mem_consts, uint64_t rip_offset);

#endif /* SRC_COMMON_DATA_STRUCTURES_SEAM_VMCS_SETUP_H_ */
