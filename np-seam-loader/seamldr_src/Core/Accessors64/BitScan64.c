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
#include <common.h>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  BitScanForward64
//
//  Input:      val - value to be scanned.
//
//  Output:     index - BIT number of first set bit
//              1 if bit is set.
//              0 if no bits are set.
//
//  Description: val is scanned forward. Index of first set bit is
//  returned in index parameter. Function returns boolean value
//  indicating whether any bit is set.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 BitScanForward64 (UINT32 *index, UINT64 val)
{
  UINT32 Reg;

  if (val == 0)
    return 0;

  if ((UINT32) (val & 0xFFFFFFFF) != 0) {
    _BitScanForward (index,(UINT32) val);
  } else if ((Reg = highdword(val)) != 0) {
    _BitScanForward (index, Reg);
    *index += 32;
  }
  return 1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  BitScanForward64AndReset
//
//  Input:      pVal - pointer to value to be scanned.
//
//  Output:     pIndex - pointer to where to store BIT number of first set bit
//              1 if bit is set.
//              0 if no bits are set.
//
//  Description: *pVal is scanned forward. Index of first set bit is
//  returned in *pIndex parameter. Function returns boolean value
//  indicating whether any bit is set.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 BitScanForward64AndReset (UINT32 *pIndex, UINT64 *pVal)
{

  UINT32 *pHighVal;

  if (*pVal == 0)
    return 0;

  if ((UINT32) (*pVal & 0xFFFFFFFF) != 0) {
    BitScanForwardAndReset (pIndex,(UINT32 *) pVal);
  } else {
    pHighVal = (UINT32 *)pVal + 1;

    BitScanForwardAndReset (pIndex, pHighVal);

    *pIndex += 32;
  }
  return 1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  BitScanReverse64
//
//  Input:      val - value to be scanned.
//
//  Output:     index - BIT number of first set bit
//              1 if bit is set.
//              0 if no bits are set.
//
//  Description: val is scanned backward. Index of first set bit is
//  returned in index parameter. Function returns boolean value
//  indicating whether any bit is set.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 BitScanReverse64 (UINT32 *index, UINT64 val)
{
  UINT32 Reg;

  if (val == 0)
    return 0;

  if ((Reg = highdword(val)) != 0) {
    _BitScanReverse (index, Reg);
    *index += 32;
  } else if ((UINT32) val != 0) {
    _BitScanReverse (index,(UINT32) val);
  }
  return 1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  BitScanReverse64AndReset
//
//  Input:      pVal - pointer to value to be scanned.
//
//  Output:     pIndex - pointer to where to store BIT number of first set bit
//              1 if bit is set.
//              0 if no bits are set.
//
//  Description: *pVal is scanned reverse. Index of first set bit is
//  returned in *pIndex parameter. Function returns boolean value
//  indicating whether any bit is set.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 BitScanReverse64AndReset (UINT32 *pIndex, UINT64 *pVal)
{

  UINT32 *pHighVal;

  if (*pVal == 0)
    return 0;

  if ((UINT32) (*pVal & 0xFFFFFFFF) != 0) {
    BitScanReverseAndReset (pIndex,(UINT32 *) pVal);
  } else {
    pHighVal = (UINT32 *)pVal + 1;

    BitScanReverseAndReset (pIndex, pHighVal);

    *pIndex += 32;
  }
  return 1;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  BitScanForwardAndReset
//
//  Input:      pVal - pointer to value to be scanned.
//
//  Output:     pIndex - pointer to var to store BIT number of first set bit
//              1 if bit is set.
//              0 if no bits are set.
//
//  Description: *pVal is scanned forward. Index of first set bit is
//  returned in *pIndex parameter. Function returns boolean value
//  indicating whether any bit is set. Tested bit is reset.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 BitScanForwardAndReset (UINT32 *pIndex, UINT32 *pVal)
{

  if (0 == _BitScanForward (pIndex, *pVal))
	  return 0;
  _bittestandreset (pVal, *pIndex);
  return 1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Procedure:  BitScanReverseAndReset
//
//  Input:      pVal - pointer to value to be scanned.
//
//  Output:     pIndex - pointer where to store BIT number of first set bit
//              1 if bit is set.
//              0 if no bits are set.
//
//  Description: *pVal is scanned forward. Index of first set bit is
//  returned in *pIndex parameter. Function returns boolean value
//  indicating whether any bit is set. Tested bit is reset.
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UINT32 BitScanReverseAndReset (UINT32 *pIndex, UINT32 *pVal)
{

  if (0== _BitScanReverse (pIndex, *pVal))
	  return 0;
  _bittestandreset (pVal, *pIndex);
  return 1;
}

