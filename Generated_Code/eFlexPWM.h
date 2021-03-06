/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : eFlexPWM.h
**     Project     : exp-the-motor
**     Processor   : MC56F8257
**     Component   : Init_eFlexPWM
**     Version     : Component 01.000, Driver 01.00, CPU db: 3.00.239
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2021-03-27, 16:57, # CodeGen: 14
**     Abstract    :
**          This file implements the eFlexPWM (eFlexPWM) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : eFlexPWM
**          Device                                         : eFlexPWM
**          Settings                                       : 
**            Submodule 0                                  : Enabled
**              Submodule 0 device                         : eFlexPWM_SM0
**              Clock setting                              : 
**                PWM clock source                         : IP Bus clock
**                PWM generator clock                      : Enabled
**                PWM prescaler                            : 1
**                Module clock                             : 60 MHz
**                Init counter value                       : 35536
**                PWM value 0 - half cycle point           : 0
**                PWM value 1 - counter modulo             : 29999
**                Fractional circuit power up              : Disabled
**                Fractional value 1 circuit               : Disabled
**                Fractional value 1                       : 0
**                Dead time value 0                        : 0
**                Dead time value 1                        : 0
**                PWM frequency                            : 1.0000 kHz
**                PWM period                               : 1000.0000 us
**                PWM dead time 0                          : 0
**                PWM dead time 1                          : 0
**              Enabled in Wait mode                       : no
**              Enabled in Debug mode                      : no
**              Channel settings                           : 
**                Mode of PWM ch A and B                   : Independent
**                Complementary PWM source                 : PWM23
**                Double switching                         : Disabled
**                Channel A (PWM23)                        : 
**                  PWM function                           : 
**                    PWM value 2                          : 0
**                    Fractional value 2 and 3 circuit     : Disabled
**                    Fractional value 2                   : 0
**                    PWM value 3                          : 0
**                    Fractional value 3                   : 0
**                    SW output                            : Logic 0
**                    Deadtime source                      : Generated PWM
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Enabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**                Channel B (PWM45)                        : 
**                  PWM function                           : 
**                    PWM value 4                          : 0
**                    Fractional value 4 and 5 circuit     : Disabled
**                    Fractional value 4                   : 0
**                    PWM value 5                          : 0
**                    Fractional value 5                   : 0
**                    SW output                            : Logic 0
**                    Deadtime source                      : Generated PWM
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Enabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**                Channel X (PWM01)                        : 
**                  PWM function                           : 
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Disabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**              Output trigger settings                    : 
**                OUT_TRIG0 signal settings                : 
**                  Output trigger for Val 0               : Disabled
**                  Output trigger for Val 2               : Disabled
**                  Output trigger for Val 4               : Disabled
**                OUT_TRIG1 signal settings                : 
**                  Output trigger for Val 1               : Disabled
**                  Output trigger for Val 3               : Disabled
**                  Output trigger for Val 5               : Disabled
**              Reload settings                            : 
**                Reload source                            : Local reload signal
**                Reload frequency                         : 1
**                Half cycle reload                        : Disabled
**                Full cycle reload                        : Enabled
**                Load mode                                : Load at next PWM reload if LDOK is set
**              Force and initialization settings          : 
**                Initialization source                    : Local sync signal
**                Force initialization                     : Disabled
**                Force source                             : Local force signal
**                Init value ch A                          : Low
**                Init value ch B                          : Low
**                Init value ch X                          : Low
**            Submodule 1                                  : Enabled
**              Submodule 1 device                         : eFlexPWM_SM1
**              Clock setting                              : 
**                PWM clock source                         : Submodule 0's clock
**                PWM generator clock                      : Enabled
**                PWM prescaler                            : 1
**                Module clock                             : 60 MHz
**                Init counter value                       : 35536
**                PWM value 0 - half cycle point           : 0
**                PWM value 1 - counter modulo             : 29999
**                Fractional circuit power up              : Disabled
**                Fractional value 1 circuit               : Disabled
**                Fractional value 1                       : 0
**                Dead time value 0                        : 0
**                Dead time value 1                        : 0
**                PWM frequency                            : 1.0000 kHz
**                PWM period                               : 1000.0000 us
**                PWM dead time 0                          : 0
**                PWM dead time 1                          : 0
**              Enabled in Wait mode                       : no
**              Enabled in Debug mode                      : no
**              Channel settings                           : 
**                Mode of PWM ch A and B                   : Independent
**                Complementary PWM source                 : PWM23
**                Double switching                         : Disabled
**                Channel A (PWM23)                        : 
**                  PWM function                           : 
**                    PWM value 2                          : 0
**                    Fractional value 2 and 3 circuit     : Disabled
**                    Fractional value 2                   : 0
**                    PWM value 3                          : 0
**                    Fractional value 3                   : 0
**                    SW output                            : Logic 0
**                    Deadtime source                      : Generated PWM
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Enabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**                Channel B (PWM45)                        : 
**                  PWM function                           : 
**                    PWM value 4                          : 0
**                    Fractional value 4 and 5 circuit     : Disabled
**                    Fractional value 4                   : 0
**                    PWM value 5                          : 0
**                    Fractional value 5                   : 0
**                    SW output                            : Logic 0
**                    Deadtime source                      : Generated PWM
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Enabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**                Channel X (PWM01)                        : 
**                  PWM function                           : 
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Disabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**              Output trigger settings                    : 
**                OUT_TRIG0 signal settings                : 
**                  Output trigger for Val 0               : Disabled
**                  Output trigger for Val 2               : Disabled
**                  Output trigger for Val 4               : Disabled
**                OUT_TRIG1 signal settings                : 
**                  Output trigger for Val 1               : Disabled
**                  Output trigger for Val 3               : Disabled
**                  Output trigger for Val 5               : Disabled
**              Reload settings                            : 
**                Reload source                            : Master reload signal
**                Reload frequency                         : 1
**                Half cycle reload                        : Disabled
**                Full cycle reload                        : Enabled
**                Load mode                                : Load at next PWM reload if LDOK is set
**              Force and initialization settings          : 
**                Initialization source                    : Local sync signal
**                Force initialization                     : Disabled
**                Force source                             : Local force signal
**                Init value ch A                          : Low
**                Init value ch B                          : Low
**                Init value ch X                          : Low
**            Submodule 2                                  : Enabled
**              Submodule 2 device                         : eFlexPWM_SM2
**              Clock setting                              : 
**                PWM clock source                         : Submodule 0's clock
**                PWM generator clock                      : Enabled
**                PWM prescaler                            : 1
**                Module clock                             : 60 MHz
**                Init counter value                       : 35536
**                PWM value 0 - half cycle point           : 0
**                PWM value 1 - counter modulo             : 29999
**                Fractional circuit power up              : Disabled
**                Fractional value 1 circuit               : Disabled
**                Fractional value 1                       : 0
**                Dead time value 0                        : 0
**                Dead time value 1                        : 0
**                PWM frequency                            : 1.0000 kHz
**                PWM period                               : 1000.0000 us
**                PWM dead time 0                          : 0
**                PWM dead time 1                          : 0
**              Enabled in Wait mode                       : no
**              Enabled in Debug mode                      : no
**              Channel settings                           : 
**                Mode of PWM ch A and B                   : Independent
**                Complementary PWM source                 : PWM23
**                Double switching                         : Disabled
**                Channel A (PWM23)                        : 
**                  PWM function                           : 
**                    PWM value 2                          : 0
**                    Fractional value 2 and 3 circuit     : Disabled
**                    Fractional value 2                   : 0
**                    PWM value 3                          : 0
**                    Fractional value 3                   : 0
**                    SW output                            : Logic 0
**                    Deadtime source                      : Generated PWM
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Enabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**                Channel B (PWM45)                        : 
**                  PWM function                           : 
**                    PWM value 4                          : 0
**                    Fractional value 4 and 5 circuit     : Disabled
**                    Fractional value 4                   : 0
**                    PWM value 5                          : 0
**                    Fractional value 5                   : 0
**                    SW output                            : Logic 0
**                    Deadtime source                      : Generated PWM
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Enabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**                Channel X (PWM01)                        : 
**                  PWM function                           : 
**                    Output fault state                   : Forced to 0 prior to output polarity
**                    Output polarity                      : Not inverted
**                    Channel masked                       : no
**                    Channel output                       : Disabled
**                    Fault channel 0                      : 
**                      Disable by fault 0                 : no
**                      Disable by fault 1                 : no
**                      Disable by fault 2                 : no
**                      Disable by fault 3                 : no
**              Output trigger settings                    : 
**                OUT_TRIG0 signal settings                : 
**                  Output trigger for Val 0               : Disabled
**                  Output trigger for Val 2               : Disabled
**                  Output trigger for Val 4               : Disabled
**                OUT_TRIG1 signal settings                : 
**                  Output trigger for Val 1               : Disabled
**                  Output trigger for Val 3               : Disabled
**                  Output trigger for Val 5               : Disabled
**              Reload settings                            : 
**                Reload source                            : Master reload signal
**                Reload frequency                         : 1
**                Half cycle reload                        : Disabled
**                Full cycle reload                        : Enabled
**                Load mode                                : Load at next PWM reload if LDOK is set
**              Force and initialization settings          : 
**                Initialization source                    : Local sync signal
**                Force initialization                     : Disabled
**                Force source                             : Local force signal
**                Init value ch A                          : Low
**                Init value ch B                          : Low
**                Init value ch X                          : Low
**            Submodule 3                                  : Disabled
**            Fault channel 0 protection settings          : 
**              Common fault settings                      : 
**                Input filter                             : Disabled
**                Fault Glitch Stretch                     : Disabled
**              Fault 0                                    : 
**                Fault active level                       : Logic 0
**                Fault clearing mode                      : Automatic
**                Fault safety mode                        : Normal
**                Full cycle recovery                      : no
**              Fault 1                                    : 
**                Fault active level                       : Logic 0
**                Fault clearing mode                      : Automatic
**                Fault safety mode                        : Normal
**                Full cycle recovery                      : no
**              Fault 2                                    : 
**                Fault active level                       : Logic 0
**                Fault clearing mode                      : Automatic
**                Fault safety mode                        : Normal
**                Full cycle recovery                      : no
**              Fault 3                                    : 
**                Fault active level                       : Logic 0
**                Fault clearing mode                      : Automatic
**                Fault safety mode                        : Normal
**                Full cycle recovery                      : no
**          Pins                                           : 
**            SM0 pins                                     : Enabled
**              PWM/Input capture channels                 : 
**                Channel A                                : Enabled
**                  PWM/Input capture pin A                : GPIOE1_PWM0A
**                  PWM/Input capture pin A signal         : 
**                Channel B                                : Enabled
**                  PWM/Input capture pin B                : GPIOE0_PWM0B
**                  PWM/Input capture pin B signal         : 
**                Channel X                                : Disabled
**              External control A - EXTA                  : Disabled
**              External synchronization                   : Disabled
**            SM1 pins                                     : Enabled
**              PWM/Input capture channels                 : 
**                Channel A                                : Enabled
**                  PWM/Input capture pin A                : GPIOE3_PWM1A
**                  PWM/Input capture pin A signal         : 
**                Channel B                                : Enabled
**                  PWM/Input capture pin B                : GPIOE2_PWM1B
**                  PWM/Input capture pin B signal         : 
**                Channel X                                : Disabled
**              External control A - EXTA                  : Disabled
**              External synchronization                   : Disabled
**            SM2 pins                                     : Enabled
**              PWM/Input capture channels                 : 
**                Channel A                                : Enabled
**                  PWM/Input capture pin A                : GPIOE5_PWM2A_XB_IN3
**                  PWM/Input capture pin A signal         : 
**                Channel B                                : Enabled
**                  PWM/Input capture pin B                : GPIOE4_PWM2B_XB_IN2
**                  PWM/Input capture pin B signal         : 
**                Channel X                                : Disabled
**              External control A - EXTA                  : Disabled
**              External synchronization                   : Disabled
**            SM3 pins                                     : Disabled
**            PWM Faults                                   : 
**              Fault channel 0                            : 
**                Fault 0                                  : Disabled
**                Fault 1                                  : Disabled
**                Fault 2                                  : Disabled
**                Fault 3                                  : Disabled
**            External clock                               : 
**              External clock                             : Disabled
**              External clock frequency                   : 1
**            External force                               : Disabled
**          Interrupts/DMA                                 : 
**            SM0 Interrupts/DMA                           : Enabled
**              Compare interrupt                          : 
**                Interrupt                                : INT_PWM_SubModule0_Compare
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                Compare interrupt 0                      : Disabled
**                Compare interrupt 1                      : Disabled
**                Compare interrupt 2                      : Disabled
**                Compare interrupt 3                      : Disabled
**                Compare interrupt 4                      : Disabled
**                Compare interrupt 5                      : Disabled
**              Reload interrupt                           : 
**                Interrupt                                : INT_PWM_SubModule0_Reload
**                Interrupt priority                       : 1
**                ISR Name                                 : PWMC1_InterruptOnReload
**                Reload interrupt                         : Enabled
**              Reload error interrupt                     : 
**                Interrupt                                : INT_PWM_ReloadError
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                SM0 reload error interrupt               : Disabled
**            SM1 Interrupts/DMA                           : Enabled
**              Compare interrupt                          : 
**                Interrupt                                : INT_PWM_SubModule1_Compare
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                Compare interrupt 0                      : Disabled
**                Compare interrupt 1                      : Disabled
**                Compare interrupt 2                      : Disabled
**                Compare interrupt 3                      : Disabled
**                Compare interrupt 4                      : Disabled
**                Compare interrupt 5                      : Disabled
**              Reload interrupt                           : 
**                Interrupt                                : INT_PWM_SubModule1_Reload
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                Reload interrupt                         : Disabled
**              Reload error interrupt                     : 
**                Interrupt                                : INT_PWM_ReloadError
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                SM1 reload error interrupt               : Disabled
**            SM2 Interrupts/DMA                           : Enabled
**              Compare interrupt                          : 
**                Interrupt                                : INT_PWM_SubModule2_Compare
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                Compare interrupt 0                      : Disabled
**                Compare interrupt 1                      : Disabled
**                Compare interrupt 2                      : Disabled
**                Compare interrupt 3                      : Disabled
**                Compare interrupt 4                      : Disabled
**                Compare interrupt 5                      : Disabled
**              Reload interrupt                           : 
**                Interrupt                                : INT_PWM_SubModule2_Reload
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                Reload interrupt                         : Disabled
**              Reload error interrupt                     : 
**                Interrupt                                : INT_PWM_ReloadError
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                SM2 reload error interrupt               : Disabled
**            SM3 Interrupts/DMA                           : Enabled
**              Compare interrupt                          : 
**                Interrupt                                : INT_PWM_SubModule3_Compare
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                Compare interrupt 0                      : Disabled
**                Compare interrupt 1                      : Disabled
**                Compare interrupt 2                      : Disabled
**                Compare interrupt 3                      : Disabled
**                Compare interrupt 4                      : Disabled
**                Compare interrupt 5                      : Disabled
**              Capture interrupt                          : 
**                Interrupt                                : INT_PWM_SubModule3_InputCapture
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                Capture A 0 interrupt                    : Disabled
**                Capture A 1 interrupt                    : Disabled
**                Capture B 0 interrupt                    : Disabled
**                Capture B 1 interrupt                    : Disabled
**                Capture X 0 interrupt                    : Disabled
**                Capture X 1 interrupt                    : Disabled
**              Reload interrupt                           : 
**                Interrupt                                : INT_PWM_SubModule3_Reload
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                Reload interrupt                         : Disabled
**              Reload error interrupt                     : 
**                Interrupt                                : INT_PWM_ReloadError
**                Interrupt priority                       : medium priority
**                ISR Name                                 : 
**                SM3 reload error interrupt               : Disabled
**            Fault interrupt                              : 
**              Interrupt                                  : INT_PWM_Fault
**              Interrupt priority                         : 1
**              ISR Name                                   : PWMC1_InterruptOnFault
**              Channel 0 fault 0 interrupt                : Enabled
**              Channel 0 fault 1 interrupt                : Enabled
**              Channel 0 fault 2 interrupt                : Enabled
**              Channel 0 fault 3 interrupt                : Enabled
**          Initialization                                 : 
**            Load values after init into SM0              : yes
**            Load values after init into SM1              : yes
**            Load values after init into SM2              : yes
**            Load values after init into SM3              : no
**            Enable peripheral clock for SM0              : yes
**            Enable peripheral clock for SM1              : yes
**            Enable peripheral clock for SM2              : yes
**            Enable peripheral clock for SM3              : no
**            Fault channel 0 test                         : No simulated fault
**            Fault flag clearing                          : 
**              Fault channel 0 flag 0                     : Do not initialize
**              Fault channel 0 flag 1                     : Do not initialize
**              Fault channel 0 flag 2                     : Do not initialize
**              Fault channel 0 flag 3                     : Do not initialize
**            Monitor PLL mode                             : Do not monitor PLL
**            Call Init method                             : no
**     Contents    :
**         Init - void eFlexPWM_Init(void);
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
** @file eFlexPWM.h
** @version 01.00
** @brief
**          This file implements the eFlexPWM (eFlexPWM) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup eFlexPWM_module eFlexPWM module documentation
**  @{
*/         

#ifndef eFlexPWM_H_
#define eFlexPWM_H_

/* MODULE eFlexPWM. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

/* Peripheral base address parameter */
#define eFlexPWM_DEVICE eFlexPWM_BASE_PTR


/*
** ===================================================================
**     Method      :  eFlexPWM_Init (component Init_eFlexPWM)
**     Description :
**         This method initializes registers of the eFlexPWM module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void eFlexPWM_Init(void);
/*
** ===================================================================
** The interrupt service routine must be implemented by user in one
** of the user modules (see eFlexPWM.c file for more information).
** ===================================================================
*/
void PWMC1_InterruptOnReload(void);
/*
** ===================================================================
** The interrupt service routine must be implemented by user in one
** of the user modules (see eFlexPWM.c file for more information).
** ===================================================================
*/
void PWMC1_InterruptOnFault(void);


/* END eFlexPWM. */
#endif /* #ifndef __eFlexPWM_H_ */
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
