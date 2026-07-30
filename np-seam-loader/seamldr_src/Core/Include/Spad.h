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

#ifndef __SPAD_H__
#define __SPAD_H__

#define SPAD_STATE(X) LT_SPAD_ ## X

extern UINT8 __IsAcmGlobalStateSet(UINT64 sts);
extern void __AcmGlobalStateClear(UINT64 sts);
extern void __AcmGlobalStateSet(UINT64 sts);

#if TRACE_WITH_FUNCTIONS & TRACE_GSTATE

extern UINT8 _IsAcmGlobalStateSet(UINT64 sts, const char *, char *, UINT32);
#define IsAcmGlobalStateSet(X) _IsAcmGlobalStateSet(SPAD_STATE(X), STRINGIFY(X), __FUNCTION__, __LINE__)

extern void _AcmGlobalStateClear(UINT64 sts, const char *, char *, UINT32);
#define AcmGlobalStateClear(X) _AcmGlobalStateClear(SPAD_STATE(X), STRINGIFY(X), __FUNCTION__, __LINE__)

extern void _AcmGlobalStateSet(UINT64 sts, const char *, char *, UINT32);
#define AcmGlobalStateSet(X)   _AcmGlobalStateSet(SPAD_STATE(X), STRINGIFY(X), __FUNCTION__, __LINE__)
#else
#define IsAcmGlobalStateSet(X) __IsAcmGlobalStateSet(SPAD_STATE(X))
#define AcmGlobalStateClear(X) __AcmGlobalStateClear(SPAD_STATE(X))
#define AcmGlobalStateSet(X)   __AcmGlobalStateSet(SPAD_STATE(X))
#endif

#endif
