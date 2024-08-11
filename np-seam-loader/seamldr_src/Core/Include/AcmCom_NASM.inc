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

%ifndef ACMCOM_EQU
%define ACMCOM_EQU 0


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                       MACROS
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

%define CR0_PG                             0x80000000
%define CR4_PAE                            0x20
%define CR4_PSE                            0x10
%define PAGE4K                             0x1000
%define _1KB                               0x400
%define _2KB                               0x800
%define _4KB                               0x1000
%define _4KB_MASK                          (  ~  ( _4KB - 1 ) )
%define IA32_EFER_MSR                      0xC0000080
%define LME                                0x100
%define YMM_REG_QWORDS                     4
%define LT_PUB_BASE                        0xFED30000
%define _64KB                              0x10000
%define LT_PRV_BASE                        0xFED20000
%define BIT0                               0x1
%define BIT8                               0x100
%define BIT11                              0x800
%define CRASH_CODE_VALID                   0x80000000
%define MSR_CORE_THREAD_COUNT              0x35          ;Can be removed
%define MSR_SMRR_PHYMASK                   0x1F3          ;Can be removed
%define ACM_CODE64_SELECTOR                24
%define CRASH_CODE_SW_GENERATED            0x40000000
%define AC_BIOSAC                          0
%define AC_SINIT                           1
%define ERR_RLP_TIMEOUT                    1
%define ERR_RLP_SMRR_CONFIG                3
%define ERR_RLP_SMRR2_CONFIG               4
%define CLASS_ACM_EXIT                     7
%define CLASS_INTERNAL_ERRORS              0x20
%define ERR_SHADOW_STACK                   1
%define MSR_IA32_BIOS_SIGN_ID              0x8B
%define ERR_NO_RLP_UCODE_UPDATE            2
%define MSR_SMRR_PHYMASK                   0x1F3
%define MSR_SMRR2_PHYMASK                  0x1F7
%define MSR_SMRR2_PHYBASE                  0x1F6
%define MSR_IA32_MISC_ENABLES              0x1A0
%define BIT18                              0x40000
%define GDT_SIZE                           32
%define ACM_CODE_SELECTOR                  8
%define EXITAC                             3
%define SENTER                             4
%define SEXIT                              5
%define WAKEUP                             8
%define _8KB                               0x2000
%define MSR_SMRR_PHYBASE                   0x1F2
%define ACM_DATA_SELECTOR                  16
%define PORT80                             0x80
%define LBL_ACM                            0x1
%define RFA_VALID                          0x8000
%define IDT32GATE_INIT_1                   0x8E00
%define VACANT                             0x00
%define NOT_VACANT                         0x0ff
%define CR4_PGE                            (1 << 7)
%define ENTERACCS				           2
%define MSR_BIOS_SE_SVN                    0x302
%define MSR_BIOS_DONE    			       0x151
%define MSR_PLATFORM_INFO    			   0xCE
%define MSR_PLATFORM_INFO_SAMPLE_PART	   (1 << 27)
%define CR0_WP                             (1 << 16)
%define CR4_PAE        					   (1 << 5)
%define CR4_PGE 					       (1 << 7)
%define CR4_LA57					       (1 << 12)
%define CR4_SMXE                           (1 << 14)

%define MF_PRODUCTION      0
%define MF_DEBUG           (1 << 15)
%define MF_PROD_WORTHY     0
%define MF_NOT_PROD_WORTHY (1 << 14)


; T_DATA no longer used after code changes

%define _GETSEC         db      0x0F, 0x37
%define _MONITOR        db      0x0F, 0x01, 0x0C8
%define _MWAIT          db      0x0F, 0x01, 0x0C9

; append underscore to globals
%pragma win32 gprefix _

%ifidn __OUTPUT_FORMAT__, win64
DEFAULT REL      ; needed to instruct NASM to emit RIP-relative code
%endif

%macro GETSEC_EXITAC 0
        mov     eax, EXITAC                  ; GETSEC (EAX=3) for ExitAC
        mov     ebx, %%RETURN_ADDRESS
        xor     ecx, ecx
        xor     edx, edx
        _GETSEC
%%RETURN_ADDRESS:
%endmacro

%macro GETSEC_WAKEUP 0
        mov     eax, WAKEUP                  ; GETSEC (EAX=8) for WAKEUP
        xor     ebx, ebx
        xor     ecx, ecx
        xor     edx, edx
        _GETSEC
%endmacro

