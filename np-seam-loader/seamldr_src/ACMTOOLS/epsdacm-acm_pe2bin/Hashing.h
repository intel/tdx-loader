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
/*****************************************************************************
 **
 **   Copyright (C) 2015-2021 Intel Corporation. All rights reserved.
 **
 **  The information and source code contained herein is the exclusive
 **  property of Intel Corporation and may not be disclosed, examined
 **  or reproduced in whole or in part without explicit written authorization
 **  from the company.
 **
 ******************************************************************************/
 /*****************************************************************************
  *  Filename:   Hashing.h                                                    *
  *****************************************************************************/


  // TPM_ALG_ID values
#define TPM_ALG_RSA    0x1
#define TPM_ALG_SHA    0x4
#define TPM_ALG_SHA256 0xB
#define TPM_ALG_SHA384 0xC
#define TPM_ALG_SHA512 0xD
#define TPM_ALG_SM3    0x12
#define TPM_ALG_SM4    0x13
#define TPM_ALG_RSASSA 0x14
#define TPM_ALG_RSAPSS 0x16
#define TPM_ALG_ECDSA  0x18
#define TPM_ALG_SM2    0x1B


#define MAX_HASH_COUNT       5
#define SHA1_DIGEST_SIZE     20
#define SHA256_DIGEST_SIZE   32
#define SM3_256_DIGEST_SIZE  32
#define SHA384_DIGEST_SIZE   48
#define SHA512_DIGEST_SIZE   64

//Max size of the TPML_DIGEST_VALUES:
//count = sizeof(UINT32) + (MAX_HASH_COUNT * sizeof(UINT16) + size of all digests above)
#define TPML_DIGEST_VALUES_MAX_SIZE 210
#define SIZE_OF_COM_DATA 230

typedef union TPMU_HA {
    BYTE    sha1[SHA1_DIGEST_SIZE];
    BYTE    sha256[SHA256_DIGEST_SIZE];
    BYTE    sm3_256[SM3_256_DIGEST_SIZE];
    BYTE    sha384[SHA384_DIGEST_SIZE];
    BYTE    sha512[SHA512_DIGEST_SIZE];
} TPMU_HA;

typedef struct TPMT_HA {
    UINT16  hashAlg;
    TPMU_HA digest;
} TPMT_HA;

typedef struct TPML_DIGEST_VALUES {
    UINT32   count;
    TPMT_HA  digests[MAX_HASH_COUNT];
} TPML_DIGEST_VALUES;

enum TPML_DIGEST_INDEX {
    SHA1_INDEX,
    SHA256_INDEX,
    SHA384_INDEX,
    SHA512_INDEX,
    SM3_INDEX
};

extern TPML_DIGEST_VALUES CrtmVersionDigests;
extern UINT16 SCRTMHashAlgs[5];

boolean HashCrtmVersionData(const BYTE *inBuffer, size_t buffSize, UINT16 hashAlg);
size_t getHashDigestSize(UINT16 hashAlg);
void printHex(const BYTE *buffer, size_t length);