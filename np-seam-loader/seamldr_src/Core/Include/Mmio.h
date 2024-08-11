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

#define ReadPublicDword(R)              ReadMmioDword(LT_PUB_BASE + offsetof(TXT, R))
#define WritePublicDword(R, D)          WriteMmioDword(LT_PUB_BASE + offsetof(TXT, R), D)
#define ReadPublicQword(R)              ReadMmioQword(LT_PUB_BASE + offsetof(TXT, R))
#define WritePublicQword(R, D)          WriteMmioQword(LT_PUB_BASE + offsetof(TXT, R), D)

#define ReadPrivateDword(R)             ReadMmioDword(LT_PRV_BASE + offsetof(TXT, R))
#define WritePrivateDword(R, D)         WriteMmioDword(LT_PRV_BASE + offsetof(TXT, R), D)
#define ReadPrivateQword(R)             ReadMmioQword(LT_PRV_BASE + offsetof(TXT, R))
#define WritePrivateQword(R, D)         WriteMmioQword(LT_PRV_BASE + offsetof(TXT, R), D)

#define __ReadPublicDword(R)            __ReadMmioDword(LT_PUB_BASE + offsetof(TXT, R))
#define __WritePublicDword(R, D)        __WriteMmioDword(LT_PUB_BASE + offsetof(TXT, R), D)
#define __ReadPublicQword(R)            __ReadMmioQword(LT_PUB_BASE + offsetof(TXT, R))
#define __WritePublicQword(R, D)        __WriteMmioQword(LT_PUB_BASE + offsetof(TXT, R), D)

#define __ReadPrivateDword(R)           __ReadMmioDword(LT_PRV_BASE + offsetof(TXT, R))
#define __WritePrivateDword(R, D)       __WriteMmioDword(LT_PRV_BASE + offsetof(TXT, R), D)
#define __ReadPrivateQword(R)           __ReadMmioQword(LT_PRV_BASE + offsetof(TXT, R))
#define __WritePrivateQword(R, D)       __WriteMmioQword(LT_PRV_BASE + offsetof(TXT, R), D)

#define ReadTpmQword(R)                 ReadMmioQword(TPM_ACCESS_LX + offsetof(TPM_FIFO, R))
#define WriteTpmQword(R, D)             WriteMmioQword(TPM_ACCESS_LX + offsetof(TPM_FIFO, R), D)
#define ReadTpmDword(R)                 ReadMmioDword(TPM_ACCESS_LX + offsetof(TPM_FIFO, R))
#define WriteTpmDword(R, D)             WriteMmioDword(TPM_ACCESS_LX + offsetof(TPM_FIFO, R), D)
#define ReadTpmWord(R)                  ReadMmioWord(TPM_ACCESS_LX + offsetof(TPM_FIFO, R))
#define WriteTpmWord(R, D)              WriteMmioWord(TPM_ACCESS_LX + offsetof(TPM_FIFO, R), D)
#define ReadTpmByte(R)                  ReadMmioByte(TPM_ACCESS_LX + offsetof(TPM_FIFO, R))
#define WriteTpmByte(R, D)              WriteMmioByte(TPM_ACCESS_LX + offsetof(TPM_FIFO, R), D)

#define __ReadTpmQword(R)               __ReadMmioQword(TPM_ACCESS_LX + offsetof(TPM_FIFO, R))
#define __WriteTpmQword(R, D)           __WriteMmioQword(TPM_ACCESS_LX + offsetof(TPM_FIFO, R), D)
#define __ReadTpmDword(R)               __ReadMmioDword(TPM_ACCESS_LX + offsetof(TPM_FIFO, R))
#define __WriteTpmDword(R, D)           __WriteMmioDword(TPM_ACCESS_LX + offsetof(TPM_FIFO, R), D)
#define __ReadTpmWord(R)                __ReadMmioWord(TPM_ACCESS_LX + offsetof(TPM_FIFO, R))
#define __WriteTpmWord(R, D)            __WriteMmioWord(TPM_ACCESS_LX + offsetof(TPM_FIFO, R), D)
#define __ReadTpmByte(R)                __ReadMmioByte(TPM_ACCESS_LX + offsetof(TPM_FIFO, R))
#define __WriteTpmByte(R, D)            __WriteMmioByte(TPM_ACCESS_LX + offsetof(TPM_FIFO, R), D)

