@ECHO off
set ACM_USER_REV=%1

rem -----------------------------------------------------------------------------
rem
rem BUILD Options
rem
echo.
echo     Select BUILD Option:
echo.
echo     MAKE: %~n0%~x0 optimization settings override MAKEFLAG.MAK settings.
echo     1 - ENG_NT_OD        : engineering no trace optimization disabled.
echo     2 - ENG_TR_OD        : engineering with trace optimization disabled
echo     3 - ENG_TR_O1        : production with trace optimized.
echo     4 - REL_NT_O1        : production no trace optimized.
echo.
echo     Production signing: ENG_TR_O1 (DBG,NPW) + REL_NT_O1 (PW,NPW)
echo     5 - Release compound : All NPW and PW combinations at once.
echo.
echo     CLEAN: project specific and full
echo     6 - ENG_NT_CLEAN     : ENG_NT project clean
echo     7 - ENG_TR_CLEAN     : ENG_TR project clean
echo     8 - REL_NT_CLEAN     : REL_NT project clean
echo     9 - ENG_NT_CLEANALL  : ENG_NT full clean
echo     A - ENG_TR_CLEANALL  : ENG_TR full clean
echo     B - REL_NT_CLEANALL  : REL_NT full clean
echo.
echo     Q - Quit
echo.
echo.Select:
@choice /c:123456789ABQ /N
if errorlevel 12 goto :EOF
if errorlevel 11  goto REL_NT_CLEANALL
if errorlevel 10  goto ENG_TR_CLEANALL
if errorlevel 9  goto ENG_NT_CLEANALL
if errorlevel 8  goto REL_NT_CLEAN
if errorlevel 7  goto ENG_TR_CLEAN
if errorlevel 6  goto ENG_NT_CLEAN
if errorlevel 5  goto REL_COMPOUND
if errorlevel 4 goto REL_NT_O1
if errorlevel 3 goto ENG_TR_O1
if errorlevel 2 goto ENG_TR_OD
if errorlevel 1 goto ENG_NT_OD


rem -----------------------------------------------------------------------------
rem BUILD commands
rem
rem All commands below can include option for partial disabling of
rem optimisation in the form: <FOLDER_NAME>_CL_FLAGS=/Od
rem For instance: COMBIOSAC_CL_FLAGS=/Od. Optimisation will disabled for
rem named folder.

rem -----------------------------------------------------------------------------
rem Option 1
rem

:ENG_NT_OD
set ALL_CL_FLAGS=/Od

call BLDX ENG_NT OD
goto :EOF

rem -----------------------------------------------------------------------------
rem Option 2
rem
:ENG_TR_OD
set ALL_CL_FLAGS=/Od

call BLDX ENG_TR OD
goto :EOF

rem -----------------------------------------------------------------------------
rem Option 3
rem
:ENG_TR_O1
set ALL_CL_FLAGS=
rem set COMBIOSAC_CL_FLAGS=/Od
rem set COMBTG_CL_FLAGS=/Od
rem set COMMON_CL_FLAGS=/Od
rem set COMSINIT_CL_FLAGS=/Od
rem set CRYPTO_CL_FLAGS=/Od
rem set INTERNAL_CL_FLAGS=/Od
rem set HASH_CL_FLAGS=/Od
rem set IPP_CL_FLAGS=/Od
rem set LCP_CL_FLAGS=/Od
rem set PCI_CL_FLAGS=/Od
rem set RANGES_CL_FLAGS=/Od
rem set TPM_CL_FLAGS=/Od
rem set INTERFACECRB_CL_FLAGS=/Od
rem set INTERFACEFIFO_CL_FLAGS=/Od
rem set TPM12_CL_FLAGS=/Od
rem set TPM20_CL_FLAGS=/Od
rem set TPM20LIB_CL_FLAGS=/Od
rem set TRACE_CL_FLAGS=/Od
rem set SERIAL_CL_FLAGS=/Od
rem set USB_CL_FLAGS=/Od
rem set LOCAL_CL_FLAGS=/Od
rem set COMMON64_CL_FLAGS=/Od
rem set COMSINIT_CL_FLAGS=/Od

call BLDX ENG_TR O1
goto :EOF

rem -----------------------------------------------------------------------------
rem Option 4
rem
:REL_NT_O1
set ALL_CL_FLAGS=
rem set COMBIOSAC_CL_FLAGS=/Od
rem set COMBTG_CL_FLAGS=/Od
rem set COMMON_CL_FLAGS=/Od
rem set COMSINIT_CL_FLAGS=/Od
rem set CRYPTO_CL_FLAGS=/Od
rem set INTERNAL_CL_FLAGS=/Od
rem set HASH_CL_FLAGS=/Od
rem set IPP_CL_FLAGS=/Od
rem set LCP_CL_FLAGS=/Od
rem set PCI_CL_FLAGS=/Od
rem set RANGES_CL_FLAGS=/Od
rem set TPM_CL_FLAGS=/Od
rem set INTERFACECRB_CL_FLAGS=/Od
rem set INTERFACEFIFO_CL_FLAGS=/Od
rem set TPM12_CL_FLAGS=/Od
rem set TPM20_CL_FLAGS=/Od
rem set TPM20LIB_CL_FLAGS=/Od
rem set TRACE_CL_FLAGS=/Od
rem set SERIAL_CL_FLAGS=/Od
rem set USB_CL_FLAGS=/Od
rem set LOCAL_CL_FLAGS=/Od
rem set COMMON64_CL_FLAGS=/Od
rem set COMSINIT_CL_FLAGS=/Od

call BLDX REL_NT O1
goto :EOF

rem -----------------------------------------------------------------------------
rem Option 5
rem
:REL_COMPOUND
set ALL_CL_FLAGS=
call :REL_NT_O1

set ALL_CL_FLAGS=
call :ENG_TR_O1
goto :EOF

rem -----------------------------------------------------------------------------
rem Option 6
rem
:ENG_NT_CLEAN

call    BLDX ENG_NT CLEAN
goto :EOF

rem -----------------------------------------------------------------------------
rem Option 7
rem
:ENG_TR_CLEAN

call    BLDX ENG_TR CLEAN
goto :EOF

rem -----------------------------------------------------------------------------
rem Option 8
rem
:REL_NT_CLEAN

call    BLDX REL_NT CLEAN
goto :EOF

rem -----------------------------------------------------------------------------
rem Option 9
rem
:ENG_NT_CLEANALL

call    BLDX ENG_NT CLEANALL
goto :EOF

rem -----------------------------------------------------------------------------
rem Option A
rem
:ENG_TR_CLEANALL

call    BLDX ENG_TR CLEANALL
goto :EOF

rem -----------------------------------------------------------------------------
rem Option B
rem
:REL_NT_CLEANALL

call    BLDX REL_NT CLEANALL
goto :EOF

