# Copyright (C) 2023 Intel Corporation                                          
#                                                                               
# Permission is hereby granted, free of charge, to any person obtaining a copy  
# of this software and associated documentation files (the "Software"),         
# to deal in the Software without restriction, including without limitation     
# the rights to use, copy, modify, merge, publish, distribute, sublicense,      
# and/or sell copies of the Software, and to permit persons to whom             
# the Software is furnished to do so, subject to the following conditions:      
#                                                                               
# The above copyright notice and this permission notice shall be included       
# in all copies or substantial portions of the Software.                        
#                                                                               
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS       
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL      
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES             
# OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE            
# OR OTHER DEALINGS IN THE SOFTWARE.                                            
#                                                                               
# SPDX-License-Identifier: MIT

#*****************************************************************************
#
# Build control flags.
#
#*****************************************************************************
MKF_FLAGS = $(MKF_FLAGS)

#-----------------------------------------------------------------------------
# Uncomment to build for Simics Simulation
#-----------------------------------------------------------------------------

SIMICS_BLD=0
ifdef $(SEAMLDR_SIMICS_BUILD)
SIMICS_BLD:=$(SEAMLDR_SIMICS_BUILD)
endif
MKF_FLAGS = $(MKF_FLAGS) /DSIMICS_BLD=$(SIMICS_BLD)

MKF_FLAGS = $(MKF_FLAGS) /DMKF_USE_MAKEFLAG_H=1

#-----------------------------------------------------------------------------
# Uncomment to use USB I/F instead of COM I/F
#-----------------------------------------------------------------------------

MKF_USB_TRACE=0
#MKF_FLAGS = $(MKF_FLAGS) /DMKF_USB_TRACE=1

#-----------------------------------------------------------------------------
# Uncomment to enable SMC support in Tremont (Atom) CPUs
#-----------------------------------------------------------------------------

#MKF_FLAGS = $(MKF_FLAGS) /DMKF_ATOM_SUPPORT=1


#-----------------------------------------------------------------------------
# Uncomment to force ACM Build Size to be 256KB (pad ACM binary with 0s)
# Otherwise ACMPE2BINx will allow ACM to be any build size
#-----------------------------------------------------------------------------

#ACMBINSIZE = 256

#-----------------------------------------------------------------------------
# Uncomment to enable PFR support
#-----------------------------------------------------------------------------

MKF_PFR_SUPPORTED=1
MKF_FLAGS = $(MKF_FLAGS) /DMKF_PFR_SUPPORTED=1

#-----------------------------------------------------------------------------
# Set if platforms do not have PCH (use S3M2.0+ for boot services)
#-----------------------------------------------------------------------------

MKF_IBL_SUPPORTED=1
MKF_USE_MAKEFLAG_H=1

#MKF_FLAGS = $(MKF_FLAGS) /DMKF_EPS_SUPPORTED=1

MKF_64BIT_CODE_SUPPORT=1
MKF_FLAGS = $(MKF_FLAGS) /DMKF_64BIT_CODE_SUPPORT=1

#-----------------------------------------------------------------------------
# Uncomment to enable Benchmarking Support (ENGINEERING TESTS ONLY)
#-----------------------------------------------------------------------------
MKF_BENCHMARKING=0

#-----------------------------------------------------------------------------
# Uncomment to disable optimization for all core and project "C" files
#-----------------------------------------------------------------------------

#CORE_FLAGS = $(CORE_FLAGS) "ALL_CL_FLAGS = /Od"

#-----------------------------------------------------------------------------
# Uncomment to disable optimization for local "C" files
#-----------------------------------------------------------------------------

#LOCAL_CL_FLAGS = $(LOCAL_CL_FLAGS) /Od

#-----------------------------------------------------------------------------
# Uncomment to disable optimization for local 64-bit "C" files
#-----------------------------------------------------------------------------

#LOCAL_CL64_FLAGS =  $(LOCAL_CL_FLAGS) /Od

#-----------------------------------------------------------------------------
# Uncomment selectively few of the following lines to disable optimization
# for selected core component "C" files
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# LCP elements selection controls. Must be defined in preprocessing as well
# as in code.
#-----------------------------------------------------------------------------

MKF_LCP_POLELT_TYPE_MLE_SUPPORTED=0
MKF_LCP_POLELT_TYPE_PCONF_SUPPORTED=0
MKF_LCP_POLELT_TYPE_SBIOS_SUPPORTED=0
MKF_LCP_POLELT_TYPE_STM_SUPPORTED=0

