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

#ifndef ACMERR_H_
#define ACMERR_H_

//*****************************************************************************
//
// Common AC_ENTRY errors
//
//*****************************************************************************

#define CLASS_ACM_PROGRESS 0x00

#define CLASS_ACM_ENTRY    0x1
enum ENUM_ACM_ENTRY {
  ERR_LAUNCH      = 0x1,                  //Error in ACM entry conditions
  ERR_NEM_ENABLED = 0x2,                  //No Eviction Mode is enabled
  ERR_CPU_LT_TYPE = 0x3,                  //CPU type as indicated by BIT34
                                          //of MSR 0x13A mismatches platform
                                          //type (client / server)
  ERR_DEV_ID = 0x4,                       //Platform hub as indicated by
                                          //device ID is not supported
  ERR_CPU_ID = 0x5,                       //CPU type as indicated by
                                          //Family/Model/Stepping is not
                                          //supported
  ERR_NO_UCODE_UPDATE = 0x6,              //Microcode update patch is not
                                          //loaded
  ERR_DEBUG_MCU = 0x7,                    //Debug microcode update patch is
                                          //forbidden for module kind
  ERR_DMI_LINK_DOWN  = 0x8,               //DMI link is determined down
  ERR_ACM_REVOKED    = 0x9,               //ACM is revoked
  ERR_TPM_DOUBLE_AUX = 0xA,               //Two AUX indices are detected
                                          //with handles 0x50000002 and
                                          //0x50000003
  ERR_FIT_POLICY   = 0xB,
  ERR_ORIGINAL_EIP = 0xC,                 //Address of launching GETSEC
                                          //instruction is too close to code
                                          //segment limit
  ERR_DBG_INTRF_ENABLED = 0xD,            //Debug Interface MSR 0xC80 is
                                          //either enabled or not locked
  ERR_PW_PS2_WRITELOCK = 0xE,             //Production Module and PS index
                                          //attribute indicates it isn't
                                          //locked
  ERR_CONFIG_LOCKCONFIG           = 0xF,  //lock config error occured
  ERR_SACM_FAIL                   = 0x10, // startup ACM failed
  ERR_ACM_FATAL                   = 0x11, // fatal ACM error
  ERR_CPU_PCH_MISMATCH            = 0x12, // CPU and PCH mismatch
  ERR_DUAL_SIGNED_HEADER_MISMATCH = 0x13, //Dual-signed ACM has different
                                          //values for SVNs/Module IDs
                                          //etc in top/bottom headers
  ERR_INVALID_HEADER      = 0x14,         // Invalid header
  ERR_PROBE_MODE_OCCURRED = 0x15,         // Probe mode error occured
};
//
// Minor error codes for ERR_LAUNCH
//
enum ENUM_ERR_LAUNCH {
  ERR_LAUNCH_PARAM = 0x1,  //Reserved bits in launch parameter (EDX/EDI)
                           //must be clear Second line comment  Third line
                           //comment
  ERR_LAUNCH_LEAF   = 0x2, //BIOSAC entered not via GETSEC.ENTERACCS
  ERR_LAUNCH_SENTER = 0x3, //BIOSAC entered via GETSEC.SENTER or SINIT
                           //entered via GETSEC.ENTERACCS
  ERR_LAUNCH_MEASUR = 0x4, //Startup ACM failed as indicated by SPAD
                           //register BIT32 & BIT62
};

//
// Minor error codes for ERR_ACM_FATAL
//
enum ENUM_ERR_ACM_FATAL {
  ERR_PCH_DWR = 0x1
};

//-----------------------------------------------------------------------------
//
//Common MTRR errors
//-----------------------------------------------------------------------------
#define CLASS_MTRR_CHECK 0x2
enum ENUM_MTRR_CHECK {
  ERR_RULE1 = 0x1, //One of the following errors: variable MTRRs are
                   //disabled fixed MTRRs are enabled default memory type
                   //is not UC
  ERR_RULE2 = 0x2, //Not all enabled variable MTRRs have memory type WB
  ERR_RULE3 = 0x3, //Enabled variable MTRRs overlap
  ERR_RULE4 = 0x4, //Base of one of enabled variable MTRRs is not size
                   //aligned
  ERR_RULE5 = 0x5, //Enabled variable MTRRs cover more than ACM size
                   //rounded up to the next 4KB
  ERR_RULE6 = 0x6, //There are gaps between enabled variable MTRRs
  ERR_MASK  = 0x7, //High bits of MTRR mask (BIT32+) are Incorrect
  ERR_MAP   = 0x8, //ACM overlaps LT register space
  ERR_COUNT = 0x9, //Internal error. Too many MTRRs detected - cannot
                   //handle
};

//-----------------------------------------------------------------------------
//
// Range checking service errors
//-----------------------------------------------------------------------------
#define CLASS_RANGE_CHECK 0x3
enum ENUM_RANGE_CHECK {
  ERR_BASIC_RANGE_CHECK = 0x1,                  //One of ranges in array failed the check:
                                                //alignment is incorrect top address is
                                                //below base Range placement is incorrect
                                                //as required by its attributes
  ERR_RANGE_OVERLAPPING = 0x2,                  //One or several ranges in array overlap
  ERR_RANGE_SEQUENCE    = 0x3,                  //Ranges are not located in required
                                                //sequence
  ERR_RANGE_NOT_CONTAINED                = 0x4,
  ERR_RANGE_NOT_IDENTICAL_ACROSS_SOCKETS = 0x5, //Range not identical across sockets
};

//
// Minor error codes for ERR_BASIC_RANGE_CHECK and ERR_RANGE_OVERLAPPING
//
enum ENUM_ERR_BASIC_RANGE_CHECK {
  ERR_DMAR_TAB     = 0x1,
  ERR_OSSINIT_TAB  = 0x2,
  ERR_LAPIC        = 0x3,
  ERR_PMR          = 0x4,
  ERR_PRIMARY      = 0x5,
  ERR_SECONDARY    = 0x6,
  ERR_VTD_IA_EXC   = 0x7,
  ERR_VTD_GT_EXC   = 0x8,
  ERR_ACPI_TAB     = 0x9,
  ERR_MLE_PD_PAGE1 = 0xA,
  ERR_MLE_PD_PAGE2 = 0xB,
  ERR_MLE_PT_PAGE  = 0xC,
  ERR_MLE_PAGE     = 0xD,
  ERR_OSMLE_TAB    = 0xE,
};

//
// Minor error codes for ERR_RANGE_SEQUENCE
//
enum ENUM_ERR_RANGE_SEQUENCE {
  ERR_DRAM_LO = 0x1,
  ERR_DRAM_HI = 0x2,
  ERR_TOUUD   = 0x3,
};

//
// Minor error codes for ERR_RANGE_NOT_CONTAINED
//
enum ENUM_ERR_RANGE_NOT_CONTAINED {
  ERR_IA_EXC      = 0x1,
  ERR_GT_EXC      = 0x2,
  ERR_GT_EXC_TSEG = 0x3,
  ERR_GT_EXC_DPR  = 0x4,
  ERR_GT_EXC_SGX  = 0x5,
};

//-----------------------------------------------------------------------------
//
// TPM errors
//-----------------------------------------------------------------------------
#define CLASS_TPM_ACCESS 0x4
enum ENUM_TPM_ACCESS {
  ERR_OK,        // Indicator of successful execution of the function.
  ERR_TPM_ERROR, // TPM returned an error
  ERR_LOCALITY,
  ERR_ACC_INVLD,
  ERR_NV_UNLOCKED,                    // TPM NV RAM not locked
  ERR_TPM_DISABLED,                   // TPM is disabled
  ERR_TPM_DEACTIVATED,                // TPM is deactivated
  ERR_TPM_NV_INDEX_INVALID,           // TPM NV indices incorrectly defined
  ERR_TPM_INCOMPAT_BIOSAC,            // Incompatible BIOS ACM
  ERR_TPM_INCOMPAT_AUXREV,            // Incompatible AUX revision.
  ERR_TPM_INBUF_TOO_SHORT,            // Input buffer is too short.
  ERR_TPM_OUTBUF_TOO_SHORT,           // Output buffer is too short.
  ERR_SECRETS_BIT_SET,                // Secrets bit is set.
  ERR_INTRF_NOT_SUP,                  // Interface is not supported
  ERR_FAMILY_NOT_SUP,                 // Family is not supported
  ERR_BANK_COUNT,                     // Too many banks := 3
  ERR_ALG_NOT_SUPPORTED,              // Mandatory hashing algorithm not supported
  ERR_TPM_NV_INDEX_RO,                // Read only index.
  ERR_TPM_NV_DATA_SIZE_OVER,          // Read only index.
  ERR_NO_TPM_PRESENT,                 // TPM not found
  ERR_PCR_BANKS_NOT_SUPPORTED,        // Embedded SW policy is selected
                                      // but implemented PCR banks
                                      // are not supported by ACM SW
  ERR_SCRTM_FAILED,                   // ACM attempted measurement from Locality 3 but failed
                                      // ACM must reset and restart TPM from Locality 0
                                      // This error must be set in CRASH register not BIOSACM register
  /*
   * //
   * // Errors returned by TPM driver
   * //
   * //ERR_ACCESS_PM_TIMER = 0x1A,           // PM timer base is not programmed.
   */
  ERR_OUTPUT_BUFFER_TOO_SHORT = 0x1B, // Output buffer for the TPM response to short.
  ERR_INVALID_INPUT_PARA      = 0x1C, // Input parameter for the function invalid.
  ERR_INVALID_RESPONSE_WR     = 0x1D, // Exhausted retry attempts during command reception.
  ERR_INVALID_RESPONSE_RD     = 0x1E, // Exhausted retry attempts during command completion.
  ERR_RESPONSE_TIMEOUT        = 0x1F, // Time out for TPM response.
  ERR_OVER_UNDER_RUN          = 0x1A  // Broken handshaking of last byte - this error is never returned.
};

//
// Minor error codes for ERR_ACC_INVLD
//
enum ENUM_ERR_ACC_INVLD {
  ERR_ACC_INVLD_0_ON   = 0x1, //Request to activate locality 0 failed
  ERR_ACC_INVLD_0_OF   = 0x2, //Request to relinquish locality 0 failed
  ERR_ACC_INVLD_GEN_ON = 0x3, //Request to activate any locality failed
  ERR_ACC_INVLD_GEN_OF = 0x4, //Request to relinquish any locality failed
  ERR_ACC_INVLD_3_ON   = 0x5, //Request to activate locality 3 failed
  ERR_ACC_INVLD_3_OF   = 0x6, //Request to relinquish locality 3 failed
};

