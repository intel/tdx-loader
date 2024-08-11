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
#include <Server/Include/common64.h>
#include <Header.h>
#include <common32.h>

#include <PSeamldrSize.h>

P_SEAMLDR_CONSTS_t PSeamldrConstAsm;
UINT32 PSeamldrSizeAsm = PSEAMLDR_SIZE;
UINT8 PSeamldrAsm[PSEAMLDR_SIZE] = { 0 };

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  Init64bitComArea
//
//  Input:      None
//
//  Output:     None
//
//  Description: All fields of Init64bitComArea communication area with
//  64-bit code are initialized.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Init64bitComArea()
{
  //
  // Initialize 32-64 bit communication data
  //

  fillMemory(SeamldrCom64Data.OriginalGdtr, 0, sizeof(SeamldrCom64Data.OriginalGdtr));
  *(UINT16 *)SeamldrCom64Data.OriginalGdtr = (UINT16)(OriginalECX >> 16);

  SeamldrCom64Data.OriginalCR4 = OriginalCR4;
  SeamldrCom64Data.HeaderStart = (UINT64)(UINTPTR)&HeaderStart;
  SeamldrCom64Data.PseamldrOffset = (UINT64)(UINTPTR)&PSeamldrAsm;
  SeamldrCom64Data.PseamldrSize = PSeamldrSizeAsm;
  SeamldrCom64Data.PseamldrConstsOffset = (UINT64)(UINTPTR)&PSeamldrConstAsm;
  SeamldrCom64Data.OriginalES = OriginalES & 0x0FF8;
  SeamldrCom64Data.OriginalFS = OriginalFS & 0x0FF8;
  SeamldrCom64Data.OriginalGS = OriginalGS & 0x0FF8;
  SeamldrCom64Data.OriginalSS = OriginalSS & 0x0FF8;
  SeamldrCom64Data.OriginalECX = OriginalECX & 0x0FF8;
  SeamldrCom64Data.OriginalIDTRLimit = (OriginalIDTR & MAX_WORD);
  TRACE("OriginalIDTR Limit: 0x%x\n", SeamldrCom64Data.OriginalIDTRLimit);
}
