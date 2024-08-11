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
 * Micrsoft compiler can replacement code sections with internal allmul so
 * we must provide a replacement.
 * per api
 * Purpose:
 *        Does a unsigned long divide of the arguments.  Arguments are
 *        not changed.
 *
 * Entry:
 *        Arguments are passed on the stack:
 *                1st pushed: X (QWORD)
 *                2nd pushed: Y (QWORD)
 *
 * Exit:
 *        EDX:EAX contains the product of X * Y
 *        NOTE: this routine removes the parameters from the stack.
 *
 * Uses:
 *        ECX
 *
 * Exceptions:
 *
 *  NOTE, this must follow same usage as microsoft runtime. This routine removes arguments from stack
 *
 *
 *    XL = X[31.0] XH = X[63.32] YL = Y[31.0] YH = Y[63.0]
 *
 *    XL_YH = XL * YH
 *    XH_YL = XH * YL
 *    EAX = XL * YL
 *    EDX = ((XL * YL) >> 32) + XL_YH + XH_YL
 */

__declspec(naked) void __cdecl _allmul(void)
{
  _asm {
    push ebx
    mov ebx, [esp + 08h]; X_L
    mov eax, [esp + 10h]; Y_L
    mov edx, [esp + 0Ch]; X_H
    mov ecx, [esp + 14h]; Y_H
    imul ecx, ebx; Y_H *X_L
    imul edx, eax; X_H *Y_L
    add ecx, edx; XL_YH + XH_YL
    mul ebx; XL *YL
    add edx, ecx; ((XL * YL) >> 32) + XL_YH + XH_YL
    pop ebx
    ret     16; we have to pop arguments off stack
  }
}
