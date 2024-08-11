@echo off

set ACM_ROOT_DIR=%CD%
if %ACM_ROOT_DIR:~-1%==\ set ACM_ROOT_DIR=%ACM_ROOT_DIR:~0,-1%

set TOOLS_PATH=c:\acmtools
set TOOLS64_PATH=c:\acmtools\x86_amd64

set ADDTOPATH=

echo "%PATH%;" | find /C /I "%TOOLS_PATH%;" >nul

if %ERRORLEVEL% NEQ 0 (
  set ADDTOPATH=%TOOLS_PATH%;%TOOLS64_PATH%;
)

set PATH=%ADDTOPATH%%PATH%
