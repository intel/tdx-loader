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

;Same as 586
CPU P4
;---------------------------------------------------------------------------
%include "AcmCom_NASM.inc"


section EDATA32 data write PUBLIC

        ALIGN 16

    CodeSegmentStart:    dd  00 ; size of ACM data + stack

    OriginalIDTR:    dq  00h         ; Original IDTR Limit/Base
    OriginalEIP:     dd  00h
    OriginalEAX:     dd  00h
    OriginalEBX:     dd  00h    
    OriginalECX:     dd  00h
    OriginalESI:     dd  00h
    OriginalEDI:     dd  00h
    OriginalEDX:     dd  00h
    OriginalCR3:     dd  00h
    OriginalCR4:     dd  00h    
    OriginalES:      dw 00h
    OriginalFS:      dw 00h
    OriginalGS:      dw 00h
    OriginalSS:      dw 00h        


    ;PUBLIC R_ACM
    global R_ACM
    R_ACM:              dq  LBL_ACM
                        dw  0
                        dw  RFA_VALID
    AcmSize:            dd  00h         ; Size of currently running ACM
                        dd  0
    AcmBase:            dd  00h         ; Base address of where ACM is in memory
                        dd  0
    AcmTop:             dd  00h         ; End address of ACM in memory
                        dd  0
                        dq  _4KB_MASK

        
;----------------------------------------------------------------------------
;       C O D E     S E G M E N T
;----------------------------------------------------------------------------
section .text$mn code PUBLIC align=1 USE32
        ;
        ; Don't destroy the following values.
        ; ACM_PE2BIN tool reads [sinitAcmStart - 8] and interprets it
        ; as offset of image where to store relocation table
        ; ACM_PE2BIN tool stores offset of the beginning of CODE32 segment in
        ; [sinitAcmStart - 4] for ACM code use.
        ; Initializing of [sinitAcmStart - x] = offset HeaderStart is
        ; equivalent to initializing it as [sinitAcmStart - x] = 0 but with
        ; side effect that offset of sinitAcmStart - x is inserted into
        ; relocation table and is fixed-up by fix-up loop.
        ; Code makes use of this effect.
        ;
    istruc COM_DATA
    at COM_DATA.Data64Start,      dd       HeaderStart
    at COM_DATA.Code64Start,      dd       HeaderStart
    at COM_DATA.Code64End,        dd       HeaderStart
    at COM_DATA.Code64Entry,      dd       HeaderStart
    at COM_DATA.StkStart,         dd       stackStart
    at COM_DATA.Code32Start,      dd       HeaderStart
    iend

;-----------------------------------------------------------------------------
;-----------------------------------------------------------------------------
;  Procedure:	AcmEntryPoint
; 
;  Input:	State after GETSEC[SENTER|ENTERACCS] instruction
; 
;  Output:	None
; 
;  Description:	Performs fix-ups; transfers control to project-specific
;               entry point
; 
;-----------------------------------------------------------------------------
;-----------------------------------------------------------------------------
AcmEntryPoint :
        nop
        nop
        nop


        ; Right after ENTERACCS, SEAMLDR 32-bit assembly code will do the following:
        ; SIDT saved_OS_IDTR
        ; LIDT null_IDTR // a 48-bit variable that contains 0's
        sidt    [ds:(ebp + stackStart + 4*6)]

        mov     dword [ds:(ebp + stackStart + 4)], 0       ; Make sure that Null IDTR is actually zero
        mov     dword  [ds:(ebp + stackStart + 4 + 4)], 0
        lidt    [ds:(ebp + stackStart + 4)]          ; Load NULL IDTR
        
        cmp     eax, ENTERACCS
        jz     _IS_ENTERACCS        
        ud2
        _IS_ENTERACCS:        
        lfence
    


        ;
        ; Save registers to Fixup scratch area (size of 40h bytes reserved for fixup routine use)
        ;
        mov     dword  [ds:(ebp + stackStart + 4*0)], eax
        mov     dword  [ds:(ebp + stackStart + 4*1)], ebx
        mov     dword  [ds:(ebp + stackStart + 4*2)], ecx
        mov     dword  [ds:(ebp + stackStart + 4*3)], edx
        mov     dword  [ds:(ebp + stackStart + 4*4)], esi
        mov     dword  [ds:(ebp + stackStart + 4*5)], edi


        ;
        ; SE_SVN should be written as soon as possible
        ;

        mov     ecx, MSR_BIOS_SE_SVN
        rdmsr

        ; bits [63:56] (upper 8 bits of EDX) of SE_SVN MSR are the SEAMLDR_SVN that we want to write

        and     edx, 000FFFFFFh
        xor     ebx, ebx
        mov     bx, word [ds:(ebp + ACM_HEADER_0.SeSvn)]         
        ; SeSvn is 16 bits - don't overwrite another component's svn
        shl     ebx, 24
        or      edx, ebx

        ; Need to clear lower 8 bits containing patch-at-reset SE_SVN value, not writable and will GP if written with !0 value.

        and     eax, 0FFFFFF00h
        wrmsr
           

        mov     ecx, MSR_BIOS_DONE
        rdmsr
        test    eax, 1
        jnz _BIOS_DONE_LOCKED
        db      0Fh, 0Bh                ; ud2
        
        _BIOS_DONE_LOCKED:


        mov     esi, stackStart+40h
        add     esi, ebp                ; point to ACM reloc table for fixup
        mov     ecx, dword [esi] ; get relocCount

        ; Update this section of code for 18 bits of relocation data for 256KB ACM size support
        or          ecx,ecx
        IF ne                           ; Test for IF ecx != 0 condition
          xor     edx, edx              ; # bits to shift right (Shift Right counter)
          add     esi, 4                ; point to 1st relocAddr
          mov     ebx, 3FFFFh           ; For clipping to lower 18 bits

          xor     eax, eax