//
// Minor error codes for ERR_TPM_NV_INDEX_INVALID
//
enum ENUM_ERR_TPM_NV_INDEX_INVALID {
  ERR_TPM_NV_INDEX_INVALID_AUX = 0x1,         //One or more of TPM AUX
                                              //index properties are
                                              //incorrect: localities
                                              //attributes or index size
  ERR_TPM_NV_INDEX_INVALID_AUX_ATTR = 0x2,    //TPM AUX index attributes
                                              //incorrect
  ERR_TPM_NV_INDEX_INVALID_AUX_ALG = 0x3,     //TPM AUX index nameAlg
                                              //incorrect
  ERR_TPM_NV_INDEX_INVALID_AUX_POL_SZ = 0x4,  //TPM AUX index policy digest
                                              //size is incorrect
  ERR_TPM_NV_INDEX_INVALID_AUX_POL_VAL = 0x5, //TPM AUX index policy digest
                                              //value is incorrect
  ERR_TPM_NV_INDEX_INVALID_AUX_SIZE = 0x6,    //TPM AUX index data size is
                                              //incorrect
  ERR_TPM_NV_INDEX_INVALID_PO = 0x7,          //One or more of TPM PO index
                                              //properties are incorrect:
                                              //localities attributes or
                                              //index size
  ERR_TPM_NV_INDEX_INVALID_PO_ATTR = 0x8,     //TPM PO index attributes
                                              //incorrect
  ERR_TPM_NV_INDEX_INVALID_PO_ALG = 0x9,      //TPM PO index nameAlg
                                              //incorrect
  ERR_TPM_NV_INDEX_INVALID_PO_POL_SZ = 0xA,   //TPM PO index policy digest
                                              //size is incorrect
  ERR_TPM_NV_INDEX_INVALID_PO_POL_VAL = 0xb,  //TPM PO index policy digest
                                              //value is incorrect
  ERR_TPM_NV_INDEX_INVALID_PO_SIZE = 0xc,     //TPM PO index data size is
                                              //incorrect
  ERR_TPM_NV_INDEX_INVALID_PS = 0xd,          //One or more of TPM PS index
                                              //properties are incorrect:
                                              //localities attributes or
                                              //index size
  ERR_TPM_NV_INDEX_INVALID_PS_ATTR = 0xe,     //TPM PS index attributes
                                              //incorrect
  ERR_TPM_NV_INDEX_INVALID_PS_ALG = 0xf,      //TPM PS index nameAlg
                                              //incorrect
  ERR_TPM_NV_INDEX_INVALID_PS_POL_SZ = 0x10,  //TPM PS index PSlicy digest
                                              //size is incorrect
  ERR_TPM_NV_INDEX_INVALID_PS_POL_VAL = 0x11, //TPM PS index PSlicy digest
                                              //value is incorrect
  ERR_TPM_NV_INDEX_INVALID_PS_SIZE = 0x12,    //TPM PS index data size is
                                              //incorrect
};

//
// Minor error codes for ERR_BANK_COUNT
//
enum ENUM_ERR_BANK_COUNT {
  ERR_BANK_COUNT_EVT = 0x1, //TPM2_PCR_Event command
  ERR_BANK_COUNT_SEQ = 0x2, //TPM2_PCR_EventSequenceComplete command
};

//
// Minor error codes for ERR_TPM_NV_DATA_SIZE_OVER
//

enum ENUM_ERR_TPM_NV_DATA_SIZE_OVER {
  ERR_TPM_NV_DATA_SIZE_OVER_RD = 0x1, //TPM2_NV_Read command
  ERR_TPM_NV_DATA_SIZE_OVER_WR = 0x2, //TPM2_NV_Write command
  ERR_TPM_NV_DATA_SIZE_OVER_EV = 0x3, //TPM2_NV_Event command
};

//
// Minor error codes to supplement major code ERR_PCR_BANKS_NOT_SUPPORTED
//
enum ENUM_ERR_PCR_BANKS_NOT_SUPPORTED {
  ERR_PCR_BANKS_CAPPED = 0x1,
};

//
// Minor error codes to supplement major code ERR_RESPONSE_TIMEOUT
//
enum ENUM_ERR_RESPONSE_TIMEOUT {
  ERR_WAIT_COMMAND_READY = 0x1,         //FIFO I/F. Command ready bit set
  ERR_WAIT_SELFTEST_DONE = 0x2,         //FIFO I/F. Self-test done bit set
  ERR_WAIT_STATUS_VALID  = 0x3,         //FIFO I/F. Status register valid
                                        //bit set
  ERR_WAIT_BURSTCOUNT_READY = 0x4,      //FIFO I/F. Burst count to be
                                        //positive
  ERR_WAIT_COMMAND_COMPLETE = 0x5,      //FIFO I/F. DataAvail bit to unset
  ERR_WAIT_ACCESS_VALID     = 0x6,      //FIFO I/F. Access register valid
                                        //bit set
  ERR_WAIT_ACTIVE_LOCALITY     = 0x7,   //FIFO I/F. Active locality bit set
  ERR_WAIT_FWSTS4_PTT_VALID    = 0x8,
  ERR_CRB_WAIT_LOC_STATE_VALID = 0x9,   //CRB I/F. Wait time-out for
                                        //locality to activate
  ERR_CRB_WAIT_ACTIVE_LOCALITY = 0xA,   //CRB I/F. Wait time-out for
                                        //locality to activate
  ERR_CRB_WAIT_LOCALITY_ASSIGNED = 0xB, //CRB I/F. Wait time-out for
                                        //locality to inactivate
  ERR_CRB_WAIT_TPM_IDLE = 0xC,          //CRB I/F. Wait time-out for TPM to
                                        //enter idle state
  ERR_CRB_WAIT_COMMAND_READY    = 0xD,  //CRB I/F. Command ready bit set
  ERR_CRB_WAIT_COMMAND_COMPLETE = 0xE,  //CRB I/F. Control area command
                                        //complete bit set
  ERR_CRB_WAIT_ACCESS_VALID = 0xF,      //CRB I/F. Locality state valid bit
                                        //set
};

//-----------------------------------------------------------------------------
//
// Chipset configuration errors.
//-----------------------------------------------------------------------------
#define CLASS_CHIPSET_CONFIG_1 0x5

enum ENUM_CHIPSET_CONFIG_1 {
  ERR_TXT_RANGE_ENABLES = 0x1,    //One of parameters (base or size) of
                                  //mandatory TXT ranges is invalid: HEAP
                                  //SINIT DPR
  ERR_TXT_RANGE_SIZES = 0x2,      //Size of one or more of mandatory TXT
                                  //ranges is insufficient: HEAP SINIT DPR
  ERR_GMS_SIZE = 0x3,             //Graphics memory size field in GGC
                                  //register is incorrect
  ERR_GTT_SIZE = 0x4,             //GTT size field in GGC register is
                                  //incorrect
  ERR_GM_APP_SIZE = 0x5,          //Graphics memory aperture size is
                                  //incorrect
  ERR_MC_NOT_LOCKED = 0x6,        //Memory controller lock register is not
                                  //locked
  ERR_MC_LOCKED = 0x7,            //Memory controller lock register is
                                  //locked
  ERR_LT_CONFIG_NOT_LOCKED = 0x8, //TXT configuration is not locked in MSR
                                  //0x2E7
  ERR_REMAP_CONFIG = 0x9,         //Remap configuration is incorrect
  ERR_SMRR_CONFIG  = 0xA,         //SMRR configuration error
  ERR_SINIT_CONFIG = 0xb,         //Loaded ACM is not located inside of
                                  //SINIT memory
  ERR_APIC_CONFIG = 0xc,          //ACM is loaded not by Boot Strap
                                  //Processor (BSP)
  ERR_PMR_CONFIG = 0xd,           //Protected Memory Range (PMR)
                                  //configuration error
  ERR_DPR_CONFIG   = 0xe,         //DPR configuration error
  ERR_TOLUD_CONFIG = 0xf,         //TOLUD register is unlocked
  ERR_MEUMA_CONFIG = 0x10,        //ME UMA configuration error
  ERR_TOM_CONFIG   = 0x11,        //TOM configuration error: Lock bit is in
                                  //unexpected state incorrect address as
                                  //compared to ME UMA programming
  ERR_GGC_CONFIG   = 0x12,        //Erroneous GGC register programming
  ERR_BDSM_CONFIG  = 0x13,        //BDSM register is unlocked
  ERR_BGSM_CONFIG  = 0x14,        //BGSM register is unlocked
  ERR_TSEG_CONFIG  = 0x15,        //TSEGMB register is unlocked
  ERR_TOUUD_CONFIG = 0x16,        //TOUUD is either unlocked or miss-
                                  //programmed relative to TOM or TOLUD or
                                  //REMAP
  ERR_PCIEX_CONFIG     = 0x17,    //Erroneous PCIEXBAR register programming
  ERR_WAKE_ERR_BIT_SET = 0x18,    //TXT.STS.WAKE-ERR bit is set
  ERR_FLASH_CONFIG     = 0x19,    //Erroneous BIOS decode register
                                  //programming
  ERR_MCHBAR_CONFIG = 0x1a,       //MCHBAR disabled or outside of PCI MMIO
                                  //or above 4GB
  ERR_SMRR2_CONFIG    = 0x1b,     //SMRR2 configuration error
  ERR_BTG_CONFIG      = 0x1c,     //Not supported BtG profile
  ERR_GFXVTBAR_CONFIG = 0x1d,     //GFXVTBAR and Graphics device 2 enable
                                  //state mismatch
  ERR_DLCK_CONFIG = 0x1e,         //DLOCK bit state unexpected
  ERR_P2SB_CONFIG = 0x1f,
};

//
// Minor error codes for ERR_REMAP_CONFIG
//
enum ENUM_ERR_REMAP_CONFIG {
  ERR_REMAP_CONFIG_EN = 0x1,  //Enable bit is unset in either base or limit
                              //register
  ERR_REMAP_CONFIG_LEN = 0x2, //Length of remapped memory is incorrect
                              //relative to programming of bases of ME UMA
                              //and/or PCI MMIO
};

//
// Minor error codes for ERR_P2SB_CONFIG
//
enum ENUM_ERR_P2SB_CONFIG {
  ERR_P2SB_CONFIG_LK = 1,
};

//
// Minor error codes for ERR_SMRR_CONFIG
//
enum ENUM_ERR_SMRR_CONFIG {
  ERR_SMRR_CONFIG_LOMSK = 0x1, //Low DWORD of mask register is incorrect
  ERR_SMRR_CONFIG_HIMSK = 0x2, //High DWORD of mask register is incorrect
  ERR_SMRR_CONFIG_TYP   = 0x3, //Caching type of SMRAM is not Write Back
                               //(WB)
  ERR_SMRR_CONFIG_TSEG = 0x4,  //SMRR and TSEG ranges are not equal
};