LCP_ELT_SELECTION=0
ifeq ($(MKF_LCP_POLELT_TYPE_MLE_SUPPORTED),1)
LCP_ELT_SELECTION:=$(LCP_ELT_SELECTION)+LCP_POLELT_TYPE_MLE_SUPPORTED
endif
ifeq ($(MKF_LCP_POLELT_TYPE_PCONF_SUPPORTED),1)
LCP_ELT_SELECTION:=$(LCP_ELT_SELECTION)+LCP_POLELT_TYPE_PCONF_SUPPORTED
endif
ifeq ($(MKF_LCP_POLELT_TYPE_SBIOS_SUPPORTED),1)
LCP_ELT_SELECTION:=$(LCP_ELT_SELECTION)+LCP_POLELT_TYPE_SBIOS_SUPPORTED
endif
ifeq ($(MKF_LCP_POLELT_TYPE_STM_SUPPORTED),1)
LCP_ELT_SELECTION:=$(LCP_ELT_SELECTION)+LCP_POLELT_TYPE_STM_SUPPORTED
endif

#-----------------------------------------------------------------------------
# SW supported crypto algorithm selection.
#-----------------------------------------------------------------------------
MF_ALG_SHA1_PRESENT=0
MF_ALG_SHA256_PRESENT=0
MF_ALG_SHA384_PRESENT=0
MF_ALG_SHA512_PRESENT=0
MF_ALG_SM3_256_PRESENT=0
MF_ALG_RSASSA_PRESENT=0
MF_ALG_RSAPSS_PRESENT=0
MF_ALG_ECDSA_PRESENT=0
MF_ALG_SM2_PRESENT=0

#used to be IPP build switch in develop
#invalid for new branch
#MKF_USE_MIXED_CRYPTO=1
#
MKF_USE_INTERNAL_HASH=0

ACM_TYPE=AC_BIOSAC
PLATFORM_TYPE=SERVER

#CORE_FLAGS = $(CORE_FLAGS) "COMBIOSAC_CL_FLAGS = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "COMMON_CL_FLAGS    = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "COMSINIT_CL_FLAGS  = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "HASH_CL_FLAGS      = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "LCP_CL_FLAGS       = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "PCI_CL_FLAGS       = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "RANGES_CL_FLAGS    = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "RSA_CL_FLAGS       = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "TPM_CL_FLAGS       = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "TRACE_CL_FLAGS     = /Od"
#CORE_FLAGS = $(CORE_FLAGS) "SERIAL_CL_FLAGS    = /Od"

ACTM_PLAT_EMR = 2
ACTM_PLAT_GNR = 3
ACTM_PLAT 	= ACTM_PLAT_EMR

MKF_FLAGS = $(MKF_FLAGS) /DACTM_PLATFORM=$(ACTM_PLAT_EMR)

LOCAL_CL_FLAGS = $(LOCAL_CL_FLAGS) $(MKF_FLAGS) /I..\Include
LOCAL_CL64_FLAGS =  $(LOCAL_CL64_FLAGS) $(MKF_FLAGS)



#-----------------------------------------------------------------------------
# TPM selection controls.
# To enable Set selection to 1
# To disable set to 0
#-----------------------------------------------------------------------------


MKF_CAP_TPM_FAM_20=1
MKF_CAP_TPM_ITF_CRB=1
MKF_CAP_TPM_ITF_FIFO=1

#*****************************************************************************
#
# Module control parameters - most frequently changing.
#
#*****************************************************************************

# Sighting #3864887  (0KB .text alignment)
TEXT_ALIGNMENT = 0KB


# New AuxRevocationCheck - ACM_VERSION value must be updated as follows:
# debug SINIT: '0'
# NPW SINIT:   '1'
# PW  SINIT:   '2'
# any security issue will increment this SVN +1
# (max supported SINIT_SVN in LT_CSS is '15' now...)
# this value will be updated in BIOS ACM's 0x6e4 offset
#   and saved into TPM AUX SINIT_SVN field
#   SINIT ACM will compare its ACM_HEADER.AcmSvn value against
#   the TPM AUX SINIT_SVN field and revoke if needed.

#*****************************************************************************
#
# Update ACM_VERSION when doing PW SINIT release, +4 every release
# pe2bintool follows rules mentioned in ACM release guide section
# ACM versioning
#
#*****************************************************************************
ACM_VERSION=0x00

