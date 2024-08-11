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

#ifndef __IO_H__
#define __IO_H__

#include <Trace.h>

extern UINT8 __InPort8(UINT16 addr);
extern void __OutPort8(UINT16 addr, UINT8);
extern UINT16 __InPort16(UINT16 addr);
extern void __OutPort16(UINT16 addr, UINT16);
extern UINT32 __InPort32(UINT16 addr);
extern void __OutPort32(UINT16 addr, UINT32);

#if TRACE_WITH_FUNCTIONS & TRACE_IO

extern UINT8 InPort8Tr(UINT16 addr, const char *Name, UINT32 LineNumber);
extern void OutPort8Tr(UINT16 addr, UINT8, const char *Name, UINT32 LineNumber);
extern UINT16 InPort16Tr(UINT16 addr, const char *Name, UINT32 LineNumber);
extern void OutPort16Tr(UINT16 addr, UINT16, const char *Name, UINT32 LineNumber);
extern UINT32 InPort32Tr(UINT16 addr, const char *Name, UINT32 LineNumber);
extern void OutPort32Tr(UINT16 addr, UINT32, const char *Name, UINT32 LineNumber);

#define InPort8(P)      InPort8Tr(P, __FUNCTION__, __LINE__)
#define InPort16(P)     InPort16Tr(P, __FUNCTION__, __LINE__)
#define InPort32(P)     InPort32Tr(P, __FUNCTION__, __LINE__)
#define OutPort8(P, D)  OutPort8Tr(P, D, __FUNCTION__, __LINE__)
#define OutPort16(P, D) OutPort16Tr(P, D, __FUNCTION__, __LINE__)
#define OutPort32(P, D) OutPort32Tr(P, D, __FUNCTION__, __LINE__)

#else

#define InPort8(P)      __InPort8(P)
#define InPort16(P)     __InPort16(P)
#define InPort32(P)     __InPort32(P)
#define OutPort8(P, D)  __OutPort8(P, D)
#define OutPort16(P, D) __OutPort16(P, D)
#define OutPort32(P, D) __OutPort32(P, D)

#endif

#endif
