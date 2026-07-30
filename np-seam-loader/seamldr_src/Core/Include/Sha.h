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

#ifndef __SHA_H__
#define __SHA_H__

#include "Common.h"

typedef void (*shaupdate)(void);
typedef void (*shafinal)(void *, void *);

struct internal_sha_ctx {
  UINT32    accumulated_len;
  UINT32    block_size;
  shaupdate doupdate;
  UINT32    tail_len;
  UINT8 *   tail_msg;
};

struct sha1_ctx {
  struct internal_sha_ctx common_ctx;
  UINT32                  vars1[10];
  UINT32                  w1[80];
};

struct sha2_ctx {
  struct internal_sha_ctx common_ctx;
  UINT32                  vars2[16];
  UINT32                  w2[80];
  UINT32                  temps2[2];
};

struct sha3_ctx {
  struct internal_sha_ctx common_ctx;
  union {
    struct {
      UINT64 varh0;
      UINT64 varh1;
      UINT64 varh2;
      UINT64 varh3;
      UINT64 varh4;
      UINT64 varh5;
      UINT64 varh6;
      UINT64 varh7;
    } _hvars;
    UINT64 hvars[8];
  } h_u;
  UINT64 vara;
  UINT64 varb;
  UINT64 varc;
  UINT64 vard;
  UINT64 vare;
  UINT64 varf;
  UINT64 varg;
  UINT64 varh;
  UINT64 temp1;
  UINT64 temp2;
  UINT64 var1;
  UINT64 var2;
  UINT64 var3;
  UINT64 vart0;
  UINT64 vart1;
  UINT64 vart2;
  UINT32 w[160];
};

/*
 *  Input:  Memory operands
 *
 *  Output: Accumulator edx:eax contains computed function value or memory operand
 *               is updated per operation.
 *
 *  Registers:  eax, edx are modified
 *
 *  Description:  Implements functions per IETF RFC6234
 *               edx:eax pair plays the role of accumulator for all operations.
 */

// Var value is added to edx:eax.
// On exit edx:eax contain sum value.
#define ADD64(Var) __asm \
  { \
    __asm add eax, DWORD PTR Var \
    __asm adc edx, DWORD PTR Var + 4 \
  }

// edx:eax is 8 bytes swapped.
#define BSWAP64 __asm \
  { \
    __asm xchg eax, edx \
    __asm bswap eax \
    __asm bswap edx \
  }

// Var is loaded into edx:eax
#define LOAD64(Var) __asm \
  { \
    __asm mov eax, int ptr Var \
    __asm mov edx, int ptr Var + 4 \
  }

// edx:eax is stored into Var.
// On exit edx:eax contain initial value.
#define STORE64(Var) __asm \
  { \
    __asm mov     int ptr Var, eax \
    __asm mov     int ptr Var + 4, edx \
  }

// Performs AND edx:eax, Var.
// On exit result is in edx:eax
#define AND64(Var) __asm \
  { \
    __asm and     eax, DWORD PTR Var \
    __asm and     edx, DWORD PTR Var + 4 \
  }

// Performs XOR edx:eax, Var.
// On exit result is in edx:eax
#define XOR64(Var) __asm \
  { \
    __asm xor     eax, DWORD PTR Var \
    __asm xor     edx, DWORD PTR Var + 4 \
  }

/*
 * Performs XOR Var, edx:eax. Result is stored in Var
 * On exit edx:eax contain initial value.
 *
 * VAR_XOR64   MACRO Var
 *        xor     DWORD PTR Var, eax
 *        xor     DWORD PTR Var + 4, edx
 * ENDM
 *
 * Performs NOT edx:eax
 * On exit result is in edx:eax
 */
#define NOT64 __asm \
  { \
    __asm not     eax \
    __asm not     edx \
  }

//
// Cnt == 0 : 63
//
// Performs SHR Var, Cnt. Result is stored in Var
// On exit edx:eax contain shifted Var value.
//
#define SHR64(Var, Cnt) __asm \
  { \
    __asm push ecx \
    LOAD64(Var) \
    __asm mov ecx, Cnt \
    __asm cmp ecx, 32 \
    __asm jb shr64_1_ ## Var_ ## Cnt \
    __asm mov eax, edx \
    __asm mov edx, 0 \
    __asm sub ecx, 32 \
    __asm shr64_1_ ## Var_ ## Cnt:         \
    __asm shrd eax, edx, cl \
    __asm mov DWORD PTR Var, eax \
    __asm shr edx, cl \
    __asm mov DWORD PTR Var + 4, edx \
    __asm pop ecx \
  }

