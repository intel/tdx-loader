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

#ifndef HEADER_H
#define HEADER_H
#pragma pack (1)
#include <basic_defs.h>

#define REVISION_ID_MASK 1

typedef struct _ACM_CHIPSET_ID {
  UINT32 dFlags;
  UINT16 wVendorId;
  UINT16 wDeviceId;
  UINT16 wRevisionId;
  UINT16 wReserved;
  UINT32 dReserved;
} ACM_CHIPSET_ID;

typedef struct {
  UINT32         ChipsetIdCount;
  ACM_CHIPSET_ID ChipsetIdArray[];
} ACM_CHIPSET_ID_TBL;

typedef struct _ACM_PROCESSOR_ID {
  UINT32 dFMS;
  UINT32 dFMSMask;
  UINT64 qPlatformID;
  UINT64 qPlatformMask;
} ACM_PROCESSOR_ID;

typedef struct {
  UINT32           ProcessorIdCount;
  ACM_PROCESSOR_ID ProcessorIdArray[];
} ACM_PROCESSOR_ID_TBL;

typedef struct {
  UINT32 TpmCapabilities;
  UINT16 AlgIdCount;
  UINT16 AlgIdArray[];
} ACM_TPM_CAPABILITIES_TBL;

typedef struct P_SEAMLDR_CONSTS {
  UINT64 CDataStackSize;
  UINT64 CCodeRgnSize;
  UINT64 CDataRgnSize;
  UINT64 CKeyholeRgnSize;
  UINT64 CKeyholeEditRgnSize;
  UINT64 CEntryPointOffset;
} P_SEAMLDR_CONSTS_t;
typedef struct {
  UINT8  platformPhase;
  UINT16 genVersion;
  UINT8  coreVersion[];
} ACM_GEN_CORE_VER_INFO_TBL;

#define CPU_MODULE_TYPE       1
#define CS_MODULE_TYPE        2

#define CLIENT_MODULE_SUBTYPE 0
#define LTSX_MODULE_SUBTYPE   1

#define DUAL_SIGNED_EN        1

//
// Header length + header version
//
#define HEADER_0_INIT_1 {161, 0}
#define HEADER_3_INIT_1 {224, 0x30000}
#define HEADER_4_INIT_1 {928, 0x40000}

//
// Module vendor + Date + Module size (in DW)
//
#define HEADER_INIT_2 {0x8086, 0, 0x620}

//
// Code control + Error entry point.
//
#define HEADER_INIT_3 {00, 00}

//
// Reserved2 + KeySize + ScratchSize + Rsa3072PubKey + Rsa3072Sig +
// scratch
//
#define HEADER_0_INIT_4 {{0}, 64, 143}
#define HEADER_3_INIT_4 {{0}, 96, 208, {0}, {0}, {0}}
#define HEADER_4_INIT_4 {{0}, 96, 896, {0}, {0}, {0}, {0}, {0}, {0}}

#ifndef MF_CS_PRESENT_2
#define MF_CS_PRESENT_2 0
#endif

#ifndef MF_CS_PRESENT_3
#define MF_CS_PRESENT_3 0
#endif

#ifndef MF_CS_PRESENT_4
#define MF_CS_PRESENT_4 0
#endif

#ifndef MF_PROC_PRESENT_2
#define MF_PROC_PRESENT_2 0
#endif

#ifndef MF_PROC_PRESENT_3
#define MF_PROC_PRESENT_3 0
#endif

#ifndef MF_PROC_PRESENT_4
#define MF_PROC_PRESENT_4 0
#endif

#ifndef MF_PROC_PRESENT_5 // Sighting #3865449
#define MF_PROC_PRESENT_5 0
#endif

#ifndef MF_ALG_SHA1_PRESENT
#define MF_ALG_SHA1_PRESENT 0
#endif

#ifndef MF_ALG_SHA256_PRESENT
#define MF_ALG_SHA256_PRESENT 0
#endif

#ifndef MF_ALG_SHA384_PRESENT
#define MF_ALG_SHA384_PRESENT 0
#endif

#ifndef MF_ALG_SHA512_PRESENT
#define MF_ALG_SHA512_PRESENT 0
#endif

#ifndef MF_ALG_SM3_256_PRESENT
#define MF_ALG_SM3_256_PRESENT 0
#endif

#ifndef MF_ALG_RSASSA_PRESENT
#define MF_ALG_RSASSA_PRESENT 0
#endif

#ifndef MF_ALG_RSAPSS_PRESENT
#define MF_ALG_RSAPSS_PRESENT 0
#endif

#ifndef MF_ALG_ECDSA_PRESENT
#define MF_ALG_ECDSA_PRESENT 0
#endif

#ifndef MF_ALG_SM2_PRESENT
#define MF_ALG_SM2_PRESENT 0
#endif

#define CHIPSET_ID_COUNT                    (MF_CS_PRESENT_1 + MF_CS_PRESENT_2 + \
                                             MF_CS_PRESENT_3 + MF_CS_PRESENT_4)                         // Number of entries in array of ProcessorIDs
