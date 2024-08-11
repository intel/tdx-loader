#// Copyright (C) 2023 Intel Corporation                                          
#//                                                                               
#// Permission is hereby granted, free of charge, to any person obtaining a copy  
#// of this software and associated documentation files (the "Software"),         
#// to deal in the Software without restriction, including without limitation     
#// the rights to use, copy, modify, merge, publish, distribute, sublicense,      
#// and/or sell copies of the Software, and to permit persons to whom             
#// the Software is furnished to do so, subject to the following conditions:      
#//                                                                               
#// The above copyright notice and this permission notice shall be included       
#// in all copies or substantial portions of the Software.                        
#//                                                                               
#// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS       
#// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   
#// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL      
#// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES             
#// OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
#// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE            
#// OR OTHER DEALINGS IN THE SOFTWARE.                                            
#//                                                                               
#// SPDX-License-Identifier: MIT

# compiler_defs.mk - Compiler definition and flags

include proj_defs.mk

# Compiler
CC = clang
CXX = clang++
CCVERSION = $(shell clang --version | grep ^clang | cut -f1 -d"." | sed 's/^.* //g' )

# Standard flags
STD_FLAGS = -MD -MP -m64 -Wall -Wextra -fPIC -fno-builtin-memset -fvisibility=hidden \
		    -mcmodel=small -mstack-alignment=16 -mstackrealign -std=c17 -mno-mmx -mno-sse

# Optimization flags
OPT_FLAGS = -O2

# SecV mandatory flags
SECV_FLAGS = -Wdouble-promotion -Wshadow -Wconversion -Wmissing-prototypes -Wpointer-arith \
			 -Wuninitialized -Wunreachable-code -Wunused-function -Werror -D_FORTIFY_SOURCE=2 \
			 -fno-zero-initialized-in-bss -fstack-protector-strong -fno-jump-tables

CET_FLAGS = -mshstk -fcf-protection

# Combined flags
CFLAGS = $(STD_FLAGS) $(PROJ_FLAGS) $(OPT_FLAGS) $(SECV_FLAGS) $(CET_FLAGS) $(PRODUCTION_FLAGS)

# Entry pointer for the linker
MODULE_ENTRY_POINT = pseamldr_entry_point

# Linker flags
LINKER_SCRIPT = $(PROJ_DIR)/tdx_linker_script.lds

LDFLAGS = -Wl,-shared -Wl,-pie -Wl,-e,$(MODULE_ENTRY_POINT) -Wl,-z,relro -Wl,-z,now -Wl,--wrap=__stack_chk_fail \
		  -disable-red-zone -nostartfiles -Wl,-T,$(LINKER_SCRIPT)