//
// Minor error codes for ERR_PMR_CONFIG
//
enum ENUM_ERR_PMR_CONFIG {
  ERR_PMR_CONFIG_EN = 0x1,    //DMA remapping engines in platform are
                              //not identically programmed (enabled or
                              //disabled)
  ERR_PMR_CONFIG_RNG_L = 0x2, //DMA remapping engines in platform are
                              //not identically programmed (different
                              //Low PMR programming)
  ERR_PMR_CONFIG_RNG_H = 0x3, //DMA remapping engines in platform are
                              //not identically programmed (different
                              //High PMR programming)
  ERR_PMR_CAP1            = 0x4,
  ERR_PMR_CAP2            = 0x5,
  ERR_PMR_STS1            = 0x6,
  ERR_PMR_STS2            = 0x7,
  ERR_PMR_STS3            = 0x8,
  ERR_PMR_STS4            = 0x9,
  ERR_DESCRIPTOR_INVALID1 = 0xA,
  ERR_DESCRIPTOR_INVALID2 = 0xb,
  ERR_FAULT_STATUS        = 0xc,
};

//
// Minor error codes for ERR_DPR_CONFIG
//
enum ENUM_ERR_DPR_CONFIG {
  ERR_DPR_CONFIG_EN = 0x1, //DPR is not enabled
  ERR_DPR_CONFIG_SZ = 0x2, //One or more of the following is detected: DPR
                           //size programmed into uncore register is less
                           //than in PCH register DPR size is less than
                           //minimal required DPR region is not 1MB aligned
                           //DPR top Is not equal TSEG base
};

//
// Minor error codes for ERR_MEUMA_CONFIG
//
enum ENUM_ERR_MEUMA_CONFIG {
  ERR_MEUMA_CONFIG_EN    = 0x1, //MESEG mask register is not enabled
  ERR_MEUMA_CONFIG_ALIGN = 0x2, //ME UMA memory alignment error
  ERR_MEUMA_CONFIG_VLD   = 0x3, //Misc Shadow register valid bit is unset
  ERR_MEUMA_CONFIG_MATCH = 0x4, //ME UMA memory size as detected from MESEG
                                //mask and Misc. shadow registers don't
                                //match
  ERR_MEUMA_CONFIG_SZ = 0x5,    //Erroneous ME UMA size
};

//
// Minor error codes for ERR_GGC_CONFIG
//
enum ENUM_ERR_GGC_CONFIG {
  ERR_GGC_CONFIG_EN = 0x1, //GGC enable bit is unset
  ERR_GGC_CONFIG_LK = 0x2, //GGC lock bit is unset
};

//
// Minor error codes for ERR_FLASH_CONFIG
//
enum ENUM_ERR_FLASH_CONFIG {
  ERR_FLASH_CONFIG_SZ = 0x1, //Size error
  ERR_FLASH_CONFIG_LK = 0x2, //Unlocked
};

//
// Minor error codes for ERR_MCHBAR_CONFIG
//
enum ENUM_ERR_MCHBAR_CONFIG {
  ERR_MCHBAR_CONFIG_OVERLAP = 0x1,
};

#define CLASS_CHIPSET_CONFIG_2 0x6
enum ENUM_CHIPSET_CONFIG_2 {
  ERR_DMI_CONFIG       = 0x1,
  ERR_IMR3_BASE_CONFIG = 0x2,
  ERR_IMR3_SIZE_CONFIG = 0x3,
  ERR_REGBAR_CONFIG    = 0x4,
  ERR_TPR_CONFIG       = 0x5,
};

//
// Minor error codes for ENUM_ERR_DMI_CONFIG
//
enum ENUM_ERR_DMI_CONFIG {
  ERR_DMI_CONFIG_LK = 1,
};

//
// Minor error codes for ERR_TPR_CONFIG
//
enum ENUM_ERR_TPR_CONFIG {
  ERR_TPR_CONFIG_RNG_FLAGS    = 0x1,
  ERR_TPR_CONFIG_RNG_MISMATCH = 0x2,
  ERR_TPR_CONFIG_RNG_LEN      = 0x3,
};

//-----------------------------------------------------------------------------
//
// Trampoline code errors
//-----------------------------------------------------------------------------
#define CLASS_ERR_ACM_EXIT 0x7
enum ENUM_ERR_ACM_EXIT {
  ERR_RLP_TIMEOUT         = 0x1, //Timeout waking up RLPs
  ERR_NO_RLP_UCODE_UPDATE = 0x2, //Microcode patch is detected not loaded
                                 //in one of RLPs
  ERR_RLP_SMRR_CONFIG = 0x3,     //Mismatch of SMRR programming between ILP
                                 //and one of RLPs
  ERR_RLP_SMRR2_CONFIG = 0x4,    //Mismatch of SMRR2 programming between
                                 //ILP and one of RLPs
};
//-----------------------------------------------------------------------------
//
// Miscellaneous errors.
//-----------------------------------------------------------------------------
#define CLASS_MISC_CONFIG 0x8
enum ENUM_MISC_CONFIG {
  ERR_INTERRUPT = 0x1,                         //Internal error. Interrupt
                                               //has occurred due to CPU
                                               //exception
  ERR_MISC_CONFIG_TIMEOUT               = 0x2, //Detected time-out
  ERR_MISC_CONFIG_THREAD                = 0x3, //Thread error
  ERR_MISC_CONFIG_INTERNAL              = 0x4, //Unspecified internal error
  ERR_MISC_CONFIG_PREVIOUS_ERR_DETECTED = 0x5, //Detected error of previous
                                               //launch
  ERR_RANDOM = 0x6,                            //Failure to get random
                                               //number
  ERR_COPY_BOUNDS = 0x7,                       //Violation of bounds during
                                               //copy operation.
  ERR_MISC_CONFIG_INVALID_ALGORITHM = 0x8,     //Being asked to use an
                                               //unsupported algorithm
  ERR_INTERNAL_ERROR = 0x9,                    //All kind of non-
                                               //correctable errors
  ERR_ROGUE_ACM   = 0xA,
  ERR_STACK_FRAME = 0xB,
  ERR_FILL_BOUNDS = 0xC //Violation of bounds during
                        //memfill operation
};

//
// Minor error codes to supplement major codes ERR_MISC_CONFIG_TIMEOUT
//
enum ENUM_ERR_MISC_CONFIG_TIMEOUT {
  ERR_RESOURCE_TIMEOUT = 0x1, //Time-out waiting lock to set or threads to
                              //rendezvous
};

//
// Minor error codes to supplement major codes ERR_MISC_CONFIG_THREAD
//
enum ENUM_ERR_MISC_CONFIG_THREAD {
  ERR_THREAD_RENDEZVOUS = 0x1, //Time-out waiting threads to rendezvous
  ERR_THREAD_MISSING    = 0x2, //Thread didn't join environment
};

//
// Minor error codes - supplement ERR_COPY_BOUNDS
//
enum ENUM_ERR_COPY_BOUNDS {
  ERR_BOUNDS_PCR_EVENT      = 0x1,
  ERR_BOUNDS_PCR_EVENT_SEQ  = 0x2,
  ERR_BOUNDS_READ_PUBLIC    = 0x3,
  ERR_BOUNDS_PCR_BANKS_1    = 0x4,
  ERR_BOUNDS_PCR_BANKS_2    = 0x5,
  ERR_BOUNDS_PCR_BANKS_3    = 0x6,
  ERR_BOUNDS_ARRAY_ELEMENT  = 0x7,
  ERR_BOUNDS_IBB_EVENT_HASH = 0x8,
  ERR_BOUNDS_AUX_INDEX      = 0x9,
  ERR_BOUNDS_PS_INDEX       = 0xA,
  ERR_BOUNDS_PO_INDEX       = 0xB,
  ERR_BOUNDS_BENCHMARK_HEAP = 0xC,
  ERR_BOUNDS_PCR_MASK       = 0xD,
  ERR_BOUNDS_PCR_COMPOSITE  = 0xE,
  ERR_BOUNDS_PCR_SELECTION  = 0xF,
  ERR_BOUNDS_LCP            = 0x10,
  ERR_BOUNDS_AUX_PROP       = 0x11,
  ERR_BOUNDS_PO_PROP        = 0x12,
};

//
// Minor error codes - supplement ERR_INTERNAL_ERROR
//
enum ENUM_ERR_INTERNAL_ERROR {
  ERR_TIMEOUT_1  = 0x1,
  ERR_TIMEOUT_2  = 0x2,
  ERR_TIMEOUT_3  = 0x3,
  ERR_TIMEOUT_4  = 0x4,
  ERR_TIMEOUT_5  = 0x5,
  ERR_TIMEOUT_6  = 0x6,
  ERR_TIMEOUT_7  = 0x7,
  ERR_TIMEOUT_8  = 0x8,
  ERR_TIMEOUT_9  = 0x9,
  ERR_TIMEOUT_10 = 0xA,
  ERR_TIMEOUT_11 = 0xb,
  ERR_TIMEOUT_12 = 0xc,
  ERR_TIMEOUT_13 = 0xd,
  ERR_TIMEOUT_14 = 0xe,
  ERR_TIMEOUT_15 = 0xf,
  ERR_TIMEOUT_16 = 0x10,
};

//
// Minor error code - supplement ERR_FILL_BOUNDS
//
enum ENUM_FILL_BOUNDS {
  ERR_BOUNDS_PAGE_TABLE = 0x1,
  ERR_BOUNDS_STM        = 0x2,
};
//*****************************************************************************
//
// BIOSAC Error Classes
//
//*****************************************************************************

#define CLASS_FN_SCLEAN 0x9
enum ENUM_FN_SCLEAN {
  ERR_MEMSCRUB = 0x1,
};

//-----------------------------------------------------------------------------
//
// Reset establishment function errors
//-----------------------------------------------------------------------------
#define CLASS_FN_RESET_EST 0xA
enum ENUM_FN_RESET_EST {
  ERR_EST_TXT_NOT_LOCKED_DISABLED = 0x1,
};

//-----------------------------------------------------------------------------
//
// Alias check errors. Obsolete since moved to BIOSAC
//-----------------------------------------------------------------------------
#define CLASS_ALIAS_CHECK 0xB
enum ENUM_ALIAS_CHECK {
  /*
   * //
   * // ERR_INTERRUPT64 = 1,
   * //
   * // This value is specified in Entry64.equ file and is used in ACM
   * // code of Entry64.asm file only. Here this value is reserved to make
   * // room in CLASS_ALIAS_CHECK related enumeration.
   * //
   */
  ERR_MAPPING64          = 0x2,
  ERR_ALIAS              = 0x3,
  ERR_GTT_CFG            = 0x4,
  ERR_NOT_DRAM           = 0x5,
  ERR_RD_WR_CNT_MISMATCH = 0x6,
  ERR_CONFIG_DIGEST      = 0x10,
};

