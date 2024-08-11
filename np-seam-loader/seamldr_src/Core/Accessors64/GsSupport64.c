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

#include <GsSupport64.h>
#include <common.h>
#include <Accessors.h>

// Init cookies with some default values, in case there is an overflow before 
// it is initialized
UINTN __security_cookie = DEFAULT_SECURITY_COOKIE;

__declspec(noreturn)
void
__security_deadloop(void)
{
DeadLoop:
  _ud2();
  goto  DeadLoop;
}

UINTN
__security_cookie_rdrand(void)
{
    UINT8 num_retries = 10; // number of max retries
    UINT32 status = 0;
	UINT64 value = 0;
    while(num_retries != 0){
        if (RdSeed64(&value)){
            status = 1;
            break;
        }
        num_retries--;
        _mm_pause();
    }
    if (status == 0) {
        __security_deadloop();
    }
    return value;
}

void 
__security_init_cookie(void)
{
    UINTN Cookie;
    Cookie = __security_cookie_rdrand();
    if (Cookie == 0){       
      __security_deadloop();
    }
  __security_cookie = Cookie;
}

__declspec(noreturn) void __report_gsfailure(UINTN _StackCookie)
{
  (void) _StackCookie;
  __security_deadloop();
}

void __cdecl __security_check_cookie(UINTN _StackCookie)
{
  if (_StackCookie == __security_cookie) {
    return;
  }
  
  __report_gsfailure(_StackCookie);    
}

#if (MKF_ENGINEERING==1) &&(MKF_TRACE==1)
__declspec(noreturn)
void
__cdecl __report_rangecheckfailure(void)
{
  __report_gsfailure(0);
}
#endif

__declspec(noreturn)
void 
__GSHandlerCheck(void)
{
  __security_deadloop();  
}
