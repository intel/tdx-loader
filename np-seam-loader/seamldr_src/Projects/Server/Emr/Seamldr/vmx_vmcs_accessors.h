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

// AUTOMATICALLY GENERATED FILE - DO NOT MODIFY //

#ifndef __RPC_B0_VMX_VMCS_ACCESSORS_H__
#define __RPC_B0_VMX_VMCS_ACCESSORS_H__

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_IDT_Vector_ErrorCode
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_IDT_Vector_ErrorCode()
/// @brief  Returns the value of the <tt> VM_Exit_IDT_Vector_ErrorCode </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_IDT_Vector_ErrorCode </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_IDT_Vector_ErrorCode(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IDT_VECTOR_ERRORCODE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_IDT_Vector_ErrorCode()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_IDT_Vector_ErrorCode </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_IDT_Vector_ErrorCode field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_IDT_Vector_ErrorCode(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IDT_VECTOR_ERRORCODE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Hlat_Plr_Pfx_Size
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Hlat_Plr_Pfx_Size()
/// @brief  Returns the value of the <tt> Hlat_Plr_Pfx_Size </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Hlat_Plr_Pfx_Size </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Hlat_Plr_Pfx_Size(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HLAT_PLR_PFX_SIZE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Hlat_Plr_Pfx_Size()
/// @brief  Writes value <tt> val </tt> into the the <tt> Hlat_Plr_Pfx_Size </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Hlat_Plr_Pfx_Size field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Hlat_Plr_Pfx_Size(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HLAT_PLR_PFX_SIZE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR3_Target_Count
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR3_Target_Count()
/// @brief  Returns the value of the <tt> CR3_Target_Count </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> CR3_Target_Count </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR3_Target_Count(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_COUNT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR3_Target_Count()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR3_Target_Count </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.CR3_Target_Count field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR3_Target_Count(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_COUNT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_ES_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_ES_Selector()
/// @brief  Returns the value of the <tt> Host_ES_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Host_ES_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_ES_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_ES_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_ES_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_ES_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Host_ES_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_ES_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_ES_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Saved_Working_VMCS_Ptr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Saved_Working_VMCS_Ptr()
/// @brief  Returns the value of the <tt> Guest_Saved_Working_VMCS_Ptr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> void*    </tt> read from the <tt> Guest_Saved_Working_VMCS_Ptr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Saved_Working_VMCS_Ptr(VMCS_T_PTR)  \
  (*((void **) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SAVED_WORKING_VMCS_POINTER_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Saved_Working_VMCS_Ptr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Saved_Working_VMCS_Ptr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             void*    value to be written into the VMCS.Guest_Saved_Working_VMCS_Ptr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Saved_Working_VMCS_Ptr(VMCS_T_PTR, VAL)  \
  (*((void **) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SAVED_WORKING_VMCS_POINTER_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_IO_RCX
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_IO_RCX()
/// @brief  Returns the value of the <tt> VM_Exit_IO_RCX </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VM_Exit_IO_RCX </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_IO_RCX(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_RCX_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_IO_RCX()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_IO_RCX </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VM_Exit_IO_RCX field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_IO_RCX(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_RCX_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IA32_EFER
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IA32_EFER()
/// @brief  Returns the value of the <tt> Host_IA32_EFER </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_IA32_EFER </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IA32_EFER(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_EFER_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IA32_EFER()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IA32_EFER </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_IA32_EFER field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IA32_EFER(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_EFER_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_Instruction_Info
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_Instruction_Info()
/// @brief  Returns the value of the <tt> VM_Exit_Instruction_Info </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_Instruction_Info </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_Instruction_Info(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_INSTRUCTION_INFO_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_Instruction_Info()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_Instruction_Info </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_Instruction_Info field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_Instruction_Info(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_INSTRUCTION_INFO_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_RIP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_RIP()
/// @brief  Returns the value of the <tt> Host_RIP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_RIP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_RIP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_RIP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_RIP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_RIP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_RIP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_RIP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_RIP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Secondary_Exit_CTLS
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Secondary_Exit_CTLS()
/// @brief  Returns the value of the <tt> Secondary_Exit_CTLS </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Secondary_Exit_CTLS </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Secondary_Exit_CTLS(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_SECONDARY_EXIT_CTLS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Secondary_Exit_CTLS()
/// @brief  Writes value <tt> val </tt> into the the <tt> Secondary_Exit_CTLS </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Secondary_Exit_CTLS field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Secondary_Exit_CTLS(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_SECONDARY_EXIT_CTLS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_FS_ARbyte
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_FS_ARbyte()
/// @brief  Returns the value of the <tt> Guest_FS_ARbyte </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_FS_ARbyte </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_FS_ARbyte(VMCS_T_PTR) hal_read_guest_arbyte((VMCS_T_PTR), VMX_GUEST_FS_ARBYTE_OFFSET)

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_FS_ARbyte()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_FS_ARbyte </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_FS_ARbyte field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_FS_ARbyte(VMCS_T_PTR, VAL) hal_write_guest_arbyte((VMCS_T_PTR), VMX_GUEST_FS_ARBYTE_OFFSET, (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// MSR_Bitmap_PhyPtr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_MSR_Bitmap_PhyPtr()
/// @brief  Returns the value of the <tt> MSR_Bitmap_PhyPtr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> MSR_Bitmap_PhyPtr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_MSR_Bitmap_PhyPtr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_MSR_BITMAP_PHYPTR_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_MSR_Bitmap_PhyPtr()
/// @brief  Writes value <tt> val </tt> into the the <tt> MSR_Bitmap_PhyPtr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.MSR_Bitmap_PhyPtr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_MSR_Bitmap_PhyPtr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_MSR_BITMAP_PHYPTR_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Entry_Exception_ErrorCode
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Entry_Exception_ErrorCode()
/// @brief  Returns the value of the <tt> VM_Entry_Exception_ErrorCode </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Entry_Exception_ErrorCode </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Entry_Exception_ErrorCode(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_EXCEPTION_ERRORCODE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Entry_Exception_ErrorCode()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Entry_Exception_ErrorCode </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Entry_Exception_ErrorCode field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Entry_Exception_ErrorCode(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_EXCEPTION_ERRORCODE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_SS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_SS_Selector()
/// @brief  Returns the value of the <tt> Host_SS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Host_SS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_SS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_SS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_SS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_SS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Host_SS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_SS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_SS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_GS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_GS_Selector()
/// @brief  Returns the value of the <tt> Host_GS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Host_GS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_GS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_GS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_GS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_GS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Host_GS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_GS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_GS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// EPTP_INDEX
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_EPTP_INDEX()
/// @brief  Returns the value of the <tt> EPTP_INDEX </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> EPTP_INDEX </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_EPTP_INDEX(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EPTP_INDEX_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_EPTP_INDEX()
/// @brief  Writes value <tt> val </tt> into the the <tt> EPTP_INDEX </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.EPTP_INDEX field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_EPTP_INDEX(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EPTP_INDEX_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_Instruction_Length
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_Instruction_Length()
/// @brief  Returns the value of the <tt> VM_Exit_Instruction_Length </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_Instruction_Length </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_Instruction_Length(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_INSTRUCTION_LENGTH_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_Instruction_Length()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_Instruction_Length </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_Instruction_Length field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_Instruction_Length(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_INSTRUCTION_LENGTH_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// POSTED_INTErrUPT_DESCRIPTOR_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_POSTED_INTErrUPT_DESCRIPTOR_Address()
/// @brief  Returns the value of the <tt> POSTED_INTErrUPT_DESCRIPTOR_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> POSTED_INTErrUPT_DESCRIPTOR_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_POSTED_INTErrUPT_DESCRIPTOR_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_POSTED_INTErrUPT_DESCRIPTOR_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> POSTED_INTErrUPT_DESCRIPTOR_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.POSTED_INTErrUPT_DESCRIPTOR_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_POSTED_INTErrUPT_DESCRIPTOR_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_POSTED_INTERRUPT_DESCRIPTOR_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_TR_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_TR_Base()
/// @brief  Returns the value of the <tt> Guest_TR_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_TR_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_TR_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_TR_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_TR_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_TR_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_TR_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_TR_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_TR_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Execution_Control_Secondary_Proc_Based
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Execution_Control_Secondary_Proc_Based()
/// @brief  Returns the value of the <tt> VM_Execution_Control_Secondary_Proc_Based </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Execution_Control_Secondary_Proc_Based </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Execution_Control_Secondary_Proc_Based(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_SECONDARY_PROC_BASED_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Execution_Control_Secondary_Proc_Based()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Execution_Control_Secondary_Proc_Based </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Execution_Control_Secondary_Proc_Based field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Execution_Control_Secondary_Proc_Based(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_SECONDARY_PROC_BASED_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_DR7
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_DR7()
/// @brief  Returns the value of the <tt> Guest_DR7 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_DR7 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_DR7(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_DR7_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_DR7()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_DR7 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_DR7 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_DR7(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_DR7_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_VM_Entry_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_VM_Entry_Control()
/// @brief  Returns the value of the <tt> PPPE_VM_Entry_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_VM_Entry_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_VM_Entry_Control(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_VM_ENTRY_CONTROL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_VM_Entry_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_VM_Entry_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_VM_Entry_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_VM_Entry_Control(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_VM_ENTRY_CONTROL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VMCS_Launch_State
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VMCS_Launch_State()
/// @brief  Returns the value of the <tt> VMCS_Launch_State </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VMCS_Launch_State </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VMCS_Launch_State(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMCS_LAUNCH_STATE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VMCS_Launch_State()
/// @brief  Writes value <tt> val </tt> into the the <tt> VMCS_Launch_State </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VMCS_Launch_State field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VMCS_Launch_State(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMCS_LAUNCH_STATE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_CR4
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_CR4()
/// @brief  Returns the value of the <tt> Host_CR4 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_CR4 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_CR4(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR4_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_CR4()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_CR4 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_CR4 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_CR4(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR4_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Virtual_APIC_Page_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Virtual_APIC_Page_Address()
/// @brief  Returns the value of the <tt> Virtual_APIC_Page_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Virtual_APIC_Page_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Virtual_APIC_Page_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VIRTUAL_APIC_PAGE_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Virtual_APIC_Page_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> Virtual_APIC_Page_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Virtual_APIC_Page_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Virtual_APIC_Page_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VIRTUAL_APIC_PAGE_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_Exception_Inhibits
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_Exception_Inhibits()
/// @brief  Returns the value of the <tt> PPPE_Guest_Exception_Inhibits </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_Guest_Exception_Inhibits </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_Guest_Exception_Inhibits(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_EXCEPTION_INHIBITS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_Exception_Inhibits()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_Exception_Inhibits </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_Guest_Exception_Inhibits field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_Exception_Inhibits(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_EXCEPTION_INHIBITS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vch_LIST_Physaddr_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Vch_LIST_Physaddr_Base()
/// @brief  Returns the value of the <tt> Vch_LIST_Physaddr_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Vch_LIST_Physaddr_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Vch_LIST_Physaddr_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VCH_LIST_PHYSADDR_BASE_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Vch_LIST_Physaddr_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Vch_LIST_Physaddr_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Vch_LIST_Physaddr_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Vch_LIST_Physaddr_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VCH_LIST_PHYSADDR_BASE_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pasid_High
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Pasid_High()
/// @brief  Returns the value of the <tt> Pasid_High </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Pasid_High </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Pasid_High(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PASID_HIGH_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Pasid_High()
/// @brief  Writes value <tt> val </tt> into the the <tt> Pasid_High </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Pasid_High field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Pasid_High(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PASID_HIGH_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR0_Guest_Host_Mask
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR0_Guest_Host_Mask()
/// @brief  Returns the value of the <tt> CR0_Guest_Host_Mask </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> CR0_Guest_Host_Mask </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR0_Guest_Host_Mask(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR0_GUEST_HOST_MASK_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR0_Guest_Host_Mask()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR0_Guest_Host_Mask </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.CR0_Guest_Host_Mask field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR0_Guest_Host_Mask(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR0_GUEST_HOST_MASK_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_Qualification
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_Qualification()
/// @brief  Returns the value of the <tt> VM_Exit_Qualification </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VM_Exit_Qualification </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_Qualification(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_QUALIFICATION_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_Qualification()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_Qualification </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VM_Exit_Qualification field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_Qualification(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_QUALIFICATION_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_RTIT_CTL
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_RTIT_CTL()
/// @brief  Returns the value of the <tt> Guest_RTIT_CTL </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_RTIT_CTL </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_RTIT_CTL(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RTIT_CTL_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_RTIT_CTL()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_RTIT_CTL </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_RTIT_CTL field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_RTIT_CTL(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RTIT_CTL_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// RSVD_64_BIT_Control_4
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_RSVD_64_BIT_Control_4()
/// @brief  Returns the value of the <tt> RSVD_64_BIT_Control_4 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> RSVD_64_BIT_Control_4 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_RSVD_64_BIT_Control_4(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_64_BIT_CONTROL_4_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_RSVD_64_BIT_Control_4()
/// @brief  Writes value <tt> val </tt> into the the <tt> RSVD_64_BIT_Control_4 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.RSVD_64_BIT_Control_4 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_RSVD_64_BIT_Control_4(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_64_BIT_CONTROL_4_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_FS_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_FS_Base()
/// @brief  Returns the value of the <tt> Guest_FS_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_FS_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_FS_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_FS_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_FS_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_FS_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_FS_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_FS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_FS_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VMCS_Caching_Arch_Ptr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VMCS_Caching_Arch_Ptr()
/// @brief  Returns the value of the <tt> VMCS_Caching_Arch_Ptr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> void*    </tt> read from the <tt> VMCS_Caching_Arch_Ptr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VMCS_Caching_Arch_Ptr(VMCS_T_PTR)  \
  (*((void **) (((uint8_t *) (VMCS_T_PTR)) + VMCS_CACHING_ARCH_PTR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VMCS_Caching_Arch_Ptr()
/// @brief  Writes value <tt> val </tt> into the the <tt> VMCS_Caching_Arch_Ptr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             void*    value to be written into the VMCS.VMCS_Caching_Arch_Ptr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VMCS_Caching_Arch_Ptr(VMCS_T_PTR, VAL)  \
  (*((void **) (((uint8_t *) (VMCS_T_PTR)) + VMCS_CACHING_ARCH_PTR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IA32_SYSENTER_ESP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IA32_SYSENTER_ESP()
/// @brief  Returns the value of the <tt> Host_IA32_SYSENTER_ESP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_IA32_SYSENTER_ESP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IA32_SYSENTER_ESP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_SYSENTER_ESP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IA32_SYSENTER_ESP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IA32_SYSENTER_ESP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_IA32_SYSENTER_ESP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IA32_SYSENTER_ESP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_SYSENTER_ESP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_IO_RSI
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_IO_RSI()
/// @brief  Returns the value of the <tt> VM_Exit_IO_RSI </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VM_Exit_IO_RSI </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_IO_RSI(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_RSI_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_IO_RSI()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_IO_RSI </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VM_Exit_IO_RSI field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_IO_RSI(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_RSI_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*  /*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VMCS_Caching_UArch_Info
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VMCS_Caching_UArch_Info()
/// @brief  Returns the value of the <tt> VMCS_Caching_UArch_Info </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> VMCS_Caching_UArch_Info </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VMCS_Caching_UArch_Info(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMCS_CACHING_UARCH_INFO_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VMCS_Caching_UArch_Info()
/// @brief  Writes value <tt> val </tt> into the the <tt> VMCS_Caching_UArch_Info </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.VMCS_Caching_UArch_Info field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VMCS_Caching_UArch_Info(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMCS_CACHING_UARCH_INFO_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_LDTR_ARbyte
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_LDTR_ARbyte()
/// @brief  Returns the value of the <tt> Guest_LDTR_ARbyte </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_LDTR_ARbyte </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_LDTR_ARbyte(VMCS_T_PTR) hal_read_guest_arbyte((VMCS_T_PTR), VMX_GUEST_LDTR_ARBYTE_OFFSET)

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_LDTR_ARbyte()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_LDTR_ARbyte </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_LDTR_ARbyte field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_LDTR_ARbyte(VMCS_T_PTR, VAL) hal_write_guest_arbyte((VMCS_T_PTR), VMX_GUEST_LDTR_ARBYTE_OFFSET, (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_TR_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_TR_Selector()
/// @brief  Returns the value of the <tt> Guest_TR_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_TR_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_TR_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_TR_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_TR_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_TR_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_TR_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_TR_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_TR_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_IDT_Vector_Field
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_IDT_Vector_Field()
/// @brief  Returns the value of the <tt> VM_Exit_IDT_Vector_Field </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_IDT_Vector_Field </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_IDT_Vector_Field(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IDT_VECTOR_FIELD_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_IDT_Vector_Field()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_IDT_Vector_Field </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_IDT_Vector_Field field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_IDT_Vector_Field(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IDT_VECTOR_FIELD_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_Lbr_CTL
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_Lbr_CTL()
/// @brief  Returns the value of the <tt> Guest_IA32_Lbr_CTL </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_Lbr_CTL </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_Lbr_CTL(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_LBR_CTL_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_Lbr_CTL()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_Lbr_CTL </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_Lbr_CTL field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_Lbr_CTL(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_LBR_CTL_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_FS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_FS_Selector()
/// @brief  Returns the value of the <tt> Host_FS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Host_FS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_FS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_FS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_FS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_FS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Host_FS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_FS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_FS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_FS_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_FS_Base()
/// @brief  Returns the value of the <tt> Host_FS_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_FS_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_FS_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_FS_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_FS_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_FS_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_FS_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_FS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_FS_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_DS_ARbyte
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_DS_ARbyte()
/// @brief  Returns the value of the <tt> Guest_DS_ARbyte </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_DS_ARbyte </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_DS_ARbyte(VMCS_T_PTR) hal_read_guest_arbyte((VMCS_T_PTR), VMX_GUEST_DS_ARBYTE_OFFSET)

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_DS_ARbyte()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_DS_ARbyte </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_DS_ARbyte field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_DS_ARbyte(VMCS_T_PTR, VAL) hal_write_guest_arbyte((VMCS_T_PTR), VMX_GUEST_DS_ARBYTE_OFFSET, (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// RSVD_32_BIT_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_RSVD_32_BIT_Control()
/// @brief  Returns the value of the <tt> RSVD_32_BIT_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> RSVD_32_BIT_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_RSVD_32_BIT_Control(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_32_BIT_CONTROL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_RSVD_32_BIT_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> RSVD_32_BIT_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.RSVD_32_BIT_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_RSVD_32_BIT_Control(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_32_BIT_CONTROL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// SPPTP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_SPPTP()
/// @brief  Returns the value of the <tt> SPPTP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> SPPTP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_SPPTP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_SPPTP_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_SPPTP()
/// @brief  Writes value <tt> val </tt> into the the <tt> SPPTP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.SPPTP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_SPPTP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_SPPTP_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_CS_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_CS_Limit()
/// @brief  Returns the value of the <tt> Guest_CS_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_CS_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_CS_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CS_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_CS_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_CS_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_CS_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_CS_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CS_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_PDPtr1
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_PDPtr1()
/// @brief  Returns the value of the <tt> Guest_PDPtr1 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_PDPtr1 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_PDPtr1(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PDPTR1_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_PDPtr1()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_PDPtr1 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_PDPtr1 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_PDPtr1(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PDPTR1_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_PDPtr0
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_PDPtr0()
/// @brief  Returns the value of the <tt> Guest_PDPtr0 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_PDPtr0 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_PDPtr0(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PDPTR0_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_PDPtr0()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_PDPtr0 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_PDPtr0 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_PDPtr0(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PDPTR0_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_MSR_Load_Count
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_MSR_Load_Count()
/// @brief  Returns the value of the <tt> VM_Exit_MSR_Load_Count </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_MSR_Load_Count </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_MSR_Load_Count(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_MSR_LOAD_COUNT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_MSR_Load_Count()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_MSR_Load_Count </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_MSR_Load_Count field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_MSR_Load_Count(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_MSR_LOAD_COUNT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_PDPtr2
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_PDPtr2()
/// @brief  Returns the value of the <tt> Guest_PDPtr2 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_PDPtr2 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_PDPtr2(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PDPTR2_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_PDPtr2()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_PDPtr2 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_PDPtr2 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_PDPtr2(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PDPTR2_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Hlatp
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Hlatp()
/// @brief  Returns the value of the <tt> Hlatp </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Hlatp </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Hlatp(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HLATP_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Hlatp()
/// @brief  Writes value <tt> val </tt> into the the <tt> Hlatp </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Hlatp field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Hlatp(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HLATP_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pconfig_ExitING
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Pconfig_ExitING()
/// @brief  Returns the value of the <tt> Pconfig_ExitING </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Pconfig_ExitING </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Pconfig_ExitING(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PCONFIG_EXITING_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Pconfig_ExitING()
/// @brief  Writes value <tt> val </tt> into the the <tt> Pconfig_ExitING </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Pconfig_ExitING field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Pconfig_ExitING(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PCONFIG_EXITING_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// EPTP_LIST_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_EPTP_LIST_Address()
/// @brief  Returns the value of the <tt> EPTP_LIST_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> EPTP_LIST_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_EPTP_LIST_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EPTP_LIST_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_EPTP_LIST_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> EPTP_LIST_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.EPTP_LIST_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_EPTP_LIST_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EPTP_LIST_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Entry_INTR_Info
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Entry_INTR_Info()
/// @brief  Returns the value of the <tt> VM_Entry_INTR_Info </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Entry_INTR_Info </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Entry_INTR_Info(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_INTR_INFO_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Entry_INTR_Info()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Entry_INTR_Info </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Entry_INTR_Info field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Entry_INTR_Info(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_INTR_INFO_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Td_Hkid
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Td_Hkid()
/// @brief  Returns the value of the <tt> Guest_Td_Hkid </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_Td_Hkid </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Td_Hkid(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_TD_HKID_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Td_Hkid()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Td_Hkid </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_Td_Hkid field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Td_Hkid(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_TD_HKID_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VMCS_Caching_Saved_Dirty_Bits
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VMCS_Caching_Saved_Dirty_Bits()
/// @brief  Returns the value of the <tt> VMCS_Caching_Saved_Dirty_Bits </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VMCS_Caching_Saved_Dirty_Bits </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VMCS_Caching_Saved_Dirty_Bits(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMCS_CACHING_SAVED_DIRTY_BITS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VMCS_Caching_Saved_Dirty_Bits()
/// @brief  Writes value <tt> val </tt> into the the <tt> VMCS_Caching_Saved_Dirty_Bits </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VMCS_Caching_Saved_Dirty_Bits field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VMCS_Caching_Saved_Dirty_Bits(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMCS_CACHING_SAVED_DIRTY_BITS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_GS_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_GS_Base()
/// @brief  Returns the value of the <tt> Host_GS_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_GS_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_GS_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_GS_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_GS_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_GS_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_GS_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_GS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_GS_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_EFER
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_EFER()
/// @brief  Returns the value of the <tt> Guest_IA32_EFER </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_EFER </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_EFER(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_EFER_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_EFER()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_EFER </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_EFER field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_EFER(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_EFER_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_CS_ARbyte
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_CS_ARbyte()
/// @brief  Returns the value of the <tt> Guest_CS_ARbyte </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_CS_ARbyte </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_CS_ARbyte(VMCS_T_PTR) hal_read_guest_arbyte((VMCS_T_PTR), VMX_GUEST_CS_ARBYTE_OFFSET)

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_CS_ARbyte()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_CS_ARbyte </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_CS_ARbyte field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_CS_ARbyte(VMCS_T_PTR, VAL) hal_write_guest_arbyte((VMCS_T_PTR), VMX_GUEST_CS_ARBYTE_OFFSET, (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PML_LoG_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PML_LoG_Address()
/// @brief  Returns the value of the <tt> PML_LoG_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PML_LoG_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PML_LoG_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PML_LOG_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PML_LoG_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> PML_LoG_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PML_LoG_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PML_LoG_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PML_LOG_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_Perf_Global_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_Perf_Global_Control()
/// @brief  Returns the value of the <tt> Guest_IA32_Perf_Global_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_Perf_Global_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_Perf_Global_Control(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_Perf_Global_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_Perf_Global_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_Perf_Global_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_Perf_Global_Control(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_PERF_GLOBAL_CONTROL_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_PDPtr3
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_PDPtr3()
/// @brief  Returns the value of the <tt> Guest_PDPtr3 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_PDPtr3 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_PDPtr3(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PDPTR3_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_PDPtr3()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_PDPtr3 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_PDPtr3 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_PDPtr3(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PDPTR3_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Instruction_ErrorCode
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Instruction_ErrorCode()
/// @brief  Returns the value of the <tt> VM_Instruction_ErrorCode </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Instruction_ErrorCode </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Instruction_ErrorCode(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_INSTRUCTION_ERRORCODE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Instruction_ErrorCode()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Instruction_ErrorCode </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Instruction_ErrorCode field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Instruction_ErrorCode(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_INSTRUCTION_ERRORCODE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IA32_S_Cet
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IA32_S_Cet()
/// @brief  Returns the value of the <tt> Host_IA32_S_Cet </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_IA32_S_Cet </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IA32_S_Cet(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_S_CET_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IA32_S_Cet()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IA32_S_Cet </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_IA32_S_Cet field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IA32_S_Cet(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_S_CET_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VMCS_Revision_ID
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VMCS_Revision_ID()
/// @brief  Returns the value of the <tt> VMCS_Revision_ID </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VMCS_Revision_ID </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VMCS_Revision_ID(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMCS_REVISION_ID_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VMCS_Revision_ID()
/// @brief  Writes value <tt> val </tt> into the the <tt> VMCS_Revision_ID </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VMCS_Revision_ID field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VMCS_Revision_ID(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMCS_REVISION_ID_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_MSR_Store_Count
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_MSR_Store_Count()
/// @brief  Returns the value of the <tt> VM_Exit_MSR_Store_Count </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_MSR_Store_Count </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_MSR_Store_Count(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_MSR_STORE_COUNT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_MSR_Store_Count()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_MSR_Store_Count </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_MSR_Store_Count field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_MSR_Store_Count(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_MSR_STORE_COUNT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_SYSENTER_CS
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_SYSENTER_CS()
/// @brief  Returns the value of the <tt> Guest_IA32_SYSENTER_CS </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_IA32_SYSENTER_CS </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_SYSENTER_CS(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_SYSENTER_CS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_SYSENTER_CS()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_SYSENTER_CS </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_IA32_SYSENTER_CS field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_SYSENTER_CS(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_SYSENTER_CS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Abort_Indicator
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Abort_Indicator()
/// @brief  Returns the value of the <tt> Abort_Indicator </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Abort_Indicator </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Abort_Indicator(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_ABORT_INDICATOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Abort_Indicator()
/// @brief  Writes value <tt> val </tt> into the the <tt> Abort_Indicator </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Abort_Indicator field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Abort_Indicator(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_ABORT_INDICATOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_CS_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_CS_Base()
/// @brief  Returns the value of the <tt> Guest_CS_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_CS_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_CS_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CS_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_CS_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_CS_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_CS_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_CS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CS_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_CS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_CS_Selector()
/// @brief  Returns the value of the <tt> Host_CS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Host_CS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_CS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_CS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_CS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Host_CS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_CS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR3_Target_Value_3
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR3_Target_Value_3()
/// @brief  Returns the value of the <tt> CR3_Target_Value_3 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> CR3_Target_Value_3 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR3_Target_Value_3(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_VALUE_3_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR3_Target_Value_3()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR3_Target_Value_3 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.CR3_Target_Value_3 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR3_Target_Value_3(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_VALUE_3_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR3_Target_Value_2
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR3_Target_Value_2()
/// @brief  Returns the value of the <tt> CR3_Target_Value_2 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> CR3_Target_Value_2 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR3_Target_Value_2(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_VALUE_2_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR3_Target_Value_2()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR3_Target_Value_2 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.CR3_Target_Value_2 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR3_Target_Value_2(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_VALUE_2_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR3_Target_Value_1
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR3_Target_Value_1()
/// @brief  Returns the value of the <tt> CR3_Target_Value_1 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> CR3_Target_Value_1 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR3_Target_Value_1(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_VALUE_1_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR3_Target_Value_1()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR3_Target_Value_1 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.CR3_Target_Value_1 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR3_Target_Value_1(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_VALUE_1_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR3_Target_Value_0
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR3_Target_Value_0()
/// @brief  Returns the value of the <tt> CR3_Target_Value_0 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> CR3_Target_Value_0 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR3_Target_Value_0(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_VALUE_0_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR3_Target_Value_0()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR3_Target_Value_0 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.CR3_Target_Value_0 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR3_Target_Value_0(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR3_TARGET_VALUE_0_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PAUSE_LoOP_ExitING_WINDOW
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PAUSE_LoOP_ExitING_WINDOW()
/// @brief  Returns the value of the <tt> PAUSE_LoOP_ExitING_WINDOW </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> PAUSE_LoOP_ExitING_WINDOW </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PAUSE_LoOP_ExitING_WINDOW(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PAUSE_LOOP_EXITING_WINDOW_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PAUSE_LoOP_ExitING_WINDOW()
/// @brief  Writes value <tt> val </tt> into the the <tt> PAUSE_LoOP_ExitING_WINDOW </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.PAUSE_LoOP_ExitING_WINDOW field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PAUSE_LoOP_ExitING_WINDOW(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PAUSE_LOOP_EXITING_WINDOW_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Entry_MSR_Load_PhyPtr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Entry_MSR_Load_PhyPtr()
/// @brief  Returns the value of the <tt> Entry_MSR_Load_PhyPtr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Entry_MSR_Load_PhyPtr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Entry_MSR_Load_PhyPtr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_ENTRY_MSR_LOAD_PHYPTR_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Entry_MSR_Load_PhyPtr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Entry_MSR_Load_PhyPtr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Entry_MSR_Load_PhyPtr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Entry_MSR_Load_PhyPtr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_ENTRY_MSR_LOAD_PHYPTR_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_PAT
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_PAT()
/// @brief  Returns the value of the <tt> Guest_IA32_PAT </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_PAT </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_PAT(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_PAT_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_PAT()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_PAT </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_PAT field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_PAT(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_PAT_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_VMCS_Child_Ptr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_VMCS_Child_Ptr()
/// @brief  Returns the value of the <tt> PPPE_VMCS_Child_Ptr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_VMCS_Child_Ptr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_VMCS_Child_Ptr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_VMCS_CHILD_POINTER_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_VMCS_Child_Ptr()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_VMCS_Child_Ptr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_VMCS_Child_Ptr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_VMCS_Child_Ptr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_VMCS_CHILD_POINTER_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_CR3
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_CR3()
/// @brief  Returns the value of the <tt> Host_CR3 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_CR3 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_CR3(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR3_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_CR3()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_CR3 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_CR3 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_CR3(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR3_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_CR0
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_CR0()
/// @brief  Returns the value of the <tt> Host_CR0 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_CR0 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_CR0(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR0_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_CR0()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_CR0 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_CR0 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_CR0(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_CR0_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_RBX
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_RBX()
/// @brief  Returns the value of the <tt> PPPE_Guest_RBX </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_RBX </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_RBX_OFFSET)))

#define Rd_PPPE_Guest_RBX_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_RBX(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RBX_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RBX_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_RBX_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_RBX_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_RBX_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_RBX_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_RBX_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_RBX_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_RBX_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_RBX_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_RBX_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_RBX_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_RBX_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_RBX_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_RBX_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_RBX()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_RBX </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_RBX field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_RBX(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RBX_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_RBX((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_RBX_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RBX_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_RBX_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_RBX_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_RBX_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBX_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_ES_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_ES_Base()
/// @brief  Returns the value of the <tt> Guest_ES_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_ES_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_ES_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_ES_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_ES_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_ES_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_ES_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_ES_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_ES_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// XSS_Exit_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_XSS_Exit_Control()
/// @brief  Returns the value of the <tt> XSS_Exit_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> XSS_Exit_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_XSS_Exit_Control(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_XSS_EXIT_CONTROL_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_XSS_Exit_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> XSS_Exit_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.XSS_Exit_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_XSS_Exit_Control(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_XSS_EXIT_CONTROL_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_SSP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_SSP()
/// @brief  Returns the value of the <tt> Host_SSP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_SSP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_SSP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_SSP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_SSP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_SSP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_SSP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_SSP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_SSP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Hidden_Pnd_Debug_Exception
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Hidden_Pnd_Debug_Exception()
/// @brief  Returns the value of the <tt> Guest_Hidden_Pnd_Debug_Exception </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_Hidden_Pnd_Debug_Exception </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Hidden_Pnd_Debug_Exception(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_HIDDEN_PND_DEBUG_EXCEPTION_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Hidden_Pnd_Debug_Exception()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Hidden_Pnd_Debug_Exception </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_Hidden_Pnd_Debug_Exception field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Hidden_Pnd_Debug_Exception(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_HIDDEN_PND_DEBUG_EXCEPTION_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_IO_RIP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_IO_RIP()
/// @brief  Returns the value of the <tt> VM_Exit_IO_RIP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VM_Exit_IO_RIP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_IO_RIP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_RIP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_IO_RIP()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_IO_RIP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VM_Exit_IO_RIP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_IO_RIP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_RIP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_VPID
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_VPID()
/// @brief  Returns the value of the <tt> Guest_VPID </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_VPID </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_VPID(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_VPID_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_VPID()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_VPID </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_VPID field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_VPID(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_VPID_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_SS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_SS_Selector()
/// @brief  Returns the value of the <tt> Guest_SS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_SS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_SS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_SS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_SS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_SS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_SS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_GDTR_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_GDTR_Base()
/// @brief  Returns the value of the <tt> Guest_GDTR_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_GDTR_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_GDTR_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GDTR_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_GDTR_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_GDTR_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_GDTR_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_GDTR_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GDTR_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Exit_MSR_Store_PhyPtr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Exit_MSR_Store_PhyPtr()
/// @brief  Returns the value of the <tt> Exit_MSR_Store_PhyPtr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Exit_MSR_Store_PhyPtr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Exit_MSR_Store_PhyPtr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EXIT_MSR_STORE_PHYPTR_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Exit_MSR_Store_PhyPtr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Exit_MSR_Store_PhyPtr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Exit_MSR_Store_PhyPtr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Exit_MSR_Store_PhyPtr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EXIT_MSR_STORE_PHYPTR_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// No_Commit_Threshold
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_No_Commit_Threshold()
/// @brief  Returns the value of the <tt> No_Commit_Threshold </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> No_Commit_Threshold </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_No_Commit_Threshold(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_NO_COMMIT_THRESHOLD_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_No_Commit_Threshold()
/// @brief  Writes value <tt> val </tt> into the the <tt> No_Commit_Threshold </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.No_Commit_Threshold field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_No_Commit_Threshold(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_NO_COMMIT_THRESHOLD_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_INTErrUPT_SSP_TABLE_Addr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_INTErrUPT_SSP_TABLE_Addr()
/// @brief  Returns the value of the <tt> Guest_IA32_INTErrUPT_SSP_TABLE_Addr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_INTErrUPT_SSP_TABLE_Addr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_INTErrUPT_SSP_TABLE_Addr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_INTERRUPT_SSP_TABLE_ADDR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_INTErrUPT_SSP_TABLE_Addr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_INTErrUPT_SSP_TABLE_Addr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_INTErrUPT_SSP_TABLE_Addr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_INTErrUPT_SSP_TABLE_Addr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_INTERRUPT_SSP_TABLE_ADDR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_CS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_CS_Selector()
/// @brief  Returns the value of the <tt> Guest_CS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_CS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_CS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_CS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_CS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_CS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_CS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_BNDCFGS
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_BNDCFGS()
/// @brief  Returns the value of the <tt> Guest_BNDCFGS </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_BNDCFGS </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_BNDCFGS(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_BNDCFGS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_BNDCFGS()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_BNDCFGS </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_BNDCFGS field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_BNDCFGS(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_BNDCFGS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_Exception_ErrorCode
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_Exception_ErrorCode()
/// @brief  Returns the value of the <tt> VM_Exit_Exception_ErrorCode </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_Exception_ErrorCode </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_Exception_ErrorCode(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_EXCEPTION_ERRORCODE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_Exception_ErrorCode()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_Exception_ErrorCode </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_Exception_ErrorCode field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_Exception_ErrorCode(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_EXCEPTION_ERRORCODE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_Control()
/// @brief  Returns the value of the <tt> VM_Exit_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_Control(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_CONTROL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_Control(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_CONTROL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_GS_ARbyte
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_GS_ARbyte()
/// @brief  Returns the value of the <tt> Guest_GS_ARbyte </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_GS_ARbyte </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_GS_ARbyte(VMCS_T_PTR) hal_read_guest_arbyte((VMCS_T_PTR), VMX_GUEST_GS_ARBYTE_OFFSET)

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_GS_ARbyte()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_GS_ARbyte </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_GS_ARbyte field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_GS_ARbyte(VMCS_T_PTR, VAL) hal_write_guest_arbyte((VMCS_T_PTR), VMX_GUEST_GS_ARBYTE_OFFSET, (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_TR_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_TR_Limit()
/// @brief  Returns the value of the <tt> Guest_TR_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_TR_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_TR_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_TR_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_TR_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_TR_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_TR_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_TR_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_TR_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_LDTR_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_LDTR_Limit()
/// @brief  Returns the value of the <tt> Guest_LDTR_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_LDTR_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_LDTR_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_LDTR_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_LDTR_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_LDTR_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_LDTR_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_LDTR_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_LDTR_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_RSP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_RSP()
/// @brief  Returns the value of the <tt> Guest_RSP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_RSP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_RSP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RSP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_RSP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_RSP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_RSP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_RSP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RSP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_TR_ARbyte
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_TR_ARbyte()
/// @brief  Returns the value of the <tt> Guest_TR_ARbyte </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_TR_ARbyte </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_TR_ARbyte(VMCS_T_PTR) hal_read_guest_arbyte((VMCS_T_PTR), VMX_GUEST_TR_ARBYTE_OFFSET)

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_TR_ARbyte()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_TR_ARbyte </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_TR_ARbyte field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_TR_ARbyte(VMCS_T_PTR, VAL) hal_write_guest_arbyte((VMCS_T_PTR), VMX_GUEST_TR_ARBYTE_OFFSET, (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_RIP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_RIP()
/// @brief  Returns the value of the <tt> Guest_RIP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_RIP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_RIP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RIP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_RIP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_RIP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_RIP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_RIP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RIP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// TSC_Offset
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_TSC_Offset()
/// @brief  Returns the value of the <tt> TSC_Offset </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> TSC_Offset </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_TSC_Offset(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_TSC_OFFSET_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_TSC_Offset()
/// @brief  Writes value <tt> val </tt> into the the <tt> TSC_Offset </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.TSC_Offset field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_TSC_Offset(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_TSC_OFFSET_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Shared_EPT_Ptr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Shared_EPT_Ptr()
/// @brief  Returns the value of the <tt> Guest_Shared_EPT_Ptr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_Shared_EPT_Ptr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Shared_EPT_Ptr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SHARED_EPT_POINTER_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Shared_EPT_Ptr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Shared_EPT_Ptr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_Shared_EPT_Ptr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Shared_EPT_Ptr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SHARED_EPT_POINTER_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR0_Read_Shadow
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR0_Read_Shadow()
/// @brief  Returns the value of the <tt> CR0_Read_Shadow </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> CR0_Read_Shadow </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR0_Read_Shadow(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR0_READ_SHADOW_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR0_Read_Shadow()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR0_Read_Shadow </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.CR0_Read_Shadow field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR0_Read_Shadow(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR0_READ_SHADOW_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inter_VM_IPI_Physaddr_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Inter_VM_IPI_Physaddr_Base()
/// @brief  Returns the value of the <tt> Inter_VM_IPI_Physaddr_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Inter_VM_IPI_Physaddr_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Inter_VM_IPI_Physaddr_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_INTER_VM_IPI_PHYSADDR_BASE_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Inter_VM_IPI_Physaddr_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Inter_VM_IPI_Physaddr_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Inter_VM_IPI_Physaddr_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Inter_VM_IPI_Physaddr_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_INTER_VM_IPI_PHYSADDR_BASE_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IA32_SYSENTER_CS
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IA32_SYSENTER_CS()
/// @brief  Returns the value of the <tt> Host_IA32_SYSENTER_CS </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Host_IA32_SYSENTER_CS </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IA32_SYSENTER_CS(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_SYSENTER_CS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IA32_SYSENTER_CS()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IA32_SYSENTER_CS </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Host_IA32_SYSENTER_CS field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IA32_SYSENTER_CS(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_SYSENTER_CS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_FS_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_FS_Limit()
/// @brief  Returns the value of the <tt> Guest_FS_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_FS_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_FS_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_FS_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_FS_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_FS_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_FS_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_FS_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_FS_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_GDTR_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_GDTR_Limit()
/// @brief  Returns the value of the <tt> Guest_GDTR_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_GDTR_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_GDTR_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GDTR_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_GDTR_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_GDTR_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_GDTR_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_GDTR_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GDTR_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_R12
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_R12()
/// @brief  Returns the value of the <tt> PPPE_Guest_R12 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_R12 </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_R12_OFFSET)))

#define Rd_PPPE_Guest_R12_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_R12(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_R12_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_R12_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_R12_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_R12_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_R12_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_R12_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_R12_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_R12_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_R12_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_R12_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_R12_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_R12_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_R12_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_R12_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_R12_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_R12()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_R12 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_R12 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_R12(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_R12_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_R12((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_R12_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_R12_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_R12_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_R12_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_R12_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R12_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Execution_Control_Proc_Based
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Execution_Control_Proc_Based()
/// @brief  Returns the value of the <tt> VM_Execution_Control_Proc_Based </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Execution_Control_Proc_Based </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Execution_Control_Proc_Based(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_PROC_BASED_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Execution_Control_Proc_Based()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Execution_Control_Proc_Based </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Execution_Control_Proc_Based field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Execution_Control_Proc_Based(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_PROC_BASED_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR4_Guest_Host_Mask
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR4_Guest_Host_Mask()
/// @brief  Returns the value of the <tt> CR4_Guest_Host_Mask </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> CR4_Guest_Host_Mask </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR4_Guest_Host_Mask(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR4_GUEST_HOST_MASK_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR4_Guest_Host_Mask()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR4_Guest_Host_Mask </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.CR4_Guest_Host_Mask field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR4_Guest_Host_Mask(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR4_GUEST_HOST_MASK_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pid_Ptr_TABLE_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Pid_Ptr_TABLE_Address()
/// @brief  Returns the value of the <tt> Pid_Ptr_TABLE_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Pid_Ptr_TABLE_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Pid_Ptr_TABLE_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PID_POINTER_TABLE_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Pid_Ptr_TABLE_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> Pid_Ptr_TABLE_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Pid_Ptr_TABLE_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Pid_Ptr_TABLE_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PID_POINTER_TABLE_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_EPT_Ptr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_EPT_Ptr()
/// @brief  Returns the value of the <tt> Guest_EPT_Ptr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_EPT_Ptr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_EPT_Ptr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_EPT_POINTER_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_EPT_Ptr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_EPT_Ptr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_EPT_Ptr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_EPT_Ptr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_EPT_POINTER_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_SSP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_SSP()
/// @brief  Returns the value of the <tt> PPPE_Guest_SSP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_Guest_SSP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_Guest_SSP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_SSP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_SSP()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_SSP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_Guest_SSP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_SSP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_SSP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PAUSE_LoOP_ExitING_GAP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PAUSE_LoOP_ExitING_GAP()
/// @brief  Returns the value of the <tt> PAUSE_LoOP_ExitING_GAP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> PAUSE_LoOP_ExitING_GAP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PAUSE_LoOP_ExitING_GAP(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PAUSE_LOOP_EXITING_GAP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PAUSE_LoOP_ExitING_GAP()
/// @brief  Writes value <tt> val </tt> into the the <tt> PAUSE_LoOP_ExitING_GAP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.PAUSE_LoOP_ExitING_GAP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PAUSE_LoOP_ExitING_GAP(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PAUSE_LOOP_EXITING_GAP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Execution_Control_Pin_Based
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Execution_Control_Pin_Based()
/// @brief  Returns the value of the <tt> VM_Execution_Control_Pin_Based </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Execution_Control_Pin_Based </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Execution_Control_Pin_Based(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_PIN_BASED_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Execution_Control_Pin_Based()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Execution_Control_Pin_Based </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Execution_Control_Pin_Based field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Execution_Control_Pin_Based(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_PIN_BASED_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_DS_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_DS_Base()
/// @brief  Returns the value of the <tt> Guest_DS_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_DS_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_DS_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_DS_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_DS_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_DS_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_DS_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_DS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_DS_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Uinv
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Uinv()
/// @brief  Returns the value of the <tt> Guest_Uinv </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_Uinv </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Uinv(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_UINV_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Uinv()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Uinv </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_Uinv field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Uinv(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_UINV_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IA32_Perf_Global_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IA32_Perf_Global_Control()
/// @brief  Returns the value of the <tt> Host_IA32_Perf_Global_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_IA32_Perf_Global_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IA32_Perf_Global_Control(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_PERF_GLOBAL_CONTROL_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IA32_Perf_Global_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IA32_Perf_Global_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_IA32_Perf_Global_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IA32_Perf_Global_Control(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_PERF_GLOBAL_CONTROL_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// IO_Bitmap_A_PhyPtr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_IO_Bitmap_A_PhyPtr()
/// @brief  Returns the value of the <tt> IO_Bitmap_A_PhyPtr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> IO_Bitmap_A_PhyPtr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_IO_Bitmap_A_PhyPtr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_IO_BITMAP_A_PHYPTR_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_IO_Bitmap_A_PhyPtr()
/// @brief  Writes value <tt> val </tt> into the the <tt> IO_Bitmap_A_PhyPtr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.IO_Bitmap_A_PhyPtr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_IO_Bitmap_A_PhyPtr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_IO_BITMAP_A_PHYPTR_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_Pkrs
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_Pkrs()
/// @brief  Returns the value of the <tt> Host_Pkrs </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_Pkrs </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_Pkrs(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_PKRS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_Pkrs()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_Pkrs </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_Pkrs field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_Pkrs(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_PKRS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_DebugCtlMSR
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_DebugCtlMSR()
/// @brief  Returns the value of the <tt> Guest_IA32_DebugCtlMSR </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_DebugCtlMSR </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_DebugCtlMSR(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_DEBUGCTLMSR_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_DebugCtlMSR()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_DebugCtlMSR </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_DebugCtlMSR field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_DebugCtlMSR(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_DEBUGCTLMSR_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_GDTR_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_GDTR_Base()
/// @brief  Returns the value of the <tt> Host_GDTR_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_GDTR_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_GDTR_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_GDTR_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_GDTR_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_GDTR_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_GDTR_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_GDTR_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_GDTR_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_SYSENTER_ESP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_SYSENTER_ESP()
/// @brief  Returns the value of the <tt> Guest_IA32_SYSENTER_ESP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_SYSENTER_ESP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_SYSENTER_ESP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_SYSENTER_ESP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_SYSENTER_ESP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_SYSENTER_ESP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_SYSENTER_ESP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_SYSENTER_ESP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_SYSENTER_ESP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_GS_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_GS_Base()
/// @brief  Returns the value of the <tt> Guest_GS_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_GS_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_GS_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GS_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_GS_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_GS_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_GS_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_GS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GS_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_Instruction_Immediate
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_Instruction_Immediate()
/// @brief  Returns the value of the <tt> PPPE_Guest_Instruction_Immediate </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_Guest_Instruction_Immediate </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_Guest_Instruction_Immediate(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_INSTRUCTION_IMMEDIATE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_Instruction_Immediate()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_Instruction_Immediate </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_Guest_Instruction_Immediate field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_Instruction_Immediate(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_INSTRUCTION_IMMEDIATE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// EOI_Exit_TABLE_0
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_EOI_Exit_TABLE_0()
/// @brief  Returns the value of the <tt> EOI_Exit_TABLE_0 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> EOI_Exit_TABLE_0 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_EOI_Exit_TABLE_0(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EOI_EXIT_TABLE_0_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_EOI_Exit_TABLE_0()
/// @brief  Writes value <tt> val </tt> into the the <tt> EOI_Exit_TABLE_0 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.EOI_Exit_TABLE_0 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_EOI_Exit_TABLE_0(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EOI_EXIT_TABLE_0_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_ES_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_ES_Limit()
/// @brief  Returns the value of the <tt> Guest_ES_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_ES_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_ES_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_ES_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_ES_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_ES_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_ES_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_ES_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_ES_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// EOI_Exit_TABLE_2
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_EOI_Exit_TABLE_2()
/// @brief  Returns the value of the <tt> EOI_Exit_TABLE_2 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> EOI_Exit_TABLE_2 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_EOI_Exit_TABLE_2(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EOI_EXIT_TABLE_2_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_EOI_Exit_TABLE_2()
/// @brief  Writes value <tt> val </tt> into the the <tt> EOI_Exit_TABLE_2 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.EOI_Exit_TABLE_2 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_EOI_Exit_TABLE_2(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EOI_EXIT_TABLE_2_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// EOI_Exit_TABLE_3
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_EOI_Exit_TABLE_3()
/// @brief  Returns the value of the <tt> EOI_Exit_TABLE_3 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> EOI_Exit_TABLE_3 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_EOI_Exit_TABLE_3(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EOI_EXIT_TABLE_3_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_EOI_Exit_TABLE_3()
/// @brief  Writes value <tt> val </tt> into the the <tt> EOI_Exit_TABLE_3 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.EOI_Exit_TABLE_3 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_EOI_Exit_TABLE_3(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EOI_EXIT_TABLE_3_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// EOI_Exit_TABLE_1
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_EOI_Exit_TABLE_1()
/// @brief  Returns the value of the <tt> EOI_Exit_TABLE_1 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> EOI_Exit_TABLE_1 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_EOI_Exit_TABLE_1(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EOI_EXIT_TABLE_1_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_EOI_Exit_TABLE_1()
/// @brief  Writes value <tt> val </tt> into the the <tt> EOI_Exit_TABLE_1 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.EOI_Exit_TABLE_1 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_EOI_Exit_TABLE_1(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EOI_EXIT_TABLE_1_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Virtual_APIC_ACCESS_Page_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Virtual_APIC_ACCESS_Page_Address()
/// @brief  Returns the value of the <tt> Virtual_APIC_ACCESS_Page_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Virtual_APIC_ACCESS_Page_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Virtual_APIC_ACCESS_Page_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Virtual_APIC_ACCESS_Page_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> Virtual_APIC_ACCESS_Page_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Virtual_APIC_ACCESS_Page_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Virtual_APIC_ACCESS_Page_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VIRTUAL_APIC_ACCESS_PAGE_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// POSTED_INTErrUPT_NOTIFICATION_Vector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_POSTED_INTErrUPT_NOTIFICATION_Vector()
/// @brief  Returns the value of the <tt> POSTED_INTErrUPT_NOTIFICATION_Vector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> POSTED_INTErrUPT_NOTIFICATION_Vector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_POSTED_INTErrUPT_NOTIFICATION_Vector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_POSTED_INTERRUPT_NOTIFICATION_VECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_POSTED_INTErrUPT_NOTIFICATION_Vector()
/// @brief  Writes value <tt> val </tt> into the the <tt> POSTED_INTErrUPT_NOTIFICATION_Vector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.POSTED_INTErrUPT_NOTIFICATION_Vector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_POSTED_INTErrUPT_NOTIFICATION_Vector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_POSTED_INTERRUPT_NOTIFICATION_VECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_GS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_GS_Selector()
/// @brief  Returns the value of the <tt> Guest_GS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_GS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_GS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_GS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_GS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_GS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_GS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IA32_PAT
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IA32_PAT()
/// @brief  Returns the value of the <tt> Host_IA32_PAT </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_IA32_PAT </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IA32_PAT(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_PAT_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IA32_PAT()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IA32_PAT </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_IA32_PAT field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IA32_PAT(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_PAT_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_TR_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_TR_Base()
/// @brief  Returns the value of the <tt> Host_TR_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_TR_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_TR_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_TR_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_TR_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_TR_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_TR_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_TR_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_TR_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// TSC_MULTIPLIER
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_TSC_MULTIPLIER()
/// @brief  Returns the value of the <tt> TSC_MULTIPLIER </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> TSC_MULTIPLIER </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_TSC_MULTIPLIER(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_TSC_MULTIPLIER_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_TSC_MULTIPLIER()
/// @brief  Writes value <tt> val </tt> into the the <tt> TSC_MULTIPLIER </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.TSC_MULTIPLIER field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_TSC_MULTIPLIER(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_TSC_MULTIPLIER_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_DS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_DS_Selector()
/// @brief  Returns the value of the <tt> Guest_DS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_DS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_DS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_DS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_DS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_DS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_DS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_DS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_DS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_INTErrUPT_Status
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_INTErrUPT_Status()
/// @brief  Returns the value of the <tt> Guest_INTErrUPT_Status </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_INTErrUPT_Status </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_INTErrUPT_Status(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_INTERRUPT_STATUS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_INTErrUPT_Status()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_INTErrUPT_Status </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_INTErrUPT_Status field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_INTErrUPT_Status(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_INTERRUPT_STATUS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_Instruction_Opcode
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_Instruction_Opcode()
/// @brief  Returns the value of the <tt> PPPE_Guest_Instruction_Opcode </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_Guest_Instruction_Opcode </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_Guest_Instruction_Opcode(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_INSTRUCTION_OPCODE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_Instruction_Opcode()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_Instruction_Opcode </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_Guest_Instruction_Opcode field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_Instruction_Opcode(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_INSTRUCTION_OPCODE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Pnd_Debug_Exception
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Pnd_Debug_Exception()
/// @brief  Returns the value of the <tt> Guest_Pnd_Debug_Exception </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_Pnd_Debug_Exception </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Pnd_Debug_Exception(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PND_DEBUG_EXCEPTION_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Pnd_Debug_Exception()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Pnd_Debug_Exception </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_Pnd_Debug_Exception field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Pnd_Debug_Exception(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PND_DEBUG_EXCEPTION_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Sleep_State
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Sleep_State()
/// @brief  Returns the value of the <tt> Guest_Sleep_State </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_Sleep_State </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Sleep_State(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SLEEP_STATE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Sleep_State()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Sleep_State </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_Sleep_State field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Sleep_State(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SLEEP_STATE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_ES_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_ES_Selector()
/// @brief  Returns the value of the <tt> Guest_ES_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_ES_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_ES_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_ES_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_ES_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_ES_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_ES_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_ES_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_ES_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_LDTR_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_LDTR_Base()
/// @brief  Returns the value of the <tt> Guest_LDTR_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_LDTR_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_LDTR_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_LDTR_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_LDTR_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_LDTR_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_LDTR_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_LDTR_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_LDTR_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// RSVD_64_BIT_VMExit_DATA
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_RSVD_64_BIT_VMExit_DATA()
/// @brief  Returns the value of the <tt> RSVD_64_BIT_VMExit_DATA </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> RSVD_64_BIT_VMExit_DATA </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_RSVD_64_BIT_VMExit_DATA(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_64_BIT_VMEXIT_DATA_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_RSVD_64_BIT_VMExit_DATA()
/// @brief  Writes value <tt> val </tt> into the the <tt> RSVD_64_BIT_VMExit_DATA </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.RSVD_64_BIT_VMExit_DATA field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_RSVD_64_BIT_VMExit_DATA(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_64_BIT_VMEXIT_DATA_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_Reason
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_Reason()
/// @brief  Returns the value of the <tt> VM_Exit_Reason </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_Reason </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_Reason(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_REASON_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_Reason()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_Reason </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_Reason field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_Reason(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_REASON_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_CR4
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_CR4()
/// @brief  Returns the value of the <tt> Guest_CR4 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_CR4 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_CR4(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CR4_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_CR4()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_CR4 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_CR4 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_CR4(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CR4_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_CR0
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_CR0()
/// @brief  Returns the value of the <tt> Guest_CR0 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_CR0 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_CR0(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CR0_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_CR0()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_CR0 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_CR0 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_CR0(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CR0_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_CR3
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_CR3()
/// @brief  Returns the value of the <tt> Guest_CR3 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_CR3 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_CR3(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CR3_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_CR3()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_CR3 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_CR3 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_CR3(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_CR3_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_SMBase
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_SMBase()
/// @brief  Returns the value of the <tt> Guest_SMBase </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_SMBase </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_SMBase(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SMBASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_SMBase()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_SMBase </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_SMBase field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_SMBase(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SMBASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_IO_RDI
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_IO_RDI()
/// @brief  Returns the value of the <tt> VM_Exit_IO_RDI </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VM_Exit_IO_RDI </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_IO_RDI(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_RDI_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_IO_RDI()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_IO_RDI </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VM_Exit_IO_RDI field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_IO_RDI(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_RDI_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_FS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_FS_Selector()
/// @brief  Returns the value of the <tt> Guest_FS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_FS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_FS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_FS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_FS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_FS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_FS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_FS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_FS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_LDTR_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_LDTR_Selector()
/// @brief  Returns the value of the <tt> Guest_LDTR_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_LDTR_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_LDTR_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_LDTR_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_LDTR_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_LDTR_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_LDTR_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_LDTR_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_LDTR_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ENCLV_Exit_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_ENCLV_Exit_Control()
/// @brief  Returns the value of the <tt> ENCLV_Exit_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> ENCLV_Exit_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_ENCLV_Exit_Control(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_ENCLV_EXIT_CONTROL_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_ENCLV_Exit_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> ENCLV_Exit_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.ENCLV_Exit_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_ENCLV_Exit_Control(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_ENCLV_EXIT_CONTROL_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PageFault_ErrorCode_Match
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PageFault_ErrorCode_Match()
/// @brief  Returns the value of the <tt> PageFault_ErrorCode_Match </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> PageFault_ErrorCode_Match </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PageFault_ErrorCode_Match(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PAGEFAULT_ERRORCODE_MATCH_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PageFault_ErrorCode_Match()
/// @brief  Writes value <tt> val </tt> into the the <tt> PageFault_ErrorCode_Match </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.PageFault_ErrorCode_Match field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PageFault_ErrorCode_Match(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PAGEFAULT_ERRORCODE_MATCH_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_Exception_Info
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_Exception_Info()
/// @brief  Returns the value of the <tt> VM_Exit_Exception_Info </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Exit_Exception_Info </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_Exception_Info(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_EXCEPTION_INFO_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_Exception_Info()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_Exception_Info </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Exit_Exception_Info field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_Exception_Info(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_EXCEPTION_INFO_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_RAX
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_RAX()
/// @brief  Returns the value of the <tt> PPPE_Guest_RAX </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_RAX </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_RAX_OFFSET)))

#define Rd_PPPE_Guest_RAX_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_RAX(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RAX_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RAX_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_RAX_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_RAX_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_RAX_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_RAX_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_RAX_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_RAX_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_RAX_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_RAX_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_RAX_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_RAX_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_RAX_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_RAX_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_RAX_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_RAX()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_RAX </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_RAX field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_RAX(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RAX_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_RAX((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_RAX_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RAX_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_RAX_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_RAX_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_RAX_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RAX_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PML_INDEX
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PML_INDEX()
/// @brief  Returns the value of the <tt> PML_INDEX </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> PML_INDEX </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PML_INDEX(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PML_INDEX_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PML_INDEX()
/// @brief  Writes value <tt> val </tt> into the the <tt> PML_INDEX </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.PML_INDEX field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PML_INDEX(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PML_INDEX_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Interuptibility
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Interuptibility()
/// @brief  Returns the value of the <tt> Guest_Interuptibility </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_Interuptibility </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Interuptibility(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_INTERRUPTIBILITY_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Interuptibility()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Interuptibility </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_Interuptibility field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Interuptibility(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_INTERRUPTIBILITY_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IDTR_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IDTR_Base()
/// @brief  Returns the value of the <tt> Host_IDTR_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_IDTR_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IDTR_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IDTR_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IDTR_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IDTR_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_IDTR_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IDTR_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IDTR_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_GS_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_GS_Limit()
/// @brief  Returns the value of the <tt> Guest_GS_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_GS_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_GS_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GS_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_GS_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_GS_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_GS_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_GS_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_GS_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IDTR_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IDTR_Base()
/// @brief  Returns the value of the <tt> Guest_IDTR_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IDTR_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IDTR_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IDTR_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IDTR_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IDTR_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IDTR_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IDTR_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IDTR_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IDTR_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IDTR_Limit()
/// @brief  Returns the value of the <tt> Guest_IDTR_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_IDTR_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IDTR_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IDTR_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IDTR_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IDTR_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_IDTR_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IDTR_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IDTR_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_FUNCTION_ControlS
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_FUNCTION_ControlS()
/// @brief  Returns the value of the <tt> VM_FUNCTION_ControlS </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VM_FUNCTION_ControlS </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_FUNCTION_ControlS(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_FUNCTION_CONTROLS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_FUNCTION_ControlS()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_FUNCTION_ControlS </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VM_FUNCTION_ControlS field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_FUNCTION_ControlS(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_FUNCTION_CONTROLS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_RSP
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_RSP()
/// @brief  Returns the value of the <tt> PPPE_Guest_RSP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_RSP </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_RSP_OFFSET)))

#define Rd_PPPE_Guest_RSP_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_RSP(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RSP_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RSP_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_RSP_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_RSP_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_RSP_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_RSP_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_RSP_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_RSP_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_RSP_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_RSP_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_RSP_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_RSP_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_RSP_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_RSP_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_RSP_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_RSP()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_RSP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_RSP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_RSP(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RSP_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_RSP((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_RSP_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RSP_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_RSP_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_RSP_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_RSP_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSP_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Entry_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Entry_Control()
/// @brief  Returns the value of the <tt> VM_Entry_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Entry_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Entry_Control(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_CONTROL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Entry_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Entry_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Entry_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Entry_Control(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_CONTROL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Entry_Instruction_Length
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Entry_Instruction_Length()
/// @brief  Returns the value of the <tt> VM_Entry_Instruction_Length </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Entry_Instruction_Length </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Entry_Instruction_Length(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_INSTRUCTION_LENGTH_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Entry_Instruction_Length()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Entry_Instruction_Length </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Entry_Instruction_Length field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Entry_Instruction_Length(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_INSTRUCTION_LENGTH_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_ES_ARbyte
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_ES_ARbyte()
/// @brief  Returns the value of the <tt> Guest_ES_ARbyte </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_ES_ARbyte </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_ES_ARbyte(VMCS_T_PTR) hal_read_guest_arbyte((VMCS_T_PTR), VMX_GUEST_ES_ARBYTE_OFFSET)

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_ES_ARbyte()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_ES_ARbyte </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_ES_ARbyte field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_ES_ARbyte(VMCS_T_PTR, VAL) hal_write_guest_arbyte((VMCS_T_PTR), VMX_GUEST_ES_ARBYTE_OFFSET, (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// RSVD_64_BIT_Control_5
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_RSVD_64_BIT_Control_5()
/// @brief  Returns the value of the <tt> RSVD_64_BIT_Control_5 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> RSVD_64_BIT_Control_5 </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_RSVD_64_BIT_Control_5(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_64_BIT_CONTROL_5_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_RSVD_64_BIT_Control_5()
/// @brief  Writes value <tt> val </tt> into the the <tt> RSVD_64_BIT_Control_5 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.RSVD_64_BIT_Control_5 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_RSVD_64_BIT_Control_5(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_64_BIT_CONTROL_5_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_Doorbell_Inhibits
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_Doorbell_Inhibits()
/// @brief  Returns the value of the <tt> PPPE_Guest_Doorbell_Inhibits </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_Guest_Doorbell_Inhibits </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_Guest_Doorbell_Inhibits(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_DOORBELL_INHIBITS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_Doorbell_Inhibits()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_Doorbell_Inhibits </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_Guest_Doorbell_Inhibits field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_Doorbell_Inhibits(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_DOORBELL_INHIBITS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_Instruction_Displacement
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_Instruction_Displacement()
/// @brief  Returns the value of the <tt> PPPE_Guest_Instruction_Displacement </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_Guest_Instruction_Displacement </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_Guest_Instruction_Displacement(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_INSTRUCTION_DISPLACEMENT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_Instruction_Displacement()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_Instruction_Displacement </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_Guest_Instruction_Displacement field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_Instruction_Displacement(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_INSTRUCTION_DISPLACEMENT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_RSI
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_RSI()
/// @brief  Returns the value of the <tt> PPPE_Guest_RSI </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_RSI </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_RSI_OFFSET)))

#define Rd_PPPE_Guest_RSI_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_RSI(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RSI_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RSI_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_RSI_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_RSI_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_RSI_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_RSI_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_RSI_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_RSI_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_RSI_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_RSI_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_RSI_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_RSI_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_RSI_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_RSI_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_RSI_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_RSI()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_RSI </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_RSI field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_RSI(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RSI_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_RSI((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_RSI_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RSI_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_RSI_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_RSI_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_RSI_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RSI_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Hidden_RFLAGS
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Hidden_RFLAGS()
/// @brief  Returns the value of the <tt> Guest_Hidden_RFLAGS </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_Hidden_RFLAGS </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Hidden_RFLAGS(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_HIDDEN_RFLAGS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Hidden_RFLAGS()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Hidden_RFLAGS </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_Hidden_RFLAGS field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Hidden_RFLAGS(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_HIDDEN_RFLAGS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VMRead_Bitmap_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VMRead_Bitmap_Address()
/// @brief  Returns the value of the <tt> VMRead_Bitmap_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VMRead_Bitmap_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VMRead_Bitmap_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMREAD_BITMAP_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VMRead_Bitmap_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> VMRead_Bitmap_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VMRead_Bitmap_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VMRead_Bitmap_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMREAD_BITMAP_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PageFault_ErrorCode_Mask
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PageFault_ErrorCode_Mask()
/// @brief  Returns the value of the <tt> PageFault_ErrorCode_Mask </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> PageFault_ErrorCode_Mask </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PageFault_ErrorCode_Mask(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PAGEFAULT_ERRORCODE_MASK_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PageFault_ErrorCode_Mask()
/// @brief  Writes value <tt> val </tt> into the the <tt> PageFault_ErrorCode_Mask </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.PageFault_ErrorCode_Mask field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PageFault_ErrorCode_Mask(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PAGEFAULT_ERRORCODE_MASK_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_SS_ARbyte
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_SS_ARbyte()
/// @brief  Returns the value of the <tt> Guest_SS_ARbyte </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Guest_SS_ARbyte </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_SS_ARbyte(VMCS_T_PTR) hal_read_guest_arbyte((VMCS_T_PTR), VMX_GUEST_SS_ARBYTE_OFFSET)

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_SS_ARbyte()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_SS_ARbyte </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Guest_SS_ARbyte field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_SS_ARbyte(VMCS_T_PTR, VAL) hal_write_guest_arbyte((VMCS_T_PTR), VMX_GUEST_SS_ARBYTE_OFFSET, (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Pkrs
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Pkrs()
/// @brief  Returns the value of the <tt> Guest_Pkrs </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_Pkrs </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Pkrs(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PKRS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Pkrs()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Pkrs </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_Pkrs field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Pkrs(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PKRS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ENCLS_Exit_Control
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_ENCLS_Exit_Control()
/// @brief  Returns the value of the <tt> ENCLS_Exit_Control </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> ENCLS_Exit_Control </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_ENCLS_Exit_Control(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_ENCLS_EXIT_CONTROL_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_ENCLS_Exit_Control()
/// @brief  Writes value <tt> val </tt> into the the <tt> ENCLS_Exit_Control </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.ENCLS_Exit_Control field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_ENCLS_Exit_Control(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_ENCLS_EXIT_CONTROL_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_MISC_UArch_State
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_MISC_UArch_State()
/// @brief  Returns the value of the <tt> PPPE_Guest_MISC_UArch_State </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_Guest_MISC_UArch_State </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_Guest_MISC_UArch_State(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_MISC_UARCH_STATE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_MISC_UArch_State()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_MISC_UArch_State </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_Guest_MISC_UArch_State field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_MISC_UArch_State(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_MISC_UARCH_STATE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Exception_Bitmap
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Exception_Bitmap()
/// @brief  Returns the value of the <tt> Exception_Bitmap </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Exception_Bitmap </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Exception_Bitmap(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EXCEPTION_BITMAP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Exception_Bitmap()
/// @brief  Writes value <tt> val </tt> into the the <tt> Exception_Bitmap </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Exception_Bitmap field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Exception_Bitmap(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EXCEPTION_BITMAP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_RSP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_RSP()
/// @brief  Returns the value of the <tt> Host_RSP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_RSP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_RSP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_RSP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_RSP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_RSP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_RSP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_RSP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_RSP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_RBP
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_RBP()
/// @brief  Returns the value of the <tt> PPPE_Guest_RBP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_RBP </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_RBP_OFFSET)))

#define Rd_PPPE_Guest_RBP_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_RBP(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RBP_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RBP_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_RBP_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_RBP_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_RBP_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_RBP_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_RBP_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_RBP_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_RBP_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_RBP_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_RBP_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_RBP_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_RBP_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_RBP_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_RBP_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_RBP()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_RBP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_RBP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_RBP(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RBP_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_RBP((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_RBP_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RBP_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_RBP_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_RBP_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_RBP_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RBP_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_SYSENTER_EIP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_SYSENTER_EIP()
/// @brief  Returns the value of the <tt> Guest_IA32_SYSENTER_EIP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_SYSENTER_EIP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_SYSENTER_EIP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_SYSENTER_EIP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_SYSENTER_EIP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_SYSENTER_EIP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_SYSENTER_EIP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_SYSENTER_EIP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_SYSENTER_EIP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_SSP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_SSP()
/// @brief  Returns the value of the <tt> Guest_SSP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_SSP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_SSP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SSP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_SSP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_SSP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_SSP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_SSP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SSP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_SS_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_SS_Limit()
/// @brief  Returns the value of the <tt> Guest_SS_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_SS_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_SS_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SS_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_SS_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_SS_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_SS_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_SS_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SS_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Preemption_Timer_Count
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Preemption_Timer_Count()
/// @brief  Returns the value of the <tt> Guest_Preemption_Timer_Count </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_Preemption_Timer_Count </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Preemption_Timer_Count(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PREEMPTION_TIMER_COUNT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Preemption_Timer_Count()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Preemption_Timer_Count </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_Preemption_Timer_Count field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Preemption_Timer_Count(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PREEMPTION_TIMER_COUNT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// OSV_CVP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_OSV_CVP()
/// @brief  Returns the value of the <tt> OSV_CVP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> OSV_CVP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_OSV_CVP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_OSV_CVP_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_OSV_CVP()
/// @brief  Writes value <tt> val </tt> into the the <tt> OSV_CVP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.OSV_CVP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_OSV_CVP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_OSV_CVP_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_RDI
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_RDI()
/// @brief  Returns the value of the <tt> PPPE_Guest_RDI </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_RDI </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_RDI_OFFSET)))

#define Rd_PPPE_Guest_RDI_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_RDI(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RDI_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RDI_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_RDI_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_RDI_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_RDI_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_RDI_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_RDI_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_RDI_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_RDI_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_RDI_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_RDI_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_RDI_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_RDI_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_RDI_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_RDI_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_RDI()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_RDI </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_RDI field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_RDI(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RDI_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_RDI((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_RDI_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RDI_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_RDI_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_RDI_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_RDI_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RDI_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Entry_MSR_Load_Count
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Entry_MSR_Load_Count()
/// @brief  Returns the value of the <tt> VM_Entry_MSR_Load_Count </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> VM_Entry_MSR_Load_Count </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Entry_MSR_Load_Count(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_MSR_LOAD_COUNT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Entry_MSR_Load_Count()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Entry_MSR_Load_Count </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.VM_Entry_MSR_Load_Count field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Entry_MSR_Load_Count(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_ENTRY_MSR_LOAD_COUNT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Last_Pid_Ptr_INDEX
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Last_Pid_Ptr_INDEX()
/// @brief  Returns the value of the <tt> Last_Pid_Ptr_INDEX </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Last_Pid_Ptr_INDEX </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Last_Pid_Ptr_INDEX(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_LAST_PID_POINTER_INDEX_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Last_Pid_Ptr_INDEX()
/// @brief  Writes value <tt> val </tt> into the the <tt> Last_Pid_Ptr_INDEX </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Last_Pid_Ptr_INDEX field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Last_Pid_Ptr_INDEX(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_LAST_PID_POINTER_INDEX_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_IA32_S_Cet
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_IA32_S_Cet()
/// @brief  Returns the value of the <tt> Guest_IA32_S_Cet </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_IA32_S_Cet </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_IA32_S_Cet(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_S_CET_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_IA32_S_Cet()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_IA32_S_Cet </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_IA32_S_Cet field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_IA32_S_Cet(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_IA32_S_CET_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Execution_Control_Tertiary_Proc_Based
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Execution_Control_Tertiary_Proc_Based()
/// @brief  Returns the value of the <tt> VM_Execution_Control_Tertiary_Proc_Based </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VM_Execution_Control_Tertiary_Proc_Based </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Execution_Control_Tertiary_Proc_Based(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Execution_Control_Tertiary_Proc_Based()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Execution_Control_Tertiary_Proc_Based </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VM_Execution_Control_Tertiary_Proc_Based field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Execution_Control_Tertiary_Proc_Based(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXECUTION_CONTROL_TERTIARY_PROC_BASED_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// IO_Bitmap_B_PhyPtr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_IO_Bitmap_B_PhyPtr()
/// @brief  Returns the value of the <tt> IO_Bitmap_B_PhyPtr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> IO_Bitmap_B_PhyPtr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_IO_Bitmap_B_PhyPtr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_IO_BITMAP_B_PHYPTR_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_IO_Bitmap_B_PhyPtr()
/// @brief  Writes value <tt> val </tt> into the the <tt> IO_Bitmap_B_PhyPtr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.IO_Bitmap_B_PhyPtr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_IO_Bitmap_B_PhyPtr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_IO_BITMAP_B_PHYPTR_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_UNWIND
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_UNWIND()
/// @brief  Returns the value of the <tt> PPPE_UNWIND </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_UNWIND </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_UNWIND(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_UNWIND_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_UNWIND()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_UNWIND </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_UNWIND field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_UNWIND(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_UNWIND_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Parent_VMCS_Ptr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Parent_VMCS_Ptr()
/// @brief  Returns the value of the <tt> Guest_Parent_VMCS_Ptr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> void*    </tt> read from the <tt> Guest_Parent_VMCS_Ptr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Parent_VMCS_Ptr(VMCS_T_PTR)  \
  (*((void **) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PARENT_VMCS_POINTER_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Parent_VMCS_Ptr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Parent_VMCS_Ptr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             void*    value to be written into the VMCS.Guest_Parent_VMCS_Ptr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Parent_VMCS_Ptr(VMCS_T_PTR, VAL)  \
  (*((void **) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PARENT_VMCS_POINTER_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_TR_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_TR_Selector()
/// @brief  Returns the value of the <tt> Host_TR_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Host_TR_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_TR_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_TR_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_TR_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_TR_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Host_TR_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_TR_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_TR_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_SS_Base
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_SS_Base()
/// @brief  Returns the value of the <tt> Guest_SS_Base </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_SS_Base </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_SS_Base(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SS_BASE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_SS_Base()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_SS_Base </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_SS_Base field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_SS_Base(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_SS_BASE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// CR4_Read_Shadow
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_CR4_Read_Shadow()
/// @brief  Returns the value of the <tt> CR4_Read_Shadow </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> CR4_Read_Shadow </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_CR4_Read_Shadow(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR4_READ_SHADOW_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_CR4_Read_Shadow()
/// @brief  Writes value <tt> val </tt> into the the <tt> CR4_Read_Shadow </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.CR4_Read_Shadow field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_CR4_Read_Shadow(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_CR4_READ_SHADOW_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IA32_SYSENTER_EIP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IA32_SYSENTER_EIP()
/// @brief  Returns the value of the <tt> Host_IA32_SYSENTER_EIP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_IA32_SYSENTER_EIP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IA32_SYSENTER_EIP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_SYSENTER_EIP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IA32_SYSENTER_EIP()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IA32_SYSENTER_EIP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_IA32_SYSENTER_EIP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IA32_SYSENTER_EIP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_SYSENTER_EIP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// TPR_Threshold
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_TPR_Threshold()
/// @brief  Returns the value of the <tt> TPR_Threshold </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> TPR_Threshold </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_TPR_Threshold(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_TPR_THRESHOLD_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_TPR_Threshold()
/// @brief  Writes value <tt> val </tt> into the the <tt> TPR_Threshold </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.TPR_Threshold field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_TPR_Threshold(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_TPR_THRESHOLD_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_R15
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_R15()
/// @brief  Returns the value of the <tt> PPPE_Guest_R15 </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_R15 </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_R15_OFFSET)))

#define Rd_PPPE_Guest_R15_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_R15(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_R15_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_R15_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_R15_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_R15_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_R15_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_R15_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_R15_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_R15_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_R15_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_R15_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_R15_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_R15_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_R15_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_R15_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_R15_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_R15()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_R15 </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_R15 field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_R15(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_R15_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_R15((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_R15_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_R15_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_R15_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_R15_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_R15_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_R15_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_RFLAGS
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_RFLAGS()
/// @brief  Returns the value of the <tt> Guest_RFLAGS </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_RFLAGS </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_RFLAGS(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RFLAGS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_RFLAGS()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_RFLAGS </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_RFLAGS field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_RFLAGS(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_RFLAGS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// RSVD_32_BIT_Guest_State
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_RSVD_32_BIT_Guest_State()
/// @brief  Returns the value of the <tt> RSVD_32_BIT_Guest_State </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> RSVD_32_BIT_Guest_State </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_RSVD_32_BIT_Guest_State(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_32_BIT_GUEST_STATE_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_RSVD_32_BIT_Guest_State()
/// @brief  Writes value <tt> val </tt> into the the <tt> RSVD_32_BIT_Guest_State </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.RSVD_32_BIT_Guest_State field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_RSVD_32_BIT_Guest_State(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_RSVD_32_BIT_GUEST_STATE_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VM_Exit_IO_Instruction_Initial_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VM_Exit_IO_Instruction_Initial_Address()
/// @brief  Returns the value of the <tt> VM_Exit_IO_Instruction_Initial_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VM_Exit_IO_Instruction_Initial_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VM_Exit_IO_Instruction_Initial_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_INSTRUCTION_INITIAL_ADDRESS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VM_Exit_IO_Instruction_Initial_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> VM_Exit_IO_Instruction_Initial_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VM_Exit_IO_Instruction_Initial_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VM_Exit_IO_Instruction_Initial_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VM_EXIT_IO_INSTRUCTION_INITIAL_ADDRESS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Exit_MSR_Load_PhyPtr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Exit_MSR_Load_PhyPtr()
/// @brief  Returns the value of the <tt> Exit_MSR_Load_PhyPtr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Exit_MSR_Load_PhyPtr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Exit_MSR_Load_PhyPtr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EXIT_MSR_LOAD_PHYPTR_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Exit_MSR_Load_PhyPtr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Exit_MSR_Load_PhyPtr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Exit_MSR_Load_PhyPtr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Exit_MSR_Load_PhyPtr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_EXIT_MSR_LOAD_PHYPTR_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Virtual_Exception_Info_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Virtual_Exception_Info_Address()
/// @brief  Returns the value of the <tt> Virtual_Exception_Info_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Virtual_Exception_Info_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Virtual_Exception_Info_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Virtual_Exception_Info_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> Virtual_Exception_Info_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Virtual_Exception_Info_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Virtual_Exception_Info_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VIRTUAL_EXCEPTION_INFO_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pasid_Low
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Pasid_Low()
/// @brief  Returns the value of the <tt> Pasid_Low </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Pasid_Low </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Pasid_Low(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PASID_LOW_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Pasid_Low()
/// @brief  Writes value <tt> val </tt> into the the <tt> Pasid_Low </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Pasid_Low field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Pasid_Low(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_PASID_LOW_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// VMWrite_Bitmap_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_VMWrite_Bitmap_Address()
/// @brief  Returns the value of the <tt> VMWrite_Bitmap_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> VMWrite_Bitmap_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_VMWrite_Bitmap_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMWRITE_BITMAP_ADDRESS_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_VMWrite_Bitmap_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> VMWrite_Bitmap_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.VMWrite_Bitmap_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_VMWrite_Bitmap_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_VMWRITE_BITMAP_ADDRESS_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_DS_Limit
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_DS_Limit()
/// @brief  Returns the value of the <tt> Guest_DS_Limit </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint32_t    </tt> read from the <tt> Guest_DS_Limit </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_DS_Limit(VMCS_T_PTR)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_DS_LIMIT_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_DS_Limit()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_DS_Limit </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint32_t    value to be written into the VMCS.Guest_DS_Limit field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_DS_Limit(VMCS_T_PTR, VAL)  \
  (*((uint32_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_DS_LIMIT_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_FROM_RIP
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_FROM_RIP()
/// @brief  Returns the value of the <tt> PPPE_FROM_RIP </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_FROM_RIP </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_FROM_RIP(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_FROM_RIP_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_FROM_RIP()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_FROM_RIP </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_FROM_RIP field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_FROM_RIP(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_FROM_RIP_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_DS_Selector
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_DS_Selector()
/// @brief  Returns the value of the <tt> Host_DS_Selector </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint16_t    </tt> read from the <tt> Host_DS_Selector </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_DS_Selector(VMCS_T_PTR)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_DS_SELECTOR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_DS_Selector()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_DS_Selector </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint16_t    value to be written into the VMCS.Host_DS_Selector field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_DS_Selector(VMCS_T_PTR, VAL)  \
  (*((uint16_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_DS_SELECTOR_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Page_Fault_Address
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Page_Fault_Address()
/// @brief  Returns the value of the <tt> PPPE_Page_Fault_Address </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_Page_Fault_Address </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_Page_Fault_Address(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_PAGE_FAULT_ADDRESS_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Page_Fault_Address()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Page_Fault_Address </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_Page_Fault_Address field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Page_Fault_Address(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_PAGE_FAULT_ADDRESS_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guest_Physical_Address_Info
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Guest_Physical_Address_Info()
/// @brief  Returns the value of the <tt> Guest_Physical_Address_Info </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Guest_Physical_Address_Info </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Guest_Physical_Address_Info(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PHYSICAL_ADDRESS_INFO_FULL_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Guest_Physical_Address_Info()
/// @brief  Writes value <tt> val </tt> into the the <tt> Guest_Physical_Address_Info </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Guest_Physical_Address_Info field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Guest_Physical_Address_Info(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_GUEST_PHYSICAL_ADDRESS_INFO_FULL_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_VMExit_INJECTION
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_VMExit_INJECTION()
/// @brief  Returns the value of the <tt> PPPE_VMExit_INJECTION </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> PPPE_VMExit_INJECTION </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_PPPE_VMExit_INJECTION(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_VMEXIT_INJECTION_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_VMExit_INJECTION()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_VMExit_INJECTION </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.PPPE_VMExit_INJECTION field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_VMExit_INJECTION(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_VMEXIT_INJECTION_OFFSET)) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PPPE_Guest_RCX
//            is NOT CACHED by HW, so can be accessed using loads
//            and stores (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_PPPE_Guest_RCX()
/// @brief  Returns the value of the <tt> PPPE_Guest_RCX </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> ia32mmx64_t </tt> read from the <tt> PPPE_Guest_RCX </tt>
///         field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define __Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)  \
  (((ia32mmx64_t *) (((uint8_t *) (VMCS_T_PTR)) + PPPE_GUEST_RCX_OFFSET)))

#define Rd_PPPE_Guest_RCX_IA32MMX64(VMCS_T_PTR)       \
  (*(__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)))

#define Rd_PPPE_Guest_RCX(VMCS_T_PTR)                 \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RCX_UINT64(VMCS_T_PTR)          \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint64)

#define Rd_PPPE_Guest_RCX_UINT32_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint32[0])
#define Rd_PPPE_Guest_RCX_UINT32_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint32[1])

#define Rd_PPPE_Guest_RCX_UINT16_0(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint16[0])
#define Rd_PPPE_Guest_RCX_UINT16_1(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint16[1])
#define Rd_PPPE_Guest_RCX_UINT16_2(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint16[2])
#define Rd_PPPE_Guest_RCX_UINT16_3(VMCS_T_PTR)        \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint16[3])

#define Rd_PPPE_Guest_RCX_UINT8_0(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[0])
#define Rd_PPPE_Guest_RCX_UINT8_1(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[1])
#define Rd_PPPE_Guest_RCX_UINT8_2(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[2])
#define Rd_PPPE_Guest_RCX_UINT8_3(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[3])
#define Rd_PPPE_Guest_RCX_UINT8_4(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[4])
#define Rd_PPPE_Guest_RCX_UINT8_5(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[5])
#define Rd_PPPE_Guest_RCX_UINT8_6(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[6])
#define Rd_PPPE_Guest_RCX_UINT8_7(VMCS_T_PTR)         \
  (__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[7])

////////////////////////////////////////////////////////////////////////////
// Wr_PPPE_Guest_RCX()
/// @brief  Writes value <tt> val </tt> into the the <tt> PPPE_Guest_RCX </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor undefined for this VT-cached VMCS field.
/// @param  vmcs Pointer to an active (potentially cacheable fields) VMCS.
/// @param  val  ia32mmx64_t value to be written into the VMCS.PPPE_Guest_RCX field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_PPPE_Guest_RCX(VMCS_T_PTR, VAL)               \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RCX_IA32MMX64(VMCS_T_PTR, VAL)     \
  Wr_PPPE_Guest_RCX((VMCS_T_PTR), ((uint64_t) (VAL)))

#define Wr_PPPE_Guest_RCX_UINT64(VMCS_T_PTR, VAL)        \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint64) = (VAL))

#define Wr_PPPE_Guest_RCX_UINT32_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint32[0]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT32_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint32[1]) = (VAL))

#define Wr_PPPE_Guest_RCX_UINT16_0(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint16[0]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT16_1(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint16[1]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT16_2(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint16[2]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT16_3(VMCS_T_PTR, VAL)      \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint16[3]) = (VAL))

#define Wr_PPPE_Guest_RCX_UINT8_0(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[0]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT8_1(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[1]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT8_2(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[2]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT8_3(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[3]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT8_4(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[4]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT8_5(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[5]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT8_6(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[6]) = (VAL))
#define Wr_PPPE_Guest_RCX_UINT8_7(VMCS_T_PTR, VAL)       \
  ((__Get_PPPE_Guest_RCX_IA32MMX64_P(VMCS_T_PTR)->uint8[7]) = (VAL))

/*******************************************************************************
* ##########################################################
* #                                                        #
* # Copyright (C) 2022 Intel Corporation                   #
* # Intel Proprietary Information                          #
* #                                                        #
* ##########################################################
*
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Host_IA32_INTErrUPT_SSP_TABLE_Addr
//            is NOT CACHED by HW, so can be accessed using
//            load/stores directly (without VMREAD and VMWRITE).
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Rd_Host_IA32_INTErrUPT_SSP_TABLE_Addr()
/// @brief  Returns the value of the <tt> Host_IA32_INTErrUPT_SSP_TABLE_Addr </tt> field from a given VMCS.
///         This accessor function helps provide the fastest read access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR   Pointer to an active (potentially cacheable fields) VMCS.
/// @return <tt> uint64_t    </tt> read from the <tt> Host_IA32_INTErrUPT_SSP_TABLE_Addr </tt> field of the specified VMCS.
////////////////////////////////////////////////////////////////////////////

#define Rd_Host_IA32_INTErrUPT_SSP_TABLE_Addr(VMCS_T_PTR)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_INTERRUPT_SSP_TABLE_ADDR_OFFSET)))

////////////////////////////////////////////////////////////////////////////
// Wr_Host_IA32_INTErrUPT_SSP_TABLE_Addr()
/// @brief  Writes value <tt> val </tt> into the the <tt> Host_IA32_INTErrUPT_SSP_TABLE_Addr </tt> field a given VMCS.
///         This accessor function helps provide the fastest write access to
///         a given VMCS without having to worry about VMCS field/component cacheability.
///         Accessor active for this VT-cached VMCS field.
/// @param  VMCS_T_PTR    Pointer to an active (potentially cacheable fields) VMCS.
/// @param  VAL             uint64_t    value to be written into the VMCS.Host_IA32_INTErrUPT_SSP_TABLE_Addr field.
/// @return No return value.
////////////////////////////////////////////////////////////////////////////

#define Wr_Host_IA32_INTErrUPT_SSP_TABLE_Addr(VMCS_T_PTR, VAL)  \
  (*((uint64_t *) (((uint8_t *) (VMCS_T_PTR)) + VMX_HOST_IA32_INTERRUPT_SSP_TABLE_ADDR_OFFSET)) = (VAL))

#endif // __RPC_B0_VMX_VMCS_ACCESSORS_H__