//-----------------------------------------------------------------------------
//
// Startup function errors.
// Need to reconcile with CLASS_BTG_STARTUP
//-----------------------------------------------------------------------------

#define CLASS_STARTUPACM 0xC
enum ENUM_STARTUPACM {
  ERR_STARTUPACM_FIT_TABLE = 0x1,
  ERR_STARTUPACM_INTERNAL  = 0x2,
  ERR_STARTUPACM_TPM_ERROR = 0x3,
  ERR_STARTUPACM_TXT_ERROR = 0x4,
  ERR_STARTUPACM_INFO      = 0x5,
};

//
// Minor code errors for ERR_STARTUPACM_TPM_ERROR
//
enum ENUM_ERR_STARTUPACM_TPM_ERROR {
  TXT_STARTUPTPM_SUCCESS        = 0x1,
  TXT_STARTUPTPM_NO_TPM         = 0x2,
  TXT_STARTUPTPM_AUX1           = 0x3,
  TXT_STARTUPTPM_AUX2           = 0x4,
  TXT_STARTUPTPM_AUX3           = 0x5,
  TXT_STARTUPTPM_AUX4           = 0x6,
  TXT_STARTUPTPM_TOO_MANY_BANKS = 0x7,
};

//
// Minor code errors for ERR_STARTUPACM_TXT_ERROR
//
enum ENUM_ERR_STARTUPACM_TXT_ERROR {
  TXT_STARTUPTXT_EXECUTION_POLICY     = 0x1,
  TXT_STARTUPTXT_SCRUBBING_POLICY     = 0x2,
  TXT_STARTUPTXT_BACKUP_POLICY        = 0x3,
  TXT_STARTUPTXT_PLATFORM_TYPE        = 0x4,
  TXT_STARTUPTXT_HECI_DEVICE_DIS      = 0x5,
  TXT_STARTUPTXT_PDRS_INVALID         = 0x6,
  TXT_STARTUPTXT_SMX_NOT_SUPPORTED    = 0x7,
  TXT_STARTUPTXT_PTT_NOT_SUPPORTED    = 0x8,
  TXT_STARTUPTXT_COSIGN_NOT_SUPPORTED = 0x9,
  TXT_STARTUPTXT_RESET_ATTACK_SUPPORT = 0xA
};

//
// Minor code errors for ERR_STARTUPACM_INFO
//
enum ENUM_ERR_STARTUPACM_INFO {
  TXT_STARTUPINFO_POWER_DOWN_EXECUTED = 0x1,
  TXT_STARTUPINFO_SCRUBBING_CODE_ERR  = 0x2,
};

//-----------------------------------------------------------------------------
// Client BIOSAC Error Classes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
// Function ResetAux errors
//-----------------------------------------------------------------------------
#define CLASS_FN_RESET_AUX 0xD
enum ENUM_FN_RESET_AUX {
  ERR_AUX_TXT_NOT_LOCKED_DISABLED = 0x1,
};

//-----------------------------------------------------------------------------
//
// This is LockConfiguration function error - used to be SCHECK, not renamed
//
#define CLASS_FN_SCHECK 0xE
enum ENUM_FN_SCHECK {
  ERR_CLEAR_SECRETS_NOT_CALLED = 0x1,
};

//-----------------------------------------------------------------------------
//
// IBB loader errors.
//-----------------------------------------------------------------------------

#define CLASS_IBBL 0xF
enum ENUM_IBBL {
  ERR_IBBL_FIT_ACCESS_ERROR = 0x1,
  ERR_IBBL_BPM_ACCESS_ERROR = 0x2,
  ERR_IBBL_NEM_SETUP_ERROR  = 0x3,
  ERR_IBBL_LLC_SIZE_ERROR   = 0x4,
};

//
// Minor code errors for ERR_IBBL_BPM_ACCESS_ERROR
//
enum ENUM_ERR_IBBL_BPM_ACCESS_ERROR {
  IBBL_BPM_NOT_FOUND       = 0x1,
  IBBL_BPM_NOT_REACHABLE   = 0x2,
  IBBL_BPM_VER_UNSUPPORTED = 0x3,
  IBBL_BPM_IBB_NOT_FOUND   = 0x4,
};

//
// Minor code errors for ERR_IBBL_NEM_SETUP_ERROR
//
enum ENUM_ERR_IBBL_NEM_SETUP_ERROR {
  IBBL_NEM_OVERLAP_ERROR                   = 0x1,
  IBBL_NEM_ALIGNMENT_UP_ERROR              = 0x2,
  IBBL_NEM_ALIGNMENT_DOWN_ERROR            = 0x3,
  IBBL_NEM_INSUFFICIENT_NUMOF_MTRRS_ERROR  = 0x4,
  IBBL_NEM_OVERLAP_ERROR_NEM_MAP_STRUCTURE = 0x5,
  IBBL_NEM_OVERLAP_ERROR_FIT               = 0x6,
  IBBL_NEM_OVERLAP_ERROR_KM                = 0x7,
  IBBL_NEM_OVERLAP_ERROR_BPM               = 0x8,
  IBBL_NEM_OVERLAP_ERROR_ACM               = 0x9,
};

//
// Minor code errors for ERR_IBBL_LLC_SIZE_ERROR
//
enum ENUM_ERR_IBBL_LLC_SIZE_ERROR {
  IBBL_LLC_SIZE_NOT_FOUND = 1,
  IBBL_LLC_TOO_SMALL,
};

//-----------------------------------------------------------------------------
//
// BtG startup function errors.
//-----------------------------------------------------------------------------
#define CLASS_BTG_STARTUP 0x10
enum ENUM_BTG_STARTUP {
  BTG_SUCCESS        = 0x0,
  BTG_INIT_ERROR     = 0x1,
  BTG_NEM_ERROR      = 0x2,
  BTG_MANIFEST_ERROR = 0x3,
  BTG_MEASURE_ERROR  = 0x4,
  BTG_POLICY_ERROR   = 0x5,
  BTG_FAIL           = 0x6,
};

//
// Minor code errors for BTG_INIT_ERROR
//
enum ENUM_BTG_INIT_ERROR {
  BTG_INIT_SUCCESS                  = 0x0,
  BTG_INIT_PBE_NOT_SET_ERROR        = 0x1,
  BTG_INIT_INVALID_BOOT_TYPE_ERROR  = 0x2,
  BTG_INIT_POLICY_ERROR             = 0x3,
  BTG_INIT_INVALID_KM_ID_ERROR      = 0x4,
  BTG_INIT_INVALID_BP_KEY_ERROR     = 0x5,
  BTG_INIT_INVALID_BP_PROFILE_ERROR = 0x6,
  BTG_INIT_ACM_ADDRESS_RANGE_ERROR  = 0x7,
  BTG_INIT_ACM_REVOKED_ERROR        = 0x8,
  BTG_INIT_ME_OK_PROCEED_ERROR      = 0x9,
  BTG_INIT_MCP_BAD_ERROR            = 0xA,
  BTG_INIT_MCP_MISMATCH_ERROR       = 0xB,
};

//
// Minor code errors for BTG_NEM_ERROR
//
enum ENUM_BTG_NEM_ERROR {
  BTG_NEM_SUCCESS                           = 0x0,
  BTG_NEM_MTRR_COUNT_ERROR                  = 0x1,
  BTG_NEM_INSUFFICIENT_NUMOF_MTRRS_ERROR    = 0x2,
  BTG_NEM_IBB_SEGMENT_ERROR                 = 0x3,
  BTG_NEM_IBB_SEGMENT_OVERLAP_ERROR         = 0x4,
  BTG_NEM_IBB_OUT_OF_MTRR_RANGE_ERROR       = 0x5,
  BTG_NEM_IBB_ENTRY_POINT_OUT_OF_IBB_ERROR  = 0x6,
  BTG_NEM_IBB_HASH_NOT_VALID_ERROR          = 0x7,
  BTG_NEM_CANT_READ_LLC_SIZE_ERROR          = 0x8,
  BTG_NEM_LLC_SIZE_TOO_SMALL_ERROR          = 0x9,
  BTG_NEM_MANIFEST_FLASH_CRAM_COMPARE_ERROR = 0xA,
  BTG_NEM_FIT_FLASH_CRAM_COMPARE_ERROR      = 0xb,
  BTG_NEM_VTD_RANGE_CHECK_ERROR             = 0xc,
  BTG_NEM_VTD_DISABLED_IN_HARDWARE          = 0xd,
  BTG_NEM_DMA_BPM_DEF                       = 0xe,
  BTG_NEM_DMA_BPM_OVRLAP                    = 0xf,
  BTG_NEM_VTD_ENABLE_FAILED                 = 0x10,
  BTG_NEM_ALIGNMENT_ERROR                   = 0x11,
  BTG_NEM_VTD_DISABLED_IN_BPM               = 0x12,
  BTG_NEM_ACM_ALIGNMENT                     = 0x13,
  BTG_NEM_MTRR_RANGE_UNDER_4KB              = 0x14,
  BTG_NEM_MTRR_RANGE_NOT_2PN                = 0x15,
  BTG_NEM_MTRR_INVALID_BASE_ALIGNMENT       = 0x16,
  BTG_NEM_IBB_SEGMENT_NULL                  = 0x17,
  BTG_NEM_TPR_ENABLE_FAILED                 = 0x18
};

//
// Minor code errors for BTG_MANIFEST_ERROR
//
enum ENUM_BTG_MANIFEST_ERROR {
  BTG_MANIFEST_SUCCESS                        = 0x0,
  BTG_KM_INVALID_STRUCT_ERROR                 = 0x1,
  BTG_KM_INVALID_KM_ID_ERROR                  = 0x2,
  BTG_KM_REVOKED_ERROR                        = 0x3,
  BTG_MANIFEST_INVALID_HEADER_STRUCT_ERROR    = 0x4,
  BTG_MANIFEST_INVALID_IBB_STRUCT_ERROR       = 0x5,
  BTG_MANIFEST_INVALID_PM_DATA_STRUCT_ERROR   = 0x6,
  BTG_MANIFEST_INVALID_SIGNATURE_STRUCT_ERROR = 0x7,
  BTG_MANIFEST_REVOKED_ERROR                  = 0x8,
  BTG_MANIFEST_INVALID_SIZE_ERROR             = 0x9,
  BTG_MANIFEST_OVER_BUFFSER_SIZE_ERROR        = 0xA,
  BTG_FIT_INVALID_HEADER_ERROR                = 0xb,
  BTG_FIT_KM_ENTRY_ERROR                      = 0xc,
  BTG_FIT_MANIFEST_ENTRY_ERROR                = 0xd,
  BTG_FIT_KM_ENTRY_MISSING_ERROR              = 0xe,
  BTG_FIT_MANIFEST_ENTRY_MISSING_ERROR        = 0xf,
};

