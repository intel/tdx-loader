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
/**
 * @file seamldr_memory_map.c
 * @brief
 */

#include "pseamldr_api_handlers.h"
#include "x86_defs/x86_defs.h"
#include "memory_handlers/keyhole_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"
#include "accessors/ia32_accessors.h"
#include "seam_sigstruct.h"
#include "x86_defs/msr_defs.h"
#include "seam_memory_map.h"
#include "../../../include/pseamldr_basic_defs.h"

#define PAGING_LEVEL_PDE               1

static uint64_t map_seam_range_page(memory_constants_t* mem_consts, uint64_t pa, uint64_t la, uint64_t attributes,
                                    bool_t keyhole_range)
{
    uint64_t pt_idx;
    ia32e_pxe_t* pxe_ptr;
    uint64_t pxe_pa;

    uint64_t seamrr_linear_delta = get_psysinfo_table()->module_region_base - get_pseamldr_data()->system_info.seamrr_base;

    pxe_pa = mem_consts->pml4_physbase;

    // walk and fill if needed non leaf levels
    for (uint64_t i = SEAM_MODULE_PAGE_LEVEL - 1; i > 0; i--)
    {
        pxe_ptr = (ia32e_pxe_t*)(pxe_pa + seamrr_linear_delta);
        pt_idx = (la >> (i * 9 + 12)) & 0x1FF;
        // check if PT exists
        if (pxe_ptr[pt_idx].raw == 0)
        {
            // if the allocator got to the data region - we are out of memory
            // SEAM range physical map: (bigger address at the bottom)
            // ==========================
            // SEAMRR_BASE
            // SEAM VMCS area
            // Data region (address grows up)
            // SEAM page table region end (last page table available) and Data region end
            // SEAM page table region start - current_pt_physbase (address grows down)
            // SEAM PML4 page table
            // Stack region
            uint64_t data_region_end = mem_consts->data_region_physbase + mem_consts->data_region_size;
            if (mem_consts->current_pt_physbase < data_region_end)
            {
                return NULL_PA;
            }
            pxe_ptr[pt_idx].raw = mem_consts->current_pt_physbase;

            if (keyhole_range && (i == PAGING_LEVEL_PDE))
            {
                pxe_ptr[pt_idx].raw |= SEAM_KEYHOLE_PDE_ATTRIBUTES;
            }
            else
            {
                pxe_ptr[pt_idx].raw |= SEAM_NON_LEAF_PXE_ATTRIBUTES;
            }

            mem_consts->current_pt_physbase -= PAGE_SIZE_IN_BYTES;
        }

        pxe_pa = (uint64_t)(pxe_ptr[pt_idx].fields_4k.addr) << IA32E_4K_PAGE_OFFSET;
    }
    // map leaf level
    pt_idx = ((pa_t)la).fields_4k.pt_index;

    pxe_ptr = (ia32e_pxe_t*)(pxe_pa + seamrr_linear_delta);
    pxe_ptr[pt_idx].raw = pa | attributes;

    return pxe_pa;
}

static bool_t map_regular_range(memory_constants_t* mem_consts, uint64_t range_pa, uint64_t range_la,
                                uint64_t size_in_bytes, uint64_t attributes)
{
    for (uint64_t i = 0; i < size_in_bytes / PAGE_SIZE_IN_BYTES; i++)
    {
        uint64_t pxe_pa = map_seam_range_page(mem_consts, range_pa, range_la, attributes, false);
        IF_RARE (pxe_pa == NULL_PA)
        {
            return false;
        }
        range_pa += PAGE_SIZE_IN_BYTES;
        range_la += PAGE_SIZE_IN_BYTES;
    }

    return true;
}

