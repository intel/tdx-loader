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
#include <header.h>
#include <PSeamldrSize.h>

#pragma optimize( "", off )

#pragma data_seg("ADATA32")
#pragma bss_seg("ADATA32")
#pragma const_seg("ADATA32")

#ifdef _MSC_VER
#define FORCE_ALIGN __declspec(align(4))
#else
#define FORCE_ALIGN
#endif

//
// Compute offset to start of ChipsetIdTbl
//
#define CHIPSET_ID_TBL_OFF sizeof(ACM_HEADER) + \
  sizeof(ACM_INFO_TABLE)
//
// Compute offset to start of ProcessorIdTbl
//
#define PROCESSOR_ID_TBL_OFF  CHIPSET_ID_TBL_OFF + \
  sizeof(ACM_CHIPSET_ID_TBL) + \
  CHIPSET_ID_COUNT * sizeof(ACM_CHIPSET_ID)

#define TPM_INFO_LIST_OFF     PROCESSOR_ID_TBL_OFF + \
  sizeof(ACM_PROCESSOR_ID_TBL) + \
  PROCESSOR_ID_COUNT * sizeof(ACM_PROCESSOR_ID)

#define GEN_CORE_VER_LIST_OFF TPM_INFO_LIST_OFF + \
  sizeof(ACM_TPM_CAPABILITIES_TBL) + \
  ALG_ID_COUNT * sizeof(UINT16)

ACM_HEADER HeaderStart = {
  MCP_MODULE_TYPE,
  MCP_MODULE_SUBTYPE,
  HEADER_INIT_1,
  MCP_MODULE_ID,
  MCP_MODULE_FLAGS,
  HEADER_INIT_2,
  MCP_ACM_SVN,
  MCP_SE_SVN,
  HEADER_INIT_3,
  GDT_SIZE,
  (UINT32) &GdtBasePtr,
  ACM_CODE_SELECTOR,
  (UINT32)AcmEntryPoint,
  HEADER_INIT_4
};

//
// ACM Info Table start
//
ACM_INFO_TABLE AcmInfoTableStart = {
  INFO_TAB_INIT_1,
  MCP_CHIPSET_ACM_TYPE,
  ACM_INFO_TAB_VER,
  INFO_TAB_INIT_2,
  CHIPSET_ID_TBL_OFF,
  OS_SINIT_TAB_VER,
  MIN_MLE_HEADER_VER,
  MCP_ACM_CAPABILITIES,
  MCP_ACM_VER,
  MCP_ACM_REVISION,
  PROCESSOR_ID_TBL_OFF,
  TPM_INFO_LIST_OFF,
  GEN_CORE_VER_LIST_OFF,
};

__declspec(align(2))
ACM_GEN_CORE_VER_INFO_TBL GenCoreVersionInfoTbl = {
  MCP_PLAT_PHASE,
  ACM_GEN_VERSION,
  ACM_CORE_VERSION,
};

//
// Chipset ID table start
//
ACM_CHIPSET_ID_TBL ChipsetIdTbl = {
  CHIPSET_ID_COUNT,
  {
    {
      MF_REVID_MASK_1,
      0x8086,
      MF_DEVICE_ID_1,
      MF_REVISION_ID_1,
      00,
      00
    } // 1st CS supported
#if (MF_CS_PRESENT_2)
    ,
    {
      MF_REVID_MASK_2,
      0x8086,
      MF_DEVICE_ID_2,
      MF_REVISION_ID_2,
      00,
      00
    } // 2nd CS supported
#endif
#if (MF_CS_PRESENT_3)
    ,
    {
      MF_REVID_MASK_3,
      0x8086,
      MF_DEVICE_ID_3,
      MF_REVISION_ID_3,
      00,
      00
    } // 3rd CS supported
#endif
#if (MF_CS_PRESENT_4)
    ,
    {
      MF_REVID_MASK_4,
      0x8086,
      MF_DEVICE_ID_4,
      MF_REVISION_ID_4,
      00,
      00
    } // 4th CS supported
#endif
  }
};

//
// Processor ID table start
//
FORCE_ALIGN
ACM_PROCESSOR_ID_TBL ProcessorIdTbl = {
  PROCESSOR_ID_COUNT,
  {
    {
      MF_FMS_1,
      MF_FMS_MASK_1,
      PLATFORM_ID_1,
      PLATFORM_ID_MASK_1
    } //1st Processor supported
#if (MF_PROC_PRESENT_2)
    ,
    {
      MF_FMS_2,
      MF_FMS_MASK_2,
      PLATFORM_ID_2,
      PLATFORM_ID_MASK_2 //2nd Processor supported
    }
#endif
#if (MF_PROC_PRESENT_3)
    ,
    {
      MF_FMS_3,
      MF_FMS_MASK_3,
      PLATFORM_ID_3,
      PLATFORM_ID_MASK_3 //3rd Processor supported
    }
#endif
#if (MF_PROC_PRESENT_4)
    ,
    {
      MF_FMS_4,
      MF_FMS_MASK_4,
      PLATFORM_ID_4,
      PLATFORM_ID_MASK_4 //4th Processor supported
    }
#endif
#if (MF_PROC_PRESENT_5)
    ,
    {
      MF_FMS_5,
      MF_FMS_MASK_5,
      PLATFORM_ID_5,
      PLATFORM_ID_MASK_5 //4th Processor supported
    }
#endif
  }
};

ACM_TPM_CAPABILITIES_TBL TpmCapabilitiesTbl = {
  MCP_ACM_TPM_CAPABILITIES,
  ALG_ID_COUNT,
#if (MF_ALG_SHA1_PRESENT)
  TPM_ALG_SHA1,
#endif
#if (MF_ALG_SHA256_PRESENT)
  TPM_ALG_SHA256,
#endif
#if (MF_ALG_SHA384_PRESENT)
  TPM_ALG_SHA384,
#endif
#if (MF_ALG_SHA512_PRESENT)
  TPM_ALG_SHA512,
#endif
#if (MF_ALG_SM3_256_PRESENT)
  TPM_ALG_SM3_256,
#endif
#if (MF_ALG_RSASSA_PRESENT)
  TPM_ALG_RSASSA,
#endif
#if (MF_ALG_RSAPSS_PRESENT)
  TPM_ALG_RSAPSS,
#endif
#if (MF_ALG_ECDSA_PRESENT)
  TPM_ALG_ECDSA,
#endif
#if (MF_ALG_SM2_PRESENT)
  TPM_ALG_SM2,
#endif
};