//
// Minor code errors for BTG_MEASURE_ERROR
//
enum ENUM_BTG_MEASURE_ERROR {
  BTG_MEASURE_FAIL                 = 0x0,
  BTG_MEASURE_SUCCESS              = 0x1,
  BTG_CRYPTO_HASH_NOT_VALID_ERROR  = 0x2,
  BTG_CRYPTO_VERIFY_SIG_FAIL_ERROR = 0x3,
  BTG_MEASURE_HASH_COMPARE         = 0x4,
};

//-----------------------------------------------------------------------------
//
// Boot Point Tehcnology errors - new errors of CBnT
//-----------------------------------------------------------------------------
#define CLASS_BPT_INTEGRITY 0x11
//
// Major errors of CLASS_BPT_INTEGRITY
//
enum ENUM_BPT_INTEGRITY {
  ERR_SUCCESS         = 0x0,
  ERR_FPF_POLICY      = 0x1,
  ERR_BPT_ACM_REVOKED = 0x2,
  ERR_FIT             = 0x3,
  ERR_KM              = 0x4,
  ERR_BPM             = 0x5,
  ERR_IBB             = 0x6,
  ERR_PRE_BOOT_OBJ    = 0x7, //Computed heap data table size mismatches
                             //value in header
  ERR_BTG_MEASURE_ERROR = 0x8,
  ERR_BTG_POLICY_ERROR  = 0x9,
};

//
// Minor errors of ERR_FPF_POLICY
//
enum ENUM_ERR_FPF_POLICY {
  ERR_FPF_MSR_READ             = 0x1,
  ERR_FPF_KM_ID_VALUE          = 0x2,
  ERR_FPF_KM_PUBKEY_DGST_VALUE = 0x3,
};

//
// Minor errors of ERR_FIT
//
enum ENUM_ERR_FIT {
  ERR_FIT_INVALID_SIZE       = 0x1,
  ERR_FIT_INVALID_HEADER     = 0x2,
  ERR_FIT_KM_ENTRY_MISSING   = 0x3,
  ERR_FIT_KM_ENTRY_INVALID   = 0x4,
  ERR_FIT_BPM_ENTRY_MISSING  = 0x5,
  ERR_FIT_BPM_ENTRY_INVALID  = 0x6,
  ERR_FIT_SACM_ENTRY_MISSING = 0x7,
  ERR_FIT_SACM_ENTRY_INVALID = 0x8,
  ERR_FIT_TXT_POLICY_INVALID = 0x9,
};

//
// Minor errors of ERR_KM
//
enum ENUM_ERR_KM {
  ERR_KM_INVALID_SIZE                = 0x1,
  ERR_KM_STRUCTURE_INVALID           = 0x2,
  ERR_KM_KEYSIGN_PTR_INVALID         = 0x3,
  ERR_KM_SIGN_PTR_INVALID            = 0x4,
  ERR_KM_SIGNATURE_STRUCTURE_INVALID = 0x5,
  ERR_KM_CRYPTO_VERIFY_SIG_FAIL      = 0x6,
  ERR_KM_ID_VALUE                    = 0x7,
  ERR_KM_REVOKED                     = 0x8,
};

//
// Minor errors of ERR_BPM
//
enum ENUM_ERR_BPM {
  ERR_BPM_INVALID_SIZE                      = 0x1,
  ERR_BPM_STRUCTURE_INVALID                 = 0x2,
  ERR_BPM_SE_STRUCTURE_INVALID              = 0x3,
  ERR_BPM_SE_POSTIBB_DGST_STRUCTURE_INVALID = 0x4,
  ERR_BPM_SE_PTR_INVALID                    = 0x5,
  ERR_BPM_SE_IBB_SEGMENTS_PTR_INVALID       = 0x6,
  ERR_BPM_SE_ENTRY_POINT_PTR_INVALID        = 0x7,
  ERR_BPM_SE_ENTRY_POINT_VALUE_INVALID      = 0x8,
  ERR_BPM_SE_IBB_DGST_PTR_INVALID           = 0x9,
  ERR_BPM_SE_IBB_DGST_STRUCTURE_INVALID     = 0xA,
  ERR_BPM_SE_SEG_CNT_PTR_INVALID            = 0xb,
  ERR_BPM_SE_SEG_CNT_VALUE_INVALID          = 0xc,
  ERR_BPM_TXTE_STRUCTURE_INVALID            = 0xd,
  ERR_BPM_TXTE_SEG_CNT_PTR_INVALID          = 0xe,
  ERR_BPM_TXTE_SEG_CNT_VALUE_INVALID        = 0xf,
  ERR_BPM_PCDE_PTR_INVALID                  = 0x10,
  ERR_BPM_PCDE_STRUCTURE_INVALID            = 0x11,
  ERR_BPM_PCDE_PWR_DN_PTR_INVALID           = 0x12,
  ERR_BPM_PCDE_PWR_DN_STRUCTURE_INVALID     = 0x13,
  ERR_BPM_PCDE_PWR_DN_EFF_PTR_INVALID       = 0x14,
  ERR_BPM_PMDE_STRUCTURE_INVALID            = 0x15,
  ERR_BPM_SIGE_PTR_INVALID                  = 0x16,
  ERR_BPM_SIGE_STRUCTURE_INVALID            = 0x17,
  ERR_BPM_SIGE_KEYSIGN_PTR_INVALID          = 0x18,
  ERR_BPM_SIGE_SIGN_PTR_INVALID             = 0x19,
  ERR_BPM_SIGE_CRYPTO_VERIFY_SIG_FAIL       = 0x1a,
  ERR_BPM_REVOKED                           = 0x1b,
  ERR_BPM_FIT_SIZE_MISMATCH                 = 0x1c,
  ERR_BPM_TXTE_PTR_INVALID                  = 0x1d,
  ERR_BPM_FIT_PTR_INVALID                   = 0x1e,
  ERR_BPM_PFRE_PTR_INVALID                  = 0x1f,
  ERR_BPM_PFRE_STRUCTURE_INVALID            = 0x20,
};

//
// Minor errors of ERR_IBB
//
enum ENUM_ERR_IBB {
  ERR_BPM_SE_IBB_STRUCTURE_INVALID        = 0x1,
  ERR_BPM_SE_IBB_ENTRY_POINT              = 0x2,
  ERR_BPM_SE_IBB_DGST_VALUE_INVALID       = 0x3,
  ERR_BPM_SE_IBB_SEG_OVERLAP              = 0x4,
  ERR_BPM_SE_INVALID_SEGMENT_CACHE_TYPE   = 0x5,
  ERR_BPM_SE_CANNOT_CLUSTER_CACHE_TYPES   = 0x6,
  ERR_BPM_SE_CANNOT_CLUSTER_SEGMENT_TYPES = 0x7,
  ERR_BPM_SE_FIT_OBJECTS_OUTSIDE_TC       = 0x8,
  ERR_BPM_SE_INVALID_SEGMENT_TYPE_BC      = 0x9,
  ERR_BPM_SE_INVALID_SEGMENT_TYPE_TC      = 0xA,
  ERR_BPM_SE_TOTAL_WB_WP_SEGMENT_COUNT    = 0xb,
};

// Startup ACM, PFR specific errors
#define CLASS_PFR 0x12
enum ENUM_PFR {
  ERR_PFR_UNSUPPORTED = 0x1,
  ERR_CPLD_INTERFACE  = 0x2,
};

//
// Minor errors of ERR_CPLD_INTERFACE
//
enum ENUM_ERR_CPLD_INTERFACE {
  ERR_CPLD_ADDR_NOT_INITIALIZED = 0x1,
  ERR_S3M_REG_NOT_INITIALIZED   = 0x2,
  ERR_S3M_READ                  = 0x3,
  ERR_S3M_WRITE                 = 0x4,
  ERR_S3M_ROOT_KEY_HASH         = 0x5,
};

//-----------------------------------------------------------------------------
//
// PCR related errors
//-----------------------------------------------------------------------------
#define CLASS_PCR_INTEGRITY_CHECK 0x13
enum ENUM_PCR_INTEGRITY_CHECK {
  ERR_PCR17_VALUE = 0x1,          //Value in PCR17 does not match expected
                                  //result
  ERR_PCR18_VALUE = 0x2,          //Value in PCR18 does not match expected
                                  //result
  ERR_PCRFMT_NOT_SUPPORTED = 0x3, //PCR mapping (legacy or D/A) is not
                                  //supported for TPM family and / or
                                  //mismatches request
  ERR_PCR_NOT_SUPPORTED = 0x4,
  ERR_PCR_BIOS_DIGEST   = 0x5,
};
//-----------------------------------------------------------------------------
//
// Event log related errors
//-----------------------------------------------------------------------------
#define CLASS_EVENT_LOG 0x14
enum ENUM_EVENT_LOG {
  ERR_LOG_HEADER_GUID    = 0x1, //Error log GUID is wrong
  ERR_LOG_HEADER_VERSION = 0x2, //Unsupported event log version
  ERR_LOG_HEADER_FIELDS  = 0x3, //Inconsistent offsets in log header
  ERR_LOG_SIZE           = 0x4, //Log size is less than minimum requested
                                //or no room to place event entry
  ERR_LOG_RECORD_VERSION = 0x5, //Unsupported event log record version
};

//-----------------------------------------------------------------------------
//
// Heap content related errors
//-----------------------------------------------------------------------------
#define CLASS_HEAP_TABLE_BUILD 0x15

//-----------------------------------------------------------------------------
//
// Errors in SINIT 64 bit code.
//-----------------------------------------------------------------------------
#define CLASS_SINIT64_MODE 0x16
enum ENUM_SINIT64_MODE {
  /*
   * //
   * // ERR_INTERRUPT64 = 1,
   * //
   * // This value is specified in Entry64.equ file and is used in ACM
   * // code of Entry64.asm file only. Here this value is reserved to make
   * // room in CLASS_SINIT64_MODE related enumeration.
   * //
   */
  ERR_BUSY_TIME_OUT_1     = 0x10,
  ERR_BUSY_TIME_OUT_2     = 0x1,
  ERR_BUSY_TIME_OUT_3     = 0x2,
  ERR_READ_BOOT_POL       = 0x3,
  ERR_READ_BTG_BP_KEY0    = 0x4,
  ERR_READ_BTG_BP_KEY1    = 0x5,
  ERR_READ_BTG_BP_KEY2    = 0x6,
  ERR_READ_BTG_BP_KEY3    = 0x7,
  ERR_READ_BTG_BP_KEY4    = 0x8,
  ERR_READ_BTG_BP_KEY5    = 0x9,
  ERR_HECIBAR_IN_LOW_DRAM = 0xA, // If Heci1bar address lies below 4GB and below TOLUD.
  ERR_HECIBAR_IN_HI_DRAM  = 0xB, // If Heci1bar address lies above 4GB and below TOUUD.
};

