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
 * @file data_accessors.h
 * @brief Global and local data accessors, and SYSINFO table acessors
 */

#ifndef SRC_COMMON_ACCESSORS_DATA_ACCESSORS_H_
#define SRC_COMMON_ACCESSORS_DATA_ACCESSORS_H_

#include "pseamldr_basic_defs.h"
#include "pseamldr_basic_types.h"
#include "../data_structures/pseamldr_data.h"
#include "../data_structures/pseamldr_data.h"
#include "../data_structures/pseamldr_data_types.h"
#include "../helpers/error_reporting.h"

//****************************************************************************************
// Optimized accessors to SEAM module data structures - always use those in the code
//****************************************************************************************
// Explanation on the syntax below:
// The "i" constraint creates a constant integer immediate input constraint with a symbolic name, "local_data".
// The square brackets are the syntax to reference the immediate.
// And the '%c' syntax is necessary to get the formatting correct for using the constant as a memory operand.
// More info:
// https://gcc.gnu.org/onlinedocs/gcc/Simple-Constraints.html#Simple-Constraints,
// https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html#InputOperands
// https://gcc.gnu.org/onlinedocs/gccint/Output-Template.html#Output-Template.

_STATIC_INLINE_ pseamldr_data_t* get_pseamldr_data(void)
{
    uint64_t data_addr;

    _ASM_ ("movq %%gs:%c[pseamldr_data], %0\n\t"
             :"=r"(data_addr)
             :[pseamldr_data]"i"(offsetof(pseamldr_data_t, seamldr_data_fast_ref_ptr)));

    return (pseamldr_data_t*)data_addr;
}

_STATIC_INLINE_ p_sysinfo_table_t* get_psysinfo_table(void)
{
    uint64_t psysinfo_table_addr;
    _ASM_ ("movq %%gs:%c[psysinfo], %0\n\t"
             :"=r"(psysinfo_table_addr)
             :[psysinfo]"i"(offsetof(pseamldr_data_t, psysinfo_fast_ref_ptr)));

    return (p_sysinfo_table_t*)psysinfo_table_addr;
}

//****************************************************************************************
// Raw non-optimized accessors to SEAM module data structures - should not be used in code
//****************************************************************************************

// In SEAM PSEAMLDR module, GSBASE holds a pointer to the local data of current thread
// We are reading GSBASE by loading effective address of 0 with GS prefix
_STATIC_INLINE_ pseamldr_data_t* calculate_local_data(void)
{
    void* local_data_addr;
    _ASM_VOLATILE_ ("rdgsbase %0"
                     :"=r"(local_data_addr)
                     :
                     :"cc");

    return (pseamldr_data_t*)local_data_addr;
}

// In SEAM PSEAMLDR module, FSBASE holds a pointer to the SYSINFO table
// We are reading FSBASE by loading effective address of 0 with FS prefix
_STATIC_INLINE_ p_sysinfo_table_t* calculate_sysinfo_table(void)
{
    void* sysinfo_table_addr;
    _ASM_VOLATILE_ ("rdfsbase %0"
                     :"=r"(sysinfo_table_addr)
                     :
                     :"cc");

    return (p_sysinfo_table_t*)sysinfo_table_addr;
}

// Must be first thing to do before accessing data or sysinfo table
_STATIC_INLINE_ pseamldr_data_t* init_data_fast_ref_ptrs(void)
{
    pseamldr_data_t* local_data = calculate_local_data();

    IF_RARE (!local_data->seamldr_data_fast_ref_ptr)
    {
        local_data->seamldr_data_fast_ref_ptr = local_data;
        local_data->psysinfo_fast_ref_ptr = calculate_sysinfo_table();
    }

    return local_data;
}

// This function relies on the P-SEAMLDR physical memory layout as defined in NP-SEAMLDR PAS (v0.92, figure 2.1)
// If this layout ever changes in NP-SEAMLDR, then P-SEAMLDR would have to change too.
// This function should be used only with virtual addresses that are located in P-SEAMLDR data region
//
// !!!DO NOT!!! Use VA's of variables on stack!!!
_STATIC_INLINE_ uint64_t translate_module_data_va_to_pa(uint64_t va)
{
    p_sysinfo_table_t* st_p = get_psysinfo_table();

    pseamldr_sanity_check(((va >= st_p->data_rgn_base) && (va < st_p->data_rgn_base + st_p->data_rgn_size)),
                          SCEC_HELPERS_SOURCE, 5);

    // Let offset_in_data_region = v – FS:DATA_REGION_BASE
    uint64_t offset_in_data_region = va - st_p->data_rgn_base;

    // Let data_region_base_pa = (FS:P_SEAMLDR_RR_BASE + FS: P_SEAMLDR_RANGE_SIZE) –
    // (4096 + FS:CODE_REGION_SIZE + FS:STACK_REGION_SIZE + FS:DATA_REGION_SIZE)
    uint64_t data_region_base_pa = (st_p->p_seamldr_range_base + st_p->p_seamldr_range_size) -
            (_4KB + st_p->code_rgn_size + st_p->stack_rgn_size + st_p->data_rgn_size);

    pseamldr_sanity_check(((data_region_base_pa + offset_in_data_region) >= data_region_base_pa),
                          SCEC_HELPERS_SOURCE, 6);

    // Let p = data_region_base_pa + offset_in_data_region; Return p
    return (data_region_base_pa + offset_in_data_region);
}

#endif /* SRC_COMMON_ACCESSORS_DATA_ACCESSORS_H_ */
