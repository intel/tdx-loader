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

#pragma once

#include <Common64.h>

#define IA32_PG_P      1u
#define IA32_PG_RW     (1u << 1)
#define IA32_PG_U      (1u << 2)
#define IA32_PG_WT     (1u << 3)
#define IA32_PG_CD     (1u << 4)
#define IA32_PG_A      (1u << 5)
#define IA32_PG_D      (1u << 6)
#define IA32_PG_PS     (1u << 7)
#define IA32_PG_G      (1u << 8)
#define IA32_PG_PAT_2M (1u << 12)
#define IA32_PG_PAT_4K IA32_PG_PS
#define IA32_PG_NX     (1ull << 63)

typedef union IA32E_PXE_U {
  struct {
    UINT32
      P        : 1,  // 0
      RW       : 1,  // 1
      US       : 1,  // 2
      PWT      : 1,  // 3
      PCD      : 1,  // 4
      A        : 1,  // 5
      D        : 1,  // 6
      Leaf     : 1,  // 7
      G        : 1,  // 8
      Ignore_0 : 3,  // 9-11
      Addr1    : 20; // 12-31
    UINT32 Addr2;
  } FieldsPS;
  struct {
    UINT32
      P        : 1,  // 0
      RW       : 1,  // 1
      US       : 1,  // 2
      PWT      : 1,  // 3
      PCD      : 1,  // 4
      A        : 1,  // 5
      D        : 1,  // 6
      Leaf     : 1,  // 7
      G        : 1,  // 8
      Ignore_0 : 3,  // 9-11
      PAT      : 1,  // 12
      RSVD     : 8,  // 13-20
      Addr1    : 11; // 21-31
    UINT32 Addr2;
  } Fields2M;
  struct {
    UINT32
      P        : 1,  // 0
      RW       : 1,  // 1
      US       : 1,  // 2
      PWT      : 1,  // 3
      PCD      : 1,  // 4
      A        : 1,  // 5
      D        : 1,  // 6
      PAT      : 1,  // 7
      G        : 1,  // 8
      Ignore_0 : 3,  // 9-11
      Addr1    : 20; // 12-31
    UINT32 Addr2;
  } Fields4K;
  UINT64 Raw;
} IA32E_PXE_T;

typedef struct {
  IA32E_PXE_T PT[512];
} IA32E_PAGING_TABLE_T;

// ;---------------------------------------------------------------------------- -
// ; Input tables are sorted like that from the base :
// ; 0x0 - PML5 base - entry at index 0 points to PML4 base
// ; 0x1000 - PML4 base - entry at index 0 points to PDPT base
// ; 0x2000 - PDPT base - entries at indeces 0 - 3 point to the 4 PD tables - which can cover the whole low 4 GB space
// ; 0x3000 - PD table 0
// ; 0x4000 - PD table 1
// ; 0x5000 - PD table 2
// ; 0x6000 - PD table 3
// ; 0x7000 - PT table 0 - used for 1 to 1 mapping of the ACM
// ; 0x8000 - PT table 1 - used for 1 to 1 mapping of the ACM
// ; 0x9000 - PT table 2 - used for all other 4K mappings in the system. (not necessary 1 to 1)
// ;---------------------------------------------------------------------------- -
typedef struct {
  IA32E_PAGING_TABLE_T Pml5;
  IA32E_PAGING_TABLE_T Pml4;
  IA32E_PAGING_TABLE_T Pdpt;
  IA32E_PAGING_TABLE_T Pd[4];
  IA32E_PAGING_TABLE_T Pt[3];
} SEAMLDR_PAGING_TABLE_T;

extern SEAMLDR_PAGING_TABLE_T SeamldrPagingTable;

typedef struct PT_CTX_s {
  UINT64 PtBaseFor4KMappings;
  UINT64 PdBaseFor2MBMappings;
  UINT64 VirtualBaseFor4KMappings;
  UINT64 VirtualBaseFor2MBMappings;
  UINT32 NextFreePtIdx;
  UINT32 NextFreePdIdx;
} PT_CTX;

typedef struct {
  UINT64 PtBaseAddrLa;
  UINT64 PtBaseAddrPa;
  UINT64 PtAllocatorPa;
  UINT64 NumPageLevels;
  INT64  VPDelta;
  UINT64 PagingStructSize;
} SEAMRR_PT_CTX;

#define BAD_MAPPING (~(0x0ULL))

typedef enum {
  PAGE_READ_ONLY,
  PAGE_WRITABLE
} PAGE_ACCESS_TYPE;

typedef enum {
  PAGE_4K,
  PAGE_2M
} PAGE_SIZE;

typedef enum {
  PAGE_UC_MEMTYPE,
  PAGE_WB_MEMTYPE
} PAGE_CACHING_TYPE;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:	MapPhysicalRange
//
//  Input:	pctx - pointer to context.
//          Addr - Physical address to map
//          Size - size to map memory windows.
//          IsWritable - If writable pamming if required
//          LargePageMapping - If 2MB pages should be used for mapping
//          IsWBMemtype - If WB or US memtype should be used for mapping
//
//
//  Output:	Virtual address for the start of the requested physical range.
//
//  Description:	Maps a phyisical address to an available virtual address.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT64 MapPhysicalRange(PT_CTX *pctx, UINT64 Addr, UINT64 size, PAGE_ACCESS_TYPE IsWritable, PAGE_SIZE PageMappingSize, PAGE_CACHING_TYPE IsWBMemtype);

void RemoveLinearMapping(PT_CTX *pctx, UINT64 LinearAddr, BOOL LargePageMapping);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:	MapPage
//
//  Input:	pctx - pointer to context.
//          LinearAddr - Linear address to map
//          PhysAddr - Physical Address to map
//          Attr - required page attribute
//          PageMappingSize - size of page to map - 2mb/4kb
//
//  Output:	PT used for mapping, NULL if out of memory
//
//  Description:	Initializes the context.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT64 *MapPage(SEAMRR_PT_CTX *SeamrrPtCtx, UINT64 LinearAddr, UINT64 PhysAddr, UINT64 Attr, PAGE_SIZE PageMappingSize, BOOL IsKeyHoleMapping);
SEAMRR_PT_CTX *InitPseamldrPtCtx(OUT SEAMRR_PT_CTX *SeamrrPtCtx, UINT64 SeamRrVa, UINT64 SeamRrBase, UINT64 SeamRrSize, UINT64 PSeamldrRangeBase, UINT64 PagingStructSize);
PT_CTX *EstablishSeamldrPaging(SEAMLDR_COM64_DATA *pCom64, IN OUT PT_CTX *PtCtx);
