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
 * @file x86_defs.h
 * @brief x86 definitions
 */

#ifndef SRC_COMMON_X86_DEFS_X86_DEFS_H_
#define SRC_COMMON_X86_DEFS_X86_DEFS_H_

#include "../../../include/pseamldr_basic_defs.h"
#include "../../../include/pseamldr_basic_types.h"

#define CPUID_FMS_STEPPING_MASK         0xFULL

typedef union {
    struct
    {
        uint64_t  offset_low   : 16;
        uint64_t  selector     : 16;
        uint64_t  reserved_0   : 8;
        uint64_t  gate_type    : 5;
        uint64_t  dpl          : 2;
        uint64_t  present      : 1;
        uint64_t  offset_high  : 16;
        uint64_t  offset_upper : 32;
        uint64_t  reserved_1   : 32;
    };
    struct
    {
        uint64_t  raw_low;
        uint64_t  raw_high;
    };
} ia32_idt_gate_descriptor;
pseamldr_static_assert(sizeof(ia32_idt_gate_descriptor) == 16, ia32_idt_gate_descriptor);

typedef union {
    struct
    {
        uint64_t
        pe          : 1,  //bit 0
        mp          : 1,  //bit 1
        em          : 1,  //bit 2
        ts          : 1,  //bit 3
        et          : 1,  //bit 4
        ne          : 1,  //bit 5
        reserved_0  : 10, //bits 6-15
        wp          : 1,  //bit 16
        reserved_1  : 1,  //bit 17
        am          : 1,  //bit 18
        reserved_2  : 10, //bits 19-28
        nw          : 1,  //bit 29
        cd          : 1,  //bit 30
        pg          : 1,  //bit 31
        reserved_3  : 32; //bits 32-63
    };
    uint64_t raw;
} ia32_cr0_t;
pseamldr_static_assert(sizeof(ia32_cr0_t) == 8, ia32_cr0_t);

#define CR0_PE           BIT(0)
#define CR0_ET           BIT(4)
#define CR0_NE           BIT(5)
#define CR0_WP           BIT(16)
#define CR0_PG           BIT(31)

#define CR0_IGNORED_MASK 0x1FFAFFC0

typedef union {
    struct
    {
        uint64_t
            reserved_0 : 3,
            pwt        : 1,
            pcd        : 1,
            reserved_1 : 7,
            base       : 52;
    };
    uint64_t raw;
} ia32_cr3_t;
pseamldr_static_assert(sizeof(ia32_cr3_t) == 8, ia32_cr3_t);

typedef union {
    struct
    {
        uint64_t
            vme        : 1,   // Bit 0
            pvi        : 1,   // Bit 1
            tsd        : 1,   // Bit 2
            de         : 1,   // Bit 3
            pse        : 1,   // Bit 4
            pae        : 1,   // Bit 5
            mce        : 1,   // Bit 6
            pge        : 1,   // Bit 7
            pce        : 1,   // Bit 8
            osfxsr     : 1,   // Bit 9
            osxmmexcpt : 1,   // Bit 10
            umip       : 1,   // Bit 11
            la57       : 1,   // Bit 12
            vmxe       : 1,   // Bit 13
            smxe       : 1,   // Bit 14
            reserved_0 : 1,   // Bit 15
            fsgsbase   : 1,   // Bit 16
            pcide      : 1,   // Bit 17
            osxsave    : 1,   // Bit 18
            keylocker  : 1,   // Bit 19
            smep       : 1,   // Bit 20
            smap       : 1,   // Bit 21
            pke        : 1,   // Bit 22
            cet        : 1,   // Bit 23
            pks        : 1,   // Bit 24
            uie        : 1,   // Bit 25
            reserved_1 : 38;  // Bits 26:63
    };
    uint64_t raw;
} ia32_cr4_t;
pseamldr_static_assert(sizeof(ia32_cr4_t) == 8, ia32_cr4_t);

