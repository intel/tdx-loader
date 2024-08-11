# Copyright (C) 2023 Intel Corporation                                          
#                                                                               
# Permission is hereby granted, free of charge, to any person obtaining a copy  
# of this software and associated documentation files (the "Software"),         
# to deal in the Software without restriction, including without limitation     
# the rights to use, copy, modify, merge, publish, distribute, sublicense,      
# and/or sell copies of the Software, and to permit persons to whom             
# the Software is furnished to do so, subject to the following conditions:      
#                                                                               
# The above copyright notice and this permission notice shall be included       
# in all copies or substantial portions of the Software.                        
#                                                                               
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS       
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL      
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES             
# OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE            
# OR OTHER DEALINGS IN THE SOFTWARE.                                            
#                                                                               
# SPDX-License-Identifier: MIT

import sys
import struct
import re
from   ctypes import *

IMAGE_FILE_MACHINE_I386           = 0x014c
IMAGE_FILE_MACHINE_X64            = 0x8664
EFI_IMAGE_NT_OPTIONAL_HDR32_MAGIC = 0x10b
EFI_IMAGE_NT_OPTIONAL_HDR64_MAGIC = 0x20b

class EFI_IMAGE_DOS_HEADER(Structure):
    _fields_ = [
        ('e_magic',              c_uint16),
        ('e_cblp',               c_uint16),
        ('e_cp',                 c_uint16),
        ('e_crlc',               c_uint16),
        ('e_cparhdr',            c_uint16),
        ('e_minalloc',           c_uint16),
        ('e_maxalloc',           c_uint16),
        ('e_ss',                 c_uint16),
        ('e_sp',                 c_uint16),
        ('e_csum',               c_uint16),
        ('e_ip',                 c_uint16),
        ('e_cs',                 c_uint16),
        ('e_lfarlc',             c_uint16),
        ('e_ovno',               c_uint16),
        ('e_res',                ARRAY(c_uint16, 4)),
        ('e_oemid',              c_uint16),
        ('e_oeminfo',            c_uint16),
        ('e_res2',               ARRAY(c_uint16, 10)),
        ('e_lfanew',             c_uint16)
        ]

class EFI_IMAGE_DATA_DIRECTORY(Structure):
    _fields_ = [
        ('VirtualAddress',       c_uint32),
        ('Size',                 c_uint32)
        ]

class EFI_IMAGE_FILE_HEADER(Structure):
    _fields_ = [
        ('Machine',               c_uint16),
        ('NumberOfSections',      c_uint16),
        ('TimeDateStamp',         c_uint32),
        ('PointerToSymbolTable',  c_uint32),
        ('NumberOfSymbols',       c_uint32),
        ('SizeOfOptionalHeader',  c_uint16),
        ('Characteristics',       c_uint16)
        ]

class EFI_IMAGE_OPTIONAL_HEADER32(Structure):
    _fields_ = [
        ('Magic',                         c_uint16),
        ('MajorLinkerVersion',            c_uint8),
        ('MinorLinkerVersion',            c_uint8),
        ('SizeOfCode',                    c_uint32),
        ('SizeOfInitializedData',         c_uint32),
        ('SizeOfUninitializedData',       c_uint32),
        ('AddressOfEntryPoint',           c_uint32),
        ('BaseOfCode',                    c_uint32),
        ('BaseOfData',                    c_uint32),
        ('ImageBase',                     c_uint32),
        ('SectionAlignment',              c_uint32),
        ('FileAlignment',                 c_uint32),
        ('MajorOperatingSystemVersion',   c_uint16),
        ('MinorOperatingSystemVersion',   c_uint16),
        ('MajorImageVersion',             c_uint16),
        ('MinorImageVersion',             c_uint16),
        ('MajorSubsystemVersion',         c_uint16),
        ('MinorSubsystemVersion',         c_uint16),
        ('Win32VersionValue',             c_uint32),
        ('SizeOfImage',                   c_uint32),
        ('SizeOfHeaders',                 c_uint32),
        ('CheckSum',                      c_uint32),
        ('Subsystem',                     c_uint16),
        ('DllCharacteristics',            c_uint16),
        ('SizeOfStackReserve',            c_uint32),
        ('SizeOfStackCommit' ,            c_uint32),
        ('SizeOfHeapReserve',             c_uint32),
        ('SizeOfHeapCommit' ,             c_uint32),
        ('LoaderFlags'     ,              c_uint32),
        ('NumberOfRvaAndSizes',           c_uint32),
        ('DataDirectory',                 ARRAY(EFI_IMAGE_DATA_DIRECTORY, 16))
        ]

