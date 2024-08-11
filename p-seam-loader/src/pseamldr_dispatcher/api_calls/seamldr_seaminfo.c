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
 * @brief SEAMLDR.SEAMINFO API handler
 */
#include "../../../include/pseamldr_basic_defs.h"
#include "pseamldr_api_handlers.h"
#include "x86_defs/x86_defs.h"
#include "memory_handlers/keyhole_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"
#include "accessors/ia32_accessors.h"

api_error_type seamldr_seaminfo(uint64_t output_buffer_pa)
{
    uint8_t*           out_seaminfo_la = NULL;
    p_sysinfo_table_t* p_sysinfo_table = get_psysinfo_table();
    api_error_type     return_value = PSEAMLDR_EUNSPECERR;

    //Check SEAMLDR SEAMINFO output PA
    return_value = check_and_map_aligned_shared_hpa((pa_t)output_buffer_pa, _2KB, TDX_RANGE_RW,
                                                    (void**)&out_seaminfo_la);
    IF_RARE (return_value != PSEAMLDR_SUCCESS)
    {
        TDX_ERROR("Output PA is not a valid/aligned shared HPA pa=0x%llx\n", output_buffer_pa);
        goto EXIT;
    }

    pseamldr_memcpy(out_seaminfo_la, _2KB, p_sysinfo_table, _2KB);

    return_value = PSEAMLDR_SUCCESS;

EXIT:

    IF_COMMON (out_seaminfo_la != NULL)
    {
        free_la(out_seaminfo_la);
    }

    return return_value;
}
