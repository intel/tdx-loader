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

#ifndef COMMON_H
#define COMMON_H

#pragma pack (push, 1)
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//                          USAGE REQUIREMENTS
// Only general-purpose definitions can be placed in this file,
// free from chipset etc. dependencies.
//
// All definitions must be self-contained, not dependant on information from
// other include files.
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#pragma data_seg("EDATA32")
#pragma bss_seg("EDATA32")
#pragma const_seg("EDATA32")
#pragma warning ( disable : 4091 )
#include <basic_defs.h>
#include <MemoryOps.h>

#define STRINGIFY(X) #X

#define BITN(N)      (1 << (N))
//-----------------------------------------------------------------------------
// Misc definitions and helper macros.
//-----------------------------------------------------------------------------

#define TRUE      1
#define FALSE     0
#define NULL      0
#define EQUAL     0
#define NOT_EQUAL 1

#define IN
#define OUT
#define OPTIONAL

#define max(A, B)      (((A) > (B)) ? (A) : (B))

#define offsetof(T, I) ((UINT32)((UINT8 *)&((T *)0)->I - (UINT8 *)0))

#define highdword(R)   (*((UINT32 *)&(R) +1))

#define rounded(R, V)  ((((R) % (V)) == 0) ? (R) : (((R) / (V)) * (V)) + (V))

//-----------------------------------------------------------------------------
// Common types
//-----------------------------------------------------------------------------
#define INT8   __int8           //char
#define UINT8  unsigned __int8  //char
#define UINT16 unsigned __int16 //short int
#define UINT32 unsigned __int32 //long
#define UINT64 unsigned __int64 //long long
#define UINTN  UINT64
#define INT32  __int32
#define INT64  __int64
typedef UINT8 BOOL;
typedef UINT32 (*PTR_FUNC_NO_ARG) ();

//
// PAE linear address.
// NOTE - "C" structures containing bit fields are allocated in memory
// starting from low order bit. For instance Off bit field in LADRPAE
// DWORD occupies lowest 12 bits.
//
typedef struct _LADRPAE {
  UINT32 Off    : 12; // 11:0 - offset
  UINT32 PTIdx  : 9;  // 20:12 - page table index
  UINT32 PDIdx  : 9;  // 29:21 - page directory index
  UINT32 PDPIdx : 2;  // 31:30 - page directory pointer index.
} LADRPAE;

//
// Content of CRASH register
//
typedef struct _CRASH_REGISTER {
  UINT32 AcmType     : 4;  // 3:0   - Type of ACM
  UINT32 Class       : 6;  // 9:4   - Class of error
  UINT32 Major       : 5;  // 14:10 - Major error code
  UINT32 Source      : 1;  // 15    - Source - ACM or MLE
  UINT32 Minor       : 12; // 27:16 - Minor error code and progress code
  UINT32 Res         : 2;  // 29:28 - Reserved for future
  UINT32 SwGenerated : 1;  // 30 - Register value is SW generated
  UINT32 Valid       : 1;  // 31 - Register value is valid
}CRASH_REGISTER;

typedef struct {
  UINT64 BtPol;
  UINT64 BpKey0;
  UINT64 BpKey1;
  UINT64 BpKey2;
  UINT64 BpKey3;
  UINT64 BpKey4;
  UINT64 BpKey5;
}BOOT_POLICY_DATA;

typedef struct {
  //
  // GTTMMADR
  //
  UINT64 Rc6Mem;
  UINT64 MediaRc6Mem;
  UINT64 Mdrb;
  UINT64 Touud;
  UINT64 Tolud;
  UINT64 Bgsm;
  UINT64 Bdsm;
  UINT64 Ggc;
  UINT64 TsegMb;
  UINT64 Dpr;
  UINT64 Pavpc;
  UINT64 PavpcDE;
  UINT64 PrmrrBase;
  UINT64 PrmrrMask;
  UINT32 Mpmen;
  UINT32 PmrLoBase;
  UINT32 PmrLoLimit;
  UINT32 PmrHiBase;
  UINT32 PmrHiLimit;
  UINT32 GunitCtrl;
  UINT32 GucWopcmOffset;
  UINT32 GucWopcmSize;
  UINT32 GucMediaWopcmOffset;
  UINT32 GucMediaWopcmSize;
} GTT_COPY;

#define _4GB      0x100000000
#define _2GB      0x80000000
#define _1GB      0x40000000
#define _512MB    0x20000000
#define _256MB    0x10000000
#define _128MB    0x8000000
#define _64MB     0x4000000
#define _16MB     0x1000000
#define _8MB      0x800000
#define _4MB      0x400000
#define _2MB      0x200000
#define _1MB      0x100000
#define _512KB    0x80000
#define _256KB    0x40000
#define _128KB    0x20000
#define _64KB     0x10000
#define _32KB     0x8000
#define _16KB     0x4000
#define _12KB     0x3000
#define _8KB      0x2000
#define _4KB      0x1000
#define _2KB      0x800
#define _1KB      0x400
#define _64B      0x40
#define _16B      0x10

#define PAGE4K    0x1000
#define PAGE2M    0x200000

#define _2MB_MASK (~(_2MB - 1))

#define _4KB_MASK (~(_4KB - 1))

//-----------------------------------------------------------------------------
// Maximal values fpr types
//-----------------------------------------------------------------------------
#define MAX_QWORD      ((UINT64) 0xFFFFFFFFFFFFFFFF)
#define MAX_DWORD      ((UINT32) 0xFFFFFFFF)
#define MAX_WORD       ((UINT16) 0xFFFF)

#define MF_PROD_WORTHY 0

