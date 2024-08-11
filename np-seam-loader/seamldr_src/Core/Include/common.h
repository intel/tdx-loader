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
#define TOSTRING(X)  STRINGIFY(X)

#define PORT80 0x80
#define PORT81 0x81

#define BITN(N) (1 << (N))
//-----------------------------------------------------------------------------
// Misc definitions and helper macros.
//-----------------------------------------------------------------------------

#define TRUE      1
#define FALSE     0
#define NULL      0
#define EQUAL     0
#define NOT_EQUAL 1
#define ZEROS     ((UINT32) 0)
#define ONES      ((UINT32) 0xFFFFFFFF)

#define IN
#define OUT
#define OPTIONAL

#define max(A, B)      (((A) > (B)) ? (A) : (B))
#define min(A, B)      (((A) > (B)) ? (B) : (A))

#define offsetof(T, I) ((UINT32)((UINT8 *)&((T *)0)->I - (UINT8 *)0))
#define lenof(T, I)    sizeof(((T *)0)->I)

#define highdword(R)   (*((UINT32 *)&(R) +1))
#define highword(R)    (*((UINT16 *)&(R) +1))
#define highbyte(R)    (*((UINT8 *)&(R) +1))

#define rounded(R, V)  ((((R) % (V)) == 0) ? (R) : (((R) / (V)) * (V)) + (V))
#define rounded4KB(R)  rounded((R), (_4KB))

#define SWAP_UINT16(x) (((x) >> 8) | ((x) << 8))
#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

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
typedef UINT8 *PBYTE;
typedef char *PSBYTE;
typedef UINT32 *PDWORD;
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

//-----------------------------------------------------------------------------
// Sizes and masks
//-----------------------------------------------------------------------------
#define _4PB        0x0010000000000000
#define _64TB       0x400000000000
#define _256GB      0x4000000000
#define _64GB       0x1000000000
#define _32GB       0x800000000
#define _16GB       0x400000000
#define _8GB        0x200000000
#define _4GB        0x100000000
#define _3GB        0xC0000000
#define _2GB        0x80000000
#define _2016MB     0x7E000000
#define _1_5GB      0x60000000
#define _1GB        0x40000000
#define _512MB      0x20000000
#define _480MB      0x1E000000
#define _448MB      0x1C000000
#define _416MB      0x1A000000
#define _384MB      0x18000000
#define _352MB      0x16000000
#define _320MB      0x14000000
#define _288MB      0x12000000
#define _256MB      0x10000000
#define _224MB      0xE000000
#define _192MB      0xC000000
#define _160MB      0xA000000
#define _128MB      0x8000000
#define _96MB       0x6000000
#define _64MB       0x4000000
#define _60MB       0x3C00000
#define _56MB       0x3800000
#define _52MB       0x3400000
#define _48MB       0x3000000
#define _44MB       0x2C00000
#define _40MB       0x2800000
#define _36MB       0x2400000
#define _32MB       0x2000000
#define _28MB       0x1C00000
#define _24MB       0x1800000
#define _20MB       0X1400000
#define _16MB       0x1000000
#define _15MB       0xF00000
#define _14MB       0xE00000
#define _12MB       0xC00000
#define _8MB        0x800000
#define _4MB        0x400000
#define _3MB        0x300000
#define _2MB        0x200000
#define _1MB        0x100000
#define _512KB      0x80000
#define _256KB      0x40000
#define _384KB      0x60000
#define _192KB      0x30000
#define _172KB      0x2B000
#define _128KB      0x20000
#define _64KB       0x10000
#define _32KB       0x8000
#define _31KB       0x7C00
#define _20KB       0x5000
#define _16KB       0x4000
#define _12KB       0x3000
#define _8KB        0x2000
#define _6KB        0x1800
#define _4KB        0x1000
#define _2KB        0x800
#define _1KB        0x400
#define _64B        0x40
#define _16B        0x10

#define PAGE4K      0x1000
#define PAGE2M      0x200000
#define PAGE4M      0x400000

