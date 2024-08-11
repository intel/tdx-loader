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
 * @file rsa.h
 * @brief Crypto API for RSA verification
 */

#ifndef SRC_COMMON_CRYPTO_RSA_H_
#define SRC_COMMON_CRYPTO_RSA_H_

#include "../../../include/pseamldr_basic_defs.h"
#include "../../../include/pseamldr_basic_types.h"
#include "sha384.h"

#define SIZE_OF_RSA_SIGNATURE      384
#define SIZE_OF_RSA_CTX_BUFFER     0x2000

/**
 * @struct rsa_ctx_t
 *
 * @brief Context of an RSA process.
 */
typedef struct rsa_ctx_s
{
    uint8_t buffer[SIZE_OF_RSA_CTX_BUFFER];
} rsa_ctx_t;

crypto_api_error rsa_verify_signature(uint8_t* signature, const uint8_t* message,
                                      uint32_t message_len, uint32_t public_exp,
                                      const uint8_t* modulus, bool_t* is_valid);

#endif /* SRC_COMMON_CRYPTO_RSA_H_ */