%macro GETSEC_SEXIT 0
        mov     eax, SEXIT                  ; GETSEC (EAX=5) for SEXIT
        xor     ebx, ebx
        xor     ecx, ecx
        xor     edx, edx
        _GETSEC
%endmacro

%macro TDATA_VAR  0
        ;
        ; Changing hardcoded T_DATA onto one retrieved from SINIT size
        ;
        mov     edi, LT_PUB_BASE + TXT.LT_SINIT_SIZE
        mov     edi, DWORD [edi]    ; Get SINIT region size
        add     edi, ebp
        sub     edi, _64KB
%endmacro
%define TDATA_VAR_RET_VAL(x)  [edi + x] ; Sighting #3865476  End

%macro TDATA_VAR_OFFSET_IN_EAX        1
        ;
        ; ebp keeps address of SINIT module in memory
        ;
        ; Changing hardcoded T_DATA onto one retrieved from SINIT size
        ;
        mov     edi, LT_PUB_BASE + TXT.LT_SINIT_SIZE
        mov     eax, DWORD [edi]    ; Get SINIT region size
        sub     eax, _64KB
        add     eax, ebp
        add     eax, %1

%endmacro

%define EDATA_VAR(x)    [ebp +  x]


%macro EDATA_VAR_OFFSET_IN_EAX        1
        ;;
        ;; ebp keeps address of SINIT module in memory
        ;;
        mov     eax, ebp
        add     eax, %1
%endmacro

%macro PROGRESS_MARK    1
        push BYTE %1
        call  ProgressMark
        %if MKF_ENGINEERING eq 1
                %if MKF_TRACE EQ 1
                        extern TraceProgress
                        push DWORD %1
                        call  TraceProgress

                %endif
        %endif
%endmacro

%macro TRAMPOLINE_ERROR    1
        %if MKF_ENGINEERING eq 1
                %if MKF_TRACE EQ 1
                        extern TraceTrampolineCodeError
                        push DWORD %1
                        call TraceTrampolineCodeError

                %endif
        %endif
%endmacro

%macro STACK_TEST_FILL_IN       0
%if (MKF_ENGINEERING == 1)
        mov     edi, stackStart
        mov     ecx, esp
        sub     ecx, stackStart
        shr     ecx, 2
        mov     eax, 0CCCCCCCCh
        rep     stosd
%endif
%endmacro


%define FILL64(H,L)     ( ( ( ( H ) - ( L ) ) / 8 ) - 1 )
%define FILL8(H,L)      ( ( ( H ) - ( L ) ) - 1 )

;%macro FILL64    2
;        exitm <( ( ( ( %1 ) - ( %2 ) ) / 8 ) - 1 ) >
;%endmacro
;
;%macro FILL8    2
;        exitm <( ( ( %1 ) - ( %2 ) ) - 1 ) >
;%endmacro

%define CR_Valid_cr                     1
%define CR_SwGenerated_cr               1
%define CR_Res_cr                       5
%define CR_Minor_cr                     9
%define CR_Source_cr                    1
%define CR_Major_cr                     5
%define CR_Class_cr                     6
%define CR_AcmType_cr                   4

%define CR_Valid_cr_position                     31
%define CR_SwGenerated_cr_position               30
%define CR_Res_cr_position                       25
%define CR_Minor_cr_position                     16
%define CR_Source_cr_position                    15
%define CR_Major_cr_position                     10
%define CR_Class_cr_position                     4
%define CR_AcmType_cr_position                   0

;
; Crash register record
;
;CR      RECORD  Valid_cr:1,SwGenerated_cr:1,Res_cr:5,Minor_cr:9,Source_cr:1,Major_cr:5,Class_cr:6,AcmType_cr:4
;
; Policy control record
;
;PC      RECORD  Res2_pc:28,OWN_REQ_pc:1,CAP_EXT_pc:1,NPW_OK_pc:1,RES_pc:1


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                STRUCTURE DEFINITIONS
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;TXT STRUCTURE

