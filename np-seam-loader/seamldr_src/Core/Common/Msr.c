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
unsigned __int64 __rdtsc(void);
#pragma intrinsic(__rdtsc)
unsigned __int64 __readmsr(int register);
#pragma intrinsic(__readmsr)
void __writemsr(unsigned long, unsigned __int64);
#pragma intrinsic(__writemsr)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  readMsr
//
//  Input:  msr - MSR number to read
//
//  Output:  pHiDword and pLoDword - pointers to high and low return values
//
//  Description: Parts of MSR value are returned if pointers are not NULL
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void __readMsr(UINT32 msr_register, UINT32 *pHiDword, UINT32 *pLoDword)
{
  UINT64 msr_value = 0;

  msr_value = __readMsr64(msr_register);
  if (pHiDword != 0) {
    *pHiDword = (UINT32)(msr_value >> 32);
  }
  if (pLoDword != 0) {
    *pLoDword = (UINT32)((msr_value & (UINT64)0xFFFFFFFF));
  }
  return;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  readMsr64
//
//  Input:  msr - MSR number to read
//
//  Output:  Return 64 bits MSR register contents
//
//  Description: MSR value is returned as 64-bit value.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

UINT64 __readMsr64(UINT32 msr_register)
{
  return __readmsr((INT32)msr_register);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  writeMsr
//
//  Input:  msr - MSR number to read
//
//  Output:  None
//
//  Description: MSR is written with passed-in values.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void __writeMsr(UINT32 msr_register, UINT32 hiDword, UINT32 loDword)
{
  UINT64 value = ((UINT64)hiDword << 32) | (UINT64)loDword;

  __writemsr(msr_register, value);
  return;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  readTsc64
//
//  Input:  None
//
//  Output:  Return rdtsc value
//
//  Description: TSC value is returned as 64-bit value.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

UINT64 readTsc64(void)
{
  return __rdtsc();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  calibrateTsc64
//
//  Input:  None
//
//  Output:  TSC Clk/Msec is returned as 64-bit value
//
//  Description: TSC Clk/Msec is returned as 64-bit value.
//               MSR_PLATFORM_INFO[15:8] * 133.33 MHz is frequency of TSC
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

UINT64 calibrateTsc64(void)
{
  UINT64 msr_value = 0;
  UINT64 result = 0;

  msr_value = __readMsr64(MSR_PLATFORM_INFO);
  result = ((msr_value & (UINT64)0xFF00) >> 8) * 133330;
  return result;
}