//-----------------------------------------------------------------------------
// LCP element selection. Convinient to keep it here since they are
// used in makeflag.mak file, are propagated to makeflag.h file and
// cause sintax error if LCP.H is not included in file being compiled.
//-----------------------------------------------------------------------------

#define LCP_POLELT_TYPE_MLE    0
#define LCP_POLELT_TYPE_PCONF  1

#define LCP_POLELT_TYPE_CUSTOM 3
#define LCP_POLELT_TYPE_STM    4

#define ENTERACCS              2
#define SENTER                 4

//-----------------------------------------------------------------------------
// Control registers
//-----------------------------------------------------------------------------
//
// CR0 bits
//
#define CR0_PE         BIT0
#define CR0_ET         BIT4
#define CR0_NE         BIT5
#define CR0_WP         BIT16
#define CR0_PG         BIT31

#define CR4_DE         BIT3
#define CR4_PAE        BIT5
#define CR4_PGE        BIT7
#define CR4_OSFXSR     BIT9
#define CR4_OSXMMEXCPT BIT10
#define CR4_LA57       BIT12
#define CR4_VMXE       BIT13
#define CR4_SMXE       BIT14
#define CR4_FSGSBASE   BIT16
#define CR4_OSXSAVE    BIT18
#define CR4_SMEP       BIT20
#define CR4_SMAP       BIT21
#define CR4_CET        BIT23
#define CR4_LASS       BIT27

//-----------------------------------------------------------------------------
// CPUID family/model/stepping masks
//-----------------------------------------------------------------------------

#define CPUID_XTENDED_FAMILY (0xFF << 20)
#define CPUID_XTENDED_MODEL  (0xF << 16)
#define CPUID_FAMILY         (0xF << 8)
#define CPUID_MODEL          (0xF << 4)
#define CPUID_FMS_MASK       (CPUID_XTENDED_FAMILY + CPUID_XTENDED_MODEL + CPUID_FAMILY + CPUID_MODEL)

//-----------------------------------------------------------------------------
// SHAXXX hash
//-----------------------------------------------------------------------------

#define H_LEN 20

//-----------------------------------------------------------------------------
// MSRs. Place only architectural, not CPU specific MSRs here
//-----------------------------------------------------------------------------

#define MSR_PLATFORM_INFO 0xCE
#define MSR_CACHE_FLUSH   0x10B //architecturally supported in both BigCore and Atom post-JVL
#define CACHE_FLUSH_CMD   BIT0

typedef struct _LAPIC_REG_SAVE {
  UINT32 RegIdx;
  UINT32 RegVal;
} LAPIC_REG_SAVE;

#define MSR_IA32_BIOS_SIGN_ID 0x08B

#define MSR_BTG_BOOT_STATUS   0x138

#define MSR_SGX_DEBUG_MODE    0x503
#define MSR_IA32_MISC_ENABLES 0x1A0

#define MSR_BIOS_DONE         0x151

//   #define SINIT_SE_SVN_MASK      (~0xFF0000)
//   #define BIOSAC_SE_SVN_MASK     (~0xFF000000)
//   #define BTG_SE_SVN_MASK        (~0xFF00000000)
//   #define SINIT_SE_SVN_SHIFT     16
//   #define BIOSAC_SE_SVN_SHIFT    24

typedef union {
  struct {
    UINT32 VALID      : 1;  // [0]     [RW/1S/V] Spiral buffer Valid
    UINT32            : 3;  // [3:1]   [RO] reserved
    UINT32 offset_2_0 : 3;  // [6:4]   [RO] Always zero since buffer is aligned with 8 bytes
    UINT32 OFFSET     : 21; // [27-7]  [RW/V] Host Secure Boot SRAM access offset
    UINT32            : 3;  // [30-28] [RO] reserved
    UINT32 INC_EN     : 1;  // [31]    [RW] Increment enable.
  } bits;
  UINT32 raw;
} SPIRAL_CSME_CTRL_t; // maps to MSR_SPRIRAL_CSME_READ_DATA

typedef struct {
  UINT32 SPIRAL_DATA_LO;     // [31:0]  Contains data found at SPIRAL_CSME_CTRL.OFFSET
  UINT32 SPIRAL_DATA_HI;     // [63:32] Contains data found at SPIRAL_CSME_CTRL.OFFSET+4
} SPIRAL_CSME_DATA_ACCESS_t; //

#define MSR_SPIRAL_CSME_ACCESS_CTRL 0x1133
typedef struct {
  UINT32 CSE_ACCESS_EN    : 1;  // [0]     Enables CSE access to spiral buffer via CSE access window
  UINT32 HOST_ACCESS_EN   : 1;  // [1]     Enables host access to spiral buffer via CSE access window
  UINT32                  : 1;  // [2]     reserved
  UINT32 HOST_ACCESS_LOCK : 1;  // [3]     Lock bit for
  UINT32 CPUNUM           : 4;  // [7:4]   [RW/L] CPU Number
  UINT32 SIZE             : 20; // [27:8]  [RO] SPIRAL Buffer Size in Words (16-bits)
  UINT32                  : 4;  // [31:28] reserved
} SPIRAL_CSME_ACCESS_CTRL_t;    // Maps to MSR_SPIRAL_CSME_ACCESS_CTRL

//
// FLOOR and CEILING definitions. CEILING use requires 64 bit output
// values. This is because output value may become over 4GB even if
// enties are below 4GB.
// Example:
//      UINT64 OutVar;
//      UINT32 InVar;
//      OutVar = CEILING(InVar,_4KB);

