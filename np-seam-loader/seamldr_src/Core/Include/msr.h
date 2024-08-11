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

#define MSR_IA32_PAT                     0x277
#define MSR_IA32_SEAMRR_BASE             0x1400
#define MSR_IA32_SEAMRR_MASK             0x1401
#define MSR_IA32_SEAMEXTEND              0x1402
#define B_SEAMRR_BASE                    0xFFFFFFFFFE000000
#define B_SEAMRR_MASK                    0xFFFFFFFFFE000000
#define N_SEAMRR_MASK_MASK               25
#define IA32_VMX_BASIC_MSR_INDEX         0x480
#define IA32_VMX_PINBASED_CTLS_MSR_INDEX 0x481
// according to SDM A.3.1 - always read as 1
#define B_PINBASED_CTLS_DEFAULT          (BIT1 | BIT2 | BIT4)

typedef union {
  struct {
    UINT64 RevisionIdentifier           : 32;
    UINT64 VmcsRegionSize               : 13;
    UINT64 Rsvd45To47                   : 3;
    UINT64 VmcsAddrWidth                : 1;
    UINT64 DualMonitorTreatment         : 1;
    UINT64 VmcsMemoryType               : 4;
    UINT64 VmExitInstructionInformation : 1;
    UINT64 VmxControlDefaultClear       : 1;
    UINT64 Rsvd56To63                   : 8;
  };
  UINT64 raw;
} VmxBasicMsr_u;
#define IA32_VMX_PROCBASED_CTLS_MSR_INDEX      0x482
// acording to SDM A.3.2 - always read as 0
#define B_PROCBASED_CTLS_DEFAULT               (0x401E172)
#define IA32_VMX_CR0_FIXED0_MSR_INDEX          0x486
#define IA32_VMX_CR0_FIXED1_MSR_INDEX          0x487
#define IA32_VMX_CR4_FIXED0_MSR_INDEX          0x488
#define IA32_VMX_CR4_FIXED1_MSR_INDEX          0x489
#define IA32_VMX_TRUE_PINBASED_CTLS_MSR_INDEX  0x48D
#define IA32_VMX_TRUE_PROCBASED_CTLS_MSR_INDEX 0x48E
#define IA32_VMX_TRUE_EXIT_CTLS_MSR_ADDR       0x048F
#define IA32_VMX_TRUE_ENTRY_CTLS_MSR_ADDR      0x0490

#define IA32_CR_S_CET_SH_STK_EN_MASK           0x0000000000000001
#define IA32_CR_S_CET_ENDBR_EN_MASK            0x0000000000000004
#define IA32_CR_S_CET_NO_TRACK_EN_MASK         0x0000000000000010

//
// MSR_IA32_SMRR_BASE (0x1400) structure
//
typedef union {
  struct {
    UINT64 reserved0 : 25; // bits [24:0]
    UINT64 base      : 39; // bits [63:25]
  };
  UINT64 raw;
} SeamrrBase_u;

//
// MSR_IA32_SMRR_MASK (0x1401) structure
//
typedef union {
  struct {
    UINT64 reserved0 : 10; // bits [9:0]
    UINT64 lock      : 1;  // bit 10
    UINT64 valid     : 1;  // bit 11
    UINT64 reserved1 : 13; // bits [24:12]
    UINT64 mask      : 39; // bits [63:25]
  };
  UINT64 raw;
} SeamrrMask_u;

#define IA32_CR_MISC_ENABLES_BOOT_NT4_BIT (1 << 22)