#define ReadCrbQword(R)                 ReadMmioQword(TPM_ACCESS_LX + offsetof(TPM_CRB, R))
#define WriteCrbQword(R, D)             WriteMmioQword(TPM_ACCESS_LX + offsetof(TPM_CRB, R), D)
#define ReadCrbDword(R)                 ReadMmioDword(TPM_ACCESS_LX + offsetof(TPM_CRB, R))
#define WriteCrbDword(R, D)             WriteMmioDword(TPM_ACCESS_LX + offsetof(TPM_CRB, R), D)
#define ReadCrbWord(R)                  ReadMmioWord(TPM_ACCESS_LX + offsetof(TPM_CRB, R))
#define WriteCrbWord(R, D)              WriteMmioWord(TPM_ACCESS_LX + offsetof(TPM_CRB, R), D)
#define ReadCrbByte(R)                  ReadMmioByte(TPM_ACCESS_LX offsetof(TPM_CRB, R))
#define WriteCrbByte(R, D)              WriteMmioByte(TPM_ACCESS_LX + offsetof(TPM_CRB, R), D)

#define __ReadCrbQword(R)               __ReadMmioQword(TPM_ACCESS_LX + offsetof(TPM_CRB, R))
#define __WriteCrbQword(R, D)           __WriteMmioQword(TPM_ACCESS_LX + offsetof(TPM_CRB, R), D)
#define __ReadCrbDword(R)               __ReadMmioDword(TPM_ACCESS_LX + offsetof(TPM_CRB, R))
#define __WriteCrbDword(R, D)           __WriteMmioDword(TPM_ACCESS_LX + offsetof(TPM_CRB, R), D)
#define __ReadCrbWord(R)                __ReadMmioWord(TPM_ACCESS_LX + offsetof(TPM_CRB, R))
#define __WriteCrbWord(R, D)            __WriteMmioWord(TPM_ACCESS_LX + offsetof(TPM_CRB, R), D)
#define __ReadCrbByte(R)                __ReadMmioByte(TPM_ACCESS_LX + offsetof(TPM_CRB, R))
#define __WriteCrbByte(R, D)            __WriteMmioByte(TPM_ACCESS_LX + offsetof(TPM_CRB, R), D)

#define ReadTpm0Qword(R)                ReadMmioQword(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R))
#define WriteTpm0Qword(R, D)            WriteMmioQword(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R), D)
#define ReadTpm0Dword(R)                ReadMmioDword(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R))
#define WriteTpm0Dword(R, D)            WriteMmioDword(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R), D)
#define ReadTpm0Word(R)                 ReadMmioWord(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R))
#define WriteTpm0Word(R, D)             WriteMmioWord(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R), D)
#define ReadTpm0Byte(R)                 ReadMmioByte(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R))
#define WriteTpm0Byte(R, D)             WriteMmioByte(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R), D)

#define __ReadTpm0Qword(R)              __ReadMmioQword(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R))
#define __WriteTpm0Qword(R, D)          __WriteMmioQword(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R), D)
#define __ReadTpm0Dword(R)              __ReadMmioDword(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R))
#define __WriteTpm0Dword(R, D)          __WriteMmioDword(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R), D)
#define __ReadTpm0Word(R)               __ReadMmioWord(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R))
#define __WriteTpm0Word(R, D)           __WriteMmioWord(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R), D)
#define __ReadTpm0Byte(R)               __ReadMmioByte(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R))
#define __WriteTpm0Byte(R, D)           __WriteMmioByte(TPM_ACCESS_L0 + offsetof(TPM_FIFO, R), D)

#define WaitPrivateStatusBitSet(R, M)   __WaitRegisterBitSet(LT_PRV_BASE + offsetof(TXT, R), M)
#define WaitPrivateStatusBitClear(R, M) __WaitRegisterBitClear(LT_PRV_BASE + offsetof(TXT, R), M)

#endif
