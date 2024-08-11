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

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  coreFillMemory
//
//  Input:  Start - start address
//          Len - length to fill in bytes.
//          Val - pattern to store
//
//  Output:  None
//
//  Description:  Initializes "Len" bytes of memory with pattern "Val"
//                starting from "Start" address.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

static void coreFillMemory(UINT8 *start_addr, UINT32 val, UINT32 len)
{
  UINT32 i = 0;

  for (i = 0; i < len / 4; i++) {
    *((UINT32 *)start_addr) = val;
    start_addr += 4;
  }

  UINT8 *pattern = (UINT8 *)&val;

  for (i = 0; i < (len % 4); i++) {
    *(start_addr + i) = *(pattern + i);
  }
  return;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  fillMemory
//
//  Input:  Start - start address
//          Len - length to fill in bytes.
//          Val - pattern to store
//
//  Output:  None
//
//  Description:  Initializes "Len" bytes of memory with pattern "Val"
//                starting from "Start" address.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void fillMemory(UINT8 *start_addr, UINT32 val, UINT32 len)
{
  INT32 Ret;

  Ret = HOOK(perform_ebp_checks((UINT32)start_addr, (UINT32)len));

  switch (Ret) {
  case  STACK_TARGET:
    break;
  case  NOT_STACK_TARGET:
    break;
  default:
    TRACE("Safe fill operation: Stack target, stack frame error -%c.\n", MAX_DWORD - Ret + 1);
    ERROR_HANDLER_FULL(CLASS_MISC_CONFIG, ERR_STACK_FRAME, Ret);
  }

  coreFillMemory(start_addr, val, len);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  fillMemoryChkBoundsWithFunc
//
//  Input:  to - destination.
//          val - value to fill memory with
//          len - length of memory to fill in bytes
//          maxBound - maximum length to copy or maximum address to copy untill
//          kind - kind of maxBound - max length or max address. Two values
//          are considered for kind:
//          (kind == 0) -> MAX_LEN_BOUND or (kind != 0) -> MAX_ADDR_BOUND
//
//  Output: filled length or 0 if error
//
// Description: "to" with lemngt "len" is filled wiht "val".
//              One of two bounds selectable via "kind" parameter can
//              be used: max length or max address.
//              Procedure must be used everywhere where filled memory
//              is controlled by external data.
//              Bounds are limited to 32 bits - so far there is no need to copy
//              from/to above 4GB
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

UINT32 fillMemoryChkBoundsWithFunc(void *_to,
                                   UINT32 val,
                                   UINT32 len,
                                   UINT32 maxBound,
                                   UINT32 kind,
                                   MEM_FILL_FUNC pFunc)
{
  UINT32 maxlen;
  UINT8 *to = (UINT8 *)_to;

  if (kind == MAX_ADDR_BOUND) {
    //
    // Destination must be less then bound address
    //
    if ((UINT32) to > maxBound) {
      return 0;
    }
    //
    // maximum len to copy is difference between max address and
    // destination.
    //
    maxlen = maxBound - (UINT32) to;
  } else {
    if (len > maxBound) {
      return 0;
    }
    //
    // If len is set as bound, we cannot wrap around.
    //
    maxlen = 0xFFFFFFFF - (UINT32) to;
  }

  //
  // abort if over length.
  //
  if (len > maxlen) {
    return 0;
  }

  (*pFunc)(to, val, len);
  return len;
}