#*****************************************************************************
#
# Update ACM_REVISION, with every official release of firmware
#
#*****************************************************************************
ACM_REVISION    = {0x0,0x4,0x5}

#*****************************************************************************
#
# Platform Phase (NA=0, PreSi=1, PostSi=2, PV=3, PRQ+=4, IPU=5)
#
#*****************************************************************************
PLAT_PHASE = 0x0

HEADER_VERSION = ACM_HEADER_V_3
STACK_SIZE      = (0x10000 + $(MCP_SHADOW_STACK_GAP))
ifeq ($(ENG_STRING),ENG)
STACK_SIZE:=$(STACK_SIZE)-0x2000
endif
# Below commented out as GNUmakefile do not use it
# Kept for developer to know the background
# BIOS ACM VERSION_PRT, NPW_ITERATION_PRT
# fields below are deprecated for CBnT BIOS ACM now.  Leave as-is.
# The ACM Version is used for TXT internal tracking
# VERSION_PRT         =     0x01 # Increment this number for each new release.  This gets added to
                                 # 033h to generate the PW version value.
# NPW_ITERATION_PRT   =     0x01 # This number s/b 1 for first NPW, 2 for second, or 3 for third.
                                 # If more than 3 NPWs are built, then VERSION has to be bumped up
                                 # and NPW_ITERATION reset to 1

# Module Flag - determines if NPW or PW
MODULE_FLAGS=MF_PROD_WORTHY

#*****************************************************************************
#
# makeflah.h header file is automatically generated.
# Edit text below to change header values and other infrequently changing
# parameters. It is expected to be set only once when project is started.
#
#*****************************************************************************

define MAKEFLAG_AUTO
#ifndef MAKEFLAG_H
#define MAKEFLAG_H
#define MKF_ENTRY_DEAD_LOOP         0
//
// Platform type
//
#define MCP_PLATFORM_TYPE           $(PLATFORM_TYPE)
//
// Header version
//
#define MF_HEADER_VERSION           $(HEADER_VERSION)
//
// Module flags control production/debug and PW/NPW module
//
#define MCP_MODULE_FLAGS            $(MODULE_FLAGS)
//
// Module version
//
#define MCP_ACM_VER                 $(ACM_VERSION)
#define MCP_ACM_REVISION            $(ACM_REVISION)
#define MCP_PLAT_PHASE              $(PLAT_PHASE)
//


//
// Min. SINIT to support on platform
// Biosac will write this value to aux index, and SINIT revocation logic will revoke itself 
// if it doesn't meet this value.
//
#define MCP_ACM_VER                 $(ACM_VERSION)
//
// Module type
//
#define MCP_MODULE_TYPE             CS_MODULE_TYPE
//
// Module sub-type
//
#define MCP_MODULE_SUBTYPE          CLIENT_MODULE_SUBTYPE   // 0

#define MCP_REVISION_ID 1
#define MCP_REVISION_ID_MASK BIT0


//-----------------------------------------------------------------------------
// Header parameters - established once in the beginning of project
//-----------------------------------------------------------------------------
// Module ID
//
#define MCP_MODULE_ID                   0       // no chipset
//
// Module type - SINIT or BIOS AC.
//
#define MCP_CHIPSET_ACM_TYPE        $(ACM_TYPE)
//
// AC Info table version
//
#define ACM_INFO_TAB_VER            0x7
//
// OS SINIT table version
//
#define OS_SINIT_TAB_VER            0
//
// Module capabilities.
//
#define MCP_ACM_CAPABILITIES        0   // no SINIT capabilities

//
// Security Version Number
//
#define MCP_ACM_SVN                 0
#define MCP_SE_SVN                  6    // Update to >=1 for PV and post PV releases

//
// LTSX / Client TXT Flag
//
#define LTSX_SERVER_TXT             LTSX_FUSED
//
// Module chipset ID structure fields
//
#define LCP_ELT_SELECTION           $(LCP_ELT_SELECTION)
//
// TXT Error register
//
#define TXT_ERROR_REGISTER          LT_PRV_BASE + offsetof (TXT, LT_BIOSACMCode)
//
// S_CRTM root
//
#define S_CRTM_ROOT                 CPU_ROOTED_S_CRTM
//
// Good values forced into certain registers
//
#define MCHBAR_ADDR                 0xFED10000

//
// Module chipset ID structure fields
//
#define   MF_CS_PRESENT_1           1
#define   MF_REVID_MASK_1           MCP_REVISION_ID_MASK
#define   MF_DEVICE_ID_1            MCP_MODULE_ID       //S3M LT_DID
#define   MF_REVISION_ID_1          MCP_REVISION_ID

