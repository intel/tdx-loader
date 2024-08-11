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

#ifndef __acm_resource__
#define __acm_resource__

#include "AcmLock.h"
#include "Spad.h"

extern volatile UINT32 FairnessCount;

typedef enum  {
	RESOURCE_BUSY = 0,
	RESOURCE_FREE,
} AcmResourceStatus;

/*
 * Checks to see if resource is free
 */
extern AcmResourceStatus IsResourceAvailable(UINT8 resource);


/*
 * lock a resources that has already been determined to be free
 * Inputs:
 *       Resource is a bit indicating which resource is being queried
 */
extern void __AcquireResource(UINT8 resource);

extern AcmResourceStatus GetResourceStatus(UINT8 resource);

extern AcmResourceStatus AcquireResource(UINT8 resource, UINT8 retry);
extern void __ReleaseResource(UINT8 resource, UINT8 force);
#define ReleaseResource(RES)  __ReleaseResource((RES), 0)

#if MKF_TRACE == 1
extern void TraceLock();
extern void TraceUnLock();
#endif

#endif
