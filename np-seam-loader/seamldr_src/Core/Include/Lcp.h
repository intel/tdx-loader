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

#ifndef LCP_H
#define LCP_H

#include <tpm.h>
#include <KeySignCom.h>

#define POLHALG_SHA1           0x00
#define POLSALG_NONE           0x00
#define POLSALG_RSA_PKCS_15    0x01
#define MAX_POLSALG            0x01

#define POLTYPE_LIST           0x00
#define POLTYPE_ANY            0x01
#define MAX_POLTYPE            0x01 // maximum value for Policy Type

#define LCP_CAP_POWN_SUPPORTED BIT0

#define LCP_MAX_LISTS          0x08
#define POLTYPE_NONE           0xFF

#define LCP_POLELT_TYPE_MAX    (LCP_POLELT_TYPE_STM + 1)
//
// Don't remove commented fields of structures - they
// cannot be uncommented due to the same zero-size aray limitation but
// help code readability.
//
// Policy control atructure of LCP_POLICY
//
typedef struct _POLICY_CONTROL {
  UINT32 reserved  : 1;
  UINT32 NPW_OK    : 1; // NPW modules are allowed.
  UINT32 reserved2 : 1; // OsSinitData.Capabilities is extended into PCR17
  UINT32 Pconf_enf : 1; // Owner policy is required or PS configuration is enforced.
  UINT32 reserved3 : 28;
} POLICY_CONTROL;

typedef struct _TPM_PCR_SELECTION {
  UINT16 sizeOfSelect;
  UINT8  pcrSelect[VAR_SIZE];
} TPM_PCR_SELECTION;

typedef struct _TPM_PCR_COMPOSITE {
  TPM_PCR_SELECTION pcrSelection;
  // UINT32         valueSize;
  // UINT8          pcrValue[valueSize * H_LEN];
} TPM_PCR_COMPOSITE;

typedef struct _TPM_PCR_INFO_SHORT {
  TPM_PCR_SELECTION pcrSelection;
  // UINT8          localityAtRelease;
  // UINT8		    digestAtRelease[H_LEN];
} TPM_PCR_INFO_SHORT;

typedef struct _LCP_PCONF_ELEMENT {
  UINT16             NumPcrInfos;
  TPM_PCR_INFO_SHORT PCRInfos[VAR_SIZE];
} LCP_PCONF_ELEMENT;

typedef struct _LCP_STM_ELEMENT {
  UINT8  HashAlg;
  UINT8  Reserved;
  UINT16 NumHashes;
  UINT8  Hashes[VAR_SIZE][H_LEN];
} LCP_STM_ELEMENT;

typedef struct _LCP_MLE_ELEMENT {
  UINT8  SINITMinVersion;
  UINT8  HashAlg;
  UINT16 NumHashes;
  UINT8  Hashes[VAR_SIZE][H_LEN];
} LCP_MLE_ELEMENT;

typedef union {
  UINT8 sha1[SHA1_DIGEST_SIZE];
  UINT8 sha256[SHA256_DIGEST_SIZE];
  UINT8 sha384[SHA384_DIGEST_SIZE];
  UINT8 sha512[SHA512_DIGEST_SIZE];
  UINT8 sm3[SM3_256_DIGEST_SIZE];
} LCP_HASH2;

#define LCP_POLELT_TYPE_MLE2 (0x10 | LCP_POLELT_TYPE_MLE)

typedef struct {
  UINT8     SINITMinVersion;
  UINT8     Reserved;
  UINT16    HashAlg; // one of TPM_ALG_*
  UINT16    NumHashes;
  LCP_HASH2 Hashes[VAR_SIZE];
} LCP_MLE_ELEMENT2;

#define LCP_POLELT_TYPE_STM2 (0x10 | LCP_POLELT_TYPE_STM)
typedef struct {
  UINT16    HashAlg; // one of TPM_ALG_*
  UINT16    NumHashes;
  LCP_HASH2 Hashes[VAR_SIZE];
} LCP_STM_ELEMENT2;

#define LCP_POLELT_TYPE_PCONF2 (0x10 | LCP_POLELT_TYPE_PCONF)

typedef struct {
  UINT16          HashAlg; // one of TPM_ALG_*
  UINT16          NumPCRInfos;
  TPMS_QUOTE_INFO PCRInfos[];
}LCP_PCONF_ELEMENT2;

