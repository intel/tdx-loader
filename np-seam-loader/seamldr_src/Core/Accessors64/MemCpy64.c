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
#include <Header.h>
#include <NpSeamldrApi.h>

/*
 * Micrsoft compiler can replacement code sections with internal memcpy so
 * we must provide a replacement. Just call copyData, but return copyto address
 * per api
 */
void *memcpy(void *to, const void *from, UINT32 len)
{
  UINT8 *d = (UINT8 *)to;
  UINT8 *s = (UINT8 *)from;

  #if 1
  while (len / 8) {
    *(UINT64 *) d = * (UINT64 *) s;
    d += 8;
    s += 8;
    len -= 8;
  };
#else
  __movsq(to, from, len / 8);
  len %= 8;
#endif
  while (len--)
    *d++ = *s++;
  return to;
}


/*
 * Implement MSVC memcpy_s interface 
 */
UINT64 memcpy_s(
    void* dest,
    UINTN destSize,
    const void* src,
    UINTN count
) {
  UINT64 Status = NP_SEAMLDR_PARAMS_STATUS_SUCCESS;
  UINT8 *d = (UINT8 *)dest;
  UINT8 *s = (UINT8 *)src;

  UINT64 dst_addr = (UINT64)d;
  UINT64 src_addr = (UINT64)s;

  const UINT64 dst_first_address = dst_addr;
  const UINT64 dst_last_address = dst_addr + count - 1;
  const UINT64 src_first_address = src_addr;
  const UINT64 src_last_address = src_addr + count - 1;

  if ((destSize < count) ||
      (dst_addr > MAX_QWORD - count - 1) ||      
      (src_addr > MAX_QWORD - count - 1))      
  {
      Status = NP_SEAMLDR_PARAMS_STATUS_EBADPARAM;
      goto EXIT;
  }

  // check if we have an overlap between source and destination
  if (((dst_first_address > src_last_address) || (dst_last_address < src_first_address)) == FALSE)
  {
      Status = NP_SEAMLDR_PARAMS_STATUS_EBADPARAM;
      goto EXIT;
  }
  
#if 1
  while (count / 8) {
    *(UINT64 *) d = * (UINT64 *) s;
    d += 8;
    s += 8;
    count -= 8;
  };
#else
  __movsq(to, from, len / 8);
  len %= 8;
#endif
  while (count--)
    *d++ = *s++;
  
  EXIT:
  return Status;
}


