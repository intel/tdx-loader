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

#ifndef TPM_H
#define TPM_H

#include <common.h>

#ifndef FN_STARTUPACM
#define FN_STARTUPACM 0XFF
#endif
//
// TPM indices
//
#ifndef TPM20_INDEX_AUX
#define TPM20_INDEX_AUX 0x01C10102 // NV Storage
#endif
#ifndef TPM20_INDEX_LCP_SUP
#define TPM20_INDEX_LCP_SUP 0x01C10103 // Launch Policy Default (Supplier)
#endif
#ifndef TPM20_INDEX_LCP_OWN
#define TPM20_INDEX_LCP_OWN 0x01C10106 // Launch Policy Owner
#endif

//
// TPM Registers for loc 0, 2, and 3
//
#define TPM_ACCESS_L0                0x0FED40000
#define TPM_ACCESS_LX                (TPM_ACCESS_L0 + ((TpmCtx.TpmLocality & 0x7) << 12))

#define LOCALITY_0                   BIT0
#define LOCALITY_1                   BIT1
#define LOCALITY_2                   BIT2
#define LOCALITY_3                   BIT3
#define LOCALITY_4                   BIT4

#define TPM20_TPMA_NV_OWNERWRITE     BIT1
#define TPM20_TPMA_NV_AUTHWRITE      BIT2
#define TPM20_TPMA_NV_POLICYWRITE    BIT3
#define TPM20_TPMA_NV_POLICY_DELETE  BIT10
#define TPM20_TPMA_NV_WRITEDEFINE    BIT13
#define TPM20_TPMA_NV_WRITE_STCLEAR  BIT14
#define TPM20_TPMA_NV_AUTHREAD       BIT18
#define TPM20_TPMA_NV_NO_DA          BIT25
#define TPM20_TPMA_NV_PLATFORMCREATE BIT30

// TPM20_LCP_PS_ATTR is PS1 attributes
// TPM20_LCP_PS_ATTR2 is PS2 attributes
#define TPM20_LCP_PS_ATTR  TPM20_TPMA_NV_POLICYWRITE + TPM20_TPMA_NV_POLICY_DELETE + \
  TPM20_TPMA_NV_AUTHREAD + TPM20_TPMA_NV_NO_DA + \
  TPM20_TPMA_NV_PLATFORMCREATE

#define TPM20_LCP_PS_ATTR2 TPM20_TPMA_NV_AUTHWRITE + TPM20_TPMA_NV_POLICY_DELETE + \
  TPM20_TPMA_NV_AUTHREAD + TPM20_TPMA_NV_NO_DA + \
  TPM20_TPMA_NV_PLATFORMCREATE + TPM20_TPMA_NV_WRITEDEFINE

//-----------------------------------------------------------------------------
//  AUX index
//
#define AUX_DATA_REV_MAJOR_30 03
#define AUX_DATA_REV_MAJOR_20 02
#define AUX_DATA_REV_MAJOR_10 01
#define AUX_DATA_REV_MINOR_00 00
//
// Inverted logic of EPS bit:
// EPS == 1 - de-asserted
// EPS == 0 - asserted
//
#define EPS BIT0

//#define AUX_DATA_REV_20_BIOSAC_REG_SIZE 32
#define AUX_DATA_BIOSAC_REGISTRATION_SIZE 20

typedef struct _ACM_AUX_REVOCATION {
  union {
    struct {
      UINT8 MinVer;
      UINT8 Flags;
    };
    UINT16 Val;
  };
} ACM_AUX_REVOCATION;

//
// BPT specific AUX data structures. Will use the same structure for
// TPM 1.2 and TPM 2.0 They are different in tyoes of fields but have
// identical layout.
//

//*****************************************************************************
//
// MUST DETERMINE BUFFER SIZE!. ALSO - CAN I REUSE BUFFERS?
// It must be 4KB for full TPM2 spec but since we are using subset of
// commands we might get away with smaller size.
//
//*****************************************************************************

#define TpmOutBuff TpmInBuff

//-----------------------------------------------------------------------------
// MMIO I/F related definitions
//-----------------------------------------------------------------------------
//
//TPM_STS_X (offset 0x1B - 0x18) defintion
//    31:28 Read Only	reserved	Reads alwaysreturn  0
//    27:26	Read Only	tpmFamily		TPM Family Identifier
//          00:  TPM 1.2 Family
//          01:  TPM 2.0 Family
//          10:  Reserved  future use
//          11:  Reserved for future use