struc TXT
.LT_STS:                          resq   1
;// 0000h
.LT_ESTS:                         resq   1
;// 0008h
.LT_THREADS_EXISTS:               resq   1
;// 0010h
.R1_0:                            resq   1
;// 0018h
.LT_THREADS_JOIN:                 resq   1
;// 0020h
.R1_1:                            resq   1
;// 0028h
.LT_CRASH:                        resq   1
;// 0030h
.LT_CMD_SYS_RESET:                resq   1
;// 0038h
.LT_CMD_OPEN_PRIVATE:             resq   1
;// 0040h
.LT_CMD_CLOSE_PRIVATE:            resq   1
;// 0048h
.LT_CRASH2:                       resq   1
;// 0050h
.R2_0:                            resq FILL64(0x0A0,0x50)
.LT_SPAD:                         resq   1
;// 00A0h
.R3_0:                            resq FILL64(0x100,0x0A0)
.LT_VER_FSBIF:                    resq   1
;// 0100h
.R3_1:                            resq   1
;// 0108h
.LT_DIDVID:                       resq   1
;// 0110h
.LT_EID:                          resq   1
;// 0118h
.R4_0:                            resq FILL64(0x200,0x118)
.LT_VER_EMIF:                     resq   1
;// 0200h
.R4_1:                            resq   1
;// 0208h
.LT_CMD_LOCKMEM_CONFIG:           resq   1
;// 0210h
.LT_CMD_UNLOCK_MEM_CONFIG:        resq   1
;// 0218h
.LT_CMD_UNLOCK_MEMORY:            resq   1
;// 0220h
.R4_2:                            resq   1
;// 0228h
.LT_LOCK_BASE:                    resq   1
;// 0230h
.LT_UNLOCK_BASE:                  resq   1
;// 0238h
.R4_3:                            resq   1
;// 0240h
.R4_4:                            resq   1
;// 0248h
.LT_CMD_CACHE_INVALIDATE:         resq   1
;// 0250h
.LT_CMD_FLUSH_WB:                 resq   1
;// 0258h
.LT_NODMA_BASE:                   resq   1
;// 0260h
.LT_NODMA_SIZE:                   resq   1
;// 0268h
.LT_SINIT_BASE:                   resq   1
;// 0270h
.LT_SINIT_SIZE:                   resq   1
;// 0278h
.LT_CMD_LOCK_PMRC:                resq   1
;// 0280h
.LT_CMD_UNLOCK_PMRC:              resq   1
;// 0288h
.LT_MLE_JOIN:                     resq   1
;// 0290h
.R4_5:                            resq   1
;// 0298h
.LT_BLOCKMAP_CAP:                 resq   1
;// 02A0h
.LT_BLOCKMAP_CNF:                 resq   1
;// 02A8h
.LT_BLOCKMAP_POINTER:             resq   1
;// 02B0h
.R4_6:                            resq   1
;// 02B8h
.LT_CMD_BLOCKMAP_EN:              resq   1
;// 02C0h
.LT_CMD_BLOCKMAP_DIS:             resq   1
;// 02C8h
.LT_CMD_NODMA_CACHE_EN:           resq   1
;// 02D0h
.LT_CMD_NODMA_CACHE_DIS:          resq   1
;// 02D8h
.LT_CMD_NODMA_TABLE_PROTECT_EN:   resq   1
;// 02E0h
.LT_CMD_NODMA_TABLE_PROTECT_DIS:  resq   1
;// 02E8h
.LT_CMD_MEM_CONFIG_CHECKED:       resq   1
;// 02F0h
.R4_7:                            resq   1
;// 02F8h
.LT_HEAP_BASE:                    resq   1
;// 0300h
.LT_HEAP_SIZE:                    resq   1
;// 0308h
.LT_MSEG_BASE:                    resq   1
;// 0310h
.LT_MSEG_SIZE:                    resq   1
;// 0318h
.LT_SCRATCHPAD_0:                 resq   1
;// 0320h
.LT_BIOSACMCode:                  resd   1
;// 0328h
.LT_ACM_BIOS_POLICY:              resd   1
;// 032ch
.LT_DPR:                          resq   1
;// 0330h
.R4_8:                            resq   1
;// 0338h
.LT_FIT_STATUS:                   resq   1
;// 0340h
.R4_9:                            resq   1
;// 0348h
.LT_INCREMENT:                    resq   1
;// 0350h
.LT_SPAD_3:                       resq   1
;// 0358h
.LT_SCRATCHPAD_4:                 resq   1
;// 0360h
.LT_SCRATCHPAD_5:                 resq   1
;// 0368h
.LT_INCREMENT_2:                  resq   1
;// 0370h
.LT_SCRATCHPAD_6:                 resq   1
;// 0378h
.LT_CMD_OPEN_LOCALITY1:           resq   1
;// 0380h
.LT_CMD_CLOSE_LOCALITY1:          resq   1
;// 0388h
.LT_CMD_OPEN_LOCALITY2:           resq   1
;// 0390h
.LT_CMD_CLOSE_LOCALITY2:          resq   1
;// 0398h
.LT_CMD_OPEN_LOCALITY3:           resq   1
;// 03A0h
.LT_CMD_CLOSE_LOCALITY3:          resq   1
;// 03A8h
.R5_0:                            resq FILL64(0x400,0x3A8)
.LT_PUBLIC_KEY:                   resq   1
;// 0400h
.R5_1:                            resq FILL64(0x608,0x400)
.LT_ESTS_SET:                     resq   1
;// 0608h
.LT_EXISTS_SET:                   resq   1
;// 0610h
.R5_2:                            resq   1
;// 0618h
.LT_JOINS_SET:                    resq   1
;// 0620h
.R6_0:                            resq FILL64(0x670,0x620)
.LT_SCLEAN_SET:                   resq   1
;// 0670h
.R7_0:                            resq FILL64(0x6A0,0x670)
.LT_SPAD_SET:                     resq   1
;// 06A0h
.R8_0:                            resq FILL64(0x710,0x6A0)
.LT_EXISTS_CLEAR:                 resq   1
;// 0710h
.R8_1:                            resq   1
;// 0718h
.LT_JOINS_CLEAR:                  resq   1
;// 0720h
.R9_0:                            resq FILL64(0x770,0x720)
.LT_SCLEAN_CLEAR:                 resq   1
;// 0770h
.R10_0:                           resq FILL64(0x7A0,0x770)
.LT_SPAD_CLEAR:                   resq   1
;// 07A0h
.R11_0:                           resq FILL64(0x800,0x7A0)
.LT_VER_FTIF:                     resq   1
;// 0800h
.R11_1:                           resq   1
;// 0808h
.LT_PCH_DIDVID:                   resq   1
;// 0810h
.R12_0:                           resq FILL64(0x880,0x810)
.LT_UCS:                          resq   1
;// 880h
.R13_0:                           resq FILL64(0x8E0,0x880)
.LT_CMD_SECRETS:                  resq   1
;// 08E0h
.LT_CMD_NO_SECRETS:               resq   1
;// 08E8h
.LT_E2STS:                        resq   1
;// 08F0h
.R13_1:                           resq   1
;// 08F8h
.LT_FT_REGS1:                     resd   1
;// 0900h
.LT_FT_REGS2:                     resd   1
;// 0904h
.R14_0:                           resq FILL64(0x0D80,0x900)
.LT_SEQ_START:                    resq   1
;// 0D80h
.R14_2:                           resq   1
;// 0D88h
.LT_SEQ_DONE:                     resq   1
;// 0D90h
.LT_INCREMENT_3:                  resq   1
;// 0D98h
.LT_SCRATCHPAD_7:                 resq   1
;// 0DA0h
.LT_INCREMENT_4:                  resq   1
;// 0DA8h
.LT_SCRATCHPAD_8:                 resq   1
;// 0DB0h
.LT_INCREMENT_5:                  resq   1
;// 0DB8h
.LT_SCRATCHPAD_9:                 resq   1
;// 0DC0h
.LT_INCREMENT_6:                  resq   1
;// 0DC8h
.LT_SCRATCHPAD_10:                resq   1
;// 0DD0h
.LT_INCREMENT_7:                  resq   1
;// 0DD8h
.LT_SCRATCHPAD_11:                resq   1
;// 0DE0h
.LT_INCREMENT_8:                  resq   1
;// 0DE8h
.LT_SCRATCHPAD_12:                resq   1
;// 0DF0h
endstruc

