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

#include "common.h"
#include "paging.h"
#include "Header.h"
#include "msr.h"

void __ud2(void);
#pragma intrinsic(__ud2)

static void Map4KPage(IA32E_PXE_T* LeafPXE, UINT64 PhysBase, PAGE_ACCESS_TYPE IsWritable, PAGE_CACHING_TYPE IsWBMemtype)
{
    if (LeafPXE->Raw != 0) {
        TXT_SHUTDOWN();
    }

    LeafPXE->Raw = PhysBase;
    LeafPXE->Fields4K.P = 1;
    LeafPXE->Fields4K.RW = (IsWritable == PAGE_WRITABLE) ? 1 : 0;
    LeafPXE->Fields4K.A = 1;
    LeafPXE->Fields4K.D = 1;

    if (IsWBMemtype == PAGE_WB_MEMTYPE) {
        // PAT0 is supposed to be WB memtype
        LeafPXE->Fields4K.PAT = 0;
        LeafPXE->Fields4K.PWT = 0;
        LeafPXE->Fields4K.PCD = 0;
    }
    else {
        // PAT7 is supposed to be UC memtype
        LeafPXE->Fields4K.PAT = 1;
        LeafPXE->Fields4K.PWT = 1;
        LeafPXE->Fields4K.PCD = 1;
    }
}

static void Map2MBPage(IA32E_PXE_T* LeafPXE, UINT64 PhysBase, PAGE_ACCESS_TYPE IsWritable, PAGE_CACHING_TYPE IsWBMemtype)
{
    if (LeafPXE->Raw != 0) {
        TXT_SHUTDOWN();
    }

    LeafPXE->Raw = PhysBase;
    LeafPXE->Fields2M.P = 1;
    LeafPXE->Fields2M.RW = (IsWritable == PAGE_WRITABLE) ? 1 : 0;
    LeafPXE->Fields2M.A = 1;
    LeafPXE->Fields2M.D = 1;
    LeafPXE->Fields2M.Leaf = 1;

    if (IsWBMemtype == PAGE_WB_MEMTYPE) {
        // PAT0 is supposed to be WB memtype
        LeafPXE->Fields2M.PAT = 0;
        LeafPXE->Fields2M.PWT = 0;
        LeafPXE->Fields2M.PCD = 0;
    }
    else {
        // PAT7 is supposed to be UC memtype
        LeafPXE->Fields2M.PAT = 1;
        LeafPXE->Fields2M.PWT = 1;
        LeafPXE->Fields2M.PCD = 1;
    }
}

UINT64 MapPhysicalRange(PT_CTX *pctx, UINT64 Addr, UINT64 size, PAGE_ACCESS_TYPE IsWritable, PAGE_SIZE PageMappingSize, PAGE_CACHING_TYPE IsWBMemtype)
{
    UINT32 i = 0;
    UINT32 PagesToMap = 0;
    UINT64 Base = 0;
    UINT64 VirtualAddr = 0;
    UINT64 OffsetInPage = 0;

    if (PageMappingSize == PAGE_2M) {

        Base = Addr & _2MB_MASK;
        OffsetInPage = Addr & (_2MB - 1);
        PagesToMap = (UINT32)(rounded((OffsetInPage + size), _2MB) / _2MB);

        if (pctx->NextFreePdIdx + PagesToMap > 512) {
            COMSERIALOUT("No free 2MB entries left to map the range");
            return BAD_MAPPING;
        }

        IA32E_PAGING_TABLE_T* Pd = (IA32E_PAGING_TABLE_T*)pctx->PdBaseFor2MBMappings;

        VirtualAddr = pctx->VirtualBaseFor2MBMappings + (pctx->NextFreePdIdx * _2MB) + OffsetInPage;

        for (i = 0; i < PagesToMap; i++, pctx->NextFreePdIdx++, Base += _2MB) {
            Map2MBPage(&Pd->PT[pctx->NextFreePdIdx], Base, IsWritable, IsWBMemtype);
        }
    }
    else {

        Base = Addr & _4KB_MASK;
        OffsetInPage = Addr & (_4KB - 1);
        PagesToMap = (UINT32)(rounded((OffsetInPage + size), _4KB) / _4KB);

        if (pctx->NextFreePtIdx + PagesToMap > 512) {
            COMSERIALOUT("No free 4KB entries left to map the range");
            return BAD_MAPPING;
        }

        IA32E_PAGING_TABLE_T* Pt = (IA32E_PAGING_TABLE_T*)pctx->PtBaseFor4KMappings;

        VirtualAddr = pctx->VirtualBaseFor4KMappings + ((UINT64)pctx->NextFreePtIdx * _4KB) + OffsetInPage;

        for (i = 0; i < PagesToMap; i++, pctx->NextFreePtIdx++, Base += _4KB) {
            Map4KPage(&Pt->PT[pctx->NextFreePtIdx], Base, IsWritable, IsWBMemtype);
        }
    }

    return VirtualAddr;
}

void RemoveLinearMapping(PT_CTX *pctx, UINT64 LinearAddr, BOOL LargePageMapping)
{
    IA32E_PAGING_TABLE_T* Pt;
    UINT64 idx;

    if (LargePageMapping) {
        Pt = (IA32E_PAGING_TABLE_T*)pctx->PdBaseFor2MBMappings;
        idx = (LinearAddr >> 21) & 0x1FF;
    }
    else {
        Pt = (IA32E_PAGING_TABLE_T*)pctx->PtBaseFor4KMappings;
        idx = (LinearAddr >> 12) & 0x1FF;
    }

    Pt->PT[idx].Raw = 0;

    __invlpg((void*)LinearAddr);
}