//
// Cnt == 0 : 63
//
// Performs ROTR Var, Cnt. Result is stored in Var
// On exit edx:eax contain rotated Var value.
//
#define ROTR64(Var, Cnt) __asm \
  { \
    __asm push ecx \
       \
    LOAD64(Var) \
       \
    __asm mov ecx, Cnt \
    __asm cmp ecx, 32 \
    __asm jb L_ ## Var_ ## Cnt \
    __asm xchg eax, edx \
    __asm sub ecx, 32 \
    __asm L_ ## Var_ ## Cnt:                       \
    /* VarT0 is temporary var for level 0 operations */ \
    __asm mov DWORD PTR VarT0, eax \
    __asm shrd eax, edx, Cnt \
    __asm mov DWORD PTR Var, eax \
    __asm mov eax, DWORD PTR VarT0 \
    __asm shrd edx, eax, Cnt \
    __asm mov DWORD PTR Var + 4, edx \
       \
    __asm pop ecx \
  }

//
// Cnt == 0 : 63
//
// Performs ROTL Var, Cnt. Result is stored in Var
// On exit edx:eax contain rotated Var value.
#define ROTL64(Var, Cnt) __asm \
  { \
    __asm push ecx \
    LOAD64(Var) \
    __asm mov ecx, Cnt \
    __asm cmp ecx, 32 \
    __asm jb rotl64_1 \
    __asm xchg eax, edx \
    __asm sub ecx, 32 \
    __asm rotl64_1: \
    /* VarT0 is temporary var for level 0 operations */ \
    __asm mov DWORD PTR VarT0, edx \
    __asm shld edx, eax, Cnt \
    __asm mov DWORD PTR Var + 4, edx \
    __asm mov edx, DWORD PTR VarT0 \
    __asm shld eax, edx, Cnt \
    __asm mov DWORD PTR Var, eax \
        \
    __asm pop ecx \
  }

//
// Implements CH( x, y, z) = (x AND y) XOR ( (NOT x) AND z)
// On exit result is in edx:eax
#define F_CH64 __asm \
  { \
    LOAD64(VarE) \
    AND64(VarF) \
    /* VarT1 is temporary var for level 1 operations */ \
    STORE64(VarT1) \
    LOAD64(VarE) \
    NOT64 \
    AND64(VarG) \
    XOR64(VarT1) \
  }

// Implements MAJ( x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z)
// On exit result is in edx:eax
#define F_MAJ64 __asm \
  { \
    LOAD64(VarA) \
    AND64(VarB) \
    /* VarT1 is temporary var for level 1 operations */ \
    /* VarT1 = (VarA AND VarB) */ \
    STORE64(VarT1) \
    LOAD64(VarA) \
    /* Acc = VarA AND VarC */ \
    AND64(VarC) \
    /* Acc = (VarA AND VarC) XOR (VarA AND VarB) */ \
    XOR64(VarT1) \
    /* Temp1 = (VarA AND VarC) XOR (VarA AND VarB) */ \
    STORE64(VarT1) \
    LOAD64(VarB) \
    /* Acc = VarB XOR VarC */ \
    AND64(VarC) \
    /* Acc = (VarB XOR VarC) XOR (VarA AND VarC) XOR (VarA AND VarB) */ \
    XOR64(VarT1) \
  }

//
// Implements BSIG0(x) = ROTR^28(x) XOR ROTR^34(x) XOR ROTR^39(x)
// On exit result is in edx:eax
//
#define F_BSIG0_64 __asm \
  { \
    LOAD64(VarA) \
    /* Var1, Var2, Var3 are temporary vars for level 1 operations */ \
    STORE64(Var1) \
    STORE64(Var2) \
    STORE64(Var3) \
    /* Var1 = ROTR(VarA, 28) */ \
    ROTR64(Var1, 28) \
    /* Var2 = ROTR(VarA, 34) */ \
    ROTR64(Var2, 34) \
    /* Var3 = ROTR(VarA, 39) */ \
    ROTR64(Var3, 39) \
    /* Acc = ROTR(VarA, 28) */ \
    LOAD64(Var1) \
    /* Acc = ROTR(VarA, 28) XOR ROTR(VarA, 34) */ \
    XOR64(Var2) \
    /* Acc = ROTR(VarA, 28) XOR ROTR(VarA, 34) XOR ROTR(VarA, 39) */ \
    XOR64(Var3) \
  }