;MLE_JOIN STRUCTURE

struc MLE_JOIN
.GdtLimit:                        resd 1
.GdtBase:                         resd 1
.SegSel:                          resd 1
.EntryPoint:                      resd 1
endstruc

;IDT64GATE STRUCTURE

struc IDT64GATE
.Off31_16_Attr_Sel_Off15_0:       resq   1
.Res_Off63_32:                    resq   1
endstruc

;COM_DATA STRUCTURE

struc COM_DATA
.Data64Start:             resd 1 ;		      // Offset of 64-bit data start (and Code32End)
.Code64Start:             resd 1 ;            // Offset of 64-bit code start
.Code64End:               resd 1 ;            // Offset of 64-bit code end
.Code64Entry:             resd 1 ;            // Offset of 64-bit code entry point
.StkStart:                resd 1 ;            // Offset of stack start
.Code32Start:             resd 1 ;            // Offset of code segment start.
endstruc

;BIOSAC_COM64_DATA STRUCTURE

struc BIOSAC_COM64_DATA
.Tolud:                   resq   1
.Touud:                   resq   1
.AcmBase:                 resd   1
.AcmSize:                 resd   1
.PdptBase:                resd   1
.error64:                 resd   1
.Pattern:                 resq YMM_REG_QWORDS
.StrideSize               resd   1
.Reserved                 resd   1
.shadow_stack_vesp:       resq   1
endstruc

