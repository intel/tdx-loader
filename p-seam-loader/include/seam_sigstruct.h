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
 * @file seam_sigstruct.h
 * @brief SEAM signature structure
 */
#ifndef INCLUDE_SEAM_SIGSTRUCT_H_
#define INCLUDE_SEAM_SIGSTRUCT_H_

#define SIGSTRUCT_MODULUS_SIZE 384
#define SIGSTRUCT_SIGNATURE_SIZE 384
#define SIGSTRUCT_SEAMHASH_SIZE 48

#include "pseamldr_basic_types.h"
#include "debug/tdx_debug.h"

#pragma pack(push,1)

#define SEAM_SIGSTRUCT_KEY_SIZE_DWORDS        0x60
#define SEAM_SIGSTRUCT_MODULUS_SIZE_DWORDS    0x60
#define SEAM_SIGSTRUCT_EXPONENT_SIZE_DWORDS   0x1
#define SEAM_SIGSTRUCT_RSA_EXPONENT           0x10001 // (2^16 + 1)
#define SEAM_SIGSTRUCT_HEADER_TYPE_GENERIC_FW 0x6
#define SEAM_SIGSTRUCT_HEADER_LENGTH_DWORDS   0xE1
#define SEAM_SIGSTRUCT_HEADER_VERSION_MINOR   0x0UL
#define SEAM_SIGSTRUCT_HEADER_VERSION_MAJOR   0x1UL
#define SEAM_SIGSTRUCT_HEADER_VERSION         ((SEAM_SIGSTRUCT_HEADER_VERSION_MAJOR << 16) | \
                                                SEAM_SIGSTRUCT_HEADER_VERSION_MINOR)
#define SEAM_SIGSTRUCT_SIZE_DWORDS            0x200

#define SEAM_SIGSTRUCT_INTEL_MODULE_VENDOR    0x8086
#define SEAM_SIGSTRUCT_MAX_CPUID_TABLE_SIZE   255

typedef union
{
    struct
    {
        uint32_t reserved        : 31;
        uint32_t is_debug_signed : 1;
    };

    uint32_t raw;
} module_type_t;

#define TDX_MODULE_1_0_MAJOR_SVN            0

typedef union seam_svn_u
{
    struct
    {
        uint8_t seam_minor_svn;
        uint8_t seam_major_svn;
    };

    uint16_t raw;
} seam_svn_t;
pseamldr_static_assert(sizeof(seam_svn_t) == 2, seam_svn_t);

#define SEAM_SIGSTRUCT_SIZE            2048
#define SEAM_SIGSTRUCT_HEADER_SIZE     128
#define SEAM_SIGSTRUCT_SIG_OFFSET      SEAM_SIGSTRUCT_HEADER_SIZE
#define SEAM_SIGSTRUCT_SIG_SIZE        (384+4+384)
#define SEAM_SIGSTRUCT_BODY_OFFSET     (SEAM_SIGSTRUCT_SIG_OFFSET + SEAM_SIGSTRUCT_SIG_SIZE)
#define SEAM_SIGSTRUCT_BODY_SIZE       (SEAM_SIGSTRUCT_SIZE - SEAM_SIGSTRUCT_HEADER_SIZE - SEAM_SIGSTRUCT_SIG_SIZE)

#if ((SEAM_SIGSTRUCT_BODY_OFFSET + SEAM_SIGSTRUCT_BODY_SIZE) != SEAM_SIGSTRUCT_SIZE)
#error "Wrong SEAM SIGSTRUCT size constants!!!"
#endif

typedef struct
{
    uint32_t header_type;
    uint32_t header_length;
    uint32_t header_version;
    module_type_t module_type;
    uint32_t module_vendor;
    uint32_t date;
    uint32_t size;
    uint32_t key_size;
    uint32_t modulus_size;
    uint32_t exponent_size;
    uint8_t reserved0[88];

    uint8_t modulus[SIGSTRUCT_MODULUS_SIZE];
    uint32_t exponent;
    uint8_t signature[SIGSTRUCT_SIGNATURE_SIZE];

    uint8_t seamhash[SIGSTRUCT_SEAMHASH_SIZE];
    seam_svn_t seamsvn;
    uint64_t attributes;
    uint32_t rip_offset;
    uint8_t num_stack_pages;
    uint8_t num_tls_pages;
    uint16_t num_keyhole_pages;
    uint16_t num_global_data_pages;
    uint16_t max_tdmrs;
    uint16_t max_rsvd_per_tdmr;
    uint16_t pamt_entry_size_4k;
    uint16_t pamt_entry_size_2m;
    uint16_t pamt_entry_size_1g;
    uint8_t  reserved1[6];
    uint16_t module_hv;
    uint16_t min_update_hv;
    bool_t   no_downgrade;
    uint8_t  reserved2[1];
    uint16_t num_handoff_pages;

    uint32_t gdt_idt_offset;
    uint32_t fault_wrapper_offset;
    uint8_t  reserved3[24];

    uint32_t cpuid_table_size;
    uint32_t cpuid_table[SEAM_SIGSTRUCT_MAX_CPUID_TABLE_SIZE];

} seam_sigstruct_t;

#pragma pack(pop)

pseamldr_static_assert(sizeof(seam_sigstruct_t) == SEAM_SIGSTRUCT_SIZE, seam_sigstruct_t);
pseamldr_static_assert(offsetof(seam_sigstruct_t, modulus) == SEAM_SIGSTRUCT_SIG_OFFSET, seam_sigstruct_t);
pseamldr_static_assert(offsetof(seam_sigstruct_t, seamhash) == SEAM_SIGSTRUCT_BODY_OFFSET, seam_sigstruct_t);


#endif /* INCLUDE_SEAM_SIGSTRUCT_H_ */
