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

# proj_defs.mk - Project related defintions

PROJ_FLAGS = 

ifndef RELEASE
PROJ_FLAGS += -DDEBUG
endif

ifdef SEAM_INST_SUPPORT
PROJ_FLAGS += -DSEAM_INSTRUCTIONS_SUPPORTED_IN_COMPILER
endif

#Versioning
ifdef PSEAMLDR_BUILD_DATE
PROJ_FLAGS += -DPSEAMLDR_BUILD_DATE=$(PSEAMLDR_BUILD_DATE)
else
PROJ_FLAGS += -DPSEAMLDR_BUILD_DATE=$(shell date +%Y%m%d)
endif

ifdef PSEAMLDR_BUILD_NUM
PROJ_FLAGS += -DPSEAMLDR_BUILD_NUM=$(PSEAMLDR_BUILD_NUM)
else
PROJ_FLAGS += -DPSEAMLDR_BUILD_NUM=0
endif

ifdef PSEAMLDR_MINOR_VER
PROJ_FLAGS += -DPSEAMLDR_MINOR_VER=$(PSEAMLDR_MINOR_VER)
else
PROJ_FLAGS += -DPSEAMLDR_MINOR_VER=0
endif

ifdef PSEAMLDR_MAJOR_VER
PROJ_FLAGS += -DPSEAMLDR_MAJOR_VER=$(PSEAMLDR_MAJOR_VER)
else
PROJ_FLAGS += -DPSEAMLDR_MAJOR_VER=1
endif
