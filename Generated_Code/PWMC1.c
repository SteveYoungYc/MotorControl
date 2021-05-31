/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PWMC1.c
**     Project     : exp-the-motor
**     Processor   : MC56F8257
**     Component   : PWMMC
**     Version     : Component 01.779, Driver 01.01, CPU db: 3.00.239
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2021-03-27, 16:53, # CodeGen: 13
**     Abstract    :
**         This component "PWMMC" implements 6-channel center-aligned or 
**         edge-aligned pulse-width modulator for AC motor control, which 
**         is presented on chip. The device is capable of controlling most 
**         motor types: AC induction motors (ACIM), both brushless (BLDC) 
**         and brush DC motors (BDC), switched (SRM) and variable reluctance  
**         motors (VRM),and stepper motors.
**         Another possibility of using this component is as a pulse-width modulation 
**         generator that generates 6 signals with variable duty and fixed cycle.
**     Settings    :
**          Component name                                 : PWMC1
**          Device                                         : eFlexPWM
**          Device                                         : eFlexPWM_SM0_Timer
**          Align                                          : center-aligned mode
**          Peripheral initialization                      : eFlexPWM
**          Reload                                         : 1
**          Frequency/period                               : 1 kHz
**          Output Frequency                               : 1000 Hz
**          Same frequency in modes                        : no
**          Dead-time                                      : 0 ?s
**          Dead-time 1                                    : 0 ?s
**          Interrupt service/event                        : Enabled
**            Reload interrupt priority                    : medium priority
**            Interrupt on reload                          : INT_PWM_SubModule0_Reload
**            Fault protection interrupts                  : Enabled
**              Interrupt on fault 0                       : INT_PWM_Fault
**              Fault 0 interrupt priority                 : medium priority
**              Interrupt on fault 1                       : INT_PWM_Fault
**              Fault 1 interrupt priority                 : medium priority
**              Interrupt on fault 2                       : INT_PWM_Fault
**              Fault 2 interrupt priority                 : medium priority
**              Interrupt on fault 3                       : INT_PWM_Fault
**              Fault 3 interrupt priority                 : medium priority
**            Interrupt preserve registers                 : yes
**          Channel 0                                      : 
**            Channel                                      : eFlexPWM_SM0_ChannelA
**            PWM pin                                      : GPIOE1_PWM0A
**            PWM pin signal                               : 
**          Channel 1                                      : Enabled
**            Channel                                      : eFlexPWM_SM0_ChannelB
**            PWM pin                                      : GPIOE0_PWM0B
**            PWM pin signal                               : 
**          Channel 2                                      : Enabled
**            Channel                                      : eFlexPWM_SM1_ChannelA
**            PWM pin                                      : GPIOE3_PWM1A
**            PWM pin signal                               : 
**          Channel 3                                      : Enabled
**            Channel                                      : eFlexPWM_SM1_ChannelB
**            PWM pin                                      : GPIOE2_PWM1B
**            PWM pin signal                               : 
**          Channel 4                                      : Enabled
**            Channel                                      : eFlexPWM_SM2_ChannelA
**            PWM pin                                      : GPIOE5_PWM2A_XB_IN3
**            PWM pin signal                               : 
**          Channel 5                                      : Enabled
**            Channel                                      : eFlexPWM_SM2_ChannelB
**            PWM pin                                      : GPIOE4_PWM2B_XB_IN2
**            PWM pin signal                               : 
**          Fault protection                               : controlled by this component
**            Fault 0                                      : Enabled
**              Fault clearing mode                        : automatic
**              Fault flag clearing                        : Do not initialize
**            Fault 1                                      : Enabled
**              Fault clearing mode                        : automatic
**              Fault flag clearing                        : Do not initialize
**            Fault 2                                      : Enabled
**              Fault clearing mode                        : automatic
**              Fault flag clearing                        : Do not initialize
**            Fault 3                                      : Enabled
**              Fault clearing mode                        : automatic
**              Fault flag clearing                        : Do not initialize
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Simulation output mode                         : PWM
**          High output value                              : 1
**          Low output value                               : 0
**     Contents    :
**         SetDuty          - byte PWMC1_SetDuty(byte Channel, PWMC1_TPWMMC_Duty Duty);
**         Load             - void PWMC1_Load(void);
**         SetRatio16       - byte PWMC1_SetRatio16(byte Channel, word Ratio);
**         OutputPadEnable  - void PWMC1_OutputPadEnable(void);
**         OutputPadDisable - void PWMC1_OutputPadDisable(void);
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
** @file PWMC1.c
** @version 01.01
** @brief
**         This component "PWMMC" implements 6-channel center-aligned or 
**         edge-aligned pulse-width modulator for AC motor control, which 
**         is presented on chip. The device is capable of controlling most 
**         motor types: AC induction motors (ACIM), both brushless (BLDC) 
**         and brush DC motors (BDC), switched (SRM) and variable reluctance  
**         motors (VRM),and stepper motors.
**         Another possibility of using this component is as a pulse-width modulation 
**         generator that generates 6 signals with variable duty and fixed cycle.
*/         
/*!
**  @addtogroup PWMC1_module PWMC1 module documentation
**  @{
*/         


