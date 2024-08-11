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
#include <tpm.h>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  Wait10us
//
//  Input:	None
//
//  Output:	None
//
//  Description:	Stalls execution for 10 us.
//
//  TSC clock period = 1000000us / 2.4Ghz = 0.000416666 us
//
//  Bits toggle (half-period):
//  Bit 0 = 0.000416666 us
//  ...
//  Bit 12 = 1.706663936 us
//
//  Toggles of Bit 12 per 10us = 10 / 1.706663936 = 5.86 ~~ 6 toggles
//  Since front is asynck to start loop, select one more - 7 toggles
//  6 * 1.706663936=10.239983616 : 7 * 1.706663936 = 11.946647552 us
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void __Wait10us()
{
  UINT32 Idx, Prev, New;

  for (Idx = 0; Idx < 7; Idx++) {
    Prev = BIT12 & (UINT32) readTsc64();

    do {
      New = BIT12 & (UINT32) readTsc64();
    } while (Prev == New);
  }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:	TinyWaitRegisterValue
//
//  Input:	RegAddr - MMIO register address
//          Width - register width in bytes: 1,2,4 are legal values
//          Mask - bit mask to AND with register value
//          Cond - condition to apply to masked register value: EQUAL
//                 and NOT_EQUAL are legal values
//          ExpVal - value to be "Cond" related to masked register
//                   value
//          Timeout - timeout in 10th of usec to wait for "Cond"
//
//  Output:	0 if value is met or 1 if timeout occurred.
//
//  Description:	Waits up to "Timeout" msec for masked register value
//  to be "Cond" to expected value. Register is read as byte, word or
//  dword as specified in "Width" parameter.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 TinyWaitRegisterValue(UINT32 RegAddr,
                             UINT32 Width,
                             UINT32 Mask,
                             UINT32 Cond,
                             UINT32 ExpVal,
                             UINT32 Timeout
                             )
{
  UINT32 Current, Idx;

  for (Idx = 0; Idx < Timeout; Idx++) {
    Current = Mask &
              ((UINT32) ((Width == 1) ?
                         __ReadMmioByte(RegAddr) :
                         ((Width == 2) ?  __ReadMmioWord(RegAddr) : __ReadMmioDword(RegAddr))));

    if ((Cond == EQUAL) && (Current == ExpVal)) {
      return 0;
    } else if ((Cond == NOT_EQUAL) && (Current != ExpVal)) {
      return 0;
    }

    __Wait10us();
  }
  return 1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:	BaseWaitMsrValue
//
//  Input:	MsrAddr - MSRr address
//          Mask - bit mask to AND with register value
//          Cond - condition to apply to masked register value: EQUAL
//                 and NOT_EQUAL are legal values
//          ExpVal - value to be "Cond" related to masked register
//                   value
//          Step  - 10usec or 1msec denoted as 0 and 1
//          Timeout - timeout in 10th of usec or in ms to wait for "Cond"
//
//  Output:	0 if value is met or 1 if timeout occurred.
//
//  Description:	Waits up to "Timeout" msec for masked register value
//  to be "Cond" to expected value. MSR is read as qword.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 BaseWaitMsrValue(UINT32 MsrAddr,
                        UINT64 Mask,
                        UINT32 Cond,
                        UINT64 ExpVal,
                        UINT32 Timeout,
                        UINT32 Step
                        )
{
  UINT64 Current;
  UINT32 Idx;

  for (Idx = 0; Idx < Timeout; Idx++) {
    Current = Mask & __readMsr64(MsrAddr);

    if ((Cond == EQUAL) && (Current == ExpVal)) {
      return 0;
    } else if ((Cond == NOT_EQUAL) && (Current != ExpVal)) {
      return 0;
    }

    (Step == In1MSEC) ? Wait1ms() : __Wait10us();
  }
  return 1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  __WaitRegisterBitSet
//
//  Input:  Reg - register in MMIO space.
//          Mask - bit to wait to be asserted
//
//  Output:	0 if value is met or 1 if timeout occurred.
//
//  Description: Waits with timeout 1ms for single bit in
//  MMIO register to be asserted. Exits immediately upon assertion.
//  Despite that status is returned, it is expected that caller will
//  ignore it, since not clear what action needs to be taken. If LT
//  status bit is not asserted after 1ms past LT command CS is broken.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 __WaitRegisterBitSet(UINT32 Reg,
                            UINT32 Mask
                            )
{
  return TinyWaitRegisterValue(
    Reg,
    4,
    Mask,
    EQUAL,
    Mask,
    100
    );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  __WaitRegisterBitClear
//
//  Input:  Reg - register in MMIO space.
//          Mask - bit to wait to be cleared
//
//  Output:	0 if value is met or 1 if timeout occured.
//
//  Description: Waits with timeout 1ms for single bit in
//  MMIO register to be de-asserted. Exits immediately upon de-assertion.
//  Despite that status is returned, it is expected that caller will
//  ignore it, since not clear what action needs to be taken. If LT
//  status bit is not de-asserted after 1ms past LT command CS is broken.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 __WaitRegisterBitClear(UINT32 Reg,
                              UINT32 Mask
                              )
{
  return TinyWaitRegisterValue(
    Reg,
    4,
    Mask,
    EQUAL,
    0,
    100
    );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  __Wait1ms
//
//  Input:	None
//
//  Output:	None
//
//  Description:	Stalls execution for 1 ms.
//  +--------------------------------------------------------------------+
//  |This procedure is specially designed to be called from trampoline   |
//  |code. It is NOT very accurate but it can be called from code which  |
//  |has not been fixed up.                                              |
//  +--------------------------------------------------------------------+
//  TSC clock period = 1000000us / 2.4Ghz = 0.000416666 us
//
//  Bits toggle (half-period):
//  Bit 0 = 0.000416666 us
//  ...
//  Bit 17 = 54.613245952 us
//  Bit 18 = 109.226491904 us
//
//  Toggles of Bit 18 per 1ms = 1000 / 109.226491904 = 9.155 ~~ 10 toggles
//  Since front is asynck to start loop, select one more - 11 toggles
//  10 * 109.226491904 : 11 * 109.226491904 = 1092.26491904 : 1201.491410944 us
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void __Wait1ms()
{
  UINT32 Idx, Prev, New;

  for (Idx = 0; Idx < 11; Idx++) {
    Prev = BIT18 & (UINT32) readTsc64();

    do {
      New = BIT18 & (UINT32) readTsc64();
    } while (Prev == New);
  }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  Wait1ms
//
//  Input:	None
//
//  Output:	None
//
//  Description:	Stalls execution for 1 ms.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Wait1ms()
{
  UINT64 Now, Then, TscClkPerMsec;

#if (SIMICS_BLD == 1)
  TscClkPerMsec = 0x15 * 133330;
#else
  TscClkPerMsec = calibrateTsc64();
#endif

  Now = readTsc64();
  Then = Now + TscClkPerMsec;

  do {
    Now = readTsc64();
  } while (Now < Then);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  Wait100ms
//
//  Input:	None
//
//  Output:	None
//
//  Description:	Stalls execution for 100 ms.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void WaitFixedTime(UINT32 Time)
{
  UINT32 Idx;

  for (Idx = 0; Idx < Time; Idx++) {
    Wait1ms();
  }
}