#define CR4_DE              BIT(3)
#define CR4_PAE             BIT(5)
#define CR4_PGE             BIT(7)
#define CR4_OSFXSR          BIT(9)
#define CR4_OSXMMEXCPT      BIT(10)
#define CR4_VMXE            BIT(13)
#define CR4_FSGSBASE        BIT(16)
#define CR4_OSXSAVE         BIT(18)
#define CR4_SMEP            BIT(20)
#define CR4_SMAP            BIT(21)
#define CR4_CET             BIT(23)

typedef union {
    struct
    {
        uint64_t
            cf         : 1,
            reserved_0 : 1, // must be 1
            pf         : 1,
            reserved_1 : 1, // must be 0
            af         : 1,
            reserved_2 : 1, // must be 0
            zf         : 1,
            sf         : 1,
            tf         : 1,
            ief        : 1,
            df         : 1,
            of         : 1,
            iopl       : 2,
            nt         : 1,
            reserved_3 : 1, // must be 0
            rf         : 1,
            vm         : 1,
            ac         : 1,
            vif        : 1,
            vip        : 1,
            id         : 1,
            reserved_4 : 42; // must be 0
    };
    uint64_t raw;
} ia32_rflags_t;
pseamldr_static_assert(sizeof(ia32_rflags_t) == 8, ia32_rflags_t);

#define RFLAGS_ARITHMETIC_FLAGS_MASK           0x000008D5   // CF, PF, AF, ZF, SF, OF

#define IA32E_PAGING_STRUCT_ADDR_MASK    ((uint64_t) 0x000FFFFFFFFFF000LLU)
#define IA32E_256T_ADDR_MASK             ((uint64_t) 0x000F000000000000LLU)
#define IA32E_512G_ADDR_MASK             ((uint64_t) 0x000FFF8000000000LLU)
#define IA32E_1G_ADDR_MASK               ((uint64_t) 0x000FFFFFC0000000LLU)
#define IA32E_2M_ADDR_MASK               ((uint64_t) 0x000FFFFFFFE00000LLU)
#define IA32E_1G_RSRV_ADDR_MASK          ((uint64_t) 0x000000003FFFE000LLU)
#define IA32E_2M_RSRV_ADDR_MASK          ((uint64_t) 0x00000000001FE000LLU)
#define IA32E_1G_OFFSET                  ((uint64_t) 0x000000003FFFFFFFLLU)
#define IA32E_2M_OFFSET                  ((uint64_t) 0x00000000001FFFFFLLU)
#define IA32E_4K_OFFSET                  ((uint64_t) 0x0000000000000FFFLLU)

#define IA32E_4K_PAGE_OFFSET             12
#define IA32E_2M_PAGE_OFFSET             21
#define IA32E_1G_PAGE_OFFSET             30

#define IA32E_PG_P              BIT(0)
#define IA32E_PG_RW             BIT(1)
#define IA32E_PG_U              BIT(2)
#define IA32E_PG_A              BIT(5)
#define IA32E_PG_D              BIT(6)
#define IA32E_PG_XD             BIT(63)

typedef union ia32e_pxe_u {
    struct {
        uint64_t
            p         :   1,  // 0
            rw        :   1,  // 1
            us        :   1,  // 2
            pwt       :   1,  // 3
            pcd       :   1,  // 4
            a         :   1,  // 5
            d         :   1,  // 6
            pat       :   1,  // 7
            g         :   1,  // 8
            ignore_0  :   3,  // 9-11
            addr      :   40, // 12-51
            ignore_1  :   7,  // 52-58
            protkey   :   4,  // 59-62
            xd        :   1;  // 63
  } fields_4k;
  uint64_t raw;
} ia32e_pxe_t;
pseamldr_static_assert(sizeof(ia32e_pxe_t) == 8, ia32e_pxe_t);

#define MAX_PA                  52ULL
#define NULL_PA                 ~(0ULL) // -1

