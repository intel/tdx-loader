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

#ifndef MEMORY_OPS_H
#define MEMORY_OPS_H

typedef struct {
  UINT32 caller_ebp;
  UINT32 caller_eip;
  UINT8  vars[];
} STACK_METADATA;

#define IN_STACK         1
#define OUT_OF_STACK     -1

#define NOT_STACK_TARGET 0
#define STACK_TARGET     1

#define ERR(n) (-(n))

typedef void * (*COPY_DATA_FUNC)(void *, const void *, UINT32);

typedef void (*MEM_FILL_FUNC) (UINT8 *, UINT32, UINT32);

//*************** Must use methods to perform fast copy **********************************
//
// Fast copy procedure. Uses multi-byte instructions.
//
void *fastCopyData(void *to, const void *from, UINT32 length);

#define copyData(TO, FR, LEN) fastCopyData((TO), (FR), (LEN))

//*************** Must use method to perform slow copy ***********************************
//
// Slow copy procedure. Uses only DWORD and byte stransfers
//
void *copyMemory(void *to, const void *from, UINT32 length);

//*************** Must use method to perform fast copy from/to external sources **********
//
// Fast copy with bounds check
//
UINT32 copyDataChkBoundsWithFunc(void *to, const void *from, UINT32 length, UINT32, UINT32, COPY_DATA_FUNC);

#define copyDataChkBounds(TO, FROM, LEN, MAX, KIND) copyDataChkBoundsWithFunc((TO), (FROM), (LEN), (MAX), (KIND), fastCopyData)

//*************** Must use method to slow copy from/to external sources ******************
//
// Slow copy with bounds check. Note, we can't use multi-byte
// instructions to send/receive data from crb
//
#define copyMemoryChkBounds(TO, FROM, LEN, MAX, KIND) copyDataChkBoundsWithFunc((TO), (FROM), (LEN), (MAX), (KIND), copyMemory)

//*************** Must use method to fill memory with pattern ****************************
//
// Fill memroy with pattern
//
void fillMemory(UINT8 *address, UINT32 pattern, UINT32 length);

//*************** Must use method to fill memory of external sources *********************
//
// Slow memory filling with bounds check.
//
UINT32 fillMemoryChkBoundsWithFunc(void *, UINT32, UINT32, UINT32, UINT32, MEM_FILL_FUNC);

#define fillMemoryChkBounds(TO, VAL, LEN, MAX, KIND) fillMemoryChkBoundsWithFunc((TO), (VAL), (LEN), (MAX), (KIND), fillMemory)

#endif
