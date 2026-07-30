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

#ifndef __MMIO_H__
#define __MMIO_H__

#if  TRACE_WITH_FUNCTIONS & TRACE_MMIO

extern UINT8 __ReadMmioByte(UINT32 addr);
extern void __WriteMmioByte(UINT32 addr, UINT8);
extern UINT16 __ReadMmioWord(UINT32 addr);
extern void __WriteMmioWord(UINT32 addr, UINT16);
extern UINT32 __ReadMmioDword(UINT32 addr);
extern void __WriteMmioDword(UINT32 addr, UINT32);
extern UINT64 __ReadMmioQword(UINT32 addr);
extern void __WriteMmioQword(UINT32 addr, UINT64);

extern UINT8 ReadMmioByteTr(UINT32 addr, const char *name, UINT32 line);
extern void WriteMmioByteTr(UINT32 addr, UINT8, const char *name, UINT32 line);
extern UINT16 ReadMmioWordTr(UINT32 addr, const char *name, UINT32 line);
extern void WriteMmioWordTr(UINT32 addr, UINT16, const char *name, UINT32 line);
extern UINT32 ReadMmioDwordTr(UINT32 addr, const char *name, UINT32 line);
extern void WriteMmioDwordTr(UINT32 addr, UINT32, const char *name, UINT32 line);
extern UINT64 ReadMmioQwordTr(UINT32 addr, const char *name, UINT32 line);
extern void WriteMmioQwordTr(UINT32 addr, UINT64, const char *name, UINT32 line);

#define ReadMmioByte(R)      ReadMmioByteTr(R, __FUNCTION__, __LINE__)
#define WriteMmioByte(R, D)  WriteMmioByteTr(R, D, __FUNCTION__, __LINE__)
#define ReadMmioWord(R)      ReadMmioWordTr(R, __FUNCTION__, __LINE__)
#define WriteMmioWord(R, D)  WriteMmioWordTr(R, D, __FUNCTION__, __LINE__)
#define ReadMmioDword(R)     ReadMmioDwordTr(R, __FUNCTION__, __LINE__)
#define WriteMmioDword(R, D) WriteMmioDwordTr(R, D, __FUNCTION__, __LINE__)
#define ReadMmioQword(R)     ReadMmioQwordTr(R, __FUNCTION__, __LINE__)
#define WriteMmioQword(R, D) WriteMmioQwordTr(R, D, __FUNCTION__, __LINE__)

#else

#define ReadMmioByte(R)        (*(volatile UINT8 *) (R))
#define WriteMmioByte(R, D)    (*(volatile UINT8 *) (R)) = (D)
#define ReadMmioWord(R)        (*(volatile UINT16 *) (R))
#define WriteMmioWord(R, D)    (*(volatile UINT16 *) (R)) = (D)
#define ReadMmioDword(R)       (*(volatile UINT32 *) (R))
#define WriteMmioDword(R, D)   (*(volatile UINT32 *) (R)) = (D)
#define ReadMmioQword(R)       (*(volatile UINT64 *) (R))
#define WriteMmioQword(R, D)   (*(volatile UINT64 *) (R)) = (D)

#define __ReadMmioByte(R)      ReadMmioByte(R)
#define __WriteMmioByte(R, D)  WriteMmioByte(R, D)
#define __ReadMmioWord(R)      ReadMmioWord(R)
#define __WriteMmioWord(R, D)  WriteMmioWord(R, D)
#define __ReadMmioDword(R)     ReadMmioDword(R)
#define __WriteMmioDword(R, D) WriteMmioDword(R, D)
#define __ReadMmioQword(R)     ReadMmioQword(R)
#define __WriteMmioQword(R, D) WriteMmioQword(R, D)

#endif

#define WritePrivateDword(R, D) WriteMmioDword(LT_PRV_BASE + offsetof(TXT, R), D)

#endif
