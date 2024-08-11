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
unsigned long __readcr4(void);
#pragma intrinsic(__readcr4)

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:   Update_CRx
//
//  Input:  None
//
//  Output:  None
//
//  Description:  set CR0 and CR4. This procedure destroys registers
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void Update_CRx(void)
{
  UINT32 value_eax = 0;

  //Make sure osxsave and osfxsr are set

  value_eax = __readcr4();
  value_eax = value_eax | (CR4_PAE + CR4_SMXE);

  __writecr4(value_eax);

  // SEAMLDR should follow the spec and initialize CR0 explicitly to the value 0x21 (PE + NE bit set, all others are cleared)

  value_eax = CR0_PE + CR0_NE;
  __writecr0(value_eax);

  return;
}
