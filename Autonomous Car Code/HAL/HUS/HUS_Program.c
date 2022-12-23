/*
 * HSERVO_Programe.c
 *
 *  Created on: Dec 9, 2022
 *      Author: DELL
 */

#include "HUS_Interface.h"
#include "../HCLCD/HCLCD_Interface.h"
static u8 GLOB_Overflow_Counter = 0;
static u8 GLOB_Rising_Detect = 1;

static u16 GLOB_TCNT_NUM = 0;
u16 GLOB_On_Time = 0; 
u16 GLOB_DIS = 0;
	
void US_EXTI_RECEIVE()
{	
	if (GLOB_Rising_Detect == 1)
	{
		MDIO_SetPinValue(PIN2, MDIO_PORTC, PIN_HIGH);
		MTIMER0_SetPreload(0);
		MTIMER0_Init();
		GLOB_Overflow_Counter = 0;
		GLOB_Rising_Detect = 0;
	}
	else if(GLOB_Rising_Detect == 0)
	{
		GLOB_On_Time = (u16)TCNT0 + (256*((u16)GLOB_Overflow_Counter));
		MTIMER0_STOP();
		GLOB_DIS = GLOB_On_Time;
		MDIO_SetPinValue(PIN2, MDIO_PORTC, PIN_LOW);
		GLOB_Rising_Detect = 1;
	}
}

void US_OverFlow_Counter()
{
	GLOB_Overflow_Counter++;
}

void US_Trigger(void)
{
	MDIO_SetPinValue(PIN_TRIG,PORT_US,PIN_HIGH);
	_delay_us(15);
	MDIO_SetPinValue(PIN_TRIG,PORT_US,PIN_LOW);
}

void US_INIT()
{
	MDIO_SetPinDirection(PIN2, MDIO_PORTC, PIN_OUTPUT);
	MDIO_SetPinDirection(PIN_TRIG,PORT_US,PIN_OUTPUT);
	MDIO_SetPinDirection(PIN_ECHO,PORT_US,PIN_INPUT);
	_delay_ms(50);
	
	MEXTII0_Init();
	
	//US_Trigger();
	
	MEXTI_Callback1(US_EXTI_RECEIVE);
	MTIMER0_OVERFLOW_CALLBACK(US_OverFlow_Counter);
}








