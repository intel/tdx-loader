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
#include <Tpm.h>

void __outbyte(unsigned short, unsigned char);
#pragma intrinsic(__outbyte)

static const UINT32 ComAddr = 0x3f8; // COM1=3F8h, COM2=2F8h, COM3=3E8h, COM4=2E8h
static const UINT32 LineStat = 0x3f8 + 5;
static UINT8 Once = 0;

void static InitializeComPort(void)
{
  if (InitSio()) {
    __outbyte(ComAddr + 3, 0x87); // DLAB bit
    __outbyte(ComAddr + 1, 0);    // Point to MSB of baud rate divisor
    __outbyte(ComAddr, 1);        // Point to LSB of baud rate divisor
    __outbyte(ComAddr + 3, 3);    // 8 data bits, 1 stop bit, no parity
    Wait1ms();
  }
  return;
}

void ComSerialOut(unsigned char *str)
{
    #if MCP_CHIPSET_ACM_TYPE == AC_BIOSAC
  if (Once == 0) {
    Once = 1;
    InitializeComPort();
  }
    #endif

  while (*str) {
    while (0 == (_inp(LineStat) & 0x20)) {
      ;
    }
    if ((*str) == 0xa) {
      _outp(ComAddr, 0xd);
      while (0 == (_inp(LineStat) & 0x20)) {
        ;
      }
    }
    _outp(ComAddr, *str++);
  }
}