#define FLOOR(addr, interval)   ((((UINT64)addr)) & (~((UINT64)((interval) - 1))))
#define CEILING(addr, interval) (FLOOR((addr), (interval)) == addr ? addr : ((UINT64)FLOOR((addr), (interval)) + (UINT64)interval))

#define IA32_EFER_MSR   0xC0000080
#define LME             BIT8
#define N_IA32_EFER_LMA BIT10
#define N_IA32_EFER_NXE BIT11

//-----------------------------------------------------------------------------
// TXT register space
//-----------------------------------------------------------------------------

#define LT_PUB_BASE 0xFED30000
#define LT_PRV_BASE 0xFED20000

#define FILL64(H, L) ((((H)-(L)) / 8) - 1)
#define FILL8(H, L)  (((H)-(L)) - 1)

typedef struct _TXT {
  UINT64 LT_STS;               // 0000h
  UINT64 LT_ESTS;              // 0008h
  UINT64 LT_THREADS_EXISTS;    // 0010h
  UINT64 R1_0;                 // 0018h
  UINT64 LT_THREADS_JOIN;      // 0020h
  UINT64 R1_1;                 // 0028h
  UINT64 LT_CRASH;             // 0030h
  UINT64 LT_CMD_SYS_RESET;     // 0038h
  UINT64 LT_CMD_OPEN_PRIVATE;  // 0040h
  UINT64 LT_CMD_CLOSE_PRIVATE; // 0048h
  UINT64 LT_CRASH2;            // 0050h

  UINT64 R2_0[FILL64(0xA0, 0x50)];
  UINT64 LT_SPAD; // 00A0h

  UINT64 R3_0[FILL64(0x100, 0xA0)];
  UINT64 LT_VER_FSBIF; // 0100h
  UINT64 R3_1;         // 0108h
  UINT64 LT_DIDVID;    // 0110h
  UINT64 LT_EID;       // 0118h

  UINT64 R4_0[FILL64(0x200, 0x118)];
  UINT64 LT_VER_EMIF;                    // 0200h
  UINT64 R4_1;                           // 0208h
  UINT64 LT_CMD_LOCKMEM_CONFIG;          // 0210h
  UINT64 LT_CMD_UNLOCK_MEM_CONFIG;       // 0218h
  UINT64 LT_CMD_UNLOCK_MEMORY;           // 0220h
  UINT64 R4_2;                           // 0228h
  UINT64 LT_LOCK_BASE;                   // 0230h
  UINT64 LT_UNLOCK_BASE;                 // 0238h
  UINT64 R4_3;                           // 0240h
  UINT64 R4_4;                           // 0248h
  UINT64 LT_CMD_CACHE_INVALIDATE;        // 0250h
  UINT64 LT_CMD_FLUSH_WB;                // 0258h
  UINT64 LT_NODMA_BASE;                  // 0260h
  UINT64 LT_NODMA_SIZE;                  // 0268h
  UINT64 LT_SINIT_BASE;                  // 0270h
  UINT64 LT_SINIT_SIZE;                  // 0278h
  UINT64 LT_CMD_LOCK_PMRC;               // 0280h
  UINT64 LT_CMD_UNLOCK_PMRC;             // 0288h
  UINT64 LT_MLE_JOIN;                    // 0290h
  UINT64 R4_5;                           // 0298h
  UINT64 LT_BLOCKMAP_CAP;                // 02A0h
  UINT64 LT_BLOCKMAP_CNF;                // 02A8h
  UINT64 LT_BLOCKMAP_POINTER;            // 02B0h
  UINT64 R4_6;                           // 02B8h
  UINT64 LT_CMD_BLOCKMAP_EN;             // 02C0h
  UINT64 LT_CMD_BLOCKMAP_DIS;            // 02C8h
  UINT64 LT_CMD_NODMA_CACHE_EN;          // 02D0h
  UINT64 LT_CMD_NODMA_CACHE_DIS;         // 02D8h
  UINT64 LT_CMD_NODMA_TABLE_PROTECT_EN;  // 02E0h
  UINT64 LT_CMD_NODMA_TABLE_PROTECT_DIS; // 02E8h
  UINT64 LT_CMD_MEM_CONFIG_CHECKED;      // 02F0h
  UINT64 R4_7;                           // 02F8h
  UINT64 LT_HEAP_BASE;                   // 0300h
  UINT64 LT_HEAP_SIZE;                   // 0308h
  UINT64 LT_MSEG_BASE;                   // 0310h
  UINT64 LT_MSEG_SIZE;                   // 0318h
  UINT64 LT_SCRATCHPAD_0;                // 0320h
  UINT32 LT_BIOSACMCode;                 // 0328h
  UINT32 LT_ACM_BIOS_POLICY;             // 032ch
  UINT64 LT_DPR;                         // 0330h
  UINT64 R4_8;                           // 0338h
  UINT64 LT_FIT_STATUS;                  // 0340h
  UINT64 R4_9;                           // 0348h
  UINT64 LT_INCREMENT;                   // 0350h
  UINT64 LT_SPAD_3;                      // 0358h
  UINT64 LT_SCRATCHPAD_4;                // 0360h
  UINT64 LT_SCRATCHPAD_5;                // 0368h
  UINT64 LT_INCREMENT_2;                 // 0370h
  UINT64 LT_SCRATCHPAD_6;                // 0378h
  UINT64 LT_CMD_OPEN_LOCALITY1;          // 0380h
  UINT64 LT_CMD_CLOSE_LOCALITY1;         // 0388h
  UINT64 LT_CMD_OPEN_LOCALITY2;          // 0390h
  UINT64 LT_CMD_CLOSE_LOCALITY2;         // 0398h
  UINT64 LT_CMD_OPEN_LOCALITY3;          // 03A0h
  UINT64 LT_CMD_CLOSE_LOCALITY3;         // 03A8h

  UINT64 R5_0[FILL64(0x400, 0x3A8)];
  UINT64 LT_PUBLIC_KEY; // 0400h

  UINT64 R5_1[FILL64(0x608, 0x400)];
  UINT64 LT_ESTS_SET;   // 0608h
  UINT64 LT_EXISTS_SET; // 0610h
  UINT64 R5_2;          // 0618h
  UINT64 LT_JOINS_SET;  // 0620h

  UINT64 R6_0[FILL64(0x670, 0x620)];
  UINT64 LT_SCLEAN_SET; // 0670h

  UINT64 R7_0[FILL64(0x6A0, 0x670)];
  UINT64 LT_SPAD_SET; // 06A0h

  UINT64 R8_0[FILL64(0x710, 0x6A0)];
  UINT64 LT_EXISTS_CLEAR; // 0710h
  UINT64 R8_1;            // 0718h
  UINT64 LT_JOINS_CLEAR;  // 0720h

  UINT64 R9_0[FILL64(0x770, 0x720)];
  UINT64 LT_SCLEAN_CLEAR; // 0770h

  UINT64 R10_0[FILL64(0x7A0, 0x770)];
  UINT64 LT_SPAD_CLEAR; // 07A0h

  UINT64 R11_0[FILL64(0x800, 0x7A0)];
  UINT64 LT_VER_FTIF;   // 0800h
  UINT64 R11_1;         // 0808h
  UINT64 LT_PCH_DIDVID; // 0810h

  UINT64 R12_0[FILL64(0x880, 0x810)];
  UINT64 LT_UCS; // 880h

  UINT64 R13_0[FILL64(0x8E0, 0x880)];
  UINT64 LT_CMD_SECRETS;    // 08E0h
  UINT64 LT_CMD_NO_SECRETS; // 08E8h
  UINT64 LT_E2STS;          // 08F0h
  UINT64 R13_1;             // 08F8h
  UINT32 LT_FT_REGS1;       // 0900h
  UINT32 LT_FT_REGS2;       // 0904h

  UINT64 R14_0[FILL64(0xD80, 0x900)];
  UINT64 LT_SEQ_START;     // 0D80h
  UINT64 R14_2;            // 0D88h
  UINT64 LT_SEQ_DONE;      // 0D90h
                           //
                           // Added with Sunrise Point and Lewisburg
                           // These all behave like INCREMENT2 / SPAD6 pair
                           //
  UINT64 LT_INCREMENT_3;   // 0D98h
  UINT64 LT_SCRATCHPAD_7;  // 0DA0h
  UINT64 LT_INCREMENT_4;   // 0DA8h
  UINT64 LT_SCRATCHPAD_8;  // 0DB0h
  UINT64 LT_INCREMENT_5;   // 0DB8h
  UINT64 LT_SCRATCHPAD_9;  // 0DC0h
  UINT64 LT_INCREMENT_6;   // 0DC8h
  UINT64 LT_SCRATCHPAD_10; // 0DD0h
  UINT64 LT_INCREMENT_7;   // 0DD8h
  UINT64 LT_SCRATCHPAD_11; // 0DE0h
  UINT64 LT_INCREMENT_8;   // 0DE8h
  UINT64 LT_SCRATCHPAD_12; // 0DF0h
} TXT;

