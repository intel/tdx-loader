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

#ifndef ICH_H
#define ICH_H

#define  ICH_BUS             0

#define  ICH_DEV_31          31
#define  ICH_FUNC_0          0

#define  ICH_PMBASE_OFFSET   0x040 // R40h
#define  ICH_PMEN_OFFSET     0x044 // R44h

#define  ICH_TCOBASE_OFFSET  0x60

#define  ICH_TCO_RLD_OFFSET  (0)
#define  ICH_TCO1_STS_OFFSET (0x4)
#define  ICH_TCO2_STS_OFFSET (0x6)
#define  ICH_TCO1_CNT_OFFSET (0x8)

#endif
