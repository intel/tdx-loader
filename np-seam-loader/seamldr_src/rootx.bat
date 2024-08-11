@echo on

set ACM_ROOT_DIR=%CD%
if %ACM_ROOT_DIR:~-1%==\ set ACM_ROOT_DIR=%ACM_ROOT_DIR:~0,-1%

set ACM_TOOLS_PATH=%ACM_ROOT_DIR%\acmtools

REM Use Visual Studio 2013 by default
set VC_TOOLS_PATH=C:\"Program Files (x86)"\"Microsoft Visual Studio 14.0"\VC\bin
set VC_TOOLS64_PATH="C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\amd64"
set VCVARS_PATH=C:\"Program Files (x86)"\"Microsoft Visual Studio 14.0"\VC\bin

if not exist %VC_TOOLS_PATH% (
    set VC_TOOLS_PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Tools\MSVC\14.16.27023\bin\Hostx86\x86"
    set VC_TOOLS64_PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64"
    set VCVARS_PATH=C:\"Program Files (x86)"\"Microsoft Visual Studio"\2017\Professional\VC\Auxiliary\Build
)

set VC2008=0

REM If VC2008 is set, then use Visual Studio 2008 tools in the acmtools folder
if %VC2008%==1 (
  set VC_TOOLS_PATH=c:\acmtools
  set VC_TOOLS64_PATH=c:\acmtools\x86_amd64
)

if defined once goto :EOF
set once=1
call %VCVARS_PATH%\vcvars32.bat"
rem set PATH=%VC_TOOLS_PATH%;%VC_TOOLS64_PATH%;%PATH%