//
// Selected register bit structures.
//

typedef struct {
  UINT32 SenterDone_Sts    : 1;
  UINT32 SexitDone_Sts     : 1;
  UINT32 Reserved          : 2;
  UINT32 MemUnlock_Sts     : 1;
  UINT32 BaseLocked_Sts    : 1;
  UINT32 Reserved2         : 1;
  UINT32 PrivateOpen_Sts   : 1;
  UINT32 Reserved3         : 3;
  UINT32 MemConfigOk_Sts   : 1;
  UINT32 Reserved4         : 2;
  UINT32 Locality3Open_Sts : 1;
  UINT32 Locality1Open_Sts : 1;
  UINT32 Locality2Open_Sts : 1;
  UINT32 SeqInProgress     : 1;
  UINT32 Reserved5         : 14;
} REG_STS;

typedef struct {
  UINT32 Poison_Sts    : 1;
  UINT32 Rogue_Sts     : 1;
  UINT32 Memory_Attack : 1;
  UINT32 Reserved      : 2;
  UINT32 Aliasi_Fault  : 1;
  UINT32 Wakeerror_Sts : 1;
  UINT32 Reserved2     : 25;
} REG_ESTS;

typedef struct {
  struct {
    UINT32 Sleep_Entry_Error_Sts : 1;
    UINT32 Secrets_Sts           : 1;
    UINT32 Block_Mem_Sts         : 1;
    UINT32 Reset_Sts             : 1;
    UINT32 Reserved              : 28;
  } LowWrd;
  struct {
    UINT32 Reset_Policy : 1;
    UINT32 Reserved2    : 31;
  } HighWrd;
} REG_E2STS;

//-----------------------------------------------------------------------------
// ACM - PE2BIN communication area
//-----------------------------------------------------------------------------
typedef struct _COM_DATA {
  UINT32 Data64Start; // Offset of 64-bit data start (and Code32End)
  UINT32 Code64Start; // Offset of 64-bit code start
  UINT32 Code64End;   // Offset of 64-bit code end
  UINT32 Code64Entry; // Offset of 64-bit code entry point
  UINT32 StkStart;    // Offset of stack start
  UINT32 Code32Start; // Offset of code segment start.
} COM_DATA;