class EFI_IMAGE_OPTIONAL_HEADER64(Structure):
    _fields_ = [
        ('Magic',                         c_uint16),
        ('MajorLinkerVersion',            c_uint8),
        ('MinorLinkerVersion',            c_uint8),
        ('SizeOfCode',                    c_uint32),
        ('SizeOfInitializedData',         c_uint32),
        ('SizeOfUninitializedData',       c_uint32),
        ('AddressOfEntryPoint',           c_uint32),
        ('BaseOfCode',                    c_uint32),
        ('ImageBase',                     c_uint64),
        ('SectionAlignment',              c_uint32),
        ('FileAlignment',                 c_uint32),
        ('MajorOperatingSystemVersion',   c_uint16),
        ('MinorOperatingSystemVersion',   c_uint16),
        ('MajorImageVersion',             c_uint16),
        ('MinorImageVersion',             c_uint16),
        ('MajorSubsystemVersion',         c_uint16),
        ('MinorSubsystemVersion',         c_uint16),
        ('Win32VersionValue',             c_uint32),
        ('SizeOfImage',                   c_uint32),
        ('SizeOfHeaders',                 c_uint32),
        ('CheckSum'     ,                 c_uint32),
        ('Subsystem',                     c_uint16),
        ('DllCharacteristics',            c_uint16),
        ('SizeOfStackReserve',            c_uint64),
        ('SizeOfStackCommit' ,            c_uint64),
        ('SizeOfHeapReserve',             c_uint64),
        ('SizeOfHeapCommit' ,             c_uint64),
        ('LoaderFlags'     ,              c_uint32),
        ('NumberOfRvaAndSizes',           c_uint32),
        ('DataDirectory',                 ARRAY(EFI_IMAGE_DATA_DIRECTORY, 16))
        ]

EFI_IMAGE_DIRECTORY_ENTRY_EXPORT      = 0
EFI_IMAGE_DIRECTORY_ENTRY_IMPORT      = 1
EFI_IMAGE_DIRECTORY_ENTRY_RESOURCE    = 2
EFI_IMAGE_DIRECTORY_ENTRY_EXCEPTION   = 3
EFI_IMAGE_DIRECTORY_ENTRY_SECURITY    = 4
EFI_IMAGE_DIRECTORY_ENTRY_BASERELOC   = 5
EFI_IMAGE_DIRECTORY_ENTRY_DEBUG       = 6
EFI_IMAGE_DIRECTORY_ENTRY_COPYRIGHT   = 7
EFI_IMAGE_DIRECTORY_ENTRY_GLOBALPTR   = 8
EFI_IMAGE_DIRECTORY_ENTRY_TLS         = 9
EFI_IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG = 10

class EFI_IMAGE_NT_HEADERS32(Structure):
    _fields_ = [
        ('Signature',            c_uint32),
        ('FileHeader',           EFI_IMAGE_FILE_HEADER),
        ('OptionalHeader',       EFI_IMAGE_OPTIONAL_HEADER32)
        ]

class EFI_IMAGE_NT_HEADERS64(Structure):
    _fields_ = [
        ('Signature',            c_uint32),
        ('FileHeader',           EFI_IMAGE_FILE_HEADER),
        ('OptionalHeader',       EFI_IMAGE_OPTIONAL_HEADER64)
        ]

