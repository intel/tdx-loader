; Copyright (C) 2023 Intel Corporation                                          
;                                                                               
; Permission is hereby granted, free of charge, to any person obtaining a copy  
; of this software and associated documentation files (the "Software"),         
; to deal in the Software without restriction, including without limitation     
; the rights to use, copy, modify, merge, publish, distribute, sublicense,      
; and/or sell copies of the Software, and to permit persons to whom             
; the Software is furnished to do so, subject to the following conditions:      
;                                                                               
; The above copyright notice and this permission notice shall be included       
; in all copies or substantial portions of the Software.                        
;                                                                               
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS       
; OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL      
; THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES             
; OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
; ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE            
; OR OTHER DEALINGS IN THE SOFTWARE.                                            
;                                                                               
; SPDX-License-Identifier: MIT

%ifndef SEAMLDRCOM_EQU
%define SEAMLDRCOM_EQU 0

;COM64_DATA STRUCTURE

struc SEAMLDR_COM64_DATA

.OriginalR8:                  resq   1
.OriginalR9:	              resq   1
.OriginalR10:                 resq   1
.OriginalR11:                 resq   1
.OriginalR12:                 resq   1
.OriginalCR3:                 resq   1
.OriginalCR4:                 resd   1
.OriginalES:                  resw   1
.OriginalFS:                  resw   1
.OriginalGS:                  resw   1
.OriginalSS:                  resw   1
.OriginalECX                  resd   1
.OriginalIDTRLimit:           resw   1
.NewIDTR:               	  resb   10
.OriginalGdtr:                resb   10
.ResumeRip:               	  resq   1
.PtCtxPtr:                    resq   1
.RetVal:                      resq   1
.HeaderStart:                 resq   1
.PseamldrSize:                resd   1
.PseamldrOffset:              resq   1
.PseamldrConstsOffset:     	  resq   1
.NewGdtr:     				  resb   10
endstruc


%endif ;SEAMLDRCOM_EQU