#define PROCESSOR_ID_COUNT                  (MF_PROC_PRESENT_1 + MF_PROC_PRESENT_2 + \
                                             MF_PROC_PRESENT_3 + MF_PROC_PRESENT_4 + MF_PROC_PRESENT_5) // Number of entries in array of ProcessorIDs

#define ALG_ID_COUNT                        (MF_ALG_SHA1_PRESENT + MF_ALG_SHA256_PRESENT + \
                                             MF_ALG_SHA384_PRESENT + MF_ALG_SHA512_PRESENT + \
                                             MF_ALG_SM3_256_PRESENT + MF_ALG_RSASSA_PRESENT + \
                                             MF_ALG_ECDSA_PRESENT + MF_ALG_SM2_PRESENT + MF_ALG_RSAPSS_PRESENT)

#define ACM_TPM_CAP_EXTEND_POLICY_ALG_AGILE BIT0
#define ACM_TPM_CAP_EXTEND_POLICY_SW_EMBED  BIT1
#define ACM_TPM_CAP_DTPM_FAM12_SUPPORT      BIT2
#define ACM_TPM_CAP_DTPM_FAM20_SUPPORT      BIT3
#define ACM_TPM_CAP_PTT_FAM20_SUPPORT       BIT5
#define ACM_TPM_CAP_TCG_IDX_SET             BIT6

#define ACM_GEN_VERSION                     0x2
#define ACM_CORE_VERSION                    {1, 1, 0}

typedef struct {
  UINT16 ModuleType;
  UINT16 ModuleSubType;
  struct {
    UINT32 HeaderLen;
    UINT32 HeaderVersion;
  };
  UINT16 ModuleID;
  UINT16 ModuleFlags;
  struct {
    UINT32 ModuleVendor;
    UINT32 Revision;
    UINT32 Sizeb;
  };
  UINT16 AcmSvn;
  UINT16 SeSvn;

  struct {
    UINT32 CodeControl;
    UINT32 ErrorEntryPoint;
  };
  UINT32 GDTSize;
  UINT32 GDTBasePtr;
  UINT32 SegSel;
  UINT32 EntryPoint;
  struct {
    UINT8  Reserved2[64];
    UINT32 KeySize;     // 64 DWORDS in the Key
    UINT32 ScratchSize; // 143 DWORDS = Sractch Size
    UINT8  RSA2048PubKey[256];
    UINT32 PubExp;
    UINT8  RSA2048Sig[256];
    UINT8  scratch[572];
  };
} ACM_HEADER_0;

typedef struct {
  UINT16 ModuleType;
  UINT16 ModuleSubType;
  struct {
    UINT32 HeaderLen;
    UINT32 HeaderVersion;
  };
  UINT16 ModuleID;
  UINT16 ModuleFlags;
  struct {
    UINT32 ModuleVendor;
    UINT32 Revision;
    UINT32 Sizeb;
  };
  UINT16 AcmSvn;
  UINT16 SeSvn;
  struct {
    UINT32 CodeControl;
    UINT32 ErrorEntryPoint;
  };
  UINT32 GDTSize;
  UINT32 GDTBasePtr;
  UINT32 SegSel;
  UINT32 EntryPoint;
  struct {
    UINT8  Reserved2[64];
    UINT32 KeySize;     // 96 DWORDS in the Key
    UINT32 ScratchSize; // 208 DWORDS = 832 BYTES Sractch Size
    UINT8  RSA3072PubKey[384];
    UINT8  RSA3072Sig[384];
    UINT8  scratch[832];
  };
} ACM_HEADER_3;

typedef struct {
  UINT16 ModuleType;
  UINT16 ModuleSubType;
  struct {
    UINT32 HeaderLen;
    UINT32 HeaderVersion;
  };
  UINT16 ModuleID;
  UINT16 ModuleFlags;
  struct {
    UINT32 ModuleVendor;
    UINT32 Revision;
    UINT32 Sizeb;
  };
  UINT16 AcmSvn;
  UINT16 SeSvn;
  struct {
    UINT32 CodeControl;
    UINT32 ErrorEntryPoint;
  };
  UINT32 GDTSize;
  UINT32 GDTBasePtr;
  UINT32 SegSel;
  UINT32 EntryPoint;
  struct {
    UINT8  Reserved2[64];
    UINT32 KeySize;     // 96 DWORDS in the Key
    UINT32 ScratchSize; // 208 DWORDS = 832 BYTES Sractch Size
    UINT8  RSA3072PubKey[384];
    UINT8  RSA3072Sig[384];

    UINT8 XMSSPubKey[64];
    UINT8 XMSSSig[2692];
    UINT8 Reserved3[60];
    UINT8 scratch[3584];
  };
} ACM_HEADER_4;

#define ACM_HEADER_V4 0x40000
#define ACM_HEADER_V3 0x30000
#define ACM_HEADER_V0 0x0