typedef struct _SAVE_STATE_MAP {
  UINT8  Res[0xFEEC];
  UINT32 IEDBASE;
  UINT8  Res2[0xFEF8 - 0xFEEC - 4];
  UINT32 SMBASE;
  UINT32 SMREVID;
} SAVE_STATE_MAP;

//-----------------------------------------------------------------------------
// Error handling related defines.
//-----------------------------------------------------------------------------

//
// Crash register bit masks. Sometimes use of CRASH_REGISTER structure
// defined above is not convinient. Here are equivalent bit definitions.
//

#define CRASH_CODE_VALID        0x80000000
#define CRASH_CODE_SW_GENERATED 0x40000000

#define CPU_AUTH_ERR            0x7

//
//  Error context variable.
//
typedef struct _ERR_CONTEXT {
  UINT32 Class;
  UINT32 Major;
  UINT32 Minor;
} ERR_CONTEXT;

//
// Value passed to error handler to indicate that it has to retrieve
// respective error/class code from error context variable.
//
#define VOID -1

#include <AcmErr.h>
#include <AcmErrExtend.h>

//-----------------------------------------------------------------------------
// Ranges
//-----------------------------------------------------------------------------

//
// Range flags and attributes - directs how range must be placed.
// Simple flags and attributes correspond to each other - for each flag
// must be one and only one range with the same attribute.
//

#define LBL_PCI_NON_SPECIFIC BIT1

typedef struct _RANGE {
  UINT64 labl;  // Label - GHX, ISA hole etc.
  UINT16 attr;  // Access attribute
  UINT16 flags; // Flags specifying range
  UINT64 len;
  UINT64 base;
  UINT64 top;
  UINT64 almtMask; // Mask of aligment bits
} RANGE;

#define CONTAINED     BIT0
#define ENCLOSES      BIT1
#define CONGRUENT     BIT2
#define ABOVE         BIT3
#define BELOW         BIT4
#define TANGENT_ABOVE BIT5
#define TANGENT_BELOW BIT6

#define TANGENT       (TANGENT_ABOVE + TANGENT_BELOW)
#define DISJOINT      (ABOVE + BELOW)

#define ANY           -1 // any value

//-----------------------------------------------------------------------------
// Parameters passed to page retrieval function to indicate first
// call or subsequent call.
//-----------------------------------------------------------------------------

#define MAX_LEN_BOUND  0
#define MAX_ADDR_BOUND ~MAX_LEN_BOUND

//-----------------------------------------------------------------------------
// Include makeflag here to use it in preprocessing of
// platform-specific selections.
// Late placement of makeflag.h files allows use in it of common
// definitions.
//-----------------------------------------------------------------------------

#define TRAPLOOP(X) { volatile int foo = (X); while (foo); }

#ifdef MKF_USE_MAKEFLAG_H
#include <makeflag.auto>
//#include <Benchmark.h>
#include <Trace.h>
#include <Mmio.h>
#include <Pci.h>
#endif

//-----------------------------------------------------------------------------
// Interface
//-----------------------------------------------------------------------------

typedef UINT32 (*UINT32_NO_ARG) ();
typedef UINT16 (*UINT16_NO_ARG) ();
typedef UINT8 (*UINT8_NO_ARG) ();
typedef UINT8 (*UINT8_ARG_UINT32) (UINT32);
typedef UINT8 * (*UINT8_ARG_UINT32_UINT32_UINT32) (UINT32, UINT32, UINT32);
typedef UINT32 (*UINT32_ARG_UINT32) (UINT32);
typedef void (*VOID_NO_ARG) ();
typedef void (*VOID_ARG_UINT32) (UINT32);
typedef void (*VOID_ARG_UINT16) (UINT16);
typedef void (*VOID_ARG_PUINT8_UINT32) (UINT8 *, UINT32);
typedef void (*VOID_ARG_UINT32_PUINT8) (UINT32, UINT8 *);
typedef void (*VOID_ARG_UINT32_UINT32) (UINT32, UINT32);
typedef void (*VOID_ARG_UINT32_UINT32_UINT32) (UINT32, UINT32, UINT32);
typedef void (*VOID_ARG_UINT32_UINT32_UINT32_PUINT8_UINT32) (UINT32, UINT32, UINT32, UINT8 *, UINT32);
typedef void (*VOID_ARG_UINT32_UINT32_UINT32_PUINT8) (UINT32, UINT32, UINT32, UINT8 *);
typedef void (*VOID_ARG_UINT32_UINT32_PVOID_UINT32_PUINT8) (UINT32, UINT32, void *, UINT32, UINT8 *);

void commonAcmEntryPoint();
void ProjectAcmEntryPoint();

UINT16 Compare(const UINT8 Order, const UINT16 CmpWidth, const void *First, const void *Second);

void Sort(void *Array, UINT16 Count, UINT16 EltWidth, UINT16 CmpOffset, UINT8 Order, UINT16 CmpWidth,
          UINT16 (*Compare)(const UINT8 Order, const UINT16 CmpWidth, const void *First, const void *Second));

void Movdir64B(const void *, void *);
void SeamldrThunk64();
void CoreAcmErrorHandler(UINT32, UINT32);
void ProgressMark(UINT8);
void LtReset();
void __ErrorHandler(UINT32, UINT32);
void __readMsr(UINT32, UINT32 *, UINT32 *);
UINT64 __readMsr64(UINT32);
void __writeMsr(UINT32, UINT32, UINT32);
void __writeMsr64(UINT32, UINT64);
void _ud2(void);
UINT64 readTsc64();
void WriteCr3(UINT64);
UINT64 ReadCr3();
void ProbeMchBar(UINT64);
void ServerProbeBar(UINT64);
void __Wait10us();
UINT32 get_esp(void);