typedef struct _LCP_POLICY_ELEMENT {
  UINT32 EltSize;
  UINT32 EltType;
  UINT32 PolEltControl;
  union {
    LCP_MLE_ELEMENT    e1;
    LCP_PCONF_ELEMENT  e2;
    LCP_STM_ELEMENT    e4;
    LCP_MLE_ELEMENT2   e11;
    LCP_PCONF_ELEMENT2 e12;
    LCP_STM_ELEMENT2   e14;
  };
} LCP_POLICY_ELEMENT;

// #define ORIGIN_POLICY_NONE      0
// #define ORIGIN_POLICY_PS        1
// #define ORIGIN_POLICY_PO        2

typedef struct _LCP_ELT_EFF_HASH {
  UINT32 PolEltControl;
  UINT8  PolEltHash[H_LEN];
} LCP_ELT_EFF_HASH;

//
// This structure represents data in TPM 1.2 PO index
//

typedef struct _LCP_POLICY {
  UINT16 PolicyVersion;
  UINT8  HashAlg;
  UINT8  PolicyType;
  UINT8  SINITMinVersion;
  UINT8  Reserved;
  UINT16 DataRevocationCounters[LCP_MAX_LISTS];
  UINT32 PolicyControl;
  UINT8  MaxSINITMinVersion;
  UINT8  Reserved2[5];
  UINT16 PowerDownInterval;
  UINT8  PolicyHash[H_LEN];
} LCP_POLICY;

typedef struct _COMBINED_HASH_DATA {
  UINT8  ScleanDigest[H_LEN];
  UINT64 MsrValidBit;
  UINT8  StmDigest[H_LEN];
  UINT32 LcpControlField;
  UINT8  LcpDigest[H_LEN];
  UINT32 OsSinitDataCapabilities;
  UINT32 ProcessorScrtmStatus;
} COMBINED_HASH_DATA;

//
// Don't delete commented field names. They are included for references.
// Commented fields cannot be uncommented since they follow fields with
// variable sizes.
//
// Cannot create some labels since PubkeyValue contains variable size array.
//

//
// Policy control atructure of LCP_POLICY
//
typedef struct _POLICY_ELT_CONTROL {
  UINT32 Res2       : 1; // Override PSup element of this type
  UINT32 StmReq     : 1; // STM required.
  UINT32 OemPcrCtrl : 1; // PCR18 stability
  UINT32 Res        : 29;
} POLICY_ELT_CONTROL;

typedef UINT32 (*PTR_FUNC_POL_ELT)(LCP_POLICY_ELEMENT *pElt);
typedef UINT32 (*PTR_FUNC_NO_ARG)();

typedef struct _LCP_POLICY_LIST {
  UINT16             ListVersion;
  UINT8              Reserved;
  UINT8              SigAlgorithm;
  UINT32             PolicyElementsSize;
  LCP_POLICY_ELEMENT PolicyElements[VAR_SIZE];
  // LCP_SIGNATURE     Signature;
} LCP_POLICY_LIST;

typedef struct _LCP_POLICY_LIST2 {
  UINT16 ListVersion;
  UINT16 SigAlgorithm;
  UINT32 PolicyElementsSize;
  //
  // Correct declaration would be LCP_POLICY_ELEMENT  PolicyElements[]
  // but 'C' compiler disallows declarations of arrays of elements
  // containig variable size arrays.
  //
  LCP_POLICY_ELEMENT PolicyElements[VAR_SIZE];
  // LCP_SIGNATURE2     Signature;
} LCP_POLICY_LIST2;

typedef struct {
  UINT16             ListVersion; // Must be 3.0
  UINT16             KeySignatureOffset;
  UINT32             PolicyElementsSize;
  LCP_POLICY_ELEMENT PolicyElements[VAR_SIZE];
  // LCP_SIGNATURE2_1  Signature;
} LCP_POLICY_LIST2_1;

typedef union {
// LCP_POLICY_LIST    TPM12PolicyList;
  LCP_POLICY_LIST2   TPM20PolicyList;
  LCP_POLICY_LIST2_1 TPM20PssPolicyList;
} LCP_LIST;

#define LCP_POLICY_LIST_VER1_MAJOR 0x01
#define LCP_POLICY_LIST_VER2_MAJOR 0x02
#define LCP_POLICY_LIST_VER3_MAJOR 0x03

#define LCP_POLICY_LIST_MAJOR(LIST)          ((LIST)->TPM20PolicyList.ListVersion >> 8)
#define LCP_POLICY_LIST_MINOR(LIST)          ((LIST)->TPM20PolicyList.ListVersion & 0xFF)

