ifndef VCINSTALLDIR
$(info WARNING: The MSVC environment hasn't been set. Setting environment variables manually...)
# Note: The MSFC tools require dirs within the INCLUDE variable be delimted by a semicolon
INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\INCLUDE;C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\ATLMFC\INCLUDE;C:\Program Files (x86)\Windows Kits\10\include\10.0.10240.0\ucrt;C:\Windows Kits\10\Include\10.0.10240.0\ucrt;
PATH += "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\BIN"
export INCLUDE PATH
endif

VC_TOOLS_PATH =   "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin"
VC_TOOLS64_PATH = "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\amd64"


NASM_TOOLS_PATH = $(ACM_TOOLS_PATH)

NASM = $(NASM_TOOLS_PATH)\nasm

CL          = $(VC_TOOLS_PATH)\cl
CL64        = $(VC_TOOLS64_PATH)\cl

ML          = $(VC_TOOLS_PATH)\ml
ML64        = $(VC_TOOLS64_PATH)\ml64

LINK        = $(VC_TOOLS_PATH)\link
LINK64      = $(VC_TOOLS64_PATH)\link

LIB         = $(VC_TOOLS_PATH)\lib
LIB64       = $(VC_TOOLS64_PATH)\lib


DUMPBIN     = $(VC_TOOLS_PATH)\dumpbin

ACM_PE2BIN  = $(ACM_TOOLS_PATH)\acm_pe2bin
ACM_PE2BINx = $(ACM_TOOLS_PATH)\acm_pe2binx
H2INCX      = $(ACM_TOOLS_PATH)\h2incx
REHASH      = $(ACM_TOOLS_PATH)\rehash