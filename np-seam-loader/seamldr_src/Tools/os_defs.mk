

nullstring=
space := $(null) #

# Helpful macro to recursively find files in subdirectories
rwildcard=$(strip $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)))


ifdef ComSpec
    DOS_CMD=$(ComSpec) /C
endif
ifdef COMSPEC
    DOS_CMD=$(COMSPEC) /C
endif

ifneq ($(DOS_CMD),)
    O_SYS = windows
else
    # We're running under Unix (or Linux)
    O_SYS = linux
endif

ifeq "$(O_SYS)" "windows"
        export SHELL := cmd.exe
	PS        = \$(nullstring)
	DOS_CMD  ?= $(ComSpec) /C
	ASH_PATH  = c:/AshlingOpellaXDforARC/opxdarc
	RM        = $(DOS_CMD) del /Q /F
	RMD       = $(DOS_CMD) rmdir /S /Q
	REN       = $(DOS_CMD) ren
	ECHO      = $(DOS_CMD) echo
	CP        = copy
	MKD       = mkdir
	FixPath   = $(subst /,\,$1)
	DIRCMD   := dir /s /b

	IFNOTEXISTDIR    = if not exist #
	ENDIFNOTEXISTDIR = $(space)
endif

ifeq ($(SHELL),/bin/bash)
	PS        = /$(nullstring)
	ASH_PATH  = /opt/opellaxdforarc/opxdarc.so
	RM        = rm -f
	RMD       = rm -f -R
	REN       = mv
	ECHO      = echo
	CP        = cp
	MKD       = mkdir -p
	FixPath   = $1
#   DIRCMD   := find Core -type f | grep .c

	IFNOTEXISTDIR=[-d $(space)
	ENDIFNOTEXISTDIR=$(space)] ||

endif