/* MODULE PWMC1. */

#include "Events.h"
#include "PWMC1.h"


/*
** ===================================================================
**     Method      :  PWMC1_InterruptOnReload (component PWMMC)
**
**     Description :
**         This event is called before PWM cycle according to reload 
**         frequency. The event is invoked only when the component is 
**         enabled and the events are enabled. This event is enabled only 
**         if Interrupt service/event is enabled.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp saveall
void PWMC1_InterruptOnReload(void)
{
  setRegBits(PWM_SM0_STS,0x1000);      /* Clear reload flag */
    PWMC1_OnReload();                  /* Invoke user event */
}

/*
** ===================================================================
**     Method      :  PWMC1_InterruptOnFault (component PWMMC)
**
**     Description :
**         This event is called when fault occurs. Only when the 
**         component is enabled and the events are enabled. This event is 
**         enabled only if Interrupt service/event is enabled and 
**         property Fault protection is set to controlled by this 
**         component. The event clears Fault flag only when the Fault is 
**         set to the automatic clearing mode. When the Fault is set to 
**         the manual clearing mode, the Fault flag must be cleared by 
**         the user using ClearFaultFlag() method.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp saveall
void PWMC1_InterruptOnFault(void)
{
  register byte FaultChannel0Flags = getReg16(PWM_FSTS); /* Stored Fault Channel0 flags */

  setReg16BitGroupVal(PWM_FSTS, FFLAG, 0x0FU); /* Clear interrupt flags of channel0 */
  if ((FaultChannel0Flags & PWM_FSTS_FFLAG0_MASK) != 0U) {
    PWMC1_OnFault0();                  /* Invoke user event */
  }
  if ((FaultChannel0Flags & PWM_FSTS_FFLAG1_MASK) != 0U) {
    PWMC1_OnFault1();                  /* Invoke user event */
  }
  if ((FaultChannel0Flags & PWM_FSTS_FFLAG2_MASK) != 0U) {
    PWMC1_OnFault2();                  /* Invoke user event */
  }
  if ((FaultChannel0Flags & PWM_FSTS_FFLAG3_MASK) != 0U) {
    PWMC1_OnFault3();                  /* Invoke user event */
  }
}

