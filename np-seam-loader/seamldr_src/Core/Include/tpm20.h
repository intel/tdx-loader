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

#ifndef TPM20_H
#define TPM20_H
#pragma pack (1)

typedef unsigned char BYTE;
typedef unsigned char uint8_t;
typedef char int8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;

typedef struct {
  UINT16 size;
  BYTE   buffer[1];
} TPM2B;

#define IMPLEMENTATION_PCR 24
#define PCR_SELECT_MIN     ((PLATFORM_PCR + 7) / 8)
#define PCR_SELECT_MAX     ((IMPLEMENTATION_PCR + 7) / 8)
#define MAX_DIGEST_BUFFER  1024
#define MAX_NV_BUFFER_SIZE 1024

typedef  UINT16 TPM_ALG_ID;
#define TPM_ALG_ERROR       (TPM_ALG_ID)(0x0000)
#define TPM_ALG_RSA         (TPM_ALG_ID)(0x0001)
#define TPM_ALG_SHA         (TPM_ALG_ID)(0x0004)
#define TPM_ALG_SHA1        (TPM_ALG_ID)(0x0004)
#define TPM_ALG_SHA256      (TPM_ALG_ID)(0x000B)
#define TPM_ALG_SHA384      (TPM_ALG_ID)(0x000C)
#define TPM_ALG_SHA512      (TPM_ALG_ID)(0x000D)
#define TPM_ALG_NULL        (TPM_ALG_ID)(0x0010)
#define TPM_ALG_SM3_256     (TPM_ALG_ID)(0x0012)
#define TPM_ALG_ECDSA       (TPM_ALG_ID)(0x0018)
#define TPM_ALG_RSASSA      (TPM_ALG_ID)(0x0014)
#define TPM_ALG_SM2         (TPM_ALG_ID)(0x001B)
#define TPM_ALG_ECC         (TPM_ALG_ID)(0x0023)
#define TPM_ALG_FIRST       (TPM_ALG_ID)(0x0001)
#define TPM_ALG_LAST        (TPM_ALG_ID)(0x0044)

#define SHA1_DIGEST_SIZE    20
#define SHA256_DIGEST_SIZE  32
#define SHA384_DIGEST_SIZE  48
#define SHA512_DIGEST_SIZE  64
#define SM3_256_DIGEST_SIZE 32

typedef  UINT32 TPM_CC;

#define TPM_CC_NV_UndefineSpaceSpecial (TPM_CC)(0x0000011f)
#define TPM_CC_HierarchyControl        (TPM_CC)(0x00000121)
#define TPM_CC_NV_Write                (TPM_CC)(0x00000137)
#define TPM_CC_PCR_Event               (TPM_CC)(0x0000013c)
#define TPM_CC_SequenceComplete        (TPM_CC)(0x0000013e)
#define TPM_CC_NV_Read                 (TPM_CC)(0x0000014e)
#define TPM_CC_Startup                 (TPM_CC)(0x00000144)
#define TPM_CC_Shutdown                (TPM_CC)(0x00000145)
#define TPM_CC_SequenceUpdate          (TPM_CC)(0x0000015c)
#define TPM_CC_FlushContext            (TPM_CC)(0x00000165)
#define TPM_CC_NV_ReadPublic           (TPM_CC)(0x00000169)
#define TPM_CC_PolicyCommandCode       (TPM_CC)(0x0000016c)
#define TPM_CC_PolicyLocality          (TPM_CC)(0x0000016f)
#define TPM_CC_PolicyOR                (TPM_CC)(0x00000171)
#define TPM_CC_StartAuthSession        (TPM_CC)(0x00000176)
#define TPM_CC_GetCapability           (TPM_CC)(0x0000017a)
#define TPM_CC_PCR_Read                (TPM_CC)(0x0000017e)
#define TPM_CC_PolicyPCR               (TPM_CC)(0x0000017f)
#define TPM_CC_PCR_Extend              (TPM_CC)(0x00000182)
#define TPM_CC_EventSequenceComplete   (TPM_CC)(0x00000185)
#define TPM_CC_HashSequenceStart       (TPM_CC)(0x00000186)

