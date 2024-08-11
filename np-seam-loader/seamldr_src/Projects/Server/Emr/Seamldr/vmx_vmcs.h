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

// AUTOMATICALLY GENERATED FILE - DO NOT MODIFY //

#ifndef __RPC_B0_VMX_VMCS_H__
#define __RPC_B0_VMX_VMCS_H__

////////////////////////////////////////////////////////////////////////////
// Date:            January Thursday 2022-01-06 03:59:09.614386
// User:            cnladmin
// Tool Directory:  /nfs/site/proj/cnl/cnl.tools.1/xucodetools/new_model2h/1.4.7/Core
// Input Files:     rpc_b0_vmx_vmcs.h vmx_vmcs.h
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// VMCS_REVISION_ID
////////////////////////////////////////////////////////////////////////////
#define VMCS_REVISION_ID 0x0

////////////////////////////////////////////////////////////////////////////
// V M C S   L A Y O U T
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// RPC_B0_VMX_VMCS - VMCS OFFSETS
////////////////////////////////////////////////////////////////////////////

#define VMX_VMCS_REVISION_ID_OFFSET                              0x0000 //4
#define VMX_ABORT_INDICATOR_OFFSET                               0x0004 //4
#define VMCS_CACHING_ARCH_PTR_OFFSET                             0x0008 //8
#define VMCS_CACHING_SAVED_DIRTY_BITS_OFFSET                     0x0010 //4
#define VMCS_CACHING_UARCH_INFO_OFFSET                           0x0014 //2
#define VMX_RESERVED_0_OFFSET                                    0x0016 //10
#define VMX_GUEST_ES_SELECTOR_OFFSET                             0x0020 //2
#define VMX_GUEST_ES_ARBYTE_OFFSET                               0x0022 //2
#define VMX_GUEST_ES_LIMIT_OFFSET                                0x0024 //4
#define VMX_GUEST_ES_BASE_OFFSET                                 0x0028 //8
#define VMX_GUEST_CS_SELECTOR_OFFSET                             0x0030 //2
#define VMX_GUEST_CS_ARBYTE_OFFSET                               0x0032 //2
#define VMX_GUEST_CS_LIMIT_OFFSET                                0x0034 //4
#define VMX_GUEST_CS_BASE_OFFSET                                 0x0038 //8
#define VMX_GUEST_SS_SELECTOR_OFFSET                             0x0040 //2
#define VMX_GUEST_SS_ARBYTE_OFFSET                               0x0042 //2
#define VMX_GUEST_SS_LIMIT_OFFSET                                0x0044 //4
#define VMX_GUEST_SS_BASE_OFFSET                                 0x0048 //8
#define VMX_GUEST_DS_SELECTOR_OFFSET                             0x0050 //2
#define VMX_GUEST_DS_ARBYTE_OFFSET                               0x0052 //2
#define VMX_GUEST_DS_LIMIT_OFFSET                                0x0054 //4
#define VMX_GUEST_DS_BASE_OFFSET                                 0x0058 //8
#define VMX_GUEST_LDTR_SELECTOR_OFFSET                           0x0060 //2
#define VMX_GUEST_LDTR_ARBYTE_OFFSET                             0x0062 //2
#define VMX_GUEST_LDTR_LIMIT_OFFSET                              0x0064 //4
#define VMX_GUEST_LDTR_BASE_OFFSET                               0x0068 //8
#define VMX_GUEST_TR_SELECTOR_OFFSET                             0x0070 //2
#define VMX_GUEST_TR_ARBYTE_OFFSET                               0x0072 //2
#define VMX_GUEST_TR_LIMIT_OFFSET                                0x0074 //4
#define VMX_GUEST_TR_BASE_OFFSET                                 0x0078 //8
#define VMX_GUEST_FS_SELECTOR_OFFSET                             0x0080 //2
#define VMX_GUEST_FS_ARBYTE_OFFSET                               0x0082 //2
#define VMX_GUEST_FS_LIMIT_OFFSET                                0x0084 //4
#define VMX_GUEST_FS_BASE_OFFSET                                 0x0088 //8
#define VMX_GUEST_GS_SELECTOR_OFFSET                             0x0090 //2
#define VMX_GUEST_GS_ARBYTE_OFFSET                               0x0092 //2
#define VMX_GUEST_GS_LIMIT_OFFSET                                0x0094 //4
#define VMX_GUEST_GS_BASE_OFFSET                                 0x0098 //8
#define VMX_NO_COMMIT_THRESHOLD_OFFSET                           0x00a0 //4
#define VMX_GUEST_GDTR_LIMIT_OFFSET                              0x00a4 //4
#define VMX_GUEST_GDTR_BASE_OFFSET                               0x00a8 //8
#define VMX_RSVD_32_BIT_GUEST_STATE_OFFSET                       0x00b0 //4
#define VMX_GUEST_IDTR_LIMIT_OFFSET                              0x00b4 //4
#define VMX_GUEST_IDTR_BASE_OFFSET                               0x00b8 //8
#define VMX_HOST_ES_SELECTOR_OFFSET                              0x00c0 //2
#define VMX_HOST_CS_SELECTOR_OFFSET                              0x00c2 //2
#define VMX_HOST_SS_SELECTOR_OFFSET                              0x00c4 //2
#define VMX_HOST_DS_SELECTOR_OFFSET                              0x00c6 //2
#define VMX_HOST_FS_SELECTOR_OFFSET                              0x00c8 //2
#define VMX_HOST_GS_SELECTOR_OFFSET                              0x00ca //2
#define VMX_HOST_TR_SELECTOR_OFFSET                              0x00cc //2
#define VMX_GUEST_VPID_OFFSET                                    0x00ce //2
#define VMX_OSV_CVP_FULL_OFFSET                                  0x00d0 //8
#define VMX_OSV_CVP_HIGH_OFFSET                                  0xd4   //4
#define VMX_VMCS_LAUNCH_STATE_OFFSET                             0x00d8 //4
#define VMX_VM_INSTRUCTION_ERRORCODE_OFFSET                      0x00dc //4
#define VMX_GUEST_HIDDEN_PND_DEBUG_EXCEPTION_OFFSET              0x00e0 //8
#define VMX_GUEST_HIDDEN_RFLAGS_OFFSET                           0x00e8 //8
#define VMX_PAUSE_LOOP_EXITING_GAP_OFFSET                        0x00f0 //4
#define VMX_PAUSE_LOOP_EXITING_WINDOW_OFFSET                     0x00f4 //4
#define VMX_GUEST_SAVED_WORKING_VMCS_POINTER_FULL_OFFSET         0x00f8 //8
#define VMX_GUEST_SAVED_WORKING_VMCS_POINTER_HIGH_OFFSET         0xfc   //4
#define VMX_GUEST_IA32_DEBUGCTLMSR_FULL_OFFSET                   0x0100 //8
#define VMX_GUEST_IA32_DEBUGCTLMSR_HIGH_OFFSET                   0x104  //4
#define VMX_GUEST_IA32_PAT_FULL_OFFSET                           0x0108 //8
#define VMX_GUEST_IA32_PAT_HIGH_OFFSET                           0x10c  //4
#define VMX_GUEST_IA32_EFER_FULL_OFFSET                          0x0110 //8
#define VMX_GUEST_IA32_EFER_HIGH_OFFSET                          0x114  //4
#define VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_FULL_OFFSET           0x0118 //8
#define VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_HIGH_OFFSET           0x11c  //4
#define VMX_VM_EXECUTION_CONTROL_PROC_BASED_OFFSET               0x0120 //4
#define VMX_VM_EXECUTION_CONTROL_SECONDARY_PROC_BASED_OFFSET     0x0124 //4
#define VMX_VM_EXECUTION_CONTROL_PIN_BASED_OFFSET                0x0128 //4
#define VMX_TPR_THRESHOLD_OFFSET                                 0x012c //4
#define VMX_PAGEFAULT_ERRORCODE_MASK_OFFSET                      0x0130 //4
#define VMX_PAGEFAULT_ERRORCODE_MATCH_OFFSET                     0x0134 //4
#define VMX_GUEST_INTERRUPTIBILITY_OFFSET                        0x0138 //4
#define VMX_GUEST_SLEEP_STATE_OFFSET                             0x013c //4
#define VMX_GUEST_EPT_POINTER_FULL_OFFSET                        0x0140 //8
#define VMX_GUEST_EPT_POINTER_HIGH_OFFSET                        0x144  //4
#define VMX_GUEST_PHYSICAL_ADDRESS_INFO_FULL_OFFSET              0x0148 //8
#define VMX_GUEST_PHYSICAL_ADDRESS_INFO_HIGH_OFFSET              0x14c  //4
#define VMX_VM_ENTRY_INTR_INFO_OFFSET                            0x0150 //4
#define VMX_VM_ENTRY_EXCEPTION_ERRORCODE_OFFSET                  0x0154 //4
#define VMX_VM_ENTRY_INSTRUCTION_LENGTH_OFFSET                   0x0158 //4
#define VMX_VM_EXIT_CONTROL_OFFSET                               0x015c //4
#define VMX_GUEST_PREEMPTION_TIMER_COUNT_OFFSET                  0x0160 //4
#define VMX_VM_EXIT_MSR_STORE_COUNT_OFFSET                       0x0164 //4
#define VMX_VM_EXIT_MSR_LOAD_COUNT_OFFSET                        0x0168 //4
#define VMX_VM_EXIT_REASON_OFFSET                                0x016c //4
#define VMX_VM_EXIT_EXCEPTION_INFO_OFFSET                        0x0170 //4
#define VMX_VM_EXIT_EXCEPTION_ERRORCODE_OFFSET                   0x0174 //4
#define VMX_VM_EXIT_IDT_VECTOR_FIELD_OFFSET                      0x0178 //4
#define VMX_VM_EXIT_IDT_VECTOR_ERRORCODE_OFFSET                  0x017c //4
#define VMX_VM_EXIT_INSTRUCTION_LENGTH_OFFSET                    0x0180 //4
#define VMX_VM_EXIT_INSTRUCTION_INFO_OFFSET                      0x0184 //4
#define VMX_GUEST_PARENT_VMCS_POINTER_FULL_OFFSET                0x0188 //8
#define VMX_GUEST_PARENT_VMCS_POINTER_HIGH_OFFSET                0x18c  //4
#define VMX_TSC_OFFSET_FULL_OFFSET                               0x0190 //8
#define VMX_TSC_OFFSET_HIGH_OFFSET                               0x194  //4
#define VMX_VM_EXIT_QUALIFICATION_OFFSET                         0x0198 //8
#define VMX_VM_EXIT_IO_RCX_OFFSET                                0x01a0 //8
#define VMX_VM_EXIT_IO_RSI_OFFSET                                0x01a8 //8
#define VMX_VM_EXIT_IO_RDI_OFFSET                                0x01b0 //8
#define VMX_VM_EXIT_IO_RIP_OFFSET                                0x01b8 //8
#define VMX_VM_EXIT_IO_INSTRUCTION_INITIAL_ADDRESS_OFFSET        0x01c0 //8
#define VMX_GUEST_DR7_OFFSET                                     0x01c8 //8
#define VMX_GUEST_RSP_OFFSET                                     0x01d0 //8
#define VMX_GUEST_RIP_OFFSET                                     0x01d8 //8
#define VMX_GUEST_RFLAGS_OFFSET                                  0x01e0 //8
#define VMX_GUEST_PND_DEBUG_EXCEPTION_OFFSET                     0x01e8 //8
#define VMX_GUEST_IA32_SYSENTER_ESP_OFFSET                       0x01f0 //8
#define VMX_GUEST_IA32_SYSENTER_EIP_OFFSET                       0x01f8 //8
#define VMX_GUEST_IA32_SYSENTER_CS_OFFSET                        0x0200 //4
#define VMX_EPTP_INDEX_OFFSET                                    0x0204 //2
#define VMX_HLAT_PLR_PFX_SIZE_OFFSET                             0x0206 //2
#define VMX_GUEST_CR0_OFFSET                                     0x0208 //8
#define VMX_GUEST_CR3_OFFSET                                     0x0210 //8
#define VMX_GUEST_CR4_OFFSET                                     0x0218 //8
#define VMX_GUEST_PDPTR0_FULL_OFFSET                             0x0220 //8
#define VMX_GUEST_PDPTR0_HIGH_OFFSET                             0x224  //4
#define VMX_GUEST_PDPTR1_FULL_OFFSET                             0x0228 //8
#define VMX_GUEST_PDPTR1_HIGH_OFFSET                             0x22c  //4
#define VMX_GUEST_PDPTR2_FULL_OFFSET                             0x0230 //8
#define VMX_GUEST_PDPTR2_HIGH_OFFSET                             0x234  //4
#define VMX_GUEST_PDPTR3_FULL_OFFSET                             0x0238 //8
#define VMX_GUEST_PDPTR3_HIGH_OFFSET                             0x23c  //4
#define VMX_CR0_GUEST_HOST_MASK_OFFSET                           0x0240 //8
#define VMX_CR4_GUEST_HOST_MASK_OFFSET                           0x0248 //8
#define VMX_CR0_READ_SHADOW_OFFSET                               0x0250 //8
#define VMX_CR4_READ_SHADOW_OFFSET                               0x0258 //8
#define VMX_CR3_TARGET_VALUE_0_OFFSET                            0x0260 //8
#define VMX_CR3_TARGET_VALUE_1_OFFSET                            0x0268 //8
#define VMX_CR3_TARGET_VALUE_2_OFFSET                            0x0270 //8
#define VMX_CR3_TARGET_VALUE_3_OFFSET                            0x0278 //8
#define VMX_EOI_EXIT_TABLE_0_FULL_OFFSET                         0x0280 //8
#define VMX_EOI_EXIT_TABLE_0_HIGH_OFFSET                         0x284  //4
#define VMX_EOI_EXIT_TABLE_1_FULL_OFFSET                         0x0288 //8
#define VMX_EOI_EXIT_TABLE_1_HIGH_OFFSET                         0x28c  //4
#define VMX_EOI_EXIT_TABLE_2_FULL_OFFSET                         0x0290 //8
#define VMX_EOI_EXIT_TABLE_2_HIGH_OFFSET                         0x294  //4
#define VMX_EOI_EXIT_TABLE_3_FULL_OFFSET                         0x0298 //8
#define VMX_EOI_EXIT_TABLE_3_HIGH_OFFSET                         0x29c  //4
#define VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_FULL_OFFSET      0x02a0 //8
#define VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_HIGH_OFFSET      0x2a4  //4
#define VMX_GUEST_SMBASE_OFFSET                                  0x02a8 //4
#define VMX_POSTED_INTERRUPT_NOTIFICATION_VECTOR_OFFSET          0x02ac //2
#define VMX_GUEST_UINV_OFFSET                                    0x02ae //2
#define VMX_EXCEPTION_BITMAP_OFFSET                              0x02b0 //4
#define VMX_CR3_TARGET_COUNT_OFFSET                              0x02b4 //4
#define VMX_VM_ENTRY_CONTROL_OFFSET                              0x02b8 //4
#define VMX_VM_ENTRY_MSR_LOAD_COUNT_OFFSET                       0x02bc //4
#define VMX_VIRTUAL_APIC_PAGE_ADDRESS_FULL_OFFSET                0x02c0 //8
#define VMX_VIRTUAL_APIC_PAGE_ADDRESS_HIGH_OFFSET                0x2c4  //4
#define VMX_IO_BITMAP_A_PHYPTR_FULL_OFFSET                       0x02c8 //8
#define VMX_IO_BITMAP_A_PHYPTR_HIGH_OFFSET                       0x2cc  //4
#define VMX_IO_BITMAP_B_PHYPTR_FULL_OFFSET                       0x02d0 //8
#define VMX_IO_BITMAP_B_PHYPTR_HIGH_OFFSET                       0x2d4  //4
#define VMX_EXIT_MSR_STORE_PHYPTR_FULL_OFFSET                    0x02d8 //8
#define VMX_EXIT_MSR_STORE_PHYPTR_HIGH_OFFSET                    0x2dc  //4
#define VMX_EXIT_MSR_LOAD_PHYPTR_FULL_OFFSET                     0x02e0 //8
#define VMX_EXIT_MSR_LOAD_PHYPTR_HIGH_OFFSET                     0x2e4  //4
#define VMX_ENTRY_MSR_LOAD_PHYPTR_FULL_OFFSET                    0x02e8 //8
#define VMX_ENTRY_MSR_LOAD_PHYPTR_HIGH_OFFSET                    0x2ec  //4
#define VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_FULL_OFFSET         0x02f0 //8
#define VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_HIGH_OFFSET         0x2f4  //4
#define VMX_MSR_BITMAP_PHYPTR_FULL_OFFSET                        0x02f8 //8
#define VMX_MSR_BITMAP_PHYPTR_HIGH_OFFSET                        0x2fc  //4
#define VMX_HOST_RSP_OFFSET                                      0x0300 //8
#define VMX_HOST_RIP_OFFSET                                      0x0308 //8
#define VMX_HOST_IA32_PAT_FULL_OFFSET                            0x0310 //8
#define VMX_HOST_IA32_PAT_HIGH_OFFSET                            0x314  //4
#define VMX_HOST_IA32_EFER_FULL_OFFSET                           0x0318 //8
#define VMX_HOST_IA32_EFER_HIGH_OFFSET                           0x31c  //4
#define VMX_HOST_IA32_PERF_GLOBAL_CONTROL_FULL_OFFSET            0x0320 //8
#define VMX_HOST_IA32_PERF_GLOBAL_CONTROL_HIGH_OFFSET            0x324  //4
#define VMX_HOST_CR0_OFFSET                                      0x0328 //8
#define VMX_HOST_CR3_OFFSET                                      0x0330 //8
#define VMX_HOST_CR4_OFFSET                                      0x0338 //8
#define VMX_HOST_IDTR_BASE_OFFSET                                0x0340 //8
#define VMX_HOST_GDTR_BASE_OFFSET                                0x0348 //8
#define VMX_HOST_FS_BASE_OFFSET                                  0x0350 //8
#define VMX_HOST_GS_BASE_OFFSET                                  0x0358 //8
#define VMX_HOST_TR_BASE_OFFSET                                  0x0360 //8
#define VMX_HOST_IA32_SYSENTER_ESP_OFFSET                        0x0368 //8
#define VMX_HOST_IA32_SYSENTER_EIP_OFFSET                        0x0370 //8
#define VMX_HOST_IA32_SYSENTER_CS_OFFSET                         0x0378 //4
#define VMX_GUEST_INTERRUPT_STATUS_OFFSET                        0x037c //2
#define VMX_PML_INDEX_OFFSET                                     0x037e //2
#define VMX_VM_FUNCTION_CONTROLS_FULL_OFFSET                     0x0380 //8
#define VMX_VM_FUNCTION_CONTROLS_HIGH_OFFSET                     0x384  //4
#define VMX_EPTP_LIST_ADDRESS_FULL_OFFSET                        0x0388 //8
#define VMX_EPTP_LIST_ADDRESS_HIGH_OFFSET                        0x38c  //4
#define VMX_VMREAD_BITMAP_ADDRESS_FULL_OFFSET                    0x0390 //8
#define VMX_VMREAD_BITMAP_ADDRESS_HIGH_OFFSET                    0x394  //4
#define VMX_VMWRITE_BITMAP_ADDRESS_FULL_OFFSET                   0x0398 //8
#define VMX_VMWRITE_BITMAP_ADDRESS_HIGH_OFFSET                   0x39c  //4
#define VMX_PML_LOG_ADDRESS_FULL_OFFSET                          0x03a0 //8
#define VMX_PML_LOG_ADDRESS_HIGH_OFFSET                          0x3a4  //4
#define VMX_XSS_EXIT_CONTROL_FULL_OFFSET                         0x03a8 //8
#define VMX_XSS_EXIT_CONTROL_HIGH_OFFSET                         0x3ac  //4
#define VMX_ENCLS_EXIT_CONTROL_FULL_OFFSET                       0x03b0 //8
#define VMX_ENCLS_EXIT_CONTROL_HIGH_OFFSET                       0x3b4  //4
#define VMX_RSVD_64_BIT_VMEXIT_DATA_FULL_OFFSET                  0x03b8 //8
#define VMX_RSVD_64_BIT_VMEXIT_DATA_HIGH_OFFSET                  0x3bc  //4
#define VMX_ENCLV_EXIT_CONTROL_FULL_OFFSET                       0x03c0 //8
#define VMX_ENCLV_EXIT_CONTROL_HIGH_OFFSET                       0x3c4  //4
#define VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_FULL_OFFSET           0x03c8 //8
#define VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_HIGH_OFFSET           0x3cc  //4
#define VMX_GUEST_BNDCFGS_FULL_OFFSET                            0x03d0 //8
#define VMX_GUEST_BNDCFGS_HIGH_OFFSET                            0x3d4  //4
#define VMX_SPPTP_FULL_OFFSET                                    0x03d8 //8
#define VMX_SPPTP_HIGH_OFFSET                                    0x3dc  //4
#define VMX_TSC_MULTIPLIER_FULL_OFFSET                           0x03e0 //8
#define VMX_TSC_MULTIPLIER_HIGH_OFFSET                           0x3e4  //4
#define VMX_GUEST_RTIT_CTL_FULL_OFFSET                           0x03e8 //8
#define VMX_GUEST_RTIT_CTL_HIGH_OFFSET                           0x3ec  //4
#define VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_FULL_OFFSET 0x03f0 //8
#define VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_HIGH_OFFSET 0x3f4  //4
#define VMX_GUEST_SHARED_EPT_POINTER_FULL_OFFSET                 0x03f8 //8
#define VMX_GUEST_SHARED_EPT_POINTER_HIGH_OFFSET                 0x3fc  //4
#define VMX_PCONFIG_EXITING_FULL_OFFSET                          0x0400 //8
#define VMX_PCONFIG_EXITING_HIGH_OFFSET                          0x404  //4
#define VMX_HLATP_FULL_OFFSET                                    0x0408 //8
#define VMX_HLATP_HIGH_OFFSET                                    0x40c  //4
#define VMX_PID_POINTER_TABLE_ADDRESS_FULL_OFFSET                0x0410 //8
#define VMX_PID_POINTER_TABLE_ADDRESS_HIGH_OFFSET                0x414  //4
#define VMX_SECONDARY_EXIT_CTLS_FULL_OFFSET                      0x0418 //8
#define VMX_SECONDARY_EXIT_CTLS_HIGH_OFFSET                      0x41c  //4
#define VMX_PASID_LOW_FULL_OFFSET                                0x0420 //8
#define VMX_PASID_LOW_HIGH_OFFSET                                0x424  //4
#define VMX_PASID_HIGH_FULL_OFFSET                               0x0428 //8
#define VMX_PASID_HIGH_HIGH_OFFSET                               0x42c  //4
#define VMX_GUEST_IA32_LBR_CTL_FULL_OFFSET                       0x0430 //8
#define VMX_GUEST_IA32_LBR_CTL_HIGH_OFFSET                       0x434  //4
#define VMX_HOST_IA32_INTERRUPT_SSP_TABLE_ADDR_OFFSET            0x0438 //8
#define VMX_GUEST_IA32_S_CET_OFFSET                              0x0440 //8
#define VMX_GUEST_SSP_OFFSET                                     0x0448 //8
#define VMX_GUEST_IA32_INTERRUPT_SSP_TABLE_ADDR_OFFSET           0x0450 //8
#define VMX_HOST_IA32_S_CET_OFFSET                               0x0458 //8
#define VMX_HOST_SSP_OFFSET                                      0x0460 //8
#define VMX_LAST_PID_POINTER_INDEX_OFFSET                        0x0468 //2
#define VMX_RESERVED_1_OFFSET                                    0x046a //2
#define VMX_GUEST_TD_HKID_OFFSET                                 0x046c //4
#define VMX_INTER_VM_IPI_PHYSADDR_BASE_FULL_OFFSET               0x0470 //8
#define VMX_INTER_VM_IPI_PHYSADDR_BASE_HIGH_OFFSET               0x474  //4
#define VMX_RSVD_32_BIT_CONTROL_OFFSET                           0x0478 //4
#define VMX_RESERVED_2_OFFSET                                    0x047c //4
#define VMX_HOST_PKRS_FULL_OFFSET                                0x0480 //8
#define VMX_HOST_PKRS_HIGH_OFFSET                                0x484  //4
#define VMX_GUEST_PKRS_FULL_OFFSET                               0x0488 //8
#define VMX_GUEST_PKRS_HIGH_OFFSET                               0x48c  //4
#define VMX_VCH_LIST_PHYSADDR_BASE_FULL_OFFSET                   0x0490 //8
#define VMX_VCH_LIST_PHYSADDR_BASE_HIGH_OFFSET                   0x494  //4
#define VMX_RSVD_64_BIT_CONTROL_4_FULL_OFFSET                    0x0498 //8
#define VMX_RSVD_64_BIT_CONTROL_4_HIGH_OFFSET                    0x49c  //4
#define VMX_RSVD_64_BIT_CONTROL_5_FULL_OFFSET                    0x04a0 //8
#define VMX_RSVD_64_BIT_CONTROL_5_HIGH_OFFSET                    0x4a4  //4
#define VMX_RESERVED_3_OFFSET                                    0x04a8 //88
#define PPPE_GUEST_RAX_OFFSET                                    0x0500 //8
#define PPPE_GUEST_RCX_OFFSET                                    0x0508 //8
#define PPPE_GUEST_RDX_OFFSET                                    0x0510 //8
#define PPPE_GUEST_RBX_OFFSET                                    0x0518 //8
#define PPPE_GUEST_RSP_OFFSET                                    0x0520 //8
#define PPPE_GUEST_RBP_OFFSET                                    0x0528 //8
#define PPPE_GUEST_RSI_OFFSET                                    0x0530 //8
#define PPPE_GUEST_RDI_OFFSET                                    0x0538 //8
#define PPPE_GUEST_R8_OFFSET                                     0x0540 //8
#define PPPE_GUEST_R9_OFFSET                                     0x0548 //8
#define PPPE_GUEST_R10_OFFSET                                    0x0550 //8
#define PPPE_GUEST_R11_OFFSET                                    0x0558 //8
#define PPPE_GUEST_R12_OFFSET                                    0x0560 //8
#define PPPE_GUEST_R13_OFFSET                                    0x0568 //8
#define PPPE_GUEST_R14_OFFSET                                    0x0570 //8
#define PPPE_GUEST_R15_OFFSET                                    0x0578 //8
#define PPPE_VMEXIT_INJECTION_OFFSET                             0x0580 //8
#define PPPE_FROM_RIP_OFFSET                                     0x0588 //8
#define PPPE_PAGE_FAULT_ADDRESS_OFFSET                           0x0590 //8
#define PPPE_VM_ENTRY_CONTROL_OFFSET                             0x0598 //8
#define PPPE_VMCS_CHILD_POINTER_OFFSET                           0x05a0 //8
#define PPPE_UNWIND_OFFSET                                       0x05a8 //8
#define PPPE_GUEST_DOORBELL_INHIBITS_OFFSET                      0x05b0 //8
#define PPPE_GUEST_MISC_UARCH_STATE_OFFSET                       0x05b8 //8
#define PPPE_GUEST_INSTRUCTION_OPCODE_OFFSET                     0x05c0 //8
#define PPPE_GUEST_INSTRUCTION_DISPLACEMENT_OFFSET               0x05c8 //8
#define PPPE_GUEST_INSTRUCTION_IMMEDIATE_OFFSET                  0x05d0 //8
#define PPPE_GUEST_EXCEPTION_INHIBITS_OFFSET                     0x05d8 //8
#define PPPE_GUEST_SSP_OFFSET                                    0x05e0 //8
#define PPPE_PRE_VM_EXIT_VMCS_LEVEL_OFFSET                       0x05e8 //4
#define VMX_RESERVED_4_OFFSET                                    0x05ec //2580

