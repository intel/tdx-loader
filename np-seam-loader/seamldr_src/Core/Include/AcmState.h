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

#ifndef __ACMSTATE_H__
#define __ACMSTATE_H__

#include <trace.h>

#define ACM_STATE(X) ACMSTATE_ ## X

enum ENUM_ACM_STATE {
  ACMSTATE_POSSIBLE_ROGUE_BIOS,
  ACMSTATE_DONOTHING_ON_EXIT,
  ACMSTATE_UNLOCKED_NEEDED,
  ACMSTATE_VERFIY_BIOS_REQUIRED,
  ACMSTATE_INNODE_SPECIFIC_CODE,
  ACMSTATE_SBSP,
  ACMSTATE_NOTPM,
  ACMSTATE_S3,
  ACMSTATE_COIN_BATTERY_REMOVED,
  ACMSTATE_TXT_POLICY_PRESENT,
  ACMSTATE_HOTPLUG,
  ACMSTATE_RESTORE_ICH_PMBASE,
  ACMSTATE_TRAPERROR,
  ACMSTATE_SECRETS_PRESENT,
  ACMSTATE_NO_DEBUG_PORT,
  ACMSTATE_TRAP_ERROR,
  ACMSTATE_TRACE_RENDEZVOUS,
  ACMSTATE_TRAP_RENDEZVOUS_ERRORS,
  ACMSTATE_DISABLE_TIMEOUTS,
  ACMSTATE_FOUR_SOCKET_WORKAROUND,
  ACMSTATE_BOOT_TEST,
  ACMSTATE_CPURESET_ON_ERROR,
  ACMSTATE_QPI_LATE_ADD, /* Set when BIOS Scratchpad7 register = 1, indicating QPI late-add on this socket */
  ACMSTATE_BOOTGUARD_ENABLED,
  ACMSTATE_TPM_INITIALIZED,
  ACMSTATE_BTG_BIOS_VERIFIED,
  ACMSTATE_BTG_MANIFEST_VALID
};

extern void __AcmLocalStateClear(UINT8 sts);
#define AcmLocalStateClear(X) __AcmLocalStateClear(ACM_STATE(X))
extern void __AcmLocalStateSet(UINT8 sts);
#define AcmLocalStateSet(X)   __AcmLocalStateSet(ACM_STATE(X))
extern UINT8 __IsAcmLocalStateSet(UINT8 sts);
#define IsAcmLocalStateSet(X) __IsAcmLocalStateSet(ACM_STATE(X))

#endif
