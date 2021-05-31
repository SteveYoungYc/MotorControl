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

#include "port.h"

#include "dspfunc.h"



/*****************************************************************************/
void dspfuncInitialize(void)
{

  /* Set saturation mode, set 2's complement rounding, and reset limit bit */

  archSetSat32();
  archSet2CompRound();
  archResetLimitBit();
}

/*****************************************************************************/
/* Primitives (impyuu, impysu) added to circumvent CW problems */

#if 0
// CW V2 compiler is used to implement these functions for V1 compatibility

#undef add

asm unsigned long impyuu(unsigned short unsigA, unsigned short unsigB)
{  /* y0 = unsigA, y1 = unsigB */
  push  OMR      /* store the status of the OMR register */
  bfclr #0x10,OMR    /* set saturation OFF (SA = 0) */
  bfset #0x0100,OMR   /* set Condition Code bit (CC) bit to 1 */
  move  y0,x0      /* save y0 (unsigA) to x0 */
  andc  #0x7fff,y0    /* mask the sign position - represent the positive sign number */
  mpysu y0,y1,a    /* multiply signed operand (y0) and unsigned operand (unsigB = y1)*/
  tstw  x0        /* test if MSB is 0 or 1 (set N flag in SR reg) */
  bge   OVER      /* jump accordig to N flag - if 1 pass, if 0 jump */
  movei #0x7fff,x0  /* store maximum positive value to x0 */
  macsu x0,y1,a    /* multiply 0x7fff with unsigB and accumulate with the previous product */
  clr   b        /* clear B register, used as a temporary location */
  move  y1,b0      /* move unsigB to the LSP of B */
  add   b,a        /* correct the result, needed two times because of fractional multiplication */
  add   b,a       /*  --||-- */
  OVER:
    asr   a               /* fractional into integer number conversion */
  bge   OVERFLOW        /* branch according to V flag - if 1 jump, if 0 pass */
  bfclr #0x8000,a1    /* correction of the sign position - clear MSB bit in A */
  OVERFLOW:
  pop   OMR             /* restore original contents of OMR */
    rts
}


/* asm Int32 impysu(Int16 sig, UInt16 unsig) */
asm long impysu(short sig, unsigned short unsig)
{
  mpysu y0,y1,a
  asr a
  rts
}

#define add             __add

#else

unsigned long impyuu(unsigned short unsigA, unsigned short unsigB)
{
  return (unsigned long)unsigA * unsigB;
}

long impysu(short sig, unsigned short unsig)
{
  return (long)sig * unsig;
}

#endif
