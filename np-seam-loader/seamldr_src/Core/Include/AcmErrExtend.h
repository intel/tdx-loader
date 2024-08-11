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

#ifndef ACMERREXTEND_H_
#define ACMERREXTEND_H_

//
// BtG escape error codes programmed into MSR_BTG_BOOT_STATUS 0x138
//

typedef enum {
  //
  // main flow codes 0x1 - 0x1F
  //
  ANC_PROGRESS_SUCCESS = 0x0,
  ANC_PROGRESS_INIT_FAIL,
  ANC_PROGRESS_FIT_FAIL,
  ANC_PROGRESS_KM_FAIL,
  ANC_PROGRESS_BPM_FAIL,
  ANC_PROGRESS_DMA_FAIL,
  ANC_PROGRESS_IBB_FAIL,
  ANC_PROGRESS_NEM_FAIL,
  ANC_PROGRESS_TPM_LOCALITY_REQUEST_FAIL,
  ANC_PROGRESS_TPM_STARTUP_FAIL,
  ANC_PROGRESS_MEASURE_FAIL,
  ANC_PROGRESS_ME_FAIL,
  ANC_PROGRESS_FORCED_VBOOT,
  ANC_PROGRESS_IBBL_FAIL,
  ANC_PROGRESS_TPM_LOCALITY_REQUEST_FAIL1,
  ANC_PROGRESS_MAX_VALUE = 0x1F,
} anc_progress_e;

//*****************************************************************************
//*****************************************************************************
//
//                             IMPORTANT!
//
// Classes 0x30 - 0x3F are reserved for extention of already defined
// classes. Do not occupy for other reasons.
//
//*****************************************************************************
//*****************************************************************************

#define ACM_CLASS(C)         CLASS_ ## C
#define ACM_MAJOR_CODE(C, M) ERR_ ## C ## _ ## M

// Useful Macro to wrap around calls to ErrorHandler
// It requires error classes and major codes to conform to naming conventions.
// It prevents mismatching class codes and major codes

#define ERRORHANDLER(C, M, N)       do { \
    ErrCtx.Minor = (N); \
    ErrorHandler(ACM_CLASS(C), ACM_MAJOR_CODE(C, M)); \
} while (0)

#define ERROR_HANDLER_FULL(C, M, N) do { \
    ErrCtx.Minor = (N); \
    ErrorHandler((C), (M)); \
} while (0)

#define BTG_ERROR_HANDLER_FULL(C)   do { \
    ERROR_HANDLER_FULL((C).bits.error_class, (C).bits.error_code, (C).bits.minor_code); \
} while (0)

#endif /* ACMERREXTEND_H_ */