////////////////////////////////////////////////////////////////////////////
// RPC_B0_VMX_VMCS - VMCS SIZES
////////////////////////////////////////////////////////////////////////////

#define VMX_VMCS_REVISION_ID_SIZE                              4
#define VMX_ABORT_INDICATOR_SIZE                               4
#define VMCS_CACHING_ARCH_PTR_SIZE                             8
#define VMCS_CACHING_SAVED_DIRTY_BITS_SIZE                     4
#define VMCS_CACHING_UARCH_INFO_SIZE                           2
#define VMX_RESERVED_0_SIZE                                    10
#define VMX_GUEST_ES_SELECTOR_SIZE                             2
#define VMX_GUEST_ES_ARBYTE_SIZE                               2
#define VMX_GUEST_ES_LIMIT_SIZE                                4
#define VMX_GUEST_ES_BASE_SIZE                                 8
#define VMX_GUEST_CS_SELECTOR_SIZE                             2
#define VMX_GUEST_CS_ARBYTE_SIZE                               2
#define VMX_GUEST_CS_LIMIT_SIZE                                4
#define VMX_GUEST_CS_BASE_SIZE                                 8
#define VMX_GUEST_SS_SELECTOR_SIZE                             2
#define VMX_GUEST_SS_ARBYTE_SIZE                               2
#define VMX_GUEST_SS_LIMIT_SIZE                                4
#define VMX_GUEST_SS_BASE_SIZE                                 8
#define VMX_GUEST_DS_SELECTOR_SIZE                             2
#define VMX_GUEST_DS_ARBYTE_SIZE                               2
#define VMX_GUEST_DS_LIMIT_SIZE                                4
#define VMX_GUEST_DS_BASE_SIZE                                 8
#define VMX_GUEST_LDTR_SELECTOR_SIZE                           2
#define VMX_GUEST_LDTR_ARBYTE_SIZE                             2
#define VMX_GUEST_LDTR_LIMIT_SIZE                              4
#define VMX_GUEST_LDTR_BASE_SIZE                               8
#define VMX_GUEST_TR_SELECTOR_SIZE                             2
#define VMX_GUEST_TR_ARBYTE_SIZE                               2
#define VMX_GUEST_TR_LIMIT_SIZE                                4
#define VMX_GUEST_TR_BASE_SIZE                                 8
#define VMX_GUEST_FS_SELECTOR_SIZE                             2
#define VMX_GUEST_FS_ARBYTE_SIZE                               2
#define VMX_GUEST_FS_LIMIT_SIZE                                4
#define VMX_GUEST_FS_BASE_SIZE                                 8
#define VMX_GUEST_GS_SELECTOR_SIZE                             2
#define VMX_GUEST_GS_ARBYTE_SIZE                               2
#define VMX_GUEST_GS_LIMIT_SIZE                                4
#define VMX_GUEST_GS_BASE_SIZE                                 8
#define VMX_NO_COMMIT_THRESHOLD_SIZE                           4
#define VMX_GUEST_GDTR_LIMIT_SIZE                              4
#define VMX_GUEST_GDTR_BASE_SIZE                               8
#define VMX_RSVD_32_BIT_GUEST_STATE_SIZE                       4
#define VMX_GUEST_IDTR_LIMIT_SIZE                              4
#define VMX_GUEST_IDTR_BASE_SIZE                               8
#define VMX_HOST_ES_SELECTOR_SIZE                              2
#define VMX_HOST_CS_SELECTOR_SIZE                              2
#define VMX_HOST_SS_SELECTOR_SIZE                              2
#define VMX_HOST_DS_SELECTOR_SIZE                              2
#define VMX_HOST_FS_SELECTOR_SIZE                              2
#define VMX_HOST_GS_SELECTOR_SIZE                              2
#define VMX_HOST_TR_SELECTOR_SIZE                              2
#define VMX_GUEST_VPID_SIZE                                    2
#define VMX_OSV_CVP_FULL_SIZE                                  8
#define VMX_OSV_CVP_HIGH_SIZE                                  4
#define VMX_VMCS_LAUNCH_STATE_SIZE                             4
#define VMX_VM_INSTRUCTION_ERRORCODE_SIZE                      4
#define VMX_GUEST_HIDDEN_PND_DEBUG_EXCEPTION_SIZE              8
#define VMX_GUEST_HIDDEN_RFLAGS_SIZE                           8
#define VMX_PAUSE_LOOP_EXITING_GAP_SIZE                        4
#define VMX_PAUSE_LOOP_EXITING_WINDOW_SIZE                     4
#define VMX_GUEST_SAVED_WORKING_VMCS_POINTER_FULL_SIZE         8
#define VMX_GUEST_SAVED_WORKING_VMCS_POINTER_HIGH_SIZE         4
#define VMX_GUEST_IA32_DEBUGCTLMSR_FULL_SIZE                   8
#define VMX_GUEST_IA32_DEBUGCTLMSR_HIGH_SIZE                   4
#define VMX_GUEST_IA32_PAT_FULL_SIZE                           8
#define VMX_GUEST_IA32_PAT_HIGH_SIZE                           4
#define VMX_GUEST_IA32_EFER_FULL_SIZE                          8
#define VMX_GUEST_IA32_EFER_HIGH_SIZE                          4
#define VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_FULL_SIZE           8
#define VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_HIGH_SIZE           4
#define VMX_VM_EXECUTION_CONTROL_PROC_BASED_SIZE               4
#define VMX_VM_EXECUTION_CONTROL_SECONDARY_PROC_BASED_SIZE     4
#define VMX_VM_EXECUTION_CONTROL_PIN_BASED_SIZE                4
#define VMX_TPR_THRESHOLD_SIZE                                 4
#define VMX_PAGEFAULT_ERRORCODE_MASK_SIZE                      4
#define VMX_PAGEFAULT_ERRORCODE_MATCH_SIZE                     4
#define VMX_GUEST_INTERRUPTIBILITY_SIZE                        4
#define VMX_GUEST_SLEEP_STATE_SIZE                             4
#define VMX_GUEST_EPT_POINTER_FULL_SIZE                        8
#define VMX_GUEST_EPT_POINTER_HIGH_SIZE                        4
#define VMX_GUEST_PHYSICAL_ADDRESS_INFO_FULL_SIZE              8
#define VMX_GUEST_PHYSICAL_ADDRESS_INFO_HIGH_SIZE              4
#define VMX_VM_ENTRY_INTR_INFO_SIZE                            4
#define VMX_VM_ENTRY_EXCEPTION_ERRORCODE_SIZE                  4
#define VMX_VM_ENTRY_INSTRUCTION_LENGTH_SIZE                   4
#define VMX_VM_EXIT_CONTROL_SIZE                               4
#define VMX_GUEST_PREEMPTION_TIMER_COUNT_SIZE                  4
#define VMX_VM_EXIT_MSR_STORE_COUNT_SIZE                       4
#define VMX_VM_EXIT_MSR_LOAD_COUNT_SIZE                        4
#define VMX_VM_EXIT_REASON_SIZE                                4
#define VMX_VM_EXIT_EXCEPTION_INFO_SIZE                        4
#define VMX_VM_EXIT_EXCEPTION_ERRORCODE_SIZE                   4
#define VMX_VM_EXIT_IDT_VECTOR_FIELD_SIZE                      4
#define VMX_VM_EXIT_IDT_VECTOR_ERRORCODE_SIZE                  4
#define VMX_VM_EXIT_INSTRUCTION_LENGTH_SIZE                    4
#define VMX_VM_EXIT_INSTRUCTION_INFO_SIZE                      4
#define VMX_GUEST_PARENT_VMCS_POINTER_FULL_SIZE                8
#define VMX_GUEST_PARENT_VMCS_POINTER_HIGH_SIZE                4
#define VMX_TSC_OFFSET_FULL_SIZE                               8
#define VMX_TSC_OFFSET_HIGH_SIZE                               4
#define VMX_VM_EXIT_QUALIFICATION_SIZE                         8
#define VMX_VM_EXIT_IO_RCX_SIZE                                8
#define VMX_VM_EXIT_IO_RSI_SIZE                                8
#define VMX_VM_EXIT_IO_RDI_SIZE                                8
#define VMX_VM_EXIT_IO_RIP_SIZE                                8
#define VMX_VM_EXIT_IO_INSTRUCTION_INITIAL_ADDRESS_SIZE        8
#define VMX_GUEST_DR7_SIZE                                     8
#define VMX_GUEST_RSP_SIZE                                     8
#define VMX_GUEST_RIP_SIZE                                     8
#define VMX_GUEST_RFLAGS_SIZE                                  8
#define VMX_GUEST_PND_DEBUG_EXCEPTION_SIZE                     8
#define VMX_GUEST_IA32_SYSENTER_ESP_SIZE                       8
#define VMX_GUEST_IA32_SYSENTER_EIP_SIZE                       8
#define VMX_GUEST_IA32_SYSENTER_CS_SIZE                        4
#define VMX_EPTP_INDEX_SIZE                                    2
#define VMX_HLAT_PLR_PFX_SIZE_SIZE                             2
#define VMX_GUEST_CR0_SIZE                                     8
#define VMX_GUEST_CR3_SIZE                                     8
#define VMX_GUEST_CR4_SIZE                                     8
#define VMX_GUEST_PDPTR0_FULL_SIZE                             8
#define VMX_GUEST_PDPTR0_HIGH_SIZE                             4
#define VMX_GUEST_PDPTR1_FULL_SIZE                             8
#define VMX_GUEST_PDPTR1_HIGH_SIZE                             4
#define VMX_GUEST_PDPTR2_FULL_SIZE                             8
#define VMX_GUEST_PDPTR2_HIGH_SIZE                             4
#define VMX_GUEST_PDPTR3_FULL_SIZE                             8
#define VMX_GUEST_PDPTR3_HIGH_SIZE                             4
#define VMX_CR0_GUEST_HOST_MASK_SIZE                           8
#define VMX_CR4_GUEST_HOST_MASK_SIZE                           8
#define VMX_CR0_READ_SHADOW_SIZE                               8
#define VMX_CR4_READ_SHADOW_SIZE                               8
#define VMX_CR3_TARGET_VALUE_0_SIZE                            8
#define VMX_CR3_TARGET_VALUE_1_SIZE                            8
#define VMX_CR3_TARGET_VALUE_2_SIZE                            8
#define VMX_CR3_TARGET_VALUE_3_SIZE                            8
#define VMX_EOI_EXIT_TABLE_0_FULL_SIZE                         8
#define VMX_EOI_EXIT_TABLE_0_HIGH_SIZE                         4
#define VMX_EOI_EXIT_TABLE_1_FULL_SIZE                         8
#define VMX_EOI_EXIT_TABLE_1_HIGH_SIZE                         4
#define VMX_EOI_EXIT_TABLE_2_FULL_SIZE                         8
#define VMX_EOI_EXIT_TABLE_2_HIGH_SIZE                         4
#define VMX_EOI_EXIT_TABLE_3_FULL_SIZE                         8
#define VMX_EOI_EXIT_TABLE_3_HIGH_SIZE                         4
#define VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_FULL_SIZE      8
#define VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_HIGH_SIZE      4
#define VMX_GUEST_SMBASE_SIZE                                  4
#define VMX_POSTED_INTERRUPT_NOTIFICATION_VECTOR_SIZE          2
#define VMX_GUEST_UINV_SIZE                                    2
#define VMX_EXCEPTION_BITMAP_SIZE                              4
#define VMX_CR3_TARGET_COUNT_SIZE                              4
#define VMX_VM_ENTRY_CONTROL_SIZE                              4
#define VMX_VM_ENTRY_MSR_LOAD_COUNT_SIZE                       4
#define VMX_VIRTUAL_APIC_PAGE_ADDRESS_FULL_SIZE                8
#define VMX_VIRTUAL_APIC_PAGE_ADDRESS_HIGH_SIZE                4
#define VMX_IO_BITMAP_A_PHYPTR_FULL_SIZE                       8
#define VMX_IO_BITMAP_A_PHYPTR_HIGH_SIZE                       4
#define VMX_IO_BITMAP_B_PHYPTR_FULL_SIZE                       8
#define VMX_IO_BITMAP_B_PHYPTR_HIGH_SIZE                       4
#define VMX_EXIT_MSR_STORE_PHYPTR_FULL_SIZE                    8
#define VMX_EXIT_MSR_STORE_PHYPTR_HIGH_SIZE                    4
#define VMX_EXIT_MSR_LOAD_PHYPTR_FULL_SIZE                     8
#define VMX_EXIT_MSR_LOAD_PHYPTR_HIGH_SIZE                     4
#define VMX_ENTRY_MSR_LOAD_PHYPTR_FULL_SIZE                    8
#define VMX_ENTRY_MSR_LOAD_PHYPTR_HIGH_SIZE                    4
#define VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_FULL_SIZE         8
#define VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_HIGH_SIZE         4
#define VMX_MSR_BITMAP_PHYPTR_FULL_SIZE                        8
#define VMX_MSR_BITMAP_PHYPTR_HIGH_SIZE                        4
#define VMX_HOST_RSP_SIZE                                      8
#define VMX_HOST_RIP_SIZE                                      8
#define VMX_HOST_IA32_PAT_FULL_SIZE                            8
#define VMX_HOST_IA32_PAT_HIGH_SIZE                            4
#define VMX_HOST_IA32_EFER_FULL_SIZE                           8
#define VMX_HOST_IA32_EFER_HIGH_SIZE                           4
#define VMX_HOST_IA32_PERF_GLOBAL_CONTROL_FULL_SIZE            8
#define VMX_HOST_IA32_PERF_GLOBAL_CONTROL_HIGH_SIZE            4
#define VMX_HOST_CR0_SIZE                                      8
#define VMX_HOST_CR3_SIZE                                      8
#define VMX_HOST_CR4_SIZE                                      8
#define VMX_HOST_IDTR_BASE_SIZE                                8
#define VMX_HOST_GDTR_BASE_SIZE                                8
#define VMX_HOST_FS_BASE_SIZE                                  8
#define VMX_HOST_GS_BASE_SIZE                                  8
#define VMX_HOST_TR_BASE_SIZE                                  8
#define VMX_HOST_IA32_SYSENTER_ESP_SIZE                        8
#define VMX_HOST_IA32_SYSENTER_EIP_SIZE                        8
#define VMX_HOST_IA32_SYSENTER_CS_SIZE                         4
#define VMX_GUEST_INTERRUPT_STATUS_SIZE                        2
#define VMX_PML_INDEX_SIZE                                     2
#define VMX_VM_FUNCTION_CONTROLS_FULL_SIZE                     8
#define VMX_VM_FUNCTION_CONTROLS_HIGH_SIZE                     4
#define VMX_EPTP_LIST_ADDRESS_FULL_SIZE                        8
#define VMX_EPTP_LIST_ADDRESS_HIGH_SIZE                        4
#define VMX_VMREAD_BITMAP_ADDRESS_FULL_SIZE                    8
#define VMX_VMREAD_BITMAP_ADDRESS_HIGH_SIZE                    4
#define VMX_VMWRITE_BITMAP_ADDRESS_FULL_SIZE                   8
#define VMX_VMWRITE_BITMAP_ADDRESS_HIGH_SIZE                   4
#define VMX_PML_LOG_ADDRESS_FULL_SIZE                          8
#define VMX_PML_LOG_ADDRESS_HIGH_SIZE                          4
#define VMX_XSS_EXIT_CONTROL_FULL_SIZE                         8
#define VMX_XSS_EXIT_CONTROL_HIGH_SIZE                         4
#define VMX_ENCLS_EXIT_CONTROL_FULL_SIZE                       8
#define VMX_ENCLS_EXIT_CONTROL_HIGH_SIZE                       4
#define VMX_RSVD_64_BIT_VMEXIT_DATA_FULL_SIZE                  8
#define VMX_RSVD_64_BIT_VMEXIT_DATA_HIGH_SIZE                  4
#define VMX_ENCLV_EXIT_CONTROL_FULL_SIZE                       8
#define VMX_ENCLV_EXIT_CONTROL_HIGH_SIZE                       4
#define VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_FULL_SIZE           8
#define VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_HIGH_SIZE           4
#define VMX_GUEST_BNDCFGS_FULL_SIZE                            8
#define VMX_GUEST_BNDCFGS_HIGH_SIZE                            4
#define VMX_SPPTP_FULL_SIZE                                    8
#define VMX_SPPTP_HIGH_SIZE                                    4
#define VMX_TSC_MULTIPLIER_FULL_SIZE                           8
#define VMX_TSC_MULTIPLIER_HIGH_SIZE                           4
#define VMX_GUEST_RTIT_CTL_FULL_SIZE                           8
#define VMX_GUEST_RTIT_CTL_HIGH_SIZE                           4
#define VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_FULL_SIZE 8
#define VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_HIGH_SIZE 4
#define VMX_GUEST_SHARED_EPT_POINTER_FULL_SIZE                 8
#define VMX_GUEST_SHARED_EPT_POINTER_HIGH_SIZE                 4
#define VMX_PCONFIG_EXITING_FULL_SIZE                          8
#define VMX_PCONFIG_EXITING_HIGH_SIZE                          4
#define VMX_HLATP_FULL_SIZE                                    8
#define VMX_HLATP_HIGH_SIZE                                    4
#define VMX_PID_POINTER_TABLE_ADDRESS_FULL_SIZE                8
#define VMX_PID_POINTER_TABLE_ADDRESS_HIGH_SIZE                4
#define VMX_SECONDARY_EXIT_CTLS_FULL_SIZE                      8
#define VMX_SECONDARY_EXIT_CTLS_HIGH_SIZE                      4
#define VMX_PASID_LOW_FULL_SIZE                                8
#define VMX_PASID_LOW_HIGH_SIZE                                4
#define VMX_PASID_HIGH_FULL_SIZE                               8
#define VMX_PASID_HIGH_HIGH_SIZE                               4
#define VMX_GUEST_IA32_LBR_CTL_FULL_SIZE                       8
#define VMX_GUEST_IA32_LBR_CTL_HIGH_SIZE                       4
#define VMX_HOST_IA32_INTERRUPT_SSP_TABLE_ADDR_SIZE            8
#define VMX_GUEST_IA32_S_CET_SIZE                              8
#define VMX_GUEST_SSP_SIZE                                     8
#define VMX_GUEST_IA32_INTERRUPT_SSP_TABLE_ADDR_SIZE           8
#define VMX_HOST_IA32_S_CET_SIZE                               8
#define VMX_HOST_SSP_SIZE                                      8
#define VMX_LAST_PID_POINTER_INDEX_SIZE                        2
#define VMX_RESERVED_1_SIZE                                    2
#define VMX_GUEST_TD_HKID_SIZE                                 4
#define VMX_INTER_VM_IPI_PHYSADDR_BASE_FULL_SIZE               8
#define VMX_INTER_VM_IPI_PHYSADDR_BASE_HIGH_SIZE               4
#define VMX_RSVD_32_BIT_CONTROL_SIZE                           4
#define VMX_RESERVED_2_SIZE                                    4
#define VMX_HOST_PKRS_FULL_SIZE                                8
#define VMX_HOST_PKRS_HIGH_SIZE                                4
#define VMX_GUEST_PKRS_FULL_SIZE                               8
#define VMX_GUEST_PKRS_HIGH_SIZE                               4
#define VMX_VCH_LIST_PHYSADDR_BASE_FULL_SIZE                   8
#define VMX_VCH_LIST_PHYSADDR_BASE_HIGH_SIZE                   4
#define VMX_RSVD_64_BIT_CONTROL_4_FULL_SIZE                    8
#define VMX_RSVD_64_BIT_CONTROL_4_HIGH_SIZE                    4
#define VMX_RSVD_64_BIT_CONTROL_5_FULL_SIZE                    8
#define VMX_RSVD_64_BIT_CONTROL_5_HIGH_SIZE                    4
#define VMX_RESERVED_3_SIZE                                    88
#define PPPE_GUEST_RAX_SIZE                                    8
#define PPPE_GUEST_RCX_SIZE                                    8
#define PPPE_GUEST_RDX_SIZE                                    8
#define PPPE_GUEST_RBX_SIZE                                    8
#define PPPE_GUEST_RSP_SIZE                                    8
#define PPPE_GUEST_RBP_SIZE                                    8
#define PPPE_GUEST_RSI_SIZE                                    8
#define PPPE_GUEST_RDI_SIZE                                    8
#define PPPE_GUEST_R8_SIZE                                     8
#define PPPE_GUEST_R9_SIZE                                     8
#define PPPE_GUEST_R10_SIZE                                    8
#define PPPE_GUEST_R11_SIZE                                    8
#define PPPE_GUEST_R12_SIZE                                    8
#define PPPE_GUEST_R13_SIZE                                    8
#define PPPE_GUEST_R14_SIZE                                    8
#define PPPE_GUEST_R15_SIZE                                    8
#define PPPE_VMEXIT_INJECTION_SIZE                             8
#define PPPE_FROM_RIP_SIZE                                     8
#define PPPE_PAGE_FAULT_ADDRESS_SIZE                           8
#define PPPE_VM_ENTRY_CONTROL_SIZE                             8
#define PPPE_VMCS_CHILD_POINTER_SIZE                           8
#define PPPE_UNWIND_SIZE                                       8
#define PPPE_GUEST_DOORBELL_INHIBITS_SIZE                      8
#define PPPE_GUEST_MISC_UARCH_STATE_SIZE                       8
#define PPPE_GUEST_INSTRUCTION_OPCODE_SIZE                     8
#define PPPE_GUEST_INSTRUCTION_DISPLACEMENT_SIZE               8
#define PPPE_GUEST_INSTRUCTION_IMMEDIATE_SIZE                  8
#define PPPE_GUEST_EXCEPTION_INHIBITS_SIZE                     8
#define PPPE_GUEST_SSP_SIZE                                    8
#define PPPE_PRE_VM_EXIT_VMCS_LEVEL_SIZE                       4
#define VMX_RESERVED_4_SIZE                                    2580