typedef union pa_u {
    struct {
        union {

            // Full PA that includes the HKID
            uint64_t full_pa : MAX_PA;

            // Helper accessors for paging functions
            struct {
              uint64_t
                page_offset :   12,
                pt_index    :   9,
                pd_index    :   9,
                pdpt_index  :   9,
                pml4_index  :   9,
                pml5_index  :   9;
            } fields_4k;
            struct {
              uint64_t
                page_offset :   21,
                pd_index    :   9,
                pdpt_index  :   9,
                pml4_index  :   9,
                pml5_index  :   9;
            } fields_2m;

            // Helper accessors to determine page index, depending on page size
            struct {
                uint64_t
                  low_12_bits : 12,
                  page_4k_num : (MAX_PA - 12);
            };
            struct {
                uint64_t
                  low_21_bits : 21,
                  page_2m_num : (MAX_PA - 21);
            };
            struct {
                uint64_t
                  low_30_bits : 30,
                  page_1g_num : (MAX_PA - 30);
            };

        };

        //uint64_t rsvd : 12;
    };

    uint64_t raw;
    void* raw_void;
} pa_t;
pseamldr_static_assert(sizeof(pa_t) == 8, pa_t);

#define MOVDIR64_CHUNK_SIZE     64
#define CACHELINE_SIZE          64

typedef union
{
    struct
    {
        uint32_t rsvd :14; // 0-13
        uint32_t max_num_of_lps_sharing_cache :12; // 14-25
        uint32_t rsvd1 :4;
    };
    uint32_t raw;
} cpu_cache_params_t;
pseamldr_static_assert(sizeof(cpu_cache_params_t) == 4, cpu_cache_params_t);

/**
 * CPUID definitions
 */

#define CPUID_DET_CACHE_PARAMS_LEAF 4
#define CPUID_DET_CACHE_PARAMS_SUBLEAF 3

#define CPUID_GET_TOPOLOGY_LEAF 0x1F
#define CPUID_GET_TOPOLOGY_MAX_SUBLEAF 0x5

#define CPUID_GET_MAX_PA_LEAF 0x80000008
#define CPUID_MAX_PA_BITS     BITS(7,0)

#define CPUID_VERSION_INFORMATION_FMS   0x1

typedef union
{
    struct
    {
        uint32_t stepping_id        : 4;
        uint32_t model              : 4;
        uint32_t family             : 4;
        uint32_t processor_type     : 2;
        uint32_t rsvd0              : 2;
        uint32_t extended_model_id   : 4;
        uint32_t extended_family_id : 8;
        uint32_t rsvd1              : 4;
    };
    uint32_t raw;
} fms_info_t; //cpuid_01_eax
pseamldr_static_assert(sizeof(fms_info_t) == 4, fms_info_t);

typedef union
{
    struct
    {
        uint32_t level_number : 8;
        uint32_t level_type   : 8;
        uint32_t rsvd         : 16;
    };
    uint32_t raw;
} cpuid_topology_level_t;  //cpuid_04_03_ecx
pseamldr_static_assert(sizeof(cpuid_topology_level_t) == 4, cpuid_topology_level_t);

typedef enum
{
    LEVEL_TYPE_INVALID = 0,
    LEVEL_TYPE_SMT     = 1,
    LEVEL_TYPE_CORE    = 2,
    LEVEL_TYPE_MODULE  = 3,
    LEVEL_TYPE_TILE    = 4,
    LEVEL_TYPE_DIE     = 5,
    LEVEL_TYPE_MAX     = 6
} cpuid_topology_level_type_e;

typedef union
{
    struct
    {
        uint32_t shift_count : 5;
        uint32_t rsvd        : 27;
    };
    uint32_t raw;
} cpuid_topology_shift_t;
pseamldr_static_assert(sizeof(cpuid_topology_shift_t) == 4, cpuid_topology_shift_t);

#endif /* SRC_COMMON_X86_DEFS_X86_DEFS_H_ */
