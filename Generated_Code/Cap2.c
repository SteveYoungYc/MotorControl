/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cap2.c
**     Project     : exp-the-motor
**     Processor   : MC56F8257
**     Component   : Capture
**     Version     : Component 02.223, Driver 02.06, CPU db: 3.00.239
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2021-05-31, 16:21, # CodeGen: 57
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Driver      :
**         It is recommended to use method GetCaptureValue in event OnCapture.
**         Content of the capture register is protected from update only
**         to end of event Cap2_OnCapture.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TMRA1
**             Counter shared          : Yes
**
**         High speed mode
**             Prescaler               : divide-by-128
**           Maximal time for capture register
**             Xtal ticks              : 1118481
**             microseconds            : 139810
**             milliseconds            : 140
**             seconds (real)          : 0.139810133333
**             Hz                      : 7
**           One tick of timer is
**             microseconds            : 2.133333
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TMRA1_CAPT [F012]
**              Counter                : TMRA1_CNTR [F015]
**              Mode                   : TMRA1_CTRL [F016]
**              Run                    : TMRA1_CTRL [F016]
**              Prescaler              : TMRA1_CTRL [F016]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       8             |  GPIOC4_TA1_CMPB_O
**             ----------------------------------------------------
**
**         Port name                   : GPIOC_Low
**         Bit number (in port)        : 4
**         Bit mask of the port        : 0010
**
**         Signal edge/level           : both
**         Priority                    : 1
**         Pull option                 : off
**
**     Contents    :
**         Reset           - byte Cap2_Reset(void);
**         GetCaptureValue - byte Cap2_GetCaptureValue(Cap2_TCapturedValue *Value);
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
/*!
** @file Cap2.c
** @version 02.06
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup Cap2_module Cap2 module documentation
**  @{
*/         

/* MODULE Cap2. */

#include "Events.h"
#include "Cap2.h"

static Cap2_TCapturedValue CntrState;  /* Content of counter */

/* Internal method prototypes */

/*
** ===================================================================
**     Method      :  Cap2_Reset (component Capture)
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte Cap2_Reset(void)
{
  CntrState = getReg(TMRA1_CNTR);      /* Load content of counter register to variable CntrState */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Cap2_GetCaptureValue (component Capture)
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               2.133333 us in high speed mode
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte Cap2_GetCaptureValue(Cap2_TCapturedValue *Value)
{
  *Value = getReg(TMRA1_CAPT);         /* Return captured value of counter register */
  *Value -= CntrState;                 /* Subtract counter state stored during last reset */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Cap2_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cap2_Init(void)
{
  /* TMRA1_CTRL: CM=0,PCS=0,SCS=1,ONCE=0,LENGTH=0,DIR=0,Co_INIT=0,OM=0 */
  setReg(TMRA1_CTRL,0x80);             /* Set up mode */
  setReg(TMRA1_CNTR,0x00);             /* Reset counter register */
  setReg(TMRA1_LOAD,0x00);             /* Reset load register */
  setRegBit(TMRA1_SCTRL,IEFIE);        /* Enable input edge interrupt */
  setReg(TMRA1_CAPT,0x00);             /* Reset capture register */
  /* TMRA1_FILT: ??=0,??=0,??=0,??=0,??=0,FILT_CNT=0,FILT_PER=0 */
  setReg(TMRA1_FILT,0x00);             /* Set up input filter register */
  CntrState = 0U;                      /* Initial state of variable */
  setRegBitGroup(TMRA1_CTRL,PCS,0x0F); /* Set prescaler register according to the selected high speed CPU mode */
  setRegBitGroup(TMRA1_SCTRL,CAPTURE_MODE,0x03); /* Enable capture */
}

/*
** ===================================================================
**     Method      :  Cap2_Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the beans event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cap2_Interrupt(void)
{
  Cap2_OnCapture();                    /* Invoke user event */
  clrRegBit(TMRA1_SCTRL,IEF);          /* Reset interrupt request flag and enable updating of the capture register */
}

/* END Cap2. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/