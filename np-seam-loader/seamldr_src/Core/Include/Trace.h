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

#ifndef TRACE_H
#define TRACE_H

#define TRACE_ENABLED_FLG        BIT0
#define TRACE_SERIALPORT_ENABLED BIT1
#define TRACE_USBPORT_ENABLED    BIT2

#define TRACE_ERRORHANDLER       BIT0
#define TRACE_MMIO               BIT1
#define TRACE_IO                 BIT2
#define TRACE_MSR                BIT3
#define TRACE_TPM                BIT4
#define TRACE_PCI                BIT5
#define TRACE_GSTATE             BIT6

#if (MKF_ENGINEERING == 1) && (MKF_TRACE == 1)

typedef UINT8 (*TRACE_WRITE_STRING) (char *, UINT32 len);

typedef struct _traceInterface {
  UINT32 preTrace;
  UINT32 postTrace;
  UINT32 writeString;
  UINT32 flags;
  UINT32 maxTimeout;
  UINT32 offLine;
  char * func;
} TRACEINTERFACE;

extern TRACEINTERFACE traceRoutines;

#define IS_TRACE_ENABLED (traceRoutines.flags & TRACE_ENABLED_FLG)

  #define TRACE(s, ...)            Trace(s, __VA_ARGS__)
  #define PRINTF(s, ...)           Printf(s, __VA_ARGS__)
  #define TRACEIT()                Printf("%s#%d\n", __FILE__, __LINE__);
  #define TRACEFUNCTION(c, s, ...) TraceFunction(c, s, __VA_ARGS__)
  #define TRACE_RANGE(s)           TraceRange(s)
  #define TRACE_RANGE_TABLE(s, t)  TraceRangeTable(s, t)
  #define TRACE_IF(c)              if (c)
  #define TRACE_PROGRESS(c)        TraceProgress(c)
  #define SET_NO_TRACE     do { \
    (traceRoutines.flags &= ~TRACE_ENABLED_FLG); \
    traceRoutines.offLine = __LINE__; \
    traceRoutines.func = __FUNCTION__; \
} while (0)
  #define SET_TRACE        (traceRoutines.flags |= TRACE_ENABLED_FLG)
  #define IS_TRACE_ENABLED (traceRoutines.flags & TRACE_ENABLED_FLG)
  #define EXEC_NO_TRACE(c)                          do { \
    UINT8 enabled = IS_TRACE_ENABLED; \
    SET_NO_TRACE; \
    (c); \
    if (enabled) \
    SET_TRACE; \
    } while (0)
  #define TRACE_VALUE(c, w)                         TraceValue(c, w)
  #define PRINTBUFFER(CONTROL, PTR, SIZE, FMT, ...) PrintBuffer((CONTROL), (PTR), (SIZE), FMT, __VA_ARGS__)
  #define PRINTMULTIHASH(MH, FMT)                   MultiHashPrint(MH, FMT)
  #define HEXDUMP(buf, buf_size)                    HexDump(buf, buf_size)

#if  TRACE_WITH_FUNCTIONS & TRACE_TPM
  #define TPM_TRANSMIT_DEBUG(R) tpmTransmitDebug(R)
#else
  #define TPM_TRANSMIT_DEBUG(R)
#endif

#define TRACE_BENCHMARK(tn, tg, tsc) __Trace("Tsk=0x%x, Tag=0x%x, Tsc=%llx\n", tn, tg, tsc)

#else
  #define TRACE(s, ...)
  #define PRINTF(s, ...)
  #define TRACEIT()
  #define TRACEFUNCTION(c, s, ...)
  #define TRACE_RANGE(s)
  #define TRACE_RANGE_TABLE(s, t)
  #define TRACE_IF(c)
  #define TRACE_PROGRESS(c)
  #define SET_NO_TRACE
  #define SET_TRACE
  #define EXEC_NO_TRACE(c) (c)
  #define TRACE_VALUE(c, w)
  #define PRINTBUFFER(CONTROL, PTR, SIZE, FMT, ...)
  #define PRINTMULTIHASH(MH, FMT)
  #define TPM_TRANSMIT_DEBUG(R)
  #define HEXDUMP(buf, buf_size)
  #define TRACE_BENCHMARK(tn, tg, tsc)
#endif

#define PROGRESS_MARK(code) ProgressMark((UINT8) code); SAVE_BENCHMARK(code, 0x0); TRACE_PROGRESS(code)

typedef char *va_list;

#if !defined(_INTSIZE)
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#endif

#define va_start(ap, v)        (ap = (va_list) & v + _INTSIZEOF(v))
#define va_arg(ap, t)          (*(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
#define va_end(ap)             (ap = (va_list)0)

#define FN_PROGRESS_MARK(F, C) PROGRESS_MARK(((F) << 4) + C)

void TraceWriteString(char *, UINT32);

void Trace(char *, ...);
void Printf(const char *, ...);
void PrintBuffer(UINT8 control, const unsigned char *buffer, UINT32 size, const char *Format, ...);
void TraceFunction(UINT8, char *, ...);

void TraceRange(RANGE *);
void TraceRangeTable(RANGE **, UINT32);
void TraceProgress(UINT32);
void TraceValue(UINT64, UINT32);
void _Trace(char *Format, ...);
void HexDump(void *ptr, UINT32 size);

void InitSioUart();
void RestoreSioUart();
UINT32 InitSioSmsc1007();

void NumToStr(UINT8 *, UINT32, UINT64);
void TraceUnLock();

#endif