typedef struct _TPM_FIFO {
  UINT8  TPM_ACCESS;          // OFF 0
  UINT8  R[FILL8(0x14, 0)];
  UINT32 TPM_INTF_CAPABILITY; // OFF 0x14
  UINT8  TPM_STS;             // OFF 0x18
  UINT16 TPM_BRST_CNT;        // OFF 0x19
  UINT8  R2[FILL8(0x24, 0x1A)];
  UINT8  TPM_DATA_FIFO[4];    // OFF 0x24
  UINT8  R3[FILL8(0x30, 0x27)];
  UINT32 TPM_INTERFACE_ID;    // OFF30
  UINT8  R4[FILL8(0x80, 0x33)];
  UINT8  TPM_XDATA_FIFO[64];  // OFF 0x80
  UINT8  R5[FILL8(0xF00, 0xBF)];
  UINT16 TPM_VID;             // OFF 0xF00
  UINT16 TPM_DID;             // OFF 0xF02
  UINT8  TPM_RID;             // OFF 0xF04
} TPM_FIFO;

typedef struct _REG_TPM_INTF_CAPABILITY {
  UINT32 Misc             : 8;
  UINT32 BurstCountStatic : 1; // 0 - dynamic; 1 - static
  //
  // DataTransferSizeSupport:
  //
  // 00 - legacy only
  // 01 - 8B
  // 10 - 32B
  // 11 - 64B
  UINT32 DataTransferSize : 2;
  UINT32 Res              : 17;
  UINT32 InterfaceVersion : 3; // 000 - 1.21 or before; 001 - 1.3
  UINT32 Res2             : 1;
} REG_TPM_INTF_CAPABILITY;

typedef struct _REG_TPM_ACCESS {
  UINT8 TpmEstablishment : 1;
  UINT8 RequestUse       : 1;
  UINT8 PendingRequest   : 1;
  UINT8 Seize            : 1;
  UINT8 BeenSeized       : 1;
  UINT8 ActiveLocality   : 1;
  UINT8 Reserved         : 1;
  UINT8 TmpRegValidSts   : 1;
} REG_TPM_ACCESS;

typedef struct _REG_TPM_STS {
  UINT8 Reserved      : 1;
  UINT8 ResponseRetry : 1;
  UINT8 SelfTestDone  : 1;
  UINT8 Expect        : 1;
  UINT8 DataAvail     : 1;
  UINT8 TpmGo         : 1;
  UINT8 CommandReady  : 1;
  UINT8 StsValid      : 1;
} REG_TPM_STS;

//-----------------------------------------------------------------------------
// CRB I/F related definitions
//-----------------------------------------------------------------------------

// typedef struct _TPM_CONTROL_AREA {
//   UINT32  Request;
//   UINT32  Status;
//   UINT32  Cancel;
//   UINT32  Start;
//   UINT64  R;
//   UINT32  CmdSize;
//   UINT64  CmdAddr;
//   UINT32  RspSize;
//   UINT64  RspAddr;
// } TPM_CONTROL_AREA;

#define TPMCRBBUF_LEN 3968

typedef struct _TPM_CRB {
  UINT32 TPM_LOC_STATE;                      // OFF 0
  UINT32 R1;
  UINT32 TPM_LOC_CTRL;                       // OFF 0x8
  UINT32 TPM_LOC_STS;                        // OFF 0xC
  UINT8  R2[FILL8(0x30, 0xF)];
  UINT64 TPM_CRB_INTF_ID;                    // OFF 0x30
  UINT64 TPM_CRB_CTRL_EXT;                   // OFF 0x38
  UINT32 TPM_CRB_CTRL_REQ;                   // OFF 0x40
  UINT32 TPM_CRB_CTRL_STS;                   // OFF 0x44
  UINT32 TPM_CRB_CTRL_CANCEL;                // OFF 0x48
  UINT32 TPM_CRB_CTRL_START;                 // OFF 0x4C
  UINT64 TPM_CRB_CTRL_INT;                   // OFF 0x50
  UINT32 TPM_CRB_CTRL_CMD_SIZE;              // OFF 0x58
  UINT32 TPM_CRB_CTRL_CMD_LADDR;             // OFF 0x5C
  UINT32 TPM_CRB_CTRL_CMD_HADDR;             // OFF 0x60
  UINT32 TPM_CRB_CTRL_RSP_SIZE;              // OFF 0x64
  UINT64 TPM_CRB_CTRL_RSP_ADDR;              // OFF 0x68
  UINT8  R3[FILL8(0x80, 0x6F)];
  UINT8  TPM_CRB_DATA_BUFFER[TPMCRBBUF_LEN]; // OFF 0x80
} TPM_CRB;

