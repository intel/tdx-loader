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

#ifndef SRC_COMMON_CRYPTO_INTEL_KEY_HASH_H_
#define SRC_COMMON_CRYPTO_INTEL_KEY_HASH_H_

const unsigned char key_hash_v0[48] =
{
    0xd2, 0x94, 0x22, 0x9c, 0x92, 0xba, 0x64, 0x5e, 0x16, 0xa5, 0x99, 0x8c,
    0x2e, 0x23, 0x1f, 0xd7, 0x39, 0x23, 0x60, 0xd4, 0x0f, 0xd0, 0x27, 0x99,
    0x94, 0xc7, 0x6a, 0xa4, 0x5b, 0x0c, 0x2e, 0x72, 0x88, 0x64, 0xdc, 0x09,
    0xc0, 0x37, 0x82, 0xcd, 0x18, 0x9d, 0x64, 0x51, 0x58, 0x48, 0x7f, 0x88
};

const unsigned char key_hash_v1[48] =
{
    0x8d, 0x56, 0x46, 0xb2, 0x6c, 0xab, 0xd9, 0xe9, 0x91, 0x59, 0x8c, 0x55,
    0xc6, 0xbc, 0x46, 0x60, 0x2f, 0x45, 0x45, 0x35, 0x4a, 0xee, 0xdf, 0x81,
    0xc2, 0x5c, 0x77, 0x8b, 0x6b, 0x8d, 0x6e, 0x64, 0xb4, 0x9a, 0xe3, 0x23,
    0x30, 0x42, 0xa3, 0xc5, 0x65, 0x5b, 0xa6, 0x5f, 0xa4, 0x1a, 0x22, 0x22
};

const unsigned char css_production_key_hash[48] =
{
    0xc8, 0x57, 0x2f, 0x54, 0x88, 0x69, 0xa0, 0xbe, 0xca, 0x19, 0x37, 0x6b,
    0x81, 0xc2, 0xdf, 0xfc, 0x2a, 0x23, 0xb5, 0xa5, 0xf7, 0x1d, 0xa0, 0xb8,
    0x75, 0x79, 0xb4, 0x3f, 0x40, 0x8d, 0xaa, 0x1a, 0x33, 0xba, 0xd9, 0xc1,
    0x49, 0xeb, 0x56, 0xc6, 0x34, 0xf8, 0x83, 0x73, 0x79, 0x68, 0xa3, 0x4c
};

const unsigned char* intel_key_hash = css_production_key_hash;

#endif /* SRC_COMMON_CRYPTO_INTEL_KEY_HASH_H_ */
