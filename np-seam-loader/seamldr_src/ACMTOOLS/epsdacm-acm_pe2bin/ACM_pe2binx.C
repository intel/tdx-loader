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
 *  Filename:   ACM_PE2BINx.C  ((for SKL and newer projects)                  *
 *  Function:   1) extracts binary from a firmware PE/COFF executable         *
 *              2) saves ACM realted section to ACM binary file               *
 *  Compiler:   MSVS 12.0                                                     *
 *****************************************************************************/

#include        "ACM_PE2BINx.H"
#include        "Hashing.h"

//---------------------------------------------------------------
// main
//---------------------------------------------------------------
int main (int argc, char *argv[])
{
  printf ("\n-------------------------------------------------------------------------------------\n");
  printf ("ACM_PE2BINx: TXT ACM build tool (PE/COFF EXE -> ACM image), version %s (%s), (for SKL and newer projects)\n", VERSION, __DATE__);
  printf ("Copyright (C) 2015-2021 Intel Corporation (internal use only).  All rights reserved.\n\n");
  
  if (ParseCMD (argc, argv))
  {
    printf (HelpMSG);
    exit (1);
  }
  
  if (HelpCMD)
  {
    printf (HelpMSG);
    return 0;
  }
  
  // Prepare for processing ACM PE32 main file
  if (!CopyFile (Arg[0], EXE32_tmp, FALSE))
  {
    printf ("ERROR: Failed to duplicate %s\n", Arg[0]);
    printf ("-------------------------------------------------------------------------------------\n\n");
    exit (1); 
  }
  
  // Prepare for processing ACM PE32+ 64bit module file
  if (EXE64FilePresentFlag)   {
    if (!CopyFile (EXE64FName, EXE64_tmp, FALSE))
    {
      printf ("ERROR: Failed to duplicate %s\n", EXE64FName);
      printf ("-------------------------------------------------------------------------------------\n\n");
      DeleteFile (EXE32_tmp);
      exit (1); 
    }
  }
  
  // Prepare for processing ACM PE32+ 64bit module file
  if (TEXT_AlignmentFlag)   {
    if (OpenEXE32_tmp (EXE32_tmp))
    {
      printf ("-------------------------------------------------------------------------------------\n\n");
      exit (1);
    }
    
    // Find TEXT_AlignmentSize
    ComputeUpdateTextAligmentSize ();
    
    UnmapViewOfFile (EXE32_fp);
    CloseHandle (EXE32_fm);
    CloseHandle (EXE32_fh);
    DeleteFile (EXE32_tmp);
    
    return 0;
  }
  else
  {
    if (OpenFiles (EXE32_tmp, Arg[1], EXE64_tmp))
    {
      printf ("-------------------------------------------------------------------------------------\n\n");
      exit (1);
    }
    
    if (PE2Bin ())  
    {
      CloseFiles ();
      DeleteFile (Arg[1]);
      printf ("-------------------------------------------------------------------------------------\n\n");
      exit (1); 
    }
  }
  
  CloseFiles ();
  DeleteFile (EXE32_tmp);
  if (EXE64FilePresentFlag) DeleteFile (EXE64_tmp);
  
  if (AcmFlags) 
  {
    if (ACMsToggleFlagsBits ())
    {
      DeleteFile (Arg[1]);
      printf ("-------------------------------------------------------------------------------------\n\n");
      exit (1);
    }
  }
  
  printf ("-------------------------------------------------------------------------------------\n");
  return 0;
}

//---------------------------------------------------------------
// Parsing the command line
//---------------------------------------------------------------
int ParseCMD (int argc, char *argv[])
{
  char    *ptr;
  char    EXE64bit_str[] = "EXE64bit:";              // -EXE64bit: option
  char    TEXT_Padding_str[] = "TEXT_Alignment:";    // -TEXT_Alignment: option
  char    AcmSize_str[] = "AcmSize:";                // -AcmSize: option
  char    AcmUserRev_str[] = "AcmUserRev:";          // -AcmUserRev: option
  char    SCRTMIntegrity_str[] = "SCRTMIntegrity";  // -SCRTMIntegrity: option
  char    *pTmpPtr = NULL;
  int     length1, length2;
  
  j = 0;
  for ( i = 1; i < argc; i++ )
  {
    ptr = argv[i];
    if ((*ptr == '-') || (*ptr == '/'))
    {
      ptr++;
      if ((_stricmp (ptr, "?") == 0) || (_stricmp (ptr, "h") == 0) || (_stricmp (ptr, "help") == 0))
      {
        HelpCMD = TRUE;
        return 0;
      }
      else if (_stricmp (ptr, "AcmFlags") == 0)
      {
        AcmFlags = TRUE;
      }
      else if (_stricmp (ptr, "AcmRevision") == 0)
      {
        AcmRevision = TRUE;
      }
	  else if (_stricmp(ptr, "Verbose") == 0)
	  {
		Verbose = TRUE;
	  }
      else if (_strnicmp (ptr, AcmSize_str, strlen (AcmSize_str)) == 0)
      {
        pTmpPtr = (ptr += strlen (AcmSize_str));
        length1 = strlen (ptr);
        
        if (_strnicmp (pTmpPtr, AcmSize2N_str, strlen (AcmSize2N_str)) == 0)  {
          AcmSize_Type = TYPE_ACMSIZE2N;
		      ptr += strlen (AcmSize2N_str);
		      length2 = strlen (AcmSize2N_str);
        } 
        else if (_strnicmp (pTmpPtr, AcmSizeSet_str, strlen (AcmSizeSet_str)) == 0)   {
          AcmSize_Type = TYPE_ACMSIZESET;
          ptr += strlen (AcmSizeSet_str);
		      length2 = strlen (AcmSizeSet_str);
        }
        else {
          AcmSize_Type = TYPE_ACMSIZEUSER;
		      if ((*pTmpPtr=='0') && ((*(pTmpPtr+1)=='x') || (*(pTmpPtr+1)=='X')))   {

		        pTmpPtr += 2;
			      UserAcmSize = strtoul(pTmpPtr, &ptr, 16);
			      length2 = 2 + (ptr - pTmpPtr);       // 2 for '0x', + length of numeric digits
			      
			    }
			    else {
			      UserAcmSize = strtoul(pTmpPtr, &ptr, 10);
			      length2 = (ptr - pTmpPtr);           // length of numeric digits
			      
			      if (length1 != length2)  {           // might contain KB
               if (_stricmp (ptr, "KB") == 0) {  // Check for KB
                 UserAcmSize *= 1024;
                 length2 += 2;
			         }
			      }
			    }

		      if (ptr == pTmpPtr)   {                // Check for blank input
            printf ("ERROR: incorrect -AcmSize syntax\n");
            return 1;
		      }

		    }

        if (length2 != length1)
	      {
          printf ("ERROR: incorrect -AcmSize syntax\n");
          return 1;
        }

      }
      else if (_strnicmp (ptr, EXE64bit_str, strlen (EXE64bit_str)) == 0)
      {                                                     
        pTmpPtr = ptr + strlen (EXE64bit_str);
        if (*pTmpPtr == '\0')
        {
          printf ("ERROR: valid EXE64bit filename expected (PE32+ ACM module) for -EXE64bit: switch.\n");
          return (1);
        }
        strcpy_s (EXE64FName, strlen (pTmpPtr) + 1, pTmpPtr);
        EXE64FilePresentFlag = TRUE;
      }
      else if (_strnicmp (ptr, AcmUserRev_str, strlen (AcmUserRev_str)) == 0)
      {                                                     
        pTmpPtr = ptr + strlen (AcmUserRev_str);

        if (strlen (pTmpPtr) !=  8)
        {
          printf ("ERROR: expecting \"yyyymmdd\" format for -AcmUserRev: switch.\n");
          return (1);
        }
        strcpy_s (AcmUserRev, strlen (pTmpPtr) + 1, pTmpPtr);
        AcmUserRevFlag = TRUE;
      }
      else if (_strnicmp (ptr, TEXT_Padding_str, strlen (TEXT_Padding_str)) == 0)
      {
        ptr += strlen (TEXT_Padding_str);
        if (_strnicmp (ptr, Align0KB_str, strlen (Align0KB_str)) == 0)
          TEXT_Alignment = 0;
        else if (_strnicmp (ptr, Align1KB_str, strlen (Align1KB_str)) == 0)
          TEXT_Alignment = 1024;
        else if (_strnicmp (ptr, Align4KB_str, strlen (Align4KB_str)) == 0)
          TEXT_Alignment = 4*1024;
        else
        {
          printf ("ERROR: Alignment %s not supported. Expected 0KB/1KB/4KB\n", &argv[i][1]);
          return 1;
        }
        
        TEXT_AlignmentFlag = TRUE;
        pTmpPtr = ptr + strlen (TEXT_Padding_str);
      }
      else if (_strnicmp(ptr, SCRTMIntegrity_str, strlen(SCRTMIntegrity_str)) == 0) {
          SCRTMIntegrity = TRUE;
      }
      else
      {
        printf ("ERROR: Unsupported switch \"-%s\"\n", &argv[i][1]);
        return 1;
      }
    }
    else
    {
      if (j < NUM_ARG) strcpy_s (Arg[j++], strlen (argv[i]) + 1, argv[i]);
      else
      {
        printf ("ERROR: too many arguments\n");
        return 1;
      }
    }
  }
  if ((!TEXT_AlignmentFlag) && (j != NUM_ARG))
  {
    printf ("ERROR: too few arguments\n");
    return 1;
  }
  
  return 0;
}

