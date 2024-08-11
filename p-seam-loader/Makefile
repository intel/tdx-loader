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

include src_defs.mk
include compiler_defs.mk

.PHONY: default all clean test

MSG := echo -e

ifndef RELEASE
TARGET = $(DEBUG_TARGET)
TARGET_CONSTSFILE := $(DEBUG_TARGET_CONSTS)
OBJS_DIR = $(DEBUG_DIR)/$(OBJ_DIR_NAME)
else
TARGET = $(RELEASE_TARGET)
TARGET_CONSTSFILE := $(RELEASE_TARGET_CONSTS)
OBJS_DIR = $(RELEASE_DIR)/$(OBJ_DIR_NAME)
endif

CONSTGEN_BIN := $(OBJS_DIR)/constants_generator.out

C_OBJECTS = $(foreach obj,$(__C_OBJECTS),$(OBJS_DIR)/$(obj))
ASM_OBJECTS = $(foreach obj,$(__ASM_OBJECTS),$(OBJS_DIR)/$(obj))
OBJECTS = $(C_OBJECTS) $(ASM_OBJECTS)
DEPS := $(OBJECTS:.o=.d)

CFLAGS += -D__FILENAME__=\"$(lastword $(subst /, ,$<))\"

CRYPTO_OBJECTS := $(CRYPTO_LIB_PATH)/$(CRYPTO_LIB_FILENAME)

default: $(TARGET)
all: default

$(CRYPTO_OBJECTS): $(CRYPTO_LIB_SRC_DIR)
	cd $(CRYPTO_LIB_MAIN_DIR); \
	CC=$(CC) CXX=$(CXX) cmake CMakeLists.txt -B_build -DARCH=intel64 -DMERGED_BLD:BOOL=off -DPLATFORM_LIST="y8"; \
	cd _build; \
	make -j8 ippcp_s_y8

$(C_OBJECTS): $(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDE_PATH) $(CFLAGS) -c $< -o $@

$(ASM_OBJECTS): $(OBJS_DIR)/%.o: %.S
	@mkdir -p $(@D)
	$(CC) $(INCLUDE_PATH) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(CRYPTO_OBJECTS) $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -L$(CRYPTO_LIB_PATH) $(CRYPTO_LIB) -o $@
	$(CC) $(CONSTGEN_C) $(CFLAGS) $(INCLUDE_PATH) -o $(CONSTGEN_BIN)
ifndef DO_NOT_STRIP
ifdef RELEASE
	strip -s $(RELEASE_TARGET)
endif
endif
	#The padding operation must be the last change made to the binary 
	$(MSG) "Padding Binary to page size granularity"
	python $(PAD_BINARY_PY) $@
	#Generate consts
	$(eval size := stat -c %s $@)
	$(eval entry_point := readelf -h $@ | grep "Entry point" | cut -d' ' -f20)
	$(CONSTGEN_BIN) $(TARGET_CONSTSFILE) `$(size)` `$(entry_point)`
	
clean:
	rm -rf $(DEBUG_DIR)/$(OBJ_DIR_NAME)
	rm -rf $(RELEASE_DIR)/$(OBJ_DIR_NAME)
	rm -f $(DEBUG_TARGET)
	rm -f $(RELEASE_TARGET)
	rm -f $(DEBUG_TARGET_CONSTS)
	rm -f $(RELEASE_TARGET_CONSTS)
	rm -f $(CONSTGEN_BIN)
	
cleanall:
	rm -rf $(CRYPTO_LIB_MAIN_DIR)/_build
	make clean
	
help:
	$(MSG) "\nP-SEAMLDR Module Makefile    - available build flag options (use with regular 'make' command):"
	$(MSG) "\tRELEASE=1                    - builds a release flavor of the library."
	$(MSG) "\nAdditional make targets:"
	$(MSG) "\tmake clean                   - cleans everything except crypto library."
	$(MSG) "\tmake cleanall                - cleans everything including the crypto library."

	
-include $(DEPS)

