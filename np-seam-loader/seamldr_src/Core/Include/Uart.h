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

#ifndef UART_H
#define UART_H

#define COM1_BASE                  0x3f8
#define COM2_BASE                  0x2f8
#define COM3_BASE                  0x3e8
#define COM4_BASE                  0x2e8

#define MAX_SERIAL_TIMEOUT_LOOPS   2

#define COM_PORT                   COM1_BASE

#define RECEIVER_BUFFER            0x00
#define TRANSMIT_HOLDING           0x00
#define DIVISOR_LATCH_LOW          0x00 // 0/1 - 16-bit

#define DIVISOR_LATCH_HIGH         0x01
#define INTERRUPT_ENABLE           0x01
#   define DISABLE_INTERRUPTS      0x00

#define INTERRUPT_IDENTIFICATION   0x02
#define FIFO_CONTROL               0x02
#define     FIFO_DISABLE_MASK      0xfe

#define LINE_CONTROL               0x03
#   define DIVISOR_LATCH_ACCESS    0x80
#   define NO_STOP                 0x00
#   define NO_PARITY               0x00
#   define BITS8                   0x03

#define MODEM_CONTROL              0x04
#define LINE_STATUS                0x05
#   define TRANS_HOLDING_REG_EMPTY 0x20
#   define DATA_READY              0x01

#define MODEM_STATUS               0x06
#define SCRATCH                    0x07

#define CHAR_LF                    0xa
#define CHAR_CR                    0xd

extern UINT8 SerialWriteString(char *str, UINT32 len);

#endif UART_H
