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
 * @file elf.c
 * @brief ELF header handling
 */

#include "elf.h"
#include "error_reporting.h"
#include "accessors/ia32_accessors.h"

static bool_t relocate_elf_section(uint64_t image_addr, uint64_t image_size, elf64_shdr_t* section_header,
                                   uint64_t relocation_addr)
{
    elf64_rela_t* relocation;

    if (section_header->sh_entsize == 0)
    {
        TDX_ERROR("Section entry size is 0 which is unsupported\n");
        return false;
    }

    for (uint64_t i = 0; i < section_header->sh_size / section_header->sh_entsize; i++)
    {
        uint64_t relocation_offset = section_header->sh_addr + (i * section_header->sh_entsize);

        if (relocation_offset > (image_size - sizeof(elf64_rela_t)))
        {
            TDX_ERROR("Relocation entry offset 0x%llx is out of image bounds\n", relocation_offset);
            return false;
        }

        lfence(); // Fence speculative access to wrong address

        relocation = (elf64_rela_t*)(image_addr + relocation_offset);

        if (relocation->r_info == R_X86_64_RELATIVE)
        {
            if (relocation->r_offset > (image_size - sizeof(uint64_t)))
            {
                TDX_ERROR("Relocation offset 0x%llx is out of image bounds\n", relocation->r_offset);
                return false;
            }

            if (relocation->r_addend >= image_size)
            {
                TDX_ERROR("Relocation addend 0x%llx is out of image bounds\n", relocation->r_addend);
                return false;
            }

            lfence(); // Fence speculative access to wrong address

            *(uint64_t*)(image_addr + relocation->r_offset) = relocation_addr + relocation->r_addend;
        }
        else
        {
            TDX_ERROR("Unsupported relocation type - %d\n", relocation->r_info);
            return false;
        }
    }

    return true;
}

static bool_t check_elf_header(elf64_ehdr_t* elf_header)
{
    if ((elf_header->e_ident[EI_MAG0] != ELF_MAGIC0) ||
        (elf_header->e_ident[EI_MAG1] != ELF_MAGIC1) ||
        (elf_header->e_ident[EI_MAG2] != ELF_MAGIC2) ||
        (elf_header->e_ident[EI_MAG3] != ELF_MAGIC3))
    {
        TDX_ERROR("Unsupported ELF magic number 0x%lx\n", *((uint32_t*)elf_header->e_ident));
        return false;
    }

    if (elf_header->e_ident[EI_CLASS] != ELF_CLASS64)
    {
        TDX_ERROR("Unsupported ELF architecture class %d\n", elf_header->e_ident[EI_CLASS]);
        return false;
    }

    if (elf_header->e_ident[EI_DATA] != ELF_DATA2LSB)
    {
        TDX_ERROR("Unsupported ELF byte order %d\n", elf_header->e_ident[EI_DATA]);
        return false;
    }

    if (elf_header->e_ident[EI_VERSION] != EV_CURRENT)
    {
        TDX_ERROR("Unsupported ELF version %d\n", elf_header->e_ident[EI_VERSION]);
        return false;
    }

    return true;
}

bool_t relocate_elf_image(uint64_t image_addr, uint64_t image_size, uint64_t relocation_addr)
{
    elf64_ehdr_t* elf_header = (elf64_ehdr_t*)image_addr;
    elf64_shdr_t* section_header;

    if (!check_elf_header(elf_header))
    {
        return false;
    }

    for (uint64_t i = 0; i < elf_header->e_shnum; i++)
    {
        uint64_t section_header_offset = elf_header->e_shoff + (i * elf_header->e_shentsize);
        if (section_header_offset > (image_size - sizeof(elf64_shdr_t)))
        {
            TDX_ERROR("Section header offset 0x%llx is out of image bounds\n", section_header_offset);
            return false;
        }

        lfence(); // Fence speculative access to wrong address

        section_header = (elf64_shdr_t*)(image_addr + section_header_offset);

        if (section_header->sh_type == SHT_RELA)
        {
            if (!relocate_elf_section(image_addr, image_size, section_header, relocation_addr))
            {
                return false;
            }
        }
    }

    return true;
}
