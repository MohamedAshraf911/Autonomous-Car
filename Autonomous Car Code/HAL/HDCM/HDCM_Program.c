/*
 * HDCM_Program.c
 *
 * Created: 12/16/2022 2:27:33 PM
 *  Author: Hisham Elbadry
 */ 
#include "HDCM_Interface.h"
#include "util/delay.h"

void HDCM_Init(void)
{
	MDIO_SetPinDirection(EN_1,DCmotor_EN,PIN_OUTPUT);
	MDIO_SetPinDirection(EN_2,DCmotor_EN,PIN_OUTPUT);
	MDIO_SetPinDirection(A_1,DCmotor_PINs,PIN_OUTPUT);
	MDIO_SetPinDirection(A_2,DCmotor_PINs,PIN_OUTPUT);
	MDIO_SetPinDirection(A_3,DCmotor_PINs,PIN_OUTPUT);
	MDIO_SetPinDirection(A_4,DCmotor_PINs,PIN_OUTPUT);
	
	MDIO_SetPinValue(EN_1,DCmotor_EN,PIN_HIGH);
	MDIO_SetPinValue(EN_2,DCmotor_EN,PIN_HIGH);
	
}

void HDCM_Forward_M_Right(void)
{
	MDIO_SetPinValue(A_1,DCmotor_PINs,PIN_LOW);
	MDIO_SetPinValue(A_2,DCmotor_PINs,PIN_HIGH);
}
void HDCM_Backward_M_Right(void)
{
	MDIO_SetPinValue(A_2,DCmotor_PINs,PIN_LOW);
	MDIO_SetPinValue(A_1,DCmotor_PINs,PIN_HIGH);
}
void HDCM_Forward_M_Left(void)
{
	MDIO_SetPinValue(A_3,DCmotor_PINs,PIN_HIGH);
	MDIO_SetPinValue(A_4,DCmotor_PINs,PIN_LOW);
}
void HDCM_Backward_M_Left(void)
{
	MDIO_SetPinValue(A_4,DCmotor_PINs,PIN_HIGH);
	MDIO_SetPinValue(A_3,DCmotor_PINs,PIN_LOW);
}

void HDCM_Stop(void)
{
	MDIO_SetPinValue(A_1,DCmotor_PINs,PIN_LOW);
	MDIO_SetPinValue(A_2,DCmotor_PINs,PIN_LOW);
	MDIO_SetPinValue(A_3,DCmotor_PINs,PIN_LOW);
	MDIO_SetPinValue(A_4,DCmotor_PINs,PIN_LOW);
}

void HDCM_Forward(void)
{
	//HDCM_Stop();
	//_delay_ms(100);
	HDCM_Forward_M_Left();
	HDCM_Forward_M_Right();
}

void HDCM_Back(void)
{
	HDCM_Backward_M_Left();
	HDCM_Backward_M_Right();
}

void HDCM_Left(void)
{
	HDCM_Backward_M_Left();
	HDCM_Forward_M_Right();
}

void HDCM_Right(void)
{
	HDCM_Backward_M_Right();
	HDCM_Forward_M_Left();
}