;When updating below structure, make sure to update COM64_DATA structure in 
;common64.h. If they are not in sync, random sinit failures may be 
;seen during resume flows

;COM64_DATA STRUCTURE

struc COM64_DATA

.Rc6Mem:                  resq   1
.MediaRc6Mem              resq   1
.Mdrb:                    resq   1
.Touud:                   resq   1
.Tolud:                   resq   1
.Bgsm:                    resq   1
.Bdsm:                    resq   1
.Ggc:                     resq   1
.TsegMb:                  resq   1
.Dpr:                     resq   1
.Pavpc:                   resq   1
.PavpcDE                  resq   1
.PrmrrBase:               resq   1
.PrmrrMask:               resq   1
.Mpmen:                   resd   1
.PmrLoBase:               resd   1
.PmrLoLimit:              resd   1
.PmrHiBase:               resd   1
.PmrHiLimit:              resd   1
.GunitCtrl:               resd   1
.GucWopcmOffset:          resd   1
.GucWopcmSize:            resd   1
.GucMediaWopcmOffset:     resd   1
.GucMediaWopcmSize:       resd   1
.BtPol:                   resq   1
.BpKey0:                  resq   1
.BpKey1:                  resq   1
.BpKey2:                  resq   1
.BpKey3:                  resq   1
.BpKey4:                  resq   1
.BpKey5:                  resq   1
.Pml4PageDirectoryBase:   resd   1
.error64:                 resd   1
.ReqType:                 resb   1
.shadow_stack_vesp:       resq   1
endstruc

%if 0
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
%endif


;GDT32DESCRIPTOR STRUCTURE

struc GDT32DESCRIPTOR

.Limit15_0:               resw    1
.Base23_0:                resb    3
.Attr:                    resb    1
.Attr_Limit19_16:         resb    1
.Base31_24:               resb    1

endstruc


;GDT STRUCTURE

struc GDT

.NullDescriptor: resb GDT32DESCRIPTOR_size
.AcmCodeDescriptor: resb GDT32DESCRIPTOR_size
.AcmDataDescriptor: resb GDT32DESCRIPTOR_size
.AcmCode64Descriptor:  resb GDT32DESCRIPTOR_size

endstruc

;RANGE STRUCTURE

struc RANGE

.labl:                    resq   1
.attr:                    resw   1
.flags:                   resw   1
.len:                     resq   1
.base:                    resq   1
.top:                     resq   1
.almtMask:                resq   1

endstruc

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                       DUMMYS FOR ACM HEADER
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

struc   Dummy_1
        .HeaderLen               resd   1
        .HeaderVersion           resd   1
endstruc

struc   Dummy_2
        .ModuleVendor            resd   1
        .Revision                resd   1
        .Sizeb                   resd   1
endstruc

struc   Dummy_3
        .CodeControl             resd   1
        .ErrorEntryPoint         resd   1
endstruc

struc   Dummy_4
        .Reserved2               resb   64
        .KeySize                 resd   1
        .ScratchSize             resd   1
        .RSA2048PubKey           resb   256
        .PubExp                  resd   1
        .RSA2048Sig              resb   256
        .scratch                 resb   572
endstruc
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;ACM_HEADER STRUCTURE
struc ACM_HEADER_0

.ModuleType                             resw    1
.ModuleSubType                          resw    1
.Dummy_1_var                            resb    Dummy_1_size
.ModuleID                               resw    1
.ModuleFlags                            resw    1
.Dummy_2_var                            resb    Dummy_2_size
.AcmSvn                                 resw    1
.SeSvn                                  resw    1
.Dummy_3_var                            resb    Dummy_3_size
.GDTSize                                resd    1
.GDTBasePtr                             resd    1
.SegSel                                 resd    1
.EntryPoint                             resd    1
.Dummy_4_var                            resb    Dummy_4_size

endstruc
;IDT32GATE STRUCTURE

struc IDT32GATE

.Off15_0:                 resw    1
.Sel:                     resw    1
.Attr:                    resw    1
.Off31_16:                resw    1