FixupLoop:
          mov     edi, dword [esi] ; get relocAddr
          xchg    ecx, edx              ; Keep ecx = Shift Right count
          shr     edi, cl               ; Shifting right by Shift Right count
          and     edi, ebx              ; Clipped to lower 18 bits
          add     dword [ds:(ebp+edi)], ebp ; fix it up
          xchg    ecx, edx              ; Restoring ecx

          add     edx,2                 ; Increment Shift Right counter
          and     edx, 0Fh              ; Clipped Shift Right counter to 0-15 count

          add     esi, 2                ; point to next relocAddr
          or      edx,edx
          IF e                          ; Test for  IF edx == 0
            add     esi, 2              ; Adjust relocAddr for proper alignment if Shift Right counter == 0
          ENDIF

          loop    FixupLoop

          %ifdef MF_ATOM_SUPPORT
          mov ecx, MSR_CACHE_FLUSH
          mov eax, CACHE_FLUSH_CMD
          mov edx, 0
          wrmsr
          %endif

        ENDIF
        
          lfence
        
        ;
        ; Find offset of code segment start, updated by ACM_PE2BIN tool
        ; Also serves as stack end
        ;
        mov     esi, AcmEntryPoint
        mov     eax, [cs:((esi - COM_DATA_size) + COM_DATA.Code32Start)]
        mov     [CodeSegmentStart], eax
        ;
        ; Restore registers from Fixup scratch area (size of 40h bytes reserved for fixup routine use)
        ;
        mov     eax, DWORD  [(stackStart + 4*0)]
        mov     ebx, DWORD  [(stackStart + 4*1)]
        mov     ecx, DWORD  [(stackStart + 4*2)]
        mov     edx, DWORD  [(stackStart + 4*3)]
        mov     esi, DWORD  [(stackStart + 4*4)]
        mov     edi, DWORD  [(stackStart + 4*5)]

        mov     [OriginalEIP], ebx
        mov     [OriginalEAX], eax
		mov     [OriginalECX], ecx
        mov     [OriginalESI], esi
        mov     [OriginalEDI], edi
        mov     [OriginalEDX], edx
        mov     eax, DWORD [(stackStart + 4*6)]
        mov     [OriginalIDTR], eax
        mov     eax, DWORD [(stackStart + 4*7)]
        mov     [OriginalIDTR + 4], eax        

        mov	    eax, cr4
        mov     [OriginalCR4], eax
        mov	    eax, cr3
        mov     [OriginalCR3], eax         

        ;                      
        ; Initialize Stack and Extended Data segments
        ;
        mov     ax, ES
        mov     [OriginalES], ax
        mov     ax, FS
        mov     [OriginalFS], ax
        mov     ax, GS
        mov     [OriginalGS], ax
        mov     ax, SS
        mov     [OriginalSS], ax        
        mov     ax, ACM_DATA_SELECTOR
        mov     es, ax
        mov     fs, ax
        mov     ss, ax                  ; init stack segment
        mov     esp, [CodeSegmentStart]

        sub     esp, MCP_STACK_GAP          ; Safety margin

        mov     ebx, [CodeSegmentStart]
        sub     ebx, MCP_SHADOW_STACK_GAP  ; setting up shadow stack buffer
        mov     DWORD [shadow_stack_vesp], ebx

        STACK_TEST_FILL_IN


        mov     [AcmBase], ebp            ; save Acm.base
        mov     DWORD [AcmTop], ebp
        xor     edx, edx
        mov     eax, [HeaderStart+ACM_HEADER_0.Dummy_2_var + Dummy_2.Sizeb]
        shl     eax, 02h                ; mult by 4
        mov     [AcmSize], eax            ; save ACM.Size in bytes
        add     [AcmTop], eax             ; Save end address of ACM
        
; HSW Sighting #3865022 Start
        ;
        ; The race condition between uCode issuing CMD.OPEN-PRIVATE
        ; and ACM reading crash register to save/restore it has been
        ; identified. The race condirion led to value "-1" read from
        ; status register because private space has not been actually
        ; opened yet at the time of this read. Measured delay between
        ; command and read was approximately 4us. Delay loop below is
        ; 5 times longer what has be sufficient in all casese unless
        ; part is hopelessy broken. Yet another side effect is
        ; that if the loop expires meaning that private space is not
        ; opened we cannot issue LT.RESET or update crash code since
        ; both registers belong to closed private space.
        ; That is why since there is no good action to take, we are
        ; not doing any and let code fall through. The same whould
        ; happen without added loop so code doesn't add any
        ; additional risk. The full analysis of what would
        ; happen if private space fails to open at all is left
        ; to SecoE.
        ; 
        ; 1308887577 fix:
        ; retry a long time, don't write to io ports
        RETRIES          EQU     080000000h
        
        mov     ecx, RETRIES
        mov     edi, LT_PRV_BASE + TXT.LT_STS
        
        REPEAT
        mov         eax,dword [edi]
        BREAK_IF_NOTEQUAL eax,0FFFFFFFFh     ; Break the loop IF eax != 0FFFFFFFFh
          pause          
        UNTILCXZ
        test ecx, ecx
        jnz OPENED_PRIVATE_SPACE
        ud2
        OPENED_PRIVATE_SPACE:
        
; HSW Sighting #3865022 End 
   
        call  Update_CRx
        
        jmp     commonAcmEntryPoint

