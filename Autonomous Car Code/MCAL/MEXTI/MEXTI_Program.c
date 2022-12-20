/*
 * MEXTI_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: DELL
 */

#include "MEXTI_Interface.h"
#include "MEXTI_Config.h"

void(*Global_Pointer1)(void) = NULL;
void(*Global_Pointer2)(void) = NULL;

void MEXTII0_Init()
{
#if MEXTI_SENSE_CONTROL_STATE == MEXTI_LOW_LEVEL

	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);

#elif MEXTI_SENSE_CONTROL_STATE == MEXTI_ANY_LOGICAL_CHANGE

	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);

#elif MEXTI_SENSE_CONTROL_STATE == MEXTI_RISING_EDGE

	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);

#elif MEXTI_SENSE_CONTROL_STATE == MEXTI_FALLING_EDGE

	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);

#endif

	SET_BIT(GICR,6);
}

void MEXTII1_Init()
{
#if MEXTI_SENSE_CONTROL_STATE == MEXTI_LOW_LEVEL

	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);

#elif MEXTI_SENSE_CONTROL_STATE == MEXTI_ANY_LOGICAL_CHANGE

	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);

#elif MEXTI_SENSE_CONTROL_STATE == MEXTI_RISING_EDGE

	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);

#elif MEXTI_SENSE_CONTROL_STATE == MEXTI_FALLING_EDGE

	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);

#endif

	SET_BIT(GICR,7);
}

void MEXTII2_Init()
{

}

void MEXTI_Callback1(void(*ptr)(void))
{
	if(ptr != NULL)
	{
		Global_Pointer1 = ptr;
	}
}

void MEXTI_Callback2(void(*ptr)(void))
{
	if(ptr != NULL)
	{
		Global_Pointer2 = ptr;
	}
}


ISR(VECT_INT0)
{
	if(Global_Pointer1 != NULL)
	{
		Global_Pointer1();
	}
}

ISR(VECT_INT1)
{
	if(Global_Pointer2 != NULL)
	{
		Global_Pointer2();
	}
}
