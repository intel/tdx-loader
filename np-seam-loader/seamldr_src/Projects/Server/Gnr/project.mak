# INTEL CONFIDENTIAL
# Copyright 2021 Intel Corporation

# Project-specific variables here
#
ifeq ($(cpu), srf)
PROJECT      := SRF
else ifeq ($(cpu), SRF)
PROJECT      := SRF
else
PROJECT      := GNR
endif
PROJECT_DIR  := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
ACM_ROOT_DIR := $(realpath $(PROJECT_DIR)/../../..)

# TODO: Add additional project-specific vars here

# Include the main makefile that does all the actual making
#
include $(ACM_ROOT_DIR)/Projects/GnuMakefile
