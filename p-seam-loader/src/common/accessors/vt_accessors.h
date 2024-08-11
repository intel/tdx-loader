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
 * @file vmcs_accessors.h
 * @brief VMCS Accessors Definitions
 */

#ifndef SRC_COMMON_ACCESSORS_VT_ACCESSORS_H_
#define SRC_COMMON_ACCESSORS_VT_ACCESSORS_H_

#include "../../../include/pseamldr_basic_defs.h"
#include "../../../include/pseamldr_basic_types.h"
#include "x86_defs/x86_defs.h"
#include "x86_defs/vmcs_defs.h"
#include "ia32_accessors.h"
#include "helpers/error_reporting.h"

typedef uint64_t vmcs_ptr_t;

/**
 * @brief Read from VMCS entry
 * @param encoding
 *
 * @return value
 */
_STATIC_INLINE_ void ia32_vmread(uint64_t encoding, uint64_t *value) {
    //According to SDM, in 64-bit mode the instruction will fail is given an
    //operand that sets encoding bit beyond 32-bit
    pseamldr_debug_assert(encoding < BIT(32));

    //asm instruction expects both operands to be 64bit.
    ia32_rflags_t rflags;
    _ASM_VOLATILE_ ("vmreadq %2,%0\n"
			"pushfq\n"
			"popq %1"
			: "=m"(*value), "=r"(rflags.raw)
			:"r"(encoding)
			:"memory", "cc");

	pseamldr_sanity_check((rflags.cf == 0 && rflags.zf == 0), SCEC_VT_ACCESSORS_SOURCE, (uint32_t)encoding);
}

/**
 * @brief Write to VMCS entry
 * @param encoding
 * @param value
 * @return
 */
_STATIC_INLINE_ void ia32_vmwrite(uint64_t encoding, uint64_t value)
{
    //According to SDM, in 64-bit mode the instruction will fail is given an
    //operand that sets encoding bit beyond 32-bit
    pseamldr_debug_assert(encoding < BIT(32));

    //asm instruction expects both operands to be 64bit.
    ia32_rflags_t rflags;
    _ASM_VOLATILE_ ("vmwriteq %1,%2\n"
			"pushfq\n"
			"popq %0"
			: "=r"(rflags.raw)
            :"r"(value), "r"(encoding)
            : "cc");

	pseamldr_sanity_check((rflags.cf == 0 && rflags.zf == 0), SCEC_VT_ACCESSORS_SOURCE, (uint32_t)encoding);
}

/**
 * @brief Clear VMCS
 * @param vmcs_p
 */
_STATIC_INLINE_ void ia32_vmclear(vmcs_ptr_t *vmcs_p) {
	_ASM_VOLATILE_ ("vmclear %0"::"m"(vmcs_p):"memory");
}

#define SEAMOPS_CAPABILITIES_LEAF          0
#define SEAMOPS_SEAMREPORT_LEAF            1
#define SEAMOPS_SEAMDB_CLEAR_LEAF          2
#define SEAMOPS_SEAMDB_INSERT_LEAF         3
#define SEAMOPS_SEAMDB_GETREF_LEAF         4
#define SEAMOPS_SEAMDB_REPORT_LEAF         5

#define SEAMOPS_SUCCESS                    0
#define SEAMOPS_INPUT_ERROR                1
#define SEAMOPS_ENTROPY_ERROR              2
#define SEAMOPS_DATABASE_ERROR             3

_STATIC_INLINE_ void ia32_seamops_seamdb_clear(void)
{
    uint64_t leaf = SEAMOPS_SEAMDB_CLEAR_LEAF;
    uint64_t result;

    _ASM_VOLATILE_ (
#ifdef SEAM_INSTRUCTIONS_SUPPORTED_IN_COMPILER
            "seamops;"
#else
            ".byte 0x66; .byte 0x0F; .byte 0x01; .byte 0xCE;"
#endif
            :"=a"(result)
            :"a"(leaf)
            :"memory", "cc");

    pseamldr_sanity_check((result == SEAMOPS_SUCCESS), SCEC_VT_ACCESSORS_SOURCE, 4);
}

#define MAX_NUMBER_OF_SEAMDB_INSERT_RETRIES         5

_STATIC_INLINE_ uint64_t ia32_seamops_seamdb_insert(void)
{
    uint64_t leaf = SEAMOPS_SEAMDB_INSERT_LEAF;
    uint64_t result;

    _ASM_VOLATILE_ (
#ifdef SEAM_INSTRUCTIONS_SUPPORTED_IN_COMPILER
            "seamops;"
#else
            ".byte 0x66; .byte 0x0F; .byte 0x01; .byte 0xCE;"
#endif
            :"=a"(result)
            :"a"(leaf)
            :"memory", "cc");

    pseamldr_sanity_check((result == SEAMOPS_ENTROPY_ERROR) || (result == SEAMOPS_SUCCESS),
                           SCEC_VT_ACCESSORS_SOURCE, 5);

    return result;
}

_STATIC_INLINE_ uint64_t ia32_seamops_seamdb_getref(uint64_t* last_entry, uint256_t* last_entry_nonce,
                                                    uint64_t* seamdb_size)
{
    uint64_t leaf = SEAMOPS_SEAMDB_GETREF_LEAF;
    uint64_t result;

    _ASM_VOLATILE_ (
#ifdef SEAM_INSTRUCTIONS_SUPPORTED_IN_COMPILER
            "seamops;"
#else
            ".byte 0x66; .byte 0x0F; .byte 0x01; .byte 0xCE;"
#endif
            "movq %%r10, %1;"
            "movq %%r11, %2;"
            "movq %%r12, %3;"
            "movq %%r13, %4;"
            "movq %%r14, %5;"
            "movq %%r15, %6;"

            :"=a"(result), "=r"(*last_entry),   "=r"(last_entry_nonce->qwords[0]),
             "=r"(last_entry_nonce->qwords[1]), "=r"(last_entry_nonce->qwords[2]),
             "=r"(last_entry_nonce->qwords[3]), "=r"(*seamdb_size)
            :"a"(leaf)
            :"memory", "cc", "r10", "r11", "r12", "r13", "r14", "r15");

    return result;
}

_STATIC_INLINE_ uint64_t ia32_seamops_capabilities(void)
{
    uint64_t leaf = SEAMOPS_CAPABILITIES_LEAF; // for CAPABILITES
    uint64_t capabilities = 0;

    _ASM_VOLATILE_ (
#ifdef SEAM_INSTRUCTIONS_SUPPORTED_IN_COMPILER
            "seamops;"
#else
            ".byte 0x66; .byte 0x0F; .byte 0x01; .byte 0xCE;"
#endif
            :"=a"(capabilities) : "a"(leaf)
            :"memory", "cc");

    return capabilities;
}

#endif /* SRC_COMMON_ACCESSORS_VT_ACCESSORS_H_ */