#define TPM20_HASH_COUNT               5

#define TPM2B_TYPE(name, bytes)         \
  typedef union {           \
    struct  {             \
      UINT16 size;           \
      BYTE   buffer[(bytes)];          \
    } t;                \
    TPM2B b;              \
  } TPM2B_ ## name

typedef UINT32 TPM_ALGORITHM_ID;
typedef UINT32 TPM_PARAMETER_SIZE;
typedef UINT16 TPM_KEY_SIZE;
typedef UINT16 TPM_KEY_BITS;

#define RC_VER1                 (0x100)
#define TPM_RC_COMMAND_CODE     (RC_VER1 + 0x043)
#define TPM_RC_NV_UNINITIALIZED (RC_VER1 + 0x04A)
#define RC_FMT1                 (0x080)
#define TPM_RC_HANDLE           (RC_FMT1 + 0x00B)

typedef UINT16 TPM_ST;

#define TPM_ST_NO_SESSIONS (0x8001)
#define TPM_ST_SESSIONS    (0x8002)

typedef UINT16 TPM_SU;
#define TPM_SU_CLEAR (0x0000)
#define TPM_SU_STATE (0x0001)

typedef UINT8 TPM_SE;
#define TPM_SE_HMAC   (0x00)
#define TPM_SE_POLICY (0x01)

typedef UINT32 TPM_CAP;
#define TPM_CAP_FIRST           (0x00000000)
#define TPM_CAP_ALGS            (0x00000000)
#define TPM_CAP_HANDLES         (0x00000001)
#define TPM_CAP_COMMANDS        (0x00000002)
#define TPM_CAP_PCRS            (0x00000005)
#define TPM_CAP_LAST            (0x00000008)
#define TPM_CAP_VENDOR_PROPERTY (0x00000100)
#define TPM_CAP_PROPERTY_STAGE  (0x00000001)
#define PTT_STAGE_OSBUP         (0x0)
#define PTT_STAGE_MAIN_MEM      (0x3)

typedef UINT32 TPM_PT;
typedef UINT32 TPM_PT_PCR;
typedef UINT32 TPM_HANDLE;
typedef UINT8 TPM_HT;

#define TPM_RH_OWNER       (0x40000001)
#define TPM_RH_NULL        (0x40000007)
#define TPM_RS_PW          (0x40000009)

#define TPM_RH_ENDORSEMENT (0x4000000B)
#define TPM_RH_PLATFORM    (0x4000000C)

typedef union {
  struct {
    unsigned int asymmetric : 1;
    unsigned int symmetric  : 1;
    unsigned int hash       : 1;
    unsigned int object     : 1;
    unsigned int reserved1  : 4;
    unsigned int signing    : 1;
    unsigned int encrypting : 1;
    unsigned int method     : 1;
    unsigned int reserved2  : 21;
  };
  UINT32 val;
} TPMA_ALGORITHM;

typedef union {
  struct {
    unsigned int continueSession : 1;
    unsigned int auditExclusive  : 1;
    unsigned int auditReset      : 1;
    unsigned int reserved1       : 2;
    unsigned int decrypt         : 1;
    unsigned int encrypt         : 1;
    unsigned int audit           : 1;
  };
  UINT32 val;
} TPMA_SESSION;

typedef union {
  struct {
    unsigned int TPM_LOC_ZERO  : 1;
    unsigned int TPM_LOC_ONE   : 1;
    unsigned int TPM_LOC_TWO   : 1;
    unsigned int TPM_LOC_THREE : 1;
    unsigned int TPM_LOC_FOUR  : 1;
    unsigned int Extended      : 3;
  };
  UINT32 val;
} TPMA_LOCALITY;

typedef BYTE TPMI_YES_NO;
#define NO  0
#define YES 1