class EFI_IMAGE_DEBUG_DIRECTORY_ENTRY(Structure):
    _fields_ = [
        ('Characteristics',       c_uint32),
        ('TimeDateStamp',         c_uint32),
        ('MajorVersion',          c_uint16),
        ('MinorVersion',          c_uint16),
        ('Type',                  c_uint32),
        ('SizeOfData',            c_uint32),
        ('RVA',                   c_uint32),
        ('FileOffset',            c_uint32),
        ]

EFI_IMAGE_DEBUG_TYPE_CODEVIEW   = 2

class EFI_IMAGE_SECTION_HEADER(Structure):
    _fields_ = [
        ('Name',                  ARRAY(c_uint8, 8)),
        ('VirtualSize',           c_uint32),
        ('VirtualAddress',        c_uint32),
        ('SizeOfRawData',         c_uint32),
        ('PointerToRawData',      c_uint32),
        ('PointerToRelocations',  c_uint32),
        ('PointerToLinenumbers',  c_uint32),
        ('NumberOfRelocations',   c_uint16),
        ('NumberOfLinenumbers',   c_uint16),
        ('Characteristics',       c_uint32),
        ]

print ('Start clearTimestamp')

if  len(sys.argv) != 2: 
    print ("usage: " + sys.argv[0] + "<exe file>")
    exit(1);
	
class Offset:
	def __init__(self, section, offset):
		self.section = section
		self.offset = offset

f_exe = open(sys.argv[1], 'rb+')
f_exe.seek(0)
exe_contents = f_exe.read()
exe_array = bytearray(exe_contents)
f_exe.seek(0)

DosHdr  = EFI_IMAGE_DOS_HEADER.from_buffer (exe_array, 0)
if DosHdr.e_magic != 0x5A4D :
  print ('ERROR: Invalid exe image (DosHdr - 0x%x)'%(DosHdr.e_magic))
  sys.exit(1)
PeHdr   = EFI_IMAGE_NT_HEADERS32.from_buffer (exe_array, DosHdr.e_lfanew)
if PeHdr.Signature != 0x4550:
  print ('ERROR: Invalid exe image (PeHdr - 0x%x)'%(PeHdr.Signature))
  sys.exit(1)
if PeHdr.FileHeader.Machine == IMAGE_FILE_MACHINE_X64:
  PeHdr64 = EFI_IMAGE_NT_HEADERS64.from_buffer (exe_array, DosHdr.e_lfanew)
  PeSectionOffset = DosHdr.e_lfanew + 4 + sizeof(EFI_IMAGE_FILE_HEADER) + PeHdr64.FileHeader.SizeOfOptionalHeader

elif PeHdr.FileHeader.Machine == IMAGE_FILE_MACHINE_I386:
  PeHdr32 = EFI_IMAGE_NT_HEADERS32.from_buffer (exe_array, DosHdr.e_lfanew)
  PeSectionOffset = DosHdr.e_lfanew + 4 + sizeof(EFI_IMAGE_FILE_HEADER) + PeHdr32.FileHeader.SizeOfOptionalHeader

else :
  print ('ERROR: Invalid exe image (Machine - 0x%x)'%(PeHdr.FileHeader.Machine))
  sys.exit(1)
  
ZeroedTimestamp = False
for Index in range (0, PeHdr.FileHeader.NumberOfSections, 1):
	PeSection = EFI_IMAGE_SECTION_HEADER.from_buffer (exe_array, PeSectionOffset + sizeof(EFI_IMAGE_SECTION_HEADER) * Index)    
	if bytes(PeSection.Name) == b".uncomme":
		ZeroedTimestamp = True
		exe_array[PeSection.PointerToRawData + 4 : PeSection.PointerToRawData + 8] = [0, 0, 0, 0]
		f_exe.write(exe_array)
  
f_exe.close()
print ("Clear timestamp done!")
if ZeroedTimestamp:
	exit(0)
else:
	exit(1)

