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

#ifndef KEYSIGNCOM_H
#define KEYSIGNCOM_H

//
// THe following VAR_SIZE definition is explicitly phony. It is used
// simply to make respecive array addressible if structures are nested
// and have more than one array.
//

#define VAR_SIZE 0xCC

//
// boot guard structure defs specifically for crypto code
//
#define RSA_KEY_SIZE_1K             1024
#define RSA_KEY_SIZE_2K             2048
#define RSA_KEY_SIZE_3K             3072

#define ECC_KEY_SIZE_256            256
#define ECC_KEY_SIZE_384            384

#define MAX_RSA_KEY_BYTES           384
#define MAX_ECC_KEY_BYTES           48
#define RSA_DEFAULT_PUBLIC_EXPONENT 0x00010001

//
// RSA Public Key structure
//
typedef struct {
  UINT8  version;                    // must be RSA_PUBLIC_KEY_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size;                   // Number of bits in the modulus.
  UINT32 exponent;                   // The public exponent (must be RSA_KEY_EXPONENT_VALUE)
  UINT8  modulus[MAX_RSA_KEY_BYTES]; // The modulus in LSB format (384 bytes)
} rsa_public_key_t;

typedef struct {
  UINT8  version;                      // must be RSA_PUBLIC_KEY_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size;                     // Number of bits in the modulus.
  UINT32 exponent;                     // The public exponent (must be RSA_KEY_EXPONENT_VALUE)
  UINT8  modulus[RSA_KEY_SIZE_2K / 8]; // The modulus in LSB format (256 bytes)
} rsa2k_pubkey_t;

typedef struct {
  UINT8  version;                      // must be RSA_PUBLIC_KEY_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size;                     // Number of bits in the modulus.
  UINT32 exponent;                     // The public exponent (must be RSA_KEY_EXPONENT_VALUE)
  UINT8  modulus[RSA_KEY_SIZE_3K / 8]; // The modulus in LSB format (256 bytes)
} rsa3k_pubkey_t;

typedef struct {
  UINT8  version;   // must be RSA_PUBLIC_KEY_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size;  // Number of bits in the modulus.
  UINT32 exponent;  // The public exponent (must be RSA_KEY_EXPONENT_VALUE)
  UINT8  modulus[]; // The modulus in LSB format (256 bytes)
} rsa_pubkey_t;

//
// RSA SSA signature structure
// RSASSASig Structure
//
typedef    struct {
  UINT8  version;                      // must be RSA_SSA_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size;                     // Number of bits in the signature
  UINT16 hash_alg;                     // Hash algorithm used for signature
  UINT8  signature[MAX_RSA_KEY_BYTES]; // PKCS #1 v 1.5 signature (384 bytes)
} rsa_ssa_signature_t;

//
// RSA SSA signature structure
// RSASSASig Structure
//
typedef struct {
  UINT8  version;                        // must be RSA_SSA_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size;                       // Number of bits in the signature
  UINT16 hash_alg;                       // Hash algorithm used for signature
  UINT8  signature[RSA_KEY_SIZE_2K / 8]; // PKCS #1 v 1.5 signature (256 bytes)
} rsa2k_sign_t;

typedef struct {
  UINT8  version;                        // must be RSA_SSA_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size;                       // Number of bits in the signature
  UINT16 hash_alg;                       // Hash algorithm used for signature
  UINT8  signature[RSA_KEY_SIZE_3K / 8]; // PKCS #1 v 1.5 signature (256 bytes)
} rsa3k_sign_t;

typedef struct {
  UINT8  version;  // must be RSA_SSA_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size; // Number of bits in the signature
  UINT16 hash_alg; // Hash algorithm used for signature
}sign_hdr_t;

typedef struct {
  UINT8  version;    // must be RSA_SSA_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size;   // Number of bits in the signature
  UINT16 hash_alg;   // Hash algorithm used for signature
  UINT8  sig_data[]; // PKCS #1 v 1.5 signature (256 bytes)
} rsa_sign_t;

//
// RSA Key signature structure
//
typedef struct {
  UINT8               version;    // KEY_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16              key_alg;    // ALG_RSA.
  rsa_public_key_t    key;        // RSAPublicKey
  UINT16              sig_scheme; // ALG_RSASSA.
  rsa_ssa_signature_t signature;  // RSASSA Sig
} rsa_key_signature_t;

typedef struct {
  UINT8          version;    // KEY_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16         key_alg;    // ALG_RSA.
  rsa2k_pubkey_t key;        // RSAPublicKey
  UINT16         sig_scheme; // ALG_RSASSA.
  rsa2k_sign_t   signature;  // RSASSA Sig
} rsa2k_keysign_t;