typedef TPM_HANDLE TPMI_DH_OBJECT;
typedef TPM_HANDLE TPMI_DH_PERSISTENT;
typedef TPM_HANDLE TPMI_DH_ENTITY;
typedef TPM_HANDLE TPMI_DH_PCR;
typedef TPM_HANDLE TPMI_SH_AUTH_SESSION;
typedef TPM_HANDLE TPMI_SH_POLICY;
typedef TPM_HANDLE TPMI_DH_CONTEXT;
typedef TPM_HANDLE TPMI_RH_HIERARCHY;
typedef TPM_HANDLE TPMI_RH_PLATFORM;
typedef TPM_HANDLE TPMI_RH_PROVISION;
typedef TPM_HANDLE TPMI_RH_CLEAR;
typedef TPM_HANDLE TPMI_RH_NV_AUTH;
typedef TPM_HANDLE TPMI_RH_NV_INDEX;
typedef TPM_ALG_ID TPMI_ALG_HASH;
typedef TPM_ALG_ID TPMI_ALG_SYM;

typedef union {
  BYTE sha1[SHA1_DIGEST_SIZE];
  BYTE sha256[SHA256_DIGEST_SIZE];
  BYTE sha384[SHA384_DIGEST_SIZE];
  BYTE sha512[SHA512_DIGEST_SIZE];
  BYTE sm3_256[SM3_256_DIGEST_SIZE];
} TPMU_HA;

typedef struct {
  TPMI_ALG_HASH hashAlg;
  TPMU_HA       digest;
} TPMT_HA;

TPM2B_TYPE(DIGEST, sizeof(TPMU_HA));

TPM2B_TYPE(DATA, sizeof(TPMT_HA));

typedef TPM2B_DIGEST TPM2B_NONCE;

typedef TPM2B_DIGEST TPM2B_AUTH;

TPM2B_TYPE(EVENT, 1024);

TPM2B_TYPE(MAX_BUFFER, MAX_DIGEST_BUFFER);

TPM2B_TYPE(MAX_NV_BUFFER, MAX_NV_BUFFER_SIZE);

typedef struct {
  UINT8 sizeofSelect;
  BYTE  pcrSelect[PCR_SELECT_MAX];
} TPMS_PCR_SELECT;

typedef struct {
  TPMI_ALG_HASH hash;
  UINT8         sizeofSelect;
  BYTE          pcrSelect[PCR_SELECT_MAX];
} TPMS_PCR_SELECTION;

typedef struct {
  TPM_ALG_ID     alg;
  TPMA_ALGORITHM algProperties;
} TPMS_ALG_PROPERTY;

typedef struct {
  TPM_PT property;
  UINT32 value;
} TPMS_TAGGED_PROPERTY;

typedef struct {
  TPM_PT_PCR tag;
  UINT8      sizeofSelect;
  BYTE       pcrSelect[PCR_SELECT_MAX];
} TPMS_TAGGED_PCR_SELECT;

typedef struct {
  UINT32       count;
  TPM2B_DIGEST digests[8];
} TPML_DIGEST;

typedef struct {
  UINT32  count;
  TPMT_HA digests[TPM20_HASH_COUNT];
} TPML_DIGEST_VALUES;

TPM2B_TYPE(DIGEST_VALUES, sizeof(TPML_DIGEST_VALUES));

typedef struct {
  UINT32             count;
  TPMS_PCR_SELECTION pcrSelections[TPM20_HASH_COUNT];
} TPML_PCR_SELECTION;

typedef struct {
  UINT32            count;
  TPMS_ALG_PROPERTY algProperties[1];
} TPML_ALG_PROPERTY;

#define FTPM_MAX_INTEL_PROP_VALUE 1
typedef UINT32 INTEL_PROP_VALUE;

typedef struct {
  UINT32 count;
  union {
    INTEL_PROP_VALUE properties[FTPM_MAX_INTEL_PROP_VALUE];
    INTEL_PROP_VALUE property;
  };
} INTEL_PROPERTY;

typedef union {
  TPML_ALG_PROPERTY algorithms;
  INTEL_PROPERTY    intelProperty;
} TPMU_CAPABILITIES;

