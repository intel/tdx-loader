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

%include "AcmCom_NASM.inc"
%include "Entry64_NASM.inc"
%include "SeamldrCom64Data.inc"


global Entry64

segment .data  align=16

segment .text  align=16

               
;-----------------------------------------------------------------------------
;-----------------------------------------------------------------------------
;  Procedure:	Entry64
;
;  Input:	None
;
;  Output:	None
;
;  Description:	Entry procedure of 64-bit code.
;
;-----------------------------------------------------------------------------
;-----------------------------------------------------------------------------
Entry64:
        %push Entry64
        %stacksize flat64           ; tell NASM to use rbp
        %assign %$localsize  0
        %local pCom64data:QWORD

        %assign %$elements 0
        %rep 4
        %local %[pIdt64_%{$elements}]:QWORD
        %assign %$elements %$elements + 1
        %endrep

        enter   %$localsize,0
        ;
        ; Save entry parameter
        ;
        mov  [pCom64data],rcx
        
        mov     rcx, [pCom64data]
        ; backup registers
        mov     [rcx + SEAMLDR_COM64_DATA.OriginalR8], r8
        mov     [rcx + SEAMLDR_COM64_DATA.OriginalR9], r9
        mov     [rcx + SEAMLDR_COM64_DATA.OriginalR10], r10
        mov     [rcx + SEAMLDR_COM64_DATA.OriginalR11], r11
        mov     [rcx + SEAMLDR_COM64_DATA.OriginalR12], r12

        ; zero non-input registers
        mov     r13, 0
        mov     r14, 0
        mov     r15, 0

        ; Align the stack pointer to 16-byte before running the main 64-bit code - required from proper crypto usage
        
        and     rsp, 0fffffffffffffff0h
        sub     rsp, 20h
        
        call    Target64
        
        ;; SEAMLDR64 finished running here.
        ;; Exit procedure:
        
        mov     rcx, [pCom64data]
        
        
        lgdt    [rcx + SEAMLDR_COM64_DATA.NewGdtr]
        
        
        mov     ax, [rcx+ SEAMLDR_COM64_DATA.OriginalES]
        mov     es, ax
        mov     ds, ax
        mov     ax, [rcx + SEAMLDR_COM64_DATA.OriginalFS]
        mov     fs, ax
        mov     ax, [rcx + SEAMLDR_COM64_DATA.OriginalGS]
        mov     gs, ax        
        mov     ax, [rcx + SEAMLDR_COM64_DATA.OriginalSS]
        mov     ss, ax        
        
        mov     eax, [rcx + SEAMLDR_COM64_DATA.OriginalECX  ]      
        push    rax
        mov     rax,   _restored_cs
        push    rax

        retfq   
        _restored_cs:
        
        lgdt    [rcx + SEAMLDR_COM64_DATA.OriginalGdtr]
        
        ;; turn off PCIDE bit in current CR4
        mov     rdx, cr4
        and     edx, (~020000h)
        mov     cr4, rdx 

        xor     rdx, rdx
        mov     edx, [rcx + SEAMLDR_COM64_DATA.OriginalCR4]

        ;; Obtain the saved OS CR4 and retain following bits - LA57, and PGE. Mask off all other bits to 0 and set the SMXE bit to 1.
        ;; PAE should be set regardless of whether it was set originally or not.
        and     edx, (CR4_LA57 | CR4_PGE)
        or      edx, (CR4_SMXE | CR4_PAE)
        mov     cr4, rdx
        
        mov     rdx, cr0
        and     edx, (~(CR0_WP))
        mov     cr0, rdx
        
DoExitAC:

        ;; Parameters for EXITAC
        mov     rbx, [rcx + SEAMLDR_COM64_DATA.ResumeRip]         ; uCode restores the RIP from RBX during EXITAC
        mov     r8, [rcx + SEAMLDR_COM64_DATA.OriginalCR3]         ; uCode restores the CR3 from R8 during EXITAC
        mov     r9, [rcx + SEAMLDR_COM64_DATA.RetVal]          ; SEAMLDR Error code is reported in R9
        mov     rdx, 0                                                     ; Clear all flags
        mov     rax, EXITAC                                                ; Do ExitAC
        
        push    2
        popfq

        lidt    [rcx + SEAMLDR_COM64_DATA.NewIDTR]
     

        ;; Clear other registers as described in spec - not xor to avoid changing flags
        mov     rdi, 0
        mov     rsi, 0
        mov     rcx, 0
        mov     rbp, 0
        mov     rsp, 0
        mov     r10, 0
        mov     r11, 0
        mov     r12, 0
        mov     r13, 0
        mov     r14, 0
        mov     r15, 0
        
        ; REX.W EXITAC to exit AC mode.
        db 48h
        _GETSEC
        
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ;;;;;;;;;;;;;;;;; SHOULD NOT RETURN HERE AFTER GETSEC ;;;;;;;;;;;;;;;;;
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ;; Cannot use ud2 -> triple fault for TXT shutdown here, because OS
        ;; IDT is already restored at that point
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        
        jmp     $



