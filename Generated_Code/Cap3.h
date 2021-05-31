/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cap3.h
**     Project     : exp-the-motor
**     Processor   : MC56F8257
**     Component   : Capture
**     Version     : Component 02.223, Driver 02.06, CPU db: 3.00.239
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2021-05-17, 16:50, # CodeGen: 53
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Driver      :
**         It is recommended to use method GetCaptureValue in event OnCapture.
**         Content of the capture register is protected from update only
**         to end of event Cap3_OnCapture.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TMRA2
**             Counter shared          : No
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
**              Capture                : TMRA2_CAPT [F022]
**              Counter                : TMRA2_CNTR [F025]
**              Mode                   : TMRA2_CTRL [F026]
**              Run                    : TMRA2_CTRL [F026]
**              Prescaler              : TMRA2_CTRL [F026]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       31            |  GPIOC6_TA2_XB_IN3_CMP_REF
**             ----------------------------------------------------
**
**         Port name                   : GPIOC_Low
**         Bit number (in port)        : 6
**         Bit mask of the port        : 0040
**
**         Signal edge/level           : both
**         Priority                    : 1
**         Pull option                 : off
**
**     Contents    :
**         Enable          - byte Cap3_Enable(void);
**         Disable         - byte Cap3_Disable(void);
**         EnableEvent     - byte Cap3_EnableEvent(void);
**         Reset           - byte Cap3_Reset(void);
**         GetCaptureValue - byte Cap3_GetCaptureValue(Cap3_TCapturedValue *Value);
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
** @file Cap3.h
** @version 02.06
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup Cap3_module Cap3 module documentation
**  @{
*/         

#ifndef __Cap3
#define __Cap3

/* MODULE Cap3. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#ifndef __BWUserType_Cap3_TCapturedValue
#define __BWUserType_Cap3_TCapturedValue
  typedef word Cap3_TCapturedValue;    /* Captured value, unsigned integer value. Bit-width of the type depends on the width of selected timer. */
#endif

#define Cap3_PRESCALER_VALUE 0x80UL    /* Initial prescaler value of the timer. It is available only if the bean is enabled in high speed mode. */
#define Cap3_PRESCALER_VALUE_HIGH 0x80UL /* Prescaler value of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */
#define Cap3_COUNTER_INPUT_CLOCK_HZ_HIGH 0x0007270EUL /* Counter input clock value in high speed mode [Hz] (integer number). It is available only if the bean is enabled in high speed mode. */
#define Cap3_COUNTER_INPUT_CLOCK_HZ 0x0007270EUL /* Initial counter input clock value [Hz] (integer number). It is available only if the bean is enabled in high speed mode. */
/* Deprecated constants */
#define Cap3_CFhigh        0x0007270EUL /* Frequency of counting in high speed CPU mode */

byte Cap3_Enable(void);
/*
** ===================================================================
**     Method      :  Cap3_Enable (component Capture)
**     Description :
**         This method enables the component - it starts the capture.
**         Events may be generated (<DisableEvent>/<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte Cap3_Disable(void);
/*
** ===================================================================
**     Method      :  Cap3_Disable (component Capture)
**     Description :
**         This method disables the component - it stops the capture.
**         No events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte Cap3_EnableEvent(void);
/*
** ===================================================================
**     Method      :  Cap3_EnableEvent (component Capture)
**     Description :
**         This method enables the events. This method is available
**         only if any event is selected.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte Cap3_Reset(void);
/*
** ===================================================================
**     Method      :  Cap3_Reset (component Capture)
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

byte Cap3_GetCaptureValue(Cap3_TCapturedValue *Value);
/*
** ===================================================================
**     Method      :  Cap3_GetCaptureValue (component Capture)
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

void Cap3_Init(void);
/*
** ===================================================================
**     Method      :  Cap3_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void Cap3_Interrupt(void);
/*
** ===================================================================
**     Method      :  Cap3_Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the beans event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Cap3. */

#endif /* ifndef __Cap3 */
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