////////////////////////////////////////////////////////////////////////////
// RPC_B0_VMX_VMCS - VMCS ENCODINGS
////////////////////////////////////////////////////////////////////////////

#define VMX_GUEST_ES_SELECTOR_ENCODE                             0x0800
#define VMX_GUEST_ES_ARBYTE_ENCODE                               0x4814
#define VMX_GUEST_ES_LIMIT_ENCODE                                0x4800
#define VMX_GUEST_ES_BASE_ENCODE                                 0x6806
#define VMX_GUEST_CS_SELECTOR_ENCODE                             0x0802
#define VMX_GUEST_CS_ARBYTE_ENCODE                               0x4816
#define VMX_GUEST_CS_LIMIT_ENCODE                                0x4802
#define VMX_GUEST_CS_BASE_ENCODE                                 0x6808
#define VMX_GUEST_SS_SELECTOR_ENCODE                             0x0804
#define VMX_GUEST_SS_ARBYTE_ENCODE                               0x4818
#define VMX_GUEST_SS_LIMIT_ENCODE                                0x4804
#define VMX_GUEST_SS_BASE_ENCODE                                 0x680A
#define VMX_GUEST_DS_SELECTOR_ENCODE                             0x0806
#define VMX_GUEST_DS_ARBYTE_ENCODE                               0x481A
#define VMX_GUEST_DS_LIMIT_ENCODE                                0x4806
#define VMX_GUEST_DS_BASE_ENCODE                                 0x680C
#define VMX_GUEST_LDTR_SELECTOR_ENCODE                           0x080C
#define VMX_GUEST_LDTR_ARBYTE_ENCODE                             0x4820
#define VMX_GUEST_LDTR_LIMIT_ENCODE                              0x480C
#define VMX_GUEST_LDTR_BASE_ENCODE                               0x6812
#define VMX_GUEST_TR_SELECTOR_ENCODE                             0x080E
#define VMX_GUEST_TR_ARBYTE_ENCODE                               0x4822
#define VMX_GUEST_TR_LIMIT_ENCODE                                0x480E
#define VMX_GUEST_TR_BASE_ENCODE                                 0x6814
#define VMX_GUEST_FS_SELECTOR_ENCODE                             0x0808
#define VMX_GUEST_FS_ARBYTE_ENCODE                               0x481C
#define VMX_GUEST_FS_LIMIT_ENCODE                                0x4808
#define VMX_GUEST_FS_BASE_ENCODE                                 0x680E
#define VMX_GUEST_GS_SELECTOR_ENCODE                             0x080A
#define VMX_GUEST_GS_ARBYTE_ENCODE                               0x481E
#define VMX_GUEST_GS_LIMIT_ENCODE                                0x480A
#define VMX_GUEST_GS_BASE_ENCODE                                 0x6810
#define VMX_NO_COMMIT_THRESHOLD_ENCODE                           0x4024
#define VMX_GUEST_GDTR_LIMIT_ENCODE                              0x4810
#define VMX_GUEST_GDTR_BASE_ENCODE                               0x6816
#define VMX_RSVD_32_BIT_GUEST_STATE_ENCODE                       0x4830
#define VMX_GUEST_IDTR_LIMIT_ENCODE                              0x4812
#define VMX_GUEST_IDTR_BASE_ENCODE                               0x6818
#define VMX_HOST_ES_SELECTOR_ENCODE                              0x0C00
#define VMX_HOST_CS_SELECTOR_ENCODE                              0x0C02
#define VMX_HOST_SS_SELECTOR_ENCODE                              0x0C04
#define VMX_HOST_DS_SELECTOR_ENCODE                              0x0C06
#define VMX_HOST_FS_SELECTOR_ENCODE                              0x0C08
#define VMX_HOST_GS_SELECTOR_ENCODE                              0x0C0A
#define VMX_HOST_TR_SELECTOR_ENCODE                              0x0C0C
#define VMX_GUEST_VPID_ENCODE                                    0x0000
#define VMX_OSV_CVP_FULL_ENCODE                                  0x200C
#define VMX_OSV_CVP_HIGH_ENCODE                                  0x200d
#define VMX_VM_INSTRUCTION_ERRORCODE_ENCODE                      0x4400
#define VMX_PAUSE_LOOP_EXITING_GAP_ENCODE                        0x4020
#define VMX_PAUSE_LOOP_EXITING_WINDOW_ENCODE                     0x4022
#define VMX_GUEST_SAVED_WORKING_VMCS_POINTER_FULL_ENCODE         0x2800
#define VMX_GUEST_SAVED_WORKING_VMCS_POINTER_HIGH_ENCODE         0x2801
#define VMX_GUEST_IA32_DEBUGCTLMSR_FULL_ENCODE                   0x2802
#define VMX_GUEST_IA32_DEBUGCTLMSR_HIGH_ENCODE                   0x2803
#define VMX_GUEST_IA32_PAT_FULL_ENCODE                           0x2804
#define VMX_GUEST_IA32_PAT_HIGH_ENCODE                           0x2805
#define VMX_GUEST_IA32_EFER_FULL_ENCODE                          0x2806
#define VMX_GUEST_IA32_EFER_HIGH_ENCODE                          0x2807
#define VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_FULL_ENCODE           0x2808
#define VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_HIGH_ENCODE           0x2809
#define VMX_VM_EXECUTION_CONTROL_PROC_BASED_ENCODE               0x4002
#define VMX_VM_EXECUTION_CONTROL_SECONDARY_PROC_BASED_ENCODE     0x401E
#define VMX_VM_EXECUTION_CONTROL_PIN_BASED_ENCODE                0x4000
#define VMX_TPR_THRESHOLD_ENCODE                                 0x401C
#define VMX_PAGEFAULT_ERRORCODE_MASK_ENCODE                      0x4006
#define VMX_PAGEFAULT_ERRORCODE_MATCH_ENCODE                     0x4008
#define VMX_GUEST_INTERRUPTIBILITY_ENCODE                        0x4824
#define VMX_GUEST_SLEEP_STATE_ENCODE                             0x4826
#define VMX_GUEST_EPT_POINTER_FULL_ENCODE                        0x201A
#define VMX_GUEST_EPT_POINTER_HIGH_ENCODE                        0x201b
#define VMX_GUEST_PHYSICAL_ADDRESS_INFO_FULL_ENCODE              0x2400
#define VMX_GUEST_PHYSICAL_ADDRESS_INFO_HIGH_ENCODE              0x2401
#define VMX_VM_ENTRY_INTR_INFO_ENCODE                            0x4016
#define VMX_VM_ENTRY_EXCEPTION_ERRORCODE_ENCODE                  0x4018
#define VMX_VM_ENTRY_INSTRUCTION_LENGTH_ENCODE                   0x401A
#define VMX_VM_EXIT_CONTROL_ENCODE                               0x400C
#define VMX_GUEST_PREEMPTION_TIMER_COUNT_ENCODE                  0x482E
#define VMX_VM_EXIT_MSR_STORE_COUNT_ENCODE                       0x400E
#define VMX_VM_EXIT_MSR_LOAD_COUNT_ENCODE                        0x4010
#define VMX_VM_EXIT_REASON_ENCODE                                0x4402
#define VMX_VM_EXIT_EXCEPTION_INFO_ENCODE                        0x4404
#define VMX_VM_EXIT_EXCEPTION_ERRORCODE_ENCODE                   0x4406
#define VMX_VM_EXIT_IDT_VECTOR_FIELD_ENCODE                      0x4408
#define VMX_VM_EXIT_IDT_VECTOR_ERRORCODE_ENCODE                  0x440A
#define VMX_VM_EXIT_INSTRUCTION_LENGTH_ENCODE                    0x440C
#define VMX_VM_EXIT_INSTRUCTION_INFO_ENCODE                      0x440E
#define VMX_TSC_OFFSET_FULL_ENCODE                               0x2010
#define VMX_TSC_OFFSET_HIGH_ENCODE                               0x2011
#define VMX_VM_EXIT_QUALIFICATION_ENCODE                         0x6400
#define VMX_VM_EXIT_IO_RCX_ENCODE                                0x6402
#define VMX_VM_EXIT_IO_RSI_ENCODE                                0x6404
#define VMX_VM_EXIT_IO_RDI_ENCODE                                0x6406
#define VMX_VM_EXIT_IO_RIP_ENCODE                                0x6408
#define VMX_VM_EXIT_IO_INSTRUCTION_INITIAL_ADDRESS_ENCODE        0x640A
#define VMX_GUEST_DR7_ENCODE                                     0x681A
#define VMX_GUEST_RSP_ENCODE                                     0x681C
#define VMX_GUEST_RIP_ENCODE                                     0x681E
#define VMX_GUEST_RFLAGS_ENCODE                                  0x6820
#define VMX_GUEST_PND_DEBUG_EXCEPTION_ENCODE                     0x6822
#define VMX_GUEST_IA32_SYSENTER_ESP_ENCODE                       0x6824
#define VMX_GUEST_IA32_SYSENTER_EIP_ENCODE                       0x6826
#define VMX_GUEST_IA32_SYSENTER_CS_ENCODE                        0x482A
#define VMX_EPTP_INDEX_ENCODE                                    0x0004
#define VMX_HLAT_PLR_PFX_SIZE_ENCODE                             0x0006
#define VMX_GUEST_CR0_ENCODE                                     0x6800
#define VMX_GUEST_CR3_ENCODE                                     0x6802
#define VMX_GUEST_CR4_ENCODE                                     0x6804
#define VMX_GUEST_PDPTR0_FULL_ENCODE                             0x280A
#define VMX_GUEST_PDPTR0_HIGH_ENCODE                             0x280b
#define VMX_GUEST_PDPTR1_FULL_ENCODE                             0x280C
#define VMX_GUEST_PDPTR1_HIGH_ENCODE                             0x280d
#define VMX_GUEST_PDPTR2_FULL_ENCODE                             0x280E
#define VMX_GUEST_PDPTR2_HIGH_ENCODE                             0x280f
#define VMX_GUEST_PDPTR3_FULL_ENCODE                             0x2810
#define VMX_GUEST_PDPTR3_HIGH_ENCODE                             0x2811
#define VMX_CR0_GUEST_HOST_MASK_ENCODE                           0x6000
#define VMX_CR4_GUEST_HOST_MASK_ENCODE                           0x6002
#define VMX_CR0_READ_SHADOW_ENCODE                               0x6004
#define VMX_CR4_READ_SHADOW_ENCODE                               0x6006
#define VMX_CR3_TARGET_VALUE_0_ENCODE                            0x6008
#define VMX_CR3_TARGET_VALUE_1_ENCODE                            0x600A
#define VMX_CR3_TARGET_VALUE_2_ENCODE                            0x600C
#define VMX_CR3_TARGET_VALUE_3_ENCODE                            0x600E
#define VMX_EOI_EXIT_TABLE_0_FULL_ENCODE                         0x201C
#define VMX_EOI_EXIT_TABLE_0_HIGH_ENCODE                         0x201d
#define VMX_EOI_EXIT_TABLE_1_FULL_ENCODE                         0x201E
#define VMX_EOI_EXIT_TABLE_1_HIGH_ENCODE                         0x201f
#define VMX_EOI_EXIT_TABLE_2_FULL_ENCODE                         0x2020
#define VMX_EOI_EXIT_TABLE_2_HIGH_ENCODE                         0x2021
#define VMX_EOI_EXIT_TABLE_3_FULL_ENCODE                         0x2022
#define VMX_EOI_EXIT_TABLE_3_HIGH_ENCODE                         0x2023
#define VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_FULL_ENCODE      0x2016
#define VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_HIGH_ENCODE      0x2017
#define VMX_GUEST_SMBASE_ENCODE                                  0x4828
#define VMX_POSTED_INTERRUPT_NOTIFICATION_VECTOR_ENCODE          0x0002
#define VMX_GUEST_UINV_ENCODE                                    0x0814
#define VMX_EXCEPTION_BITMAP_ENCODE                              0x4004
#define VMX_CR3_TARGET_COUNT_ENCODE                              0x400A
#define VMX_VM_ENTRY_CONTROL_ENCODE                              0x4012
#define VMX_VM_ENTRY_MSR_LOAD_COUNT_ENCODE                       0x4014
#define VMX_VIRTUAL_APIC_PAGE_ADDRESS_FULL_ENCODE                0x2012
#define VMX_VIRTUAL_APIC_PAGE_ADDRESS_HIGH_ENCODE                0x2013
#define VMX_IO_BITMAP_A_PHYPTR_FULL_ENCODE                       0x2000
#define VMX_IO_BITMAP_A_PHYPTR_HIGH_ENCODE                       0x2001
#define VMX_IO_BITMAP_B_PHYPTR_FULL_ENCODE                       0x2002
#define VMX_IO_BITMAP_B_PHYPTR_HIGH_ENCODE                       0x2003
#define VMX_EXIT_MSR_STORE_PHYPTR_FULL_ENCODE                    0x2006
#define VMX_EXIT_MSR_STORE_PHYPTR_HIGH_ENCODE                    0x2007
#define VMX_EXIT_MSR_LOAD_PHYPTR_FULL_ENCODE                     0x2008
#define VMX_EXIT_MSR_LOAD_PHYPTR_HIGH_ENCODE                     0x2009
#define VMX_ENTRY_MSR_LOAD_PHYPTR_FULL_ENCODE                    0x200A
#define VMX_ENTRY_MSR_LOAD_PHYPTR_HIGH_ENCODE                    0x200b
#define VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_FULL_ENCODE         0x2014
#define VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_HIGH_ENCODE         0x2015
#define VMX_MSR_BITMAP_PHYPTR_FULL_ENCODE                        0x2004
#define VMX_MSR_BITMAP_PHYPTR_HIGH_ENCODE                        0x2005
#define VMX_HOST_RSP_ENCODE                                      0x6C14
#define VMX_HOST_RIP_ENCODE                                      0x6C16
#define VMX_HOST_IA32_PAT_FULL_ENCODE                            0x2c00
#define VMX_HOST_IA32_PAT_HIGH_ENCODE                            0x2c01
#define VMX_HOST_IA32_EFER_FULL_ENCODE                           0x2c02
#define VMX_HOST_IA32_EFER_HIGH_ENCODE                           0x2c03
#define VMX_HOST_IA32_PERF_GLOBAL_CONTROL_FULL_ENCODE            0x2c04
#define VMX_HOST_IA32_PERF_GLOBAL_CONTROL_HIGH_ENCODE            0x2c05
#define VMX_HOST_CR0_ENCODE                                      0x6C00
#define VMX_HOST_CR3_ENCODE                                      0x6C02
#define VMX_HOST_CR4_ENCODE                                      0x6C04
#define VMX_HOST_IDTR_BASE_ENCODE                                0x6C0E
#define VMX_HOST_GDTR_BASE_ENCODE                                0x6C0C
#define VMX_HOST_FS_BASE_ENCODE                                  0x6C06
#define VMX_HOST_GS_BASE_ENCODE                                  0x6C08
#define VMX_HOST_TR_BASE_ENCODE                                  0x6C0A
#define VMX_HOST_IA32_SYSENTER_ESP_ENCODE                        0x6C10
#define VMX_HOST_IA32_SYSENTER_EIP_ENCODE                        0x6C12
#define VMX_HOST_IA32_SYSENTER_CS_ENCODE                         0x4C00
#define VMX_GUEST_INTERRUPT_STATUS_ENCODE                        0x0810
#define VMX_PML_INDEX_ENCODE                                     0x0812
#define VMX_VM_FUNCTION_CONTROLS_FULL_ENCODE                     0x2018
#define VMX_VM_FUNCTION_CONTROLS_HIGH_ENCODE                     0x2019
#define VMX_EPTP_LIST_ADDRESS_FULL_ENCODE                        0x2024
#define VMX_EPTP_LIST_ADDRESS_HIGH_ENCODE                        0x2025
#define VMX_VMREAD_BITMAP_ADDRESS_FULL_ENCODE                    0x2026
#define VMX_VMREAD_BITMAP_ADDRESS_HIGH_ENCODE                    0x2027
#define VMX_VMWRITE_BITMAP_ADDRESS_FULL_ENCODE                   0x2028
#define VMX_VMWRITE_BITMAP_ADDRESS_HIGH_ENCODE                   0x2029
#define VMX_PML_LOG_ADDRESS_FULL_ENCODE                          0x200E
#define VMX_PML_LOG_ADDRESS_HIGH_ENCODE                          0x200f
#define VMX_XSS_EXIT_CONTROL_FULL_ENCODE                         0x202C
#define VMX_XSS_EXIT_CONTROL_HIGH_ENCODE                         0x202d
#define VMX_ENCLS_EXIT_CONTROL_FULL_ENCODE                       0x202E
#define VMX_ENCLS_EXIT_CONTROL_HIGH_ENCODE                       0x202f
#define VMX_RSVD_64_BIT_VMEXIT_DATA_FULL_ENCODE                  0x2402
#define VMX_RSVD_64_BIT_VMEXIT_DATA_HIGH_ENCODE                  0x2403
#define VMX_ENCLV_EXIT_CONTROL_FULL_ENCODE                       0x2036
#define VMX_ENCLV_EXIT_CONTROL_HIGH_ENCODE                       0x2037
#define VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_FULL_ENCODE           0x202A
#define VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_HIGH_ENCODE           0x202b
#define VMX_GUEST_BNDCFGS_FULL_ENCODE                            0x2812
#define VMX_GUEST_BNDCFGS_HIGH_ENCODE                            0x2813
#define VMX_SPPTP_FULL_ENCODE                                    0x2030
#define VMX_SPPTP_HIGH_ENCODE                                    0x2031
#define VMX_TSC_MULTIPLIER_FULL_ENCODE                           0x2032
#define VMX_TSC_MULTIPLIER_HIGH_ENCODE                           0x2033
#define VMX_GUEST_RTIT_CTL_FULL_ENCODE                           0x2814
#define VMX_GUEST_RTIT_CTL_HIGH_ENCODE                           0x2815
#define VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_FULL_ENCODE 0x2034
#define VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_HIGH_ENCODE 0x2035
#define VMX_GUEST_SHARED_EPT_POINTER_FULL_ENCODE                 0x203C
#define VMX_GUEST_SHARED_EPT_POINTER_HIGH_ENCODE                 0x203d
#define VMX_PCONFIG_EXITING_FULL_ENCODE                          0x203E
#define VMX_PCONFIG_EXITING_HIGH_ENCODE                          0x203f
#define VMX_HLATP_FULL_ENCODE                                    0x2040
#define VMX_HLATP_HIGH_ENCODE                                    0x2041
#define VMX_PID_POINTER_TABLE_ADDRESS_FULL_ENCODE                0x2042
#define VMX_PID_POINTER_TABLE_ADDRESS_HIGH_ENCODE                0x2043
#define VMX_SECONDARY_EXIT_CTLS_FULL_ENCODE                      0x2044
#define VMX_SECONDARY_EXIT_CTLS_HIGH_ENCODE                      0x2045
#define VMX_PASID_LOW_FULL_ENCODE                                0x2038
#define VMX_PASID_LOW_HIGH_ENCODE                                0x2039
#define VMX_PASID_HIGH_FULL_ENCODE                               0x203A
#define VMX_PASID_HIGH_HIGH_ENCODE                               0x203b
#define VMX_GUEST_IA32_LBR_CTL_FULL_ENCODE                       0x2816
#define VMX_GUEST_IA32_LBR_CTL_HIGH_ENCODE                       0x2817
#define VMX_HOST_IA32_INTERRUPT_SSP_TABLE_ADDR_ENCODE            0x6C1C
#define VMX_GUEST_IA32_S_CET_ENCODE                              0x6828
#define VMX_GUEST_SSP_ENCODE                                     0x682A
#define VMX_GUEST_IA32_INTERRUPT_SSP_TABLE_ADDR_ENCODE           0x682C
#define VMX_HOST_IA32_S_CET_ENCODE                               0x6C18
#define VMX_HOST_SSP_ENCODE                                      0x6C1A
#define VMX_LAST_PID_POINTER_INDEX_ENCODE                        0x0008
#define VMX_GUEST_TD_HKID_ENCODE                                 0x4026
#define VMX_INTER_VM_IPI_PHYSADDR_BASE_FULL_ENCODE               0x2048
#define VMX_INTER_VM_IPI_PHYSADDR_BASE_HIGH_ENCODE               0x2049
#define VMX_RSVD_32_BIT_CONTROL_ENCODE                           0x4028
#define VMX_HOST_PKRS_FULL_ENCODE                                0x2c06
#define VMX_HOST_PKRS_HIGH_ENCODE                                0x2c07
#define VMX_GUEST_PKRS_FULL_ENCODE                               0x2818
#define VMX_GUEST_PKRS_HIGH_ENCODE                               0x2819
#define VMX_VCH_LIST_PHYSADDR_BASE_FULL_ENCODE                   0x2046
#define VMX_VCH_LIST_PHYSADDR_BASE_HIGH_ENCODE                   0x2047
#define VMX_RSVD_64_BIT_CONTROL_4_FULL_ENCODE                    0x204A
#define VMX_RSVD_64_BIT_CONTROL_4_HIGH_ENCODE                    0x204b
#define VMX_RSVD_64_BIT_CONTROL_5_FULL_ENCODE                    0x204C
#define VMX_RSVD_64_BIT_CONTROL_5_HIGH_ENCODE                    0x204d

