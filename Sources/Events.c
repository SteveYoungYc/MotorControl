/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.03
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "PID.h"
#include <stdio.h>
#include <math.h>

/* User includes (#include below this line is not maintained by Processor Expert) */

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
word a;
int time, x = 0, o = 3000, f;
long int d = 10000, D = 52428;
int C3, C4, C6;

//things for overflowtime
int overflowtime = 0;
int time = 0;

unsigned int rreaderhelper;
int index;
unsigned int count[3];
int e = 0, y = 0;
float n, T, nSet = 2000, nRecord[2];
PID_IncTypeDef PID;
float speed[3] = {0.0f, 1000.0f, 2000.0f};
int speedCount = 0;

void TI1_OnInterrupt(void)
{

	f = 0;
	a = PESL(GPIOC, GPIO_READ_RAW_DATA, NULL);
	C3 = (int)((a & 0b0000000000001000) >> 3);
	C4 = (int)((a & 0b0000000000010000) >> 4);
	C6 = (int)((a & 0b0000000001000000) >> 6);

	if (C3 == 1 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(3, D);
		PWMC1_SetRatio16(4, d);
	}
	if (C3 == 1 && C4 == 0 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(4, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 1 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 0 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 1)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(3, D);
	}
	PWMC1_Load();

	//		if(x>=10000){d=d+3300;}
	//        x=x+1;
	//		if(d>=20000){d=20000;}

	//	//test
	//	a=PESL(GPIOC,GPIO_READ_RAW_DATA,NULL);
	//	C3=(int)((a&0b0000000000001000)>>3);
	//	C4=(int)((a&0b0000000000010000)>>4);
	//	C6=(int)((a&0b0000000001000000)>>6);
	if (C3 == 1 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(3, d);
		PWMC1_SetRatio16(4, d);
	}
	PWMC1_Load();
	d = d + 3300;
	if (d >= 20000)
		d = 20000;
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
word a;
int f;
//long int d;
int C3, C4, C6;

void Cap1_OnCapture(void)
{
	f = 1;
	TI1_Disable();

	a = PESL(GPIOC, GPIO_READ_RAW_DATA, NULL);
	C3 = (int)((a & 0b0000000000001000) >> 3);
	C4 = (int)((a & 0b0000000000010000) >> 4);
	C6 = (int)((a & 0b0000000001000000) >> 6);
	if (C3 == 1 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(3, D);
		PWMC1_SetRatio16(4, d);
	}
	if (C3 == 1 && C4 == 0 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(4, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 1 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 0 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 1)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(3, D);
	}
	PWMC1_Load();
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void PWMC1_OnReload(void)
{
	/* Write your code here ... */
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void PWMC1_OnFault0(void)
{
	/* Write your code here ... */
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void PWMC1_OnFault1(void)
{
	/* Write your code here ... */
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void PWMC1_OnFault2(void)
{
	/* Write your code here ... */
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void PWMC1_OnFault3(void)
{
	/* Write your code here ... */
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called

void Cap3_OnCapture(void)
{
	f = 1;
	TI1_Disable();

	a = PESL(GPIOC, GPIO_READ_RAW_DATA, NULL);
	C3 = (int)((a & 0b0000000000001000) >> 3);
	C4 = (int)((a & 0b0000000000010000) >> 4);
	C6 = (int)((a & 0b0000000001000000) >> 6);
	if (C3 == 1 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(3, D);
		PWMC1_SetRatio16(4, d);
	}
	if (C3 == 1 && C4 == 0 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(4, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 1 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 0 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 1)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(3, D);
	}
	PWMC1_Load();

	//things for rad reading
	count[0] = count[1];
	count[1] = count[2];
	Cap3_GetCaptureValue(&rreaderhelper);
	count[2] = rreaderhelper;
	index++;

	T = count[2] * 139.810 / 1000 / 65536 - count[0] * 139.810 / 1000 / 65536 + overflowtime * 139.810 / 1000; //
	//if(T<0){T = T + 0.13981;}
	n = fabs(60 / T / 2);

	nRecord[0] = nRecord[1];
	nRecord[1] = n;

	if (nSet != 0)
	{
		if (fabs(nRecord[1] - nSet) > 0.7 * nSet)
		{
			nRecord[1] = nRecord[0];
		}
		n = nRecord[1];
	}
	else
	{
		
	}
	

	if (index == 3)
	{
		index = 0;
		overflowtime = 0;
	}

	PID.P = 10.0f;
	PID.I = 1.0f;
	PID.D = 5.0f;
	PID.OutputMax = 40000;
	PID.OutputMin = 10;
	PID.IntegralMax = 20000;
	//d += PID_Inc(nSet, n, &PID);
	d = PID_Cal(&PID, n, nSet);
	//	if(C3==0&&C4==1&&C6==1){y=y+1;Cap3_GetCaptureValue(&rreaderhelper);count[0]=rreaderhelper;}
	//	if(y>=1){y=0;Cap3_GetCaptureValue(&rreaderhelper);
	//		count[1]=rreaderhelper;
	//		n=1/((count[1]-count[0])*139.810/65536+overflowtime*139.810)/2;
	//		overflowtime=0;}
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void Cap2_OnCapture(void)
{
	f = 1;
	TI1_Disable();

	a = PESL(GPIOC, GPIO_READ_RAW_DATA, NULL);
	C3 = (int)((a & 0b0000000000001000) >> 3);
	C4 = (int)((a & 0b0000000000010000) >> 4);
	C6 = (int)((a & 0b0000000001000000) >> 6);
	if (C3 == 1 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(3, D);
		PWMC1_SetRatio16(4, d);
	}
	if (C3 == 1 && C4 == 0 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(4, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 1 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 0 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 1)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(3, D);
	}
	PWMC1_Load();
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void Cap3_OnOverflow(void)
{
	overflowtime = overflowtime + 1;

	f = 1;
	TI1_Disable();

	a = PESL(GPIOC, GPIO_READ_RAW_DATA, NULL);
	C3 = (int)((a & 0b0000000000001000) >> 3);
	C4 = (int)((a & 0b0000000000010000) >> 4);
	C6 = (int)((a & 0b0000000001000000) >> 6);
	if (C3 == 1 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(3, D);
		PWMC1_SetRatio16(4, d);
	}
	if (C3 == 1 && C4 == 0 && C6 == 0)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(4, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 1 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(1, D);
	}
	if (C3 == 0 && C4 == 0 && C6 == 1)
	{
		PWMC1_SetRatio16(0, 0);
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(2, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 1)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(3, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(5, D);
	}
	if (C3 == 0 && C4 == 1 && C6 == 0)
	{
		PWMC1_SetRatio16(1, 0);
		PWMC1_SetRatio16(2, 0);
		PWMC1_SetRatio16(4, 0);
		PWMC1_SetRatio16(5, 0);
		PWMC1_SetRatio16(0, d);
		PWMC1_SetRatio16(3, D);
	}
	PWMC1_Load();
}

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
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void TI2_OnInterrupt(void)
{
	/* Write your code here ... */
	time = (time + 1) % 2000;
	if (time == 0)
	{
		speedCount = (speedCount + 1) % 3;
		nSet = speed[speedCount];
	}
}

/* END Events */

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