// Implements BSIG1(x) = ROTR^14(x) XOR ROTR^18(x) XOR ROTR^41(x)
// On exit result is in edx:eax
#define F_BSIG1_64 __asm \
  { \
    LOAD64(VarE) \
    /* Var1, Var2, Var3 are temporary vars for level 1 operations */ \
    STORE64(Var1) \
    STORE64(Var2) \
    STORE64(Var3) \
    /* Var1 = ROTR(VarE, 14) */ \
    ROTR64(Var1, 14) \
    /* Var2 = ROTR(VarE, 18) */ \
    ROTR64(Var2, 18) \
    /* Var3 = ROTR(VarE, 41) */ \
    ROTR64(Var3, 41) \
    /* Acc = ROTR(VarE, 14) */ \
    LOAD64(Var1) \
    /* Acc = ROTR(VarE, 14) XOR ROTR(VarE, 18) */ \
    XOR64(Var2) \
    /* Acc = ROTR(VarE, 14) XOR ROTR(VarE, 18) XOR ROTR(VarE, 41) */ \
    XOR64(Var3) \
  }

// Implements SSIG0(x) = ROTR^1(x) XOR ROTR^8(x) XOR SHR^7(x)
// On exit result is in edx:eax
#define F_SSIG0_64(Var) __asm \
  { \
    LOAD64(Var) \
    /* Var1, Var2, Var3 are temporary vars for level 1 operations */ \
    STORE64(Var1) \
    STORE64(Var2) \
    STORE64(Var3) \
    /* Var1 = ROTR(Var, 1) */ \
    ROTR64(Var1, 1) \
    /* Var2 = ROTR(Var, 8) */ \
    ROTR64(Var2, 8) \
    /* Var3 = SHR(Var3, 7) */ \
    SHR64(Var3, 7) \
    /* Acc = ROTR(Var, 1) */ \
    LOAD64(Var1) \
    /* Acc = ROTR(Var, 1) XOR ROTR(Var, 8) */ \
    XOR64(Var2) \
    /* Acc = ROTR(Var, 1) XOR ROTR(Var, 8) XOR SHR(Var3, 7) */ \
    XOR64(Var3) \
  }

// Implements SSIG1(x) = ROTR^19(x) XOR ROTR^61(x) XOR SHR^6(x)
// On exit result is in edx:eax
#define F_SSIG1_64(Var) __asm \
  { \
    LOAD64(Var) \
    /* Var1, Var2, Var3 are temporary vars for level 1 operations */ \
    STORE64(Var1) \
    STORE64(Var2) \
    STORE64(Var3) \
    /* Var1 = ROTR(Var, 19) */ \
    ROTR64(Var1, 19) \
    /* Var2 = ROTL(Var, 3) */ \
    ROTL64(Var2, 3) \
    /* Var1 = SHR(Var, 6) */ \
    SHR64(Var3, 6) \
    /* Acc = ROTR(Var, 19) */ \
    LOAD64(Var1) \
    /* Acc = ROTR(Var, 19) XOR ROTL(Var, 3) */ \
    XOR64(Var2) \
    /* Acc = ROTR(Var, 19) XOR ROTL(Var, 3) XOR SHR(Var, 6) */ \
    XOR64(Var3) \
  }

/*
 *  Input:  edi - index of Wt variable
 *    ebx - points to message
 *
 *  Output: None
 *
 *  Registers:  eax, edx are modified
 *
 *  Description:  Sets Wt for one given index t
 */

/*
 *  Input:  edi - index of Wt variable
 *
 *  Output: edx:eax = T1
 *
 *  Registers:  eax, edx are modified
 *
 *  Description:  Computes T1 variable
 */

/*
 *  Input:  edi - index of Wt variable
 *
 *  Output: edx:eax = T2
 *
 *  Registers:  eax, edx are modified
 *
 *  Description:  Computes T2 variable
 */

#endif