void __writecr3(unsigned __int64 value);
#pragma intrinsic(__writecr3)

#if TRACE_WITH_FUNCTIONS & TRACE_MSR

#define readMsr(A, B, C) do { \
    UINT32 REG1, REG2; \
    __readMsr((A), (B), (C)); \
    REG1 = REG2 = 0; \
    if ((B)) \
    REG1 = *((UINT32 *)(B)); \
    if ((C)) \
    REG2 = *((UINT32 *)(C)); \
    TRACEFUNCTION(TRACE_MSR, "MSRRD(%s#%d): %04x=%08x%08x\n", __FUNCTION__, __LINE__, (A), REG1, REG2); \
} while(0)

static __inline UINT64 _readMsr64(UINT32 addr, const char *name, UINT32 lineNumber)
{
  UINT64 dummy;

  dummy = __readMsr64(addr);
  TRACEFUNCTION(TRACE_MSR, "MSRRD(%s#%d): %04x=%L\n", name, lineNumber, addr, dummy);
  return dummy;
}

#define readMsr64(A)      _readMsr64(A, __FUNCTION__, __LINE__)

#define writeMsr(A, B, C) do { \
    TRACEFUNCTION(TRACE_MSR, "MSRWR(%s#%d): %04x=%08x%08x\n", __FUNCTION__, __LINE__, (A), (B), (C)); \
    __writeMsr((A), (B), (C)); \
} while(0)

#else
#define readMsr(A, B, C)  __readMsr((A), (B), (C))
#define readMsr64(A)      __readMsr64((A))
#define writeMsr(A, B, C) __writeMsr((A), (B), (C))
#define writeMsr64(A, B)  __writeMsr64((A), (B))
#endif

#if TRACE_WITH_FUNCTIONS & TRACE_ERRORHANDLER
#define ErrorHandler(A, B) do { \
    TRACEFUNCTION(TRACE_ERRORHANDLER, "ERROR-HANDLER(%s#%d)\n", __FUNCTION__, __LINE__); \
    __ErrorHandler((A), (B)); \
} while(0)
#else
#define ErrorHandler(A, B) __ErrorHandler((A), (B))
#endif

UINT32 isMetForAllRanges(
  RANGE *,
  RANGE **,
  UINT32,
  UINT64,
  UINT32
  );

UINT32 isMetForOneOfRanges(
  RANGE *,
  RANGE **,
  UINT32,
  UINT64,
  UINT32
  );

UINT32 basicIsRangeSeparate(
  RANGE *,
  UINT64
  );

UINT32 basicIsSeparate(
  UINT64
  );

UINT32 areRangesContiguous(
  RANGE *[],
  UINT32,
  UINT64
  );

UINT64 shiftLeft64(UINT64, UINT32);

UINT32 arrayCheck(RANGE *[], UINT32, UINT64);

UINT32 BitScanForward64(UINT32 *, UINT64);
UINT32 BitScanReverse64(UINT32 *, UINT64);
UINT32 BitScanForward64AndReset(UINT32 *, UINT64 *);
UINT32 BitScanReverse64AndReset(UINT32 *, UINT64 *);
UINT32 BitScanForwardAndReset(UINT32 *, UINT32 *);
UINT32 BitScanReverseAndReset(UINT32 *, UINT32 *);
UINT32 GetSgxFusingInfo();
void Update_CRx();
void x86_copy8b(UINT8 *, UINT8 *);
void x86_copy16b(UINT8 *, UINT8 *);
void x86_copy32b(UINT8 *, UINT8 *);
void x86_copy64b(UINT8 *, UINT8 *);

typedef UINT32 (*GET_DATA)                (UINT32, UINT32 *, UINT32 *);
//void    getPcrValue                       (UINT32, UINT8 *);

UINT32 GetMaxPhyAddr();
UINT64 GetPhyAddrMask();
UINT32 GetCpuFms();

void SignalSinitScheckWasRun();
void VerifySinitScheckWasRun();
void ServerSignalSinitScheckWasRun();
void ServerVerifySinitScheckWasRun();
void ClientHandleTopSwap();
void ServerHandleTopSwap();

INT32 perform_ebp_checks(UINT32 dest, UINT32 size);

UINT32 isRangeSeparate(
  RANGE *,
  RANGE *[],
  UINT32,
  UINT64
  );

UINT32 validateRangePlacement(RANGE *);
BOOL BtgProfile3Handling();

#define HOOK(A) Hook ## A

#define CLIENT                       1
#define SERVER                       2
#if     MCP_PLATFORM_TYPE == CLIENT
#define HookSignalSinitScheckWasRun  SignalSinitScheckWasRun
#define HookVerifySinitScheckWasRun  VerifySinitScheckWasRun
#define HookPlatformSpecificServices ClientPlatformSpecificServices
#define HookDmarSpecificChk          ClientDmarSpecificChk
#define HookProbeMchBar              ProbeMchBar
#define HookSaveEnableMchBar         SaveEnableMchBar
#define HookRestoreMchBar            RestoreMchBar
#define HookTopSwap                  ClientHandleTopSwap

#ifdef  MKF_BTG21_SUPPORT
#define HookStartupBlockBootSupport() do {StartupBlockBootSupport(); \
                                          if (BtgErrorResult.raw != BTG_SUCCESS) { \
                                            SET_BTG_ESC(ANC_PROGRESS_IBBL_FAIL); \
                                            goto FnStartupExit; \
                                          } \
} while (0)