#define CLASS_SAI_POLICY_CHECK 0x17
enum ENUM_SAI_POLICY_CHECK {
  ERR_SAI_POLICY_LB_W            = 0x1,
  ERR_SAI_POLICY_LB_MCHECK_W     = 0x2,
  ERR_SAI_POLICY_DFX             = 0x3,
  ERR_SAI_POLICY_OS_W            = 0x4,
  ERR_SAI_POLICY_BTSMM_W         = 0x5,
  ERR_SAI_POLICY_BOOT_W          = 0x6,
  ERR_SAI_POLICY_BIOS_W          = 0x7,
  ERR_SAI_POLICY_MCHECK_W        = 0x8,
  ERR_SAI_POLICY_LB_MCHECK_WCP   = 0x9,
  ERR_SAI_POLICY_OS_W_CP         = 0xA,
  ERR_SAI_POLICY_DFX_CP          = 0xb,
  ERR_SAI_POLICY_LB_MCHECK_W_WAC = 0xc,
  ERR_SAI_POLICY_OS_W_WAC        = 0xd,
  ERR_SAI_POLICY_BTSMM_W_WAC     = 0xe,
  ERR_SAI_POLICY_IMR3_SAI        = 0xf,
  ERR_SAI_POLICY_IMR3_SAI_WAC    = 0x10,
  ERR_SAI_POLICY_DFX_OEM_CP      = 0x11,
  ERR_SAI_POLICY_DFX_OEM_WAC     = 0x12,
};

#define CLASS_CXL_CHECK 0x18
enum ENUM_CXL_CHECK {
  ERR_CXL_RCRBBAR_REG_OVER_4GB        = 0x1,
  ERR_CXL_MEMBAR_REG_OVER_4GB         = 0x2,
  ERR_CXL_CAPABILITIES_HEADER_REG     = 0x3,
  ERR_CXL_SEC_CAPABILITIES_HEADER_REG = 0x4,
};
//-----------------------------------------------------------------------------
//
// DMA protection - TPR configuration errors
//-----------------------------------------------------------------------------
#define CLASS_TPR_CONFIG 0x19
enum ENUM_TPR_CONFIG {
  ERR_CONFIG_TPR          = 0x1,
  ERR_REQ_TPR             = 0x2,
  ERR_SRL_REG_CNT         = 0x3,
  ERR_TPR_CNT             = 0x4,
  ERR_SRL_CONFIG          = 0x5,
  ERR_INS_CNT             = 0x6,
  ERR_ALL_TPR_NOT_DEFINED = 0x7,
  ERR_ALL_SRL_NOT_DEFINED = 0x8,
  ERR_MLE_DMA_CONFIG      = 0x9,
};

//-----------------------------------------------------------------------------
//
// Internal errors
//-----------------------------------------------------------------------------
#define CLASS_INTERNAL_ERRORS 0x20
enum ENUM_INTERNAL_ERRORS {
  ERR_SHADOW_STACK = 0x1,
};

//-----------------------------------------------------------------------------
//
// Memory Reference Code erros.
//-----------------------------------------------------------------------------
#define CLASS_MRC_CONFIG 0x21
enum ENUM_MRC_CONFIG {
  ERR_DDR_TYPE_MISMATCH = 0x1,
};

#define CLASS_ACPI_CHECK 0x22
enum ENUM_ACPI_CHECK {
  ERR_RSDP_CHKSM   = 0x1, //RSDP checksum error
  ERR_NO_RSDT      = 0x2, //RSDT not found
  ERR_INVALID_RSDT = 0x3, //Validation of RSDT table failed
  ERR_NO_DMAR      = 0x4, //DMAR table not found
  ERR_INVALID_DMAR = 0x5, //Validation of DMAR table failed
  ERR_NO_MADT      = 0x6, //MADT table not found
  ERR_INVALID_MADT = 0x7, //Validation of MADT table failed
  ERR_INVALID_RSDP = 0x8, //Validation of RSDP table failed
  ERR_INVALID_XSDT = 0x9, //Validation of XSDT table failed
  ERR_NO_MCFG      = 0xA,
  ERR_NO_CEDT      = 0xb,
  ERR_INVALID_CEDT = 0xc,
  ERR_NO_DTPR      = 0xd,
  ERR_INVALID_APIC = 0xe,
  ERR_INVALID_MCFG = 0xf,
  ERR_INVALID_DTPR = 0x10,
};

//
// Minor errors for ERR_INVALID_CEDT
//
enum ENUM_ERR_INVALID_CEDT {
  ERR_CEDT_LENGTH          = 1,
  ERR_CEDT_LENGTH_OVERFLOW = 0x2,
  ERR_RCRBBAR_OVER_4GB     = 0x3,
  ERR_RCRBBAR_OVERLAP      = 0x4,
  ERR_DPMEMBAR_OVERLAP     = 0x5,
  ERR_RCRBBAR_CNT_OVERFLOW = 0x6,
  ERR_MISSING_CHBS_ENTRY   = 0x7,
  ERR_INVALID_CHBS_VERSION = 0x8,
  ERR_INVALID_CHBS_SIZE    = 0x9,
  ERR_INVALID_CHBS_TYPE    = 0xA,
  ERR_INVALID_CHBS_UID     = 0xB,
  ERR_CHBS_SECURITY_POLICY = 0xC,
};

//-----------------------------------------------------------------------------
//
// ClearSecrets function errors
//-----------------------------------------------------------------------------
#define CLASS_CLEAR_SECRETS 0x23

enum ENUM_CLEAR_SECRETS {
  ERR_CLEAR_SECRETS_MEMORY_LOCKED  = 0x1,
  ERR_CLEAR_SECRETS_BIOS_UNTRUSTED = 0x2,
};

//-----------------------------------------------------------------------------
//
// ACPI errors, DMAR specific.
//-----------------------------------------------------------------------------
#define CLASS_DMAR_CHECK 0x24
enum ENUM_DMAR_CHECK {
  ERR_DMAR_INVALID_TYPE = 0x1,   //Unknown structure type is detected in
                                 //DMAR table
  ERR_DMAR_INVALID_STRUCT = 0x2,
  ERR_DMAR_LENGTH         = 0x3, //Computed DMAR length mismatches value in
                                 //header
  ERR_DMAR_IR = 0x4,             //Interrupt remapping is required but not
                                 //supported
  ERR_DMAR_ADDR_WIDTH = 0x5,     //Memory bus address width differs from
                                 //reported in DMAR header
  ERR_DMAR_DEV_SCOPE  = 0x6,
  ERR_DMAR_DEV_CONFIG = 0x7,
  ERR_DRHD            = 0x8,
  ERR_RMRR            = 0x9, //Incorrect placement of PMRR. Must be in
                             //GFX UMA for GFX VT-d engine and in DRAM
                             //for DMI-PEG engine
  ERR_ATSR                   = 0xA,
  ERR_RHSA                   = 0xb,
  ERR_ANDD                   = 0xc,
  ERR_INCLUDE_ALL            = 0xd,
  ERR_MISSING_DEV_SCOPE      = 0xe,
  ERR_SATC                   = 0xf,
  ERR_DMAR_VTD_DRHD_MISMATCH = 0x10, // VTD entries do no match drhd vtd match
};

//
// Minor errors for ERR_DRHD
//
enum ENUM_ERR_DRHD {
  ERR_DRHD_LENGTH         = 0x1, //Incorrect length
  ERR_DRHD_FLAGS          = 0x2,
  ERR_DRHD_CONFIG_BASE    = 0x3, //Incorrect config base
  ERR_DRHD_DEV_SCOPE_GFX  = 0x4,
  ERR_DRHD_INCLUDE_ALL    = 0x5,
  ERR_DRHD_TO_HW_MISMATCH = 0x6,
};

//
// Minor errors for ERR_RMRR
//
enum ENUM_ERR_RMRR {
  ERR_RMRR_LENGTH        = 0x1,
  ERR_RMRR_DEV_SCOPE_GFX = 0x2,
  ERR_RMRR_COUNT         = 0x3,
};

//
// Minor errors for ERR_SATC
//
enum ENUM_ERR_SATC {
  ERR_SATC_LENGTH      = 0x1,
  ERR_SATC_FLAGS       = 0x2,
  ERR_SATC_CONFIG_BASE = 0x3,
  ERR_SATC_DEV_SCOPE   = 0x4,
};

//-----------------------------------------------------------------------------
//
// This is obsolete SCHECK function erorr - server specific.
//
#define CLASS_SCHECK 0x25

//-----------------------------------------------------------------------------
//
// DMA protection - PMR configuration errors
//-----------------------------------------------------------------------------
#define CLASS_PMR_CONFIG 0x26
enum ENUM_PMR_CONFIG {
  ERR_DMA_REMAP   = 0x1, //DMA remapping is turned on
  ERR_PMRL_CONFIG = 0x2, //PMR low configuration error - it is either
                         //enabled but not requested or request differs
                         //from actual programming
  ERR_PMRH_CONFIG = 0x3, //PMR low configuration error - it is either
                         //enabled but not requested or request differs
                         //from actual programming
};

//-----------------------------------------------------------------------------
//
// BIOS properties errors.
// Consider recomciling with CLASS_BTG_STARTUP
//-----------------------------------------------------------------------------
#define CLASS_BIOS_PROPERTIES 0x27

enum ENUM_BIOS_PROPERTIES {
  ERR_BIOS_PROPERTIES_NO_ENTRY_POINT          = 0x1,
  ERR_BIOS_PROPERTIES_NO_BIOS_MODULES         = 0x2,
  ERR_BIOS_PROPERTIES_NO_MANIFEST             = 0x3,
  ERR_BIOS_PROPERTIES_FIT_BIOS_MODULE_RECORD  = 0x4,
  ERR_BIOS_PROPERTIES_FIT_END                 = 0x5,
  ERR_BIOS_PROPERTIES_FIT_RESET               = 0x6,
  ERR_BIOS_PROPERTIES_FIT_PTR                 = 0x7,
  ERR_BIOS_PROPERTIES_FIT_STARTUP_REGIONS     = 0x8,
  ERR_BIOS_PROPERTIES_FIT_STARTUP_ACM_OVERLAP = 0x9,
  ERR_BIOS_PROPERTIES_FIT_BIOS_POLICY_OVERLAP = 0xA,
  ERR_BIOS_PROPERTIES_FIT_POLICY_RECORD       = 0xb,
};

