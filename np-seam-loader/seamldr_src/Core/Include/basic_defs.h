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

#ifndef BASIC_H
#define BASIC_H

#ifndef _SEAMLDR_VALIDATION_
#define UINT8  unsigned __int8  //char
#define UINT16 unsigned __int16 //short int
#define UINT32 unsigned __int32 //long
#define UINT64 unsigned __int64 //long long
#endif

//
// Bit definitions
//
#define BIT0  0x01
#define BIT1  0x02
#define BIT2  0x04
#define BIT3  0x08
#define BIT4  0x010
#define BIT5  0x020
#define BIT6  0x040
#define BIT7  0x080
#define BIT8  0x0100
#define BIT9  0x0200
#define BIT10 0x0400
#define BIT11 0x0800
#define BIT12 0x01000
#define BIT13 0x02000
#define BIT14 0x04000
#define BIT15 0x08000
#define BIT16 0x010000
#define BIT17 0x020000
#define BIT18 0x040000
#define BIT19 0x080000
#define BIT20 0x0100000
#define BIT21 0x0200000
#define BIT22 0x0400000
#define BIT23 0x0800000
#define BIT24 0x01000000
#define BIT25 0x02000000
#define BIT26 0x04000000
#define BIT27 0x08000000
#define BIT28 0x010000000
#define BIT29 0x020000000
#define BIT30 0x040000000
#define BIT31 0x080000000
#define BIT32 0x100000000
#define BIT33 0x200000000
#define BIT34 0x400000000
#define BIT35 0x800000000
#define BIT36 0x1000000000
#define BIT37 0x2000000000
#define BIT38 0x4000000000
#define BIT39 0x8000000000
#define BIT40 0x10000000000
#define BIT41 0x20000000000
#define BIT42 0x40000000000
#define BIT43 0x80000000000
#define BIT44 0x100000000000
#define BIT45 0x200000000000
#define BIT46 0x400000000000
#define BIT47 0x800000000000
#define BIT48 0x1000000000000
#define BIT49 0x2000000000000
#define BIT50 0x4000000000000
#define BIT51 0x8000000000000
#define BIT52 0x10000000000000
#define BIT53 0x20000000000000
#define BIT54 0x40000000000000
#define BIT55 0x80000000000000
#define BIT56 0x100000000000000
#define BIT57 0x200000000000000
#define BIT58 0x400000000000000
#define BIT59 0x800000000000000
#define BIT60 0x1000000000000000
#define BIT61 0x2000000000000000
#define BIT62 0x4000000000000000
#define BIT63 0x8000000000000000

#define BITN(N) (1 << (N))

typedef  UINT16 TPM_ALG_ID;
#define TPM_ALG_ERROR           (TPM_ALG_ID)(0x0000)
#define TPM_ALG_RSA             (TPM_ALG_ID)(0x0001)
#define TPM_ALG_SHA             (TPM_ALG_ID)(0x0004)
#define TPM_ALG_SHA1            (TPM_ALG_ID)(0x0004)
#define TPM_ALG_SHA256          (TPM_ALG_ID)(0x000B)
#define TPM_ALG_SHA384          (TPM_ALG_ID)(0x000C)
#define TPM_ALG_SHA512          (TPM_ALG_ID)(0x000D)
#define TPM_ALG_NULL            (TPM_ALG_ID)(0x0010)
#define TPM_ALG_SM3_256         (TPM_ALG_ID)(0x0012)
#define TPM_ALG_ECDSA           (TPM_ALG_ID)(0x0018)
#define TPM_ALG_RSASSA          (TPM_ALG_ID)(0x0014)
#define TPM_ALG_RSAPSS          (TPM_ALG_ID)(0x0016)
#define TPM_ALG_SM2             (TPM_ALG_ID)(0x001B)
#define TPM_ALG_ECC             (TPM_ALG_ID)(0x0023)
#define TPM_ALG_FIRST           (TPM_ALG_ID)(0x0001)
#define TPM_ALG_LAST            (TPM_ALG_ID)(0x0044)

#define MF_PROD_WORTHY          0

#define OS_SINIT_DATA_VERSION_7 7

#ifdef MKF_USE_MAKEFLAG_H
#include <makeflag.auto>
#endif

//-----------------------------------------------------------------------------
// Module types - SINIT or BIOS AC.
//-----------------------------------------------------------------------------
#define AC_BIOSAC    0
#define AC_SINIT     1
#define AC_SINIT_REV 9

//-----------------------------------------------------------------------------
// ACM header versions
//-----------------------------------------------------------------------------
#define ACM_HEADER_V_0 0
#define ACM_HEADER_V_3 3
#define ACM_HEADER_V_4 4

//
// MLE
//

#define MLE_MAJ_HEADER_VER 0x2
#define MLE_MIN_HEADER_VER 0
//
// Header version this SINIT is compatible with: Major version 2, Minor
// version 0
//
#define MLE_HEADER_VER     (MLE_MAJ_HEADER_VER SHL 16) + MLE_MIN_HEADER_VER

#define MIN_MLE_HEADER_VER (MLE_MAJ_HEADER_VER << 16) // Minimum supported MLE header (Major version 2, Minor version 0)

//---------------------------------------------------------------------
// MLE/ACM Capabilities defines
//-----------------------------------------------------------------------------
#define CAP_GETSEC_WAKEUP               BIT0
#define CAP_MONITOR_WAKEUP              BIT1
#define CAP_EBX_ECX_PASSED              BIT2
#define CAP_STM_SUPPORTED               BIT3
#define CAP_PCRFMT_LG_NOT_SUPPORTED     BIT4
#define CAP_PCRFMT_DA_SUPPORTED         BIT5

#define CAP_PLATFORM_TYPE_MASK          BIT7 + BIT6
#define CAP_CLIENT_PLATFORM             BIT6
#define CAP_SERVER_PLATFORM             BIT7
#define CAP_MAXPHYADDR_SUPPORT          BIT8
#define CAP_TCG_COMPAT_TPM2_0_EVENTLOG  BIT9
#define CAP_BPT_SUPPORT                 BIT10
#define CAP_MEMORY_POWER_DOWN_SUPPORTED BIT11
#define CAP_BTG_UNBREAKABLE_SHUTDOWN    BIT12
#define CAP_PFR_RECOVERY                BIT13
#define CAP_TPR_DMA_PROTECTION          BIT14
#define CAP_NO_RESET_ATTACK_MITIGATION  BIT15
#define CAP_TME_SUPPORT                 BIT16
#define CAP_CSE_SECURE_CHANNEL_SUPPORT  BIT17

void AcmEntryPoint();

#endif
