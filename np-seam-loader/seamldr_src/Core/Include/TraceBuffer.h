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

#ifndef TRACEBUFFER_H_
#define TRACEBUFFER_H_

#if MKF_TRACE == 1
#include <Common.h>
#include <Trace.h>

typedef struct _traceBuffer {
  UINT8 *buffer;
  UINT32 len;
  UINT32 bufferCount;
  UINT32 maxCount; // Might be useful to see how full we ever get
  UINT32 writeString;
  UINT32 writeChar;
} TRACEBUFFER;

extern TRACEBUFFER traceBuffer;

static UINT32 BufferChar(char c);
extern UINT8 BufferWriteString(unsigned char *str, UINT32 len);
extern void InitializeTraceBuffer(UINT8 *buffer, UINT32 size);
extern void FlushTraceBuffer();
#endif

#endif /* TRACEBUFFER_H_ */
