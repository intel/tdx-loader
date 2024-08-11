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
 * @file msr_defs.h
 * @brief msr definitions
 */


#ifndef SRC_COMMON_X86_DEFS_MSR_DEFS_H_
#define SRC_COMMON_X86_DEFS_MSR_DEFS_H_

#include "../../../include/pseamldr_basic_defs.h"
#include "../../../include/pseamldr_basic_types.h"
#include "x86_defs.h"

#define IA32_SEAMRR_BASE_MSR_ADDR                        0x1400
#define IA32_SEAMRR_MASK_MSR_ADDR                        0x1401
#define IA32_SEAMEXTEND_MSR_ADDR                         0x1402

#define IA32_TME_CAPABILITY_MSR_ADDR                     0x981
#define IA32_TME_ACTIVATE_MSR_ADDR                       0x982
#define IA32_MKTME_KEYID_PARTITIONING_MSR_ADDR           0x87

#define IA32_SPEC_CTRL_MSR_ADDR                          0x48
#define IA32_DEBUGCTL_MSR_ADDR                           0x1D9

#define IA32_PRED_CMD_MSR_ADDR                           0x49
#define IA32_SGX_DEBUG_MODE_MSR_ADDR                     0x503
#define IA32_MISC_ENABLE_MSR_ADDR                        0x1A0


#define IA32_INTR_PENDING_MSR_ADDR                       0x9A
#define IA32_WBINVDP_MSR_ADDR                            0x98
#define IA32_CORE_THREAD_COUNT_MSR_ADDR                  0x35

#define IA32_SEAMRR_BASE_AND_MASK_MASK           BITS((MAX_PA-1), 25)

#define IA32_MISC_ENABLE_BOOT_NT4_BIT BIT(22)
#define IA32_S_CET_SH_STK_EN_BIT      BIT(0)
#define IA32_S_CET_ENDBR_EN_BIT       BIT(2)
#define IA32_S_CET_NO_TRACK_EN_BIT    BIT(4)

typedef union
{
    struct
    {
        uint64_t syscall_enabled :1;
        uint64_t reserved_0 :7;
        uint64_t lme :1;
        uint64_t reserved_1 :1;
        uint64_t lma :1;
        uint64_t xde :1;
        uint64_t reserved_2 :52;
    };
    uint64_t raw;
} ia32_efer_t;

#define IA32_EFER_LME_BIT      BIT(8)
#define IA32_EFER_LMA_BIT      BIT(10)
#define IA32_EFER_NXE_BIT      BIT(11)

typedef union {
    struct
    {
        uint64_t
            lbr             : 1, // 0
            btf             : 1, // 1
            reserved_0      : 4, // 2-5
            tr              : 1, // 6
            bts             : 1, // 7
            btint           : 1, // 8
            bts_off_os      : 1, // 9
            bts_off_usr     : 1, // 10
            frz_lbr_pmi     : 1, // 11
            frz_perfmon_pmi : 1, // 12
            en_uncore_pmi   : 1, // 13
            frz_while_smm   : 1, // 14
            rtm_debug       : 1, // 15
            reserved_1      : 48; // 16-63

    };
    uint64_t raw;
} ia32_debugctl_t;
pseamldr_static_assert(sizeof(ia32_debugctl_t) == 8, ia32_debugctl_t);

typedef union
{
    struct
    {
        uint64_t lock                            : 1 , //0
                 tme_enable                      : 1,  //1
                 key_select                      : 1,  //2
                 save_key_for_standby            : 1,  //3
                 tme_policy                      : 4,  //4-7
                 sgx_tem_enable                  : 1,  //8
                 rsvd                            : 22, //9-30
                 tme_enc_bypass_enable           : 1,  //31
                 mk_tme_keyid_bits               : 4,  //32-35
                 tdx_reserved_keyid_bits         : 4,  //36-39
                 rsvd1                           : 8,  //40-47
                 algs_aes_xts_128                : 1,  //48
                 algs_aes_xts_128_with_integrity : 1,  //49
                 algs_aes_xts_256                : 1,  //50
                 algs_aes_xts_256_with_integrity : 1,  //51
                 algs_rsvd                       : 12;
    };
    uint64_t raw;
} ia32_tme_activate_t;
pseamldr_static_assert(sizeof(ia32_tme_activate_t) == 8, ia32_tme_activate_t);

