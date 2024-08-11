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

/*
 * Micrsoft compiler can replacement code sections with internal memset so
 * we must provide a replacement. Just call MemFill, but return copyto address
 * per api
 *
 * Wel, we can't directly call MemFill, which is treating Val as a dword value
 * instead of a byte. So before calling, initialize a dword's bytes with lsb of
 * value passed to us.
 */
void * memset(void *Start, UINT32 Val, UINT32 Len)
{
  union {
    UINT8 bytes[4];
    UINT32 val;
  } tmp;
  
  UINT8 byte = (UINT8)(Val & 0xFF);
  
  tmp.bytes[0] = byte;
  tmp.bytes[1] = byte;
  tmp.bytes[2] = byte;
  tmp.bytes[3] = byte;

  fillMemory((UINT8 *)Start, tmp.val, Len);  
  return(Start);
}
