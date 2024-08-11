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

#if (MKF_ENGINEERING==1) &&(MKF_TRACE==1)
void ComSerialOut(unsigned char *str) {
    //static uint8_t initialized=0;
    unsigned short     comPort = 0x3f8;

    while (*str) {
        while (0 == (_inp(comPort + 5) & 0x20));
        if ((*str) == 0xa) {
            _outp(comPort, 0xd);
            while (0 == (_inp(comPort + 5) & 0x20));
        }
        _outp(comPort, *str++);
    }
}

const static char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9' ,'A', 'B', 'C', 'D', 'E', 'F' };

void printHex(UINT64 num)
{
    int i = 0, k = 0;
    static char buffer[17];    
    for (i = 0; i<16; i++) {
        buffer[15 - i] = hex[num & 0xF];
        num = num >> 4;
    }
    buffer[16] = 0;

    ComSerialOut(buffer);
}

#endif