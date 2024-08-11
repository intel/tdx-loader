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
 * @file sha384.c
 * @brief Crypto implementation of SHA384
 */
#include "crypto/sha384.h"
#include "helpers/helpers.h"
#include "ippcp.h"

crypto_api_error sha384_generate_hash(const uint8_t * block,
                                      uint32_t block_size,
                                      uint64_t * hash)
{
    int32_t method_buffer_size;
    uint8_t hash_method_buff[HASH_METHOD_BUFFER_SIZE];
    IppStatus ret_val = ippStsErr;

    ret_val = ippsHashMethodGetSize(&method_buffer_size);

    if (ret_val != ippStsNoErr || method_buffer_size > (int32_t)sizeof(hash_method_buff))
    {
        TDX_ERROR("Required method buffer size is %d\n", method_buffer_size);
        return ippStsErr;
    }

    IppsHashMethod* hash_method_ptr = (IppsHashMethod*)hash_method_buff;
    ret_val = ippsHashMethodSet_SHA384(hash_method_ptr);
    if (ret_val != ippStsNoErr)
    {
        TDX_ERROR("SHA384 Method setting failed\n");
        return ippStsErr;
    }

    return ippsHashMessage_rmf(block, (int)block_size, (Ipp8u*)hash, hash_method_ptr);
}

