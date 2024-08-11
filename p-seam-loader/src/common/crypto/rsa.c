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
 * @file rsa.c
 * @brief Crypto implementation of RSA
 */

#include "helpers/helpers.h"
#include "ippcp.h"
#include "rsa.h"
#include "sha384.h"
#include "accessors/data_accessors.h"
#include "debug/tdx_debug.h"

static void little_to_big_endian_convert(const uint8_t* input, uint8_t* output, uint32_t len)
{
    for (uint32_t i = 0; i < len; i++)
    {
        output[(len - 1) - i] = input[i];
    }
}

#define MAX_BIG_NUMBER_SIZE         SIZE_OF_RSA_SIGNATURE

static IppStatus rsa_set_ipp_big_num(IppsBigNumState* big_num_IPP, const uint8_t* number_ptr, uint32_t size)
{
    IppStatus ret_val;
    uint8_t big_endian_number[MAX_BIG_NUMBER_SIZE];

    if (size > MAX_BIG_NUMBER_SIZE)
    {
        return ippStsErr;
    }

    little_to_big_endian_convert(number_ptr, big_endian_number, size);

    ret_val = ippsSetOctString_BN((const Ipp8u*)big_endian_number, (int)size, big_num_IPP);

    return ret_val;
}

static IppsBigNumState* rsa_init_ipp_big_num_on_buffer(uint8_t** static_buffer, int32_t* static_buffer_size,
                                                       const uint8_t* number_ptr, uint32_t size)
{
    int32_t big_num_ctx_size;
    int32_t big_num_len_in_dwords = size / sizeof(uint32_t);

    // get size
    IppStatus ret_val = ippsBigNumGetSize(big_num_len_in_dwords, &big_num_ctx_size);

    if (ret_val != ippStsNoErr || big_num_ctx_size <= 0 || big_num_ctx_size > *static_buffer_size)
    {
        return NULL;
    }

    IppsBigNumState* big_num_IPP = (IppsBigNumState*)*static_buffer;
    ret_val = ippsBigNumInit(big_num_len_in_dwords, big_num_IPP);
    if (ret_val != ippStsNoErr)
    {
        return NULL;
    }

    ret_val = rsa_set_ipp_big_num(big_num_IPP, number_ptr, size);

    if (ret_val != ippStsNoErr)
    {
        return NULL;
    }

    *static_buffer += (uint32_t)big_num_ctx_size;
    *static_buffer_size -= big_num_ctx_size;

    return big_num_IPP;
}

static IppsRSAPublicKeyState* rsa_init_ipp_pub_key_on_buffer(uint8_t** static_buffer, int32_t* static_buffer_size,
                                                             IppsBigNumState* modulus_IPP, uint32_t modulus_size,
                                                             IppsBigNumState* public_exp_IPP, uint32_t public_exp_size)
{
    int32_t modulus_bitsize    = (int32_t)modulus_size * 8;
    int32_t public_exp_bitsize = (int32_t)public_exp_size * 8;
    int32_t public_key_ctx_size;

    IppStatus ret_val = ippsRSA_GetSizePublicKey(modulus_bitsize, public_exp_bitsize, &public_key_ctx_size);

    if (ret_val != ippStsNoErr || public_key_ctx_size <= 0 || public_key_ctx_size > *static_buffer_size)
    {
        return NULL;
    }

    IppsRSAPublicKeyState* public_key_IPP = (IppsRSAPublicKeyState*)(*static_buffer);
    ret_val = ippsRSA_InitPublicKey(modulus_bitsize, public_exp_bitsize, public_key_IPP, public_key_ctx_size);
    if (ret_val != ippStsNoErr)
    {
        return NULL;
    }

    ret_val = ippsRSA_SetPublicKey(modulus_IPP, public_exp_IPP, public_key_IPP);
    if (ret_val != ippStsNoErr)
    {
        return NULL;
    }

    *static_buffer += (uint32_t)public_key_ctx_size;
    *static_buffer_size -= public_key_ctx_size;

    return public_key_IPP;
}



crypto_api_error rsa_verify_signature(uint8_t* signature, const uint8_t* message,
                                      uint32_t message_len, uint32_t public_exp,
                                      const uint8_t* modulus, bool_t* is_valid)
{
    int32_t pkcs_scratch_buffer_size, method_buffer_size;

    uint8_t* static_buffer = get_pseamldr_data()->rsa_context.buffer;
    int32_t static_buffer_size = SIZE_OF_RSA_CTX_BUFFER;

    IppsBigNumState* public_exp_IPP;
    IppsBigNumState* modulus_IPP;
    IppsRSAPublicKeyState* public_key_IPP;
    IppStatus ret_val = ippStsErr;

    public_exp_IPP = rsa_init_ipp_big_num_on_buffer(&static_buffer, &static_buffer_size,
                                                    (uint8_t*)&public_exp, sizeof(public_exp));
    modulus_IPP = rsa_init_ipp_big_num_on_buffer(&static_buffer, &static_buffer_size,
                                                 modulus, SIZE_OF_RSA_SIGNATURE);

    if ((public_exp_IPP == NULL) || (modulus_IPP == NULL))
    {
        TDX_ERROR("RSA big number initialization failed\n");
        return ippStsErr;
    }

    public_key_IPP = rsa_init_ipp_pub_key_on_buffer(&static_buffer, &static_buffer_size,
                                                    modulus_IPP, SIZE_OF_RSA_SIGNATURE,
                                                    public_exp_IPP, sizeof(public_exp));

    if (public_key_IPP == NULL)
    {
        TDX_ERROR("RSA public key initialization failed\n");
        return ippStsErr;
    }

    ret_val = ippsRSA_GetBufferSizePublicKey(&pkcs_scratch_buffer_size, public_key_IPP);
    if (ret_val != ippStsNoErr || pkcs_scratch_buffer_size <= 0 || pkcs_scratch_buffer_size > static_buffer_size)
    {
        TDX_ERROR("RSA PKCS scratch buffer initialization failed\n");
        return ippStsErr;
    }

    uint8_t signature_big_endian[SIZE_OF_RSA_SIGNATURE];
    little_to_big_endian_convert(signature, signature_big_endian, SIZE_OF_RSA_SIGNATURE);

    uint8_t hash_method_buff[HASH_METHOD_BUFFER_SIZE];

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

    int valid = 0;

    ret_val = ippsRSAVerify_PKCS1v15_rmf(message, (int)message_len, signature_big_endian,
                                     &valid, public_key_IPP, hash_method_ptr, static_buffer);

    if (ret_val != ippStsNoErr)
    {
        TDX_ERROR("RSA RKCS verification failed - %d\n", ret_val);
        return ret_val;
    }

    *is_valid = (valid == 0) ? false : true;

    return ippStsNoErr;
}

