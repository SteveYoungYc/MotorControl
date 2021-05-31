/* ###################################################################
**     Filename    : Events.h
**     Project     : exp-the-motor
**     Processor   : MC56F8257
**     Component   : Events
**     Version     : Driver 01.03
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2021-03-22, 15:42, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.03
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Bit1.h"
#include "Bit2.h"
#include "TI1.h"
#include "PWMC1.h"
#include "eFlexPWM.h"
#include "Cap1.h"
#include "Cap2.h"
#include "Cap3.h"
#include "FMSTR1.h"
#include "QSCI0.h"
#include "TI2.h"


void TI1_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Cap1_OnCapture(void);
/*
** ===================================================================
**     Event       :  Cap1_OnCapture (module Events)
**
**     Component   :  Cap1 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void PWMC1_OnReload(void);
/*
** ===================================================================
**     Event       :  PWMC1_OnReload (module Events)
**
**     Component   :  PWMC1 [PWMMC]
**     Description :
**         This event is called before PWM cycle according to reload
**         frequency. The event is invoked only when the component is
**         enabled - <Enable> and the events are enabled - <EnableEvent>.
**         This event is enabled only if <Interrupt service/event> is
**         enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void PWMC1_OnFault0(void);
/*
** ===================================================================
**     Event       :  PWMC1_OnFault0 (module Events)
**
**     Component   :  PWMC1 [PWMMC]
**     Description :
**         This event is called when fault 0 occurs. Only when the
**         component is enabled - <Enable> and the events are enabled -
**         <EnableEvent>. This event is enabled only if <Interrupt
**         service/event> is enabled and property <Fault protection> is
**         set to controlled by this component. The event clears Fault
**         flag only when the Fault is set to the automatic clearing
**         mode. When the Fault is set to the manual clearing mode, the
**         Fault flag must be cleared by the user using ClearFaultFlag()
**         method.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void PWMC1_OnFault1(void);
/*
** ===================================================================
**     Event       :  PWMC1_OnFault1 (module Events)
**
**     Component   :  PWMC1 [PWMMC]
**     Description :
**         This event is called when fault 1 occurs. (Only when the
**         component is enabled - <Enable> and the events are enabled -
**         <EnableEvent>). This event is enabled only if interrupt
**         service/event is enabled and property FaultProtection is set
**         to controlled by this component. The event clears Fault flag
**         only when the Fault is set to the automatic clearing mode.
**         When the Fault is set to the manual clearing mode, the Fault
**         flag must be cleared by the user using ClearFaultFlag()
**         method.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void PWMC1_OnFault2(void);
/*
** ===================================================================
**     Event       :  PWMC1_OnFault2 (module Events)
**
**     Component   :  PWMC1 [PWMMC]
**     Description :
**         This event is called when fault 2 occurs. (Only when the
**         component is enabled - <Enable> and the events are enabled -
**         <EnableEvent>). This event is enabled only if interrupt
**         service/event is enabled and property FaultProtection is set
**         to controlled by this component. The event clears Fault flag
**         only when the Fault is set to the automatic clearing mode.
**         When the Fault is set to the manual clearing mode, the Fault
**         flag must be cleared by the user using ClearFaultFlag()
**         method.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void PWMC1_OnFault3(void);
/*
** ===================================================================
**     Event       :  PWMC1_OnFault3 (module Events)
**
**     Component   :  PWMC1 [PWMMC]
**     Description :
**         This event is called when fault 3 occurs. (Only when the
**         component is enabled - <Enable> and the events are enabled -
**         <EnableEvent>). This event is enabled only if interrupt
**         service/event is enabled and property FaultProtection is set
**         to controlled by this component. The event clears Fault flag
**         only when the Fault is set to the automatic clearing mode.
**         When the Fault is set to the manual clearing mode, the Fault
**         flag must be cleared by the user using ClearFaultFlag()
**         method.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Cap3_OnCapture(void);
/*
** ===================================================================
**     Event       :  Cap3_OnCapture (module Events)
**
**     Component   :  Cap3 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Cap2_OnCapture(void);
/*
** ===================================================================
**     Event       :  Cap2_OnCapture (module Events)
**
**     Component   :  Cap2 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Cap3_OnOverflow(void);
/*
** ===================================================================
**     Event       :  Cap3_OnOverflow (module Events)
**
**     Component   :  Cap3 [Capture]
**     Description :
**         This event is called if counter overflows (only when the
**         component is enabled - <Enable> and the events are enabled -
**         <EnableEvent>.This event is available only if a <interrupt
**         service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TI2_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  TI2_OnInterrupt (module Events)
**
**     Component   :  TI2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

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
