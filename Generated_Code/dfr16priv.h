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

/* File: dfr16priv.h */

#ifndef __DFR16PRIV_H
#define __DFR16PRIV_H

#include "port.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************
* 16-bit Fractional FIR Filter private data structure
*******************************************************/
typedef struct dfr16_sFirStructPriv
{
  Frac16 * pC;                 /* Coefficients for the filter */
  Frac16 * pHistory;           /* Memory for the filter history buffer */
  Frac16 * pNextHistoryAddr;   /* Next memory element to use */
  UInt16   n;                  /* Length of the vector of FIR filter coefficients */
  ibool    bCanUseModAddr;     /* Can use modulo addressing on history buffer */
  ibool    bCanUseDualMAC;     /* Set if FIR can use dual parallel move MAC */
  UInt16   Factor;             /* Interpolation or decimation factor */
  UInt16   Count;              /* Count used in decimation/interpolation */
} dfr16_tFirStructPriv;


/*******************************************************
* 16-bit Fractional CFFT private data structure
*******************************************************/

/* Added: MIEL_PRASAD */
typedef struct {
    UInt16 options;
    UInt16 n;
    CFrac16 *Twiddle;
    Int16 No_of_Stages;
} dfr16_tCFFTStruct;


/*******************************************************
* 16-bit Fractional IIR Filter private data structure
*******************************************************/
typedef struct dfr16_sIirStruct
{
  Frac16 * pC;                 /* Coefficients for the filter */
  Frac16 * pHistory;           /* Memory for the filter history buffer */
  Frac16 * pNextHistoryAddr;   /* Next memory element to use */
  UInt16   nbiq;               /* No. of biquads */
  ibool    bCanUseModAddr;     /* Can use modulo addressing on history buffer */
  ibool    bCanUseDualMAC;     /* Set if IIR can use dual parallel move MAC */
} dfr16_tIirStruct;

/***********************************************************/
/* 16-bit Fractional RFFT private Data structure           */
/***********************************************************/

typedef struct
{
    UInt16 options;
    UInt16 n;
    CFrac16 *Twiddle;
    CFrac16 *Twiddle_br;
    UInt16 No_of_Stages;
} dfr16_tRFFTStruct;

#ifdef __cplusplus
}
#endif

#endif

