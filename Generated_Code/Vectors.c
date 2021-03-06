/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Vectors.c
**     Project     : exp-the-motor
**     Processor   : MC56F8257
**     Version     : Component 01.014, Driver 02.10, CPU db: 3.00.239
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2021-05-31, 16:21, # CodeGen: 57
**     Abstract    :
**
**     Settings    :
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
/*!
** @file Vectors.c                                                  
** @version 02.10
** @brief
**
*/         
/*!
**  @addtogroup Vectors_module Vectors module documentation
**  @{
*/         

#include "Cpu.h"
#include "Bit1.h"
#include "Bit2.h"
#include "TI1.h"
#include "eFlexPWM.h"
#include "Cap1.h"
#include "Cap2.h"
#include "PWMC1.h"
#include "Cap3.h"
#include "FMSTR1.h"
#include "QSCI0.h"
#include "TI2.h"
#include "Events.h"

#ifndef _lint

extern void _EntryPoint(void);         /* Startup routine */

volatile asm void _vectboot(void);
#pragma define_section interrupt_vectorsboot "interrupt_vectorsboot.text"  RX
#pragma section interrupt_vectorsboot begin
volatile asm void _vectboot(void) {
  JMP  _EntryPoint                     /* Reset vector (Used) */
  JMP  _EntryPoint                     /* COP reset vector (Used) */
}
#pragma section interrupt_vectorsboot end

volatile asm void _vect(void);
#pragma define_section interrupt_vectors "interrupt_vectors.text"  RX
#pragma section interrupt_vectors begin
volatile asm void _vect(void) {
  JMP  _EntryPoint                     /* Interrupt no. 0 (Used)   - ivINT_Reset */
  JMP  _EntryPoint                     /* Interrupt no. 1 (Used)   - ivINT_COPReset  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 2 (Unused) - ivINT_Illegal_Instruction  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 3 (Unused) - ivINT_SW3  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 4 (Unused) - ivINT_HWStackOverflow  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 5 (Unused) - ivINT_MisalignedLongWordAccess  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 6 (Unused) - ivINT_OnCE_StepCounter  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 7 (Unused) - ivINT_OnCE_BreakpointUnit  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 8 (Unused) - ivINT_OnCE_TraceBuffer  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 9 (Unused) - ivINT_OnCE_TxREmpty  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 10 (Unused) - ivINT_OnCE_RxRFull  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 11 (Unused) - ivINT_SW2  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 12 (Unused) - ivINT_SW1  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 13 (Unused) - ivINT_SW0  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 14 (Unused) - ivINT_LVI  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 15 (Unused) - ivINT_PLL  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 16 (Unused) - ivINT_TMRB3  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 17 (Unused) - ivINT_TMRB2  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 18 (Unused) - ivINT_TMRB1  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 19 (Unused) - ivINT_TMRB0  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 20 (Unused) - ivINT_ADCB_Complete  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 21 (Unused) - ivINT_ADCA_Complete  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 22 (Unused) - ivINT_ADC_ZC_LE  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 23 (Unused) - ivINT_MSCAN_Tx  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 24 (Unused) - ivINT_MSCAN_Rx  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 25 (Unused) - ivINT_MSCAN_Error  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 26 (Unused) - ivINT_MSCAN_WakeUp  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 27 (Unused) - ivINT_QSCI1_RxError  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 28 (Unused) - ivINT_QSCI1_RxFull  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 29 (Unused) - ivINT_QSCI1_TxIdle  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 30 (Unused) - ivINT_QSCI1_TxEmpty  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 31 (Unused) - ivINT_QSCI0_RxError  */
  JSR  FMSTR1_Isr                      /* Interrupt no. 32 (Used)   - ivINT_QSCI0_RxFull  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 33 (Unused) - ivINT_QSCI0_TxIdle  */
  JSR  FMSTR1_Isr                      /* Interrupt no. 34 (Used)   - ivINT_QSCI0_TxEmpty  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 35 (Unused) - ivINT_SPI_TxEmpty  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 36 (Unused) - ivINT_SPI_RxFull  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 37 (Unused) - ivINT_I2C1  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 38 (Unused) - ivINT_I2C0  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 39 (Unused) - ivINT_TMRA3  */
  JSR  Cap3_Interrupt                  /* Interrupt no. 40 (Used)   - ivINT_TMRA2  */
  JSR  Cpu__ivINT_TMRA1                /* Interrupt no. 41 (Used)   - ivINT_TMRA1  */
  JSR  Cpu__ivINT_TMRA0                /* Interrupt no. 42 (Used)   - ivINT_TMRA0  */
  JSR  PWMC1_InterruptOnFault          /* Interrupt no. 43 (Used)   - ivINT_PWM_Fault  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 44 (Unused) - ivINT_PWM_ReloadError  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 45 (Unused) - ivINT_PWM_SubModule3_Reload  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 46 (Unused) - ivINT_PWM_SubModule3_InputCapture  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 47 (Unused) - ivINT_PWM_SubModule3_Compare  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 48 (Unused) - ivINT_PWM_SubModule2_Reload  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 49 (Unused) - ivINT_PWM_SubModule2_Compare  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 50 (Unused) - ivINT_PWM_SubModule1_Reload  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 51 (Unused) - ivINT_PWM_SubModule1_Compare  */
  JSR  PWMC1_InterruptOnReload         /* Interrupt no. 52 (Used)   - ivINT_PWM_SubModule0_Reload  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 53 (Unused) - ivINT_PWM_SubModule0_Compare  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 54 (Unused) - ivINT_HFM_ERR  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 55 (Unused) - ivINT_HFM_CC  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 56 (Unused) - ivINT_HFM_CBE  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 57 (Unused) - ivINT_CMPC_Rising_Falling  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 58 (Unused) - ivINT_CMPB_Rising_Falling  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 59 (Unused) - ivINT_CMPA_Rising_Falling  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 60 (Unused) - ivINT_GPIO_F  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 61 (Unused) - ivINT_GPIO_E  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 62 (Unused) - ivINT_GPIO_D  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 63 (Unused) - ivINT_GPIO_C  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 64 (Unused) - ivINT_GPIO_B  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 65 (Unused) - ivINT_GPIO_A  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 66 (Unused) - ivINT_LP  */
}
#pragma section interrupt_vectors end

#endif _lint

/* Disable MISRA rules for interurupt routines */
/*lint -esym(765,Cpu_Interrupt) Disable MISRA rule (8.10) checking for symbols (Cpu_Interrupt). */
/*lint -esym(765,FMSTR1_Isr) Disable MISRA rule (8.10) checking for symbols (FMSTR1_Isr). */
/*lint -esym(765,Cap3_Interrupt) Disable MISRA rule (8.10) checking for symbols (Cap3_Interrupt). */
/*lint -esym(765,Cpu__ivINT_TMRA1) Disable MISRA rule (8.10) checking for symbols (Cpu__ivINT_TMRA1). */
/*lint -esym(765,Cpu__ivINT_TMRA0) Disable MISRA rule (8.10) checking for symbols (Cpu__ivINT_TMRA0). */
/*lint -esym(765,PWMC1_InterruptOnFault) Disable MISRA rule (8.10) checking for symbols (PWMC1_InterruptOnFault). */
/*lint -esym(765,PWMC1_InterruptOnReload) Disable MISRA rule (8.10) checking for symbols (PWMC1_InterruptOnReload). */

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