////////////////////////////////////////////////////////////////////////////
// RPC_B0_VMX_VMCS - VMCS FORMATS
////////////////////////////////////////////////////////////////////////////

#define VMX_VMCS_REVISION_ID_FORMAT                              2
#define VMX_ABORT_INDICATOR_FORMAT                               2
#define VMCS_CACHING_ARCH_PTR_FORMAT                             1
#define VMCS_CACHING_SAVED_DIRTY_BITS_FORMAT                     2
#define VMCS_CACHING_UARCH_INFO_FORMAT                           0
#define VMX_GUEST_ES_SELECTOR_FORMAT                             0
#define VMX_GUEST_ES_ARBYTE_FORMAT                               2
#define VMX_GUEST_ES_LIMIT_FORMAT                                2
#define VMX_GUEST_ES_BASE_FORMAT                                 3
#define VMX_GUEST_CS_SELECTOR_FORMAT                             0
#define VMX_GUEST_CS_ARBYTE_FORMAT                               2
#define VMX_GUEST_CS_LIMIT_FORMAT                                2
#define VMX_GUEST_CS_BASE_FORMAT                                 3
#define VMX_GUEST_SS_SELECTOR_FORMAT                             0
#define VMX_GUEST_SS_ARBYTE_FORMAT                               2
#define VMX_GUEST_SS_LIMIT_FORMAT                                2
#define VMX_GUEST_SS_BASE_FORMAT                                 3
#define VMX_GUEST_DS_SELECTOR_FORMAT                             0
#define VMX_GUEST_DS_ARBYTE_FORMAT                               2
#define VMX_GUEST_DS_LIMIT_FORMAT                                2
#define VMX_GUEST_DS_BASE_FORMAT                                 3
#define VMX_GUEST_LDTR_SELECTOR_FORMAT                           0
#define VMX_GUEST_LDTR_ARBYTE_FORMAT                             2
#define VMX_GUEST_LDTR_LIMIT_FORMAT                              2
#define VMX_GUEST_LDTR_BASE_FORMAT                               3
#define VMX_GUEST_TR_SELECTOR_FORMAT                             0
#define VMX_GUEST_TR_ARBYTE_FORMAT                               2
#define VMX_GUEST_TR_LIMIT_FORMAT                                2
#define VMX_GUEST_TR_BASE_FORMAT                                 3
#define VMX_GUEST_FS_SELECTOR_FORMAT                             0
#define VMX_GUEST_FS_ARBYTE_FORMAT                               2
#define VMX_GUEST_FS_LIMIT_FORMAT                                2
#define VMX_GUEST_FS_BASE_FORMAT                                 3
#define VMX_GUEST_GS_SELECTOR_FORMAT                             0
#define VMX_GUEST_GS_ARBYTE_FORMAT                               2
#define VMX_GUEST_GS_LIMIT_FORMAT                                2
#define VMX_GUEST_GS_BASE_FORMAT                                 3
#define VMX_NO_COMMIT_THRESHOLD_FORMAT                           2
#define VMX_GUEST_GDTR_LIMIT_FORMAT                              2
#define VMX_GUEST_GDTR_BASE_FORMAT                               3
#define VMX_RSVD_32_BIT_GUEST_STATE_FORMAT                       2
#define VMX_GUEST_IDTR_LIMIT_FORMAT                              2
#define VMX_GUEST_IDTR_BASE_FORMAT                               3
#define VMX_HOST_ES_SELECTOR_FORMAT                              0
#define VMX_HOST_CS_SELECTOR_FORMAT                              0
#define VMX_HOST_SS_SELECTOR_FORMAT                              0
#define VMX_HOST_DS_SELECTOR_FORMAT                              0
#define VMX_HOST_FS_SELECTOR_FORMAT                              0
#define VMX_HOST_GS_SELECTOR_FORMAT                              0
#define VMX_HOST_TR_SELECTOR_FORMAT                              0
#define VMX_GUEST_VPID_FORMAT                                    0
#define VMX_OSV_CVP_FULL_FORMAT                                  1
#define VMX_OSV_CVP_HIGH_FORMAT                                  2
#define VMX_VMCS_LAUNCH_STATE_FORMAT                             2
#define VMX_VM_INSTRUCTION_ERRORCODE_FORMAT                      2
#define VMX_GUEST_HIDDEN_PND_DEBUG_EXCEPTION_FORMAT              1
#define VMX_GUEST_HIDDEN_RFLAGS_FORMAT                           1
#define VMX_PAUSE_LOOP_EXITING_GAP_FORMAT                        2
#define VMX_PAUSE_LOOP_EXITING_WINDOW_FORMAT                     2
#define VMX_GUEST_SAVED_WORKING_VMCS_POINTER_FULL_FORMAT         1
#define VMX_GUEST_SAVED_WORKING_VMCS_POINTER_HIGH_FORMAT         2
#define VMX_GUEST_IA32_DEBUGCTLMSR_FULL_FORMAT                   1
#define VMX_GUEST_IA32_DEBUGCTLMSR_HIGH_FORMAT                   2
#define VMX_GUEST_IA32_PAT_FULL_FORMAT                           1
#define VMX_GUEST_IA32_PAT_HIGH_FORMAT                           2
#define VMX_GUEST_IA32_EFER_FULL_FORMAT                          1
#define VMX_GUEST_IA32_EFER_HIGH_FORMAT                          2
#define VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_FULL_FORMAT           1
#define VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_HIGH_FORMAT           2
#define VMX_VM_EXECUTION_CONTROL_PROC_BASED_FORMAT               2
#define VMX_VM_EXECUTION_CONTROL_SECONDARY_PROC_BASED_FORMAT     2
#define VMX_VM_EXECUTION_CONTROL_PIN_BASED_FORMAT                2
#define VMX_TPR_THRESHOLD_FORMAT                                 2
#define VMX_PAGEFAULT_ERRORCODE_MASK_FORMAT                      2
#define VMX_PAGEFAULT_ERRORCODE_MATCH_FORMAT                     2
#define VMX_GUEST_INTERRUPTIBILITY_FORMAT                        2
#define VMX_GUEST_SLEEP_STATE_FORMAT                             2
#define VMX_GUEST_EPT_POINTER_FULL_FORMAT                        1
#define VMX_GUEST_EPT_POINTER_HIGH_FORMAT                        2
#define VMX_GUEST_PHYSICAL_ADDRESS_INFO_FULL_FORMAT              1
#define VMX_GUEST_PHYSICAL_ADDRESS_INFO_HIGH_FORMAT              2
#define VMX_VM_ENTRY_INTR_INFO_FORMAT                            2
#define VMX_VM_ENTRY_EXCEPTION_ERRORCODE_FORMAT                  2
#define VMX_VM_ENTRY_INSTRUCTION_LENGTH_FORMAT                   2
#define VMX_VM_EXIT_CONTROL_FORMAT                               2
#define VMX_GUEST_PREEMPTION_TIMER_COUNT_FORMAT                  2
#define VMX_VM_EXIT_MSR_STORE_COUNT_FORMAT                       2
#define VMX_VM_EXIT_MSR_LOAD_COUNT_FORMAT                        2
#define VMX_VM_EXIT_REASON_FORMAT                                2
#define VMX_VM_EXIT_EXCEPTION_INFO_FORMAT                        2
#define VMX_VM_EXIT_EXCEPTION_ERRORCODE_FORMAT                   2
#define VMX_VM_EXIT_IDT_VECTOR_FIELD_FORMAT                      2
#define VMX_VM_EXIT_IDT_VECTOR_ERRORCODE_FORMAT                  2
#define VMX_VM_EXIT_INSTRUCTION_LENGTH_FORMAT                    2
#define VMX_VM_EXIT_INSTRUCTION_INFO_FORMAT                      2
#define VMX_GUEST_PARENT_VMCS_POINTER_FULL_FORMAT                1
#define VMX_GUEST_PARENT_VMCS_POINTER_HIGH_FORMAT                2
#define VMX_TSC_OFFSET_FULL_FORMAT                               1
#define VMX_TSC_OFFSET_HIGH_FORMAT                               2
#define VMX_VM_EXIT_QUALIFICATION_FORMAT                         3
#define VMX_VM_EXIT_IO_RCX_FORMAT                                3
#define VMX_VM_EXIT_IO_RSI_FORMAT                                3
#define VMX_VM_EXIT_IO_RDI_FORMAT                                3
#define VMX_VM_EXIT_IO_RIP_FORMAT                                3
#define VMX_VM_EXIT_IO_INSTRUCTION_INITIAL_ADDRESS_FORMAT        3
#define VMX_GUEST_DR7_FORMAT                                     3
#define VMX_GUEST_RSP_FORMAT                                     3
#define VMX_GUEST_RIP_FORMAT                                     3
#define VMX_GUEST_RFLAGS_FORMAT                                  3
#define VMX_GUEST_PND_DEBUG_EXCEPTION_FORMAT                     3
#define VMX_GUEST_IA32_SYSENTER_ESP_FORMAT                       3
#define VMX_GUEST_IA32_SYSENTER_EIP_FORMAT                       3
#define VMX_GUEST_IA32_SYSENTER_CS_FORMAT                        2
#define VMX_EPTP_INDEX_FORMAT                                    0
#define VMX_HLAT_PLR_PFX_SIZE_FORMAT                             0
#define VMX_GUEST_CR0_FORMAT                                     3
#define VMX_GUEST_CR3_FORMAT                                     3
#define VMX_GUEST_CR4_FORMAT                                     3
#define VMX_GUEST_PDPTR0_FULL_FORMAT                             1
#define VMX_GUEST_PDPTR0_HIGH_FORMAT                             2
#define VMX_GUEST_PDPTR1_FULL_FORMAT                             1
#define VMX_GUEST_PDPTR1_HIGH_FORMAT                             2
#define VMX_GUEST_PDPTR2_FULL_FORMAT                             1
#define VMX_GUEST_PDPTR2_HIGH_FORMAT                             2
#define VMX_GUEST_PDPTR3_FULL_FORMAT                             1
#define VMX_GUEST_PDPTR3_HIGH_FORMAT                             2
#define VMX_CR0_GUEST_HOST_MASK_FORMAT                           3
#define VMX_CR4_GUEST_HOST_MASK_FORMAT                           3
#define VMX_CR0_READ_SHADOW_FORMAT                               3
#define VMX_CR4_READ_SHADOW_FORMAT                               3
#define VMX_CR3_TARGET_VALUE_0_FORMAT                            3
#define VMX_CR3_TARGET_VALUE_1_FORMAT                            3
#define VMX_CR3_TARGET_VALUE_2_FORMAT                            3
#define VMX_CR3_TARGET_VALUE_3_FORMAT                            3
#define VMX_EOI_EXIT_TABLE_0_FULL_FORMAT                         1
#define VMX_EOI_EXIT_TABLE_0_HIGH_FORMAT                         2
#define VMX_EOI_EXIT_TABLE_1_FULL_FORMAT                         1
#define VMX_EOI_EXIT_TABLE_1_HIGH_FORMAT                         2
#define VMX_EOI_EXIT_TABLE_2_FULL_FORMAT                         1
#define VMX_EOI_EXIT_TABLE_2_HIGH_FORMAT                         2
#define VMX_EOI_EXIT_TABLE_3_FULL_FORMAT                         1
#define VMX_EOI_EXIT_TABLE_3_HIGH_FORMAT                         2
#define VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_FULL_FORMAT      1
#define VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_HIGH_FORMAT      2
#define VMX_GUEST_SMBASE_FORMAT                                  2
#define VMX_POSTED_INTERRUPT_NOTIFICATION_VECTOR_FORMAT          0
#define VMX_GUEST_UINV_FORMAT                                    0
#define VMX_EXCEPTION_BITMAP_FORMAT                              2
#define VMX_CR3_TARGET_COUNT_FORMAT                              2
#define VMX_VM_ENTRY_CONTROL_FORMAT                              2
#define VMX_VM_ENTRY_MSR_LOAD_COUNT_FORMAT                       2
#define VMX_VIRTUAL_APIC_PAGE_ADDRESS_FULL_FORMAT                1
#define VMX_VIRTUAL_APIC_PAGE_ADDRESS_HIGH_FORMAT                2
#define VMX_IO_BITMAP_A_PHYPTR_FULL_FORMAT                       1
#define VMX_IO_BITMAP_A_PHYPTR_HIGH_FORMAT                       2
#define VMX_IO_BITMAP_B_PHYPTR_FULL_FORMAT                       1
#define VMX_IO_BITMAP_B_PHYPTR_HIGH_FORMAT                       2
#define VMX_EXIT_MSR_STORE_PHYPTR_FULL_FORMAT                    1
#define VMX_EXIT_MSR_STORE_PHYPTR_HIGH_FORMAT                    2
#define VMX_EXIT_MSR_LOAD_PHYPTR_FULL_FORMAT                     1
#define VMX_EXIT_MSR_LOAD_PHYPTR_HIGH_FORMAT                     2
#define VMX_ENTRY_MSR_LOAD_PHYPTR_FULL_FORMAT                    1
#define VMX_ENTRY_MSR_LOAD_PHYPTR_HIGH_FORMAT                    2
#define VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_FULL_FORMAT         1
#define VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_HIGH_FORMAT         2
#define VMX_MSR_BITMAP_PHYPTR_FULL_FORMAT                        1
#define VMX_MSR_BITMAP_PHYPTR_HIGH_FORMAT                        2
#define VMX_HOST_RSP_FORMAT                                      3
#define VMX_HOST_RIP_FORMAT                                      3
#define VMX_HOST_IA32_PAT_FULL_FORMAT                            1
#define VMX_HOST_IA32_PAT_HIGH_FORMAT                            2
#define VMX_HOST_IA32_EFER_FULL_FORMAT                           1
#define VMX_HOST_IA32_EFER_HIGH_FORMAT                           2
#define VMX_HOST_IA32_PERF_GLOBAL_CONTROL_FULL_FORMAT            1
#define VMX_HOST_IA32_PERF_GLOBAL_CONTROL_HIGH_FORMAT            2
#define VMX_HOST_CR0_FORMAT                                      3
#define VMX_HOST_CR3_FORMAT                                      3
#define VMX_HOST_CR4_FORMAT                                      3
#define VMX_HOST_IDTR_BASE_FORMAT                                3
#define VMX_HOST_GDTR_BASE_FORMAT                                3
#define VMX_HOST_FS_BASE_FORMAT                                  3
#define VMX_HOST_GS_BASE_FORMAT                                  3
#define VMX_HOST_TR_BASE_FORMAT                                  3
#define VMX_HOST_IA32_SYSENTER_ESP_FORMAT                        3
#define VMX_HOST_IA32_SYSENTER_EIP_FORMAT                        3
#define VMX_HOST_IA32_SYSENTER_CS_FORMAT                         2
#define VMX_GUEST_INTERRUPT_STATUS_FORMAT                        0
#define VMX_PML_INDEX_FORMAT                                     0
#define VMX_VM_FUNCTION_CONTROLS_FULL_FORMAT                     1
#define VMX_VM_FUNCTION_CONTROLS_HIGH_FORMAT                     2
#define VMX_EPTP_LIST_ADDRESS_FULL_FORMAT                        1
#define VMX_EPTP_LIST_ADDRESS_HIGH_FORMAT                        2
#define VMX_VMREAD_BITMAP_ADDRESS_FULL_FORMAT                    1
#define VMX_VMREAD_BITMAP_ADDRESS_HIGH_FORMAT                    2
#define VMX_VMWRITE_BITMAP_ADDRESS_FULL_FORMAT                   1
#define VMX_VMWRITE_BITMAP_ADDRESS_HIGH_FORMAT                   2
#define VMX_PML_LOG_ADDRESS_FULL_FORMAT                          1
#define VMX_PML_LOG_ADDRESS_HIGH_FORMAT                          2
#define VMX_XSS_EXIT_CONTROL_FULL_FORMAT                         1
#define VMX_XSS_EXIT_CONTROL_HIGH_FORMAT                         2
#define VMX_ENCLS_EXIT_CONTROL_FULL_FORMAT                       1
#define VMX_ENCLS_EXIT_CONTROL_HIGH_FORMAT                       2
#define VMX_RSVD_64_BIT_VMEXIT_DATA_FULL_FORMAT                  1
#define VMX_RSVD_64_BIT_VMEXIT_DATA_HIGH_FORMAT                  2
#define VMX_ENCLV_EXIT_CONTROL_FULL_FORMAT                       1
#define VMX_ENCLV_EXIT_CONTROL_HIGH_FORMAT                       2
#define VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_FULL_FORMAT           1
#define VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_HIGH_FORMAT           2
#define VMX_GUEST_BNDCFGS_FULL_FORMAT                            1
#define VMX_GUEST_BNDCFGS_HIGH_FORMAT                            2
#define VMX_SPPTP_FULL_FORMAT                                    1
#define VMX_SPPTP_HIGH_FORMAT                                    2
#define VMX_TSC_MULTIPLIER_FULL_FORMAT                           1
#define VMX_TSC_MULTIPLIER_HIGH_FORMAT                           2
#define VMX_GUEST_RTIT_CTL_FULL_FORMAT                           1
#define VMX_GUEST_RTIT_CTL_HIGH_FORMAT                           2
#define VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_FULL_FORMAT 1
#define VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_HIGH_FORMAT 2
#define VMX_GUEST_SHARED_EPT_POINTER_FULL_FORMAT                 1
#define VMX_GUEST_SHARED_EPT_POINTER_HIGH_FORMAT                 2
#define VMX_PCONFIG_EXITING_FULL_FORMAT                          1
#define VMX_PCONFIG_EXITING_HIGH_FORMAT                          2
#define VMX_HLATP_FULL_FORMAT                                    1
#define VMX_HLATP_HIGH_FORMAT                                    2
#define VMX_PID_POINTER_TABLE_ADDRESS_FULL_FORMAT                1
#define VMX_PID_POINTER_TABLE_ADDRESS_HIGH_FORMAT                2
#define VMX_SECONDARY_EXIT_CTLS_FULL_FORMAT                      1
#define VMX_SECONDARY_EXIT_CTLS_HIGH_FORMAT                      2
#define VMX_PASID_LOW_FULL_FORMAT                                1
#define VMX_PASID_LOW_HIGH_FORMAT                                2
#define VMX_PASID_HIGH_FULL_FORMAT                               1
#define VMX_PASID_HIGH_HIGH_FORMAT                               2
#define VMX_GUEST_IA32_LBR_CTL_FULL_FORMAT                       1
#define VMX_GUEST_IA32_LBR_CTL_HIGH_FORMAT                       2
#define VMX_HOST_IA32_INTERRUPT_SSP_TABLE_ADDR_FORMAT            3
#define VMX_GUEST_IA32_S_CET_FORMAT                              3
#define VMX_GUEST_SSP_FORMAT                                     3
#define VMX_GUEST_IA32_INTERRUPT_SSP_TABLE_ADDR_FORMAT           3
#define VMX_HOST_IA32_S_CET_FORMAT                               3
#define VMX_HOST_SSP_FORMAT                                      3
#define VMX_LAST_PID_POINTER_INDEX_FORMAT                        0
#define VMX_GUEST_TD_HKID_FORMAT                                 2
#define VMX_INTER_VM_IPI_PHYSADDR_BASE_FULL_FORMAT               1
#define VMX_INTER_VM_IPI_PHYSADDR_BASE_HIGH_FORMAT               2
#define VMX_RSVD_32_BIT_CONTROL_FORMAT                           2
#define VMX_HOST_PKRS_FULL_FORMAT                                1
#define VMX_HOST_PKRS_HIGH_FORMAT                                2
#define VMX_GUEST_PKRS_FULL_FORMAT                               1
#define VMX_GUEST_PKRS_HIGH_FORMAT                               2
#define VMX_VCH_LIST_PHYSADDR_BASE_FULL_FORMAT                   1
#define VMX_VCH_LIST_PHYSADDR_BASE_HIGH_FORMAT                   2
#define VMX_RSVD_64_BIT_CONTROL_4_FULL_FORMAT                    1
#define VMX_RSVD_64_BIT_CONTROL_4_HIGH_FORMAT                    2
#define VMX_RSVD_64_BIT_CONTROL_5_FULL_FORMAT                    1
#define VMX_RSVD_64_BIT_CONTROL_5_HIGH_FORMAT                    2
#define PPPE_GUEST_RAX_FORMAT                                    1
#define PPPE_GUEST_RCX_FORMAT                                    1
#define PPPE_GUEST_RDX_FORMAT                                    1
#define PPPE_GUEST_RBX_FORMAT                                    1
#define PPPE_GUEST_RSP_FORMAT                                    1
#define PPPE_GUEST_RBP_FORMAT                                    1
#define PPPE_GUEST_RSI_FORMAT                                    1
#define PPPE_GUEST_RDI_FORMAT                                    1
#define PPPE_GUEST_R8_FORMAT                                     1
#define PPPE_GUEST_R9_FORMAT                                     1
#define PPPE_GUEST_R10_FORMAT                                    1
#define PPPE_GUEST_R11_FORMAT                                    1
#define PPPE_GUEST_R12_FORMAT                                    1
#define PPPE_GUEST_R13_FORMAT                                    1
#define PPPE_GUEST_R14_FORMAT                                    1
#define PPPE_GUEST_R15_FORMAT                                    1
#define PPPE_VMEXIT_INJECTION_FORMAT                             1
#define PPPE_FROM_RIP_FORMAT                                     1
#define PPPE_PAGE_FAULT_ADDRESS_FORMAT                           1
#define PPPE_VM_ENTRY_CONTROL_FORMAT                             1
#define PPPE_VMCS_CHILD_POINTER_FORMAT                           1
#define PPPE_UNWIND_FORMAT                                       1
#define PPPE_GUEST_DOORBELL_INHIBITS_FORMAT                      1
#define PPPE_GUEST_MISC_UARCH_STATE_FORMAT                       1
#define PPPE_GUEST_INSTRUCTION_OPCODE_FORMAT                     1
#define PPPE_GUEST_INSTRUCTION_DISPLACEMENT_FORMAT               1
#define PPPE_GUEST_INSTRUCTION_IMMEDIATE_FORMAT                  1
#define PPPE_GUEST_EXCEPTION_INHIBITS_FORMAT                     1
#define PPPE_GUEST_SSP_FORMAT                                    1
#define PPPE_PRE_VM_EXIT_VMCS_LEVEL_FORMAT                       2

////////////////////////////////////////////////////////////////////////////
// RPC_B0_VMX_VMCS - VtVMCS_t and XuVMCS_t VMCS structures
////////////////////////////////////////////////////////////////////////////

#ifndef ONLY_DEFINES // Turn off any non-#define code //

typedef struct {
  uint8_t _[1024];
} VtVMCS_t;
typedef struct {
  union {
    VtVMCS_t vt;
    uint8_t  _x[2048];
  };
} XuVMCS_t;

#endif // ONLY_DEFINES //

// AUTOMATICALLY GENERATED FILE - DO NOT MODIFY //

#endif // __RPC_B0_VMX_VMCS_H__ //