/*
** ===================================================================
**     Method      :  PWMC1_Init (component PWMMC)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PWMC1_Init(void)
{
  eFlexPWM_Init();
}

/*
** ===================================================================
**     Method      :  PWMC1_SetDuty (component PWMMC)
**     Description :
**         Setting duty (value) register(s) of selected channel. The
**         value is loaded after calling <Load> method.
**         
**         [ Version specific information for Freescale 56800/E and
**         HC08 and HCS12 and HCS12X derivatives ] 
**         Setting is valid for actual speed mode only, initial value
**         is restored after speed mode change.
**         
**         [ Version specific information for Freescale 56800/E
**         derivatives - eFlexPWM device ] 
**         Duty register(s) value is not affected during speed mode
**         change. It should be handled by the user code.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Channel         - Channel number (0 - 5). The number
**                           corresponds to the logical channel number
**                           assigned in the component settings, which
**                           may not correspond to channel number of the
**                           peripheral.
**         Duty            - Duty value for selected channel.
**                           
**                           Writing a number less than or equal to 0
**                           causes the PWM to be off for the entire PWM
**                           period. Writing a number greater than or
**                           equal to the 15 bit (12-bit on HC08MR32 CPU)
**                           modulus causes the PWM to be on for the
**                           entire PWM period.
**                           
**                           [ Version specific information for
**                           Freescale 56800/E derivatives - eFlexPWM
**                           device ] 
**                           Parameter duty is an unsigned value. 
**                           - _edge-aligned mode:_ parameter value is
**                           written into PWM clear-edge
**                           (eFlexPWM_SMn_VALx) register; PWM set-edge
**                           (eFlexPWM_SMn_VALx) register is not
**                           affected (zero value assumed); where x = 2,
**                           4. 
**                           - _center-aligned mode:_ parameter value is
**                           split between PWM set-edge
**                           (eFlexPWM_SMn_VALx) and PWM clear-edge
**                           (eFlexPWM_SMn_VAL(x+1)) registers; where x
**                           = 2, 4.
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_NOTAVAIL - Channel is disabled 
**                           - ERR_RANGE - Parameter Channel is out of
**                           range
** ===================================================================
*/
byte PWMC1_SetDuty(byte Channel,PWMC1_TPWMMC_Duty Duty)
{
  register PWMC1_TPWMMC_Duty HalfDuty = (PWMC1_TPWMMC_Duty)(Duty >> 0x01); /* Calculate half of duty */

  switch (Channel) {
    case 0:
      setReg(PWM_SM0_VAL2,(HalfDuty - Duty)); /* Store value to the set duty register of channel 0 */
      setReg(PWM_SM0_VAL3,HalfDuty);   /* Store value to the clear duty register of channel 0 */
      break;
    case 1:
      setReg(PWM_SM0_VAL4,(HalfDuty - Duty)); /* Store value to the set duty register of channel 1 */
      setReg(PWM_SM0_VAL5,HalfDuty);   /* Store value to the clear duty register of channel 1 */
      break;
    case 2:
      setReg(PWM_SM1_VAL2,(HalfDuty - Duty)); /* Store value to the set duty register of channel 2 */
      setReg(PWM_SM1_VAL3,HalfDuty);   /* Store value to the clear duty register of channel 2 */
      break;
    case 3:
      setReg(PWM_SM1_VAL4,(HalfDuty - Duty)); /* Store value to the set duty register of channel 3 */
      setReg(PWM_SM1_VAL5,HalfDuty);   /* Store value to the clear duty register of channel 3 */
      break;
    case 4:
      setReg(PWM_SM2_VAL2,(HalfDuty - Duty)); /* Store value to the set duty register of channel 4 */
      setReg(PWM_SM2_VAL3,HalfDuty);   /* Store value to the clear duty register of channel 4 */
      break;
    case 5:
      setReg(PWM_SM2_VAL4,(HalfDuty - Duty)); /* Store value to the set duty register of channel 5 */
      setReg(PWM_SM2_VAL5,HalfDuty);   /* Store value to the clear duty register of channel 5 */
      break;
    default:
      return ERR_RANGE;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PWMC1_Load (component PWMMC)
**     Description :
**         Apply last setting of the methods <SetDuty>, <SetDutyPercent>,
**         both <SetRatio*>, <SetPeriod> and <SetPrescaler>.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_Load(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/*
** ===================================================================
**     Method      :  PWMC1_OutputPadEnable (component PWMMC)
**     Description :
**         Method enables output pads.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_OutputPadEnable(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/*
** ===================================================================
**     Method      :  PWMC1_OutputPadDisable (component PWMMC)
**     Description :
**         Method disables output pads.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_OutputPadDisable(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/*
** ===================================================================
**     Method      :  PWMC1_SetRatio16 (component PWMMC)
**     Description :
**         This method sets a new duty-cycle ratio for selected channel.
**         The value is loaded after calling <Load> method.
**         
**         [ Version specific information for Freescale 56800/E and
**         HC08 and HCS12 and HCS12X derivatives ] 
**         Setting is valid for actual speed mode only, initial value
**         is restored after speed mode change.
**         
**         [ Version specific information for Freescale 56800/E
**         derivatives - eFlexPWM device ] 
**         Settings is not affected during speed mode change. It should
**         be handled by the user code.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Channel         - channel number (0 - 5). The number
**                           corresponds to the logical channel number
**                           assigned in the component settings, which
**                           may not correspond to channel number of the
**                           peripheral.
**         Ratio           - Ratio is expressed as an 16-bit
**                           unsigned integer number. 0 - 65535 value is
**                           proportional to ratio 0 - 100%.
**                           
**                           [ Version specific information for
**                           Freescale 56800/E derivatives - eFlexPWM
**                           device ] 
**                           - _edge-aligned mode:_ value computed from
**                           parameter is written into PWM clear-edge
**                           (eFlexPWM_SMn_VALx) register; PWM set-edge
**                           (eFlexPWM_SMn_VALx) register is not
**                           affected (zero value assumed); where x = 2,
**                           4. 
**                           - _center-aligned mode:_ value computed
**                           from parameter value is split between PWM
**                           set-edge (eFlexPWM_SMn_VALx) and PWM
**                           clear-edge (eFlexPWM_SMn_VAL(x+1))
**                           registers; where x = 2, 4.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_NOTAVAIL - Channel is disabled
**                           ERR_RANGE - Parameter Channel is out of
**                           range
** ===================================================================
*/
byte PWMC1_SetRatio16(byte Channel,word Ratio)
{
  register word SetEdgeReg = (word)((((Int32)getReg16(PWM_SM0_VAL1) - (Int16)getReg16(PWM_SM0_INIT) + 0x01) * Ratio) / 0xFFFFU); /* Store value to the set duty register */
  register word ClearEdgeReg;          /* Store value to the clear duty register */

  if ((Ratio == 0xFFFFU) && ((SetEdgeReg == 0x00U) || (SetEdgeReg == 0xFFFFU))) { /* Is duty overflow? */
    ClearEdgeReg = 0x7FFFU;            /* Set maximal value */
    SetEdgeReg = 0x8000U;              /* Set minimum value */
  }
  else {
    ClearEdgeReg = (word)((word)(SetEdgeReg + 0x01U) >> 0x01U); /* Calculate value to clear */
    SetEdgeReg = (word)(-(SetEdgeReg >> 0x01U)); /* Calculate value to set */
  }
  switch (Channel) {
    case 0:
      setReg16(PWM_SM0_VAL2,SetEdgeReg); /* Store value to the set duty register of channel 0 */
      setReg16(PWM_SM0_VAL3,ClearEdgeReg); /* Store value to the clear duty register of channel 0 */
      break;
    case 1:
      setReg16(PWM_SM0_VAL4,SetEdgeReg); /* Store value to the set duty register of channel 1 */
      setReg16(PWM_SM0_VAL5,ClearEdgeReg); /* Store value to the clear duty register of channel 1 */
      break;
    case 2:
      setReg16(PWM_SM1_VAL2,SetEdgeReg); /* Store value to the set duty register of channel 2 */
      setReg16(PWM_SM1_VAL3,ClearEdgeReg); /* Store value to the clear duty register of channel 2 */
      break;
    case 3:
      setReg16(PWM_SM1_VAL4,SetEdgeReg); /* Store value to the set duty register of channel 3 */
      setReg16(PWM_SM1_VAL5,ClearEdgeReg); /* Store value to the clear duty register of channel 3 */
      break;
    case 4:
      setReg16(PWM_SM2_VAL2,SetEdgeReg); /* Store value to the set duty register of channel 4 */
      setReg16(PWM_SM2_VAL3,ClearEdgeReg); /* Store value to the clear duty register of channel 4 */
      break;
    case 5:
      setReg16(PWM_SM2_VAL4,SetEdgeReg); /* Store value to the set duty register of channel 5 */
      setReg16(PWM_SM2_VAL5,ClearEdgeReg); /* Store value to the clear duty register of channel 5 */
      break;
    default:
      return ERR_RANGE;
  }
  return ERR_OK;
}

/* END PWMC1. */

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
