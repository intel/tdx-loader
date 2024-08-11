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

#ifndef __PCI_H__
#define __PCI_H__
#pragma pack (push, 1)

#include <common.h>
#include <trace.h>

//-----------------------------------------------------------------------------
// PCI(E) address forming macros.
//-----------------------------------------------------------------------------

#define PCI_ADDR(bus, dev, func, reg) \
  ((((UINT32) bus) << 16) + (((UINT32) dev) << 11) + (((UINT32) func) << 8) + ((UINT32) reg))

#define PCIEX_ADDR(bus, dev, func, reg) \
  ((((UINT32) bus) << 20) + (((UINT32) dev) << 15) + (((UINT32) func) << 12) + ((UINT32) reg))

extern UINT32 __ReadPCIDword(UINT32 addr);
extern void __WritePCIDword(UINT32 addr, UINT32);
extern UINT32 __ReadPCIEDword(UINT8 busNum, UINT32 addr);
extern void __WritePCIEDword(UINT8 busNum, UINT32 addr, UINT32 data);

extern UINT64 __ReadPCIQword(UINT32 addr);
extern void __WritePCIQword(UINT32 addr, UINT64);
extern UINT64 __ReadPCIEQword(UINT8 busNum, UINT32 addr);
extern void __WritePCIEQword(UINT8 busNum, UINT32 addr, UINT64 data);

extern UINT16 __ReadPCIWord(UINT32 addr);
extern void __WritePCIWord(UINT32 addr, UINT16);
extern UINT16 __ReadPCIEWord(UINT8 busNum, UINT32 addr);
extern void __WritePCIEWord(UINT8 busNum, UINT32 addr, UINT16 data);

extern UINT8 __ReadPCIByte(UINT32 addr);
extern void __WritePCIByte(UINT32 addr, UINT8);
extern UINT8 __ReadPCIEByte(UINT8 busNum, UINT32 addr);
extern void __WritePCIEByte(UINT8 busNum, UINT32 addr, UINT8 data);

extern UINT8 PcieWriteOnlyDword(UINT8 bus, UINT32 addr, UINT32 data, UINT32 mask);

#ifndef __ASM__

#if TRACE_WITH_FUNCTIONS & TRACE_PCI

extern UINT32 ReadPCIDwordTr(UINT32 addr, const char *Name, UINT32 LineNumber);
extern void WritePCIDwordTr(UINT32 addr, UINT32, const char *Name, UINT32 LineNumber);
extern UINT32 ReadPCIEDwordTr(UINT8 busNum, UINT32 addr, const char *Name, UINT32 LineNumber);
extern void WritePCIEDwordTr(UINT8 busNum, UINT32 addr, UINT32 data, const char *Name, UINT32 LineNumber);

extern UINT64 ReadPCIQwordTr(UINT32 addr, const char *Name, UINT32 LineNumber);
extern void WritePCIQwordTr(UINT32 addr, UINT64, const char *Name, UINT32 LineNumber);
extern UINT64 ReadPCIEQwordTr(UINT8 busNum, UINT32 addr, const char *Name, UINT32 LineNumber);
extern void WritePCIEQwordTr(UINT8 busNum, UINT32 addr, UINT64 data, const char *Name, UINT32 LineNumber);

extern UINT16 ReadPCIWordTr(UINT32 addr, const char *Name, UINT32 LineNumber);
extern void WritePCIWordTr(UINT32 addr, UINT16, const char *Name, UINT32 LineNumber);
extern UINT16 ReadPCIEWordTr(UINT8 busNum, UINT32 addr, const char *Name, UINT32 LineNumber);
extern void WritePCIEWordTr(UINT8 busNum, UINT32 addr, UINT16 data, const char *Name, UINT32 LineNumber);

extern UINT8 ReadPCIByteTr(UINT32 addr, const char *Name, UINT32 LineNumber);
extern void WritePCIByteTr(UINT32 addr, UINT8, const char *Name, UINT32 LineNumber);
extern UINT8 ReadPCIEByteTr(UINT8 busNum, UINT32 addr, const char *Name, UINT32 LineNumber);
extern void WritePCIEByteTr(UINT8 busNum, UINT32 addr, UINT8 data, const char *Name, UINT32 LineNumber);