#define _4GB_MASK   (~(_4GB - 1))
#define _2GB_MASK   (~(_2GB - 1))
#define _1GB_MASK   (~(_1GB - 1))
#define _512MB_MASK (~(_512MB - 1))
#define _256MB_MASK (~(_256MB - 1))
#define _128MB_MASK (~(_128MB - 1))
#define _64MB_MASK  (~(_64MB - 1))
#define _16MB_MASK  (~(_16MB - 1))
#define _8MB_MASK   (~(_8MB - 1))
#define _4MB_MASK   (~(_4MB - 1))
#define _2MB_MASK   (~(_2MB - 1))
#define _1MB_MASK   (~(_1MB - 1))

#define _512KB_MASK (~(_512KB - 1))
#define _256KB_MASK (~(_256KB - 1))
#define _128KB_MASK (~(_128KB - 1))
#define _64KB_MASK  (~(_64KB - 1))
#define _32KB_MASK  (~(_32KB - 1))
#define _16KB_MASK  (~(_16KB - 1))
#define _8KB_MASK   (~(_8KB - 1))
#define _4KB_MASK   (~(_4KB - 1))
#define _1KB_MASK   (~(_1KB - 1))
#define _64B_MASK   (~(_64B - 1))
#define _16B_MASK   (~(_16B - 1))

//-----------------------------------------------------------------------------
// Maximal values fpr types
//-----------------------------------------------------------------------------
#define MAX_QWORD ((UINT64) 0xFFFFFFFFFFFFFFFF)
#define MAX_DWORD ((UINT32) 0xFFFFFFFF)
#define MAX_WORD  ((UINT16) 0xFFFF)
#define MAX_BYTE  ((UINT8) 0xFF)

//-----------------------------------------------------------------------------
// ACM module header "FLAGS" field control bits.
// BIT15 is set to indicate DEBUG signed module.
// BIT14 is set to indicate NPW module. Flags are intended to be ORed
// if needed.
//-----------------------------------------------------------------------------
#define MF_PRODUCTION      0
#define MF_DEBUG           BIT15
#define MF_PROD_WORTHY     0
#define MF_NOT_PROD_WORTHY BIT14

//-----------------------------------------------------------------------------
// LCP element selection. Convinient to keep it here since they are
// used in makeflag.mak file, are propagated to makeflag.h file and
// cause sintax error if LCP.H is not included in file being compiled.
//-----------------------------------------------------------------------------

#define LCP_POLELT_TYPE_MLE              0
#define LCP_POLELT_TYPE_PCONF            1

#define LCP_POLELT_TYPE_CUSTOM           3
#define LCP_POLELT_TYPE_STM              4
#define LCP_ELT_TYPE_MASK                0xF
#define LCP_ELT_TYPE2_MASK               0xF0

#define LCP_POLELT_TYPE_MLE_SUPPORTED    BITN(LCP_POLELT_TYPE_MLE)
#define LCP_POLELT_TYPE_PCONF_SUPPORTED  BITN(LCP_POLELT_TYPE_PCONF)

#define LCP_POLELT_TYPE_CUSTOM_SUPPORTED BITN(LCP_POLELT_TYPE_CUSTOM)
#define LCP_POLELT_TYPE_STM_SUPPORTED    BITN(LCP_POLELT_TYPE_STM)

//-----------------------------------------------------------------------------
// Leaf value (in eax) calling GETSEC
//-----------------------------------------------------------------------------
#define CAPABILITIES 0
#define ENTERACCS    2
#define EXITAC       3
#define SENTER       4
#define SEXIT        5
#define PARAMETERS   6
#define SMCTRL       7
#define WAKEUP       8

//-----------------------------------------------------------------------------
// Max loop count for Param5 search
//-----------------------------------------------------------------------------
#define MAX_PARAM5_COUNT 10 // Sighting #3864941

//-----------------------------------------------------------------------------
// Control registers
//-----------------------------------------------------------------------------
//
// CR0 bits
//
#define CR0_PE BIT0
#define CR0_EM BIT2
#define CR0_TS BIT3
#define CR0_ET BIT4
#define CR0_NE BIT5
#define CR0_WP BIT16
#define CR0_NW BIT29
#define CR0_CD BIT30
#define CR0_PG BIT31

//
// CR4 bits
//
#define CR4_VME        BIT0
#define CR4_PVI        BIT1
#define CR4_TSD        BIT2
#define CR4_DE         BIT3
#define CR4_PSE        BIT4
#define CR4_PAE        BIT5
#define CR4_MSE        BIT6
#define CR4_PGE        BIT7
#define CR4_PCE        BIT8
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

