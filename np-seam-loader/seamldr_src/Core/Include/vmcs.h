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
#pragma once
#define VMCS_SIZE                                _4KB

#define VM_EXIT_CTRL_SAVE_DEBUG_CTRL             BIT2
#define VM_EXIT_CTRL_HOST_ADDR_SPACE_SIZE        BIT9
#define VM_EXIT_LOAD_IA32_PERF_GLOBAL_CTRL       BIT12
#define VM_EXIT_CTRL_SAVE_IA32_PAT               BIT18
#define VM_EXIT_CTRL_LOAD_IA32_PAT               BIT19
#define VM_EXIT_CTRL_SAVE_IA32_EFER              BIT20
#define VM_EXIT_CTRL_LOAD_IA32_EFER              BIT21
#define VM_EXIT_CTRL_CLEAR_IA32_BNDCFGS          BIT23
#define VM_EXIT_CTRL_CONCEAL_VMX_FROM_PT         BIT24
#define VM_EXIT_CTRL_CLEAR_IA32_RTIT_CTL         BIT25
#define VM_EXIT_CTRL_CLEAR_LBR_CTL               BIT26
#define VM_EXIT_CTRL_CLEAR_UINV                  BIT27
#define VM_EXIT_CTRL_LOAD_CET_HOST_STATE         BIT28
#define VM_EXIT_SAVE_IA32_PERF_GLOBAL_CTRL       BIT30

#define VM_ENTRY_CTRL_LOAD_DEBUG_CTRL            BIT2
#define VM_ENTRY_CTRL_LOAD_IA32_PERF_GLOBAL_CTRL BIT13
#define VM_ENTRY_CTRL_LOAD_IA32_PAT              BIT14
#define VM_ENTRY_CTRL_LOAD_IA32_EFER             BIT15
#define VM_ENTRY_CTRL_LOAD_IA32_BNDFGS           BIT16
#define VM_ENTRY_CTRL_CONCEAL_VMX_FROM_PT        BIT17
#define VM_ENTRY_CTRL_LOAD_IA32_RTIT_CTL         BIT18
#define VM_ENTRY_CTRL_LOAD_UINV                  BIT19
#define VM_ENTRY_CTRL_LOAD_GUEST_CET_STATE       BIT20
#define VM_ENTRY_CTRL_LOAD_LBR_CTL               BIT21
#define VM_ENTRY_CTRL_LOAD_IA32_PKRS             BIT22

/**
 *
 * This function store VMCS.
 *
 * @param Vmcs  VMCS pointer
 *
 * @return RFLAGS if VmPtrStore fail
 *
 **/
UINTN
AsmVmPtrStore(IN UINT64 *Vmcs);

/**
 *
 * This function load VMCS.
 *
 * @param Vmcs  VMCS pointer
 *
 * @return RFLAGS if VmPtrLoad fail
 *
 **/
UINTN
AsmVmPtrLoad(IN UINT64 *Vmcs);

/**
 *
 * This function clear VMCS.
 *
 * @param Vmcs  VMCS pointer
 *
 * @return RFLAGS if VmClear fail
 *
 **/
UINTN
AsmVmClear(IN UINT64 *Vmcs);

/**
 *
 * This function write UINN16 data to VMCS region.
 *
 * @param Index VMCS region index
 * @param Data  VMCS region value
 *
 **/
void
VmWrite16(IN UINT32 Index,
          IN UINT16 Data);

/**
 *
 * @param Index VMCS region index
 * @param Data  VMCS region value
 *
 **/
void
VmWrite64(IN UINT32 Index,
          IN UINT64 Data);

/**
 *
 * This function write UINNN data to VMCS region.
 *
 * @param Index VMCS region index
 * @param Data  VMCS region value
 *
 **/
void
VmWriteN(IN UINT32 Index,
         IN UINTN Data);

void SetupVmcs(UINT64 SeamPtBaseAddr);