#define Hooksetup_mtrrs()             setup_mtrrs_wb()
#define HookBtgProfile3Handling()
#else
#define HookStartupBlockBootSupport()
#define Hooksetup_mtrrs()         setup_mtrrs_wp()

#define HookBtgProfile3Handling() do {if (TRUE == BtgProfile3Handling()) \
                                      goto DoTxtProcessing; \
                                      } while (0)
#endif

#else
#define HookSignalSinitScheckWasRun() ServerSignalSinitScheckWasRun()
#define HookVerifySinitScheckWasRun() ServerVerifySinitScheckWasRun()
#define HookPlatformSpecificServices()
#define HookStartupBlockBootSupport()
#define Hooksetup_mtrrs() setup_mtrrs_clusters()
#define HookDmarSpecificChk
#define HookBtgProfile3Handling()
#define HookProbeMchBar      ServerProbeBar
#define HookSaveEnableMchBar ServerSaveEnableMchBar
#define HookRestoreMchBar    ServerRestoreMchBar
#define HookTopSwap          ServerHandleTopSwap
#endif

#ifdef MKF_LPSS_UART_SUPPORT
#define HookSerialout PchUartSerialOut
#else
#define HookSerialout ComSerialOut
#endif

#ifdef UNIT_TEST
#define HookSetXCRregister     SetXCRregister_mock
#define Hookperform_ebp_checks __perform_ebp_checks
#define HookGetSgxFusingInfo   __GetSgxFusingInfo
#define HookGetFitData         GetFitData_mock
#define Hookx86_copy8b         x86_copy8b_mock
#define Hookx86_copy16b        x86_copy16b_mock
#define Hookx86_copy32b        x86_copy32b_mock
#define Hookx86_copy64b        x86_copy64b_mock
#define HookMleLinToPhyAddr    MleLinToPhyAddr_mock
#define HookValidateAndHashMle ValidateAndHashMle_mock
#else
#define HookSetXCRregister     SetXCRregister
#define Hookperform_ebp_checks perform_ebp_checks
#define HookGetSgxFusingInfo   GetSgxFusingInfo
#define HookGetFitData         GetFitData
#define Hookx86_copy8b         x86_copy8b
#define Hookx86_copy16b        x86_copy16b
#define Hookx86_copy32b        x86_copy32b
#define Hookx86_copy64b        x86_copy64b
#define HookMleLinToPhyAddr    MleLinToPhyAddr
#define HookValidateAndHashMle ValidateAndHashMle
#endif

#if MKF_IBL_SUPPORTED == 0
UINT32 ReadHeciDeviceDwordRegister(UINT32);
void WriteHeciDeviceDwordRegister(UINT32, UINT32);
#define HookReadHeciDeviceDwordRegister  ReadHeciDeviceDwordRegister
#define HookWriteHeciDeviceDwordRegister WriteHeciDeviceDwordRegister
#else
UINT32 NullHeciDeviceDwordRegister(UINT32);
#define HookReadHeciDeviceDwordRegister NullHeciDeviceDwordRegister
#define HookWriteHeciDeviceDwordRegister
#endif

void WaitFixedTime(UINT32);
#define Wait100ms() WaitFixedTime(100)

UINT32 TinyWaitRegisterValue(UINT32, UINT32, UINT32, UINT32, UINT32, UINT32);
#define In10USEC 0
#define In1MSEC  1

UINT32 BaseWaitMsrValue(UINT32, UINT64, UINT32, UINT64, UINT32, UINT32);

UINT32 __WaitRegisterBitSet(UINT32, UINT32);
UINT32 __WaitRegisterBitClear(UINT32, UINT32);

#ifndef HI_SMRR_MASK
#define HI_SMRR_MASK 0
#endif
#ifndef HI_SMRR2_MASK
#define HI_SMRR2_MASK 0
#endif

extern UINT8 IslegacySupported;
extern UINT8 Allow_Holly_patch;
extern ERR_CONTEXT ErrCtx;
extern UINT8 stackStart[];
extern UINT32 CodeSegmentStart;
extern UINT32 PageDirectoryBase;
extern UINT32 ChipsetAcmType;
extern UINT32 NotProductionWorthy;
extern UINT8 MleDigest[H_LEN];
extern UINT32 TxtErrorRegister;
extern UINT32 Ltsx_ClientTxt;
extern UINT64 LtCtlSts;
extern UINT64 BiosDoneSts;
extern UINT64 ClockCount;
extern UINT32 MaxSupportedBlockWidthIndex;
extern BOOT_POLICY_DATA BtPolData;
extern GTT_COPY GttData;
extern UINT32 AcmBase;
extern UINT32 AcmSize;
extern UINT32 AcmTop;
extern UINT64 OriginalIDTR;
extern UINT32 OriginalEIP;
extern UINT32 OriginalEAX;
extern UINT32 OriginalESI;
extern UINT32 OriginalEDI;
extern UINT32 OriginalEDX;
extern UINT32 OriginalCR4;
extern UINT32 OriginalCR0;

void INTErrorHandler();

