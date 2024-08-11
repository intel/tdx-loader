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

!message ===== In make file $(ACM_ROOT_DIR)\Projects\Server\Project.mak =====

ACM_ENTRYPOINT  = AcmEntryPoint

ACM64_ENTRYPOINT= Entry64

ACM_NAME        = $(PRJ_STR)_$(ACM)_$(BLD)_$(SFX)

ACM64_NAME      = $(PRJ_STR)_$(ACM)64_$(BLD)_$(SFX)

!if ("$(BLD)"!="ENG_NT") && ("$(BLD)"!="ENG_TR") && ("$(BLD)"!="REL_NT")

!ERROR ERROR: Unsupported build type (expecting ENG_NT/ENG_TR/REL_NT).

!endif

#
# Assign directoroes. Project_dir is assigned in BLD.BAT batch file
#
OBJ_DIR         = $(PROJECT_DIR)\BUILD\PRJ\$(BLD)\$(SFX)

LIB_DIR         = $(PROJECT_DIR)\BUILD\LIB\CORE\$(BLD)\$(SFX)

SERVER_LIB_DIR  = $(PROJECT_DIR)\BUILD\LIB\SERVER\$(BLD)\$(SFX)

#*****************************************************************************
#
# Include Server core file. Transitively common core file is included as well
#
#*****************************************************************************

!include $(ACM_ROOT_DIR)\Core\Server\Build\acmx.mak

#
# NMAKE evaluates targets in the order in which they appear in make file, not in
# order in which they are listed in dependency line of ALL target.
#

all:
#
# Call nmake to build makefile.h first. It is needed for core library.
# File is saved in project dir to make sure that it has only one copy - this
# is needed for prebuild tool. Then do prebuild step and then local build.
#
        @echo ===== Performing MAKEFLAG.H BUILD step =====
        @$(NMAKE) /F makeflag.mak BLD_DIR=$(PROJECT_DIR)
        @$(NMAKE) prebuild
        @$(NMAKE) TASK=BUILD loc_build

#
# Include must be after first target otherwise makeflag.mak target will be
# built first.
#
!include  MAKEFLAG.MAK

prebuild:
        @echo ===== Performing project PREBUILD step =====
        @echo > nul <<project_listconvert.txt<<project_listexclude.txt
makeflag.auto
$(ACM).h
<<
build
$(ADDITIONAL_EXCLUDE_DIR)
<<
!if !DEFINED(SKIP_PREBUILD)
        @echo $(PREBUILD) /R $(PROJECT_DIR)\.. /T $(OBJ_DIR)\project_prebuild.incl /C project_listconvert.txt /E project_listexclude.txt /M PROJECT
        @$(PREBUILD) /R $(PROJECT_DIR)\.. /T $(OBJ_DIR)\project_prebuild.incl /C project_listconvert.txt /E project_listexclude.txt /M PROJECT
!endif
        @echo #define text_alignment_padding 0  > $(OBJ_DIR)\text_alignment_padding.h
        $(H2INCX) $(BASE_H2INCX_FLAGS) -o $(OBJ_DIR) $(PROJECT_DIR)\makeflag.auto

loc_build:
        @echo ===== Performing BUILD step =====
        @echo MKF_FLAGS=$(MKF_FLAGS) 2
        cd $(SERVER_CORE_BUILDDIR)
        @echo MKF_FLAGS=$(MKF_FLAGS) 1
        @$(NMAKE) /F $(SERVER_CORE_BUILDDIR)\corex.mak LIB_DIR=$(LIB_DIR) SERVER_LIB_DIR=$(SERVER_LIB_DIR) OBJ_DIR=$(OBJ_DIR) "MKF_FLAGS=$(MKF_FLAGS)"
        cd $(PROJECT_DIR)
        @$(NMAKE) TASK=ALL_BUILD all_build

all_build: $(OBJ_DIR)\$(ACM_NAME).bin

!if "$(TASK)"=="ALL_BUILD"

!message ===== Including $(OBJ_DIR)\project_prebuild.incl.mak=====
!include  $(OBJ_DIR)\project_prebuild.incl

!endif

#
# Tool flag updates.
#

H2INCX_FLAGS    = $(BASE_H2INCX_FLAGS) -o $(OBJ_DIR)

ALL_INCLUDES    = /I$(PROJECT_DIR) /I$(PROJECT_DIR)\..\INCLUDE /I$(OBJ_DIR) $(SERVER_INCLUDES) $(CORE_INCLUDES)

#
# Dependencies.
#

PROJECT_MAK_DEPS= $(PROJECT_DIR)\MAKEFILE \
 		  $(PROJECT_DIR)\MAKEFLAG.MAK

PROJECT_INC_DEPS= $(PROJECT_DIR)\*.h \
                  $(PROJECT_DIR)\..\INCLUDE\*.h

ALL_DEPS        = $(PROJECT_INC_DEPS) $(PROJECT_MAK_DEPS) $(SERVER_INC_DEPS) $(SERVER_MAK_DEPS) $(CORE_INC_DEPS) $(CORE_MAK_DEPS)

#
# Uncomment -AcmFlags in order to build all 4 variations of module
# in one step: Release/Debug + NPW/PW
#

ACM_PE2BINx_FLAGS = -AcmRevision -AcmFlags $(ACM_PE2BINx_FLAGS)

!if "$(ACM_USER_REV)"!=""

