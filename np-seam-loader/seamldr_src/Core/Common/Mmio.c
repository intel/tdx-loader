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

#include <common.h>
#include <trace.h>
#include <mmio.h>

#if TRACE_WITH_FUNCTIONS & TRACE_MMIO

UINT8
__ReadMmioByte(UINT32 addr)
{
  return *(volatile UINT8 *)(addr);
}

void
__WriteMmioByte(UINT32 addr, UINT8 data)
{
  (*(volatile UINT8 *)(addr)) = data;
}

UINT16
__ReadMmioWord(UINT32 addr)
{
  return *(volatile UINT16 *)(addr);
}

void
__WriteMmioWord(UINT32 addr, UINT16 data)
{
  (*(volatile UINT16 *)(addr)) = data;
}

UINT32
__ReadMmioDword(UINT32 addr)
{
  return *(volatile UINT32 *)(addr);
}

void
__WriteMmioDword(UINT32 addr, UINT32 data)
{
  (*(volatile UINT32 *)(addr)) = data;
}

UINT64
__ReadMmioQword(UINT32 addr)
{
  return *(volatile UINT64 *)(addr);
}

void
__WriteMmioQword(UINT32 addr, UINT64 data)
{
  (*(volatile UINT64 *)(addr)) = data;
}

UINT8
ReadMmioByteTr(UINT32 addr, const char *name, UINT32 line)
{
  UINT8 data = __ReadMmioByte(addr);

  TRACEFUNCTION(TRACE_MMIO, "%s#%d MEM:%08x>%02x\n", name, line, addr, data);
  return data;
}

void
WriteMmioByteTr(UINT32 addr, UINT8 data, const char *name, UINT32 line)
{
  TRACEFUNCTION(TRACE_MMIO, "%s#%d MEM:%08x<%02x\n", name, line, addr, data);
  __WriteMmioByte(addr, data);
}

UINT16
ReadMmioWordTr(UINT32 addr, const char *name, UINT32 line)
{
  UINT16 data = __ReadMmioWord(addr);

  TRACEFUNCTION(TRACE_MMIO, "%s#%d MEM:%08x>%04x\n", name, line, addr, data);
  return data;
}

void
WriteMmioWordTr(UINT32 addr, UINT16 data, const char *name, UINT32 line)
{
  TRACEFUNCTION(TRACE_MMIO, "%s#%d MEM:%08x<%04x\n", name, line, addr, data);
  __WriteMmioWord(addr, data);
}

UINT32
ReadMmioDwordTr(UINT32 addr, const char *name, UINT32 line)
{
  UINT32 data = __ReadMmioDword(addr);

  TRACEFUNCTION(TRACE_MMIO, "%s#%d MEM:%08x>%08x\n", name, line, addr, data);
  return data;
}

void
WriteMmioDwordTr(UINT32 addr, UINT32 data, const char *name, UINT32 line)
{
  TRACEFUNCTION(TRACE_MMIO, "%s#%d MEM:%08x<%08x\n", name, line, addr, data);
  __WriteMmioDword(addr, data);
}

UINT64
ReadMmioQwordTr(UINT32 addr, const char *name, UINT32 line)
{
  UINT64 data = __ReadMmioQword(addr);

  TRACEFUNCTION(TRACE_MMIO, "%s#%d MEM:%08x>%016L\n", name, line, addr, data);
  return data;
}

void
WriteMmioQwordTr(UINT32 addr, UINT64 data, const char *name, UINT32 line)
{
  TRACEFUNCTION(TRACE_MMIO, "%s#%d MEM:%08x<%016L\n", name, line, addr, data);
  __WriteMmioQword(addr, data);
}

#endif