//-----------------------------------------------------------------------------
// CPUID family/model/stepping masks
//-----------------------------------------------------------------------------

#define CPUID_XTENDED_FAMILY (0xFF << 20)
#define CPUID_XTENDED_MODEL  (0xF << 16)
#define CPUID_TYPE           (0x3 << 12)
#define CPUID_FAMILY         (0xF << 8)
#define CPUID_MODEL          (0xF << 4)
#define CPUID_STEPPING       (0xF << 0)
#define CPUID_FMS_MASK       (CPUID_XTENDED_FAMILY + CPUID_XTENDED_MODEL + CPUID_FAMILY + CPUID_MODEL)

//-----------------------------------------------------------------------------
// SHAXXX hash
//-----------------------------------------------------------------------------

#define H_LEN           20
#define H256_LEN        32
#define HASH_ALG_SHA1   0x0
#define HASH_ALG_SHA256 0x1

//-----------------------------------------------------------------------------
// Memory Controller
//-----------------------------------------------------------------------------
#define MC_NOT_PRESENT     0x0
#define MC_1_PRESENT       0x1
#define MC_2_PRESENT       0x2
#define MC_1_AND_2_PRESENT 0x3

//-----------------------------------------------------------------------------
// MSRs. Place only architectural, not CPU specific MSRs here
//-----------------------------------------------------------------------------

#define MSR_IA32_PLATFORM_ID 0x017
#define MSR_IA32_APIC_BASE   0x01B
#define MSR_PLATFORM_INFO    0xCE

#define MSR_ACM_PUBLIC_KEY0  0x20
#define MSR_ACM_PUBLIC_KEY1  0x21
#define MSR_ACM_PUBLIC_KEY2  0x22
#define MSR_ACM_PUBLIC_KEY3  0x23
//
// Local APIC register offsets.
//
#define SPURIOUS_INTERRUPT_VECTOR_REG 0xF0
#define LVT_CMCI_REG                  0x2F0
#define LVT_ICR_LO                    0x300
#define LVT_ICR_HI                    0x310
#define LVT_TIMER_REG                 0x320
#define LVT_THERMAL_MONITOR_REG       0x330
#define LVT_LINT0_REG                 0x350
#define LVT_LINT1_REG                 0x360
#define LVT_ERROR_REG                 0x370

typedef struct _LAPIC_REG_SAVE {
  UINT32 RegIdx;
  UINT32 RegVal;
} LAPIC_REG_SAVE;

#define MSR_CORE_THREAD_COUNT          0x035
#define MSR_IA32_FEATURE_CONTROL       0x03A
#define     FEATURE_CONTROL_LOCK       BIT0
#define     VMXON_IN_SMX_ENABLE        BIT1
#define     VMXON_OUT_SMX_ENABLE       BIT2
#define     SENTER_ENABLE              0xFF00
#define     SGX_ENABLE                 (BIT18 + BIT0)
#define MSR_IA32_BIOS_SIGN_ID          0x08B
#define MSR_IA32_SMM_MONITOR_CTL       0x09B
#define MSR_PKG_CST_CONFIG_CTL         0x0E2
#define MSR_PMG_IO_CAPTURE_BASE        0x0E4
#define MSR_IA32_MTRRCAP               0x0FE
  #define VCNT_MASK                    0xFF

#define MSR_BTG_BOOT_POLICY            0x130
#define MSR_BTG_BP_KEY0                0x131
#define MSR_BTG_BP_KEY1                0x132
#define MSR_BTG_BP_KEY2                0x133
#define MSR_BTG_BP_KEY3                0x134
#define MSR_BTG_BP_KEY4                0x135
#define MSR_BTG_BP_KEY5                0x136
#define MSR_BTG_BP_RSVD3               0x137
#define MSR_BTG_BOOT_STATUS            0x138
#define MSR_BTG_SACM_INFO              0x13A
  #define SPIRAL_DMI_AUTH_SUPPORT      BIT36
  #define CPU_MEMLOCK_DISABLE          BIT35
  #define LT_SX_FUSE                   BIT34
  #define BTG_FUSE                     BIT32
  #define NEM_ENABLED                  BIT0

#define IA32_SGX_SVN_STATUS            0x500

