// Copyright (C) 2023 Intel Corporation                                          
//                                                                               
// Permission is hereby granted, free of charge, to any person obtaining a copy  
// of this software and associated documentation files (the "Software"),         
// to deal in the Software without restriction, including without limitation     
// the rights to use, copy, modify, merge, publish, distribute, sublicense,      
// and/or sell copies of the Software, and to permit persons to whom             
// the Software is furnished to do so, subject to the following conditions:      
//                                                                               
// The above copyright notice and this permission notice shall be included       
// in all copies or substantial portions of the Software.                        
//                                                                               
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS       
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL      
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES             
// OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE            
// OR OTHER DEALINGS IN THE SOFTWARE.                                            
//                                                                               
// SPDX-License-Identifier: MIT
/*****************************************************************************
 **
 **   Copyright (C) 2015-2021 Intel Corporation. All rights reserved.
 **
 **  The information and source code contained herein is the exclusive
 **  property of Intel Corporation and may not be disclosed, examined
 **  or reproduced in whole or in part without explicit written authorization
 **  from the company.
 **
 *****************************************************************************/
/******************************************************************************
 *  Filename:   PE2BINx.H (for SKL and newer projects)                        *
 *****************************************************************************/

#include                <windows.h>
#include                <stdio.h>
#include                <time.h>
#include                <fileapi.h>
#include                <intrin.h>
#include                <uchar.h>

#pragma warning(disable : 4996)

#define                 MAGIC_PE32_0x10b      0x10b		// PE32  (IMAGE_NT_OPTIONAL_HDR32_MAGIC)
#define                 MAGIC_PE32Plus_0x20b  0x20b		// PE32+ (IMAGE_NT_OPTIONAL_HDR64_MAGIC)

// PE32
PIMAGE_DOS_HEADER         pEXE32_DOS_Hdr;
PIMAGE_NT_HEADERS         pEXE32_NT_Hdr;
PIMAGE_FILE_HEADER        pEXE32_File_Hdr;
PIMAGE_OPTIONAL_HEADER    pEXE32_Opt_Hdr;	// 32bit
PIMAGE_SECTION_HEADER     pEXE32_SecHdr_Start, pEXE32_Sec_CODE32, pEXE32_Sec_EDATA32, pEXE32_Sec_rdata, pEXE32_Sec_reloc;
PIMAGE_DEBUG_DIRECTORY    pEXE32_Deb_Dir;

DWORD                   PE32_Opt_Hdr__SectionAlignment;
DWORD                   PE32_Opt_Hdr__ImageBase;
DWORD                   PE32_Opt_Hdr__SizeOfImage;
DWORD                   PE32_Opt_Hdr__NumberOfRvaAndSizes;
DWORD                   PE32_Opt_Hdr__DIRECTORY_ENTRY_DEBUG__Size;
DWORD                   PE32_Opt_Hdr__BaseOfCode;
DWORD                   DebugDirectory32_RVA, DebugDirectory32_Size; DebugDirectory32_PointerToRawData=0;

// PE32+
PIMAGE_DOS_HEADER         pEXE64_DOS_Hdr;
PIMAGE_NT_HEADERS64       pEXE64_NT_Hdr;
PIMAGE_FILE_HEADER        pEXE64_File_Hdr;
PIMAGE_OPTIONAL_HEADER64  pEXE64_Opt_Hdr;   // 64bit
PIMAGE_SECTION_HEADER     pEXE64_SecHdr_Start, pEXE64_Sec_rdata, pEXE64_Sec_reloc;
PIMAGE_DEBUG_DIRECTORY    pEXE64_Deb_Dir;

DWORD                   PE64_Opt_Hdr__SectionAlignment;
DWORDLONG               PE64_Opt_Hdr__ImageBase;
DWORD                   PE64_Opt_Hdr__SizeOfImage;
DWORD                   PE64_Opt_Hdr__NumberOfRvaAndSizes;
DWORD                   PE64_Opt_Hdr__DIRECTORY_ENTRY_DEBUG__Size;
DWORD                   PE64_Opt_Hdr__BaseOfCode;
DWORD                   DebugDirectory64_RVA, DebugDirectory64_Size; DebugDirectory64_PointerToRawData=0;