typedef struct {
  UINT32 TpmEstablishment : 1;
  UINT32 LocAssigned      : 1;
  UINT32 ActiveLocality   : 3;
  UINT32 R                : 2;
  UINT32 TpmRegValidSts   : 1;
  UINT32 R2               : 24;
} REG_TPM_LOC_STATE;

typedef struct {
  UINT32 RequestAccess         : 1;
  UINT32 Relinquish            : 1;
  UINT32 Seize                 : 1;
  UINT32 ResetEstablishmentBit : 1;
  UINT32 R2                    : 28;
} REG_TPM_LOC_CTRL;

typedef struct {
  UINT32 Granted    : 1;
  UINT32 BeenSeized : 1;
  UINT32 R          : 30;
} REG_TPM_LOC_STS;

typedef struct {
  UINT32 CmdReady : 1;
  UINT32 GoIdle   : 1;
  UINT32 R        : 30;
} REG_TPM_CRB_CTRL_REQ;

typedef struct {
  UINT32 TpmSts  : 1;
  UINT32 TpmIdle : 1;
  UINT32 R       : 30;
} REG_TPM_CRB_CTRL_STS;

typedef struct {
  UINT32 InterfaceType        : 4;  // [3:0]
  UINT32 InterfaceVersion     : 4;  // [7:4]
  UINT32 InterfaceCapLocality : 1;  // [8]
  UINT32 Res                  : 4;  // [12:9]
  UINT32 CapTIS               : 1;  // [13]
  UINT32 CapCRB               : 1;  // [14]
  UINT32 CapIFRes             : 2;  // [16:15]
  UINT32 InterfaceSelector    : 2;  // [18:17]
  UINT32 IntfSelLock          : 1;  // [19]
  UINT32 Res2                 : 12; // [31:20]
} REG_TPM_INTERFACE_ID;

//
// TPM capabiiies make flags
//
#ifndef MKF_CAP_TPM_FAM_20
#define MKF_CAP_TPM_FAM_20 1
#endif

#ifndef MKF_CAP_TPM_ITF_CRB
#define MKF_CAP_TPM_ITF_CRB 1
#endif

#ifndef MKF_CAP_TPM_ITF_FIFO
#define MKF_CAP_TPM_ITF_FIFO 1
#endif

typedef struct _TPM_CONTEXT {
  //
  // Possible width of data for single transfer: 64, 32, 8, 4, 2, 1
  //
  UINT8  DataWidth[6];
  UINT32 WidthStartIdx;
  UINT32 RetryCnt;
  UINT32 DataFifo;

  UINT32 TotalTransmitted;
  UINT32 CountRemaining;
  UINT32 BurstRemaining;

  UINT32 DrvCode;
  UINT32 TpmCode;
  UINT32 Family;
  UINT32 AuxIndexSize;
//  UINT32                                        RevocationSize;
  UINT32 Interface;
  UINT32 InterfaceVersion;
  UINT32 TpmType; //dTPM or FTPM
  UINT32 Flags;
  UINT32 Policy;
  UINT32 SvnControl;
  UINT8  TpmLocality;

  //
  // Family dependent functions.
  //
  VOID_ARG_UINT16 fpCoreTpmStartup;
  VOID_NO_ARG     fpCoreTpmDisable;
  //
  // Wrapper family dependent functions.
  //
  VOID_NO_ARG                                 fpCheckAuxProperties;
  VOID_NO_ARG                                 fpCheckPsProperties;
  VOID_NO_ARG                                 fpCheckPoProperties;
  VOID_NO_ARG                                 fpCheckTpmNvProperties;
  VOID_ARG_UINT32_UINT32_UINT32_PUINT8_UINT32 fpTpmNvReadValue;
  VOID_ARG_UINT32_UINT32_UINT32_PUINT8        fpTpmNvWriteValue;
  VOID_ARG_UINT32_PUINT8                      fpTpmPcrRead;
  VOID_NO_ARG                                 fpHandleLegacyPcrFormat;
  VOID_NO_ARG                                 fpHandleDetailAuthPcr17Format;
  VOID_NO_ARG                                 fpHandleDetailAuthPcr18Format;
  VOID_NO_ARG                                 fpTpmFamilySpecificInit;
  VOID_NO_ARG                                 fpVerifyHashStartPcrValue;
  VOID_NO_ARG                                 fpValidateEventLogHeader;
  VOID_NO_ARG                                 fpRecordLogEventHashStart;
  VOID_NO_ARG                                 fpRecordLogEventPcrMapping;
  VOID_NO_ARG                                 fpRefurbishAuxIndex;
  VOID_NO_ARG                                 fpSetAuxHashAlgId;
  VOID_NO_ARG                                 fpEventLogInit;
  //
  // Interface dependent functions.
  //
  VOID_NO_ARG       fpTpmCommand;
  VOID_ARG_UINT32   fpCoreRequestLocality;
  VOID_ARG_UINT32   fpCoreRelinquishLocality;
  UINT8_ARG_UINT32  fpCoreLocalityStatus;
  UINT32_ARG_UINT32 fpCoreWaitAccessValid;

  VOID_NO_ARG fpBtgHashandExtend;
  VOID_NO_ARG fpBtgScrtmExtend;

  UINT8_ARG_UINT32_UINT32_UINT32 fpCoreTpmNvReadValue;
} TPM_CONTEXT;
//
// Structure describing support of hash algorithms
//
#define HASH_ALG_ID_COUNT 5

