/*
 * HSEVEN_SEG_Program.c
 *
 *  Created on: Sep 30, 2022
 *      Author: DELL
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "HSEVEN_SEG_Interface.h"

void HSEVEN_SEG_Init(SevenSeg_t* Ptr_SevenSegObj)
{
	//Set Pins output
	MDIO_SetPinDirection(Ptr_SevenSegObj->PinEn,Ptr_SevenSegObj->PinEnPort,PIN_OUTPUT);
	MDIO_SetPinDirection(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_OUTPUT);
	MDIO_SetPinDirection(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_OUTPUT);
	MDIO_SetPinDirection(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_OUTPUT);
	MDIO_SetPinDirection(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_OUTPUT);
}

void HSEVEN_SEG_SetMode(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegMode)
{
	if(Copy_u8SevenSegMode == SEVEN_SEG_ON)
	{
		MDIO_SetPinValue(Ptr_SevenSegObj->PinEn,Ptr_SevenSegObj->PinEnPort,PIN_HIGH);
	}
	else if(Copy_u8SevenSegMode == SEVEN_SEG_OFF)
	{
		MDIO_SetPinValue(Ptr_SevenSegObj->PinEn,Ptr_SevenSegObj->PinEnPort,PIN_LOW);
	}
	else
	{
		//wrong mode ordered
	}
}

void HSEVEN_SEG_Display(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegValue)
{
	if((Copy_u8SevenSegValue >= 0)&&(Copy_u8SevenSegValue<10))
	{
		switch(Copy_u8SevenSegValue)
		{
		case 0:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_LOW);
			break;
		case 1:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_LOW);
			break;
		case 2:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_LOW);
			break;
		case 3:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_LOW);
			break;
		case 4:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_LOW);
			break;
		case 5:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_LOW);
			break;
		case 6:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_LOW);
			break;
		case 7:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_LOW);
			break;
		case 8:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_HIGH);
			break;
		case 9:
			MDIO_SetPinValue(Ptr_SevenSegObj->PinA,Ptr_SevenSegObj->PinAPort,PIN_HIGH);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinB,Ptr_SevenSegObj->PinBPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinC,Ptr_SevenSegObj->PinCPort,PIN_LOW);
			MDIO_SetPinValue(Ptr_SevenSegObj->PinD,Ptr_SevenSegObj->PinDPort,PIN_HIGH);
			break;
		default:
			break;
		}
	}
	else
	{
		//Wrong seven segment value
	}
}
