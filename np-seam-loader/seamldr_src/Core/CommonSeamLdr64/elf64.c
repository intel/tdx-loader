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

#include "common.h"
#include "Common64.h"
#include "Header.h"
#include "NpSeamldrApi.h"
#include "NpSeamldr.h"
#include "elf.h"

UINT64 RelocateSection(UINTN ElfImage, Elf64_Shdr* SectionHeader, UINTN RelocationAddr) {
    Elf64_Rela* CurRela;

    if (SectionHeader->sh_entsize == 0) {
        return NP_SEAMLDR_PARAMS_STATUS_EBADPARAM;
    }

    for (UINT64 i = 0; i < SectionHeader->sh_size / SectionHeader->sh_entsize; i++) {        
        CurRela = (Elf64_Rela*)(ElfImage + SectionHeader->sh_addr + i * SectionHeader->sh_entsize);
        if (CurRela->r_info == R_X86_64_RELATIVE) {            
            *(UINT64 *)(ElfImage + CurRela->r_offset) = RelocationAddr + CurRela->r_addend;
        }
        else {
            COMSERIALOUT("Unsupported relocation!!\n");
            return NP_SEAMLDR_PARAMS_STATUS_EBADPARAM;
        }
    }

    return NP_SEAMLDR_PARAMS_STATUS_SUCCESS;
}

UINT64 RelocateImage(UINTN ElfImage, UINTN RelocationAddr) {
    Elf64_Ehdr* ElfHeader = (Elf64_Ehdr*)ElfImage;
    Elf64_Shdr* CurSheader;
    UINT64 Status = NP_SEAMLDR_PARAMS_STATUS_SUCCESS;

    for (UINT32 i = 0; i < (UINT32)ElfHeader->e_shnum; i++) {        
        CurSheader = (Elf64_Shdr*)(ElfImage + ElfHeader->e_shoff + (UINT64)i * ElfHeader->e_shentsize);
        if (CurSheader->sh_type == SHT_RELA) {
            Status = RelocateSection(ElfImage, CurSheader, RelocationAddr);
            if (Status != NP_SEAMLDR_PARAMS_STATUS_SUCCESS) {
                return Status;
            }
        }
    }

    return Status;
}