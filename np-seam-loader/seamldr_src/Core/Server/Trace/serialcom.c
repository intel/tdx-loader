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
#if MKF_TRACE == 1

#include <Common.h>
#include <uart.h>
#include <PortIo.h>
#include <Tpm.h>

extern UINT32 comport;
extern UINT8 accessType;
#define SERIAL_IO 0

/*
 * Procedure: XmitReadStatus
 * Input: None
 * Output:  1 if status is met
 * Description: Check for transmit buffer empty
 */
static
_serialReadStatus()
{
  UINT8 sts;
  if (accessType == SERIAL_IO)
    sts = __InPort8(comport + LINE_STATUS);
  else
    sts = __ReadMmioByte(comport + LINE_STATUS);
  return ((sts & TRANS_HOLDING_REG_EMPTY)? 1 : 0);
}

/*
 *
 * Procedure:   XmitChar
 * Input: char to send
 * Output:  None
 * Description: Send char to UART
 */
static void
__serialWriteChar(char c)
{
  while (!_serialReadStatus()) {
    ;
  }
  if (accessType == SERIAL_IO)
    __OutPort8(comport + TRANSMIT_HOLDING, (UINT8)c);
  else
    __WriteMmioByte(comport + TRANSMIT_HOLDING, (UINT8)c);
}


static void
_serialWriteChar(char c)
{
  if ( c == CHAR_LF ) {
    // Make LF into CR LF
    __serialWriteChar(CHAR_CR);
  }
  __serialWriteChar(c);
}


static UINT8
_serialPortReady(UINT8 maxRetries)
{
	UINT16 retries = maxRetries;

	if(!IS_TRACE_ENABLED) {
		return 0;
	}
	do {
	  Wait1ms();
	  if (_serialReadStatus()) {
	    break;
	  }
	} while (--retries);

	if (!retries) {
	  SET_NO_TRACE;
	  return (0);
	}
	return 1;
}

UINT8
SerialWriteString(char *str, UINT32 len)
{
  if (!_serialPortReady(traceRoutines.maxTimeout)) {
    return -1;
  }
  if (len) {
    while (len--) {
      _serialWriteChar(*str++);
    }
    return 0;
  }
  while (*str != '\0') {
    _serialWriteChar(*str++);
  }
  return 0;
}

#endif