typedef struct {
  UINT16 ModuleType;
  UINT16 ModuleSubType;
  UINT32 HeaderLen;
  UINT32 HeaderVersion;
  UINT16 ModuleID;
  UINT16 ModuleFlags;
  UINT32 ModuleVendor;
  UINT32 Revision;
  UINT32 Sizeb;
  UINT16 AcmSvn;
  UINT16 SeSvn;
  UINT32 CodeControl;
  UINT32 ErrorEntryPoint;
  UINT32 GDTSize;
  UINT32 GDTBasePtr;
  UINT32 SegSel;
  UINT32 EntryPoint;
  UINT8  Reserved2[64];
  UINT32 KeySize;
  UINT32 ScratchSize;
  UINT8 *RSAPubKeyAddr;
  UINT8 *RSASigAddr;
  UINT8 *XMSSPubKeyAddr;
  UINT8 *XMSSSigAddr;
  UINT8 *scratchAddr;
} ACM_HEADER_DATA;

#ifndef MF_HEADER_VERSION
  #define MF_HEADER_VERSION ACM_HEADER_V_3
#endif

#if MF_HEADER_VERSION == ACM_HEADER_V_0
  #define ACM_HEADER    ACM_HEADER_0
  #define HEADER_INIT_1 HEADER_0_INIT_1
  #define HEADER_INIT_4 HEADER_0_INIT_4
#elif MF_HEADER_VERSION == ACM_HEADER_V_3
  #define ACM_HEADER    ACM_HEADER_3
  #define HEADER_INIT_1 HEADER_3_INIT_1
  #define HEADER_INIT_4 HEADER_3_INIT_4
#else
  #define ACM_HEADER    ACM_HEADER_4
  #define HEADER_INIT_1 HEADER_4_INIT_1
  #define HEADER_INIT_4 HEADER_4_INIT_4
#endif

typedef struct {
  struct {
    UINT32 ACM_UUID0;
    UINT32 ACM_UUID1;
    UINT32 ACM_UUID2;
    UINT32 ACM_UUID3;
  };
  UINT8  ChipsetAcmType;
  UINT8  AitVersion;
  UINT16 AitLength;
  UINT32 ChipsetIdList;
  UINT32 OsSinitTblVer;
  UINT32 MinMLEHeaderVer;
  UINT32 SINITCaps;
  UINT8  SINITVersion;
  UINT8  AitRevision[3];
  UINT32 ProcessorIDList;
  UINT32 TpmInfoList;
  UINT32 GenCoreVersion;
} ACM_INFO_TABLE;

#define INFO_TAB_INIT_1 {0x7FC03AAA, 0x18DB46a7, 0x8F69AC2E, 0x5A7F418D}
#define INFO_TAB_INIT_2 sizeof(ACM_INFO_TABLE)

typedef struct _IDT32GATE {
  UINT16 Off15_0;
  UINT16 Sel;
  UINT16 Attr;
  UINT16 Off31_16;
} IDT32GATE;

#define IDT32GATE_INIT_1 0x8E00

typedef union {
  struct _GDT32DESCRIPTOR {
    UINT16 Limit15_0;
    UINT8  Base23_0[3];
    UINT8  Attr;
    UINT8  Attr_Limit19_16;
    UINT8  Base31_24;
  };
  UINT64 Raw;
} GDT32DESCRIPTOR;

typedef struct _GDT {
  GDT32DESCRIPTOR NullDescriptor;
  GDT32DESCRIPTOR AcmCodeDescriptor;
  GDT32DESCRIPTOR AcmDataDescriptor;
  GDT32DESCRIPTOR AcmCode64Descriptor;
} GDT;

#define ACM_CODE_SELECTOR   8
#define ACM_DATA_SELECTOR   16
#define ACM_CODE64_SELECTOR 24
#define GDT_SIZE            32

extern UINT32 AcmBase;
extern UINT32 HeaderOffset;
extern UINT32 AcmSize;
extern UINT32 AcmTop;
extern UINT64 OriginalIDTR;
extern UINT16 OriginalIDTRLimit;
extern UINT32 OriginalEIP;
extern UINT32 OriginalEAX;
extern UINT32 OriginalECX;
extern UINT32 OriginalESI;
extern UINT32 OriginalEDI;
extern UINT32 OriginalEDX;
extern UINT32 OriginalCR3;
extern UINT32 OriginalCR0;
extern UINT32 OriginalCR4;
extern UINT16 OriginalES;
extern UINT16 OriginalFS;
extern UINT16 OriginalGS;
extern UINT16 OriginalSS;
extern ACM_HEADER HeaderStart;
extern ACM_INFO_TABLE AcmInfoTableStart;
extern GDT GdtBasePtr;
extern ACM_CHIPSET_ID_TBL ChipsetIdTbl;
extern ACM_PROCESSOR_ID_TBL ProcessorIdTbl;
extern ACM_TPM_CAPABILITIES_TBL TpmCapabilitiesTbl;
extern ACM_GEN_CORE_VER_INFO_TBL GenCoreVersionInfoTbl;
extern P_SEAMLDR_CONSTS_t PSeamldrConstAsm;
extern UINT32 PSeamldrSizeAsm;
extern UINT8 PSeamldrAsm[];
extern ACM_HEADER_DATA HeaderData;
#ifdef MKF_DUAL_SIGNING_EN
UINT32 PlatformGetAcmHeaderOffset();
#endif

#pragma pack ()
#endif
