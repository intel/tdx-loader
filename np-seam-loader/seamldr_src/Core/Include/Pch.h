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

#ifndef PCH_H
#define PCH_H

#define HECI1_DEV     0x16   //CNL

#define CDF_LT_DEV_ID 0x18dc //CDF DEV ID
#define CDF_HECI1_DEV 0x18   //CDF

#define MISC_SHDW_REG 0x44
//
// Boot guard definitions.
// Sighting #3865107 Start
//
  #define FWSTS1 0x4C

typedef struct {
  UINT32 other   : 16;
  UINT32 op_mode : 4;
  UINT32 other2  : 12;
} fwsts1_t;

    #define SPS_FW 0xF

//  #define FWSTS4                  0x64
#define HOST_FW_STS_1_REG          0x40
#define HOST_FW_STS_2_REG          0x48
#define HOST_FW_STS_3_REG          0x60
#define HECI1_FW_SKU_SPS           0x6
#define SKU_MASK                   0x70
#define HOST_FW_STS_4_REG          0x64
#define HOST_FW_STS_5_REG          0x68
#define HOST_FW_STS_6_REG          0x6C
    #define BTG_FACB               BIT0
    #define BTG_PBE                BIT3
    #define BTG_ENF_MSK            (BIT7 | BIT6)
    #define BTG_ENF_IMM_SHUTDOWN   (BIT7 | BIT6)

#define LPC_BRIDGE_DEV             0x1F
  #define PCI_CMD_REG              0x04
  #define PCI_BAR_REG              0x10
  #define ACPI_BAR_REG             0x40
  #define ACPI_CONTROL_REG         0x44
  #define ACPI_PWRM_BAR_REG        0x48
  #define IOD_IOE_REG              0x80
    #define  B_PCH_LPC_ENABLES_ME2 0x02000
    #define  B_PCH_LPC_ENABLES_SE  0x01000
    #define  B_PCH_LPC_ENABLES_ME1 0x00800
    #define  B_PCH_LPC_ENABLES_KE  0x00400
    #define  B_PCH_LPC_ENABLES_HGE 0x00200
    #define  B_PCH_LPC_ENABLES_LGE 0x00100
    #define  B_PCH_LPC_ENABLES_FDE 0x00008
    #define  B_PCH_LPC_ENABLES_PPE 0x00004
    #define  B_PCH_LPC_ENABLES_CBE 0x00002
    #define  B_PCH_LPC_ENABLES_CAE 0x00001
  #define LGIR1_REG                0x84
  #define LGIR2_REG                0x88
  #define BIOS_DECODE_REG          0xD8
  #define BIOS_CONTROL_REG         0xDC
    #define LOCK_ENABLE            BIT1
    #define WRITE_PROTECT_DISABLE  BIT0

#define PCH_PCR_FUNC               1
#define PCH_ACPI_FUNC              2
#if !defined (PCH_PCR_BASE)
#define PCH_PCR_BASE               0xFD000000
#endif
// Moved to project specific folder starting with EGS
//#define PCH_PCR_DMI_LPCIOD        0xEF2770
//#define PCH_PCR_DMI_LPCIOE        0xEF2774
//#define PCH_PCR_DMI_ACPIBASE      0xEF27B4
//  #define   DMI_ACPIBASE_MASK     0xFC0000
//#define PCH_PCR_DMI_ACPIDEST      0xEF27B8
//  #define   DMI_ACPIDEST_ID_LBG   0x23A8
#define LBG_GEN_PMCON_A             0xA0
#define LBG_GEN_PMCON_B             0xA4
 #define LBG_RTC_PWR_STS            BIT2
 #define LBG_PWR_FLR                BIT1

#define PCH_DEV_31                  0x1F

#define CNL_DEV_31                  0x1F
#define CNL_ACPI_BAR_REG            0x10
#define CNL_ACPI_BAR_HIGH_REG       0x14
#define ICL_ACPI_BAR_ADDR           0xfe000000
#define GEN_PMCON_A                 0x1020
#define GEN_PMCON_B                 0x1024

#define CNL_ACPI_BAR1_REG           0x18
#define CNL_ACPI_BAR1_HIGH_REG      0x1C

#define ACPI_IO_PM1_STS             0x00
  #define B_ACPI_IO_PM1_STS_RTC     0x0400
#define ACPI_IO_PM1_EN              0x02
  #define B_ACPI_IO_PM1_EN_RTC      0x0400
#define ACPI_IO_PM1_CNT             0x04
  #define B_ACPI_IO_PM1_CNT_SLP_EN  0x00002000
  #define B_ACPI_IO_PM1_CNT_SLP_TYP 0x00001C00
  #define V_ACPI_IO_PM1_CNT_S5      0x00001C00

#define FLASH_CONTROLLER_FUNC       5
  #define SPI_BIOS_CONTROL_REG      0xDC
    #define TOP_SWAP_STS            BIT4

typedef struct {
  UINT32 other      : 10;
  UINT32 sleep_type : 3;
  UINT32 other2     : 19;
} ACPI_IO_PM1_CNT_t;

#define IOD_IOE_REG_INIT      0x30010000
#define PCH_ACPI_BASE_ADDRESS 0x0400 // ACPI Power Management I/O Register Base Address

#define ME_DISABLED           0xFFFFFFFF

UINT32 ReadHeciDeviceDwordRegister(UINT32);
void InitializePch();
void EnablePchLpcDecode();
void RestorePch();

//added for UART support
#define PCI_CONFIG_ADDRESS 0x80000060
#define PCIEX_BASE_ADDRESS 0xE0000000
#define UART2_DEV          0x19
#define UART2_FUNC         0x2
#define UART2_BAR          0xFE036000
#define UART2_RESET_OFFSET 0x204
#define UART2_CLK_OFFSET   0x200

#endif