typedef struct {
  TPM_CAP           capability;
  TPMU_CAPABILITIES data;
} TPMS_CAPABILITY_DATA;

typedef struct {
  TPML_PCR_SELECTION pcrSelect;
  TPM2B_DIGEST       pcrDigest;
} TPMS_QUOTE_INFO;

typedef struct {
  TPMI_ALG_SYM algorithm;
} TPMT_SYM_DEF;

typedef union {
  BYTE symmetric[sizeof(TPM2B_DIGEST)];
} TPMU_ENCRYPTED_SECRET;

TPM2B_TYPE(ENCRYPTED_SECRET, sizeof(TPMU_ENCRYPTED_SECRET));

typedef union {
  struct {
    unsigned int TPMA_NV_PPWRITE        : 1;
    unsigned int TPMA_NV_OWNERWRITE     : 1;
    unsigned int TPMA_NV_AUTHWRITE      : 1;
    unsigned int TPMA_NV_POLICYWRITE    : 1;
    unsigned int TPM_NT                 : 4;
    unsigned int reserved1              : 2;
    unsigned int TPMA_NV_POLICY_DELETE  : 1;
    unsigned int TPMA_NV_WRITELOCKED    : 1;
    unsigned int TPMA_NV_WRITEALL       : 1;
    unsigned int TPMA_NV_WRITEDEFINE    : 1;
    unsigned int TPMA_NV_WRITE_STCLEAR  : 1;
    unsigned int TPMA_NV_GLOBALLOCK     : 1;
    unsigned int TPMA_NV_PPREAD         : 1;
    unsigned int TPMA_NV_OWNERREAD      : 1;
    unsigned int TPMA_NV_AUTHREAD       : 1;
    unsigned int TPMA_NV_POLICYREAD     : 1;
    unsigned int reserved2              : 5;
    unsigned int TPMA_NV_NO_DA          : 1;
    unsigned int TPMA_NV_ORDERLY        : 1;
    unsigned int TPMA_NV_CLEAR_STCLEAR  : 1;
    unsigned int TPMA_NV_READLOCKED     : 1;
    unsigned int TPMA_NV_WRITTEN        : 1;
    unsigned int TPMA_NV_PLATFORMCREATE : 1;
    unsigned int TPMA_NV_READ_STCLEAR   : 1;
  };
  UINT32 val;
} TPMA_NV;

typedef struct {
  TPMI_RH_NV_INDEX nvIndex;
  TPMI_ALG_HASH    nameAlg;
  TPMA_NV          attributes;
  TPM2B_DIGEST     authPolicy;
  UINT16           dataSize;
} TPMS_NV_PUBLIC;

typedef struct {
  UINT16         size;
  TPMS_NV_PUBLIC nvPublic;
} NV_PUBLIC_2B;

typedef union {
  NV_PUBLIC_2B t;
  TPM2B        b;
} TPM2B_NV_PUBLIC;

//
// Version of PCR request structure covering all ACM suported
// algorithms.
//

typedef struct {
  TPM_ST tag;
  UINT32 responseSize;
  UINT32 responseCode;
  UINT32 pcrUpdateCounter;

  UINT32             count;
  TPMS_PCR_SELECTION pcrSelections[1];
  // TPML_DEGEST    pcrValues
} TPM20_Multi_PcrRead_Out;

typedef struct {
  TPMI_ALG_HASH hashAlg;
  UINT8         digest[SHA512_DIGEST_SIZE];
} TPMT_HA_MAX;

//
// Generic header
//
typedef struct _TPM_Header_In {
  UINT16 tag;
  UINT32 paramSize;
  UINT32 ordinal;
} TPM_Header_In;

typedef struct _TPM_Header_Out {
  UINT16 tag;
  UINT32 paramSize;
  UINT32 returnCode;
} TPM_Header_Out;

typedef struct {
  TPM_ST             tag;
  UINT32             responseSize;
  UINT32             responseCode;
  UINT32             parameterSize; // Sighting 3865089
  TPML_DIGEST_VALUES digests;
//  UINT8 otherData;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_DIGEST results;
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
} TPM20_EventSequenceComplete_Out;

