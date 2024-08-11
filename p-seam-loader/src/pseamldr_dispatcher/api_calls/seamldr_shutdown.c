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
 * @file seamldr_shutdown.c
 * @brief SEAMLDR.SHUTDOWN API handler
 */
#include "pseamldr_basic_defs.h"
#include "pseamldr_api_handlers.h"
#include "x86_defs/x86_defs.h"
#include "memory_handlers/keyhole_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"
#include "accessors/ia32_accessors.h"

api_error_type seamldr_shutdown(void)
{
    pseamldr_data_t             * pseamldr_data = get_pseamldr_data();
    p_sysinfo_table_t           * p_sysinfo_table = get_psysinfo_table();
    uint32_t                      lpid;
    api_error_type                return_value = PSEAMLDR_EUNSPECERR;

    lpid = get_current_lpid();

    // If X2APICID = CPUID.1FH.0:EDX >= MIN_LP_BITMAP_SIZE, then fatal error
    IF_RARE (lpid >= MAX_NUM_OF_LPS)
    {
        TDX_ERROR("Incorrect LPID=%d, bigger than defined max num of LP's=%d\n", lpid, MAX_NUM_OF_LPS);
        return_value = PSEAMLDR_EUNSPECERR;
        goto EXIT;
    }

    // Return EBADCALL if CURRENT_FLOW is not SHUTDOWN or READY
    IF_RARE ((pseamldr_data->current_flow != PSEAMLDR_STATE_SHUTDOWN) &&
             (pseamldr_data->current_flow != PSEAMLDR_STATE_READY))
    {
        TDX_ERROR("Incorrect current flow - %d, not SHUTDOWN or READY\n", pseamldr_data->current_flow);
        return_value = PSEAMLDR_EBADCALL;
        goto EXIT;
    }

    // Return ECLEANUPREQ if either KEY_DIRTY or CACHE_DIRTY are not all 0’s
    for (uint32_t i = 0; i < MAX_PKGS; i++)
    {
        IF_RARE (pseamldr_data->key_dirty[i])
        {
            TDX_ERROR("Cleanup required, dirty key on package %d\n", i);
            return_value = PSEAMLDR_ECLEANUPREQ;
            goto EXIT;
        }
    }

    for (uint32_t i = 0; i < MAX_NUM_OF_WBINVD_DOMAINS; i++)
    {
        IF_RARE (pseamldr_data->cache_dirty[i])
        {
            TDX_ERROR("Cleanup required, dirty cache on domain %d\n", i);
            return_value = PSEAMLDR_ECLEANUPREQ;
            goto EXIT;
        }
    }

    // Mark this LP as invoked in the current update session (i.e. set SHUTDOWN_BITMAP[X2APICID] = 1).
    IF_COMMON (bit_test_and_set(pseamldr_data->shutdown_bitmap, lpid) == 0)
    {
        pseamldr_data->lps_in_shutdown++;
    }

    // If this is the first LP on which this API is invoked (i.e. bitcount(SHUTDOWN_BITMAP) == 1),
    // then clear the SEAM_READY field in the SEAMEXTEND register (using IA32_SEAMEXTEND copy-out and copy-in commands).
    // This blocks further SEAMCALLs to the SEAM module.
    IF_RARE (pseamldr_data->lps_in_shutdown == 1)
    {
        seamextend_read(&pseamldr_data->seamextend_snapshot);
        pseamldr_data->seamextend_snapshot.seam_ready = 0;
        seamextend_write(&pseamldr_data->seamextend_snapshot);

        pseamldr_data->current_flow = PSEAMLDR_STATE_SHUTDOWN;
    }

    // If this is not the last LP on which this API is invoked then set RAX = 0 and return.
    IF_COMMON (pseamldr_data->lps_in_shutdown < p_sysinfo_table->tot_num_lps)
    {
        return_value = PSEAMLDR_SUCCESS;
        goto EXIT;
    }

    // The following steps apply only to the “last” LP:

    // If this LP is not the LP on which NP-SEAMLDR ACM was launched
    // (i.e. P_SYS_INFO_TABLE.LAST_SHUTDOWN_X2APICID != X2APICID), then set RAX = EBADCALL and return.
    IF_RARE (lpid != p_sysinfo_table->acm_x2apicid)
    {
        TDX_ERROR("LPID=%d Is different than last shutdown LPID=%d\n", lpid, p_sysinfo_table->acm_x2apicid);
        return_value = PSEAMLDR_EBADCALL;
        goto EXIT;
    }

    // Clear the SEAMEXTEND register (using IA32_SEAMEXTEND copy-in command). This blocks further SEAMCALLs to P-SEAMLDR.
    basic_memset_to_zero(&pseamldr_data->seamextend_snapshot, sizeof(seamextend_t));
    seamextend_write(&pseamldr_data->seamextend_snapshot);

    return_value = PSEAMLDR_SUCCESS;

EXIT:

    return return_value;
}
