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
 * Micrsoft compiler can replacement code sections with internal rotr so
 * we must provide a replacement.
 */
UINT32 _lrotr(UINT32 val, INT32 shift)
{
  UINT32 tmp = val;

  _asm {
    mov eax, tmp
    mov ecx, shift
    ror eax, cl
    mov tmp, eax
  }
  return tmp;
}

UINT32 _rotr(UINT32 val, INT32 shift)
{
  return _lrotr(val, shift);
}

__declspec(naked) void __cdecl _aullshr(void)
{
  __asm {
    cmp cl, 1Fh
    jbe L1
    mov eax, edx
    mov edx, 0
    sub ecx, 20h
    shr eax, cl
    jmp L2
L1:
    shrd eax, edx, cl
    shr edx, cl
L2:
    ret
  }
}
