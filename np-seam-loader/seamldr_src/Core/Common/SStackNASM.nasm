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

section EDATA32 data write PUBLIC USE32 align=16
shadow_stack_vesp: dq 0

section .text code USE32 align=1

global  _penter
_penter:
        push eax ; save tmp
        push ebx

        ; push RA to shadow stack
        mov eax, [esp+12]   ; get RA
        mov ebx, DWORD [shadow_stack_vesp]

        mov [ebx], eax      ; "push" RA
        add DWORD [shadow_stack_vesp], 4

        pop ebx
        pop eax
        ret

global  _pexit
_pexit:
        push eax ; make tmp
        push ebx

        ; pop from shadow stack
        mov ebx, DWORD [shadow_stack_vesp]
        sub ebx, 4
        mov eax, [ebx]
        mov DWORD [shadow_stack_vesp], ebx

        ; compare shadow RA to callee RA
        cmp eax, DWORD [esp + 12]
        jnz error

    skip_check:
        pop ebx ; restore tmp
        pop eax
        ret

    error:

        %ifidni ACM_TYPE,AC_BIOSAC
            %assign SHADOW_STACK_ERROR  ( CRASH_CODE_VALID + CRASH_CODE_SW_GENERATED + AC_BIOSAC + (ERR_SHADOW_STACK << CR_Major_cr_position) + (CLASS_INTERNAL_ERRORS << CR_Class_cr_position) )
        %endif
        %ifidni ACM_TYPE,AC_SINIT
            %assign SHADOW_STACK_ERROR  ( CRASH_CODE_VALID + CRASH_CODE_SW_GENERATED + AC_SINIT + (ERR_SHADOW_STACK << CR_Major_cr_position) + (CLASS_INTERNAL_ERRORS << CR_Class_cr_position) )
        %endif

        update_crash_register:
            mov     esi, LT_PRV_BASE+TXT.LT_CRASH
            mov     [esi], DWORD SHADOW_STACK_ERROR

        ltReset:
            mov   ecx, 1000
            mov   esi, LT_PRV_BASE+TXT.LT_CMD_SYS_RESET

            REPEAT
                    mov   DWORD [esi], 0
                    mov   eax, [esi]              ; Read it back
                    pause
            UNTILCXZ

        deadLoop:
            hlt
            jmp   deadLoop