#define MK_LCP_POLICY_LIST_VERSION(MAJ, MIN) (((MAJ) << 8) | ((MIN) & 0xFF))

typedef struct {
  UINT8           id[32];
  UINT8           Reserved[3];
  UINT8           NumLists;
  LCP_POLICY_LIST PolicyLists[];
} LCP_POLICY_DATA;

typedef struct {
  UINT8            id[32];
  UINT8            Reserved[3];
  UINT8            NumLists;
  LCP_POLICY_LIST2 PolicyLists[];
} LCP_POLICY_DATA2;

typedef struct {
  UINT8              id[32];
  UINT8              Reserved[3];
  UINT8              NumLists;
  LCP_POLICY_LIST2_1 PolicyLists[];
} LCP_POLICY_DATA2_1;

#define LCP_APPROVED_ALG_SHA1       BIT0
#define LCP_APPROVED_ALG_SHA224     BIT1
#define LCP_APPROVED_ALG_SHA512_224 BIT2
#define LCP_APPROVED_ALG_SHA256     BIT3
#define LCP_APPROVED_ALG_SHA512_256 BIT4
#define LCP_APPROVED_ALG_SM3_256    BIT5
#define LCP_APPROVED_ALG_SHA384     BIT6
#define LCP_APPROVED_ALG_SHA512     BIT7
#define LCP_APPROVED_ALG_WHIRLPOOL  BIT8

//
// These masks match below structure. They mush stay in sync.
//
#define LCP_APPROVED_ALG_RSASSA_MSK 0x00000FFF
#define LCP_APPROVED_ALG_ECDSA_MSK  0x00003000
#define LCP_APPROVED_ALG_SM2_MSK    0x00010000

#define LCP_APPROVED_SHA1_MSK       0x00000005
#define LCP_APPROVED_SHA256_MSK     0x0000124A
#define LCP_APPROVED_SHA384_MSK     0x00002490
#define LCP_APPROVED_SHA512_MSK     0x00000920
#define LCP_APPROVED_SM3_MSK        0x00010000

#define LCP_APPROVED_1024KEY_MSK    0x00000003
#define LCP_APPROVED_2048KEY_MSK    0x0000003C
#define LCP_APPROVED_3072KEY_MSK    0x000001C0
#define LCP_APPROVED_4096KEY_MSK    0x00000E00
#define LCP_APPROVED_256KEY_MSK     0x00001000
#define LCP_APPROVED_384KEY_MSK     0x00002000

typedef union {
  struct {
    UINT32 TPM_ALG_RSASSA_1024_SHA1   : 1;
    UINT32 TPM_ALG_RSASSA_1024_SHA256 : 1;
    UINT32 TPM_ALG_RSASSA_2048_SHA1   : 1;
    UINT32 TPM_ALG_RSASSA_2048_SHA256 : 1;

    UINT32 TPM_ALG_RSASSA_2048_SHA384 : 1;
    UINT32 TPM_ALG_RSASSA_2048_SHA512 : 1;
    UINT32 TPM_ALG_RSASSA_3072_SHA256 : 1;
    UINT32 TPM_ALG_RSASSA_3072_SHA384 : 1;

    UINT32 TPM_ALG_RSASSA_3072_SHA512 : 1;
    UINT32 TPM_ALG_RSASSA_4096_SHA256 : 1;
    UINT32 TPM_ALG_RSASSA_4096_SHA384 : 1;
    UINT32 TPM_ALG_RSASSA_4096_SHA512 : 1;
    UINT32 TPM_ALG_ECDSA_P256         : 1;
    UINT32 TPM_ALG_ECDSA_P384         : 1;
    UINT32 Reserved                   : 2;
    UINT32 TPM_ALG_SM2_SM2_CURVE      : 1;
    UINT32 Reserved2                  : 15;
  };
  UINT32 val;
} LCP_APPROVED_SIGNATURE_ALG;

//
// THis structure represents data in TPM 2.0 PO index.
//
typedef struct _LCP_POLICY2 {
  UINT16    PolicyVersion;
  UINT16    HashAlg;
  UINT8     PolicyType;                            //32
  UINT8     SINITMinVersion;                       //36
  UINT16    DataRevocationCounters[LCP_MAX_LISTS]; //40
  UINT32    PolicyControl;
  UINT8     MaxSINITMinVersion;
  UINT8     Reserved;
  UINT16    LcpHashAlgMask;
  UINT32    LcpSignAlgMask;
  UINT16    Reserved2;
  UINT16    PowerDownInterval;
  LCP_HASH2 PolicyHash;
} LCP_POLICY2;

