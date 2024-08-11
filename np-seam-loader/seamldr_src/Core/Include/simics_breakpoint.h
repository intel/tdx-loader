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
/* This Software is part of Wind River Simics. The rights to copy, distribute,
 * modify, or otherwise make use of this Software may be licensed only
 * pursuant to the terms of an applicable license agreement.
 *
 * Copyright 2010-2019 Intel Corporation */

#ifndef SIMICS_MAGIC_INSTRUCTION_H
#define SIMICS_MAGIC_INSTRUCTION_H

#if (MKF_ENGINEERING == 1)

#define MAGIC(n) do {                                                       \
                         \
    int CpuInfo[4];    \
    int Input = (0x4711 | ((unsigned)(n) << 16));   \
    __cpuid(CpuInfo, Input);    \
} while (0)

#define SIMICS_BREAKPOINT MAGIC(0)

#else

#define SIMICS_BREAKPOINT

#endif

#define SIMICS_BREAK_TRACE(s) \
  ComSerialOut(s); \
  SIMICS_BREAKPOINT \

#endif