char *SzRelocTypes[] =  {"ABSOLUTE","HIGH","LOW","HIGHLOW","HIGHADJ","MIPS_JMPADDR","SECTION","REL32","MIPS_JMPADDR16","IA64_IMM64","DIR64","HIGH3ADJ"};
LPSTR                   pEXE32_PDB_FName, pEXE64_PDB_FName;
errno_t                 err;

HANDLE                  EXE32_fh;
HANDLE                  EXE32_fm;
LPVOID                  EXE32_fp;
FILE                   *BIN32_fh;
FILE                   *ITP32_LdCmd_fh;
LPSTR                   ITP32_LdCmd_file="ACM_LoadNocode.itp";
FILE                   *ITPII_LdCmd32_fh;
LPSTR                   ITPII_LdCmd32_file="ACM_LoadNocode.py";
FILE                   *SIMICS_LdCmd_fh;
LPSTR                   SIMICS_LdCmd_BIOSAC_file="ACM_Simics.py";

HANDLE                  EXE64_fh;
HANDLE                  EXE64_fm;
LPVOID                  EXE64_fp;
FILE                   *ITP64_LdCmd_fh;
LPSTR                   ITP64_LdCmd_file="ACM_LoadNocode64.itp";
FILE                   *ITPII_LdCmd64_fh;
LPSTR                   ITPII_LdCmd64_file="ACM_LoadNocode64.py";

#define                 ADDR(A, operator, B)    ((DWORDLONG)A operator (DWORDLONG)B)
int                     ParseCMD(int, char **);
int                     OpenFiles(LPSTR, LPSTR, LPSTR);
int                     CloseFiles(void);
int                     PE2Bin(void);
int                     DumpRawSection(boolean, LPVOID, PIMAGE_SECTION_HEADER, unsigned, DWORD);
void                    DumpBinary(PBYTE, DWORD, FILE *);
PIMAGE_SECTION_HEADER   FindSecHdr(LPSTR, WORD, PIMAGE_SECTION_HEADER);
int                     FixUpRelocations(void);
int                     ITPCmd_Aligment(void);
int                     OpenEXE32_tmp(LPSTR EXE32_file);
int                     ComputeUpdateTextAligmentSize(void);
int                     ACMsToggleFlagsBits(void);
int                     AcmFileAlignment(void);
int                     GetAcmModuleOffset(void);
int                     ITPCmdFile(void);
int                     CheckAcmHeader(FILE *);
int                     CheckAcmInfoTable(FILE *);
void                    GetValueAtOffset(FILE *, DWORD, DWORD *, size_t, int, int);
UINT8                   *FindInMem(const void *buffer, size_t buff_size, const void *sub_buffer, size_t sub_size);
boolean                 fileExists(const char *path);
int                     HashEvScrtmVersion(FILE *fp);
boolean                 Hex2Utf16(BYTE *in, char16_t *out);

#define                 NUM_ARG     2
char                    Arg[NUM_ARG][257];          // Arguments after parsed (256 charaters max)
char                    Arg1_no_bin[257];           // Argument 1 with trailing .bin (if exist) removed
char                    EXE64FName[257];            // EXE64 Argument after parsed (256 charaters max)
char                    TextPaddingString[257];	    // TextPaddingString
boolean                 EXE64FilePresentFlag=FALSE;
boolean                 TEXT_AlignmentFlag=FALSE;
boolean                 AcmUserRevFlag=FALSE;
char                    EXE32_tmp[]="_tmp_32_.___";
char                    EXE64_tmp[]="_tmp_64_.___";
char                    AcmUserRev[]="yyyymmdd";
int                     i, j;
DWORD                   EDATA32_BASE=0, TEXT32_BASE=0, EDATA32_BASE_ORG=0;
DWORD                   TEXT64_BASE=0;
//----------------------------------------0-------1--------2----------3----4----5----6----7----8----9-------10---11---12---13---14---15-------------------------------------
char                    *szAcmType[] = { "BIOS", "SINIT", "STARTUP", "?", "?", "?", "?", "?", "?", "RACM", "?", "?", "?", "?", "?", "?" };
//-------------------------------------------------0-------1--------2----------3----4----5----6----7----8----9-------10---11---12---13---14---15-------------------------------------
char                    *szAcmTypeLowerCase[] = { "bios", "sinit", "startup", "?", "?", "?", "?", "?", "?", "RACM", "?", "?", "?", "?", "?", "?" };

