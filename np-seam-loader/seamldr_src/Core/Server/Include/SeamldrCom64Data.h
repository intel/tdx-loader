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

#ifndef SEAMLDR_COM_64_DATA_H
#define SEAMLDR_COM_64_DATA_H
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

typedef struct {
    UINT16  Limit;
    UINT64  Base;
} IDTR;

typedef struct {
    UINT64 OriginalR8;
    UINT64 OriginalR9;
    UINT64 OriginalR10;
    UINT64 OriginalR11;
    UINT64 OriginalR12;
    UINT64 OriginalCR3;
    UINT32 OriginalCR4;
    UINT16 OriginalES;
    UINT16 OriginalFS;
    UINT16 OriginalGS;
    UINT16 OriginalSS;
    UINT32 OriginalECX;
    UINT16 OriginalIDTRLimit;
    IDTR   NewIDTR;
    UINT8  OriginalGdtr[10];
    UINT64 ResumeRip;
    UINT64 PtCtxPtr;
    UINT64 RetVal;
    UINT64 HeaderStart;
    UINT32 PseamldrSize;
    UINT64 PseamldrOffset;
    UINT64 PseamldrConstsOffset;
    UINT8  NewGdtr[10];
} SEAMLDR_COM64_DATA;

// whenever the structure changes, don't forget to update the ASM!
C_ASSERT(sizeof(SEAMLDR_COM64_DATA) == 0x94);




#pragma pack ()
#endif // SEAMLDR_COM_64_DATA_H