typedef struct _HASH_ALG_ID_DESCR {
  UINT16 HashAlgId;
  UINT16 TpmSup : 1; // Alg is supported by TPM
  UINT16 PcrImp : 1; // PCR bank implemented
  UINT16 AcmSup : 1; // ACM implemented in SW
  UINT16 LcpSup : 1; // Alg is selecetd by LCP mask in PS/PO
  UINT16 Re     : 12;
}HASH_ALG_ID_DESCR;

#include <tpm20.h>

//
// Enough room to create 5 largest TPMT_HA digests.
//
typedef struct {
  UINT32 count;
  UINT8  data[(2 * HASH_ALG_ID_COUNT) +
              SHA1_DIGEST_SIZE + SM3_256_DIGEST_SIZE +
              SHA256_DIGEST_SIZE + SHA384_DIGEST_SIZE + SHA512_DIGEST_SIZE
  ];
} TPML_DIGEST_VALUES_MAX;

typedef struct {
  UINT32             count;
  TPMS_PCR_SELECTION pcrSelections[HASH_ALG_ID_COUNT];
} TPML_ACM_PCR_SELECTION;

typedef struct {
  ACM_AUX_REVOCATION SinitRevocation;
  ACM_AUX_REVOCATION BiosacRevocation;
} AUX_REVOCATION;

typedef struct {
  UINT32 Res;
  UINT32 AcmRevision;
  UINT16 ModuleID;
  UINT16 ModuleFlags;
  UINT16 AuxDataRev;
  UINT16 Res2;
  UINT32 Flags;
  UINT16 Res3;
  UINT16 REF_time;
  UINT8  KM_BPM_ID[4];
  union {
    struct {
      UINT16 HashAlgId;
      UINT8  McConfigHash[SHA256_DIGEST_SIZE];
      UINT32 McInputData;
    };
    TPMT_HA HashArea[];
  };
} AUX_DATA;

//
// The following is a chunk of AUX_DATA instantiated for SHA1
//
typedef struct {
  UINT32     KM_BPM_ID;
  TPM_ALG_ID hashAlg;
  UINT8      digest[SHA1_DIGEST_SIZE];
} AUX_MOULD;

typedef struct {
  AUX_REVOCATION AuxRevocation;
  AUX_DATA       AuxData;
} FULL_AUX_DATA;

typedef struct {
  TPM20_NVRead_Out Header;
  UINT16           dataSize;

  union {
    AUX_DATA data;
    UINT8    hash[AUX_DATA_BIOSAC_REGISTRATION_SIZE];
  };

  //   union {
  //     TPM20_COM_AUX_DATA  data;
  //     UINT8               hash[SHA256_DIGEST_SIZE];
  //     AUX_REVOCATION20    AuxRevocation;
  //   };
} TPM20_NV_ReadValue_Aux_Out;

//typedef TPMS_AUTH_COMMAND TPM_CMD_SESSION_DATA_IN;
//
// Structure for passing session data to commands that require it.
//
typedef struct {
  TPMI_SH_AUTH_SESSION sessionHandle;
  TPM2B_NONCE *        nonce;
  TPMA_SESSION         sessionAttributes;
  TPM2B_AUTH *         hmac;
} TPM_CMD_SESSION_DATA_IN;

typedef TPM2B_NV_PUBLIC TPM2B_MAX_NV_PUBLIC;

