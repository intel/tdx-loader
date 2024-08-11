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
 * @file ia32_accessors.h
 * @brief IA32 Accessors Definitions
 */

#ifndef SRC_COMMON_ACCESSORS_IA32_ACCESSORS_H_
#define SRC_COMMON_ACCESSORS_IA32_ACCESSORS_H_

#include "pseamldr_basic_defs.h"
#include "pseamldr_basic_types.h"
#include "x86_defs/x86_defs.h"
#include "x86_defs/mktme.h"

/**
 * @brief Generate random 64-bit number. Returns false if generation failed (no entropy)
 *
 * @param rand_out
 */
_STATIC_INLINE_ bool_t ia32_rdrand64(uint64_t* rand_out)
{
    ia32_rflags_t rflags;
    uint64_t rand = 0;

    _ASM_VOLATILE_("rdrandq %0 \n"
                   "pushfq; popq %1\n"
                   : "=r" (rand), "=r" (rflags.raw));

    *rand_out = rand;

    return (rflags.cf != 0);
}

/**
 * @brief Invalidate TLB entries by calling INVLPG instruction
 * @param addr
 */
_STATIC_INLINE_ void ia32_invalidate_tlb_entries(uint64_t addr)
{
	_ASM_VOLATILE_ ("invlpg (%0);"::"r"(addr):"memory");
}

/**
 * @brief Call CPUID instruction
 * @param leaf
 * @param subleaf
 * @param eax
 * @param ebx
 * @param ecx
 * @param edx
 */
