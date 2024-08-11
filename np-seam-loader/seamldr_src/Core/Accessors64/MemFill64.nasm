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

;---------------------------------------------------------------------------

%include "AcmCom_NASM.inc"


segment .data  align=16

segment .text  align=16

;-----------------------------------------------------------------------------
;-----------------------------------------------------------------------------
;  Procedure:	Movdir64B
; 
;  Input:	Source
;           Destination
; 
;  Output:	None
; 
;  Description:  Wrapper for a MOVDIR64B instruction
; 
;-----------------------------------------------------------------------------
;-----------------------------------------------------------------------------
global Movdir64B
Movdir64B :
    push       rdi
    push       rsi
    
    mov        rdi, rcx
    mov        rsi, rdx
;/*movdir64b op*/
    DB 066h
    DB 0Fh
    DB 038h
    DB 0F8h
;/*ModRM = RDI->RSI*/
    DB 037h
    
    pop        rsi
    pop        rdi
    
    ret


        

 