#define SMRR_0                         0
#define SMRR_2                         2

#define MSR_SGX_DEBUG_MODE             0x503
#define MSR_IA32_MISC_ENABLES          0x1A0
#define MSR_IA32_MISC_ENABLES_BOOT_NT4 BIT22
#define MSR_SMRR_PHYBASE               0x1F2
#define MSR_SMRR_PHYMASK               0x1F3
#define MSR_SMRR2_PHYBASE              0x1F6
#define MSR_SMRR2_PHYMASK              0x1F7
#define MSR_IA32_MTRR_PHYSBASE0        0x200
#define MSR_IA32_MTRR_PHYSMASK0        0x201
#define MSR_IA32_MTRR_PHYSBASE1        0x202
#define MSR_IA32_MTRR_PHYSMASK1        0x203
#define MSR_IA32_MTRR_PHYSBASE2        0x204
#define MSR_IA32_MTRR_PHYSMASK2        0x205
#define MSR_IA32_MTRR_PHYSBASE8        0x210
#define MSR_IA32_MTRR_PHYSMASK8        0x211
#define MSR_IA32_MTRR_PHYSBASE9        0x212
#define MSR_IA32_MTRR_PHYSMASK9        0x213
  #define LO_PHYS_BASE_MASK            0xFFFFF000
  #define PHYS_BASE_TYPE_MASK          0xFF
  #define PHYS_MASK_VALID              BIT11
  #define LO_PHYS_MASK_MASK            0xFFFFF000
#define MAX_SUPPORTED_MTRR_COUNT       16

#define MTRR_FIX_64K_00000             0x250
#define MTRR_FIX_16K_80000             0x258
#define MTRR_FIX_16K_A0000             0x259
#define MTRR_FIX_4K_C0000              0x268
#define MTRR_FIX_4K_C8000              0x269
#define MTRR_FIX_4K_D0000              0x26A
#define MTRR_FIX_4K_D8000              0x26B
#define MTRR_FIX_4K_E0000              0x26C
#define MTRR_FIX_4K_E8000              0x26D
#define MTRR_FIX_4K_F0000              0x26E
#define MTRR_FIX_4K_F8000              0x26F

#define BUS_WIDTH_36                   0
#define BUS_WIDTH_ACTUAL               1

#define MSR_PROBE_MODE                 0x6B
    #define PROBE_MODE_OCCURRED        BIT0

#define MSR_NO_EVICT_MODE              0x2E0
#define MSR_NO_EVICT_MODE_RUNSET_BIT   0x3

#define MSR_LTCTRLSTS                  0x2E7
  #define CONFIGLOCK                   BIT0
  #define SCHECK_PASS                  BIT4
  #define CONFIGUNLOC                  BIT16
  #define MEMLOCK_CPU_CLR              BIT17
  #define SCHECK_PASS_CLR              BIT20

#define MSR_EDRAM_ACM                  0x2E8
#define EDRAM_EXISTS                   BIT2
#define EDRAM_IS_DISABLED              BIT1
#define FORCE_EDRAM_DISABLED           BIT0

#define MSR_IA32_MTRR_DEF_TYPE         0x2FF
#define DEF_MEM_TYPE_MASK              0x7
#define DEF_FIX_MTRR_ENABLE            BIT10
#define DEF_VAR_MTRR_ENABLE            BIT11

#define MSR_BUS_NUM                    0x300

#define MSR_IA32_VMX_BASIC             0x480
#define MSR_IA32_VMX_MISC              0x485

#define MSR_UNC_CBO_CONFIG             0x396
//
// PRMRR_BASE location changed to 0x2A0
//
#define MSR_PRMRR_BASE      0x2A0
#define MSR_PRMRR_MASK      0x1F5

#define MSR_BIOS_DONE       0x151

#define MSR_FLEX_RATIO      0x194
#define B_OVERCLOCKING_LOCK BIT20
#define B_OVERCLOCKING_BINS (0x7 << 17)

#define MSR_BIOS_SE_SVN     0x302

#define MSR_MKTME_ACTIVATE  0x982

//   #define SINIT_SE_SVN_MASK      (~0xFF0000)
//   #define BIOSAC_SE_SVN_MASK     (~0xFF000000)
//   #define BTG_SE_SVN_MASK        (~0xFF00000000)
//   #define SINIT_SE_SVN_SHIFT     16
//   #define BIOSAC_SE_SVN_SHIFT    24

