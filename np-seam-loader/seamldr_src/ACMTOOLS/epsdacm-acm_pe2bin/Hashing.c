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

#include <windows.h>
#include <stdio.h>
#include <bcrypt.h>
#include <uchar.h>
#include <openssl/evp.h>
//#include "ACM_pe2binx.H"
#include "Hashing.h"

TPML_DIGEST_VALUES CrtmVersionDigests;
UINT16 SCRTMHashAlgs[5] = { TPM_ALG_SHA, TPM_ALG_SHA256, TPM_ALG_SHA384, TPM_ALG_SHA512, TPM_ALG_SM3 };

const char *hashAlg2Str(UINT16 hashAlg) {
    switch (hashAlg)
    {
        case TPM_ALG_SHA:
            return "sha1";
        case TPM_ALG_SHA256:
            return "sha256";
        case TPM_ALG_SHA384:
            return "sha384";
        case TPM_ALG_SHA512:
            return "sha512";
        case TPM_ALG_SM3:
            return "sm3";
        default:
            return NULL;
    }
}

size_t getHashDigestSize(UINT16 hashAlg) {
    switch (hashAlg)
    {
        case TPM_ALG_SHA:
            return SHA1_DIGEST_SIZE;
        case TPM_ALG_SHA256:
            return SHA256_DIGEST_SIZE;
        case TPM_ALG_SHA384:
            return SHA384_DIGEST_SIZE;
        case TPM_ALG_SHA512:
            return SHA512_DIGEST_SIZE;
        case TPM_ALG_SM3:
            return SM3_256_DIGEST_SIZE;
        default:
            return 0;
    }
}

UINT16 hashAlg2DgstValIndex(UINT16 hashAlg) {
    switch (hashAlg)
    {
    case TPM_ALG_SHA:
        return SHA1_INDEX;
    case TPM_ALG_SHA256:
        return SHA256_INDEX;
    case TPM_ALG_SHA384:
        return SHA384_INDEX;
    case TPM_ALG_SHA512:
        return SHA512_INDEX;
    case TPM_ALG_SM3:
        return SM3_INDEX;
    default:
        return 0xFFFF;
    }
}


boolean HashCrtmVersionData(const BYTE *inBuffer, size_t buffSize, UINT16 hashAlg) {
    EVP_MD_CTX *ctx = NULL;
    const EVP_MD *md = NULL;
    size_t digestLength;
    UINT32 status = 0;
    UINT16 tpmlValuesIndex;

    if (inBuffer == NULL) {
        printf("Error: HashData, input or output buffer not allocated.\n");
        return FALSE;
    }
    
    digestLength = getHashDigestSize(hashAlg);
    if (digestLength == 0) {
        printf("Error: HashData, unsupported hash alg.\n");
        return FALSE;
    }

    tpmlValuesIndex = hashAlg2DgstValIndex(hashAlg);

    ctx = EVP_MD_CTX_create();
    if (ctx == NULL) {
        printf("Error: HashData, hash context not allocated.\n");
        return FALSE;
    }
    md = EVP_get_digestbyname(hashAlg2Str(hashAlg));
    //md = getEvpMd(hashAlg);
    if (md == NULL) {
        printf("Error: failed to set up hashing algorithm\n.");
        return FALSE;
    }

    if (EVP_DigestInit(ctx, md) == 0) {
        printf("Error: failed to initialize hashing context\n.");
        EVP_MD_CTX_destroy(ctx);
        return FALSE;
    }
    if (EVP_DigestUpdate(ctx, (const void *)inBuffer, buffSize) == 0) {
        printf("Error: failed to update hashing function\n.");
        EVP_MD_CTX_destroy(ctx);
        return FALSE;
    }

    CrtmVersionDigests.digests[tpmlValuesIndex].hashAlg = _byteswap_ushort(hashAlg);
    status = EVP_DigestFinal(ctx, (unsigned char *) &CrtmVersionDigests.digests[tpmlValuesIndex].digest, NULL);
    if (status == 0) {
        printf("Error: failed to finalize hashing function\n.");
        EVP_MD_CTX_destroy(ctx);
        return FALSE;
    }
    EVP_MD_CTX_destroy(ctx);
    return TRUE;
}

void printHex(const BYTE *buffer, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (i % 16 == 0) {
            printf("\n");
        }
        printf("%02X ", *(buffer + i));
    }
    printf("\n");
}