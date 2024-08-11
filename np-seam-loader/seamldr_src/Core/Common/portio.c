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

#include "common.h"
#include "portio.h"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:
//
//  Input:	None
//
//  Output:	None
//
//  Description:
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT8 __InPort8(UINT16 ioAddress)
{
  UINT8 alReg;

  _asm {
    mov dx, ioAddress
    in al, dx
    mov alReg, al
  }

  return alReg;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:
//
//  Input:	None
//
//  Output:	None
//
//  Description:
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT16 __InPort16(UINT16 ioAddress)
{
  UINT16 axReg;

  _asm {
    mov dx, ioAddress
    in ax, dx
    mov axReg, ax
  }

  return axReg;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:
//
//  Input:	None
//
//  Output:	None
//
//  Description:
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 __InPort32(UINT16 ioAddress)
{
  UINT32 eaxReg;

  _asm {
    mov dx, ioAddress
    in eax, dx
    mov eaxReg, eax
  }

  return eaxReg;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:
//
//  Input:	None
//
//  Output:	None
//
//  Description:
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void __OutPort8(UINT16 ioAddress, UINT8 data)
{
  _asm {
    mov dx, ioAddress
    mov al, data
    out dx, al
  }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:
//
//  Input:	None
//
//  Output:	None
//
//  Description:
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void __OutPort16(UINT16 ioAddress, UINT16 data)
{
  _asm {
    mov dx, ioAddress
    mov ax, data
    out dx, ax
  }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:
//
//  Input:	None
//
//  Output:	None
//
//  Description:
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void __OutPort32(UINT16 ioAddress, UINT32 data)
{
  _asm {
    mov dx, ioAddress
    mov eax, data
    out dx, eax
  }
}

#if TRACE_WITH_FUNCTIONS & TRACE_IO

UINT8
InPort8Tr(UINT16 addr, const char *name, UINT32 line)
{
  UINT8 data = __InPort8(addr);

  TRACEFUNCTION(TRACE_IO, "%s#%d IO:%04x>%02x\n", name, line, addr, data);
  return data;
}

void
OutPort8Tr(UINT16 addr, UINT8 data, const char *name, UINT32 line)
{
  TRACEFUNCTION(TRACE_IO, "%s#%d IO:%04x<%02x\n", name, line, addr, data);
  __OutPort8(addr, data);
}

UINT16
InPort16Tr(UINT16 addr, const char *name, UINT32 line)
{
  UINT16 data = __InPort16(addr);

  TRACEFUNCTION(TRACE_IO, "%s#%d IO:%04x>%04x\n", name, line, addr, data);
  return data;
}

void
OutPort16Tr(UINT16 addr, UINT16 data, const char *name, UINT32 line)
{
  TRACEFUNCTION(TRACE_IO, "%s#%d IO:%04x<%04x\n", name, line, addr, data);
  __OutPort16(addr, data);
}

UINT32
InPort32Tr(UINT16 addr, const char *name, UINT32 line)
{
  UINT32 data = __InPort32(addr);

  TRACEFUNCTION(TRACE_IO, "%s#%d IO:%04x>%08x\n", name, line, addr, data);
  return data;
}

void
OutPort32Tr(UINT16 addr, UINT32 data, const char *name, UINT32 line)
{
  TRACEFUNCTION(TRACE_IO, "%s#%d IO:%04x<%08x\n", name, line, addr, data);
  __OutPort32(addr, data);
}

#endif
