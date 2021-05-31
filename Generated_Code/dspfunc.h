/** ###################################################################
**
**     (c) Freescale Semiconductor, Inc.
**     2004 All Rights Reserved
**
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/

/* File: dspfunc.h */

#ifndef __DSPFUNC_H
#define __DSPFUNC_H

#ifndef SDK_LIBRARY
 #include "configdefines.h"

 #ifndef INCLUDE_DSPFUNC
  #error INCLUDE_DSPFUNC must be defined in AppConfig.h to initialize the DSP Function Library
 #endif
#endif

/*
   This include file is the master include file for the
   DSP568xx Digital Signal Processing Function Library -
   Fractional Algorithms for C and Assembly Programmers.
*/

/***************************
 Foundational Include Files
****************************/
#include "port.h"
#include "arch.h"
#include "prototype.h"
#include "dfr16priv.h"   /* MIEL_PRASAD */

/***************************
 Trigonometric Functions
****************************/
#include "tfr16.h"

/***************************
 Signal Processing Functions
****************************/
#include "dfr16.h"

/***************************
 Functions to Workaround CW problems
****************************/

unsigned long impyuu (unsigned short unsigA, unsigned short unsigB);
long          impysu (short          sig,    unsigned short unsig);

void dspfuncInitialize(void);

#endif