_STATIC_INLINE_ void ia32_cpuid(uint32_t leaf, uint32_t subleaf, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
{

	_ASM_VOLATILE_ ("cpuid;"              // CPUID
                     : "=a" (*eax),        // Outputs: eax = %eax
                       "=b" (*ebx),        //          ebx = %ebx
                       "=c" (*ecx),        //          ecx = %ecx
                       "=d" (*edx)         //          edx = %edx
                     : "a"  (leaf),        // Inputs:  eax = leaf
                       "c"  (subleaf) );   //          ecx = subleaf
}

_STATIC_INLINE_ void ia32_clear_ac( void )
{
	_ASM_VOLATILE_ ("clac;":::"cc");
}

_STATIC_INLINE_ void ia32_set_ac( void )
{
	_ASM_VOLATILE_ ("stac;":::"cc");
}

/**
 * @brief Call UD2 instruction
 */
_STATIC_INLINE_ void ia32_ud2( void )
{
    _ASM_VOLATILE_ ("ud2" ::: ) ;
}

_STATIC_INLINE_ uint64_t ia32_rdmsr(uint64_t addr)
{
    uint32_t low,high;
    _ASM_VOLATILE_ ("rdmsr" : "=a"(low), "=d"(high) : "c"(addr));
    return (uint64_t)((((uint64_t)(high)) << 32) | (uint64_t)(low));
}

_STATIC_INLINE_ uint64_t ia32_rdmsr_with_input(uint64_t addr, uint64_t input)
{
    uint32_t low,high;
    _ASM_VOLATILE_ ("rdmsr" : "=a"(low), "=d"(high) : "a"((uint32_t)input), "d"((uint32_t)(input >> 32)), "c"(addr));
    return (uint64_t)((((uint64_t)(high)) << 32) | (uint64_t)(low));
}

_STATIC_INLINE_ void ia32_wrmsr(uint64_t addr, uint64_t value)
{
    _ASM_VOLATILE_ ("wrmsr" : : "a"((uint32_t)value), "d"((uint32_t)(value >> 32)), "c"(addr));
}

_STATIC_INLINE_ void ia32_out16( uint16_t port, uint16_t val )
{
    _ASM_VOLATILE_ ("outw %0,%w1" : : "a" (val), "dN" (port));
}

_STATIC_INLINE_ void ia32_pause( void )
{
    _ASM_VOLATILE_ ("pause" ) ;
}

_STATIC_INLINE_ void ia32_out8( uint16_t port, uint8_t val )
{
    _ASM_VOLATILE_ ("outb %0,%w1" : : "a" (val), "dN" (port));
}

_STATIC_INLINE_ uint8_t ia32_in8( uint16_t port )
{
    uint8_t v;

    _ASM_VOLATILE_ ("inb %w1,%0" : "=a" (v) : "Nd" (port));

    return v;
}

_STATIC_INLINE_ uint64_t ia32_rdtsc( void )
{
    uint32_t a, d;

    _ASM_VOLATILE_ ("rdtsc"
                   : "=a"(a), "=d"(d));
    return ( ((uint64_t) d << 32) | (uint64_t) a );
}

_STATIC_INLINE_ uint64_t ia32_set_timeout(uint64_t period)
{
    return ia32_rdtsc() + period;
}

_STATIC_INLINE_ bool_t ia32_is_timeout_expired(uint64_t endtime)
{
    return (int64_t)(endtime - ia32_rdtsc()) < 0;
}

_STATIC_INLINE_ uint64_t bit_scan_forward64(uint64_t mask)
{
    uint64_t lsb_position;
    _ASM_VOLATILE_ ("bsfq %1, %0 \n"
                        :"=r"(lsb_position)
                        :"r"(mask)
                        :);

    return lsb_position;
}

_STATIC_INLINE_ uint64_t bit_scan_reverse64(uint64_t mask)
{
    uint64_t msb_position;
    _ASM_VOLATILE_ ("bsrq %1, %0 \n"
                        :"=r"(msb_position)
                        :"r"(mask)
                        :);

    return msb_position;
}

_STATIC_INLINE_ void movdir64b(const void *src, uint64_t dst)
{
    _ASM_VOLATILE_ (".byte  0x66, 0x0F, 0x38, 0xF8," /*movdir64b op*/ "0x37;" /*ModRM = RDI->RSI*/
                    : : "D"(src), "S"(dst) : "memory" );
}

_STATIC_INLINE_ void lfence(void)
{
    _ASM_VOLATILE_ ("lfence" : : : "memory");
}

_STATIC_INLINE_ void mfence(void)
{
    _ASM_VOLATILE_ ("mfence" : : : "memory");
}

_STATIC_INLINE_ void sfence(void)
{
    _ASM_VOLATILE_ ("sfence" : : : "memory");
}

_STATIC_INLINE_ void serialize(void)
{
    _ASM_VOLATILE_ (".byte  0x0F, 0x01, 0xE8" /*SERIALIZE op*/ : : : "memory");
}

/**
 * @brief issue PCONFIG command to program MKTME keys
 * @param key_program_addr
 * @return
 */
_STATIC_INLINE_ uint64_t ia32_mktme_key_program(mktme_key_program_t *key_program_addr)
{
    ia32_rflags_t ret_flags;
    uint64_t error_code;
    _ASM_VOLATILE_ (
        #ifdef PCONFIG_SUPPORTED_IN_COMPILER
            "pconfig;"
        #else
            ".byte 0x0F\n"
            ".byte 0x01\n"
            ".byte 0xC5\n"
        #endif
        "pushfq\n"
        "popq %%rcx"
        : "=a"(error_code), "=c"(ret_flags.raw) : "a"(0), "b"(key_program_addr) : "cc");
    // On return: ZF=0 indicates success; ZF=1 indicates failure (error code in RAX).  ZF is bit 6 in EFLAGS
    return (ret_flags.zf) ? error_code : 0;
}

_STATIC_INLINE_ void store_xmms_in_buffer(uint128_t xmms[16])
{
    _ASM_VOLATILE_ (
         // Storing the existing XMM's
            "movdqa %%xmm0, (%0)\n"
            "movdqa %%xmm1, 0x10(%0)\n"
            "movdqa %%xmm2, 0x20(%0)\n"
            "movdqa %%xmm3, 0x30(%0)\n"
            "movdqa %%xmm4, 0x40(%0)\n"
            "movdqa %%xmm5, 0x50(%0)\n"
            "movdqa %%xmm6, 0x60(%0)\n"
            "movdqa %%xmm7, 0x70(%0)\n"
            "movdqa %%xmm8, 0x80(%0)\n"
            "movdqa %%xmm9, 0x90(%0)\n"
            "movdqa %%xmm10, 0xA0(%0)\n"
            "movdqa %%xmm11, 0xB0(%0)\n"
            "movdqa %%xmm12, 0xC0(%0)\n"
            "movdqa %%xmm13, 0xD0(%0)\n"
            "movdqa %%xmm14, 0xE0(%0)\n"
            "movdqa %%xmm15, 0xF0(%0)\n"

        : : "r"(xmms));
}

_STATIC_INLINE_ void load_xmms_from_buffer(const uint128_t xmms[16])
{
    _ASM_VOLATILE_ (
            "movdqa (%0), %%xmm0\n"
            "movdqa 0x10(%0), %%xmm1\n"
            "movdqa 0x20(%0), %%xmm2\n"
            "movdqa 0x30(%0), %%xmm3\n"
            "movdqa 0x40(%0), %%xmm4\n"
            "movdqa 0x50(%0), %%xmm5\n"
            "movdqa 0x60(%0), %%xmm6\n"
            "movdqa 0x70(%0), %%xmm7\n"
            "movdqa 0x80(%0), %%xmm8\n"
            "movdqa 0x90(%0), %%xmm9\n"
            "movdqa 0xA0(%0), %%xmm10\n"
            "movdqa 0xB0(%0), %%xmm11\n"
            "movdqa 0xC0(%0), %%xmm12\n"
            "movdqa 0xD0(%0), %%xmm13\n"
            "movdqa 0xE0(%0), %%xmm14\n"
            "movdqa 0xF0(%0), %%xmm15\n"

        : : "r"(xmms));
}

#endif /* SRC_COMMON_ACCESSORS_IA32_ACCESSORS_H_ */
