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

#ifndef _ACCESSORS_H_
#define _ACCESSORS_H_

#pragma once

#define CPUID_VERSION_INFORMATION_FMS                     0x1
#define CPUID_DETERMINISTIC_CACHE_PARAMS                  0x4
#define B_MAX_PROC_ID_SHARING_TARGET_CACHE                0x3FFC000
#define N_MAX_PROC_ID_SHARING_TARGET_CACHE                14
#define CPUID_EXTENDED_FEATURE_INFORMATION                0x7
#define CPUID_EXTENDED_FEATURE_INFORMATION_5_LEVEL_PAGING BIT16
#define CPUID_EXTENDED_TOPOLOGY                           0x0B
#define CPUID_V2_EXTENDED_TOPOLOGY                        0x1F
#define CPUID_EXTENDED_TOPOLOGY_LEVEL_TYPE_SMT            0x01

//TODO - really use the atomic op
char InterlockedCompareExchange8(char volatile *Destination,
                                 char Exchange,
                                 char Comparand);

/**
 * Retrieves CPUID information.
 *
 * Executes the CPUID instruction with EAX set to the value specified by Index.
 * This function always returns Index.
 * If Eax is not NULL, then the value of EAX after CPUID is returned in Eax.
 * If Ebx is not NULL, then the value of EBX after CPUID is returned in Ebx.
 * If Ecx is not NULL, then the value of ECX after CPUID is returned in Ecx.
 * If Edx is not NULL, then the value of EDX after CPUID is returned in Edx.
 * This function is only available on IA-32 and x64.
 *
 * @param  Index The 32-bit value to load into EAX prior to invoking the CPUID
 * instruction.
 * @param  Eax   The pointer to the 32-bit EAX value returned by the CPUID
 * instruction. This is an optional parameter that may be NULL.
 * @param  Ebx   The pointer to the 32-bit EBX value returned by the CPUID
 * instruction. This is an optional parameter that may be NULL.
 * @param  Ecx   The pointer to the 32-bit ECX value returned by the CPUID
 * instruction. This is an optional parameter that may be NULL.
 * @param  Edx   The pointer to the 32-bit EDX value returned by the CPUID
 * instruction. This is an optional parameter that may be NULL.
 *
 * @return Index.
 *
 **/
UINT32
AsmCpuid(IN UINT32 Index,
         OPTIONAL OUT UINT32 *Eax,
         OPTIONAL OUT UINT32 *Ebx,
         OPTIONAL OUT UINT32 *Ecx,
         OPTIONAL OUT UINT32 *Edx);

/**
 * Retrieves CPUID information using an extended leaf identifier.
 *
 * Executes the CPUID instruction with EAX set to the value specified by Index
 * and ECX set to the value specified by SubIndex. This function always returns
 * Index. This function is only available on IA-32 and x64.
 *
 * If Eax is not NULL, then the value of EAX after CPUID is returned in Eax.
 * If Ebx is not NULL, then the value of EBX after CPUID is returned in Ebx.
 * If Ecx is not NULL, then the value of ECX after CPUID is returned in Ecx.
 * If Edx is not NULL, then the value of EDX after CPUID is returned in Edx.
 *
 * @param  Index     The 32-bit value to load into EAX prior to invoking the
 * CPUID instruction.
 * @param  SubIndex  The 32-bit value to load into ECX prior to invoking the
 * CPUID instruction.
 * @param  Eax       The pointer to the 32-bit EAX value returned by the CPUID
 * instruction. This is an optional parameter that may be
 * NULL.
 * @param  Ebx       The pointer to the 32-bit EBX value returned by the CPUID
 * instruction. This is an optional parameter that may be
 * NULL.
 * @param  Ecx       The pointer to the 32-bit ECX value returned by the CPUID
 * instruction. This is an optional parameter that may be
 * NULL.
 * @param  Edx       The pointer to the 32-bit EDX value returned by the CPUID
 * instruction. This is an optional parameter that may be
 * NULL.
 *
 * @return Index.
 *
 **/
UINT32
CpuidEx(IN UINT32 Index,
        IN UINT32 SubIndex,
        OPTIONAL OUT UINT32 *Eax,
        OPTIONAL OUT UINT32 *Ebx,
        OPTIONAL OUT UINT32 *Ecx,
        OPTIONAL OUT UINT32 *Edx);

INT32 RdSeed16(OUT UINT16 *Val);
INT32 RdSeed32(OUT UINT32 *Val);
INT32 RdSeed64(OUT UINT64 *Val);

#endif //_ACCESSORS_H_
