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
 * @file seamldr_cleanup.c
 * @brief SEAMLDR.CLEANUP API handler
 */
#include "../../../include/pseamldr_basic_defs.h"
#include "pseamldr_api_handlers.h"
#include "x86_defs/x86_defs.h"
#include "memory_handlers/keyhole_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"
#include "accessors/ia32_accessors.h"

static uint64_t calculate_handoff_data_la()
{
    pseamldr_data_t             * pseamldr_data = get_pseamldr_data();
    p_sysinfo_table_t           * p_sysinfo_table = get_psysinfo_table();

    // Set C_NUM_ADDR_LP = num_addr_lp_per_skt * P_SYS_INFO_TABLE.TOT_NUM_SOCKETS
    uint64_t num_addressable_lps = get_num_addressable_lps_on_socket() * p_sysinfo_table->tot_num_sockets;

    uint64_t vmcs_region_size = _4KB * num_addressable_lps;

    uint64_t data_region_physbase = pseamldr_data->system_info.seamrr_base +
                                       _4KB + vmcs_region_size; // Physical SYSINFO table and VMCS's

    return p_sysinfo_table->module_region_base +
                  (data_region_physbase - pseamldr_data->system_info.seamrr_base);
}

api_error_type seamldr_cleanup(void)
{
    pseamldr_data_t             * pseamldr_data = get_pseamldr_data();
    p_sysinfo_table_t           * p_sysinfo_table = get_psysinfo_table();

    uint32_t                      lpid;
    uint32_t                      pkgid;
    uint32_t                      domainid;

    api_error_type                return_value = PSEAMLDR_EUNSPECERR;

    lpid = get_current_lpid();

    // If X2APICID = CPUID.1FH.0:EDX >= MIN_LP_BITMAP_SIZE, then fatal error
    IF_RARE (lpid >= MAX_NUM_OF_LPS)
    {
        TDX_ERROR("Incorrect LPID=%d, bigger than defined max num of LP's=%d\n", lpid, MAX_NUM_OF_LPS);
        return_value = PSEAMLDR_EUNSPECERR;
        goto EXIT;
    }

    // Return EBADCALL if CURRENT_FLOW is not CLEANUP or READY
    IF_RARE ((pseamldr_data->current_flow != PSEAMLDR_STATE_READY) &&
             (pseamldr_data->current_flow != PSEAMLDR_STATE_CLEANUP))
    {
        TDX_ERROR("Incorrect current flow - %d, not READY or CLEANUP\n", pseamldr_data->current_flow);
        return_value = PSEAMLDR_EBADCALL;
        goto EXIT;
    }

    // Return EBADCALL if CLEANUP_BITMAP[i]!=0 (API already finished on this thread in this session)
    IF_RARE (bit_test(pseamldr_data->cleanup_bitmap, lpid))
    {
        TDX_ERROR("API already finished on this thread in this session\n");
        return_value = PSEAMLDR_EBADCALL;
        goto EXIT;
    }

    IF_RARE (!pseamldr_data->init_done)
    {
        TDX_ERROR("Init not done before cleanup\n");
        return_value = PSEAMLDR_EBADCALL;
        goto EXIT;
    }

    // Let p = package of LP i
    pkgid = get_current_pkgid();

    IF_RARE (pkgid >= MAX_PKGS)
    {
        TDX_ERROR("Incorrect PKGID=%d, bigger than defined max num of LP's=%d\n", pkgid, MAX_PKGS);
        return_value = PSEAMLDR_EUNSPECERR;
        goto EXIT;
    }

    // Let d = Cache domain number for thread i
    domainid = get_current_domainid();

    IF_RARE (domainid >= MAX_NUM_OF_WBINVD_DOMAINS)
    {
        TDX_ERROR("Incorrect Domain ID=%d, bigger than defined max num of LP's=%d\n", domainid, MAX_NUM_OF_WBINVD_DOMAINS);
        return_value = PSEAMLDR_EUNSPECERR;
        goto EXIT;
    }

    // On first LP: (Detected when CURRENT_FLOW == READY)
    IF_RARE (pseamldr_data->current_flow == PSEAMLDR_STATE_READY)
    {
        // Set CURRENT_FLOW to CLEANUP
        pseamldr_data->current_flow = PSEAMLDR_STATE_CLEANUP;

        // Clear SEAM_READY flag of SEAMEXTEND - this blocks further access to TDX Module
        seamextend_read(&pseamldr_data->seamextend_snapshot);
        pseamldr_data->seamextend_snapshot.seam_ready = 0;
        basic_memset_to_zero(&pseamldr_data->seamextend_snapshot.tee_tcb_svn, sizeof(tee_tcb_svn_t));
        seamextend_write(&pseamldr_data->seamextend_snapshot);

        // Turn off "valid" bit in handoff_data
        handoff_data_header_t* handoff_data = (handoff_data_header_t*)calculate_handoff_data_la();
        handoff_data->valid = 0;
    }

    // If (CLEANUP_LPs_PER_PACKAGE[p]+1 == MAX_PACKAGE_LPs[p]) and (KEY_DIRTY[p]!= 0):
    // i.e we're going be the last thread on this package, and there IS work to be done
    IF_RARE ((pseamldr_data->cleanup_lps_per_package[pkgid] + 1 == pseamldr_data->max_pkg_lps[pkgid]) &&
              pseamldr_data->key_dirty[pkgid])
    {
        uint32_t keyid = pseamldr_data->next_kid_to_config[pkgid];

        while (keyid < pseamldr_data->system_info.num_tdx_hkids)
        {
            return_value = program_mktme_keys((uint16_t)(pseamldr_data->system_info.private_hkid_min + keyid));
            IF_RARE (return_value != PSEAMLDR_SUCCESS)
            {
                TDX_ERROR("PCONFIG failure = 0x%llx\n", return_value);
                goto EXIT;
            }

            keyid++;

            pseamldr_data->next_kid_to_config[pkgid] = keyid;

            // If an interrupt is pending (check using RDMSR from INTR_PENDING)
            if (is_interrupt_pending_host_side())
            {
                // the VMM should call this API again
                return_value = PSEAMLDR_EINTERRUPT;
                goto EXIT;
            }
        }

        pseamldr_data->key_dirty[pkgid] = false;
    }

    // If (CLEANUP_LPs_PER_DOMAIN[d]+1) and (CACHE_DIRTY[d]!= 0):
    // i.e we're going be the last thread on this domain, and there IS work to be done
    IF_RARE ((pseamldr_data->cleanup_lps_per_domain[domainid] + 1 == pseamldr_data->max_domain_lps[domainid]) &&
              pseamldr_data->cache_dirty[domainid])
    {
        uint32_t block = pseamldr_data->next_block_to_flush[domainid];
        uint64_t max_cache_sub_blocks = ia32_rdmsr(IA32_WBINVDP_MSR_ADDR);

        while (block < max_cache_sub_blocks)
        {
            ia32_wrmsr(IA32_WBINVDP_MSR_ADDR, block);

            block++;

            pseamldr_data->next_block_to_flush[domainid] = block;

            // If an interrupt is pending (check using RDMSR from INTR_PENDING)
            if (is_interrupt_pending_host_side())
            {
                // the VMM should call this API again
                return_value = PSEAMLDR_EINTERRUPT;
                goto EXIT;
            }
        }

        pseamldr_data->cache_dirty[domainid] = false;
    }

#if 0
    // On SoCs that store SVNs in S3M/ESE :
        // if  (CLEANUP_LPs_PER_PACKAGE[p] +1== MAX_PACKAGE_LPs[p]) and (SVN_DIRTY[p]!=0):
        // i.e we’re gonna be the last thread on this package, and there IS work to be done
            // Run SEAMOPS[SEAMLDRUPDATESVNMAC] to update the zeroed SVN from the SEAMEXTEND buffer into the ESE/S3M
            // Set SVN_DIRTY[p]=0
#endif

    pseamldr_data->cleanup_lps_per_package[pkgid]++;
    pseamldr_data->cleanup_lps_per_domain[domainid]++;

    // Set bit i of CLEANUP_BITMAP
    (void)bit_test_and_set(pseamldr_data->cleanup_bitmap, lpid);
    pseamldr_data->lps_in_cleanup++;

    // On last thread
    IF_RARE (pseamldr_data->lps_in_cleanup >= p_sysinfo_table->tot_num_lps)
    {
        // Zero first 128B of SEAMEXTEND
        basic_memset_to_zero(&pseamldr_data->seamextend_snapshot, 128);
        seamextend_write(&pseamldr_data->seamextend_snapshot);

        // Clear SEAMDB
        ia32_seamops_seamdb_clear();
        pseamldr_data->num_remaining_updates = get_num_of_remaining_updates();

        // Zero CLEANUP_LPs_PER_PACKAGE
        basic_memset_to_zero(&pseamldr_data->cleanup_lps_per_package, sizeof(pseamldr_data->cleanup_lps_per_package));
        // Zero CLEANUP_LPs_PER_DOMAIN
        basic_memset_to_zero(&pseamldr_data->cleanup_lps_per_domain, sizeof(pseamldr_data->cleanup_lps_per_domain));
        // Zero CLEANUP_BITMAP
        basic_memset_to_zero(&pseamldr_data->cleanup_bitmap, sizeof(pseamldr_data->cleanup_bitmap));
        pseamldr_data->lps_in_cleanup = 0;

        // Set CURRENT_FLOW to READY
        pseamldr_data->current_flow = PSEAMLDR_STATE_READY;
    }

    // Return SUCCESS
    return_value = PSEAMLDR_SUCCESS;

EXIT:

    return return_value;
}
