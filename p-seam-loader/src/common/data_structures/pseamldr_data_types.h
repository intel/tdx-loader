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
 * @file loader_data.h
 * @brief SEAMLDR interface structures
 */

#ifndef SRC_COMMON_DATA_STRUCTURES_PSEAMLDR_DATA_TYPES_H_
#define SRC_COMMON_DATA_STRUCTURES_PSEAMLDR_DATA_TYPES_H_

#include "../../../include/pseamldr_basic_types.h"
#include "../../../include/pseamldr_basic_defs.h"

/**
 * @struct cmr_info_entry_t
 *
 * @brief CMR_INFO provides information about a Convertible Memory Range (CMR).
 *
 * As configured by BIOS and verified and stored securely by MCHECK.
 *
 */
typedef struct PACKED cmr_info_entry_s
{
    /**
     * Base address of the CMR.  Since a CMR is aligned on 4KB, bits 11:0 are always 0.
     */
    uint64_t  cmr_base;
    /**
     * Size of the CMR, in bytes.  Since a CMR is aligned on 4KB, bits 11:0 are always 0.
     * A value of 0 indicates a null entry.
     */
    uint64_t  cmr_size;
} cmr_info_entry_t;
pseamldr_static_assert(sizeof(cmr_info_entry_t) == 16, cmr_info_entry_t);

#define MAX_PKGS             8
#define MAX_CMR             32

/**
 * @struct p_sysinfo_table_t
 *
 * @brief This table is located at the last 4KB page of P-SEAMLDR range and is used to handoff information from MCHECK and NP-SEAMLDR to P-SEAMLDR.
 *
 * This structure can be used by P-SEAMLDR as a trusted source for hardware reported information.
 *
 */
typedef struct PACKED p_sysinfo_table_s
{
    // Fields populated by MCHECK
    uint64_t version;               /**< Structure Version – Set to 0 */
    uint32_t tot_num_lps;           /**< Total number of logical processors in platform */
    uint32_t tot_num_sockets;       /**< Total number of sockets in platform */
    fms_info_t socket_cpuid_table[MAX_PKGS]; /**< List of CPUID.leaf_1.EAX values from all sockets */
    uint64_t p_seamldr_range_base;  /**< Physical base address of P_SEAMLDR_RANGE */
    uint64_t p_seamldr_range_size;  /**< Size of P_SEAMLDR_RANGE, in bytes */
    uint8_t skip_smrr2_check;       /**< When set, indicates that the TDX module should not check SMRR2. */
    uint8_t tdx_ac;                 /**< When set, indicates that TDX memory is protected by Access Control only (no memory integrity). */
    uint8_t reserved_0[62];         /**< Reserved */
    cmr_info_entry_t cmr_data[MAX_CMR]; /**< CMR info (base and size) */
    uint8_t reserved_1[1408];       /**< Reserved */

    // Fields populated by NP-SEAMLDR
    uint64_t np_seamldr_mutex;      /**< Mutex used by NP_SEAMLDR to ensure that it’s running on a single package at a time. */
    uint64_t code_rgn_base;         /**< Base address of Code region */
    uint64_t code_rgn_size;         /**< Size of code region in bytes */
    uint64_t data_rgn_base;         /**< Base address of Data region */
    uint64_t data_rgn_size;         /**< Size of data region in bytes */
    uint64_t stack_rgn_base;        /**< Base address of stack region */
    uint64_t stack_rgn_size;        /**< Size of Stack Region in bytes */
    uint64_t keyhole_rgn_base;      /**< Base address of Keyhole region */
    uint64_t keyhole_rgn_size;      /**< Size of the Keyhole region in bytes */
    uint64_t keyhole_edit_rgn_base; /**< Keyhole Edit Region Base */
    uint64_t keyhole_edit_rgn_size; /**< Size of Keyhole Edit Region in bytes */
    uint64_t module_region_base;    /**< Linear base address of SEAM range. */
    uint32_t acm_x2apicid;          /**< The X2APICID of the LP in which the last call to the “shutdown” API should be done (a.k.a. ACM_X2APICID). */
    uint32_t acm_x2apicid_valid;    /**< Whether the ACM_X2APICID field is valid. Must be 1. */
    uint8_t reserved_2[1944];       /**< Reserved */
} p_sysinfo_table_t;
pseamldr_static_assert(sizeof(p_sysinfo_table_t) == PAGE_SIZE_IN_BYTES, p_sysinfo_table_t);

/**
 * @struct sysinfo_table_t
 *
 * @brief This table is used to handoff information from MCHECK and P-SEAMLDR to the TDX module.
 *
 * It can be used by the TDX module as a trusted source for hardware reported information.
 *
 * The first 4KB page in the SEAM range is the system information table (SYS_INFO_TABLE). The low 2KB of the page contain platform information – this information is passed by MCHECK in the low 2KB of the system information table of P-SEAMLDR (P_SYS_INFO_TABLE, located at the last 4KB page of the P-SEAMLDR range), and copied to SYS_INFO_TABLE by P-SEAMLDR when a new SEAM module is loaded.
 * The high 2KB of SYS_INFO_TABLE contains information set by P-SEAMLDR itself.
 * This table is used to handoff information from MCHECK and P-SEAMLDR to the TDX module. It can be used by the TDX module as a trusted source for hardware reported information.
 *
 */

#define SYSINFO_TABLE_MCHECK_DATA_SIZE          2048