//
// SPIRAL related MSRs
//
#define MSR_SPIRAL_UCODE_SVN 0x1130 // Returns the security version number of CPU microcode (Read only)

#define MSR_SPIRAL_CSME_CTRL 0x1131 // Interface to communicate SPIRAL info to CSME
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

// SPIRAL_CSME_DATA_ACCESS
// This is a virtual MSR. Read access map to addresses with LT space that
// ACM can't directly access. Reads come from 0xFED58D40/44, Writes go to 0xFED58D80/84
#define MSR_SPIRAL_CSME_DATA_ACCESS 0x1132
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

// MSRs for accessing Seed Passwords and other Microcode Spiral Data
//
#define MSR_SPIRAL_ACM_ACCESS_INDEX  0x1134 // Used to specify a different QWORD within a SPIRAL array
#define MSR_SPIRAL_SHARED_SECRET_2   0x1135 //
#define MSR_SPIRAL_SEED_ID           0x1136 // Returns the 32-byte Seed ID
#define MSR_SPIRAL_CR_SIGNATURE      0x1137 // Returs signature of CPU root cert
#define MSR_SPIRAL_SEED_PASSWORD_2_1 0x1138 // This MSR returs SP2 (SP_1_p_n_32)
#define MSR_SPIRAL_SEED_PASSWORD_2_2 0x1139 // This MSR returs SP2 (SP_2_p_n_32)
#define MSR_SPIRAL_SEED_PASSWORD_2_3 0x113A // This MSR returs SP2 (SP_3_p_n_32)
#define MSR_SPIRAL_SEED_PASSWORD_2_4 0x113B // This MSR returs SP2 (SP_4_p_n_32)

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

#define MTRR_MEMORY_TYPE_UC          00
#define MTRR_MEMORY_TYPE_WC          01
#define MTRR_MEMORY_TYPE_WT          04
#define MTRR_MEMORY_TYPE_WP          05
#define MTRR_MEMORY_TYPE_WB          06

#define MTRR_MIN_RANGE               0x1000

#define MSR_DEBUG_INTERFACE          0xC80
#define DEBUG_HAS_OCCURED            BIT31
#define DEBUG_LOCK                   BIT30
#define DEBUG_ENABLE                 BIT0

#define IA32_EFER_MSR                0xC0000080
#define N_IA32_EFER_SCE              BIT0
#define LME                          BIT8
#define N_IA32_EFER_LMA              BIT10
#define N_IA32_EFER_NXE              BIT11

#define TPM_BLOCK_TRANSFER_64B_INDEX 0
#define TPM_BLOCK_TRANSFER_32B_INDEX 1
#define TPM_BLOCK_TRANSFER_8B_INDEX  2
#define TPM_BLOCK_TRANSFER_4B_INDEX  3

#define CPY_BLOCK_TRANSFER_64B_INDEX 0
#define CPY_BLOCK_TRANSFER_32B_INDEX 1
#define CPY_BLOCK_TRANSFER_16B_INDEX 2
#define CPY_BLOCK_TRANSFER_8B_INDEX  3
#define CPY_BLOCK_TRANSFER_4B_INDEX  4
//-----------------------------------------------------------------------------
// TXT register space
//-----------------------------------------------------------------------------

#define LT_PUB_BASE 0xFED30000
#define LT_PRV_BASE 0xFED20000

#define FILL64(H, L)  ((((H)-(L)) / 8) - 1)
#define FILL8(H, L)   (((H)-(L)) - 1)

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

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

//
// SPAD measurement indications (values are assumed shifted to bits [1:0].
// Bits 63:62 = 10b - success
// Bits 63:62 = 01b - authentication failure
//
#define SPAD_STATUS_OFFSET 62
#define SPAD_AUTH_SUCCESS  2
#define SPAD_AUTH_FAILURE  1

// LT_SCRATCHPAD_4 bits used for Server ACM TXT signalling.
#define SCRATCHPAD_4_LOCK_LOW BIT31

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

//-----------------------------------------------------------------------------
// LTSX / Client TXT origin
//-----------------------------------------------------------------------------
#define LTSX_FUSED       BIT0
#define CLIENT_TXT_FUSED 0

