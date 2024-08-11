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
 * @file pseamldr_api_defs.h
 * @brief PSEAMLDR API Definitions
 */
#ifndef __PSEAMLDR_API_DEFS_H_INCLUDED__
#define __PSEAMLDR_API_DEFS_H_INCLUDED__

#include "pseamldr_basic_defs.h"
#include "pseamldr_basic_types.h"

#pragma pack(push)
#pragma pack(1)

/**< Enum for SEAMCALL leaves opcodes */
typedef enum
{
    SEAMLDR_INFO_LEAF             = 0x8000000000000000,
    SEAMLDR_INSTALL_LEAF          = 0x8000000000000001,
    SEAMLDR_SHUTDOWN_LEAF         = 0x8000000000000002,
    SEAMLDR_SEAMINFO_LEAF         = 0x8000000000000003,
    SEAMLDR_CLEANUP_LEAF          = 0x8000000000000004

#ifdef DEBUGFEATURE_TDX_DBG_TRACE
    ,TDDEBUGCONFIG_LEAF           = 0x80000000000000FE
#endif

} SEAMCALL_LEAVES_OPCODES;

// Error codes
#define PSEAMLDR_SUCCESS            0x0ULL
#define PSEAMLDR_EBADPARAM          0x8000000000000000ULL // Bad input parameter.
#define PSEAMLDR_EBADCALL           0x8000000000000003ULL // P-SEAMLDR has already been called.
#define PSEAMLDR_EBADHANDOFF        0x8000000000000004ULL // Update failure due to invalid or unsupported handoff data.
#define PSEAMLDR_EUNSUPPORTED       0x8000000000000006ULL // Unsupported module SVN major version in sigstruct
#define PSEAMLDR_ENOMEM             0x8000000000010002ULL // The new TDX module does not fit within the SEAM range constraints.
#define PSEAMLDR_EUNSPECERR         0x8000000000010003ULL // Unspecified platform configuration error.
#define PSEAMLDR_EUNSUPCPU          0x8000000000010004ULL // The module does not support one or more CPUs in the platform.
#define PSEAMLDR_EBADSIG            0x8000000000020000ULL // Bad TDX module signature (malformed, or signature verification failed).
#define PSEAMLDR_EBADHASH           0x8000000000020001ULL // Module image hash verification failed.
#define PSEAMLDR_EINTERRUPT         0x8000000000030000ULL // Interrupt occurred
#define PSEAMLDR_ENOENTROPY         0x8000000000030001ULL // Insufficient entropy for generating random numbers.
#define PSEAMLDR_ECLEANUPREQ        0x8000000000000005ULL // If cleanup is required during module install

typedef uint64_t api_error_type;

#define PSEAMLDR_RECOVERABLE_ERROR              0
#define PSEAMLDR_UNRECOVERABLE_ERROR            1

#define SEAMLDR_SCENARIO_LOAD                   0
#define SEAMLDR_SCENARIO_UPDATE                 1

#define SEAMLDR_PARAMS_MIN_MODULE_PAGES         1

#define SEAMLDR_PARAMS_MAX_MODULE_PAGES_V0      496

#define SEAMLDR_PARAMS_SIZE                     _4KB
#define SEAMLDR_PARAMS_MAX_MODULE_PAGES         SEAMLDR_PARAMS_MAX_MODULE_PAGES_V0

#define SEAM_MODULE_PAGE_SIZE                   _4KB

typedef struct seamldr_params_s
{
    uint32_t version;
    uint32_t scenario;
    uint64_t sigstruct_pa;
    uint8_t  reserved[104];
    uint64_t num_module_pages;
    uint64_t mod_pages_pa_list[SEAMLDR_PARAMS_MAX_MODULE_PAGES];
} seamldr_params_t;
pseamldr_static_assert(sizeof(seamldr_params_t) == SEAMLDR_PARAMS_SIZE, seamldr_params_t);

typedef union attributes_s
{
    struct
    {
        uint32_t reserved : 31;
        uint32_t is_debug : 1;
    };
    uint32_t raw;
} attributes_t;
pseamldr_static_assert(sizeof(attributes_t) == 4, attributes_t);

typedef struct PACKED tee_tcb_snv_s
{
    union
    {
        struct
        {
            uint8_t seam_minor_svn;
            uint8_t seam_major_svn;
        };
        uint16_t current_seam_svn;
    };

    uint8_t  last_patch_se_svn;
    uint8_t  reserved[13];
} tee_tcb_svn_t;
pseamldr_static_assert(sizeof(tee_tcb_svn_t) == 16, tee_tcb_svn_t);

/**
 * @struct seamextend_t
 *
 * @brief The processor maintains a platform-scoped register called SEAMEXTEND,
 *
 * Which records the attributes of the current SEAM module, and its basic execution controls.
 * P-SEAMLDR can retrieve and update this register using IA32_SEAMEXTEND command MSR.
 *
 */
typedef struct PACKED seamextend_s
{
    uint64_t      valid;
    tee_tcb_svn_t tee_tcb_svn;
    uint8_t       mrseam[48];
    uint8_t       mrsigner[48];
    uint64_t      attributes;
    uint8_t       seam_ready;
    bool_t        system_under_debug;
    uint8_t       p_seamldr_ready;
    uint8_t       reserved[5];
} seamextend_t;
pseamldr_static_assert(sizeof(seamextend_t) == 136, seamextend_t);

typedef union seamldr_info_features0_u
{
    struct
    {
        uint64_t s4_mig_api_supported : 1;  // Bit 0
        uint64_t cleanup_supported    : 1;  // Bit 1
        uint64_t reserved             : 62; // Bit 2-63
    };
    uint64_t raw;
} seamldr_info_features0_t;
pseamldr_static_assert(sizeof(seamldr_info_features0_t) == 8, seamldr_info_features0_t);

typedef struct seamldr_info_s
{
    uint32_t     version;
    attributes_t attributes;
    uint32_t     vendor_id;
    uint32_t     build_date;
    uint16_t     build_num;
    uint16_t     minor;
    uint16_t     major;
    uint16_t     reserved_0;
    uint32_t     acm_x2apic;
    uint32_t     num_remaining_updates;
    seamextend_t seamextend;
    seamldr_info_features0_t features0;
    uint8_t      reserved_2[80];
} seamldr_info_t;
pseamldr_static_assert(sizeof(seamldr_info_t) == 256, seamldr_info_t);

typedef struct handoff_data_header_s
{
    bool_t   valid;
    uint8_t  reserved;
    uint16_t hv;
    uint32_t size;
} handoff_data_header_t;
pseamldr_static_assert(sizeof(handoff_data_header_t) == 8, handoff_data_header_t);

typedef struct pseamldr_constants_s
{
    uint64_t data_stack_size;
    uint64_t code_region_size;
    uint64_t data_region_size;
    uint64_t keyhole_region_size;
    uint64_t keyhole_edit_region_size;
    uint64_t entry_point_offset;
} pseamldr_constants_t;

#define NUM_CACHELINES_IN_PAGE 64

#pragma pack(pop)


#endif // __PSEAMLDR_API_DEFS_H_INCLUDED__