//-----------------------------------------------------------------------------
//
// MLE header errors
//-----------------------------------------------------------------------------
#define CLASS_MLE_HEADER_CHECK 0x28
enum ENUM_MLE_HEADER_CHECK {
  ERR_MLE_HEADER_LIN_ADDR = 0x1,
  ERR_MLE_GUID            = 0x2,
  ERR_MLE_VERSION         = 0x3,
  ERR_MLE_FIRST_PAGE      = 0x4,
  ERR_MLE_SIZE            = 0x5,
  ERR_MLE_ENTRY_PT        = 0x6,
  ERR_MLE_CAPABILITIES    = 0x7,
};

//
// Minor errors for ERR_MLE_CAPABILITIES
//
enum ENUM_ERR_MLE_CAPABILITIES {
  ERR_MONITOR_GETSEC_WAKEUP = 0x1,
  ERR_BPT_SUPPORT           = 0x2,
};

//-----------------------------------------------------------------------------
//
// LockConfiguration function errors.
// Need to reconcile with client class CLASS_FN_SCHECK
//-----------------------------------------------------------------------------
#define CLASS_LOCK_CONFIG 0x29
enum ENUM_LOCK_CONFIG {
  ERR_LOCK_CONFIG_STARTUP_FAILED       = 0x1,
  ERR_LOCK_CONFIG_MEMORY_LOCKED        = 0x2,
  ERR_LOCK_CONFIG_HASH_REGS_NOT_LOCKED = 0x3,
  ERR_LOCK_CONFIG_SYSTEM_SETUP         = 0x4,
};

//-----------------------------------------------------------------------------
//
// MLE page table errors
//-----------------------------------------------------------------------------
#define CLASS_MLE_PT_CHECK 0x2A
enum ENUM_MLE_PT_CHECK {
  ERR_MLE_RANGE_CHECK          = 0x1,
  ERR_MLE_PAGE_RULE_FAIL       = 0x2,
  ERR_MLE_PT_BIG_PAGE          = 0x3,
  ERR_MLE_PAGE_PD_PT_RULE_FAIL = 0x4,
  ERR_MLE_PT_HASED_SIZE        = 0x5,
  ERR_MLE_PT_RLP_ENTRY_POINT   = 0x6,
};

//-----------------------------------------------------------------------------
//
// STM crash codes
//-----------------------------------------------------------------------------
#define CLASS_STM_CHECK 0x2B
enum ENUM_STM_CHECK {
  ERR_STM_RANGE_CHECK = 0x1,        //Error in placement or alignment of
                                    //STM related range
  ERR_MSEG_BASE            = 0x2,   //MSEG base is not programmed
  ERR_STM_SMBASE_NOT_FOUND = 0x3,   //Base of SMRAM code is not found
  ERR_STM_WRONG_IEDBASE    = 0x4,   //IED range incorrectly programmed
  ERR_STM_CANNOT_ENABLE    = 0x5,   //Request to enable STM via OS to SINIT
                                    //table and MLE capabilities don't
                                    //match
  ERR_STM_IS_REQUIRED = 0x6,        //Fail if MLE requested STM support via
                                    //OsSinitDataReqCaps but no STM
                                    //elements were found in LCP data or
                                    //MLE requested disabling STM support
                                    //via OsSinitDataReqCaps while STM
                                    //required bit is set in MLE
                                    //PolEltControl
  ERR_MSEG_SIZE              = 0x7, //MSEG size is not programmed
  ERR_STM_HEADER_ID          = 0x8,
  ERR_STM_HEADER_FEATURES    = 0x9, //STM header error
  ERR_STM_CPU_CAP            = 0xA, //CPU capabilities insufficient
  ERR_STM_HEADER_BLANK_FIELD = 0xB, //CS selector in header is blank
  ERR_STM_HEADER_OFFSET      = 0xC, //STM header error
  ERR_STM_HEADER_VALUE       = 0xD, //One or more of the sizes in STM
                                    //header is above 16MB
  ERR_STM_REV_ID = 0xE,             //Unsupported STM version
};

#define CLASS_EXT2_CHIPSET_CONFIG 0x2C
enum ENUM_EXT2_CHIPSET_CONFIG {
  ERR_GTT_TOLUD_LOCK        = 0x1,
  ERR_CMP_GTT_TOLUD_CONFIG  = 0x2,
  ERR_GTT_TOUUD_LOCK        = 0x3,
  ERR_CMP_GTT_TOUUD_CONFIG  = 0x4,
  ERR_GTT_BGSM_LOCK         = 0x5,
  ERR_CMP_GTT_BGSM_CONFIG   = 0x6,
  ERR_GTT_BDSM_LOCK         = 0x7,
  ERR_CMP_GTT_BDSM_CONFIG   = 0x8,
  ERR_GTT_GGC_LOCK          = 0x9,
  ERR_CMP_GGC_BDSM_CONFIG   = 0xA,
  ERR_CMP_GTT_TSEGMB_CONFIG = 0xB,
  ERR_CMP_GTT_DPR_CONFIG    = 0xC,
  ERR_GTT_PAVPC_LOCK        = 0xD,
  ERR_GTT_PRMRR_MASK_LOCK   = 0xE,
  ERR_GTT_PRMRR_MASK_EN     = 0xF,
  ERR_CMP_PRMRR_MASK_CONFIG = 0x10,
  ERR_CMP_PRMRR_BASE_CONFIG = 0x11,
  ERR_CMP_GTT_PAVPC_CONFIG  = 0x12,
  ERR_CMP_GTT_PMRLB_CONFIG  = 0x13,
  ERR_CMP_GTT_PMRLL_CONFIG  = 0x14,
  ERR_CMP_GTT_PMRHB_CONFIG  = 0x15,
  ERR_CMP_GTT_PMRHL_CONFIG  = 0x16,
  ERR_GT_FLR                = 0x17,
  ERR_GTT_PAVPC_PCME        = 0x18,
  ERR_CMP_GTT_PAVPC_LEN     = 0x19,
};

//-----------------------------------------------------------------------------
//
// Extended chipset configuration errors.
//-----------------------------------------------------------------------------

#define CLASS_EXT_CHIPSET_CONFIG 0x2D
enum ENUM_EXT_CHIPSET_CONFIG {
  ERR_PRMRR_CONFIG            = 0x1,
  ERR_TXT_NOT_DISABLED_LOCKED = 0x2,
  ERR_PMEM_CONFIG             = 0x3,
  ERR_ACPI_PWRM_CONFIG        = 0x4,
  ERR_ACPI_COIN_BATT_STS      = 0x5,
  ERR_ISPMMADRLO_CONFIG       = 0x6,
  ERR_MTBLBAR_CONFIG          = 0x7,
  ERR_SWLBAR_CONFIG           = 0x8,
  ERR_RTITLBAR_CONFIG         = 0x9,
  ERR_NPFWLBAR_CONFIG         = 0xA,
  ERR_MSR_BIOS_DONE           = 0xB,
  ERR_OVERCLOCKING_UNLOCKED   = 0xC,
  ERR_IMR_CONFIG              = 0xD,
  ERR_PAVPC_CONFIG            = 0xE,
  ERR_SEAMRR_CONFIG           = 0xF,
};

//
// Minor error codes for ERR_PRMRR_CONFIG
//
enum ENUM_ERR_PRMRR_CONFIG {
  ERR_PRMRR_LOCKED       = 0x1,
  ERR_PRMRR_NOT_LOCKED   = 0x2,
  ERR_PRMRR_CONFIG_ALIGN = 0x3,
};
//
// Minor error codes for ERR_IMR_CONFIG
//
enum ENUM_ERR_IMR_CONFIG {
  ERR_IMR_CONFIG_SIZE       = 0x1,
  ERR_IMR_CONFIG_OVERLAP    = 0x2,
  ERR_IA_EXC_NOT_LOCKED     = 0x3,
  ERR_IA_EXC_DISABLED       = 0x4,
  ERR_GT_EXC_NOT_LOCKED     = 0x5,
  ERR_GT_EXC_DISABLED       = 0x6,
  ERR_IMR_PCIALL_DISABLED   = 0x7,
  ERR_IMR_GLOBAL_WAC_POLICY = 0x8,
  ERR_IMR_GLOBAL_CP_POLICY  = 0x9,
};

//
// Minor error codes for ERR_SEAMRR_CONFIG
//
enum ENUM_ERR_SEAMRR_CONFIG {
  ERR_SEAMRR_NOT_LOCKED   = 0x1,
  ERR_SEAMRR_CONFIG_ALIGN = 0x2,
};

//-----------------------------------------------------------------------------
//
// LCP errors
//-----------------------------------------------------------------------------
#define CLASS_LAUNCH_CONTROL_POLICY 0x2E
enum ENUM_LAUNCH_CONTROL_POLICY {
  ERR_RESERVED         = 0x1,      //Reserved - don't use
  ERR_SINIT_REVOKED    = 0x2,      //SINIT is revoked
  ERR_BIOSAC_REVOKED   = 0x3,      //BIOSAC is revoked
  ERR_ELT_MISMATCH     = 0x4,      //No match found for policy element
  ERR_AUTOPROMOTE_FAIL = 0x5,      //BIOS hash differs from hash value
                                   //saved in AUX index
  ERR_FAILSAFE_FAIL         = 0x6, //Fail-safe mode failure
  ERR_PO_POL_INTEGRITY_FAIL = 0x7, //PO policy integrity check failure
  ERR_PS_POL_INTEGRITY_FAIL = 0x8, //PS policy integrity check failure
  ERR_NPW_REQ_POL           = 0x9, //NPW ACM file is detected but not
                                   //permitted due to no policy defined (PS
                                   //and / or PO)
  ERR_TPM_NOT_PROVISIONED = 0xA,   //TPM is missing NV index required for
                                   //TXT
  ERR_NO_PO_INDEX = 0x10,          //LCP files found in OSSinitData but PO
                                   //index is not present on TPM
};

//
// Minor error codes for ERR_SINIT_REVOKED. Start from 0x10 to avoid
// conflicts with policy engine generated errors.

enum ENUM_ERR_SINIT_REVOKED {
  ERR_SINIT_REVOKED_POL_CTR = 0x1,
  ERR_SINIT_REVOKED_PS      = 0x2, //SINIT Version is below minimum
                                   //specified in PS index
  ERR_SINIT_REVOKED_PO = 0x3,      //SINIT Version is below minimum
                                   //specified in PO index
};

