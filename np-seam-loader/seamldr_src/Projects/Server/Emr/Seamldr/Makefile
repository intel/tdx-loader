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

!message ===== In make file $(PROJECT_DIR)\makefile =====

!include $(ACM_ROOT_DIR)\Core\Server\Build\ACMX.MAK 
MKF_FLAGS = $(MKF_FLAGS) /DNO_CORE_ERRORHANDLE=1
CORE_FLAGS = $(CORE_FLAGS)

#*****************************************************************************
#
# Name ACM
#
#*****************************************************************************

ACM             = SEAMLDR

ADDITIONAL_EXCLUDE_DIR=SINIT^

all1: build_extra all

#*****************************************************************************
#
# Build type selection for extra objects
#
#*****************************************************************************

!if "$(BLD)"=="ENG_NT"
!elseif "$(BLD)"=="ENG_TR"
!elseif "$(BLD)"=="REL_NT"
!else

!ERROR ERROR: Unsupported build type (expecting ENG_NT/ENG_TR/REL_NT).

!endif

build_extra:
!if DEFINED(EXTRA_OBJ_DIR)
        -md     $(EXTRA_OBJ_DIR)
!endif

!include $(ACM_ROOT_DIR)\Projects\Server\PROJECT.MAK

