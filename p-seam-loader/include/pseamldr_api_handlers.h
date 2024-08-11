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
 * @file pseamldr_vmm_api_handelrs.h
 * @brief PSEAMLDR VMM API Handelrs
 */
#ifndef __PSEAMLDR_VMM_API_HANDLERS_H_INCLUDED__
#define __PSEAMLDR_VMM_API_HANDLERS_H_INCLUDED__


#include "pseamldr_api_defs.h"

/**
 * @brief Copies the low 2KB (MCHECK info) of P_SYS_INFO_TABLE to the output buffer
 *
 * @param output_buffer_pa PA of output buffer to be filled with SEAM information data
 *
 * @return Success or Error type
 */
api_error_type seamldr_seaminfo(uint64_t output_buffer_pa);

/**
 * @brief Provide information about P-SEAMLDR.
 *
 * @param output_buffer_pa PA of output buffer to be filled with SEAMLDR_INFO data
 *
 * @return Success or Error type
 */
api_error_type seamldr_info(uint64_t output_buffer_pa);


/**
 * @brief Loads or updates a given SEAM module in SEAM range.
 *
 * Returns Success (0) or error code in RAX.
 * In case of error, returns recoverable (0) or unrecoverable (1) status in RDX.
 * This API should be called on all LPs serially – the first invocation in the “update session” blocks further
 * SEAMCALLs to the SEAM module; the last invocation performs the update according to the given SEAMLDR_PARAMS.
 * On load/update success, the new SEAM module becomes executable.
 * On recoverable error (update scenario only), the old SEAM module is restored.
 * Unrecoverable errors make the old SEAM module unusable.
 * After the “update session” was completed (either successfully or unsuccessfully), another update session can start.
 *
 * @param seamldr_params_pa PA of SEAMLDR_PARAMS structure
 *
 * @return Success or Error type
 */
api_error_type seamldr_install(uint64_t seamldr_params_pa);


/**
 * @brief Shutdowns P-SEAMLDR.
 *
 * This API is used to prepare for P-SEAMLDR update by NP-SEAMLDR ACM.
 * It should be called on all LPs serially, such that the last LP on which it’s called is
 * the same LP on which NP-SEAMLDR was launched.
 * The first invocation of the “shutdown session” blocks further SEAMCALLs to the SEAM module;
 * the last invocation also blocks further SEAMCALLs to the P-SEAMLDR itself.
 *
 * @return Success or Error type
 */
api_error_type seamldr_shutdown(void);

/**
 * @brief Cleans up old SEAM module leftovers
 *
 * Clean SEAMEXTEND register (in UMRR)
 * Invalidate Caches (using WBINVD MSR)
 * Scrub all exiting TD private keys (using PCONFIG)
 * Zero the SEAM SVN saved in ESE/S3M (on SoC’s where this is applicable)
 * Essentially returning the system to a fresh start, so any module can be loaded safely as though it’s the first load.
 *
 * @return Success or Error type
 */
api_error_type seamldr_cleanup(void);

#endif // __PSEAMLDR_VMM_API_HANDLERS_H_INCLUDED__