//
// Minor error codes for ERR_PO_POL_INTEGRITY_FAIL or ERR_PS_POL_INTEGRITY_FAIL (part 1)
//
enum ENUM_ERR_PO_POL_INTEGRITY_FAIL {
  ERR_POLDATA_WRONG_SIGNATURE = 0x1,       //Header of LCP policy data file
                                           //has wrong ID string
  ERR_POLDATA_WRONG_NUMLISTS = 0x2,        //Header of LCP policy data file
                                           //has one of the following
                                           //errors: Reserved fields are not
                                           //0 or NumLists is either 0 or
                                           //more than 8
  ERR_POLDATA_CANNOT_ACCESS_DATA = 0x3,    //LCP policy data file is above
                                           //4GB
  ERR_POLDATA_DIGEST_MISMATCH = 0x4,       //LCP policy data file hash
                                           //mismatches value stored in TPM
                                           //NV index
  ERR_POLDATA_SIZE = 0x5,                  //Computed size of LCP data file
                                           //mismatches header value
  ERR_POL_WRONG_VERSION = 0x6,             //Unsupported TPM NV LCP policy
                                           //version
  ERR_POL_WRONG_HASH_ALG = 0x7,            //TPM NV LCP policy. Unsupported
                                           //hash algorithm
  ERR_POL_UNKNOWN_POLICY_TYPE = 0x8,       //TPM NV LCP policy. Unknown
                                           //policy type
  ERR_POL_NPW_NOT_ALLOW = 0x9,             //Running of NPW module is
                                           //disallowed by TPM NV LCP policy
  ERR_POL_AUX_DELETION_EN = 0xA,           //TPM NV LCP policy. Policy
                                           //Control. AUX deletion control
                                           //bit is set
  ERR_LIST_RSA_WRONG_KEY_SIZE = 0xB,       //LCP policy list. Unsupported
                                           //signing key size for RSASSA
                                           //signature
  ERR_LIST_WRONG_VERSION = 0xC,            //LCP policy list. Unsupported
                                           //version
  ERR_LIST_WRONG_SIZE = 0xD,               //LCP policy list. Computed size
                                           //mismatches header value
  ERR_LIST_WRONG_SIGNATURE_ALG = 0xE,      //LCP policy list. Unsupported
                                           //signature algorithm
  ERR_LIST_SIGNATURE_FAILURE = 0xF,        //LCP policy list. Invalid
                                           //signature
  ERR_LIST_REVOKED = 0x10,                 //LCP policy list. List is
                                           //revoked
  ERR_ELT_WRONG_HASH_ALG = 0x11,           //LCP policy element. Unsupported
                                           //hash algorithm
  ERR_ELT_WRONG_SIZE = 0x12,               //LCP policy element. Computed
                                           //size mismatches header value
  ERR_PCRINFO_INTEGRITY_FAIL = 0x13,       //PCONF element. One of the sizes
                                           //used in TPM 1.2 style
                                           //TPM_PCR_INFO_SHORT structure is
                                           //wrong
  ERR_NO_POLICY_DATA = 0x14,               //LCP element. Matching element
                                           //was found but disallowed to
                                           //match due to not suported hash
                                           //or signature algorithm or
                                           //placed in revoked list
  ERR_LIST_ECDSA_WRONG_KEY_SIZE = 0x15,    //LCP policy list. Unsupported
                                           //signing key size for ECDSA
                                           //signature
  ERR_LIST_SM2_WRONG_KEY_SIZE = 0x16,      //LCP policy list. Unsupported
                                           //signing key size for SM2_256
                                           //signature
  ERR_LIST_UNSUPPORTED_KEY_SIZE = 0x17,    //LCP policy list. Unsupported
                                           //signing key size
  ERR_LIST_UNSUPPORTED_HASH_ALG = 0x18,    //LCP Policy Hash Algorithm is
                                           //not selected in effective
                                           //LcpSignatureMask
  ERR_POL_NO_HASH_ALG = 0x19,              //LCP Policy LcpHashAlgorithmMask
                                           //is 0
  ERR_POL_UNSUPPORTED_HASH_ALG = 0x1A,     //LCP Policy Hash Algorithm is
                                           //not selected in effective
                                           //LcpAlgorithmMask
  ERR_POL_NO_SIGNATURE_ALG = 0x1B,         //LCP Policy LcpSignatureAlgMask
                                           //is 0
  ERR_POL_AUXHASH_INVALID_ALGMASK = 0x1C,  //LCP Policy AuxHashAlgMask has
                                           //more than 1 algorithm selected
                                           //or no algorithms selected
  ERR_POL_AUXHASH_UNSUPPORTED_ALG = 0x1D,  //Algorithm selected in LCP
                                           //Policy's AuxHashAlgMask is not
                                           //supported
  ERR_POL_AUXHASH_INCOMPAT_PCR_ALG = 0x1E, //Algorithm selected in LCP
                                           //Policy's AuxHashAlgMask is not
                                           //supported by TPM bank
  ERR_PCONF_ENFORCE = 0x1F,                //PO PCONF element has Override
                                           //set in EltControl and LCP
                                           //Policy has PCONF_Enforce set
};

//
// Minor error codes for ERR_PO_POL_INTEGRITY_FAIL or ERR_PS_POL_INTEGRITY_FAIL (part 2)
//
enum ENUM_ERR_PS_POL_INTEGRITY_FAIL {
  ERR_LIST_SIGNATURE_NOT_UNIQUE = 0x1,
  ERR_LIST_WRONG_KEY_ALG        = 0x2,
  ERR_POLDATA_OUT_OF_BOUNDS     = 0x3, // lcp data size is greater than the size specified in to os-sinit table.
};

//
// Minor code errors for ERR_TPM_NOT_PROVISIONED
//
enum ENUM_ERR_TPM_NOT_PROVISIONED {
  ERR_PS_INDEX_NOT_DEFINED = 0x0,
};

//-----------------------------------------------------------------------------
//
// Sanity check errors
//-----------------------------------------------------------------------------
#define CLASS_SANITY_CHECK 0x2F
enum ENUM_SANITY_CHECK {
  ERR_MCREG            = 0x1,
  ERR_VTD              = 0x2,
  ERR_DMAR             = 0x3,
  ERR_MCREG_INTERLEAVE = 0x4,
  ERR_MCZEROMEM        = 0x5,
  ERR_FIT_PATCH        = 0x6, //Holly PRT
};

#define CLASS_HEAP_TABLE_CHECK 0x30
enum ENUM_HEAP_TABLE_CHECK {
  ERR_SIZE           = 0x1,
  ERR_VERSION        = 0x2,    //Unsupported heap data table version
  ERR_PMRL_ALIGNMENT = 0x3,    //Incorrect PMR low range alignment
  ERR_PMRH_ALIGNMENT = 0x4,    //Incorrect PMR high range alignment
  ERR_MLE_LOCATION   = 0x5,    //One of the MLE placement errors: MLE base
                               //or page tables are above 4GB MLE size is
                               //above 4GB
  ERR_REQ_CAPABILITIES = 0x6,  //MLE requested and SINIT supported
                               //capabilities mismatch
  ERR_HEAPMEM_SIZE_OVER = 0x7, //Not enough room in heap memory for data
                               //allocation
  ERR_BAD_EXT_ELT_TYPE = 0x8,  //Unsupported heap extended element type
  ERR_BAD_EXT_ELT_SIZE = 0x9,  //Incorrect heap extended element size
  ERR_NOT_TERMINATED   = 0xA,  //Unterminated list of heap extended
                               //elements
  ERR_BAD_LOG_POINTER  = 0xB,  //Incorrect log pointer
  ERR_BAD_ACPI_POINTER = 0xC,  //ACPI RSDP/RSDT pointer requested via OS to
                               //SINIT data table is above 4GB
};

//
// Minor error codes for ERR_VERSION
//
enum ENUM_ERR_VERSION {
  ERR_VERSION_BIOS_DATA     = 0x1,
  ERR_VERSION_OS_SINIT_DATA = 0x2,
};

//
// Minor error codes for ERR_REQ_CAPABILITIES
//
enum ENUM_ERR_REQ_CAPABILITIES {
  ERR_REQ_CAPABILITIES_WAKEUP  = 0x1,
  ERR_REQ_CAPABILITIES_PCR_MAP = 0x2, //DMAR ACPI table
};
//
// Minor errors for ERR_REQ_TPR
//
enum ENUM_ERR_REQ_TPR {
  ERR_MISSING_TPR_REQ_ELE = 1,
  ERR_INSUFFICIENT_TPR
};

//
// Minor error codes for ERR_HEAPMEM_SIZE_OVER
//
enum ENUM_ERR_HEAPMEM_SIZE_OVER {
  ERR_HEAPMEM_SIZE_OVER_ACPI_1 = 0x1, //SINIT to MLE data table. MDR data
  ERR_HEAPMEM_SIZE_OVER_ACPI_2 = 0x2, //Total heap data size
  ERR_HEAPMEM_SIZE_OVER_ACPI_3 = 0x3,
  ERR_HEAPMEM_SIZE_OVER_HEAP_1 = 0x4,
  ERR_HEAPMEM_SIZE_OVER_HEAP_2 = 0x5,
  ERR_HEAPMEM_SIZE_OVER_HEAP_3 = 0x6,
  ERR_HEAPMEM_SIZE_OVER_ACPI_4 = 0x7,
  ERR_HEAPMEM_SIZE_OVER_ACPI_5 = 0x8,
  ERR_HEAPMEM_SIZE_OVER_ACPI_6 = 0x9,
  ERR_HEAPMEM_SIZE_OVER_ACPI_7 = 0xA,
  ERR_HEAPMEM_SIZE_OVER_ACPI_8 = 0xB,
  ERR_HEAPMEM_SIZE_OVER_ACPI_9 = 0xC,
  ERR_HEAPMEM_SIZE_OVER_ACPI_A = 0xD,
};

//
// Minor error codes for ERR_BAD_LOG_POINTER
//
enum ENUM_ERR_BAD_LOG_POINTER {
  ERR_BAD_LOG_POINTER_PTR = 0x1, //Requested log types via heap
                                 //extended log pointer element
                                 //mismatch supported TPM PCR bank
                                 //hash algorithms
  ERR_BAD_LOG_POINTER_BASE       = 0x2,
  ERR_BAD_LOG_POINTER_PTR2       = 0x3,
  ERR_BAD_LOG_POINTER_PTR2_REQ   = 0x4,
  ERR_BAD_LOG_POINTER_PTR2_MATCH = 0x5,
  ERR_BAD_LOG_POINTER_PTR2_ALG   = 0x6,
  ERR_BAD_LOG_POINTER_DUP_DSCR   = 0x7,
};

#endif /* ACMERR_H_ */