//
// After GetPolicy call actual data from PO index are copied into
// variable having this structure. It therefore universal for all TPM
// families.
//
typedef struct _ACM_LCP_POLICY {
  UINT16 PolicyVersion;
  UINT16 PolicyHashAlg;
  UINT8  PolicyType;
  UINT8  SINITMinVersion;
  UINT16 DataRevocationCounters[LCP_MAX_LISTS]; //40
  UINT32 PolicyControl;
  UINT8  MaxSINITMinVersion;
  UINT16 LcpHashAlgMask;
  UINT32 LcpSignAlgMask;
  UINT16 PowerDownInterval;
  UINT8  PolicyHash[SHA384_DIGEST_SIZE];

  // Used in policy processing
  UINT32 InvalidListsMask : 8;
  UINT32 Read             : 1;
  UINT32 Resv             : 23;
} ACM_LCP_POLICY;

#define LCP_POLICY_VER2_MAJOR     0x2
#define LCP_POLICY_VER2_MIN_MINOR 0x3
#define LCP_POLICY_VER3_MAJOR     0x3
#define LCP_POLICY_VER3_MIN_MINOR 0x1

#define LCP_POLICY_MAJOR(P)             ((P)->PolicyVersion >> 8)
#define LCP_POLICY_MINOR(P)             ((P)->PolicyVersion & 0xFF)

#define MK_LCP_POLICY_VERSION(MAJ, MIN) (((MAJ) << 8) | ((MIN) & 0xFF))

#define ELT_IND     UINT8
#define POL_CONTROL UINT32

typedef struct {
  ELT_IND     EltIndicator;
  POL_CONTROL PolControl;
  TPMT_HA     EffEltDigest;
} EFF_ELT_PRESENT_DESCRIPTOR;

typedef struct {
  ELT_IND EltIndicator;
} EFF_ELT_ABSENT_DESCRIPTOR;

typedef union {
  EFF_ELT_PRESENT_DESCRIPTOR PresDescr;
  EFF_ELT_ABSENT_DESCRIPTOR  AbsDescr;
}EFF_ELT_DESCRIPTOR;

typedef struct {
  UINT16  SignAlg;
  UINT16  HashAlg;
  UINT16  PubKeySize;
  TPMT_HA EffAuthDigest;
  //UINT64  DataBaseAddr;
  //UINT16  DataSize;
} LIST_SIGN_DSCR;

typedef struct {
  UINT16  SignAlg;
  TPMT_HA EffAuthDigest;
  //UINT64  DataBaseAddr;
  //UINT16  DataSize;
} LIST_UNSIGN_DSCR;

typedef union {
  LIST_SIGN_DSCR   SignedList;
  LIST_UNSIGN_DSCR UnsignedList;
} LIST_DSCR;

#define IDX_IND UINT8

typedef struct {
  IDX_IND        IndexIndicator;
  TPMS_NV_PUBLIC IndexProperties;
} EFF_IDX_PRESENT_DESCRIPTOR;

typedef struct {
  IDX_IND IndexIndicator;
} EFF_IDX_ABSENT_DESCRIPTOR;

typedef union {
  EFF_IDX_PRESENT_DESCRIPTOR PresDescr;
  EFF_IDX_ABSENT_DESCRIPTOR  AbsDescr;
}EFF_IDX_DESCRIPTOR;

// We don't write this anywhere, but use to keep track of hashes so they can
// be bundled together.
typedef struct {
  POL_CONTROL   PolEltControl;
  TPMI_ALG_HASH HashAlg;
  UINT32        HashSize;
  UINT8 *       Hash;
} EFF_ELF_HASH_INFO;

typedef struct _LCP_LIST_INFO {
  // UINT32  Origin;
  UINT32            Info;
  EFF_ELF_HASH_INFO HashInfo;
  UINT8             ElementCount;
} LCP_LIST_INFO;

typedef struct _LCP_POLICY_LIST_DETAILS {
  UINT8 *ListHashPointer;
  UINT32 PubKeySize;
  UINT32 SignHashAlg;
  UINT8 *PubKeyValue;
  UINT16 SignAlg;
} LCP_POLICY_LIST_DETAILS;

