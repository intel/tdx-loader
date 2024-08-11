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
 * @file sha384.h
 * @brief Crypto API for SHA384 Hash
 */
#ifndef __SHA384_H_INCLUDED__
#define __SHA384_H_INCLUDED__

#include "../../../include/pseamldr_basic_defs.h"
#include "../../../include/pseamldr_basic_types.h"

typedef int32_t crypto_api_error;
#define SIZE_OF_SHA384_BLOCK_IN_QWORD 16
#define SIZE_OF_SHA384_BLOCK_IN_DWORD (SIZE_OF_SHA384_BLOCK_IN_QWORD<<1)
#define SIZE_OF_SHA384_BLOCK_IN_BYTES (SIZE_OF_SHA384_BLOCK_IN_DWORD<<2)
#define SIZE_OF_SHA384_STATE_IN_QWORD 8
#define SIZE_OF_SHA384_STATE_IN_DWORD (SIZE_OF_SHA384_STATE_IN_QWORD<<1)
#define SIZE_OF_SHA384_STATE_IN_BYTES (SIZE_OF_SHA384_STATE_IN_DWORD<<2)
#define SIZE_OF_SHA384_HASH_IN_QWORDS 6
#define SIZE_OF_SHA384_HASH_IN_BYTES (SIZE_OF_SHA384_HASH_IN_QWORDS << 3)

#define HASH_METHOD_BUFFER_SIZE  128

/**
 * @brief Non-incremental SHA-384 hash for a block smaller than 128 bytes
 *
 * @note
 *
 * @param block Pointer to block
 * @param block_size Size of block in bytes
 * @param hash Result of SHA384 hash
 *
 * @return Success or Error type
 */
crypto_api_error sha384_generate_hash(const uint8_t * block,
                                      uint32_t block_size,
                                      uint64_t * hash);


#endif // __SHA384_H_INCLUDED__