//-----------------------------------------------------------------------------
// Save state map.
//-----------------------------------------------------------------------------
#define SMM_REV_ID_0 0x0030100
#define SMM_REV_ID_1 0x0030101
#define IEDBASE_DEF  0x0050000

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
#define CRASH_CODE_CPU_AUTH_ERR CRASH_CODE_VALID + CPU_AUTH_ERR

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

//
// Behavior of TPM access functions when error is detected
//
#define RESET_ON_ERROR    0
#define NO_RESET_ON_ERROR 1

//
// Trampoline code related
//
#define GENERIC_CALL    0
#define TRAMPOLINE_CALL 1

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

#define RFA_EXCLUSIVE_MIN BIT0  // Maximum defined exclusive attribute
#define RFA_DPR           BIT0  // DPR
#define RFA_UMA           BIT1  // UMA
#define RFA_PCI_LO        BIT2  // Low PCI range
#define RFA_PCI_HI        BIT3  // High PCI range
#define RFA_USED_DRAM_LO  BIT4  // Low used DRAM
#define RFA_USED_DRAM_HI  BIT5  // High used DRAM
#define RFA_TSEG          BIT6  // TSEG
#define RFA_GFX_UMA       BIT7  // PMR
#define RFA_FLASH         BIT8  // FLASH
#define RFA_EXCLUSIVE_MAX BIT8  // Maximum defined exclusive attribute

#define RFA_INCLUSIVE_MIN BIT9  // Maximum defined exclusive attribute
#define RFA_PCI_ANY       BIT9  // Hight or Low PCI range
#define RFA_USED_DRAM_ANY BIT10 // High or Low used DRAM
#define RFA_DMA_ANY       BIT11 // DPR or PMR
#define RFA_INCLUSIVE_MAX BIT11 // Maximum defined exclusive attribute

#define RFA_VALID         BIT15 // Range is valid flag.

//
// Common labels.
//
// Some of the ranges will never be handled separately - only as a
// group. LBL_PCI_NON_SPECIFIC label is used to mark such ranges
//
#define LBL_ACM              BIT0
#define LBL_PCI_NON_SPECIFIC BIT1
#define LBL_GEN_NON_SPECIFIC BIT2
#define LBL_MCHBAR_REG       BIT3

#define LBL_HEAP             BIT5
#define LBL_ME               BIT6
#define LBL_TSEG             BIT7
#define LBL_SINIT            BIT8
#define LBL_LAPIC            BIT9
#define LBL_ISA_HOLE         BIT10
#define LBL_LEGACY           BIT11

#define LBL_TOUUD            BIT12
#define LBL_LO_PCI           BIT13
#define LBL_DPR              BIT14
#define LBL_LO_DRAM          BIT15
#define LBL_HI_DRAM          BIT16
#define LBL_UMA              BIT17

#define LBL_SMRR             BIT18
#define LBL_PMRL             BIT19
#define LBL_PMRH             BIT20
#define LBL_PMRL_RQU         BIT21
#define LBL_PMRH_RQU         BIT22

#define LBL_DMAR             BIT23
#define LBL_RMRR             BIT24
#define LBL_RMRR_GFX         BIT25

#define LBL_LCP_PO           BIT26
#define LBL_HI_PCI           BIT27
#define LBL_FLASH            BIT28
#define LBL_REMAP            BIT29
#define LBL_GTT              BIT30
#define LBL_GM               BIT31
#define LBL_DMAR_BAR0        BIT32
#define LBL_DMAR_BAR1        BIT33
#define LBL_DMAR_BARX        BIT34
#define LBL_PQA              BIT35

#define LBL_4GBMEM           BIT36
#define LBL_ELOG             BIT37
#define LBL_MADT             BIT38
#define LBL_MSI              BIT39
#define LBL_PAVPC            BIT40
#define LBL_UMAGFX           BIT41
#define LBL_CRAB             BIT42 // base=0xFEB0_0000, size=64KB
#define LBL_SMRR2            BIT43
#define LBL_HEAP_OS2MLE      BIT44
#define LBL_HPET             BIT45
#define LBL_GTMEM            BIT46

