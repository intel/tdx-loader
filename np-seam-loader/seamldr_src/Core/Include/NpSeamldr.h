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

#include "NpSeamldrApi.h"
#include "vmcs.h"
#include "msr.h"

#define SEAMLDR_FLAG_BOOT              0
#define SEAMLDR_FLAG_UPDATE            1
#define SEAMLDR_FLAG_NOT_LOADED        0
#define SEAMLDR_FLAG_LOADED            1
#define SEAMLDR_FLAG_LOAD_IN_PRORGRESS 2

#define SP_SEAMLDR_PLAG_READY          1
#define SEAM_EXTEND_SEAM_READY_VAL     0

#define NP_SEAMLDR_MUTEX_CLEAR         0
#define NP_SEAMLDR_MUTEX_ACQUIRED      1

#define P_SYS_INFO_TABLE_VERSION       0
#define IO_SYS_INFO_TABLE_MAX_VERSION  1

// linear address defs
#define C_KEYHOLE_EDIT_REGION_BASE  0x0000000100000000
#define C_CODE_RGN_BASE             0xFFFF800000000000
#define C_STACK_RGN_BASE            0xFFFF800100000000
#define C_KEYHOLE_RGN_BASE          0xFFFF800200000000
#define C_DATA_RGN_BASE             0xFFFF800300000000
#define C_SYS_INFO_TABLE_BASE       0xFFFF8003FFFF0000
#define C_IO_SYS_INFO_TABLE_BASE    0xFFFF8003FFFF1000
#define C_MODULE_RGN_BASE           0x0000000200000000
#define CODE_REGION_ALLOCATED_SIZE  _2MB
#define P_SEAMLDR_SHADOW_STACK_SIZE _4KB
#define C_VMCS_REGION_SIZE          _8KB // including the reserved unmapped page

#define C_P_SYS_INFO_TABLE_SIZE     _4KB

#define PAGING_STRUCTURE_SIZE(rgnSize) (((((((rgnSize) / _4KB) * 8) + _4KB - 1) / _4KB) + \
                                         ((((rgnSize) / _2MB) * 8) + _4KB - 1) / _4KB + \
                                         ((((rgnSize) / _1GB) * 8) + _4KB - 1) / _4KB) * _4KB)

#define NON_CANONICAL_RIP       0x1000000000000000ULL

#define CANONICITY_MASK_4LP     (~(BIT47 - 1))
#define CANONICITY_MASK_5LP     (~(BIT56 - 1))

#define SEAM_EXTEND_VALID_INTEL 0x1FF
#define SEAM_EXTEND_VALID_OEM   0xFFFF

#define MOVDIR64B_BLOCK_SIZE    64

#define CPUID_FM_MASK           0xFFFFFFF0

#define SEAMRR_PAGE_SIZE        _4KB

#define ALIGN(x, a)           __ALIGN_MASK(x, (a) - 1)
#define __ALIGN_MASK(x, mask) (((x) + (mask)) & ~(mask))

typedef struct {
  UINT64 SeamrrVa;
  UINT64 SeamrrVaLimit;
  UINT64 AslrRand;
  UINT64 PhysAddrMask;
//  UINT64              TdxPrivateKidMask;
  UINT64              CStackRgnSize;
  UINT64              CKeyholeRgnSize;
  UINT64              CKeyholeEditRgnSize;
  UINT64              SeamrrBase;
  UINT64              SeamrrSize;
  P_SYS_INFO_TABLE_t *PSysInfoTable;
  UINT8               Padding_0[256 - 80]; // for the next field's alignment
  __declspec(align(256)) SEAM_EXTEND_t SeamExtend;
  P_SEAMLDR_CONSTS_t *PSeamldrConsts;
  UINT8               Padding_1[256 - sizeof(SEAM_EXTEND_t) - sizeof(UINTN)];
} SeamldrData_t;

BOOL SeamldrParamsAddressValid(UINTN SeamldrParamsPa);
BOOL SeamldrParamsValid();
BOOL SafeCompare(UINT8 *a, UINT8 *b, UINT64 size);
void MemZeroWithMovdir64B(UINT8 *dst, UINT64 size);
UINT64 VerifyManifest(P_SYS_INFO_TABLE_t *SysInfoTable, UINT32 Scenario, BOOL IsAcmProductionSigned);

extern SeamldrData_t SeamldrData;
extern UINT8 VmcsBuffer[VMCS_SIZE];
extern UINT8 TempGdt[PAGE4K];

// Crypto-related defs and funcs

#define IPP_BUFFER_SIZE 0x2000

extern UINT8 StaticIPPMembuf[IPP_BUFFER_SIZE];

#define SIZE_OF_SHA384_BLOCK_IN_QWORD 16
#define SIZE_OF_SHA384_BLOCK_IN_DWORD (SIZE_OF_SHA384_BLOCK_IN_QWORD << 1)
#define SIZE_OF_SHA384_BLOCK_IN_BYTES (SIZE_OF_SHA384_BLOCK_IN_DWORD << 2)
#define SIZE_OF_SHA384_STATE_IN_QWORD 8
#define SIZE_OF_SHA384_STATE_IN_DWORD (SIZE_OF_SHA384_STATE_IN_QWORD << 1)
#define SIZE_OF_SHA384_STATE_IN_BYTES (SIZE_OF_SHA384_STATE_IN_DWORD << 2)

typedef struct {
  UINT64 Total[2];                              /*!< The number of Bytes processed. */
  UINT64 State[SIZE_OF_SHA384_STATE_IN_QWORD];  /*!< The intermediate digest state. */
  UINT8  Buffer[SIZE_OF_SHA384_BLOCK_IN_BYTES]; /*!< The data block being processed. */
} Sha384Ctx_t;

typedef struct {
  UINT8 *BlockByteBuffer;
} Sha384_128B_Block_t;

void Sha384GenerateHash128B(const UINT8 *Message, UINT32 Size, UINT8 *Hash);
UINT64 VerifySignature(UINT8 *Signature, const UINT8 *Message, UINT32 MessageLen, UINT32 PublicExp, const UINT8 *Modulo);
UINT64 ComputeAndVerifySeamSignersKeyHash();
UINT64 ComputeAndVerifyModuleHash();
UINT64 memcpy_s(void *dest, UINTN destSize, const void *src, UINTN count);

#ifndef _SEAMLDR_VALIDATION_
#define PRINT_HEX_VAL(Description, Value) { COMSERIALOUT(Description); \
                                            PRINTHEX(Value); \
                                            COMSERIALOUT("\n"); }
#endif