#define ReadPCIQword(A)         ReadPCIQwordTr((A), __FUNCTION__, __LINE__)
#define ReadPCIDword(A)         ReadPCIDwordTr((A), __FUNCTION__, __LINE__)
#define ReadPCIWord(A)          ReadPCIWordTr((A), __FUNCTION__, __LINE__)
#define ReadPCIByte(A)          ReadPCIByteTr((A), __FUNCTION__, __LINE__)

#define WritePCIQword(A, D)     WritePCIQwordTr((A), (D), __FUNCTION__, __LINE__)
#define WritePCIDword(A, D)     WritePCIDwordTr((A), (D), __FUNCTION__, __LINE__)
#define WritePCIWord(A, D)      WritePCIWordTr((A), (D), __FUNCTION__, __LINE__)
#define WritePCIByte(A, D)      WritePCIByteTr((A), (D), __FUNCTION__, __LINE__)

#define ReadPCIEQword(B, A)     ReadPCIEQwordTr((B), (A), __FUNCTION__, __LINE__)
#define ReadPCIEDword(B, A)     ReadPCIEDwordTr((B), (A), __FUNCTION__, __LINE__)
#define ReadPCIEWord(B, A)      ReadPCIEWordTr((B), (A), __FUNCTION__, __LINE__)
#define ReadPCIEByte(B, A)      ReadPCIEByteTr((B), (A), __FUNCTION__, __LINE__)

#define WritePCIEQword(B, A, D) WritePCIEQwordTr((A), (D), __FUNCTION__, __LINE__)
#define WritePCIEDword(B, A, D) WritePCIEDwordTr((B), (A), (D), __FUNCTION__, __LINE__)
#define WritePCIEWord(B, A, D)  WritePCIEWordTr((B), (A), (D), __FUNCTION__, __LINE__)
#define WritePCIEByte(B, A, D)  WritePCIEByteTr((B), (A), (D), __FUNCTION__, __LINE__)

#else

#define ReadPCIQword(A)         __ReadPCIQword((A))
#define ReadPCIDword(A)         __ReadPCIDword((A))
#define ReadPCIWord(A)          __ReadPCIWord((A))
#define ReadPCIByte(A)          __ReadPCIByte((A))

#define WritePCIQword(A, D)     __WritePCIQword((A), (D))
#define WritePCIDword(A, D)     __WritePCIDword((A), (D))
#define WritePCIWord(A, D)      __WritePCIWord((A), (D))
#define WritePCIByte(A, D)      __WritePCIByte((A), (D))

#define ReadPCIEQword(B, A)     __ReadPCIEQword((B), (A))
#define ReadPCIEDword(B, A)     __ReadPCIEDword((B), (A))
#define ReadPCIEWord(B, A)      __ReadPCIEWord((B), (A))
#define ReadPCIEByte(B, A)      __ReadPCIEByte((B), (A))

#define WritePCIEQword(B, A, D) __WritePCIEQword((B), (A), (D))
#define WritePCIEDword(B, A, D) __WritePCIEDword((B), (A), (D))
#define WritePCIEWord(B, A, D)  __WritePCIEWord((B), (A), (D))
#define WritePCIEByte(B, A, D)  __WritePCIEByte((B), (A), (D))

#endif
#endif

#ifndef __ASM__

typedef union {
  struct {
    UINT32 reg  : 8;
    UINT32 func : 3;
    UINT32 dev  : 5;
    UINT32 bus  : 8;
    UINT32 res  : 8;
  } bits;
  UINT32 addr;
} PciAddr;

typedef union {
  struct {
    UINT32 reg  : 12;
    UINT32 func : 3;
    UINT32 dev  : 5;
    UINT32 bus  : 8;
    UINT32 res  : 4;
  } bits;
  UINT32 addr;
} PcieAddr;

#endif

#pragma pack (pop)
#endif