typedef struct {
  TPM_ST           tag;
  UINT32           commandSize;
  TPM_CC           commandCode;
  TPMI_RH_NV_INDEX nvIndex;
  UINT16           size;
  UINT16           offset;
} TPM20_INTC_NV_Read;

typedef struct {
  TPM_Header_Out common;
  UINT32         parameterSize;
} TPM20_NVRead_Out;

typedef struct _TPM20_NV_ReadValue_Out {
  TPM20_NVRead_Out Header;
  UINT16           dataSize;
  UINT8            data[];
} TPM20_NV_ReadValue_Out;

typedef struct _TPM20_INTC_NV_ReadValue_Out {
  TPM_Header_Out Header;
  UINT16         dataSize;
  UINT8          data[];
} TPM20_INTC_NV_ReadValue_Out;

typedef struct {
  TPM_ST            tag;
  UINT32            commandSize;
  TPM_CC            commandCode;
  TPMI_RH_PROVISION authHandle;
  TPMI_RH_NV_INDEX  nvIndex;
  UINT32            authorizationSize;
//
// NOTE: other input data consists of the following fields.  But it can't be
// specified here because some structures can vary in size.
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
//  TPM2B_MAX_NV_BUFFER data;
//  UINT16 offset;
//
} TPM20_NVWrite_In;

typedef struct {
  TPM_ST tag;
  UINT32 responseSize;
  UINT32 responseCode;
  UINT32 parameterSize;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_MAX_NV_BUFFER data;
//
} TPM20_NVWrite_Out;

typedef struct {
  TPM_ST           tag;
  UINT32           commandSize;
  TPM_CC           commandCode;
  TPMI_RH_NV_INDEX nvIndex;
//
// NOTE: other input data consists of the following fields.  But it can't be
// specified here because some structures can vary in size.
//
//  TPM2B_MAX_NV_BUFFER data;
//  UINT16 offset;
//
} TPM20_INTC_NVWrite_In;

typedef struct {
  TPM_ST         tag;
  UINT32         commandSize;
  TPM_CC         commandCode;
  TPMI_DH_OBJECT tpmKey;
  TPMI_DH_ENTITY bind;
  UINT8          authorizationSize;
//
// NOTE: otherData consists of the following fields.  But it can't be
// specified here because some structures can vary in size.
//
//  TPM2B_NONCE nonceCaller;
//  TPM2B_ENCRYPTED_SECRET salt;
//  TPM_SE sessionType;
//  TPMT_SYM_DEF symmetric;
//  TPMI_ALG_HASH authHash;
//
} TPM20_StartAuthSession_In;

typedef struct {
  TPM_ST               tag;
  UINT32               responseSize;
  UINT32               responseCode;
  TPMI_SH_AUTH_SESSION sessionHandle;
  TPM2B_NONCE          nonceTpm;
  UINT32               parameterSize;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
} TPM20_StartAuthSession_Out;

typedef struct {
  TPM_ST      tag;
  UINT32      commandSize;
  TPM_CC      commandCode;
  TPMI_DH_PCR pcrHandle;
  UINT8       authorizationSize;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
//  TPM2B_EVENT eventData;
//
} TPM20_PcrEvent_In;

typedef struct {
  TPM_ST             tag;
  UINT32             responseSize;
  UINT32             responseCode;
  UINT32             parameterSize; // Sighting 3865089
  TPML_DIGEST_VALUES digests;
// UINT8 otherData;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPML_DIGEST_VALUES digest;
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
} TPM20_PcrEvent_Out;

typedef struct {
  TPM_ST        tag;
  UINT32        responseSize;
  UINT32        responseCode;
  UINT32        pcrUpdateCounter;
  UINT32        count;        // Assumed 1
  TPMI_ALG_HASH hash;         // Assumed SHA1
  UINT8         sizeOfSelect; // Assumed 3
  UINT8         pcrSelect[3];
  TPML_DIGEST   digest;
} TPM20_Single_PcrRead_Out;