ACM_PE2BINx_FLAGS = -AcmUserRev:$(ACM_USER_REV) $(ACM_PE2BINx_FLAGS)

!endif

CORE_OBJECTS   = $(SERVER_LIB_DIR)\$(SERVER_LIB) $(LIB_DIR)\$(CORE_LIB) $(EXTRA_OBJECTS)

CORE64_OBJECTS = $(SERVER_LIB_DIR)\$(SERVER64_LIB)

!if EXIST($(LIB_DIR)\$(CORE64_LIB))

CORE64_OBJECTS=$(CORE64_OBJECTS) $(LIB_DIR)\$(CORE64_LIB)

!endif

#*****************************************************************************
#
# This is rest of actual build targets after all pre-build steps. ACM_PASS2
# target asllows to put into build newly generated text_alignment_padding.inc
# file
#
#*****************************************************************************
# Sighting #3864887  (0KB .text alignment)
$(OBJ_DIR)\$(ACM_NAME).exe:  $(OBJECTS32) $(CORE_OBJECTS) $(ALL_DEPS)
        @echo ===== Building local EXE file =====
        $(LINK) $(LNK_FLAGS) $(OBJECTS32) $(CORE_OBJECTS)
	@cd $(OBJ_DIR)
        $(ACM_PE2BINx) $(OBJ_DIR)\$(ACM_NAME).exe -TEXT_Alignment:$(TEXT_ALIGNMENT)
	@cd $(PROJECT_DIR)
        @echo TEXT_ALIGNMENT=$(TEXT_ALIGNMENT)
!if "$(TEXT_ALIGNMENT)"!="0KB"
        @echo ===== Preparing PASS2 =====
        @del $(OBJ_DIR)\Stack.obj
        @del $(OBJ_DIR)\$(ACM_NAME).exe
        $(NMAKE) ACM_PASS2
!endif
        $(DUMPBIN) /all /disasm $(OBJ_DIR)\$(ACM_NAME).exe > $(OBJ_DIR)\db_$(ACM_NAME).txt
		@echo putConsts
		py -3 putPseamldr.py $(OBJ_DIR)\_SEAMLDR_$(BLD)_$(SFX).map $(OBJ_DIR)\_SEAMLDR_$(BLD)_$(SFX).exe pseamldr.so pseamldr.so.consts

ACM_PASS2:  $(ALL_DEPS) $(OBJECTS32)
        @echo ===== Building local EXE file PASS2 =====
        $(LINK) $(LNK_FLAGS) $(OBJECTS32) $(CORE_OBJECTS)

!if "$(MKF_64BIT_CODE_SUPPORT)"=="1"
$(OBJ_DIR)\$(ACM_NAME).bin: $(HEADERS) $(OBJ_DIR)\$(ACM_NAME).exe $(OBJ_DIR)\$(ACM64_NAME).exe $(ALL_DEPS)
!else
$(OBJ_DIR)\$(ACM_NAME).bin: $(HEADERS) $(OBJ_DIR)\$(ACM_NAME).exe $(ALL_DEPS)
!endif
        @echo ===== Building local BIN file =====
        cd $(OBJ_DIR)
!if "$(MKF_64BIT_CODE_SUPPORT)"=="1"
        $(ACM_PE2BINx) $(ACM_PE2BINx_FLAGS) $*.exe $*.bin -EXE64bit:$(OBJ_DIR)\$(ACM64_NAME).exe
        @$(ACM_PE2BINx) $(ACM_PE2BINx_FLAGS) $*.exe $*.bin -EXE64bit:$(OBJ_DIR)\$(ACM64_NAME).exe > $(OBJ_DIR)\build64.log
!else
        $(ACM_PE2BINx) $(ACM_PE2BINx_FLAGS) $*.exe $*.bin
        @$(ACM_PE2BINx) $(ACM_PE2BINx_FLAGS) $*.exe $*.bin > $(OBJ_DIR)\build.log
!endif
        @$(REHASH) $(REHASH_FLAGS) $*.*.bin > $*.base64
        cd $(PROJECT_DIR)		
#
# MKF_64BIT_CODE_SUPPORT switch is not needed - not referenced target is not built
#
$(OBJ_DIR)\$(ACM64_NAME).exe:  $(ALL_DEPS) $(OBJECTS64) $(CORE64_OBJECTS)
        @echo ===== Building local 64 EXE file =====
        $(LINK64) $(LNK64_FLAGS) $(OBJECTS64) $(CORE64_OBJECTS)
		py -3 clearTimestamp.py $(OBJ_DIR)\_SEAMLDR64_$(BLD)_$(SFX).exe
        $(DUMPBIN) /all /disasm $@ > $(OBJ_DIR)\db_$(*B).txt					
		
#*****************************************************************************
#
# Clean targets.
#
#*****************************************************************************
clean:
        @echo CLEANING $(OBJ_DIR)
        -rd /S /Q $(OBJ_DIR)
!if DEFINED(EXTRA_OBJ_DIR)
        @echo CLEANING $(EXTRA_OBJ_DIR)
        -rd /S /Q $(EXTRA_OBJ_DIR)
!endif

cleanall: clean
        @echo CLEANING $(SERVER_LIB_DIR)
        -rd /S /Q $(SERVER_LIB_DIR)
        @echo CLEANING $(LIB_DIR)
        -rd /S /Q $(LIB_DIR)