typedef struct _LCP_CONTEXT {
  UINT32 WorkingListIndex;
  UINT32 WorkingEltType;

  //
  // Effective list infos combined from all policies.
  // Info fields can have the following values:
  // NO_SUCH_TYPE - elements of given type are not present
  // NO_MATCH - elements of given type are present but no match is found
  // INDEX of list where match is found
  //
#define NO_SUCH_TYPE   0xFF
#define NO_MATCH       0xFE
#define MODULE_REVOKED 0xFD

  union {
    LCP_LIST_INFO EffElt[LCP_POLELT_TYPE_MAX];
    struct {
      LCP_LIST_INFO EffMle;
      LCP_LIST_INFO EffPConf;
      LCP_LIST_INFO EffStm;
    };
  };
  LCP_LIST_INFO EffPConf2;

  union {
    //
    // Mutually exclusive definitions of EffLcpPolicyAuthorities used in
    // TPM1.2 and TPM2.0 modes. Allocated size includes total number of
    // lists that can contribute to a match: MLE, PO PCONF, PS PCONF,
    // SBIOS or STM (STM and SBIOS don't exist simulteneously); and maximum
    // size for list descriptor.
    //
    struct {
      UINT8  EffLcpPolicyAuthorities[4 * sizeof(LIST_DSCR)];
      UINT32 EffLcpPolicyAuthoritiesSize;
    };
    struct {
      LCP_HASH2 TempLcpHash[3];
      UINT32    TempLcpHashSize;
    };
  };

  LCP_HASH2 POwnListHashSpace[LCP_MAX_LISTS];

  //
  // As we process lists, store any details needed for later
  //
  LCP_POLICY_LIST_DETAILS PolicyListDetails[LCP_MAX_LISTS];

  union {
    //
    // Mutually exclusive definitions of EffLcpPolicyDetails used in
    // TPM1.2 and TPM2.0 modes. Allocated size includes total number of
    // element types: MLE, PO PCONF, PS PCONF, SBIOS, STM; and maximum
    // size for element descriptor including maximum supported digest
    // size.
    //
    UINT8 EffLcpPolicyDetails[LCP_POLELT_TYPE_MAX * sizeof(EFF_ELT_PRESENT_DESCRIPTOR)];
    struct {
      LCP_ELT_EFF_HASH EffMleEltHash;
      LCP_ELT_EFF_HASH EffPConfEltHash;
      LCP_ELT_EFF_HASH EffSbiosEltHash;
      LCP_ELT_EFF_HASH EffStmEltHash;
    };
  };
  //
  // In addition to storing NV index values of AUX and PO, we need to store
  // absent byte for PS index. Hence size = 2 * sizeof(EFF_IDX_PRESENT_DESCRIPTOR) + 1
  //
  UINT8  EffIdxPropertyDetails[2 * sizeof(EFF_IDX_PRESENT_DESCRIPTOR) + 1];
  UINT32 EffIdxPropertyDetailsSize;

  VOID_NO_ARG fpValidateLcpPolicyDataTpm;
  VOID_NO_ARG fpSetLcpEffectiveHashesTpm;
  VOID_NO_ARG fpLcpInitTpm;
  void (*fpCopyEffectiveListHash)(LCP_LIST *);
  UINT8 (*fpValidSigningAlgorithm)(LCP_LIST *);

  GET_DATA fpGetBiosModuleHash;
} LCP_CONTEXT;

void LaunchControlPolicy();
void getPolicy(UINT32, ACM_LCP_POLICY *);
void enforceMle();
void enforcePConf();
void enforceStm();
void enforceSbios();
void processTpmLcp();
UINT32 GetEffectiveLcpPolicy();
void validateLcp();
void enforceLcp();
void HashPolicy(UINT32, UINT8 *);

extern void __LcpErrorHandler(UINT32, UINT32);

#if TRACE_WITH_FUNCTIONS & TRACE_ERRORHANDLER
#define LcpErrorHandler(A, B) do { \
    TRACEFUNCTION(TRACE_ERRORHANDLER, "LCP ERROR-HANDLER(%s#%d) %08x %08x\n", __FUNCTION__, __LINE__, (A), (B)); \
    __LcpErrorHandler((A), (B)); \
} while (0)
#else
#define LcpErrorHandler(A, B) __LcpErrorHandler((A), (B))
#endif

typedef struct {
  UINT16 HashAlgId;
  INT32  HashAlgIdx;
} LCP_MASK_INFO;

#define LCP_ALG_ID_COUNT   9
#define LCP_ALG_VALID_MASK ((1 << LCP_ALG_ID_COUNT) - 1)