typedef union
{
    struct
    {
        uint64_t aes_xts_128 : 1;
        uint64_t aes_xts_128_with_integrity : 1;
        uint64_t aes_xts_256 : 1;
        uint64_t rsvd : 29;
        uint64_t mk_tme_max_keyid_bits : 4;
        uint64_t mk_tme_max_keys : 15;
        uint64_t nm_encryption_disable : 1;
        uint64_t rsvd2 : 11;
        uint64_t implicit_bit_mask : 1;
    };
    uint64_t raw;
} ia32_tme_capability_t;
pseamldr_static_assert(sizeof(ia32_tme_capability_t) == 8, ia32_tme_capability_t);

typedef union
{
    struct
    {
        uint32_t num_mktme_kids;
        uint32_t num_tdx_priv_kids;
    };
    uint64_t raw;
} ia32_tme_keyid_partitioning_t;
pseamldr_static_assert(sizeof(ia32_tme_keyid_partitioning_t) == 8, ia32_tme_keyid_partitioning_t);

typedef union ia32_seamrr_base_u {
    struct {
        uint64_t
            rsvd0       : 3,                   // [2:0]
            configured  : 1,                   // [3]
            rsvd1       : 21,                  // [24:4]
            base        : ((MAX_PA - 1) - 24), // [MAX_PA-1:25]
            rsvd2       : ((63 - MAX_PA) + 1);   // [63:MAX_PA]
    };

    uint64_t raw;
} ia32_seamrr_base_t;
pseamldr_static_assert(sizeof(ia32_seamrr_base_t) == 8, ia32_seamrr_base_t);

typedef union ia32_seamrr_mask_u {
    struct {
        uint64_t
            rsvd0       : 10,                  // [9:0]
            lock        : 1,                   // [10]
            valid       : 1,                   // [11]
            rsvd1       : 13,                  // [24:12]
            mask        : ((MAX_PA - 1) - 24), // [MAX_PA-1:25]
            rsvd2       : ((63 - MAX_PA) + 1);   // [63:MAX_PA]
    };

    uint64_t raw;
} ia32_seamrr_mask_t;
pseamldr_static_assert(sizeof(ia32_seamrr_mask_t) == 8, ia32_seamrr_mask_t);

typedef union
{
    struct
    {
        uint64_t vmcs_revision_id         : 31;
        uint64_t rsvd0                    : 1;
        uint64_t vmcs_region_size         : 13;
        uint64_t rsvd1                    : 3;
        uint64_t vmxon_pa_width           : 1;   // bits 44:32
        uint64_t dual_monitor             : 1;
        uint64_t vmcs_mt                  : 4;
        uint64_t vmexit_info_on_ios       : 1;
        uint64_t default_1_controls_clear : 1;   // bit 55
        uint64_t rsvd2                    : 8;
    };
    uint64_t raw;
} ia32_vmx_basic_t;
pseamldr_static_assert(sizeof(ia32_vmx_basic_t) == 8, ia32_vmx_basic_t);

typedef union
{
    struct
    {
        uint32_t not_allowed0;
        uint32_t allowed1;
    };
    uint64_t raw;
} ia32_vmx_allowed_bits_t;

typedef union ia32_pred_cmd_u
{
    struct
    {
        uint64_t ibpb     : 1;
        uint64_t reserved : 63;
    };
    uint64_t raw;
} ia32_pred_cmd_t;

typedef union ia32_spec_ctrl_u
{
    struct
    {
        uint64_t ibrs : 1;
        uint64_t stibp : 1;
        uint64_t ssbd : 1;
        uint64_t reserved : 61;
    };
    uint64_t raw;
} ia32_spec_ctrl_t;

typedef union ia32_sgx_debug_mode_u
{
    struct
    {
        uint64_t npk_request        : 1;
        uint64_t debug_unlock_mode  : 1;
        uint64_t rsvd               : 62;
    };
    uint64_t raw;
} ia32_sgx_debug_mode_t;

typedef union ia32_msr_intr_pending_u
{
    struct
    {
        uint64_t intr  : 1;   // Bit 0: INTR is pending
        uint64_t nmi   : 1;   // Bit 1: NMI is pending
        uint64_t smi   : 1;   // Bit 2: SMI is pending
        uint64_t other : 61;  // Bits 63:3: Other events are pending
    };
    uint64_t raw;
} ia32_msr_intr_pending_t;

typedef union ia32_core_thread_count_u
{
    struct
    {
        uint64_t lps_in_package  : 16;
        uint64_t rsvd            : 48;
    };
    uint64_t raw;
} ia32_core_thread_count_t;

#endif /* SRC_COMMON_X86_DEFS_MSR_DEFS_H_ */
