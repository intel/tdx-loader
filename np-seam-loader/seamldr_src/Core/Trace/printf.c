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
#include <trace.h>

#if MKF_TRACE == 1
#ifdef TRACE_WITH_FUNCTIONS
UINT8 traceControls = TRACE_WITH_FUNCTIONS;
#else
UINT8 traceControls = 0;
#endif

#define TAB_STOP          4
#define LEFT_JUSTIFY      0x001
#define PREFIX_SIGN       0x002
#define PREFIX_PADBLANK   0x004
#define PREFIX_PADZERO    0x008
#define LONG_TYPE         0x010

#define INT_SIGNED        0x020
#define COMA_TYPE         0x040
#define LONG_LONG_TYPE    0x080
#define DONT_TERMINATE    0x100
#define PREFIX_PADPOINTER 0x200

#define INT32_MAX         0x7fffffffU

#define PREFIX_PADMASK    0x20C

#define TEMP_STR_LEN      160

#define isdigit(_c) (((_c) >= '0') && ((_c) <= '9'))

static UINT32 StrToNumber(char **String)
{
  UINT32 Sum;
  char *Str;

  Str = *String;
  if (*Str == '0') {
    Str++;
  }
  Sum = 0;
  while (isdigit(*Str)) {
    Sum = Sum * 10 + (*Str++ - '0');
  }
  *String = Str;
  return Sum;
}

#pragma optimize( "", off )
//-----------------------------------------------------------------------------
static void UintnToStr(UINT32 Value, char *Str, UINT32 Width, UINT32 Flags, UINT32 Base)
{
  UINT32 Negative;
  UINT32 Int;
  UINT32 IntDigits;
  char *Ptr;
  char Prefix = 0;
  char c;
  UINT32 i;
  const char Hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
  char *End = Str + TEMP_STR_LEN;

#define UPDATE_STR(C) do { \
    if (Ptr < End) \
    *Ptr++ = (C); \
} while (0);

  Ptr = Str;
  if ((Value > INT32_MAX) && (Flags & INT_SIGNED)) {
    Int = ~Value + 1; /* -Value */
    Negative = 1;
  } else {
    Int = Value;
    Negative = 0;
  }

  i = 0;
  do { /* generate digits in reverse order */
    i++;
    UPDATE_STR(Hex[Int % Base]);
    if (Flags & COMA_TYPE) {
      if (Base == 16) {
        if (i % 4 == 0) {
          *Ptr++ = ',';
        }
      } else if (Base == 10) {
        if (i % 3 == 0) {
          *Ptr++ = ',';
        }
      }
    }
  } while ((Int /= Base) > 0);

  if (*(Ptr - 1) == ',') {
    Ptr--;
  }

  if (Negative) {
    *Ptr++ = '-';
  } else if (Flags & PREFIX_SIGN) {
    *Ptr++ = '+';
  }

  IntDigits = Ptr - Str;

  if ((Flags & PREFIX_PADMASK) && (Width > IntDigits)) {
    Width -= IntDigits;
    for (i = 0; i < Width; i++) {
      if (Flags & PREFIX_PADPOINTER) {
        Prefix = '0';
        if ((i + IntDigits) > 7) {
          Prefix = ' ';
        }
      }
      if (Flags & PREFIX_PADZERO) {
        Prefix = '0';
      }
      if (Flags & PREFIX_PADBLANK) {
        Prefix = ' ';
      }
      UPDATE_STR(Prefix);
    }
  }

  // For 64-bit values, the lower 32-bits already terminated string.
  if (!(Flags & DONT_TERMINATE)) {
    if (Ptr >= End) {
      Ptr = End - 1;
    }
    UPDATE_STR('\0');
  }
  --Ptr;

  /* reverse string */
  while (Str < --Ptr) {
    c = *Str;
    *Str++ = *Ptr;
    *Ptr = c;
  }
}

#pragma optimize( "", on )

