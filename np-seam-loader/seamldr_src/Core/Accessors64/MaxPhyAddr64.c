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

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  GetMaxPhyAddr
//
//  Input:      None
//
//  Output:     MAXPHYADDR value.
//
//  Description: Uses CPUID function in order to retrieve MAXPHYADDR
//  value
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 GetMaxPhyAddr ()
{
  UINT32 CpuInfo[4];                    // 0-eax, 1-ebx, 2-ecx, 3-edx

  //
  // Obtain MAXPHYADDR.
  //
  __cpuid(CpuInfo, 0x80000000);

  if (CpuInfo[0] >= 0x80000008)
    __cpuid(CpuInfo, 0x80000008);
  else
    CpuInfo[0] = 36;

  return (CpuInfo[0] & 0xFF);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  GetPhyAddrMask
//
//  Input:      None
//
//  Output:     MAXPHYADDR value.
//
//  Description: Converts MAXPHYADDR to mask value. i.e  for 36 bits
//  returns 0xFFFFFFFFF 
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT64 GetPhyAddrMask ()
{
  return shiftLeft64 (1,  GetMaxPhyAddr ()) - 1;     // Sighting #3865410
}

