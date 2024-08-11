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

#ifndef COMSRV_H
#define COMSRV_H
          
//-----------------------------------------------------------------------------
//
//                            WARNING!      
// 
// Only unique offsets must be defined here. Offsets common for all
// platforms shall be defined in RootComplex.h or Pch.h files. 
//
//-----------------------------------------------------------------------------

//
// MCHBAR
//

#define MCH_REGBAR_OFFSET                                    0x5420
#define MCH_LOCK_OFFSET                                      0x50FC
#define MCH_UMAGFXBASE_OFFSET                                0x6010
#define MCH_UMAGFXLIMIT_OFFSET                               0x6018
#define MCH_UMAGFXCTL_OFFSET                                 0x6020

#define MCH_REGBAR_OFFSET                                    0x5420
#define MCH_IPUVTDLBAR_OFFSET                                0x7880
#define MCH_IPUVTDHBAR_OFFSET                                0x7884

#define MCHBAR_CH0_CR_MC_INIT_STATE_0_0_0_MCHBAR             0x4254 // Channel 0 rank occupancy in bits [7:0]
  #define MAX_RC_BITS                                          0xFF // Max Rank Occupancy bits
#define MCHBAR_CH1_CR_MC_INIT_STATE_0_0_0_MCHBAR             0x4654 // Channel 1 rank occupancy in bits [7:0]
#define MCDECS_CR_MAD_INTER_CHANNEL_0_0_0_MCHBAR_MCMAIN      0x5000 // Channel assignment
#define MCDECS_CR_MAD_INTRA_CH0_0_0_0_MCHBAR_MCMAIN          0x5004 // Address decoder intra channel cfg reg
#define MCDECS_CR_MAD_INTRA_CH1_0_0_0_MCHBAR_MCMAIN          0x5008 // Address decoder intra channel cfg reg
#define MCDECS_CR_MAD_DIMM_CH0_0_0_0_MCHBAR_MCMAIN           0x500C // Address decode DIMM parameters
#define MCDECS_CR_MAD_DIMM_CH1_0_0_0_MCHBAR_MCMAIN           0x5010 // Address decode DIMM parameters
#define MCDECS_CR_CHANNEL_HASH_0_0_0_MCHBAR_MCMAIN           0x5024 // Channel Selection Hash Register
#define MCDECS_CR_MC_INIT_STATE_G_0_0_0_MCHBAR_MCMAIN        0x5030 // Init register
#define MCDECS_CR_MRC_REVISION_0_0_0_MCHBAR_MCMAIN           0x5034 // BIOS MRC Revision ???
#define MCDECS_CR_MC_LOCK_0_0_0_MCHBAR_MCMAIN                0x50FC // Lock register

#endif