//---------------------------------------------------------------
// Open global files
//---------------------------------------------------------------
int OpenFiles (LPSTR EXE32_file, LPSTR BIN_file, LPSTR EXE64_file)
{
  EXE32_fh = CreateFile (EXE32_file, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL,
               OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
  
  if (EXE32_fh == INVALID_HANDLE_VALUE)
  {
    printf ("Couldn't open file: %s\n", EXE32_file);
    return 1;
  }
  
  EXE32_fm = CreateFileMapping (EXE32_fh, NULL, PAGE_READWRITE, 0, 0, NULL);
  if (EXE32_fm == 0)
  {
    CloseHandle (EXE32_fh);
    printf ("Couldn't open file mapping: CreateFileMapping()\n");
    return 1;
  }
  
  EXE32_fp = MapViewOfFile (EXE32_fm, FILE_MAP_ALL_ACCESS, 0, 0, 0);
  if (EXE32_fp == 0)
  {
    CloseHandle (EXE32_fm);
    CloseHandle (EXE32_fh);
    printf ("Couldn't map view of file: MapViewOfFile()\n");
    return 1;
  }
  
  if (fopen_s (&BIN32_fh, BIN_file, "w+b") != (errno_t) NULL)
  {
    UnmapViewOfFile (EXE32_fp);
    CloseHandle (EXE32_fm);
    CloseHandle (EXE32_fh);
    printf ("Couldn't open file: %s\n", BIN_file);
    return 1;
  }
  
  if (fopen_s (&ITP32_LdCmd_fh, ITP32_LdCmd_file, "w+b") != (errno_t) NULL)
  {
    UnmapViewOfFile (EXE32_fp);
    CloseHandle (EXE32_fm);
    CloseHandle (EXE32_fh);
    fclose (BIN32_fh);
    printf ("Couldn't open file: %s\n", ITP32_LdCmd_file);
    return 1;
  }
  
  if (fopen_s (&ITPII_LdCmd32_fh, ITPII_LdCmd32_file, "w+b") != (errno_t) NULL)
  {
    UnmapViewOfFile (EXE32_fp);
    CloseHandle (EXE32_fm);
    CloseHandle (EXE32_fh);
    fclose (BIN32_fh);
    fclose (ITP32_LdCmd_fh);
    printf ("Couldn't open file: %s\n", ITPII_LdCmd32_file);
    return 1;
  }

  if (fopen_s (&SIMICS_LdCmd_fh, SIMICS_LdCmd_BIOSAC_file, "w+b") != (errno_t) NULL)
  {
    UnmapViewOfFile (EXE32_fp);
    CloseHandle (EXE32_fm);
    CloseHandle (EXE32_fh);
    fclose (BIN32_fh);
    fclose (ITP32_LdCmd_fh);
    fclose (ITPII_LdCmd32_fh);
    printf ("Couldn't open file: %s\n", ITPII_LdCmd32_file);
    return 1;
  }

  if (EXE64FilePresentFlag)   
  {
    EXE64_fh = CreateFile (EXE64_file, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL,
                 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    
    if (EXE64_fh == INVALID_HANDLE_VALUE)
    {
      UnmapViewOfFile (EXE32_fp);
      CloseHandle (EXE32_fm);
      CloseHandle (EXE32_fh);
      fclose (BIN32_fh);
      fclose (ITP32_LdCmd_fh);
      fclose (ITPII_LdCmd32_fh);
      fclose (SIMICS_LdCmd_fh);
      printf ("Couldn't open file: %s\n", EXE64_file);
      return 1;
    }
    
    EXE64_fm = CreateFileMapping (EXE64_fh, NULL, PAGE_READWRITE, 0, 0, NULL);
    if (EXE64_fm == 0)
    {
      CloseHandle (EXE64_fh);
      UnmapViewOfFile (EXE32_fp);
      CloseHandle (EXE32_fm);
      CloseHandle (EXE32_fh);
      fclose (BIN32_fh);
      fclose (ITP32_LdCmd_fh);
      fclose (ITPII_LdCmd32_fh);
      fclose (SIMICS_LdCmd_fh);
      printf ("Couldn't open file mapping: CreateFileMapping()\n");
      return 1;
    }
    
    EXE64_fp = MapViewOfFile (EXE64_fm, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    if (EXE64_fp == 0)
    {
      CloseHandle (EXE64_fm);
      CloseHandle (EXE64_fh);
      UnmapViewOfFile (EXE32_fp);
      CloseHandle (EXE32_fm);
      CloseHandle (EXE32_fh);
      fclose (BIN32_fh);
      fclose (ITP32_LdCmd_fh);
      fclose (ITPII_LdCmd32_fh);
      fclose (SIMICS_LdCmd_fh);
      printf ("Couldn't map view of file: MapViewOfFile()\n");
      return 1;
    }
    
    if (fopen_s (&ITP64_LdCmd_fh, ITP64_LdCmd_file, "w+b") != (errno_t) NULL)
    {
      UnmapViewOfFile (EXE64_fp);
      CloseHandle (EXE64_fm);
      CloseHandle (EXE64_fh);
      UnmapViewOfFile (EXE32_fp);
      CloseHandle (EXE32_fm);
      CloseHandle (EXE32_fh);
      fclose (BIN32_fh);
      fclose (ITP32_LdCmd_fh);
      fclose (ITPII_LdCmd32_fh);
      fclose (SIMICS_LdCmd_fh);
      printf ("Couldn't open file: %s\n", ITP64_LdCmd_file);
      return 1;
    }

    if (fopen_s (&ITPII_LdCmd64_fh, ITPII_LdCmd64_file, "w+b") != (errno_t) NULL)
    {
      UnmapViewOfFile (EXE64_fp);
      CloseHandle (EXE64_fm);
      CloseHandle (EXE64_fh);
      UnmapViewOfFile (EXE32_fp);
      CloseHandle (EXE32_fm);
      CloseHandle (EXE32_fh);
      fclose (BIN32_fh);
      fclose (ITP32_LdCmd_fh);
      fclose (ITPII_LdCmd32_fh);
      fclose (SIMICS_LdCmd_fh);
      printf ("Couldn't open file: %s\n", ITPII_LdCmd64_file);
      return 1;
    }
  }
  
  return 0;
}

//---------------------------------------------------------------
// Close global files
//---------------------------------------------------------------
int CloseFiles (void)
{
  if (EXE64FilePresentFlag)   
  {
    fclose (ITP64_LdCmd_fh);
    fclose (ITPII_LdCmd64_fh);
    UnmapViewOfFile (EXE64_fp);
    CloseHandle (EXE64_fm);
    CloseHandle (EXE64_fh);
  }
  
  UnmapViewOfFile (EXE32_fp);
  CloseHandle (EXE32_fm);
  CloseHandle (EXE32_fh);
  fclose (BIN32_fh);
  fclose (ITP32_LdCmd_fh);
  fclose (ITPII_LdCmd32_fh);
  fclose (SIMICS_LdCmd_fh);
  return 0;
}


//---------------------------------------------------------------
// Converting PE/COFF EXE file to Binary file
//---------------------------------------------------------------
int PE2Bin (void)
{
  // PE32 64bit handling
  printf ("Processing ACM Main EXE PE32 file: %s\n", Arg[0]);
  // Check if DOS header present
  pEXE32_DOS_Hdr = (PIMAGE_DOS_HEADER) EXE32_fp;
  if (pEXE32_DOS_Hdr->e_magic == IMAGE_DOS_SIGNATURE)  { // DOS Header found
    pEXE32_NT_Hdr = (PIMAGE_NT_HEADERS) ADDR (EXE32_fp, +, pEXE32_DOS_Hdr->e_lfanew);
    
    if (pEXE32_NT_Hdr->Signature != IMAGE_NT_SIGNATURE)
    {
      printf ("ERROR: PE Signature expected\n");
      return 1;
    }
    pEXE32_File_Hdr = (PIMAGE_FILE_HEADER) ADDR (pEXE32_NT_Hdr, +, 4); // File Header
    pEXE32_Opt_Hdr = (PIMAGE_OPTIONAL_HEADER) (pEXE32_File_Hdr + 1); // Optional Header
  } else  {                             // Unsupported format
    printf ("ERROR: Unsupported file format, expecting PE/COFF format in %s input file\n", Arg[0]);
    return 1;
  }
  
  if (pEXE32_Opt_Hdr->Magic == MAGIC_PE32_0x10b)   { // PE32
    PE32_Opt_Hdr__SectionAlignment = pEXE32_Opt_Hdr->SectionAlignment;
    PE32_Opt_Hdr__ImageBase = pEXE32_Opt_Hdr->ImageBase;
    PE32_Opt_Hdr__SizeOfImage = pEXE32_Opt_Hdr->SizeOfImage;
    PE32_Opt_Hdr__NumberOfRvaAndSizes = pEXE32_Opt_Hdr->NumberOfRvaAndSizes;
    PE32_Opt_Hdr__DIRECTORY_ENTRY_DEBUG__Size = pEXE32_Opt_Hdr->DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].Size;
    PE32_Opt_Hdr__BaseOfCode = pEXE32_Opt_Hdr->BaseOfCode;
    pEXE32_SecHdr_Start = (PIMAGE_SECTION_HEADER) (ADDR (pEXE32_Opt_Hdr, +, pEXE32_File_Hdr->SizeOfOptionalHeader)); // Section Header Starts
  } else	{
    printf ("ERROR: Unsupported file format, expecting PE/COFF format in input file\n");
    return 1;
  }
  if (DumpRawSection (!Exe64bitFile, EXE32_fp, pEXE32_SecHdr_Start, pEXE32_File_Hdr->NumberOfSections, PE32_Opt_Hdr__SectionAlignment)) return 1;
  FileLength = ftell (BIN32_fh);
  FileLength32 = FileLength;
  // Check if ACM header contains known values
  if (CheckAcmHeader(BIN32_fh)) return 1;

  // Before we can use the AcmModuleOffset we must get the calculated offset value
  GetAcmModuleOffset();
  if (AcmModuleOffset == 0) {
      printf("Error: failed to set ACM module offset.\n");
      return 1;
  }

  // Calculate ACM Info Table Offsets
  InfoTable_UUID0Offset = AcmModuleOffset;
  InfoTable_ChipsetIdListOffset = AcmModuleOffset + 0x14;
  InfoTable_ProcessorIdListOffset = AcmModuleOffset + 0x28;
  InfoTable_TPMInfoListOffset = AcmModuleOffset + 0x2C;

  // Check if ACM Info Table contains known values
  if (CheckAcmInfoTable(BIN32_fh)) return 1;

  fseek (BIN32_fh, Header_AcmEntryOffset, SEEK_SET); // Reading AcmStart offset
  fread (&AcmStart, sizeof (DWORD), 1, BIN32_fh);
  AcmStart -= (pEXE32_NT_Hdr->OptionalHeader.BaseOfCode + pEXE32_NT_Hdr->OptionalHeader.ImageBase);

  fseek (BIN32_fh, AcmModuleOffset + AcmTypeModuleOffset, SEEK_SET);
  fread (&AcmType, sizeof (char), 1, BIN32_fh);
  
  fseek (BIN32_fh, 0, SEEK_END);
  
  if (AcmType > 15)
  {
    printf ("ERROR: Unsupported ACM type (0x%X), expecting type 0 to 15\n", AcmType);
    return 1;
  }
  
  printf ("\n    StartOffset=0x%x, EndOffset=0x%x, %sAcmStart=0x%x (Size=0x%x bytes)\n", 0, FileLength32 - 1, szAcmTypeLowerCase[AcmType], AcmStart, FileLength32);
  
  // PE32+ 64bit handling
  if (EXE64FilePresentFlag)   
  {
    printf ("\n\nProcessing ACM 64bit EXE PE32+ file: %s\n", EXE64FName);
    // Check if DOS header present
    pEXE64_DOS_Hdr = (PIMAGE_DOS_HEADER) EXE64_fp;
    if (pEXE64_DOS_Hdr->e_magic == IMAGE_DOS_SIGNATURE)  { // DOS Header found
      
      pEXE64_NT_Hdr = (PIMAGE_NT_HEADERS64) ADDR (EXE64_fp, +, pEXE64_DOS_Hdr->e_lfanew);
      
      if (pEXE64_NT_Hdr->Signature != IMAGE_NT_SIGNATURE)
      {
        printf ("ERROR: PE Signature expected\n");
        return 1;
      }
      pEXE64_File_Hdr = (PIMAGE_FILE_HEADER) ADDR (pEXE64_NT_Hdr, +, 4); // File Header
      pEXE64_Opt_Hdr = (PIMAGE_OPTIONAL_HEADER64) (pEXE64_File_Hdr + 1); // PE32+
      pEXE64_SecHdr_Start = (PIMAGE_SECTION_HEADER) (ADDR (pEXE64_Opt_Hdr, +, pEXE64_File_Hdr->SizeOfOptionalHeader)); // Section Header Starts
    } else  {                           // Unsupported format
      printf ("ERROR: Unsupported file format, expecting PE/COFF format  %s input file\n", EXE64FName);
      return 1;
    }
    
    if (pEXE64_Opt_Hdr->Magic == MAGIC_PE32Plus_0x20b)   { // PE32+
      PE64_Opt_Hdr__SectionAlignment = pEXE64_Opt_Hdr->SectionAlignment;
      PE64_Opt_Hdr__ImageBase = pEXE64_Opt_Hdr->ImageBase;
      PE64_Opt_Hdr__SizeOfImage = pEXE64_Opt_Hdr->SizeOfImage;
      PE64_Opt_Hdr__NumberOfRvaAndSizes = pEXE64_Opt_Hdr->NumberOfRvaAndSizes;
      PE64_Opt_Hdr__DIRECTORY_ENTRY_DEBUG__Size = pEXE64_Opt_Hdr->DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].Size;
      PE64_Opt_Hdr__BaseOfCode = pEXE64_Opt_Hdr->BaseOfCode;
      pEXE64_SecHdr_Start = (PIMAGE_SECTION_HEADER) (ADDR (pEXE64_Opt_Hdr, +, pEXE64_File_Hdr->SizeOfOptionalHeader)); // Section Header Starts
    } else	{
      printf ("ERROR: Unsupported file format, expecting PE/COFF format in input file\n");
      return 1;
    }
    if (DumpRawSection (Exe64bitFile, EXE64_fp, pEXE64_SecHdr_Start, pEXE64_File_Hdr->NumberOfSections, PE64_Opt_Hdr__SectionAlignment)) return 1;
    
    fseek (BIN32_fh, 0, SEEK_END);
    FileLength = ftell (BIN32_fh);
    FileLength64 = FileLength - FileLength32;
    Entrypoint64 = pEXE64_Opt_Hdr->AddressOfEntryPoint - PE64_Opt_Hdr__BaseOfCode + FileLength32;
    FileLength64 = FileLength - 1;
    printf ("\n    StartOffset=0x%x, EndOffset=0x%x, Entrypoint=0x%x  (Size=0x%x bytes)\n", FileLength32, FileLength - 1, Entrypoint64, FileLength64);
  }
  
  if (FixUpRelocations ()) return 1;
  if (AcmFileAlignment ()) return 1;
  if (ITPCmdFile ())       return 1;
  //Hash scrtm if requested but AcmFlags was not set
  //Otherwise this will be hashed in AcmToggleFlagBits
  if (SCRTMIntegrity && !AcmFlags) {
      if (HashEvScrtmVersion(BIN32_fh)) return 1;
  }
  return 0;
}

//---------------------------------------------------------------
// Dump binary raw data of the PE sections
//---------------------------------------------------------------
int DumpRawSection (boolean ExeFileType, LPVOID EXE_fp, PIMAGE_SECTION_HEADER section, unsigned num_sec, DWORD PE_Opt_Hdr__SectionAlignment)
{
  boolean skip = FALSE;
  unsigned i;
  char name[IMAGE_SIZEOF_SHORT_NAME + 1];
  PBYTE   buffer;
  DWORD   size;
  
  if ((buffer = malloc (PE_Opt_Hdr__SectionAlignment)) == 0)   {
    printf ("ERROR: failed to malloc() buffer\n");
    return 1;
  }
  memset (buffer, '\0', PE_Opt_Hdr__SectionAlignment);
  
  printf ("Binary dump begins:\n\n");
  printf ("     Section       Size (hex)      File_Offset (hex)         Saved/Skipped\n");
  printf ("    =========      ==========      ================      =======================\n");
  
  for (i = 0; i < num_sec; i++, section++)  {
    // Copy section name string
    memcpy (name, section->Name, IMAGE_SIZEOF_SHORT_NAME);
    name[IMAGE_SIZEOF_SHORT_NAME] = 0;
    
    
    if (ExeFileType != Exe64bitFile) {
      if (((i == 0) && (strcmp (name, "EDATA32") != 0)) || 
        ((i == 1) && (strcmp (name, ".text") != 0)))
      {
        printf ("\nERROR: Expecting first 2 PE sections to be EDATA32, .text.   *** Aborted! ***\n");
        free (buffer);
        return 1;
      }
    }
    
    if ((strcmp (name, ".reloc") == 0) || (strcmp (name, ".comment") == 0) || (strcmp (name, ".pdata") == 0))			
      skip = TRUE;
    else
      skip = FALSE;
    
    if (strcmp (name, "EDATA32") == 0) EDATA32_BASE = section->VirtualAddress; 
	
	//
	// Update EDATA32_BASE_ORG only te first time to preserve base of EDATA32_BASE of 32bit file in case when
	// 64bit file also has EDATA32 section with a different base. This is needed to correctly compute stackEnd value later on.
	//
	if (!EDATA32_BASE_ORG)
		EDATA32_BASE_ORG = EDATA32_BASE;

    if (strcmp (name, ".text") == 0)
    {
        if (ExeFileType != Exe64bitFile)
        {
            TEXT32_BASE = section->VirtualAddress;
        }
        else
        {
            TEXT64_BASE = section->VirtualAddress;
            Codestart64 = ftell(BIN32_fh);
        }
    }
    
    if (!skip)
    {
      printf("    Current output BIN32 file position : %08X \n", ftell(BIN32_fh));
      if (section->PointerToRawData != 0) 
      {
        size = section->Misc.VirtualSize;
        DumpBinary ((PBYTE) ADDR (EXE_fp, +, section->PointerToRawData), section->Misc.VirtualSize, BIN32_fh);
        if (section->SizeOfRawData > section->Misc.VirtualSize)
        {
          size += section->SizeOfRawData - section->Misc.VirtualSize;
          DumpBinary ( buffer, section->SizeOfRawData - section->Misc.VirtualSize, BIN32_fh);
        }
        if (size & (PE_Opt_Hdr__SectionAlignment - 1))
        {
          DumpBinary (buffer, PE_Opt_Hdr__SectionAlignment - (size & (PE_Opt_Hdr__SectionAlignment - 1)), BIN32_fh);
          size += PE_Opt_Hdr__SectionAlignment - (size & (PE_Opt_Hdr__SectionAlignment - 1));
        }
        printf ("    %-10s      %08X           %08X           Saved to: %s\n", name, 
          size, section->PointerToRawData, Arg[1]);
      }
      else                              // Handling empty section
      {
        DumpBinary ( buffer, PE_Opt_Hdr__SectionAlignment, BIN32_fh);
        printf ("    %-10s      %08X           %08X           Saved to: %s\n", name, 
          PE_Opt_Hdr__SectionAlignment, section->PointerToRawData, Arg[1]);
      }
    }
    else printf ("    %-10s      %08X           %08X           Skipped\n", name, 
           section->SizeOfRawData, section->PointerToRawData);
  }
  free (buffer);
  return 0;
}

//---------------------------------------------------------------
// Write the binary raw data to file
//---------------------------------------------------------------
void DumpBinary (PBYTE ptr, DWORD length, FILE *fh)
{
  fwrite (ptr, sizeof (char), length, fh);
}


//---------------------------------------------------------------
// Find Section Header
//---------------------------------------------------------------
PIMAGE_SECTION_HEADER FindSecHdr (PSTR name, WORD NumberOfSections, PIMAGE_SECTION_HEADER section)
{
  unsigned i;
  for ( i = 0; i < NumberOfSections; i++, section++ )
  {
    if ( strncmp (section->Name, name, 8) == 0)     return section;
  }
  return 0;
}

int FixUpRelocations (void)
{

  DWORD relocValue, tmp;
  DWORDLONG relocValue64;
  DWORD i, NumEntries;
  PWORD pEntry;
  char *szRelocType;
  WORD relocType;
  PIMAGE_BASE_RELOCATION base32Reloc, base64Reloc;
  int unhandled_type = 0, stackSizeError = 0;
  DWORD ShiftLeftCounter = 0;
  
  // PE32 handling
  // Find .reloc section of the EXE32_file
  pEXE32_Sec_reloc = FindSecHdr (".reloc", pEXE32_File_Hdr->NumberOfSections, pEXE32_SecHdr_Start);
  if (pEXE32_Sec_reloc == 0)
  {
    printf ("\nERROR: .reloc section not found.   *** Aborted! ***\n");
    return 1;
  }
  
  base32Reloc = (PIMAGE_BASE_RELOCATION) ADDR (EXE32_fp, +, pEXE32_Sec_reloc->PointerToRawData);
  
  fseek (BIN32_fh, Header_AcmEntryOffset, SEEK_SET); // Reading AcmStart offset
  fread (&AcmStart, sizeof (DWORD), 1, BIN32_fh);
  AcmStart -= pEXE32_NT_Hdr->OptionalHeader.BaseOfCode - pEXE32_NT_Hdr->OptionalHeader.ImageBase;
  if (Verbose)
   printf ("AcmStart: 0x%08x\n", AcmStart);

  fseek (BIN32_fh, (AcmStart - 8), SEEK_SET); // stackStart
  fread (&stackStart, sizeof (DWORD), 1, BIN32_fh);
  stackStart -= pEXE32_NT_Hdr->OptionalHeader.BaseOfCode - pEXE32_NT_Hdr->OptionalHeader.ImageBase;
  if (Verbose)
   printf ("stackStart: 0x%08x\n", stackStart);
  
  stackEnd = (TEXT32_BASE - EDATA32_BASE_ORG);
  relocAddrPtr = stackStart + 0x40 + 4; // Reserved 40h bytes for ACM Fixup routine use as scratch pad
  
  if (relocAddrPtr >= stackEnd-4)	stackSizeError = 1;       // Adjusted stackEnd for 18-bit bit-stream handling

  //_asm {int 3};
  while (base32Reloc->SizeOfBlock && !unhandled_type)
  {
    NumEntries = (base32Reloc->SizeOfBlock - sizeof (* base32Reloc)) / sizeof (WORD);
    pEntry = (PWORD) ADDR ( base32Reloc, +,  sizeof (* base32Reloc));
    
    for (i = 0; ((i < NumEntries) && !unhandled_type); i++)
    {
      // relocType = top 4 bits of the relocation entry
      relocType = (*pEntry & 0xF000) >> 12;
      szRelocType = relocType < 12 ? SzRelocTypes[relocType] : "unhandled_type";
      
      switch (relocType)
      {
        case 0:                         // ABSOLUTE
          break;
          
        case 3:                         // HIGHLOW
          fseek (BIN32_fh, ((*pEntry & 0x0FFF) + base32Reloc->VirtualAddress - pEXE32_NT_Hdr->OptionalHeader.BaseOfCode), SEEK_SET);
          fread (&relocValue, sizeof (DWORD), 1, BIN32_fh);
          relocValue = relocValue - pEXE32_NT_Hdr->OptionalHeader.BaseOfCode - pEXE32_NT_Hdr->OptionalHeader.ImageBase;

          fseek (BIN32_fh, ((*pEntry & 0x0FFF) + base32Reloc->VirtualAddress - pEXE32_NT_Hdr->OptionalHeader.BaseOfCode), SEEK_SET);
          fwrite (&relocValue, sizeof (DWORD), 1, BIN32_fh);
          relocAddr = ((*pEntry & 0x0FFF) + base32Reloc->VirtualAddress - pEXE32_NT_Hdr->OptionalHeader.BaseOfCode);
          
          if (!stackSizeError)
          {
            fseek (BIN32_fh, relocAddrPtr, SEEK_SET);
            if (!ShiftLeftCounter) {
                //printf("no ShiftLeftCounter STACK: relocAddr = 0x%04X\n", relocAddr);
                fwrite (&relocAddr, sizeof (DWORD), 1, BIN32_fh);
            }
            else {
              fread (&tmp, sizeof (DWORD), 1, BIN32_fh);
              tmp = tmp << (32-ShiftLeftCounter);                 // Clear unwanted upper bits
              tmp = tmp >> (32-ShiftLeftCounter);                 // Restore bit position
              relocAddr = (relocAddr << ShiftLeftCounter) | tmp;  // Merge old and new data
              if (Verbose) {
                printf ("relocAddrPtr2---: 0x%08x\n\n", relocAddrPtr);  // XYZ
              }
              fseek (BIN32_fh, relocAddrPtr, SEEK_SET);
              fwrite (&relocAddr, sizeof (DWORD), 1, BIN32_fh);
            }
            
            ShiftLeftCounter+=2;
            ShiftLeftCounter &= 0xF;       // Clipped counter to 0-15
          }
          else
            relocShortage += sizeof (WORD);
          
          relocCount++;
          if (ShiftLeftCounter)     relocAddrPtr += sizeof (WORD);
          else                      relocAddrPtr += sizeof (DWORD);
          
          if (relocAddrPtr >= (stackEnd-4))	stackSizeError = 1;    // Adjusted stackEnd for 18-bit bit-stream handling
          
          break;
          //case 0xA:           // DIR64
          
        default : 
          printf ("\nERROR: Relocation Type of 0x%X (%s) is not handled by this utility.  *** Aborted! ***\n", relocType, szRelocType); 
          unhandled_type = 1;
          break;
      }
      pEntry++;  // Advance to next relocation entry
    }

	if (&base32Reloc->SizeOfBlock == NULL) {
		printf("\nERROR: Wrong image.  *** Aborted! ***\n");
		return 1;
	}

	base32Reloc = (PIMAGE_BASE_RELOCATION) ADDR (base32Reloc, +, base32Reloc->SizeOfBlock);
	
  }
  relocCount32 = relocCount;
  
  // PE64 handling
  // Find .reloc section of the EXE64_file
  if (EXE64FilePresentFlag)   {
    pEXE64_Sec_reloc = FindSecHdr (".reloc", pEXE64_File_Hdr->NumberOfSections, pEXE64_SecHdr_Start);
    if (pEXE64_Sec_reloc == 0)    
    {
      printf ("    Note: .reloc section not found in %s.\n", EXE64FName);
      // return 0;
      goto skipEXE64Reloc;
    }
    
    base64Reloc = (PIMAGE_BASE_RELOCATION) ADDR (EXE64_fp, +, pEXE64_Sec_reloc->PointerToRawData);
    
    while (base64Reloc->SizeOfBlock && !unhandled_type)
    {
      NumEntries = (base64Reloc->SizeOfBlock - sizeof (* base64Reloc)) / sizeof (WORD);
      pEntry = (PWORD) ADDR ( base64Reloc, +,  sizeof (* base64Reloc));
      
      for (i = 0; ((i < NumEntries) && !unhandled_type); i++)
      {
        // relocType = top 4 bits of the relocation entry
        relocType = (*pEntry & 0xF000) >> 12;
        szRelocType = relocType < 12 ? SzRelocTypes[relocType] : "unhandled_type";
        
        switch (relocType)
        {
          case 0:                       // ABSOLUTE
            break;
            
          case 3:                       // HIGHLOW
            fseek (BIN32_fh, ((*pEntry & 0x0FFF) + base64Reloc->VirtualAddress - pEXE32_NT_Hdr->OptionalHeader.BaseOfCode), SEEK_SET);
            fread (&relocValue, sizeof (DWORD), 1, BIN32_fh);
            
            relocValue = relocValue - pEXE32_NT_Hdr->OptionalHeader.BaseOfCode - pEXE32_NT_Hdr->OptionalHeader.ImageBase;
            fseek (BIN32_fh, ((*pEntry & 0x0FFF) + base64Reloc->VirtualAddress - pEXE32_NT_Hdr->OptionalHeader.BaseOfCode), SEEK_SET);
            fwrite (&relocValue, sizeof (DWORD), 1, BIN32_fh);
            
            relocAddr = ((*pEntry & 0x0FFF) + base64Reloc->VirtualAddress - pEXE32_NT_Hdr->OptionalHeader.BaseOfCode);
            
            if (!stackSizeError)
            {
              fseek (BIN32_fh, relocAddrPtr, SEEK_SET);
              if (!ShiftLeftCounter)  fwrite (&relocAddr, sizeof (DWORD), 1, BIN32_fh);
              else {
                fread (&tmp, sizeof (DWORD), 1, BIN32_fh);
                tmp = tmp << (32-ShiftLeftCounter);                 // Clear unwanted upper bits
                tmp = tmp >> (32-ShiftLeftCounter);                 // Restore bit position
                relocAddr = (relocAddr << ShiftLeftCounter) | tmp;  // Merge old and new data
                fseek (BIN32_fh, relocAddrPtr, SEEK_SET);                
                fwrite (&relocAddr, sizeof (DWORD), 1, BIN32_fh);
              }
            
              ShiftLeftCounter+=2;
              ShiftLeftCounter &= 0xF;       // Clipped counter to 0-15
            }
            else
              relocShortage += sizeof (WORD);
          
            relocCount++;
            if (ShiftLeftCounter)     relocAddrPtr += sizeof (WORD);
            else                      relocAddrPtr += sizeof (DWORD);
          
            if (relocAddrPtr >= (stackEnd-4))	stackSizeError = 1;    // Adjusted stackEnd for 18-bit bit-stream handling
            
            break;
            
            
          case 0xA:                     // DIR64
            fseek (BIN32_fh, ((*pEntry & 0x0FFF) + base64Reloc->VirtualAddress - pEXE64_NT_Hdr->OptionalHeader.BaseOfCode) + FileLength32, SEEK_SET);
            fread (&relocValue64, sizeof (DWORDLONG), 1, BIN32_fh);
            
            relocValue64 = relocValue64 - pEXE64_NT_Hdr->OptionalHeader.BaseOfCode - pEXE64_NT_Hdr->OptionalHeader.ImageBase + FileLength32;
            fseek (BIN32_fh, ((*pEntry & 0x0FFF) + base64Reloc->VirtualAddress - pEXE64_NT_Hdr->OptionalHeader.BaseOfCode) + FileLength32, SEEK_SET);
            fwrite (&relocValue64, sizeof (DWORDLONG), 1, BIN32_fh);
            
            relocAddr = ((*pEntry & 0x0FFF) + base64Reloc->VirtualAddress - pEXE64_NT_Hdr->OptionalHeader.BaseOfCode + FileLength32);
            
            if (!stackSizeError)
            {
              fseek (BIN32_fh, relocAddrPtr, SEEK_SET);
              if (!ShiftLeftCounter)  fwrite (&relocAddr, sizeof (DWORD), 1, BIN32_fh);
              else {
                fread (&tmp, sizeof (DWORD), 1, BIN32_fh);
                tmp = tmp << (32-ShiftLeftCounter);                 // Clear unwanted upper bits
                tmp = tmp >> (32-ShiftLeftCounter);                 // Restore bit position
                relocAddr = (relocAddr << ShiftLeftCounter) | tmp;  // Merge old and new data
                fseek (BIN32_fh, relocAddrPtr, SEEK_SET);                
                fwrite (&relocAddr, sizeof (DWORD), 1, BIN32_fh);
              }
            
              ShiftLeftCounter+=2;
              ShiftLeftCounter &= 0xF;       // Clipped counter to 0-15
            }
            else
              relocShortage += sizeof (WORD);
          
            relocCount++;
            if (ShiftLeftCounter)     relocAddrPtr += sizeof (WORD);
            else                      relocAddrPtr += sizeof (DWORD);
          
            if (relocAddrPtr >= (stackEnd-4))	stackSizeError = 1;    // Adjusted stackEnd for 18-bit bit-stream handling
            
            break;
            
          default : 
            printf ("\nERROR: Relocation Type of 0x%X (%s) is not handled by this utility.  *** Aborted! ***\n", relocType, szRelocType); 
            unhandled_type = 1;
            break;
        }
        pEntry++;                       // Advance to next relocation entry
      }
      base64Reloc = (PIMAGE_BASE_RELOCATION) ADDR (base64Reloc, +, base64Reloc->SizeOfBlock);
    }
    relocCount64 = relocCount - relocCount32;
  }
  
skipEXE64Reloc:

  printf("PE2BIN-ACM COM DATA values:\n");
  printf("\t32-bit code start                   : %08X\n", stackEnd);
  printf("\t32-bit code end / 64-bit data start : %08X\n", FileLength32);
  printf("\t64-bit code start                   : %08X\n", Codestart64);
  printf("\t64-bit code end                     : %08X\n", FileLength64);

  fseek(BIN32_fh, (AcmStart - 6 * 4), SEEK_SET); // Data64 start
  fwrite(&FileLength32, sizeof(DWORD), 1, BIN32_fh);

  fseek (BIN32_fh, (AcmStart - 5 *4), SEEK_SET); // EXE64 start
  fwrite (&Codestart64, sizeof (DWORD), 1, BIN32_fh);
  
  FileLength64 = FileLength - 1;
  fseek (BIN32_fh, (AcmStart - 4 *4), SEEK_SET); // EXE64 end
  fwrite (&FileLength64, sizeof (DWORD), 1, BIN32_fh);
  
  fseek (BIN32_fh, (AcmStart - 3 *4), SEEK_SET); // EXE64 entry
  fwrite (&Entrypoint64, sizeof (DWORD), 1, BIN32_fh);
  
  fseek (BIN32_fh, stackStart + 0x40, SEEK_SET);
  fwrite (&relocCount, sizeof (DWORD), 1, BIN32_fh);
  
  fseek (BIN32_fh, (AcmStart - 4), SEEK_SET);
  fwrite (&stackEnd, sizeof (DWORD), 1, BIN32_fh);
  if (Verbose)
    printf ("stackEnd: 0x%08x\n", stackEnd);
  
  fseek (BIN32_fh, 0, SEEK_END);
  FileLength = ftell (BIN32_fh);
  if (FileLength > MaxAcmSize)  {       // ACM size > Max ACM size?
    printf ("\nERROR: total ACM filesize (=%d bytes) > %dKB.  *** Aborted! ***\n", FileLength, (MaxAcmSize / 1024));
    return 1;
  }
  
  printf ("\nTotal # of relocations=%d (32bit EXE (PE32):%d, 64bit EXE (PE32+):%d)\n", relocCount, relocCount32, relocCount64); 
  
  if (stackSizeError)		{
    printf ("\nERROR: Stack size too small to hold reloc addresses.  *** Aborted! ***\n"); 
    printf ("Info:  stackStart=0x%08x, stackEnd=0x%08x,\n", stackStart, stackEnd);
    printf ("       stack size=0x%x bytes, shortage=0x%x bytes\n", stackEnd - stackStart, relocShortage);
  }
  
  if (!unhandled_type && !stackSizeError) return 0; 
  else return 1;
}

int AcmFileAlignment (void)
{
  int result;
  int PaddingLength = 0;
  // int ModRemainder;
  BYTE buffer[64];
  long  AcmFileSizeOffset = 0x18;
  DWORD AcmFileAlignmentSize = 64;
  int length;
  struct tm   *TimeStamp;
  DWORD  tmp;
  DWORD  year, month, day;
  
  result = fseek (BIN32_fh, 0, SEEK_END);
  FileLength = ftell (BIN32_fh);
    
  // <-AE>  
  if (AcmSize_Type == TYPE_ACMSIZE2N) { 
    if (FileLength <= 0x1000)           // 4KB
      PaddingLength = 0x1000 - FileLength;
    else if (FileLength <= 0x2000)      // 8KB
      PaddingLength = 0x2000 - FileLength;
    else if (FileLength <= 0x4000)      // 16KB
      PaddingLength = 0x4000 - FileLength;
    else if (FileLength <= 0x8000)      // 32KB
      PaddingLength = 0x8000 - FileLength;
    else if (FileLength <= 0x10000)     // 64KB
      PaddingLength = 0x10000 - FileLength;
    else if (FileLength <= 0x20000)     // 128KB
      PaddingLength = 0x20000 - FileLength;
    else if (FileLength <= 0x40000)     // 256KB
      PaddingLength = 0x40000 - FileLength;

  } else if (AcmSize_Type == TYPE_ACMSIZESET) { 
    // (1) 120KB+1 - 128KB   (sized to 128KB)
    // (2) 184KB+1 - 192KB   (sized to 192KB)
    // (3) 216KB+1 - 224KB   (sized to 224KB)
    // (4) 232KB+1 - 240KB   (sized to 240KB)
    // (5) 240KB+1 - 256KB   (sized to 256KB)
    // (6) All others sized to 64B multiple.
   
    if ((FileLength > (120*1024+1)) && (FileLength <= 128*1024))         { // (1)
      PaddingLength = (128*1024 - FileLength);

    } else if ((FileLength > (184*1024+1) && (FileLength <= 192*1024)))  { // (2)
      PaddingLength = (192*1024 - FileLength);
    
    } else if ((FileLength > (216*1024+1) && (FileLength <= 224*1024)))  { // (3)
      PaddingLength = (224*1024 - FileLength);
    
    } else if ((FileLength > (232*1024+1) && (FileLength <= 240*1024)))  { // (4)
      PaddingLength = (240*1024 - FileLength);

    } else if ((FileLength > (240*1024+1) && (FileLength <= 256*1024)))  { // (5)
      PaddingLength = (256*1024 - FileLength);

    } else {
      if (FileLength % AcmFileAlignmentSize)                               // (6)
        PaddingLength = AcmFileAlignmentSize - FileLength % AcmFileAlignmentSize;
    }   
    
  } else if (AcmSize_Type == TYPE_ACMSIZEUSER) { 
      if (UserAcmSize < FileLength) {   // User specified size needs to be at least = minimum module size
         printf ("\nERROR: user specified size = %d bytes (too small).  Current module size = %d bytes.  *** Aborted! ***\n", UserAcmSize, FileLength);
         return 1;
      }

      if (UserAcmSize > MaxAcmSize)  {  // ACM size > Max ACM size (256KB)?
        printf ("\nWARNING: total ACM filesize (=%d bytes) > %dKB.\n", UserAcmSize, (MaxAcmSize / 1024));
      }

      PaddingLength = (UserAcmSize - FileLength);
      if (UserAcmSize % AcmFileAlignmentSize) // Must be multiple of 64 bytes for ACM
         PaddingLength += (AcmFileAlignmentSize - (UserAcmSize % AcmFileAlignmentSize));
      printf ("Padding length %dKB.\n", PaddingLength/1024);

  } else {
    if (FileLength % AcmFileAlignmentSize)  // Default of 64B size alignment
      PaddingLength = AcmFileAlignmentSize - FileLength % AcmFileAlignmentSize;
  }
  
  tmp = PaddingLength;
  // Padding 0's at EOF for file size alignment
  if (PaddingLength)
  {
    memset (buffer, '\0', 64);
    //PaddingLength = AcmFileAlignmentSize - ModRemainder;
    for (;tmp > 0; tmp -= 64) {
      if  (tmp >= 64) {
        fwrite (buffer, sizeof (char), 64, BIN32_fh); 
        continue;
      } else {           
        fwrite (buffer, sizeof (char), tmp, BIN32_fh);
        break;
      }
    }
    //fwrite (buffer, sizeof (char), PaddingLength, BIN32_fh);
    printf ("    %-10s     %08X             N/A              Saved to: %s\n", "(Padding 0)", 
      PaddingLength, Arg[1]);
  }
  //
  // Restore Padding length for correct display
  //                                          
  
  // Update the actual size
  result = fseek (BIN32_fh, AcmFileSizeOffset, SEEK_SET);
  *(DWORD *) buffer = (FileLength + PaddingLength) / 4;
  fwrite (buffer, sizeof (DWORD), 1, BIN32_fh); // Update ACM size
  
  printf ("\nTotal ACM filesize=%d bytes   (=0x%x bytes)\n", (FileLength + PaddingLength), (FileLength + PaddingLength));
  
  if (AcmUserRevFlag)   // Use user input date for ACM revision
  {
    // Check for correct date format
    *(UINT64 *) buffer = (*(UINT64*) AcmUserRev - (UINT64) 0x3030303030303030);

    // Check for numeric numbers
    if (*(UINT64*) buffer & 0xF0F0F0F0F0F0F0F0) {
       printf ("ERROR: expecting \"yyyymmdd\" format for -AcmUserRev: switch.\n");
       return(1);
       }

    tmp = 0;
    for (length = 0; length < 4; length++)
    {
      tmp = tmp << 8;
      tmp |= (*(BYTE *) (buffer + (length) *2) << 4) | (*(BYTE *) (buffer + (length) *2 + 1));
    }
    
    year = (tmp >> 16);
    month = ((tmp >> 8) & 0xff);
    day = (tmp & 0xff);
    
    // Check for:  day: 1-31; month: 1-12, year: 2014-2099
    if (
       (!(( (1 <= day)   && (day <= 0x10)     ||
         ( (0x10 <= day) && (day <= 0x20) )   ||
         ( (0x20 <= day) && (day <= 0x30) )   ||
         ( (0x30 <= day) && (day <= 0x31) )
          )))
                         ||
         (!( (1 <= month)   && (month <= 0x12) ))
                         ||
         (!( (0x2014 <= year)  && (year <= 0x2099) ))
       )
       {
          printf ("\nERROR: incorrect ACMUserRev format (expecting yyyymmdd format).\n\n");
          return 1;
       }
         
    result = fseek (BIN32_fh, Header_AcmDateOffset, SEEK_SET);
    fwrite (&tmp, sizeof (UINT32), 1, BIN32_fh); // Update date field
  }  
  else if  (AcmRevision)   // Use EXE date as ACM revision
  {
    // Convert time to struct tm form
    TimeStamp = localtime ((const time_t *) &pEXE32_File_Hdr->TimeDateStamp);
    
    // 23 03 09 20  => 20 09 03 23
    sprintf (buffer, "%02d%02d%4d", TimeStamp->tm_mday, TimeStamp->tm_mon + 1, TimeStamp->tm_year + 1900);
    *(UINT64 *) buffer -= (UINT64) 0x3030303030303030;
    
    tmp = *(DWORD *) (buffer + 4);
    *(DWORD *) (buffer + 4) = (tmp << 16) | (tmp >> 16);
    
    tmp = 0;
    for (length = 0; length < 4; length++)
    {
      tmp = tmp << 8;
      tmp |= (*(BYTE *) (buffer + (3 - length) *2) << 4) | (*(BYTE *) (buffer + (3 - length) *2 + 1));
    }
    result = fseek (BIN32_fh, Header_AcmDateOffset, SEEK_SET);
    fwrite (&tmp, sizeof (UINT32), 1, BIN32_fh); // Update date field
  }
  
  if (EXE64FilePresentFlag)
    printf ("Conversion: %s + %s -> %s completed  <<<===\n", Arg[0], EXE64FName, Arg[1]);
  else
    printf ("Conversion: %s -> %s completed  <<<===\n", Arg[0], Arg[1]);
  
  return 0;
}

int GetAcmModuleOffset(void)
{
  DWORD AcmHeaderVersion;
  UINT8 uuid0[4] = { 0xAA, 0x3A, 0xC0, 0x7F };
  UINT8 *fbytes = NULL;
  fseek(BIN32_fh, 0, SEEK_SET);
  fbytes = malloc(FileLength32);
  if (fbytes == NULL) {
      printf("Failed to allocate buffer.\n");
      return 0;
  }
  fread(fbytes, sizeof(UINT8), FileLength32, BIN32_fh);
  UINT8 *uuid_start = FindInMem((const void *)fbytes, FileLength32, (const void *)uuid0, 4);
  AcmModuleOffset = uuid_start ? uuid_start - fbytes : 0;
  free(fbytes);
  //Fallback, just use hard-coded values
  if (AcmModuleOffset == 0) {
    // The ACM module starts after the ACM Header and Scratch area
    // Get version
    fseek(BIN32_fh, Header_AcmHeaderVersionOffset, SEEK_SET);
    fread(&AcmHeaderVersion, sizeof(DWORD), 1, BIN32_fh);

    switch (AcmHeaderVersion & 0xFF0000)
    {
    case ACM_VERSION_0:
        AcmModuleOffset = ACM_HEADER_0_SIZE;
        break;
    case ACM_VERSION_3:
        AcmModuleOffset = ACM_HEADER_3_SIZE;
        break;
    case ACM_VERSION_4:
        AcmModuleOffset = ACM_HEADER_4_SIZE;
        break;
    default:
        AcmModuleOffset = 0;
        break;
    }
  }
  return AcmModuleOffset;
}

int ITPCmdFile (void)
{
  int result;
  int PaddingLength = 0;
  PSTR ptr;
  int length;
  PIMAGE_SECTION_HEADER section;
  int num_sec;
  
  // Generate ITP command: "load ACM_EXE nocode" at cs:(ACM_Base+LoadNocodeOffset)"
  if (EDATA32_BASE && TEXT32_BASE)
  {
    pEXE32_Sec_rdata = FindSecHdr (".rdata", pEXE32_File_Hdr->NumberOfSections,
                         (PIMAGE_SECTION_HEADER) ((DWORD) pEXE32_Opt_Hdr + pEXE32_File_Hdr->SizeOfOptionalHeader));
    
    if (pEXE32_Sec_rdata)
      pEXE32_Deb_Dir = (PIMAGE_DEBUG_DIRECTORY) ADDR (EXE32_fp, +, pEXE32_Sec_rdata->PointerToRawData);
    
    else {                              // no .rdata section handling
      DebugDirectory32_RVA = pEXE32_Opt_Hdr->DataDirectory[6].VirtualAddress;
      DebugDirectory32_Size = pEXE32_Opt_Hdr->DataDirectory[6].Size;
      section = pEXE32_SecHdr_Start;
      num_sec = pEXE32_File_Hdr->NumberOfSections;
      
      for (i = 0; i < num_sec; i++, section++)  {
        if ((DebugDirectory32_RVA >= section->VirtualAddress) && 
          (DebugDirectory32_RVA <= (section->VirtualAddress + section->SizeOfRawData)))
          DebugDirectory32_PointerToRawData = section->PointerToRawData + (DebugDirectory32_RVA - section->VirtualAddress);
      }
      
      if (!DebugDirectory32_PointerToRawData)
      {
        printf ("\nWarning: cannot locate DebugDirectory information, no ITP load command generated.\n");
        return 0;
      }
      pEXE32_Deb_Dir = (PIMAGE_DEBUG_DIRECTORY) ADDR (EXE32_fp, +, DebugDirectory32_PointerToRawData);
    }
    
    result = fseek (BIN32_fh, AcmModuleOffset + AcmTypeModuleOffset, SEEK_SET);
    fread (&AcmType, sizeof (char), 1, BIN32_fh);
    
    if (strstr ((PSTR) ADDR (EXE32_fp, +, pEXE32_Deb_Dir->PointerToRawData), "NB10") != NULL) 
      pEXE32_PDB_FName = (PSTR) ADDR (EXE32_fp, +, pEXE32_Deb_Dir->PointerToRawData) + 0x10;
    else if (((PSTR) ADDR (EXE32_fp, +, pEXE32_Deb_Dir->PointerToRawData), "RSDS") != NULL) 
      pEXE32_PDB_FName = (PSTR) ADDR (EXE32_fp, +, pEXE32_Deb_Dir->PointerToRawData) + 0x18;
    else
    {
      printf ("\nERROR: Expecting DebugDirectory to contain NB10 or RSDS debug type.  *** Aborted! ***\n");
      return 1;
    }
    
    ptr = _strdup ( pEXE32_PDB_FName );
    length = strlen (ptr);
    _strlwr_s (ptr + length - 4, strlen (".pdb") + 1);
    
    if (strstr (ptr + length - 4, ".pdb") != NULL) // pdb file
    {
      memcpy (ptr + length - 4, ".exe", 4);
      fprintf (ITP32_LdCmd_fh, "load %s nocode at (%s_ACM_base + 0x%08X)\n", ptr, szAcmType[AcmType], (TEXT32_BASE - EDATA32_BASE));
      //printf ("\n\nITP command (saved to %s):\n", ITP32_LdCmd_file);
      //printf ("   load %s nocode  at (%s_ACM_base + 0x%08X)\n", ptr, szAcmType[AcmType], (TEXT32_BASE - EDATA32_BASE));

      fprintf (ITPII_LdCmd32_fh, "import itpii\n");
      fprintf (ITPII_LdCmd32_fh, "itp = itpii.baseaccess(); itp.vp = 0\n");
      fprintf (ITPII_LdCmd32_fh, "import acm\n\n");
      fprintf (ITPII_LdCmd32_fh, "eip = itp.threads[itp.vp].state.regs.eip\n");
      fprintf (ITPII_LdCmd32_fh, "ACM_Base=acm.SearchACM(eip)\n");
      fprintf (ITPII_LdCmd32_fh, "if (ACM_Base!=0):\n");
      fprintf (ITPII_LdCmd32_fh, "  itpii.printf(\"\\nLoading ACM symbols ...\\n\")\n");
      fprintf (ITPII_LdCmd32_fh, "  itp.threads[itp.vp].load(r\"%s\", at=itpii.Address(ACM_Base-0x%x), loadkey = \"None\", operation=itp.LoadOperations.nocode)\n", ptr, EDATA32_BASE);
      fprintf (ITPII_LdCmd32_fh, "else:\n");
      fprintf (ITPII_LdCmd32_fh, "  itpii.printf(\"\\nACM Header not found within 128KB - Failed ACM source loading ...\\n\")\n");
      printf ("\nITPII command (saved to %s):\n", ITPII_LdCmd32_file);
      printf ("   load ... %s ... at (%s_ACM_base - 0x%08X)\n", ptr, szAcmType[AcmType], EDATA32_BASE);

      fprintf (SIMICS_LdCmd_fh, "import cli\n");
      fprintf (SIMICS_LdCmd_fh, "from simmod.stc_tools.startup import mem_read\n\n");
      fprintf (SIMICS_LdCmd_fh, "def get_acm_base_address(ptr):\n");
      fprintf (SIMICS_LdCmd_fh, "    LookBackBlockCount = (256*1024/1024)  # size=256B, block size 1KB\n");
      fprintf (SIMICS_LdCmd_fh, "    DecrementStepSize  = 1024  #1KB aligned\n\n");
      fprintf (SIMICS_LdCmd_fh, "    if ptr == 0:\n");
      fprintf (SIMICS_LdCmd_fh, "        print \"Bad EIP\"\n");
      fprintf (SIMICS_LdCmd_fh, "        return\n");
      fprintf (SIMICS_LdCmd_fh, "    ptr = ptr&0xfffffc00 # 1KB aligned pointer\n");
      fprintf (SIMICS_LdCmd_fh, "    print \"\\tSearch ACM from 0x%%x (1KB aligned pointer)\"%%ptr\n");
      fprintf (SIMICS_LdCmd_fh, "    sign = 0\n");
      fprintf (SIMICS_LdCmd_fh, "    while LookBackBlockCount > 0x0:\n");
      fprintf (SIMICS_LdCmd_fh, "        sign = mem_read(ptr, 2)._value\n");
      fprintf (SIMICS_LdCmd_fh, "        #if sign == 0x0002:\n");
      fprintf (SIMICS_LdCmd_fh, "        if (mem_read(ptr+0x10,4)._value == 0x00008086) and (mem_read(ptr+0x4c0,8)._value == 0x18DB46A77FC03AAA):\n");
      fprintf (SIMICS_LdCmd_fh, "            print \"\\t > Found ACM header signature at 0x%%x\"%%ptr\n");
      fprintf (SIMICS_LdCmd_fh, "            print r\"ACM_32_File = %s\"\n", ptr);
      fprintf (SIMICS_LdCmd_fh, "            print \"ACM_32_Remap_Address = 0x%%x\\n\" %% (ptr - 0x%x)\n", EDATA32_BASE);
      if (!EXE64FilePresentFlag) {
        fprintf (SIMICS_LdCmd_fh, "            return ptr\n");
        fprintf (SIMICS_LdCmd_fh, "        ptr = ptr - DecrementStepSize\n");
        fprintf (SIMICS_LdCmd_fh, "        LookBackBlockCount = LookBackBlockCount - 1\n");
        fprintf (SIMICS_LdCmd_fh, "    print \"\\t > ACM header signature is not found\"\n");
        fprintf (SIMICS_LdCmd_fh, "    return 0\n\n");
        fprintf (SIMICS_LdCmd_fh, "get_acm_base_address(conf.skybay.mb.cpu0.core[0][0].eip) # search for acm address\n");
      }
	}
    else
    {
      printf ("Warning: Couldn't locate .pdb file in .rdata section, no ITP command generated.\n");
      fprintf (ITP32_LdCmd_fh, "//Couldn't locate .pdb file in .rdata section, no ITP command generated.\n");
      fprintf (ITPII_LdCmd32_fh, "//Couldn't locate .pdb file in .rdata section, no ITPII command generated.\n");
    }
    free (ptr);
  }
  else
  {
    printf ("ERROR: Not both EDATA32 and .text sections are present.\n");
    printf ("Warning: Couldn't locate .pdb file in .rdata section, no ITP command generated.\n");
    return 1;
  }
  
  // Generate ITP command: "load ACM_EXE nocode" at cs:(ACM_Base+LoadNocodeOffset)"
  if (EXE64FilePresentFlag)
  {
    pEXE64_Sec_rdata = FindSecHdr (".rdata", pEXE64_File_Hdr->NumberOfSections,
                         (PIMAGE_SECTION_HEADER) ((DWORD) pEXE64_Opt_Hdr + pEXE64_File_Hdr->SizeOfOptionalHeader));
    
    if (pEXE64_Sec_rdata)
      pEXE64_Deb_Dir = (PIMAGE_DEBUG_DIRECTORY) ADDR (EXE64_fp, +, pEXE64_Sec_rdata->PointerToRawData);
    
    else {                              // no .rdata section handling
      DebugDirectory64_RVA = pEXE64_Opt_Hdr->DataDirectory[6].VirtualAddress;
      DebugDirectory64_Size = pEXE64_Opt_Hdr->DataDirectory[6].Size;
      section = pEXE64_SecHdr_Start;
      num_sec = pEXE64_File_Hdr->NumberOfSections;
      
      for (i = 0; i < num_sec; i++, section++)  {
        if ((DebugDirectory64_RVA >= section->VirtualAddress) && 
          (DebugDirectory64_RVA <= (section->VirtualAddress + section->SizeOfRawData)))
          DebugDirectory64_PointerToRawData = section->PointerToRawData + (DebugDirectory64_RVA - section->VirtualAddress);
      }
      
      if (!DebugDirectory64_PointerToRawData)
      {
        printf ("\nWarning: cannot locate DebugDirectory information, no ITP load command generated.\n");
        return 0;
      }
      pEXE64_Deb_Dir = (PIMAGE_DEBUG_DIRECTORY) ADDR (EXE64_fp, +, DebugDirectory64_PointerToRawData);
    }
    
    result = fseek (BIN32_fh, AcmModuleOffset + AcmTypeModuleOffset, SEEK_SET);
    fread (&AcmType, sizeof (char), 1, BIN32_fh);
    
    if (strstr ((PSTR) ADDR (EXE64_fp, +, pEXE64_Deb_Dir->PointerToRawData), "NB10") != NULL) 
      pEXE64_PDB_FName = (PSTR) ADDR (EXE64_fp, +, pEXE64_Deb_Dir->PointerToRawData) + 0x10;
    else if (((PSTR) ADDR (EXE64_fp, +, pEXE64_Deb_Dir->PointerToRawData), "RSDS") != NULL) 
      pEXE64_PDB_FName = (PSTR) ADDR (EXE64_fp, +, pEXE64_Deb_Dir->PointerToRawData) + 0x18;
    else
    {
      printf ("\nERROR: Expecting DebugDirectory to contain NB10 or RSDS debug type.  *** Aborted! ***\n");
      return 1;
    }
    
    ptr = _strdup ( pEXE64_PDB_FName );
    length = strlen (ptr);
    _strlwr_s (ptr + length - 4, strlen (".pdb") + 1);
    
    if (strstr (ptr + length - 4, ".pdb") != NULL) // pdb file
    {
      memcpy (ptr + length - 4, ".exe", 4);
      
      fprintf (ITP64_LdCmd_fh, "load %s nocode at (%s_ACM_base + 0x%08X)\n", ptr, szAcmType[AcmType],	\
        (TEXT64_BASE - pEXE64_SecHdr_Start->VirtualAddress + FileLength32));
      //printf ("\nITP command (saved to %s):\n", ITP64_LdCmd_file);
      //printf ("   load %s nocode  at (%s_ACM_base + 0x%08X)\n", ptr, szAcmType[AcmType],	\
      //  (TEXT64_BASE - pEXE64_SecHdr_Start->VirtualAddress + FileLength32));

      fprintf (ITPII_LdCmd64_fh, "import itpii\n");
      fprintf (ITPII_LdCmd64_fh, "itp = itpii.baseaccess(); itp.vp = 0\n");
      fprintf (ITPII_LdCmd64_fh, "import acm\n\n");
      fprintf (ITPII_LdCmd64_fh, "eip = itp.threads[itp.vp].state.regs.eip\n");
      fprintf (ITPII_LdCmd64_fh, "ACM_Base=acm.SearchACM(eip)\n");
      fprintf (ITPII_LdCmd64_fh, "if (ACM_Base!=0):\n");
      fprintf (ITPII_LdCmd64_fh, "  itpii.printf(\"\\nLoading ACM symbols ...\\n\")\n");
      fprintf (ITPII_LdCmd64_fh, "  itp.threads[itp.vp].load(r\"%s\", at=itpii.Address(ACM_Base+0x%x), loadkey = \"None\", operation=itp.LoadOperations.nocode)\n", ptr, (FileLength32 - pEXE64_SecHdr_Start->VirtualAddress));
      fprintf (ITPII_LdCmd64_fh, "else:\n");
      fprintf (ITPII_LdCmd64_fh, "  itpii.printf(\"\\nACM Header not found within 128KB - Failed ACM source loading ...\\n\")\n");
      printf ("\nITPII command (saved to %s):\n", ITPII_LdCmd64_file);
      printf ("   load ... %s ... at (%s_ACM_base + 0x%08X)\n", ptr, szAcmType[AcmType], (FileLength32 - pEXE64_SecHdr_Start->VirtualAddress));

      fprintf (SIMICS_LdCmd_fh, "            print r\"ACM_64_File = %s\"\n", ptr);
      fprintf (SIMICS_LdCmd_fh, "            print \"ACM_64_Remap_Address = 0x%%x\\n\" %% (ptr + 0x%x)\n", (FileLength32 - pEXE64_SecHdr_Start->VirtualAddress));
      fprintf (SIMICS_LdCmd_fh, "            return ptr\n");
      fprintf (SIMICS_LdCmd_fh, "        ptr = ptr - DecrementStepSize\n");
      fprintf (SIMICS_LdCmd_fh, "        LookBackBlockCount = LookBackBlockCount - 1\n");
      fprintf (SIMICS_LdCmd_fh, "    print \"\\t > ACM header signature is not found\"\n");
      fprintf (SIMICS_LdCmd_fh, "    return 0\n\n");
      fprintf (SIMICS_LdCmd_fh, "get_acm_base_address(conf.skybay.mb.cpu0.core[0][0].eip) # search for acm address\n");
	}
    else
    {
      printf ("Warning: Couldn't locate .pdb file in .rdata section, no ITP command generated.\n");
      fprintf (ITP64_LdCmd_fh, "//Couldn't locate .pdb file in .rdata section, no ITP command generated.\n");
      fprintf (ITPII_LdCmd64_fh, "//Couldn't locate .pdb file in .rdata section, no ITP command generated.\n");
    }
    free (ptr);
  }

  return 0;
}


int ACMsToggleFlagsBits(void)
{
    int result, ret = 0;
    FILE *TMP_fh;
    char buffer[257];
    UINT8 AcmType;
    UINT8 PwAcmVer = 0x0;

    strcpy_s(Arg1_no_bin, strlen(Arg[1]) + 1, Arg[1]);

    if (_strcmpi((Arg[1] + strlen(Arg[1]) - 4), ".bin") == 0)
        (*(BYTE *)(Arg1_no_bin + strlen(Arg1_no_bin) - 4)) = 0;

    // -------------PW---------------------
    sprintf(buffer, "copy %s  %s > NUL", Arg[1], EXE32_tmp);
    system(buffer);

    if (fopen_s(&TMP_fh, EXE32_tmp, "r+b") != (errno_t)NULL)
    {
        printf("ERROR: Couldn't open file: %s\n", EXE32_tmp);
        ret = 1;
        goto END;
    }

  result = fseek (TMP_fh, AcmModuleOffset+AcmTypeModuleOffset, SEEK_SET);
  fread((void *) &AcmType, sizeof(UINT8), 1, TMP_fh);

  result = fseek (TMP_fh, Header_AcmFlagOffset, SEEK_SET); // AcmFlagOffset
  *(BYTE *) buffer = 0x00;              // flags[15:14] = 00b: PW
  fwrite (buffer, sizeof (BYTE), 1, TMP_fh);

  result = fseek (TMP_fh, AcmModuleOffset + AcmVersionModuleOffset, SEEK_SET); // AcmVersion Offset
  fread (&AcmVersion, sizeof (char), 1, TMP_fh);

  //Force version for BIOS ACM or startup ACM, not for sinit
  if (strcmp(szAcmType[AcmType], "SINIT") != 0) {
    if (AcmVersion < 2) {
      *(BYTE *)buffer = 2;  // For PW force 2
    }
    else {
      *(BYTE *)buffer = AcmVersion; // Or leave as is
    }
    result = fseek (TMP_fh, AcmModuleOffset + AcmVersionModuleOffset, SEEK_SET); // AcmVersion Offset
    fwrite (buffer, sizeof (BYTE), 1, TMP_fh);
  }

  if (strcmp(szAcmType[AcmType], "SINIT") == 0) {
      PwAcmVer = AcmVersion;
      *(BYTE *)buffer = AcmVersion;
      if ((AcmVersion & 0x3) != 3) { //If last two bits not 0b11
          *(BYTE *) buffer = AcmVersion | 0b11; //Flip last two bits
          PwAcmVer = AcmVersion | 0b11;
      }
      result = fseek (TMP_fh, AcmModuleOffset + AcmVersionModuleOffset, SEEK_SET);
      fwrite(buffer, sizeof(BYTE), 1, TMP_fh);
  }

  result = fseek (TMP_fh, Header_AcmAcmSvnOffset, SEEK_SET);
  fread (&AcmSvnNumber, sizeof(char), 1, TMP_fh); // Read current Acm Svn Number

    result = fseek(TMP_fh, Header_AcmSeSvnOffset, SEEK_SET);
    fread(&AcmSeSvnNumber, sizeof(char), 1, TMP_fh); // Read current SGX Svn Number

    if (AcmSvnNumber < 2) {
        result = fseek(TMP_fh, Header_AcmAcmSvnOffset, SEEK_SET);
        *(WORD *)buffer = 0x02; // PW: force Acm Svn number to 2 if it's < 2, do nothing otherwise
        fwrite(buffer, sizeof(WORD), 1, TMP_fh);
        AcmSvnNumber = 2;
    }

    if (AcmSeSvnNumber < 2) {
        result = fseek(TMP_fh, Header_AcmSeSvnOffset, SEEK_SET);
        *(WORD *)buffer = 0x02; // PW: if sgx svn is < 2 force 2, do nothing otherwise
        fwrite(buffer, sizeof(WORD), 1, TMP_fh);
    }

    //Hash SCRTM data:
    if (SCRTMIntegrity) {
        if (HashEvScrtmVersion(TMP_fh)) {
            ret = 1;
            goto END;
        }
    }
    fclose(TMP_fh);

    sprintf(buffer, "copy %s %s.PW.bin > NUL", EXE32_tmp, Arg1_no_bin);
    system(buffer);
    sprintf(buffer, "%s.PW.bin", Arg1_no_bin);
    if (!fileExists(buffer)) {
        ret = 1;
        goto END;
    }
    // ---------------------------------------

    // -----------NPW--------------------
    sprintf(buffer, "copy %s %s > NUL", Arg[1], EXE32_tmp);
    system(buffer);

    if (fopen_s(&TMP_fh, EXE32_tmp, "r+b") != (errno_t)NULL)
    {
        printf("ERROR: Couldn't open file: %s\n", EXE32_tmp);
        ret = 1;
        goto END;
    }

  result = fseek (TMP_fh, Header_AcmFlagOffset, SEEK_SET); // AcmFlagOffset
  *(BYTE *) buffer = 0x40;              // flags[15:14] 01b: NPW
  fwrite (buffer, sizeof (BYTE), 1, TMP_fh);

  result = fseek (TMP_fh, Header_AcmSeSvnOffset, SEEK_SET); // AcmSeSvnOffset
  *(WORD *) buffer = 0x01;              // SE_SVN=SGX_SVN=1 for NPW
  fwrite (buffer, sizeof (WORD), 1, TMP_fh);

  result = fseek (TMP_fh, Header_AcmAcmSvnOffset, SEEK_SET);
  fwrite (buffer, sizeof (WORD), 1, TMP_fh);

    // Reading AcmVersion for later check

    result = fseek(TMP_fh, AcmModuleOffset + AcmVersionModuleOffset, SEEK_SET); // AcmVersion Offset
    fread(&AcmVersion, sizeof(char), 1, TMP_fh);
    *(BYTE *)buffer = 0x1; //AcmVersion == 1 for NPW
    //Write
    if (strcmp(szAcmType[AcmType], "SINIT") != 0) {
        result = fseek(TMP_fh, AcmModuleOffset + AcmVersionModuleOffset, SEEK_SET);
        fwrite(buffer, sizeof(BYTE), 1, TMP_fh);
    }
    if (SCRTMIntegrity) {
        if (HashEvScrtmVersion(TMP_fh)) {
            ret = 1;
            goto END;
        }
    }
    fclose(TMP_fh);

    if (strcmp(szAcmType[AcmType], "SINIT") == 0 &&
        (AcmVersion & 0b11) == 3) {
        printf("No NPW produced if sinit ACM_Version[1:0] == 3.\n");
    }
    else {
        sprintf(buffer, "copy %s %s.NPW.bin > NUL", EXE32_tmp, Arg1_no_bin);
        system(buffer);
        sprintf(buffer, "%s.NPW.bin", Arg1_no_bin);
        if (!fileExists(buffer)) {
            ret = 1;
            goto END;
        }
    }

	// ---------------------------------------

    // -------------DBG---------------------
    sprintf(buffer, "copy %s  %s > NUL", Arg[1], EXE32_tmp);
    system(buffer);

    if (fopen_s(&TMP_fh, EXE32_tmp, "r+b") != (errno_t)NULL)
    {
        printf("ERROR: Couldn't open file: %s\n", EXE32_tmp);
        ret = 1;
        goto END;
    }

  result = fseek (TMP_fh, Header_AcmFlagOffset, SEEK_SET); // AcmFlagOffset
  *(BYTE *) buffer = 0x80;              // flags[15:14] 10b: DBG
  fwrite (buffer, sizeof (BYTE), 1, TMP_fh);
  
  result = fseek (TMP_fh, Header_AcmAcmSvnOffset, SEEK_SET); // AcmSvnOffset
  *(WORD *) buffer = 0x00;              // SE_SVN=ACM_SVN=0 for DBG
  fwrite (buffer, sizeof (WORD), 1, TMP_fh);
  
  result = fseek (TMP_fh, Header_AcmSeSvnOffset, SEEK_SET); // AcmSeSvn offset
  fwrite (buffer, sizeof (WORD), 1, TMP_fh);

  if (strcmp(szAcmType[AcmType], "SINIT") != 0) {
    result = fseek(TMP_fh, AcmModuleOffset + AcmVersionModuleOffset, SEEK_SET); // AcmVersion Offset
    *(BYTE *)buffer = 0x0;  // Forced AcmVersion 0 for DBG
    fwrite(buffer, sizeof(BYTE), 1, TMP_fh);
  }

  if (strcmp(szAcmType[AcmType], "SINIT") == 0) {
      result = fseek(TMP_fh, AcmModuleOffset + AcmVersionModuleOffset, SEEK_SET); // AcmVersion Offset
      *(BYTE *)buffer = PwAcmVer;  // Forced SINIT AcmVersion DBG to be the same as PW
      fwrite(buffer, sizeof(BYTE), 1, TMP_fh);
  }

    if (SCRTMIntegrity) {
        if (HashEvScrtmVersion(TMP_fh)) {
            ret = 1;
            goto END;
        }
    }

    fclose(TMP_fh);
    sprintf(buffer, "copy %s %s.DBG.bin > NUL", EXE32_tmp, Arg1_no_bin);
    system(buffer);
    sprintf(buffer, "%s.DBG.bin", Arg1_no_bin);
    if (!fileExists(buffer)) {
        ret = 1;
        goto END;
    }
    // ---------------------------------------
END:
    sprintf(buffer, "del %s > NUL", EXE32_tmp);
    system(buffer);
    DeleteFile(Arg[1]);
    return ret;
}

//---------------------------------------------------------------
// Converting PE/COFF EXE file to Binary file
//---------------------------------------------------------------
int ComputeUpdateTextAligmentSize (void)
{
  // PE32 64bit handling
  printf ("Processing ACM Main EXE PE32 file: %s\n", Arg[0]);
  // Check if DOS header present
  pEXE32_DOS_Hdr = (PIMAGE_DOS_HEADER) EXE32_fp;
  if (pEXE32_DOS_Hdr->e_magic == IMAGE_DOS_SIGNATURE)  { // DOS Header found
    pEXE32_NT_Hdr = (PIMAGE_NT_HEADERS) ADDR (EXE32_fp, +, pEXE32_DOS_Hdr->e_lfanew);
    
    if (pEXE32_NT_Hdr->Signature != IMAGE_NT_SIGNATURE)
    {
      printf ("ERROR: PE Signature expected\n");
      return 1;
    }
    pEXE32_File_Hdr = (PIMAGE_FILE_HEADER) ADDR (pEXE32_NT_Hdr, +, 4); // File Header
    pEXE32_Opt_Hdr = (PIMAGE_OPTIONAL_HEADER) (pEXE32_File_Hdr + 1); // Optional Header
  } else  {                             // Unsupported format
    printf ("ERROR: Unsupported file format, expecting PE/COFF format in %s input file\n", Arg[0]);
    return 1;
  }
  
  if (pEXE32_Opt_Hdr->Magic == MAGIC_PE32_0x10b)   { // PE32
    PE32_Opt_Hdr__SectionAlignment = pEXE32_Opt_Hdr->SectionAlignment;
    PE32_Opt_Hdr__ImageBase = pEXE32_Opt_Hdr->ImageBase;
    PE32_Opt_Hdr__SizeOfImage = pEXE32_Opt_Hdr->SizeOfImage;
    PE32_Opt_Hdr__NumberOfRvaAndSizes = pEXE32_Opt_Hdr->NumberOfRvaAndSizes;
    PE32_Opt_Hdr__DIRECTORY_ENTRY_DEBUG__Size = pEXE32_Opt_Hdr->DataDirectory[
                                                IMAGE_DIRECTORY_ENTRY_DEBUG].Size;
    PE32_Opt_Hdr__BaseOfCode = pEXE32_Opt_Hdr->BaseOfCode;
    pEXE32_SecHdr_Start = (PIMAGE_SECTION_HEADER) (ADDR (pEXE32_Opt_Hdr, +, pEXE32_File_Hdr->SizeOfOptionalHeader)); // Section Header Starts
  } else	{
    printf ("ERROR: Unsupported file format, expecting PE/COFF format in input file\n");
    return 1;
  }
  
  pEXE32_Sec_EDATA32 = FindSecHdr ("EDATA32", pEXE32_File_Hdr->NumberOfSections, pEXE32_SecHdr_Start);
  EDATA32_BASE = pEXE32_Sec_EDATA32->VirtualAddress;
  pEXE32_Sec_CODE32 = FindSecHdr (".text", pEXE32_File_Hdr->NumberOfSections, pEXE32_SecHdr_Start);
  
  if ((pEXE32_Sec_CODE32->VirtualAddress) <= EDATA32_BASE)
  {
    printf ("ERROR: Expecting sections in this order: EDATA32 followed by .text\n");
    return 1;
  }
  TEXT32_PaddingSize=0;     
  if (TEXT_Alignment)
  {
    TEXT32_PaddingSize = TEXT_Alignment - ((pEXE32_Sec_CODE32->VirtualAddress) - EDATA32_BASE) & (TEXT_Alignment - 1);
    printf ("*** Modifying text_alignment_padding.h for .text alignment of %xKB ***\n", (TEXT_Alignment / 1024));
    sprintf (TextPaddingString, "del text_alignment_padding.h");
    system (TextPaddingString);
    sprintf (TextPaddingString, "echo // This file is generated by build process. Do not edit.> text_alignment_padding.h");
    system (TextPaddingString);
    sprintf (TextPaddingString, "echo.>> text_alignment_padding.h");
    system (TextPaddingString);
    sprintf (TextPaddingString, "echo #define text_alignment_padding 0x%x>> text_alignment_padding.h", TEXT32_PaddingSize);
    system (TextPaddingString);
    printf ("*** Updated text_alignment_padding.h: \"text_alignment_padding  =  0x%x\" ***\n", TEXT32_PaddingSize);
    printf ("-------------------------------------------------------------------------------------\n");
  }
  return 0;
}

//---------------------------------------------------------------
// Open EXE32_tmp
//---------------------------------------------------------------
int OpenEXE32_tmp (LPSTR EXE32_file)
{
  EXE32_fh = CreateFile (EXE32_file, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL,
               OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
  
  if (EXE32_fh == INVALID_HANDLE_VALUE)
  {
    printf ("Couldn't open file: %s\n", EXE32_file);
    return 1;
  }
  
  EXE32_fm = CreateFileMapping (EXE32_fh, NULL, PAGE_READWRITE, 0, 0, NULL);
  if (EXE32_fm == 0)
  {
    CloseHandle (EXE32_fh);
    printf ("Couldn't open file mapping: CreateFileMapping()\n");
    return 1;
  }
  
  EXE32_fp = MapViewOfFile (EXE32_fm, FILE_MAP_ALL_ACCESS, 0, 0, 0);
  if (EXE32_fp == 0)
  {
    CloseHandle (EXE32_fm);
    CloseHandle (EXE32_fh);
    printf ("Couldn't map view of file: MapViewOfFile()\n");
    return 1;
  }
  return 0;
}

void GetValueAtOffset(FILE *BIN32_fh, DWORD offset, DWORD *Buffer, size_t chunk_size, int chunk_count, int origin) {
    fseek(BIN32_fh, offset, origin);
    fread(Buffer, chunk_size, chunk_count, BIN32_fh);
}

//---------------------------------------------------------------
// Check ACM header for known values
// offset of scratch - HeaderLen * 4
// offset of user area and ACM info table HeaderLen * 4 + ScratchSize * 4
//---------------------------------------------------------------
int CheckAcmHeader(FILE *BIN32_fh)
{
  DWORD Buff = 0x00; //This will hold data read from file
  DWORD HeaderLen = 0x00; //We need to store header length for some additional checks later on
  BOOL HasError = 0;

  // Check module type, must be 0x02
  GetValueAtOffset(BIN32_fh, Header_AcmTypeOffset, &Buff, sizeof(WORD), 0x1, SEEK_SET);
  if (Buff != AcmModuleTypeStable) {
      printf ("\nACM Header:\nIncorrect ACM Type\nExpected: 0x%X; found: 0x%X\n", AcmModuleTypeStable, Buff);
      HasError = 1;
  }

  // Check subtype, must be 0x00 or 0x01
  GetValueAtOffset(BIN32_fh, Header_AcmSubTypeOffset, &Buff, sizeof(WORD), 0x1, SEEK_SET);
  if (Buff != AcmSubtypeTXTStable && Buff != AcmSubtypeSACMStable) {
      printf("\nACM Header:\nIncorrect ACM SubType\nExpected: 0x%X (TXT) or 0x%X (S-ACM); found: 0x%X\n", AcmSubtypeTXTStable, AcmSubtypeSACMStable, Buff);
      HasError = 1;
  }
  // Check header len, must be 0xA1, 0xE0 or 0x3A0
  //
  GetValueAtOffset(BIN32_fh, Header_AcmHeaderLenOffset, &Buff, sizeof(DWORD), 0x1, SEEK_SET);
  HeaderLen = Buff; //Copy value, we will need it later
  if (Buff != HeaderLenLegacyStable && Buff != HeaderLenCBnTStable && Buff != HeaderLenStable) {
      printf("\nACM Header:\nIncorrect ACM Header Size\nExpected: 0x%X (legacy), 0x%X or 0x%X (current); found: 0x%X\n", HeaderLenLegacyStable, HeaderLenCBnTStable, HeaderLenStable, Buff);
      HasError = 1;
  }

  // Check header major version, must be 0x00, 0x0300 or 0x0400 depending on version
  GetValueAtOffset(BIN32_fh, Header_AcmHeaderVersionOffset, &Buff, sizeof(DWORD), 0x1, SEEK_SET);
  //Check version agains HeaderLength fields (it IS NOT the size of the entire header, just up to the scratch field)
  //Version 0x00
  if ((Buff & 0xFF0000) == HeaderVersionLegacyStable) {
      //size must be: 0xA1
      if (HeaderLen != HeaderLenLegacyStable) {
          printf("\nACM Header version 0x%X\nIncorrect header size.\nExpected: 0x0%X; found: 0x%X", Buff, HeaderLenLegacyStable, HeaderLen);
          HasError = 1;
    }
  }
  //Version 0x300
  else if ((Buff & 0xFF0000) == HeaderVersionCBnTStable) {
    //size must be: 0xE0
      if (HeaderLen != HeaderLenCBnTStable) {
          printf("\nACM Header version 0x%X\nIncorrect header size.\nExpected: 0x0%X; found: 0x%X", Buff, HeaderLenCBnTStable, HeaderLen);
          HasError = 1;
      }
  }
  //Version 0x400
  else if ((Buff & 0xFF0000) == HeaderVersionStable) {
      //size must be: 0x3A0
      if (HeaderLen != HeaderLenStable) {
          printf("\nACM Header version 0x%X\nIncorrect header size.\nExpected: 0x0%X; found: 0x%X", Buff, HeaderLenStable, HeaderLen);
          HasError = 1;
      }
  }
  //No valid version read
  else {
      printf("\nACM Header:\nIncorrect ACM Header Version\nExpected: 0x%X (legacy), 0x%X or 0x%X (current); found: 0x%X\n", HeaderVersionLegacyStable, HeaderVersionCBnTStable, HeaderVersionStable, Buff);
      HasError = 1;
  }
  return HasError;
}


//---------------------------------------------------------------
// Check ACM Info Table for known values
//---------------------------------------------------------------
int CheckAcmInfoTable(FILE *BIN32_fh) {
    DWORD Buff = 0x00;
    BOOL HasError = 0x00;
    DWORD Offset = 0x00;
    int Count = 0x0;

    // Check UUIDs at the beginning of the Info Table
    for (int i = 0; i < 4; i++) {
        GetValueAtOffset(BIN32_fh, InfoTable_UUID0Offset + Offset, &Buff, sizeof(DWORD), 0x1, SEEK_SET);
        if (Buff != InfoTable_UUID[i]) {
            printf("\nACM Info Table:\nUnrecognized UUID at offset 0x%X of the Info Table./nFound: 0x%X; expected: 0x%X.", Offset, Buff, InfoTable_UUID[i]);
            HasError = 1;
        }
        Offset += 0x4;
    }

    // Look into Chipset ID table and check VIDs
    // First read info table to see where the table is
    GetValueAtOffset(BIN32_fh, InfoTable_ChipsetIdListOffset, &Buff, sizeof (DWORD), 0x1, SEEK_SET);
    Offset = Buff; // Points to chipset id list count value
    GetValueAtOffset(BIN32_fh, Offset, &Buff, sizeof(DWORD), 0x1, SEEK_SET);
    Count = Buff;
    if (Count > 0x2970) {
        printf("\nACM Info Table:\nChipsetIDList table count too large\nCount value: 0x%X", Count);
        HasError = 1;
    }
    Offset += 0x4; // Now move the offset to the beginning of the chipset id list
    for (Count; Count > 0 && Count < 0x2970; Count--) { // If count is larger that 0x2970, this structure would be longer than the entire BIN32_fh
        // Now read Vendor ID, it must be 0x8086 and is located at offset 4 in the list
        GetValueAtOffset(BIN32_fh, Offset+0x4, &Buff, sizeof(WORD), 0x1, SEEK_SET);
        if (Buff != ChipsetID_VendorID) {
            printf("\nACM Info Table:\nChipsetIDList table Vendor ID incorrect.\nExpected: 0x%X; found: 0x%X.\n", ChipsetID_VendorID, Buff);
            HasError = 1;
        }
        Offset += 0x10; // Move offset to the next position in the chipset table
    }

    // Look into ProcessorIDList and check count, should be less than 5
    GetValueAtOffset(BIN32_fh, InfoTable_ProcessorIdListOffset, &Buff, sizeof(DWORD), 0x1, SEEK_SET);
    Offset = Buff; // Buff contains the offset of the ProcessorIDList table (count value)
    GetValueAtOffset(BIN32_fh, Offset, &Buff, sizeof(DWORD), 0x1, SEEK_SET); // Read count of entries
    if (Buff > 5) {
        printf("\nACM Info Table:\nProcessorIDList count value incorrect.\nExpected count value < 5; found: 0x%X\n", Buff);
        HasError = 1;
    }

    // Look into TPMInfoList
    GetValueAtOffset(BIN32_fh, InfoTable_TPMInfoListOffset, &Buff, sizeof(DWORD), 0x1, SEEK_SET);
    Offset = Buff;
    // Capabilities should have bits 31:7 set to 0, so capabilities should be at most 0x7F
    // Bits 5:2 cannot be 0b0000 - illegal, check that too
    GetValueAtOffset(BIN32_fh, Offset, &Buff, sizeof(DWORD), 0x1, SEEK_SET);
    if (Buff > 0x7F) {
        printf("\nACM Info Table: \nIncorrect TPM Capabilties\nExpected values less than 0x7F; found: 0x%X\n", Buff);
        HasError = 1;
        DWORD mask = 0x3C;
        if ((Buff & mask) == 0x00) {
            printf("\nACM Info Table: \nIncorrect value in TPM Capabilties\nExpected value > 0; found: 0x%X\n", (Buff & mask));
            HasError = 1;
        }
    }
    if ((Buff & 0x40) == 0) {
        // Force Capabilities[6] to 1
        Buff = Buff | 0x40;
        fflush(BIN32_fh);
        fseek(BIN32_fh, Offset, SEEK_SET);
        fwrite((const void *) &Buff, sizeof(DWORD), 0x1, BIN32_fh);
    }

    // Get count of algorithms
    Offset += 0x4;
    GetValueAtOffset(BIN32_fh, Offset, &Buff, sizeof(WORD), 0x1, SEEK_SET);
    Count = Buff;
    if (Count > 0x44) {
        printf("\nACM Info Table:\nCount of algorithm IDs larger than overall number of IDs defined for TPM 2.0 (0x0045).\nCount value: 0x%X\n", Count);
        HasError = 1;
    }
    Offset += 0x2;
    for (Count; Count > 0 && Count < 0x45; Count--) {  // TPM 2.0 spec only defines TPM_ALG_ items to 0x0044, so any number larger than that is nonsensical
        GetValueAtOffset(BIN32_fh, Offset, &Buff, sizeof(WORD), 0x1, SEEK_SET);
        switch (Buff)
        {
        case TPM_ALG_RSA:
            Offset += 2;
            continue;
        case TPM_ALG_SHA:
            Offset += 2;
            continue;
        case TPM_ALG_SHA256:
            Offset += 2;
            continue;
        case TPM_ALG_SHA384:
            Offset += 2;
            continue;
        case TPM_ALG_SHA512:
            Offset += 2;
            continue;
        case TPM_ALG_SM3:
            Offset += 2;
            continue;
        case TPM_ALG_SM4:
            Offset += 2;
            continue;
        case TPM_ALG_RSASSA:
            Offset += 2;
            continue;
        case TPM_ALG_RSAPSS:
            Offset += 2;
            continue;
        case TPM_ALG_ECDSA:
            Offset += 2;
            continue;
        case TPM_ALG_SM2:
            Offset += 2;
            continue;
        default:
            printf("\nACM Info Table:\nAlgorithmID unrecognized algorithm ID detected: 0x%X\n", Buff);
            HasError = 1;
            break;
        }
    }

    return HasError;
}

//---------------------------------------------------------------
// Find value in buffer
//---------------------------------------------------------------
UINT8 *FindInMem(const void *buffer, size_t buff_size, const void *sub_buffer, size_t sub_size) {
    /* 
      Something like memmem but worse.

      IN: ptr to a larger buffer (will look for pattern here)
      IN: size of the larger buffer
      IN: ptr to a smaller buffer (this is the pattern we will look for)
      IN: size of the smaller buffer.
      OUT: ptr to where in larger buffer the pattern starts or NULL if not found or error
    */
    UINT8 *ptr = NULL;
    if (buffer == NULL || sub_buffer == NULL) {
        return NULL;
    }
    if (buff_size < sub_size) {
        return NULL;
    }
    ptr = (UINT8 *) buffer;
    while (TRUE)
    {
        ptr = memchr((const void *)ptr, ((UINT8 *)sub_buffer)[0], buff_size - (ptr - (UINT8 *)buffer));
        if (ptr == NULL) {
            return NULL;
        }
        if (ptr && (memcmp((const void *)ptr, sub_buffer, sub_size) == 0)) {
            return ptr;
        }
        ptr++;
    }
}

boolean fileExists(const char *path) {
    if (path == NULL) {
        printf("Error: undefined path to file.\n");
        return FALSE;
    }
    if (GetFileAttributes(path) == INVALID_FILE_ATTRIBUTES) {
        printf("Error: %s not found.\n", path);
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------
// Convert bytes to their representation in UTF16
//---------------------------------------------------------------
boolean Hex2Utf16(BYTE *in, char16_t *out) {
    char16_t *p = out;
    BYTE buffer[6][3] = { {'\0'} }; // There will be 6 UTF16 strings, each will have 3 bytes (2 for values and NULL)

    //Convert to hex strings with leading zeroes
    for (UINT16 i = 0; i < 6; i++) {
        sprintf(buffer[i], "%02X", in[i]);
    }
    //Convert to UTF16 strings
    for (UINT16 i = 0; i < 6; i++) {
        for (UINT16 j = 0; j < 2; j++) {
            *p = (char16_t)buffer[i][j];
            p++;
        }
    }
    return TRUE;
}

boolean writeTpmlDigest(FILE *fp) {
    DWORD AcmEntryPoint = 0x0;
    DWORD fileOffset = 0x0;
    size_t length = 0;
    size_t hashLength = 0;

    fseek(fp, Header_AcmEntryOffset, SEEK_SET);
    fread((void *)&AcmEntryPoint, sizeof(DWORD), 1, fp);

    //Set current position to begin of com_data
    //New COM_DATA is 5*UINT32 and TPML_DIGEST_VALUES_MAX
    fileOffset = AcmEntryPoint - SIZE_OF_COM_DATA;
    fseek(fp, fileOffset, SEEK_SET);

    // Write count
    fwrite((const void *) &CrtmVersionDigests.count, sizeof(UINT32), 1, fp);

    //Move offset
    fileOffset += sizeof(CrtmVersionDigests.count);
    fseek(fp, fileOffset, SEEK_SET);

    for (UINT8 i = 0; i < MAX_HASH_COUNT; i++) {
        //byteswap hashLength, because it's big endian in TPML_DIGEST_VALUES
        hashLength = getHashDigestSize(_byteswap_ushort(CrtmVersionDigests.digests[i].hashAlg));
        if (hashLength == 0) {
            printf("Error: cannot write digest, digest size == 0.");
            return FALSE;
        }
        length = sizeof(CrtmVersionDigests.digests[i].hashAlg) + hashLength;
        fwrite((const void *)&CrtmVersionDigests.digests[i], length, 1, fp );
        fileOffset += length;
        //Move to next position
        fseek(fp, fileOffset, SEEK_SET);
    }
    return TRUE;
}

//---------------------------------------------------------------
// Handle EV_S_CRTM_VERSION event i.e. hash Date and ACM SVN
//---------------------------------------------------------------
int HashEvScrtmVersion(FILE *fp) {
    BYTE ScrtmConcat[6] = {0}; // This is for data copied from ACM binary
    char16_t ScrtmDateSvn[13] = {'\0'}; // This is the buffer that will be hashed

    //Read ACM date and SVN to buffer, then ACM_ENTRY_POINT
    fseek(fp, Header_AcmDateOffset, SEEK_SET);
    fread((void *)&ScrtmConcat, sizeof(UINT32), 1, fp);
    fseek(fp, Header_AcmAcmSvnOffset, SEEK_SET);
    fread((void *) (ScrtmConcat + sizeof(UINT32)), sizeof(UINT16), 1, fp);

    Hex2Utf16(ScrtmConcat, ScrtmDateSvn);
    CrtmVersionDigests.count = _byteswap_ulong(MAX_HASH_COUNT);
    for (UINT8 i = 0; i < ARRAYSIZE(SCRTMHashAlgs); i++) {
        HashCrtmVersionData((const BYTE *)ScrtmDateSvn, sizeof(ScrtmDateSvn), SCRTMHashAlgs[i]);
    }
    if (writeTpmlDigest(fp))
        return 0;
    return 1;
}