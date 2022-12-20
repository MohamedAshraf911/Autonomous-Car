/*
 * HSERVO_Programe.c
 *
 *  Created on: Dec 9, 2022
 *      Author: DELL
 */

#include "HSERVO_Interface.h"
#include "HSERVO_Private.h"

void TIMER1_VidInit(void)
{
	/*Set Fast pwm mode with top-->ICR1*/
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);

	/*Set non-inverting Fast pwm channel A*/
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	/*Set Prescaler-->>64 Prescaler*/
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}


void TIMER1_SetTopValue(u16 Copy_u16TopValue)
{
	ICR1=Copy_u16TopValue;
}

void TIMER1_Set_OCR1A_Value(u16 Copy_u16CTCValue)
{
	OCR1A=Copy_u16CTCValue;
}

void HSERVO_Init(void)
{
	TIMER1_SetTopValue(5000);
	TIMER1_VidInit();
	MDIO_SetPinDirection(PIN5,MDIO_PORTD,PIN_OUTPUT);
}



void HSERVO_Rotate(void)
{
	TIMER1_Set_OCR1A_Value(135); // RIGHT
	_delay_ms(1000);
	TIMER1_Set_OCR1A_Value(385); //MIDDLE
	_delay_ms(1000);
	TIMER1_Set_OCR1A_Value(635); // LEFT
	_delay_ms(1000);
	TIMER1_Set_OCR1A_Value(385); // MIDDLE
	_delay_ms(1000);
}

void HSERVO_Rotate_Middle(void)
{
	TIMER1_Set_OCR1A_Value(385);
}

void HSERVO_Rotate_Right(void)
{
	TIMER1_Set_OCR1A_Value(135);
}

void HSERVO_Rotate_Left(void)
{
	TIMER1_Set_OCR1A_Value(635);
}









