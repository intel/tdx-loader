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
 * @file seamldr_info.c
 * @brief SEAMLDR.INFO API handler
 */
#include "../../../include/pseamldr_basic_defs.h"
#include "pseamldr_api_handlers.h"
#include "x86_defs/x86_defs.h"
#include "memory_handlers/keyhole_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"
#include "accessors/ia32_accessors.h"

api_error_type seamldr_info(uint64_t output_buffer_pa)
{
    seamldr_info_t              * out_seamldr_info_la = NULL;
    ALIGN(256) seamextend_t       seamextend;
    api_error_type                return_value = PSEAMLDR_EUNSPECERR;

    //Check SEAMLDR INFO output PA
    return_value = check_and_map_aligned_shared_hpa((pa_t)output_buffer_pa, 256, TDX_RANGE_RW, (void**)&out_seamldr_info_la);
    IF_RARE (return_value != PSEAMLDR_SUCCESS)
    {
        TDX_ERROR("Output PA is not a valid/aligned shared HPA pa=0x%llx\n", output_buffer_pa);
        goto EXIT;
    }

    basic_memset_to_zero(out_seamldr_info_la, sizeof(seamldr_info_t));

    out_seamldr_info_la->version = 0;
#ifdef DEBUG
    out_seamldr_info_la->attributes.is_debug = 1;
#endif
    out_seamldr_info_la->vendor_id  = 0x8086;
    out_seamldr_info_la->build_date = PSEAMLDR_BUILD_DATE;
    out_seamldr_info_la->build_num  = PSEAMLDR_BUILD_NUM;
    out_seamldr_info_la->minor      = PSEAMLDR_MINOR_VER;
    out_seamldr_info_la->major      = PSEAMLDR_MAJOR_VER;
    out_seamldr_info_la->acm_x2apic = get_psysinfo_table()->acm_x2apicid;

    seamextend_read(&seamextend);

    pseamldr_memcpy(&out_seamldr_info_la->seamextend, sizeof(seamextend_t), &seamextend, sizeof(seamextend_t));

    pseamldr_data_t* pseamldr_data = get_pseamldr_data();

    IF_RARE (pseamldr_data->num_remaining_updates == 0)
    {
        pseamldr_data->num_remaining_updates = get_num_of_remaining_updates();
    }

    out_seamldr_info_la->num_remaining_updates = pseamldr_data->num_remaining_updates;

    out_seamldr_info_la->features0.cleanup_supported = 1;

    return_value = PSEAMLDR_SUCCESS;

EXIT:

    IF_COMMON (out_seamldr_info_la != NULL)
    {
        free_la(out_seamldr_info_la);
    }

    return return_value;
}