typedef UINT32 (*PTR_FUNC_NO_ARG)();
typedef void (*PTR_FUNC_VALIDATE_ELT)(LCP_POLICY_ELEMENT *);
typedef UINT32 (*PTR_FUNC_EVAL_ELT)(LCP_POLICY_ELEMENT *, LCP_LIST_INFO *);

UINT32 Tpm20EvaluateMlePolicyElement(LCP_POLICY_ELEMENT *,
                                     LCP_LIST_INFO *);
UINT32 Tpm20EvaluatePConfPolicyElement(LCP_POLICY_ELEMENT *,
                                       LCP_LIST_INFO *);
UINT32 Tpm20EvaluateStmPolicyElement(LCP_POLICY_ELEMENT *,
                                     LCP_LIST_INFO *);
UINT32 Tpm20EvaluateSbiosPolicyElement(LCP_POLICY_ELEMENT *,
                                       LCP_LIST_INFO *);

void Tpm20ValidateMlePolicyElement(LCP_POLICY_ELEMENT *);
void Tpm20ValidatePConfPolicyElement(LCP_POLICY_ELEMENT *);
void Tpm20ValidateStmPolicyElement(LCP_POLICY_ELEMENT *);
void Tpm20ValidateSbiosPolicyElement(LCP_POLICY_ELEMENT *);

UINT32 getListData(LCP_LIST *,
                   void **,
                   UINT32 *,
                   UINT8 **,
                   UINT8 **,
                   UINT16 *,
                   UINT16 *,
                   UINT16 *);
void ValidateSignedLcpList(LCP_LIST *);
void HashSignedLcpList(LCP_LIST *,
                       UINT8 *);
void HashUnSignedLcpList(LCP_LIST *, UINT32, UINT8 *);

void LcpInit();
UINT8 IsElementTypeValid(UINT32);

void Tpm20ValidateLcpPolicyData();

#define validateTpmLcpPolicyData (*lcpCtx.fpValidateLcpPolicyDataTpm)

void Tpm20SetLcpEffectiveHashes();

#define setLcpEffectiveHashes (*lcpCtx.fpSetLcpEffectiveHashesTpm)

void Tpm20SetLcpEffectiveHashes();

#define setLcpEffectiveHashes (*lcpCtx.fpSetLcpEffectiveHashesTpm)

#define GetBiosModuleHash     (*lcpCtx.fpGetBiosModuleHash)

UINT8 ValidateSignedListAttributes(LCP_LIST *);

void Tpm20SelectivelyCopyEffectiveListHash(LCP_LIST *);

#define copyEffectiveListHash (*lcpCtx.fpCopyEffectiveListHash)

void Tpm20LcpInit();

#define LcpTpmInit (*lcpCtx.fpLcpInitTpm)

void LcpValidatePolicyVersion(ACM_LCP_POLICY *);

UINT8 Tpm20IsLcpHashAlgSupported(UINT16);
INT32 AlgIdToIdx(UINT16);

extern COMBINED_HASH_DATA CombinedHashData;
extern UINT32 lcpModPtr;

extern PTR_FUNC_EVAL_ELT lcpEvalEltPtr[];
extern PTR_FUNC_VALIDATE_ELT lcpValEltPtr[];

extern ACM_LCP_POLICY POwnLcp;

extern LCP_CONTEXT lcpCtx;
extern UINT32 LcpEltSelection;

extern LCP_APPROVED_SIGNATURE_ALG Tpm20LcpSignAlgMask;
extern LCP_APPROVED_SIGNATURE_ALG LcpSignAlgMask;
extern UINT32 AuxHashAlgId;

extern EFF_IDX_PRESENT_DESCRIPTOR Tpm20AuxEffIdxPropertyDetail;
extern UINT32 Tpm20AuxEffIdxPropertyDetailSize;
extern EFF_IDX_DESCRIPTOR Tpm20PsEffIdxPropertyDetail;
extern UINT32 Tpm20PsEffIdxPropertyDetailSize;
extern EFF_IDX_PRESENT_DESCRIPTOR Tpm20PoEffIdxPropertyDetail;
extern UINT32 Tpm20PoEffIdxPropertyDetailSize;
extern LCP_MASK_INFO lcpMaskInfo[LCP_ALG_ID_COUNT];

static __inline LCP_POLICY_LIST_DETAILS *GetPolicyListDetails(UINT32 ListIndex)
{
  return &lcpCtx.PolicyListDetails[ListIndex];
}

#endif
