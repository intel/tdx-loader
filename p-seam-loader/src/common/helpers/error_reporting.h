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
 * @file error_reporting.h
 * @brief Runtime error reporting features for TDX module
 */

#ifndef SRC_COMMON_HELPERS_ERROR_REPORTING_H_
#define SRC_COMMON_HELPERS_ERROR_REPORTING_H_

#include "debug/tdx_debug.h"

void pseamldr_report_error_and_halt(uint32_t source_id, uint32_t code);

//TODO - input parameters may change
void pseamldr_arch_fatal_error(void);

//Architectural Fatal Error Macro.
//TODO - input parameters may change
#define FATAL_ERROR()       {\
                                TDX_ERROR("Architectural fatal error at line: %d , in file %s\n", __LINE__, __FILENAME__);\
                                pseamldr_arch_fatal_error();\
                            }

//Runtime (includes product-build) Assertion
#define pseamldr_sanity_check(cond, source_id, code) if (!(cond)) {\
                                                      TDX_ERROR("Runtime panic at line: %d , in file %s\n", __LINE__, __FILENAME__);\
                                                      pseamldr_report_error_and_halt(source_id, code);\
                                                     }


// SCEC - Sanity Check Error Code
#define SCEC_HELPERS_SOURCE            0xF002
#define SCEC_KEYHOLE_MANAGER_SOURCE    0xF005
#define SCEC_VT_ACCESSORS_SOURCE       0xF006
#define SCEC_VMM_DISPATCHER_SOURCE     0xF008
#define SCEC_CANARY_CORRUPT_SOURCE     0xCF00


#define ERROR_CODE(source_id, code)    (uint64_t)(((uint64_t)(source_id) << 32U) | (uint64_t)(code))

#endif /* SRC_COMMON_HELPERS_ERROR_REPORTING_H_ */
