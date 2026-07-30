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

#ifndef __RWC_A0_VMX_VMCS_ACCESSORS_H__
#define __RWC_A0_VMX_VMCS_ACCESSORS_H__

#define Wr_Guest_RIP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RIP_OFFSET)) = (VAL))

#define Wr_Host_CR0(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR0_OFFSET)) = (VAL))

#define Wr_Host_CR3(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR3_OFFSET)) = (VAL))

#define Wr_Host_CR4(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR4_OFFSET)) = (VAL))

#define Wr_Host_CS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CS_SELECTOR_OFFSET)) = (VAL))

#define Wr_Host_SS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_SS_SELECTOR_OFFSET)) = (VAL))

#define Wr_Host_FS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_FS_SELECTOR_OFFSET)) = (VAL))

#define Wr_Host_GS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_GS_SELECTOR_OFFSET)) = (VAL))

#define Wr_Host_TR_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_TR_SELECTOR_OFFSET)) = (VAL))

#define Wr_Host_IA32_PAT(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_PAT_FULL_OFFSET)) = (VAL))

#define Wr_Host_IA32_S_Cet(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_S_CET_OFFSET)) = (VAL))

#define Wr_Host_IA32_EFER(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_EFER_FULL_OFFSET)) = (VAL))

#define Wr_VM_Exit_Control(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_CONTROL_OFFSET)) = (VAL))

#define Wr_VM_Entry_Control(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_CONTROL_OFFSET)) = (VAL))

#define Wr_VM_Execution_Control_Pin_Based(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_PIN_BASED_OFFSET)) = (VAL))

#define Wr_VM_Execution_Control_Proc_Based(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_PROC_BASED_OFFSET)) = (VAL))

#define Wr_Host_RIP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_RIP_OFFSET)) = (VAL))

#define Wr_Host_FS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_FS_BASE_OFFSET)) = (VAL))

#define Wr_Host_RSP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_RSP_OFFSET)) = (VAL))

#define Wr_Host_SSP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_SSP_OFFSET)) = (VAL))

#define Wr_Host_GS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_GS_BASE_OFFSET)) = (VAL))

#define Wr_VMCS_Revision_ID(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMCS_REVISION_ID_OFFSET)) = (VAL))

#endif // __RWC_A0_VMX_VMCS_ACCESSORS_H__