#define   MF_CS_PRESENT_2           0
#define   MF_REVID_MASK_2           0
#define   MF_DEVICE_ID_2            0
#define   MF_REVISION_ID_2          0

#define   MF_CS_PRESENT_3           0
#define   MF_REVID_MASK_3           0
#define   MF_DEVICE_ID_3            0
#define   MF_REVISION_ID_3          0

#define   MF_CS_PRESENT_4           0
#define   MF_REVID_MASK_4           0
#define   MF_DEVICE_ID_4            0
#define   MF_REVISION_ID_4          0




//
// Processor Family/Model/Stepping and Platform ID Equates
//
#define   GNR_FMS                   0xA06D0
#define   FMS_MASK                  0xFFF3FF0

// TODO: review PLATFORM_ID
#define   PLATFORM_ID               0               // IA32_PLATFORM_ID definition changed in BWG,
#define   PLATFORM_ID_MASK          0x001C000000000000

#define     MF_PROC_PRESENT_1       1
#define     MF_FMS_1                GNR_FMS
#define     MF_FMS_MASK_1           FMS_MASK
#define     PLATFORM_ID_1           0x0000000000000000
#define     PLATFORM_ID_MASK_1      0x0000000000000000

#define     MF_PROC_PRESENT_2       0
#define     MF_FMS_2                0
#define     MF_FMS_MASK_2           0
#define     PLATFORM_ID_2           0
#define     PLATFORM_ID_MASK_2      0

#define     MF_PROC_PRESENT_3       0
#define     MF_FMS_3                0
#define     MF_FMS_MASK_3           0
#define     PLATFORM_ID_3           0
#define     PLATFORM_ID_MASK_3      0

#define     MF_PROC_PRESENT_4       0
#define     MF_FMS_4                0
#define     MF_FMS_MASK_4           0
#define     PLATFORM_ID_4           0
#define     PLATFORM_ID_MASK_4      0

//
// TPM family and interface support
//
#define MKF_CAP_TPM_FAM_20          $(MKF_CAP_TPM_FAM_20)
#define MKF_CAP_TPM_ITF_CRB         $(MKF_CAP_TPM_ITF_CRB)
#define MKF_CAP_TPM_ITF_FIFO        $(MKF_CAP_TPM_ITF_FIFO)

#define MKF_PFR_SUPPORTED           $(MKF_PFR_SUPPORTED)
#define SIMICS_BLD                  $(SIMICS_BLD)
#define TXT_STATUS                  $(TXT_STATUS)


//
// TPM_CAPABILITIES
//                 
#define    MCP_ACM_TPM_CAPABILITIES 0

//                                  
// Minimal required hash strength for naleAlg

#define     MIN_DIGEST_SIZE         32

//
// Project specific sizes
//
#define LT_DPR_MEM_SIZE             0x300000
#define HEAP_MEM_SIZE               0xE0000
//
// TPM crypto support
//
#define MF_ALG_SHA1_PRESENT         $(MF_ALG_SHA1_PRESENT)
#define MF_ALG_SHA256_PRESENT       $(MF_ALG_SHA256_PRESENT)
#define MF_ALG_SHA384_PRESENT       $(MF_ALG_SHA384_PRESENT)
#define MF_ALG_SHA512_PRESENT       $(MF_ALG_SHA512_PRESENT)
#define MF_ALG_SM3_256_PRESENT      $(MF_ALG_SM3_256_PRESENT)
#define MF_ALG_RSASSA_PRESENT       $(MF_ALG_RSASSA_PRESENT)
#define MF_ALG_RSAPSS_PRESENT       $(MF_ALG_RSAPSS_PRESENT)
#define MF_ALG_ECDSA_PRESENT        $(MF_ALG_ECDSA_PRESENT)
#define MF_ALG_SM2_PRESENT          $(MF_ALG_SM2_PRESENT)
#define MKF_USE_INTERNAL_HASH       $(MKF_USE_INTERNAL_HASH)

#define MKF_LTSX_MODE               $(MKF_LTSX_MODE)

#define MKF_USB_TRACE               $(MKF_USB_TRACE)

#define SIMICS_BLD                  $(SIMICS_BLD)


//-----------------------------------------------------------------------------
// Stack size
//-----------------------------------------------------------------------------
#define STACK_SIZE                  $(STACK_SIZE)
#endif
endef # end of define MAKEFLAG_AUTO
