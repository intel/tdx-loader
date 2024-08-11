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

#ifndef COMMON64_H
#define COMMON64_H
#pragma pack (1)
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//                          USAGE REQUIREMENTS
// Only general-purpose definitions can be placed in this file,
// free from chipset etc. dependencies.
//
// All definitions must be self-contained, not dependant on information from
// other include files.
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#ifndef _SEAMLDR_VALIDATION_

#pragma data_seg("EDATA32")
#pragma bss_seg("EDATA32")
#pragma const_seg("EDATA32")

#define UINT8  unsigned __int8          // char
#define UINT16 unsigned __int16         // short int
#define UINT32 unsigned __int32         // long
#define UINT64 unsigned __int64         // long long

#endif //_SEAMLDR_VALIDATION_

#include "SeamldrCom64Data.h"

//-----------------------------------------------------------------------------
// Leaf value (in eax) calling GETSEC
//-----------------------------------------------------------------------------
#define CAPABILITIES		0
#define ENTERACCS				2
#define EXITAC				  3
#define SENTER				  4
#define SEXIT				    5
#define PARAMETERS			6
#define SMCTRL					7
#define WAKEUP					8



#define ZMM_REG_QWORDS 8
#define YMM_REG_QWORDS 4

#define LT_SINIT_BASE 0xFED20270
#define LT_SINIT_SIZE 0xFED20278

#define REQ_CSE_WAKE  1

// Return status
#define CSE_ACTIVE    0
#define REQ_SUCCESS   1



#define LT_SINIT_BASE 0xFED20270
#define LT_SINIT_SIZE 0xFED20278


extern  SEAMLDR_COM64_DATA SeamldrCom64Data;

void  Entry64 ();  
void  SeamldrCom64(SEAMLDR_COM64_DATA *);
void Init64bitComArea();

#define TXT_SHUTDOWN()             __ud2()
void PauseCpu(void);


#pragma pack ()
#endif