typedef struct {
  UINT8          version;    // KEY_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16         key_alg;    // ALG_RSA.
  rsa3k_pubkey_t key;        // RSAPublicKey
  UINT16         sig_scheme; // ALG_RSASSA.
  rsa3k_sign_t   signature;  // RSASSA Sig
} rsa3k_keysign_t;

typedef struct {
  UINT8        version; // KEY_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16       key_alg; // ALG_RSA.
  rsa_pubkey_t key;     // RSAPublicKey
  // UINT16             sig_scheme;     // ALG_RSASSA.
  // rsa_sign_t         signature;      // RSASSA Sig
} rsa_keysign_t;

//
// ECDSA Structure Defs below
// ECDSA Public Key structure
//
typedef struct {
  UINT8  version;  // must be ECDSA_PUBLIC_KEY_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size; // Number of bits in the key (qX + qY)
  UINT16 ordinal_size;
  UINT16 curve_id;
  // UINT8   qX[];                      // The public key x component
  // UINT8   qY[];                      // The public key y component
} ecdsa_public_key_t;

//
// ECDSA signature structure
//
typedef struct {
  UINT8  version;  // must be ECDSA_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size; // Number of bits in the signature (qR + qS)
  UINT16 hash_alg;
  // UINT8   qR[];                      // ECDSA signature r component
  // UINT8   qS[];                      // ECDSA signature s component
} ecdsa_signature_t;

//
// ECDSA Key signature structure
//
typedef struct {
  UINT8              version;    // KEY_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16             key_alg;    // ALG_ECC.
  ecdsa_public_key_t key;        // ECDSA PublicKey
  UINT16             sig_scheme; // ALG_ECDSA.
  ecdsa_signature_t  signature;  // ECDSA Sig
} ecdsa_key_signature_t;

//
// SM2 key signature structure
//
typedef struct {
  UINT8  version;  // must be RSA_PUBLIC_KEY_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size; // 256 - Number of bits in key. Fixed for SM2
  UINT8  Qx[32];   // X component. Fixed size for SM2
  UINT8  Qy[32];   // Y component. Fixed size for SM2
} ecc_pubkey_t;

typedef struct {
  UINT8  version;  // must be RSA_SSA_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_size; // Number of bits in the signature
  UINT16 hash_alg; // SM3 for SM2 signature
  UINT8  r[32];    // r component. Fixed size for SM2
  UINT8  s[32];    // s component. Fixed size for SM2
} ecc_sign_t;

typedef struct {
  UINT8        version;    // KEY_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16       key_alg;    // ALG_ECC.
  ecc_pubkey_t key;        // ECCPublicKey
  UINT16       sig_scheme; // ALG_SM2.
  ecc_sign_t   signature;  // ECC Sig
} ecc_keysign_t;

typedef struct {
  UINT8  version;        // KEY_SIGNATURE_STRUCT_VERSION_1_0 = 0x10
  UINT16 key_alg;        // TPM_ALG_RSA = 0x1 or TPM_ALG_ECC = 0x23
  union {
    rsa_pubkey_t rsakey; // RSAPublicKey
    ecc_pubkey_t ecckey; // ECCPublicKey
  } key;
  // UINT16             sig_scheme;      // ALG_RSASSA or RSAPSS or ECDSA
  // union {
  //   rsa_sign_t       signature;       // RSASSA Sig
  //   ecc_sign_t       signature;       // ECDSA Sig
  // }
} keysign_t;

typedef struct _LCP_SIGNATURE {
  UINT16 RevocationCounter;
  UINT16 PubkeySize;
  UINT8  PubkeyValue[VAR_SIZE]; // UINT8   PubkeyValue[PubkeySize]
  //UINT8   sigBlock[PubkeySize]
} LCP_SIGNATURE;

typedef struct {
  UINT16 RevocationCounter;
  UINT16 PubkeySize;
  UINT32 Reserved; // For future expansion
  UINT8  Qx[];     // x coordinate Public key
  // UINT8   Qy[PubkeySize];            // y coordinate Public key
  // UINT8   r[PubkeySize];             // r component of Signature
  // UINT8   s[PubkeySize];             // s component of Signature
} LCP_ECC_SIGNATURE;

#define LCP_RSA_SIGNATURE LCP_SIGNATURE

typedef union {
  LCP_RSA_SIGNATURE RsaSignature;
  LCP_ECC_SIGNATURE EccSignature;
} LCP_SIGNATURE2;

typedef struct {
  UINT16    RevocationCounter;
  keysign_t KeySignature;
} LCP_SIGNATURE2_1;

#endif
