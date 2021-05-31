/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.h
**     Project     : exp-the-motor
**     Processor   : MC56F8257
**     Component   : 56F8257
**     Version     : Component 01.014, Driver 02.10, CPU db: 3.00.239
**     Datasheet   : MC56F824x/5xPB Rev. 1.0.0, 09/2008; MC56F82XXRM Rev. 0 Draft A 11/2008
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2021-05-31, 16:21, # CodeGen: 57
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetWaitMode - void Cpu_SetWaitMode(void);
**         SetStopMode - void Cpu_SetStopMode(void);
**
**     (c) Freescale Semiconductor, Inc.
**     2004 All Rights Reserved
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
** @file Cpu.h
** @version 02.10
** @brief
**
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

#ifndef __Cpu_H
#define __Cpu_H

/* MODULE Cpu. */

/* Active PE project configuration */
#define PEcfg_MC56F8257_Internal_PFlash_SDM 1

/* Active CPU bean */
#define PE_CPU_TYPE_56F8257

/* Active CPU variant */
#define PE_CPU_VARIANT_MC56F8257

/* Active CPU family */
#define PE_CPU_FAMILY_56800

/* Active CPU subfamily */
#define PE_CPU_SUBFAMILY_56F82xx

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PESL.h"
#include "assert.h"

#ifndef __BWUserType_TShadowRegs
#define __BWUserType_TShadowRegs
  typedef struct {                     /* Shadow register type. */
    word* R0;                          /* Shadow register R0. */
    word* R1;                          /* Shadow register R1. */
    int16_t N;                         /* Shadow register N. */
    int16_t M01;                       /* Shadow register M01. */
  } TShadowRegs;
#endif

/*lint -esym(765,SR_reg,SR_lock,_EntryPoint,_vect,_vectboot) Disable MISRA rule (8.10) checking for symbols (SR_reg,SR_lock,_EntryPoint,_vect,_vectboot). */
/* Global variables */
extern volatile word SR_lock;          /* Lock */
extern volatile word SR_reg;           /* Current value of the SR register */

#define   Cpu_SetStopMode()  asm(STOP) /* Set STOP mode */
/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component 56F8257)
**     Description :
**         Sets low power mode - Stop mode.
**         For more information about the stop mode see this CPU
**         documentation.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define   Cpu_SetWaitMode()  asm(WAIT) /* Set WAIT mode */
/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (component 56F8257)
**     Description :
**         Sets low power mode - Wait mode.
**         For more information about the wait mode see this CPU
**         documentation.
**         Release from wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



#define   Cpu_DisableInt()  __DI()     /* Disable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component 56F8257)
**     Description :
**         Disables all maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define   Cpu_EnableInt()  __EI(0)     /* Enable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component 56F8257)
**     Description :
**         Enables all maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Cpu__ivINT_TMRA1(void);
/*
** ===================================================================
**     Method      :  Cpu__ivINT_TMRA1 (component 56F8257)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void Cpu__ivINT_TMRA0(void);
/*
** ===================================================================
**     Method      :  Cpu__ivINT_TMRA0 (component 56F8257)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void PE_low_level_init(void);
/*
** ===================================================================
**     Method      :  PE_low_level_init (component 56F8257)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cpu_Interrupt(void);
/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component 56F8257)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


void _EntryPoint(void);
/*
** ===================================================================
**     Method      :  _EntryPoint (component 56F8257)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Cpu. */

#endif
/* __Cpu_H */

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
