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

#include <common.h>
#include <trace.h>

ERR_CONTEXT ErrCtx;
VOID_ARG_UINT32_UINT32 AcmErrorHandlerPtr;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:
//
//  Input:	Class - Class code or special VOID value.
//          Major - Major error code or special VOID value.
//
//  Output:	None
//
//  Description:
//
//   Crash register bit fields
//
//   31 Valid
//   30 SW generated
//   29 ------------
//    |
//   28 Res
//   27 ------------
//    |
//    | Minor Err and Progress Code
//    |
//    |
//   16 ------------
//   15 Err Source = 0 for ACM
//   14 ------------
//    | Major Err
//   10 ------------
//    9 ------------
//    | Class Code
//    4 ------------
//    3 ------------
//    | ACM Type = 1 for SINIT
//    0 ------------
//
// Max Class Code         0x3F
// Max Error Code         0x1F
// Max Minor Error Code   0x3FFF
// Max LCP Index          0x7
//
// Minor error codes can be set explicitely with call to ErrorHandler
// or can be set in advance to reflect special values.
//
// Special cases of minor error codes:
// 1. LcpErrorHandler if major error code is ERR_*_POL_INTEGRITY_FAIL
//    places respective list index into bits 29:16 of crash register.
//    Entire minor code then become:
//    [14:6] - LCP list index
//    [5:0]  - Minor error code
//
// 2. Range Check returns:
//    validateRangePlacement(pra[]):
//    validateArrayPlacement{pra[]}
//    arrayCheck(pra[])
//    isMetForAllRanges (*pr, *pra[])
//
//      Index i of failing range in array pra[]
//
//    isArraySeparate (pra[])
//
//      Index i of FIRST failing range in array pra[]
//
// 3. If TPM returns an error then this error is returned in minor
//    error field.
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void CoreAcmErrorHandler(UINT32 Class, UINT32 Major)
{
  CRASH_REGISTER CrashCode;

  //
  // If any parameter is VOID - assume that it was set outside
  // context of this handler. ErrCtx.Minor is always assumed to be
  // set outside handler context.
  //
  if (Class != VOID) {
    ErrCtx.Class = Class;
  }

  if (Major != VOID) {
    ErrCtx.Major = Major;
  }
  //
  // The following also initializes all other fields to 0
  //
  *(UINT32 *) &CrashCode = CRASH_CODE_VALID + CRASH_CODE_SW_GENERATED + ChipsetAcmType;

  CrashCode.Minor = ErrCtx.Minor;

  CrashCode.Major = ErrCtx.Major;
  CrashCode.Class = ErrCtx.Class;

  TRACE("\nError: Class = %lx, Major = %lx, Minor = %lx\n", ErrCtx.Class, ErrCtx.Major, ErrCtx.Minor);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  LtReset
//
//  Input:      None
//
//  Output:     None
//
//  Description:Function generates LT reset.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void LtReset()
{
  //
  // change to prevent multiple back-to-back LtReset. CSME cannot handle
  //
  WritePrivateDword(LT_CMD_SYS_RESET, 0);

  Wait100ms();

  //
  // Removed - don't use MMIO based reset in ACM - it can be easily
  // trapped.
  //
  // Sighting #3864605 Start
DeadLoop:
  __halt();
  goto  DeadLoop;
  // Sighting #3864605 End
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:	ProgressMark
//
//  Input:      code - progress code
//
//  Output:     None
//
//  Description:	Programs crash register with progress code. Zaps
//  error context for execution of new task. Is expected to be used
//  only between tasks.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void ProgressMark(UINT8 code)
{
  UINT32 CrashCode;

  if ((*(volatile CRASH_REGISTER *)TxtErrorRegister).Class != CLASS_ACM_PROGRESS) {
    return;
  }

  //
  // Initialize all fields of image of crash register.
  //
  //CrashCode = CRASH_CODE_VALID +
  //                   CRASH_CODE_SW_GENERATED +
  //                   (code << 16) +
  //                   ChipsetAcmType;

  //do not set valid bit 31 for progress mark
  CrashCode = 0x00000000 +
              (code << 16) +
              ChipsetAcmType;
  //
  // Program crash register with progress mark value
  //
  *(volatile UINT32 *)TxtErrorRegister = CrashCode;

  //
  // Reset error context variable to clear stale data and get ready for
  // next task.
  //
  ErrCtx.Class = ErrCtx.Major = ErrCtx.Minor = 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:	INTErrorHandler
//
//  Input:	None
//
//  Output:	None
//
//  Description:	Project specific interrupt error handler
//               - interface procedure to core code.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#ifndef INTErrorHandler
__declspec(naked) void INTErrorHandler()
{
  __ErrorHandler(CLASS_MISC_CONFIG, ERR_INTERRUPT);
}
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:	ErrorHandler
//
//  Input:	ClassCode - error class code
//          ErrorCode - error code within class code
//
//  Output:	None
//
//  Description:	Project specific error handler -
//               - interface procedure to core code.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void __ErrorHandler(UINT32 ClassCode, UINT32 ErrorCode)
{
#ifndef NO_CORE_ERRORHANDLE

  (*AcmErrorHandlerPtr)(ClassCode, ErrorCode);

#endif
}
