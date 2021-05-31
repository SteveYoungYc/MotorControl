/* ###################################################################
**     Filename    : main.c
**     Project     : exp-the-motor
**     Processor   : MC56F8257
**     Version     : Driver 01.16
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2021-03-22, 15:42, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.16
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
extern word a;

void main(void)
{
	
	TI1_Enable();
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

   for(;;) {
	   Bit1_SetVal();Bit2_SetVal();
	   FMSTR1_Poll();
//	   a=PESL(GPIOC,GPIO_READ_RAW_DATA,NULL);
//	   if(C3==1&&C4==1&&C6==0){PWMC1_SetRatio16(0,0);PWMC1_SetRatio16(2,0);PWMC1_SetRatio16(3,0);PWMC1_SetRatio16(5,0);PWMC1_SetRatio16(4,d);PWMC1_SetRatio16(1,d);}
//	   if(C3==1&&C4==0&&C6==0){PWMC1_SetRatio16(0,0);PWMC1_SetRatio16(3,0);PWMC1_SetRatio16(4,0);PWMC1_SetRatio16(5,0);PWMC1_SetRatio16(2,d);PWMC1_SetRatio16(1,d);}
//	   if(C3==1&&C4==0&&C6==1){PWMC1_SetRatio16(0,0);PWMC1_SetRatio16(1,0);PWMC1_SetRatio16(3,0);PWMC1_SetRatio16(4,0);PWMC1_SetRatio16(2,d);PWMC1_SetRatio16(5,d);}
//	   if(C3==0&&C4==0&&C6==1){PWMC1_SetRatio16(1,0);PWMC1_SetRatio16(2,0);PWMC1_SetRatio16(3,0);PWMC1_SetRatio16(4,0);PWMC1_SetRatio16(0,d);PWMC1_SetRatio16(5,d);}
//	   if(C3==0&&C4==1&&C6==1){PWMC1_SetRatio16(1,0);PWMC1_SetRatio16(2,0);PWMC1_SetRatio16(4,0);PWMC1_SetRatio16(5,0);PWMC1_SetRatio16(0,d);PWMC1_SetRatio16(3,d);}
//	   if(C3==0&&C4==1&&C6==0){PWMC1_SetRatio16(0,0);PWMC1_SetRatio16(1,0);PWMC1_SetRatio16(2,0);PWMC1_SetRatio16(5,0);PWMC1_SetRatio16(3,d);PWMC1_SetRatio16(4,d);}
  }
}

/* END main */
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