typedef struct {
  TPM_ST tag;
  UINT32 responseSize;
  UINT32 responseCode;
  UINT8  otherData;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_DIGEST result;
//  TPMT_TK_HASHCHECK validation;
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
} TPM20_SequenceComplete_Out;

typedef struct {
  TPM_ST         tag;
  UINT32         responseSize;
  UINT32         responseCode;
  TPMI_DH_OBJECT sequenceHandle;
} TPM20_HashSequenceStart_Out;

typedef struct {
  UINT16               tag;
  UINT32               responseSize;
  UINT32               responseCode;
  UINT8                moreData;
  TPMS_CAPABILITY_DATA capabilityData;
} TPM20_GetCapability_Out;

typedef struct {
  TPM_ST tag;
  UINT32 commandSize;
  TPM_CC commandCode;
  UINT32 capability;
  UINT32 property;
  UINT32 propertyCount;
} TPM20_GetCapability_In;

typedef struct {
  TPM_ST           tag;
  UINT32           commandSize;
  TPM_CC           commandCode;
  TPMI_RH_NV_INDEX nvIndex;
} TPM20_NVReadPublic_In;

typedef struct {
  TPM_ST tag;
  UINT32 responseSize;
  UINT32 responseCode;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
  TPM2B_NV_PUBLIC nvPublic;
//  TPM2B_NAME nvName;
//
} TPM20_NVReadPublic_Out;

typedef struct {
  TPM_ST tag;
  UINT32 commandSize;
  TPM_CC commandCode;
  TPM_SU shutdownType;
} TPM20_Shutdown_In;

typedef struct {
  TPM_ST tag;
  UINT32 commandSize;
  TPM_CC commandCode;
  UINT16 data;
} TPM20_INTC_PwrPersistentDataSet_In;

typedef struct {
  TPM_ST tag;
  UINT32 responseSize;
  UINT32 responseCode;
} TPM20_INTC_PwrPersistentDataSet_Out;

typedef struct {
  TPM_ST tag;
  UINT32 commandSize;
  TPM_CC commandCode;
} TPM20_INTC_PwrPersistentDataGet_In;

typedef struct {
  TPM_ST tag;
  UINT32 responseSize;
  UINT32 responseCode;
  UINT16 data;
} TPM20_INTC_PwrPersistentDataGet_Out;

//
// TPM20 startup params
//
typedef struct _TPM20_Startup_In {
  TPM_ST tag;
  UINT32 commandSize;
  TPM_CC commandCode;
  UINT16 startupType;
} TPM20_Startup_In;

typedef struct {
  TPM_ST         tag;
  UINT32         commandSize;
  TPM_CC         commandCode;
  TPMI_DH_PCR    pcrHandle;
  TPMI_DH_OBJECT sequenceHandle;
  UINT8          authorizationSize;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
//  TPM2B_MAX_BUFFER buffer;
//
} TPM20_EventSequenceComplete_In;

typedef struct {
  TPM_ST tag;
  UINT32 commandSize;
  TPM_CC commandCode;
  UINT8  authorizationSize;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_AUTH auth;
//  TPMI_ALG_HASH hashAlg;
} TPM20_HashSequenceStart_In;

typedef struct {
  TPM_ST        tag;
  UINT32        commandSize;
  TPM_CC        commandCode;
  TPMI_RH_CLEAR authHandle;
  UINT32        authorizationSize;
//
// NOTE: other input data consists of the following fields.  But it can't be
// specified here because some structures can vary in size.
//
//  TPMI_SH_AUTH_SESSION sessionHandle;
//  TPM2B_NONCE nonce;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
//  TPMI_RH_HIERARCHY hierarchy;
//  TPMI_YES_NO state;
//
} TPM20_HierarchyControl_In;

typedef struct {
  TPM_ST            tag;
  UINT32            commandSize;
  TPM_CC            commandCode;
  TPMI_RH_PROVISION authHandle;
  TPMI_RH_NV_INDEX  nvIndex;
  UINT32            authorizationSize;
//
// NOTE: other input data consists of the following fields.  But it can't be
// specified here because some structures can vary in size.
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
//  UINT16 size;
//  UINT16 offset;
//
} TPM20_NVRead_In;

