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

#define CONST_H0 0x67452301
#define CONST_H1 0xEFCDAB89
#define CONST_H2 0x98BADCFE
#define CONST_H3 0x10325476
#define CONST_H4 0xC3D2E1F0

struct sha1_ctx {
  struct internal_sha_ctx common_ctx;
  UINT32                  vars1[10];
  UINT32                  w1[80];
};

#define CONST_H00 0x6a09e667
#define CONST_H01 0xbb67ae85
#define CONST_H02 0x3c6ef372
#define CONST_H03 0xa54ff53a
#define CONST_H04 0x510e527f
#define CONST_H05 0x9b05688c
#define CONST_H06 0x1f83d9ab
#define CONST_H07 0x5be0cd19

struct sha2_ctx {
  struct internal_sha_ctx common_ctx;
  UINT32                  vars2[16];
  UINT32                  w2[80];
  UINT32                  temps2[2];
};

// Startup values for SHA384 only
#define CONST_H00_64_3 0xcbbb9d5dc1059ed8
#define CONST_H01_64_3 0x629a292a367cd507
#define CONST_H02_64_3 0x9159015a3070dd17
#define CONST_H03_64_3 0x152fecd8f70e5939
#define CONST_H04_64_3 0x67332667ffc00b31
#define CONST_H05_64_3 0x8eb44a8768581511
#define CONST_H06_64_3 0xdb0c2e0d64f98fa7
#define CONST_H07_64_3 0x47b5481dbefa4fa4

// Startup values for SHA512 only
#define CONST_H00_64_5 0x6a09e667f3bcc908
#define CONST_H01_64_5 0xbb67ae8584caa73b
#define CONST_H02_64_5 0x3c6ef372fe94f82b
#define CONST_H03_64_5 0xa54ff53a5f1d36f1
#define CONST_H04_64_5 0x510e527fade682d1
#define CONST_H05_64_5 0x9b05688c2b3e6c1f
#define CONST_H06_64_5 0x1f83d9abfb41bd6b
#define CONST_H07_64_5 0x5be0cd19137e2179

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

// Value of VarFr is copied into VarTo. edx:eax
// On exit edx:eax contain VarFr value.
#define MOV64(VarTo, VarFr) __asm \
  { \
    LOAD64(VarFr) \
    STORE64(VarTo) \
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
// Performs SHL Var, Cnt. Result is stored in Var
// On exit edx:eax contain shifted Var value.
//
#define SHL64(Var, Cnt) __asm \
  { \
    __asm push ecx \
    LOAD64 Var \
    __asm mov ecx, Cnt \
    __asm cmp ecx, 32 \
    __asm jb shl64_1 \
    __asm mov edx, eax \
    __asm mov eax, 0 \
    __asm sub ecx, 32 \
    __asm shl64_1:         \
    __asm shld edx, eax, cl \
    __asm mov DWORD PTR Var + 4, edx  \
    __asm shl eax, cl \
    __asm mov DWORD PTR Var, eax \
 \
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
#define SetWt64 __asm \
  { \
    __asm cmp edi, 16 \
    __asm jae setwt64_1 \
    LOAD64([ebx][edi * 8]) \
    BSWAP64  \
    STORE64(VarW0_79[edi * 8])  \
    __asm jmp beyondFunction \
    __asm setwt64_1: \
    /* Result in edx:eax */ \
    F_SSIG1_64(VarW0_79[edi * 8 - 2 * 8]) \
    /* Wt-7 */ \
    ADD64(VarW0_79[edi * 8 - 7 * 8])  \
    /* Wt-16 */ \
    ADD64(VarW0_79[edi * 8 - 16 * 8])  \
    /* VarT2 is temporary var for level 2 operations */ \
    STORE64(VarT2)  \
    /* result in edx:eax */ \
    F_SSIG0_64(VarW0_79[edi * 8 - 15 * 8])  \
    /* Result in edx:eax */ \
    ADD64(VarT2)  \
    STORE64(VarW0_79[edi * 8])  \
    __asm beyondFunction: \
  }

/*
 *  Input:  edi - index of Wt variable
 *
 *  Output: edx:eax = T1
 *
 *  Registers:  eax, edx are modified
 *
 *  Description:  Computes T1 variable
 */
#define SetT1_64 __asm \
  { \
    F_BSIG1_64 \
    ADD64(VarH) \
    ADD64(ConstK0_79[edi * 8]) \
    /* Wt */ \
    ADD64(VarW0_79[edi * 8]) \
    /* VarT2 is temporary var for level 2 operations */ \
    STORE64(VarT2) \
    F_CH64 \
    ADD64(VarT2) \
    STORE64(T1) \
  }

/*
 *  Input:  edi - index of Wt variable
 *
 *  Output: edx:eax = T2
 *
 *  Registers:  eax, edx are modified
 *
 *  Description:  Computes T2 variable
 */
#define SetT2_64 __asm \
  { \
    F_BSIG0_64 \
    /* VarT2 is temporary var for level 2 operations */ \
    STORE64(VarT2) \
    F_MAJ64 \
    ADD64(VarT2) \
    STORE64(T2) \
  }

#endif