#define LBL_SGX              BIT47
#define LBL_MCFG             BIT48
#define LBL_IMR              BIT49 // IMR
#define LBL_IA_EXC           BIT50 // Exclusion range IMR
#define LBL_GT_EXC           BIT51 // Exclusion range IMR
#define LBL_TBT              BIT52 // TB- Thunderbolt VTD

#define LBL_FIT_OBJ          BIT53
#define LBL_DTPR             BIT54
#define LBL_TPR              BIT55
#define LBL_TPR_RQU          BIT56
#define LBL_CEDT             BIT57
#define LBL_IBB_SEG          BIT58

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
#define OVERLAPS      BIT7

#define TANGENT       (TANGENT_ABOVE + TANGENT_BELOW)
#define DISJOINT      (ABOVE + BELOW)
#define SEPARATE      (TANGENT + DISJOINT)
#define COVERS        (ENCLOSES + CONGRUENT)
#define INCLUDED      (CONTAINED + CONGRUENT)

#define ALL           -1 // all items
#define ANY           -1 // any value
#define TBD           0  // Parameter to be calculated

//-----------------------------------------------------------------------------
// Parameters passed to page retrieval function to indicate first
// call or subsequent call.
//-----------------------------------------------------------------------------

#define FIRST_PAGE     0
#define NEXT_PAGE      1

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

#define Sort_Range_Up(Array, Count) Sort(Array, Count, sizeof(RANGE), offsetof(RANGE, base), _UP, 8, Compare)
#define Sort_Range_Dn(Array, Count) Sort(Array, Count, sizeof(RANGE), offsetof(RANGE, base), _DN, 8, Compare)
#define Sort_Mtrr_Up(Array, Count)  Sort(Array, Count, sizeof(MTRR), offsetof(MTRR, base), _UP, 8, Compare)
#define Sort_Mtrr_Dn(Array, Count)  Sort(Array, Count, sizeof(MTRR), offsetof(MTRR, base), _DN, 8, Compare)

UINT32 compareHashX(UINT8 *, UINT8 *, UINT16);
UINT32 compareData(UINT8 *, UINT8 *, UINT32);
UINT32 isZeroHashX(UINT8 *, UINT16);
void Movdir64B(const void *, void *);
void SinitThunk64();
void BiosacThunk64();
void SeamldrThunk64();
void CoreBuildPml5Tables(UINT32);
void CoreBuildPml4Tables(UINT32);
void CoreBuildPml4TablesShort(UINT32);
void CoreBuildPseTables(UINT32);
void EnablePaging();
void CoreAcmErrorHandler(UINT32, UINT32);
void ProgressMark(UINT8);
void LtReset();
void __ErrorHandler(UINT32, UINT32);
void cpyAndZap(UINT8 *, UINT32, UINT8 *, UINT32);
void ChipsetCpuPresenceTest();
void __readMsr(UINT32, UINT32 *, UINT32 *);
UINT64 __readMsr64(UINT32);
UINT64 ReadMsr64WithInput(UINT32 msr_addr, UINT32 edx_in, UINT32 eax_in);
void __writeMsr(UINT32, UINT32, UINT32);
void __writeMsr64(UINT32, UINT64);
void _ud2(void);
UINT64 readTsc64();
void CheckMTRR(UINT32);
void CheckLtCpu();
void VerifyMicrocode();
void SinitExitPoint();
void BiosacExitPoint();
void StartupExitPoint();
void SinitLtsxExitPoint();
void SinitRtcCheck();
void ProbeMchBar(UINT64);
void ServerProbeBar(UINT64);
void SinitGetGTData(void);
UINT16 GetDigestSize(UINT16);
void __Wait10us();
void ShutdownS5();
UINT32 HashAlgIdToIdx(UINT16);
void SetTxtFail();
void SetTxtDisabled();
void SendEnfNotification();
void AcmUnhandledErrorExit();
void ForceTopSwap();
UINT8 SecretsProtectionSupported();
void ForceClearSecrets();
UINT32 get_esp(void);

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

UINT64 GetRangeAlignmentMask(UINT64);

UINT64 shiftLeft64(UINT64, UINT32);

UINT32 rangeCheck(RANGE *);

UINT32 arrayCheck(RANGE *[], UINT32, UINT64);
UINT32 basicArrayCheck(UINT64);
UINT32 verifyRangesSeparate(RANGE *, UINT32, UINT64);
void FillSmrrRange(UINT32);