#define                 VERSION "10.30"
boolean                 HelpCMD=FALSE;
boolean                 Exe64bitFile=TRUE;
boolean                 AcmFlags=FALSE;
boolean                 AcmRevision=FALSE;
boolean                 AcmSize2N=FALSE;
boolean                 Verbose = FALSE;
boolean                 SCRTMIntegrity = FALSE;
char                    HelpMSG[] = 
    "\n"
    "      SYNTAX:  ACM_PE2BINx   <Input>  <Output>  <Options>\n"
    "     example:  ACM_PE2BINx   BIOSAC.exe   BIOSAC.bin  -EXE64bit:BIOSAC64.exe  -AcmRevision  -AcmSize:112KB\n"
    "\n\n\n"
    "       Input:  <EXE_file>  -  PE/COFF executable ACM file\n"
	  "\n"
    "      Output:  <BIN_file>  -  AC Module image file to be generated\n"
	  "                              (ACM_LoadNocode[64].py  - python scripts will also be generated for ITPII PDT source debug)\n"
	  "\n"
    "      Options: Optional switches supported:\n"
    "                                \"-EXE64bit:filename\"                   - to also process 64bit exe file\n"
    "                                \"-AcmRevision\"                         - to overwrite ACMRevision field of ACM header with EXE date\n"
    "                                \"-AcmUserRev:<yyyymmdd>\"               - to overwrite ACMRevision field of ACM header with user specified date\n"
    "                                \"-AcmFlags\"                            - to generate DBG, NPW & PW ACM modules with corresponding ACM Flags\n"
    "                                \"-TEXT_Alignment:0KB|1KB|4KB\"          - to set alignment (0KB/1KB/4KB) for .text section\n"
    "                                \"-AcmSize:<UserSize>|2N|Set\"           - to set ACM size.  See Notes below for details\n"
	"                                \"-Verbose\"                             - to enable diagnostic output\n"
    "                                \"-SCRTMIntegrity\" -                    - to hash ACM creation date || SVN number and save it in the binary\n"
	  "\n\n"
	  "       Notes:\n"
	  "               \"-AcmFlags\" - If ACM_Version[1:0]==11b, no NPW module produced.  Otherwise, all the following 3 modules will be produced:\n"
	  "                       PW=Production_Worthy;  NPN=Production_NPW;   DBG=Debug.\n"
	  "\n"
	  "               \"-AcmUserRev:<yyyymmdd>\" overrides \"-AcmRevision\" switch.\n"
	  "                   Expected inputs:    yyyy: 2014-2099,   mm: 1-12,   dd: 1-31\n"  
	  "                   For example: \"-AcmUserRev:20141231\" will update ACMRevision field of ACM header with 20141231 value.\n"
	  "\n"
	  "               Default maximum ACM size is 256KB.\n"
	  "\n"
    "               \"-AcmSize:<UserSize>|2N|Set\" switch is for controlling ACM size. Without this switch, default size is 64B multiple.\n"
    "                     <UserSize> - user specified ACM size (tool may pad size to 64B multiple).\n"
    "                                  Examples for 112KB in KB, Hex (bytes) or Decimal (bytes):\n"
    "                                           112KB  or  0x1C000  or  114688\n"
    "                         2N   -  2^N ACM size:\n"
    "                                     1B      - 4KB     (sized to 4KB)\n"
    "                                     4KB+1   - 8KB     (sized to 8KB)\n"
    "                                     8KB+1   - 16KB    (sized to 16KB)\n"
    "                                     16KB+1  - 32KB    (sized to 32KB)\n"
    "                                     32KB+1  - 64KB    (sized to 64KB)\n"
    "                                     64KB+1  - 128KB   (sized to 128KB)\n"
    "                                     128KB+1 - 256KB   (sized to 256KB)\n"
    "                         Set  -  Selected sizes (coverable by 4 or less MTRRs)\n"
    "                                     120KB+1 - 128KB   (sized to 128KB)\n"
    "                                     184KB+1 - 192KB   (sized to 192KB)\n"
    "                                     216KB+1 - 224KB   (sized to 224KB)\n"
    "                                     232KB+1 – 240KB   (sized to 240KB)\n"
    "                                     240KB+1 – 256KB   (sized to 256KB)\n"
    "                                     All others sized to 64B multiple.\n"
    "               \"-SCRTMIntegrity\" switch controls whether SCRTM integrity measurements will be performed.\n"
    "                                   This reads ACM date and TXT SVN number and hashes them for TPM consumption.\n"
	"\n"
	"-------------------------------------------------------------------------------------\n"
	"\n";

