/* This Software is part of Wind River Simics. The rights to copy, distribute,
 * modify, or otherwise make use of this Software may be licensed only
 * pursuant to the terms of an applicable license agreement.
 *
 * Copyright 2010-2019 Intel Corporation */

#ifndef SIMICS_MAGIC_INSTRUCTION_H
#define SIMICS_MAGIC_INSTRUCTION_H

#if (MKF_ENGINEERING == 1)

#define MAGIC(n) do {                                                       \
                         \
    int CpuInfo[4];    \
    int Input = (0x4711 | ((unsigned)(n) << 16));   \
    __cpuid(CpuInfo, Input);    \
} while (0)

#define SIMICS_BREAKPOINT MAGIC(0)

#else

#define SIMICS_BREAKPOINT

#endif

#define SIMICS_BREAK_TRACE(s) \
  ComSerialOut(s); \
  SIMICS_BREAKPOINT \

#endif