static void
__printf(const char *Format, va_list Marker)
/*++
 *
 * Routine Description:
 *
 *  printf with stdargs varargs stack frame in place of .... Limited
 *  support for sizes other than UINTN to save code space
 *
 * Arguments:
 *  Format - String containing characters to print and formating data.
 *
 *  %[flags][width]type
 *
 *  [flags] '-' left align
 *  [flags] '+' prefix with sign (+ or -)
 *  [flags] '0' zero pad numbers
 *  [flags] ' ' prefix black in front of postive numbers
 *
 *  [width] non negative decimal integer that specifies
 *          the width to print a value.
 *  [width] '*' get the width from a int argument on the stack.
 *
 *  type    'd'|'i' signed decimal integer
 *  type    'u' unsinged integer
 *  type    'x'|'X' usinged hex using "ABCDEF"
 *  type    'c' print character
 *  type    'p' print a pointer to void
 *
 *  Marker - va_list that points to the arguments for Format that are on
 *              the stack.
 *
 *
 * Returns:
 *
 *  Prints to putchar() - To save space we print every thing as UINTN and
 *  don't support type over rides like {h | I | I64 | L}
 *
 * --*/
{
  char *p;
  UINT32 Width;
  UINT32 Flags;
  char Str[TEMP_STR_LEN];
  char *String;

  // UINT32 i;

  for (p = (char *)Format; *p; p++) {
    if (*p != '%') {
      TraceWriteString(p, 1);
      continue;
    }

    p++;
    // Check for flags
    Flags = 0;
    if (*p == '-') {
      Flags |= LEFT_JUSTIFY;
    } else if (*p == '+') {
      Flags |= PREFIX_SIGN;
    } else if (*p == ' ') {
      Flags |= PREFIX_PADBLANK;
    }
    if (Flags != 0) {
      p++;
    }

    Width = 0;
    // Check for width
    if (isdigit(*p)) {
      if (*p == '0') {
        Flags |= PREFIX_PADZERO;
      }
      Width = StrToNumber(&p);
    } else if (*p == '*') {
      Width = va_arg(Marker, int);
      p++;
    }

    if (*p == ',') {
      Flags |= COMA_TYPE;
      p++;
    }

    if (!(Flags & PREFIX_PADZERO) && !(Flags & LEFT_JUSTIFY)) {
      Flags |= PREFIX_PADBLANK;
    }

    // get type
    String = Str;
    switch (*p) {
    case 'd':
    case 'i':
      // always print as UINTN will need extra code to print different widths
      UintnToStr((UINT32)va_arg(Marker, UINT32 *), Str, Width, Flags | INT_SIGNED, 10);
      break;
    case 'u':
      // always print as UINTN will need extra code to print different widths
      UintnToStr((UINT32)va_arg(Marker, UINT32 *), Str, Width, Flags, 10);
      break;
    case 'x':
    case 'X':
      // always print as UINTN will need extra code to print different widths
      UintnToStr((UINT32)va_arg(Marker, UINT32 *), Str, Width, Flags, 16);
      break;
    case 'c':
      Str[0] = (char)va_arg(Marker, char);
      Str[1] = '\0';
      break;
    case 's':
      String = (char *)va_arg(Marker, char *);
      break;
    case 'p':
      Flags &= ~PREFIX_PADMASK;
      Flags |= PREFIX_PADPOINTER;
      if (Width < 8) {
        Width = 8;
      }
      UintnToStr((UINT32)va_arg(Marker, UINT32 *), Str, Width, Flags, 16);
      break;
    case 'L':
      NumToStr(Str, 8, (UINT64)va_arg(Marker, UINT64));
      break;
    }
    TraceWriteString(String, 0);
  }
  return;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//
// NOTE:  Because printf treats all UINT8 and UINT16 data values as if they were UINT32's, when calling printf from ASM code,
//        you must push a DWORD for every variable that is 32 bits or less in size.
//        Otherwise, printf will look at the higher WORD or nibbles and if non-zero, print a larger value.
//
static void
_printf(const char *Format, ...)
{
  va_list Marker;

  va_start(Marker, Format);
  __printf(Format, Marker);
  return;
}

void
Printf(const char *Format, ...)
{
  va_list Marker;
  PTR_FUNC_NO_ARG pFunc = (PTR_FUNC_NO_ARG)traceRoutines.preTrace;

  // If ACM has a pre-trace routine, call it.
  if (pFunc) {
    (*pFunc)();
  }
  va_start(Marker, Format);
  __printf(Format, Marker);
  // If ACM has a post-trace routine, call it
  pFunc = (PTR_FUNC_NO_ARG)traceRoutines.postTrace;
  if (pFunc) {
    (*pFunc)();
  }
  va_end(Marker);
  return;
}

void
TraceFunction(UINT8 control, char *Format, ...)
{
  va_list Marker;
  PTR_FUNC_NO_ARG pFunc = (PTR_FUNC_NO_ARG)traceRoutines.preTrace;

  if (!(traceControls & control)) {
    return;
  }
  // If ACM has a pre-trace routine, call it.
  if (pFunc) {
    (*pFunc)();
  }
  va_start(Marker, Format);
  __printf(Format, Marker);
  // If ACM has a post-trace routine, call it
  pFunc = (PTR_FUNC_NO_ARG)traceRoutines.postTrace;
  if (pFunc) {
    (*pFunc)();
  }
  va_end(Marker);
  return;
}

void
PrintBuffer(UINT8 control, const unsigned char *buffer, UINT32 size, const char *fmt, ...)
{
  va_list Marker;
  UINT32 i;
  PTR_FUNC_NO_ARG pFunc = (PTR_FUNC_NO_ARG)traceRoutines.preTrace;

  if (!(traceControls & control)) {
    return;
  }
  // If ACM has a pre-trace routine, call it.
  if (pFunc) {
    (*pFunc)();
  }
  va_start(Marker, fmt);
  __printf(fmt, Marker);
  va_end(Marker);
  for (i = 0; i < size; ++i, ++buffer) {
    if (i && !(i % 16)) {
      _printf("\n");
    }
    _printf("%02x ", *buffer);
  }
  _printf("\n");
  pFunc = (PTR_FUNC_NO_ARG)traceRoutines.postTrace;
  if (pFunc) {
    (*pFunc)();
  }
}

#pragma optimize( "", off )

#endif
