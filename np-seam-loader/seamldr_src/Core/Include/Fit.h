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

#ifndef FIT_H
#define FIT_H

typedef struct _FIRMWARE_INTERFACE_TABLE_ENTRY {
  UINT64 Address;
  UINT32 Size32;
  UINT16 Version;
  UINT8  Type : 7;
  UINT8  C_V  : 1;
  UINT8  Checksum;
} FIRMWARE_INTERFACE_TABLE_ENTRY;

typedef FIRMWARE_INTERFACE_TABLE_ENTRY FitRecord;

// Following used to set debug policy.  This policy is slightly different--all bits are used
// and have a meaning.

#define FIT_TABLE_TYPE_JMP_DOLLAR 0x2f

// These appear to be fixed so change carefully

#define FEATURE_POLICY_DISABLE_SMB_WRT_CHECK BIT0
#define FEATURE_POLICY_USE_TPM2_PCREVENT     BIT1

//
// Externs
//
extern FIRMWARE_INTERFACE_TABLE_ENTRY *pStartupModuleEntry;
extern FIRMWARE_INTERFACE_TABLE_ENTRY *pManifestEntry;
extern FIRMWARE_INTERFACE_TABLE_ENTRY *pFirstBiosModuleEntry;

extern UINT32 EntryPointAddr;
extern UINT32 NemMemSize;
extern UINT32 BiosModuleEntryCount;
extern UINT32 LowestBiosModuleBase;

//
// Interface
//
void HOOK(GetFitData());
extern FitRecord *FindFitRecord(UINT8 type, UINT8 *index);

#ifdef MKF_REGRESSION
#endif

#if MKF_ENGINEERING == 1
#define FIT_JUMP_DOLLAR(X) do { \
    FitRecord *_jmpFit = NULL; \
    _jmpFit = FindFitRecord(FIT_TABLE_TYPE_JMP_DOLLAR, NULL); \
    if (_jmpFit && ServerGetFitRecordData(_jmpFit, 0, NULL)) \
    TRAPLOOP((X)); \
} while (0)
#else
#define FIT_JUMP_DOLLAR(X)
#endif

#endif