typedef struct PACKED sysinfo_table_s
{
    // Fields populated by MCHECK
    uint8_t mcheck_fields[SYSINFO_TABLE_MCHECK_DATA_SIZE];

    // Fields populated by P-SEAMDLR
    uint64_t reserved_0;            /**< deprecated SEAM status */
    uint64_t code_rgn_base;         /**< Base address of Code region */
    uint64_t code_rgn_size;         /**< Size of code region in bytes */
    uint64_t data_rgn_base;         /**< Base address of Data region */
    uint64_t data_rgn_size;         /**< Size of data region in bytes */
    uint64_t stack_rgn_base;        /**< Base address of stack region */
    uint64_t stack_rgn_size;        /**< Size of Stack Region in bytes */
    uint64_t keyhole_rgn_base;      /**< Base address of Keyhole region */
    uint64_t keyhole_rgn_size;      /**< Size of the Keyhole region in bytes */
    uint64_t keyhole_edit_rgn_base; /**< Keyhole Edit Region Base */
    uint64_t keyhole_edit_rgn_size; /**< Size of Keyhole Edit Region in bytes */
    uint64_t num_stack_pages;       /**< Data Stack size per thread unit=(# 4K pages) – 1 */
    uint64_t num_tls_pages;         /**< TLS size per thread - unit=(# 4K pages) – 1 */
    uint16_t module_hv;             /**< The native handoff version that this TDX module should support */
    uint16_t min_update_hv;         /**< The minimum handoff version that this TDX module should support */
    bool_t   no_downgrade;          /**< A boolean flag that indicates whether this TDX module should disallow downgrades */
    uint8_t  reserved_1[1];         /**< Reserved */
    uint16_t num_handoff_pages;     /**< The number of 4KB pages (minus 1) allocated at the beginning of the data region for handoff data. */
    uint8_t  reserved_2[1936];

} sysinfo_table_t;
pseamldr_static_assert(sizeof(sysinfo_table_t) == PAGE_SIZE_IN_BYTES, sysinfo_table_t);



#define ASLR_BIT_MASK                  0x7FFC
#define LINEAR_BASE_KEYEDIT_REION      0x0000000100000000
#define LINEAR_BASE_CODE_REGION        0xFFFF800000000000
#define LINEAR_BASE_STACK_REGION       0xFFFF800100000000
#define LINEAR_BASE_KEYHOLE_REGION     0xFFFF800200000000
#define LINEAR_BASE_DATA_REGION        0xFFFF800300000000
#define LINEAR_BASE_SYSINFO_TABLE      0xFFFF8003FFFF0000

#define SEAM_NON_LEAF_PXE_ATTRIBUTES         (IA32E_PG_P | IA32E_PG_RW | IA32E_PG_A | IA32E_PG_U)
#define SEAM_CODE_RANGE_ATTRIBUTES           (IA32E_PG_P | IA32E_PG_A)
#define SEAM_DATA_RANGE_ATTRIBUTES           (IA32E_PG_P | IA32E_PG_RW | IA32E_PG_A | IA32E_PG_D | IA32E_PG_XD)
#define SEAM_DATA_STACK_RANGE_ATTRIBUTES     (IA32E_PG_P | IA32E_PG_RW | IA32E_PG_A | IA32E_PG_D | IA32E_PG_XD)
#define SEAM_SHADOW_STACK_RANGE_ATTRIBUTES   (IA32E_PG_P | IA32E_PG_A | IA32E_PG_D | IA32E_PG_XD)
#define SEAM_SYSINFO_RANGE_ATTRIBUTES        (IA32E_PG_P | IA32E_PG_A | IA32E_PG_XD)
#define SEAM_IOSYSINFO_RANGE_ATTRIBUTES      (IA32E_PG_P | IA32E_PG_A | IA32E_PG_XD)
#define SEAM_KEYHOLE_RANGE_ATTRIBUTES        0
#define SEAM_KEYHOLE_PDE_ATTRIBUTES          (SEAM_NON_LEAF_PXE_ATTRIBUTES | IA32E_PG_XD)
#define SEAM_KEYHOLE_EDIT_RANGE_ATRIBUTES    (IA32E_PG_P | IA32E_PG_RW | IA32E_PG_U | IA32E_PG_A | IA32E_PG_D | IA32E_PG_XD)

#define SEAMRR_MODULE_CODE_REGION_SIZE       _2MB

#define SEAM_MODULE_PAGE_LEVEL         4

#define NUM_OF_EXCEPTION_VECTORS              32
#define SEAM_MODULE_EXCEPTION_HANDLER_SIZE    16

typedef struct memory_constants_s
{
    uint64_t module_physlimit;
    uint64_t seamcfg_region_size;
    uint64_t vmcs_region_size;
    uint64_t sysinfo_table_linbase;
    uint64_t code_region_size;
    uint64_t code_region_linbase;
    uint64_t code_region_physbase;
    uint64_t local_data_size;
    uint64_t global_data_size;
    uint64_t data_region_size;
    uint64_t data_region_linbase;
    uint64_t data_region_physbase;
    uint64_t data_stack_size;
    uint64_t shadow_stack_size;
    uint64_t lp_stack_size;
    uint64_t stack_region_size;
    uint64_t stack_region_linbase;
    uint64_t stack_region_physbase;
    uint64_t keyhole_region_size;
    uint64_t keyhole_region_linbase;
    uint64_t keyedit_region_size;
    uint64_t keyedit_region_linbase;
    uint64_t paging_structure_size;
    uint64_t pml4_physbase;
    uint64_t current_pt_physbase;
    uint64_t num_addressable_lps;
    uint64_t handoff_data_size;
    uint64_t idt_linbase;
    uint64_t gdt_linbase;
    uint64_t fault_wrapper_linbase;
    bool_t   td_preserving_supported;
} memory_constants_t;

#endif /* SRC_COMMON_DATA_STRUCTURES_PSEAMLDR_DATA_TYPES_H_ */