static bool_t map_keyhole_range(memory_constants_t* mem_consts)
{
    uint64_t keyhole_rgn_la = mem_consts->keyhole_region_linbase;
    uint64_t keyedit_rgn_la = mem_consts->keyedit_region_linbase;

    uint64_t prev_mapped_pt_pa = NULL_PA;
    uint64_t curr_mapped_pt_pa = NULL_PA;

    for (uint32_t i = 0; i < mem_consts->keyhole_region_size / PAGE_SIZE_IN_BYTES; i++)
    {
        curr_mapped_pt_pa = map_seam_range_page(mem_consts, 0, keyhole_rgn_la, SEAM_KEYHOLE_RANGE_ATTRIBUTES, true);
        if (curr_mapped_pt_pa == NULL_PA)
        {
            return false;
        }

        if (curr_mapped_pt_pa != prev_mapped_pt_pa)
        {
            if (keyedit_rgn_la >= mem_consts->keyedit_region_linbase + mem_consts->keyedit_region_size)
            {
                TDX_ERROR("Not enough space in keyhole edit region\n");
                return false;
            }

            if (map_seam_range_page(mem_consts, curr_mapped_pt_pa, keyedit_rgn_la,
                                    SEAM_KEYHOLE_EDIT_RANGE_ATRIBUTES, false) == NULL_PA)
            {
                return false;
            }

            prev_mapped_pt_pa = curr_mapped_pt_pa;
            keyedit_rgn_la += PAGE_SIZE_IN_BYTES;
        }

        keyhole_rgn_la += PAGE_SIZE_IN_BYTES;
    }

    return true;
}

api_error_type seam_module_memory_map(pseamldr_data_t* pseamldr_data, memory_constants_t* mem_consts)
{
    mem_consts->pml4_physbase = mem_consts->stack_region_physbase - _4KB;
    mem_consts->current_pt_physbase = mem_consts->pml4_physbase - _4KB;

    // Map code range
    if (!map_regular_range(mem_consts, mem_consts->code_region_physbase, mem_consts->code_region_linbase,
                           mem_consts->code_region_size, SEAM_CODE_RANGE_ATTRIBUTES))
    {
        TDX_ERROR("Code range mapping failure\n");
        return PSEAMLDR_ENOMEM;
    }

    // Map data range
    if (!map_regular_range(mem_consts, mem_consts->data_region_physbase, mem_consts->data_region_linbase,
                           mem_consts->data_region_size, SEAM_DATA_RANGE_ATTRIBUTES))
    {
        TDX_ERROR("Data range mapping failure\n");
        return PSEAMLDR_ENOMEM;
    }

    // Data and shadow stack ranges per LP
    for (uint32_t i = 0; i < mem_consts->num_addressable_lps; i++)
    {
        uint64_t stack_pa_start = mem_consts->stack_region_physbase + i * mem_consts->lp_stack_size;
        uint64_t stack_la_start = mem_consts->stack_region_linbase + i * mem_consts->lp_stack_size;

        if (!map_regular_range(mem_consts, stack_pa_start, stack_la_start,
                               mem_consts->data_stack_size, SEAM_DATA_STACK_RANGE_ATTRIBUTES))
        {
            TDX_ERROR("Data stack range mapping failure\n");
            return PSEAMLDR_ENOMEM;
        }

        if (!map_regular_range(mem_consts,
                               stack_pa_start + mem_consts->data_stack_size,
                               stack_la_start + mem_consts->data_stack_size,
                               mem_consts->shadow_stack_size, SEAM_SHADOW_STACK_RANGE_ATTRIBUTES))
        {
            TDX_ERROR("Shadow stack range mapping failure\n");
            return PSEAMLDR_ENOMEM;
        }
    }

    // Sysinfo page
    if (!map_regular_range(mem_consts, pseamldr_data->system_info.seamrr_base, mem_consts->sysinfo_table_linbase,
                           _4KB, SEAM_SYSINFO_RANGE_ATTRIBUTES))
    {
        TDX_ERROR("Sysinfo table mapping failure\n");
        return PSEAMLDR_ENOMEM;
    }

    // Keyhole + keyhole edit pages
    if (!map_keyhole_range(mem_consts))
    {
        TDX_ERROR("Keyholes mapping failure\n");
        FATAL_ERROR();
    }

    return PSEAMLDR_SUCCESS;
}