endstruc

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                       FUNCTION PROTOTYPES
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

extern fillMemory
extern CoreBuildPml4TablesShort
extern AcmEntryPoint
extern CoreBuildPml4Tables
extern copyMemory
extern __Wait1ms
extern INTErrorHandler
extern Update_CRx
extern SgxProtection
extern commonAcmEntryPoint

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                       EXTERN VARIABLES
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

extern BiosacCom64Data
extern Com64Data
extern AcmBase
extern stackStart
extern GdtBasePtr
extern monitorField
extern ilpSmrrBase
extern ilpSmrrMask
extern ilpSmrr2Base
extern ilpSmrr2Mask
extern ilpSmrr2Support
extern LocalitiesToCheck
extern BspMcuVer
extern MlePageTabPhy
extern MleEntryPointPhy
extern CodeSegmentStart
extern AcmSize
extern AcmTop
extern OriginalIDTR
extern OriginalEIP
extern OriginalEAX
extern OriginalESI
extern OriginalEDI
extern OriginalECX
extern OriginalEDX
extern OriginalCR4
extern OriginalES
extern OriginalFS
extern OriginalGS
extern OriginalSS
extern SeamldrCom64Data
extern OriginalIDTRLimit
extern HeaderStart
extern shadow_stack_vesp
extern shadow_stack_vesp64
extern shadow_stack_vesp64_bottom

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                       Helper macros
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;            Implementation of if and else Macros
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

%macro IF 1

        %push IF
        j%-1  %$ifnot

%endmacro

%macro ELSE 0

  %ifctx IF
        %repl   else
        jmp     %$ifend
        %$ifnot:
  %else
        %error  "expected IF before ELSE"
  %endif

%endmacro

%macro ENDIF 0

  %ifctx IF
        %$ifnot:
        %pop
  %elifctx  else
        %$ifend:
        %pop
  %else
        %error  "expected IF or ELSE before ENDIF"
  %endif

%endmacro

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Implementation of Repeat Macro
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

%macro REPEAT 0

    %push   REPEAT
    %$begin:

%endmacro

%macro UNTIL_FOREVER 0
        jmp    %$begin
%$break:
    %pop

%endmacro

%macro UNTIL 3
        cmp %1,%3
        j%-2    %$begin
%$break:
    %pop

%endmacro

%macro UNTILCXZ 0

        loop    %$begin
%$break:
    %pop

%endmacro

%macro UNTILCXNZ 0

        loop    %$begin
%$break:
    %pop

%endmacro


%macro BREAK_IF_EQUAL 2
	%ifctx REPEAT
                cmp %1,%2
                je %$break
	%else
		%fatal "BREAK_IF must be inside REPEAT"
	%endif
%endmacro

%macro BREAK_IF_NOTEQUAL 2
	%ifctx REPEAT
                cmp %1,%2
                jne %$break
	%else
		%fatal "BREAK_IF must be inside REPEAT"
	%endif
%endmacro

%macro BREAK_IF_ZERO 0
	%ifctx REPEAT
                je %$break
	%else
		%fatal "BREAK_IF must be inside REPEAT"
	%endif
%endmacro

%macro BREAK_IF_NOT_ZERO 0
	%ifctx REPEAT
                jne %$break
	%else
		%fatal "BREAK_IF must be inside REPEAT"
	%endif
%endmacro
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Implementation of MULTIPUSH and MULTIPOP Macro
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


%macro  MULTIPUSH 1-*

  %rep  %0
        push    %1
  %rotate 1
  %endrep

%endmacro

%macro  MULTIPOP 1-*

  %rep %0
  %rotate -1
        pop     %1
  %endrep

%endmacro

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Implementation of PROLOGUE and EPILOGUE  Macro
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%macro  PROLOGUE 1
        push    ebp
        mov     ebp,esp
        sub     esp,%1
%endmacro

%macro  PROLOGUE 0
        push    ebp
        mov     ebp,esp
%endmacro

%macro  EPILOGUE  0
        leave
        ret
%endmacro
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Implementation of DEBUG_BREAK_POINT Macro define DEBUG before using
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

%ifdef DEBUG

%macro DEBUG_BREAK_POINT 0
        jmp     $
%endmacro

%macro PRINT_TO_PORT 1
        push ax
        mov ax, %1
        out PORT80, ax
        pop ax
%endmacro

%else
%macro DEBUG_BREAK_POINT  0
%endmacro

%macro PRINT_TO_PORT 1
%endmacro

%endif

%endif