UINT32 compareTwoRanges(RANGE *, RANGE *);
UINT32 compareAddressToRange(UINT64, RANGE *);
UINT32 BitScanForward64(UINT32 *, UINT64);
UINT32 BitScanReverse64(UINT32 *, UINT64);
UINT32 BitScanForward64AndReset(UINT32 *, UINT64 *);
UINT32 BitScanReverse64AndReset(UINT32 *, UINT64 *);
UINT32 BitScanForwardAndReset(UINT32 *, UINT32 *);
UINT32 BitScanReverseAndReset(UINT32 *, UINT32 *);
void SetupCpuFeatures();
void RestoreCpuFeatures();
UINT32 GetSgxFusingInfo();
void SgxProtection();
void Update_CRx();
void InitializeHeaderData();
void DualSignedHeaderCheck();
void x86_copy8b(UINT8 *, UINT8 *);
void x86_copy16b(UINT8 *, UINT8 *);
void x86_copy32b(UINT8 *, UINT8 *);
void x86_copy64b(UINT8 *, UINT8 *);

typedef UINT32 (*GET_DATA)                (UINT32, UINT32 *, UINT32 *);
//void    getPcrValue                       (UINT32, UINT8 *);
UINT32 GetSmBase();
UINT32 strLen(char *);

void SaveLapicRegisters(UINT32);
void RestoreLapicRegisters(UINT32);
UINT32 GetMaxPhyAddr();
UINT64 GetPhyAddrMask();
UINT32 GetCpuFms();
UINT32 Swap(void *, UINT32);

void SaveUnlockLtLock();
void RestoreRelockLtLock();
void AuxRevocationCheck();
void AuxDetection();
UINT32 IsFlashAcm();
BOOL TxtBiosVerification();

void DoNothing();
void SignalSinitScheckWasRun();
void VerifySinitScheckWasRun();
void ServerSignalSinitScheckWasRun();
void ServerVerifySinitScheckWasRun();
void ClientHandleTopSwap();
void ServerHandleTopSwap();

void RestoreRelockBiosDoneLock();
void SaveUnlockBiosDoneLock();
void SinitBtgBootPolChk();
void executeGetSec(UINT32, UINT32);
void CheckSeSvn();
INT32 perform_ebp_checks(UINT32 dest, UINT32 size);
INT32 perform_ebp_checks64(UINT64 dest, UINT32 size);
UINT32 isPatternHashX(UINT8 *, UINT32, UINT16);

UINT32 isRangeSeparate(
  RANGE *,
  RANGE *[],
  UINT32,
  UINT64
  );

void ReadVtgCfgBars();
void coreTpm20Shutdown(UINT16);
UINT32 GetDate();
UINT32 validateRangePlacement(RANGE *);
UINT32 InitSio();
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

void EndBenchmark();
void CmosSave(void *, UINT32, UINT32);
UINT32 getsecParameters(UINT32, UINT32 *, UINT32 *, UINT32 *, UINT32);
void LongJump(void *);
UINT32 RdrandProc();
void GetRandomDwords(UINT32 *buf, UINT32 num_dwords);

UINT32 GetStrongestHashAlgId(UINT32 HashAlgMask);

void WaitFixedTime(UINT32);
#define Wait100ms() WaitFixedTime(100)
#define Wait1s()    WaitFixedTime(1000)

UINT32 TinyWaitRegisterValue(UINT32, UINT32, UINT32, UINT32, UINT32, UINT32);
#define In10USEC 0
#define In1MSEC  1

UINT32 BaseWaitMsrValue(UINT32, UINT64, UINT32, UINT64, UINT32, UINT32);
#define WaitMsrValue(A, B, C, D, E)     BaseWaitMsrValue(A, B, C, D, E, In1MSEC)
#define TinyWaitMsrValue(A, B, C, D, E) BaseWaitMsrValue(A, B, C, D, E, In10USEC)

UINT32 __WaitRegisterBitSet(UINT32, UINT32);
UINT32 __WaitRegisterBitClear(UINT32, UINT32);
UINT32 SafeAdd(UINT32, void *, void *, void *);

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
#define R_ELOG_SHA1 R_ELOG
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

#define NORETRUN __declspec(noreturn)
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