typedef struct {
  TPM_ST      tag;
  UINT32      commandSize;
  TPM_CC      commandCode;
  TPMI_DH_PCR pcrHandle;
  UINT32      authorizationSize;
//
// NOTE: other input data consists of the following fields.  But it can't be
// specified here because some structures can vary in size.
//
//  TPMI_SH_AUTH_SESSION sessionHandle;
//  TPM2B_NONCE nonce;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
//  TPML_DIGEST_VALUES digests;
//
} TPM20_PcrExtend_In;

typedef struct {
  TPM_ST tag;
  UINT32 commandSize;
  TPM_CC commandCode;
  UINT8  authorizationSize;
//
// NOTE: other input data consists of the following fields.  But it can't be
// specified here because some structures can vary in size.
//
//  TPML_PCR_SELECTION pcrSelection;
//
} TPM20_PcrRead_In;

typedef struct {
  TPM_ST         tag;
  UINT32         commandSize;
  TPM_CC         commandCode;
  TPMI_SH_POLICY policySession;
//
// NOTE: other input data consists of the following fields.  But it can't be
// specified here because some this structure will allocate two bytes
// for it when the canonical version (over the wire version) will only use
// one byte.
//
//  TPMA_LOCALITY locality;
//
} TPM20_PolicyLocality_In;

typedef struct {
  TPM_ST         tag;
  UINT32         commandSize;
  TPM_CC         commandCode;
  TPMI_SH_POLICY policySession;
  UINT8          otherData;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPML_DIGEST pHashList;
//
} TPM20_PolicyOr_In;

typedef struct {
  TPM_ST         tag;
  UINT32         commandSize;
  TPM_CC         commandCode;
  TPMI_DH_OBJECT sequenceHandle;
  UINT8          authorizationSize;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
//  TPM2B_MAX_BUFFER buffer;
//  TPMI_RH_HIERARCHY hierarchy;
//
} TPM20_SequenceComplete_In;

typedef struct {
  TPM_ST         tag;
  UINT32         commandSize;
  TPM_CC         commandCode;
  TPMI_DH_OBJECT sequenceHandle;
  UINT8          authorizationSize;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_NONCE nonceTpm;
//  TPMA_SESSION sessionAttributes;
//  TPM2B_AUTH hmac;
//
//  TPM2B_MAX_BUFFER buffer;
//
} TPM20_SequenceUpdate_In;

typedef struct {
  TPM_ST           tag;
  UINT32           commandSize;
  TPM_CC           commandCode;
  TPMI_RH_NV_INDEX nvIndex;
  TPMI_RH_PLATFORM platform;
  UINT8            otherData;
  //
  // NOTE: other input data consists of the following fields.  But it can't be
  // specified here because some structures can vary in size.
  //
  //  Note:  first two sessions below are associated with
  //  the nvIndex and platform handles.
  //  TPM_CMD_SESSION_DATA_IN[];
  //
} TPM20_NV_UndefineSpaceSpecial_In;

typedef struct {
  TPM_ST          tag;
  UINT32          commandSize;
  TPM_CC          commandCode;
  TPMI_DH_CONTEXT flushHandle;
} TPM20_FlushContext_In;

typedef struct {
  TPM_ST         tag;
  UINT32         commandSize;
  TPM_CC         commandCode;
  TPMI_SH_POLICY policySession;
  TPM_CC         code;
} TPM20_PolicyCommandCode_In;

typedef struct {
  TPM_ST         tag;
  UINT32         commandSize;
  TPM_CC         commandCode;
  TPMI_SH_POLICY policySession;
  UINT8          otherData;
//
// NOTE: other output data consists of the following fields.  But it can't be
// specified here because some structures can vary in size or may not
// even be present.
//
//  TPM2B_DIGEST &pcrDigest;
//  TPML_PCR_SELECTION &pcrs;
//
} TPM20_PolicyPcr_In;

#endif