extern RANGE R_ACM;
extern RANGE R_HEAP;
extern RANGE R_ME_UMA;
extern RANGE R_SINIT;
extern RANGE R_LAPIC_REG;
extern RANGE R_MCH_REG;
extern RANGE R_EP_REG;
extern RANGE R_DMI_REG;
extern RANGE R_APIC_REG;
extern RANGE R_TXT_REG;
extern RANGE R_SPI_ADR;
extern RANGE R_PCIE_REG;
extern RANGE R_REMAP;
extern RANGE R_GM_ADR;
extern RANGE R_GTT_ADR;
extern RANGE R_GTT_UMA;
extern RANGE R_PEG10_REG;
extern RANGE R_PEG11_REG;
extern RANGE R_PEG12_REG;
extern RANGE R_PEG60_REG;
extern RANGE R_PEG10_MEM;
extern RANGE R_PEG11_MEM;
extern RANGE R_PEG12_MEM;
extern RANGE R_PEG60_MEM;
extern RANGE R_CHAP_REG;
extern RANGE R_ISA_HOLE;
extern RANGE R_LEGACY;
extern RANGE R_TOUUD;
extern RANGE R_4GBMEM;
extern RANGE R_VTD0_REG;
extern RANGE R_VTD1_REG;
extern RANGE R_UMA;
extern RANGE R_TSEG;
extern RANGE R_GFX_UMA;
extern RANGE R_DPR;
extern RANGE R_PMR_LO;
extern RANGE R_PMR_HI;
extern RANGE R_PCI_LO;
extern RANGE R_PCI_HI;
extern RANGE R_DRAM_HI;
extern RANGE R_DRAM_LO;
extern RANGE R_SMRR;
extern RANGE R_PMR_LO_RQU;
extern RANGE R_PMR_HI_RQU;
extern RANGE R_LCP_POWN;
extern RANGE R_DMAR_TAB;
extern RANGE R_RMRR_TAB[];
extern RANGE R_MADT_TAB;
extern RANGE R_MCFG_TAB;
extern RANGE R_CEDT_TAB;
extern RANGE R_DTPR_TAB;
extern RANGE R_MSI;
extern RANGE R_CRAB;
extern RANGE R_HPET;
extern RANGE R_SMRR2;
extern RANGE R_ELOG;
extern RANGE R_ELOG_SHA256;
extern RANGE R_ELOG_SHA384;
extern RANGE R_ELOG_SHA512;
extern RANGE R_ELOG_SM3;
extern RANGE R_HEAP_OS2MLE;
extern RANGE R_TMBAR;
extern RANGE R_GDXC_REG;
extern RANGE R_PAVPC;
extern RANGE R_WOPCM;
extern RANGE R_MDRBMEM;
extern RANGE R_RC6MEM;
extern RANGE R_MEDIARC6MEM;
extern RANGE R_UMAGFX;
extern RANGE R_MSEG;
extern RANGE R_SGX[];
extern RANGE R_ISP;
extern RANGE R_NP_MTB;
extern RANGE R_NP_SW;
extern RANGE R_NP_RTIT;
extern RANGE R_NP_FW;
extern RANGE R_PMBAR;
extern RANGE R_EDSR;
//Add Sec Range
extern RANGE R_NP_MSC0;
extern RANGE R_NP_MSC1;
extern RANGE R_NP_PCH_MSC0;
extern RANGE R_NP_PCH_MSC1;
extern RANGE R_EDRAM;
extern RANGE R_REGBAR;

extern RANGE R_IMR [];
extern RANGE R_IMR_IA_EXC;
extern RANGE R_IMR_GT_EXC;

extern RANGE R_CXL_REG[];

extern RANGE R_TBL_END;
extern RANGE R_VTD_REG [];
extern RANGE R_PQA [];

extern UINT64 DRAM_EXCLUSIVE_LABELS;

#ifndef MAX_PRMRR_COUNT
#define MAX_PRMRR_COUNT 1
#endif

#ifndef MAX_VTD_COUNT
#define MAX_VTD_COUNT 2
#endif

#ifndef MAX_TPR_COUNT
#define MAX_TPR_COUNT 2
#endif

#ifndef MAX_TPR_INS_COUNT
#define MAX_TPR_INS_COUNT 2
#endif

#ifndef MAX_RMRR_COUNT
#define MAX_RMRR_COUNT 1
#endif

#ifndef MAX_IMR_COUNT
#define MAX_IMR_COUNT 1
#endif

#ifndef MAX_CXL_COUNT
#define MAX_CXL_COUNT 1
#endif

//TODO: add CXL devices to this structure.
//requires Client validation
#if MCP_CHIPSET_ACM_TYPE == AC_SINIT
typedef struct _RANGE_STRUCT {
  RANGE *vtd_range[MAX_VTD_COUNT];
  RANGE *pqa_range[MAX_VTD_COUNT];
  RANGE *rmrr_range[MAX_RMRR_COUNT];
  RANGE *imr_range[MAX_IMR_COUNT];
  RANGE *sgx_range[MAX_PRMRR_COUNT];
#if TPR_SUPPORTED == 1
  RANGE *tpr_range[MAX_TPR_COUNT];
#endif
  RANGE *fix_range[];
} RANGE_STRUCT;

extern RANGE_STRUCT ProjectRangeTable_0;
#define ProjectRangeTable ProjectRangeTable_0.vtd_range

#else

extern RANGE *ProjectRangeTable[];

#endif // MCP_CHIPSET_ACM_TYPE==AC_SINIT
//
// Definition help catch error at build time.
//
#define C_ASSERT(e) typedef char ___C_ASSERT___ [e?1:-1]

#ifdef UNIT_TEST
// flag defined in GnuMakefile used for ULT frame-work alone
// These mock functions emulate hardware access
#include "mocks.h"

#endif

#if MKF_TRACE == 1
void ComSerialOut(unsigned char *str);
void printHex(UINT64 num);
#define COMSERIALOUT(x) ComSerialOut(x)
#define PRINTHEX(x)     printHex(x)
#else
#define COMSERIALOUT(...)
#define PRINTHEX(...)
#endif

#pragma pack (pop)
#endif
