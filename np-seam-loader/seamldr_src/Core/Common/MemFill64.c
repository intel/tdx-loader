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
//  Procedure:  coreFillMemory
//
//  Input:  Start - start address
//          Len - length to fill in bytes.
//          Val - pattern to store
//
//  Output:  None
//
//  Description:  Initializes "Len" bytes of memory with pattern "Val"
//                starting from "Start" address.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

static void coreFillMemory(UINT8 *start_addr, UINT32 val, UINT32 len)
{
  UINT32 i = 0;

  for (i = 0; i < len / 4; i++) {
    *((UINT32 *)start_addr) = val;
    start_addr += 4;
  }

  UINT8 *pattern = (UINT8 *)&val;

  for (i = 0; i < (len % 4); i++) {
    *(start_addr + i) = *(pattern + i);
  }
  return;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  fillMemory
//
//  Input:  Start - start address
//          Len - length to fill in bytes.
//          Val - pattern to store
//
//  Output:  None
//
//  Description:  Initializes "Len" bytes of memory with pattern "Val"
//                starting from "Start" address.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void fillMemory(UINT8 *start_addr, UINT32 val, UINT32 len)
{
  coreFillMemory(start_addr, val, len);
}