void Wait1ms();
void __Wait1ms();
UINT64 calibrateTsc64();

//void Tpm20EventUnifyDigests         (TPML_DIGEST_VALUES *);

// void Tpm20ExtendZeroDigest          (UINT32, TPML_DIGEST_VALUES_MAX *);

void BiosacTpmInterfaceInit();
void ClientBiosacTpmInterfaceInit();
void SinitTpmInterfaceInit();

void Tpm20NVWrite_PTT(TPMI_RH_NV_INDEX,
                      TPM2B_MAX_NV_BUFFER *,
                      UINT16);

void Tpm20NVWrite(TPMI_RH_NV_AUTH,
                  TPMI_RH_NV_INDEX,
                  TPM2B_MAX_NV_BUFFER *,
                  UINT16,
                  TPM_CMD_SESSION_DATA_IN *);

void Tpm20NVRead_PTT(TPMI_RH_NV_INDEX,
                     UINT16,
                     UINT16);

void Tpm20PcrExtend(TPMI_DH_PCR, TPML_DIGEST_VALUES *, TPM_CMD_SESSION_DATA_IN *);

void Tpm20PcrExtend(TPMI_DH_PCR,
                    TPML_DIGEST_VALUES *,
                    TPM_CMD_SESSION_DATA_IN *);

void Tpm20EventSequenceComplete(TPMI_DH_PCR pcrHandle,
                                TPMI_DH_OBJECT sequenceHandle,
                                TPM2B_MAX_BUFFER *buffer,
                                TPM_CMD_SESSION_DATA_IN *pcrHandleAuth,
                                TPM_CMD_SESSION_DATA_IN *sequenceHandleAuth);

void Tpm20PolicyPcr(TPMI_SH_POLICY,        /* in */
                    TPM2B_DIGEST *,        /* in */
                    TPML_PCR_SELECTION *); /* in */

void Tpm20PcrEvent(TPMI_DH_PCR,
                   TPM2B_EVENT *,
                   TPM_CMD_SESSION_DATA_IN *);

void Tpm20StartAuthSession(TPMI_DH_OBJECT,
                           TPMI_DH_ENTITY,
                           TPM2B_NONCE *,
                           TPM2B_ENCRYPTED_SECRET *,
                           TPM_SE,
                           TPMT_SYM_DEF *,
                           TPMI_ALG_HASH);

void Tpm20NVRead(TPMI_RH_NV_AUTH,
                 TPMI_RH_NV_INDEX,
                 UINT16,
                 UINT16,
                 TPM_CMD_SESSION_DATA_IN *);

void Tpm20HierarchyControl(
  TPMI_RH_CLEAR,
  TPMI_RH_HIERARCHY,
  TPMI_YES_NO,
  TPM_CMD_SESSION_DATA_IN *);

void CopySessionData_LE_To_BE_Canonical(void **,
                                        TPM_CMD_SESSION_DATA_IN *,
                                        UINT32 *);

#if     MCP_PLATFORM_TYPE == CLIENT

#if     MCP_CHIPSET_ACM_TYPE == AC_SINIT
#define HookModuleSpecificTpmInterfaceInit SinitTpmInterfaceInit
#else
#define HookModuleSpecificTpmInterfaceInit ClientBiosacTpmInterfaceInit
#endif

#else

#if     MCP_CHIPSET_ACM_TYPE == AC_SINIT
#define HookModuleSpecificTpmInterfaceInit SinitTpmInterfaceInit
#else
#define HookModuleSpecificTpmInterfaceInit BiosacTpmInterfaceInit
#endif

#endif

extern UINT8 TpmInBuff[];
extern UINT8 TpmOutBuff[];
extern UINT32 ContractPolicy;
extern TPM_CONTEXT TpmCtx;
extern UINT32 IndexLcpOwn;
extern UINT32 IndexAux;
extern HASH_ALG_ID_DESCR HashAlgIdList[HASH_ALG_ID_COUNT];

extern UINT32 PcrMapping;
extern TPML_DIGEST PolicyOrDigests384;
extern TPML_DIGEST PolicyOrDigests256;
extern TPML_DIGEST PolicyOrDigestsSm3;

extern TPM2B_AUTH auth;
extern TPMI_DH_OBJECT sequenceHandle;

extern UINT16 Tpm20AuxIndexNameAlgorithm;
extern UINT32 AuxMcHashAlgId;
extern UINT32 AuxMcConfigHashOff;

extern UINT8 TpmPresent;
extern UINT8 *AuxWritePolicyDigests[];

#endif