// ACM Header Offsets 
DWORD Header_AcmTypeOffset          = 0x00;
DWORD Header_AcmSubTypeOffset       = 0x02;
DWORD Header_AcmHeaderLenOffset    = 0x04;
DWORD Header_AcmHeaderVersionOffset = 0x08;
DWORD Header_AcmFlagOffset          = 0x0F;
DWORD Header_AcmDateOffset          = 0x14;
DWORD Header_AcmAcmSvnOffset        = 0x1C;
DWORD Header_AcmSeSvnOffset         = 0x1E;
DWORD Header_AcmEntryOffset         = 0x34;
DWORD Header_AcmScratchSizeOffset   = 0x7C;

// ACM Info Table Offsets will be calculated during runtime
DWORD InfoTable_UUID0Offset;
DWORD InfoTable_ChipsetIdListOffset;
DWORD InfoTable_ProcessorIdListOffset;
DWORD InfoTable_TPMInfoListOffset;
DWORD InfoTable_ACMVerInfoTableOffset;

// ACM Module Offsets
DWORD AcmTypeModuleOffset     = 0x10;
DWORD AcmVersionModuleOffset  = 0x24;

// ACM Header Major Versions
#define ACM_VERSION_0 0x0
#define ACM_VERSION_3 0x30000
#define ACM_VERSION_4 0x40000

// These values are calculated based on the ACM specification
#define ACM_HEADER_0_SIZE 0x4C0
#define ACM_HEADER_3_SIZE 0x6C0
#define ACM_HEADER_4_SIZE 0x1C80

// AcmModuleOffset is calculated during runtime
DWORD AcmModuleOffset = 0;

// Stable values in ACM Header defined in MLE DG
const WORD AcmModuleTypeStable = 0x02;
const WORD AcmSubtypeTXTStable = 0x00;
const WORD AcmSubtypeSACMStable = 0x01;
const DWORD HeaderLenLegacyStable = 0xA1; // For ACM header 0.0 (legacy)
const DWORD HeaderLenCBnTStable = 0xE0; // For ACM header 3.0 with CBnT
const DWORD HeaderLenStable = 0x3A0; // For ACM header 4.0 with XMSS support
const DWORD HeaderVersionLegacyStable = ACM_VERSION_0; // bits 31:16 - major 0x0000; bits 15:0 minor 0x0000 - legacy
const DWORD HeaderVersionCBnTStable = ACM_VERSION_3; //bits 31:16 - major 0x0300; bits 15:0 minor 0x0000 - CBnT
const DWORD HeaderVersionStable = ACM_VERSION_4; ////bits 31:16 - major 0x0400; bits 15:0 minor 0x0000 - XMSS support
// Stable values in ACM Info Table:
const DWORD InfoTable_UUID[] = { 0x7FC03AAA, 0x18DB46A7, 0x8F69AC2E, 0x5A7F418D };
const WORD ChipsetID_VendorID = 0x8086;

DWORD AcmStart,stackStart=0, stackEnd=0;
DWORD relocAddrPtr=0, relocAddr, relocCount=0, relocCount32=0, relocCount64=0, relocShortage=0;
int FileLength, FileLength32=0, FileLength64=0;
DWORD Entrypoint64=0, Codestart64=0;
char AcmType;
DWORD TEXT32_PaddingSize=0;
DWORD TEXT_Alignment=0;
char *Align0KB_str="0KB";
char *Align1KB_str="1KB";
char *Align4KB_str="4KB";
char *AcmSize2N_str="2N";
char *AcmSizeSet_str="Set";
int AcmSize_Type=0;
int UserAcmSize=0;
#define TYPE_ACMSIZE2N   1
#define TYPE_ACMSIZESET  2
#define TYPE_ACMSIZEUSER 3
int MaxAcmSize=512*1024;
char AcmVersion;
char AcmSvnNumber;
char AcmSeSvnNumber;
