/*
 * MDIO_Program.c
 *
 *  Created on: Sep 24, 2022
 *      Author: DELL
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "MDIO_Interface.h"
#include "MDIO_Private.h"

void MDIO_SetPortDirection(u8 Copy_u8PortNumber, u8 Copy_u8PortDirection)
{
	if((Copy_u8PortDirection == PORT_OUTPUT)||(Copy_u8PortDirection == PORT_INPUT))
	{
		//VALID PORT DIRECTION GIVEN
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA :
			DDRA = Copy_u8PortDirection;
			break;
		case MDIO_PORTB :
			DDRB = Copy_u8PortDirection;
			break;
		case MDIO_PORTC :
			DDRC = Copy_u8PortDirection;
			break;
		case MDIO_PORTD :
			DDRD = Copy_u8PortDirection;
			break;
		default :
			break;
		}
	}
	else
	{
		//Invalid Port direction given
	}
}

void MDIO_SetPinDirection(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 Copy_u8PinDirection)
{
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			if(Copy_u8PinDirection == PIN_OUTPUT)
			{
				SET_BIT(DDRA,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection == PIN_INPUT)
			{
				CLR_BIT(DDRA,Copy_u8PinNumber);
			}
			else
			{
				//invalid pin direction
			}
			break;
		case MDIO_PORTB:
			if(Copy_u8PinDirection == PIN_OUTPUT)
			{
				SET_BIT(DDRB,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection == PIN_INPUT)
			{
				CLR_BIT(DDRB,Copy_u8PinNumber);
			}
			else
			{
				//invalid pin direction
			}
			break;
		case MDIO_PORTC:
			if(Copy_u8PinDirection == PIN_OUTPUT)
			{
				SET_BIT(DDRC,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection == PIN_INPUT)
			{
				CLR_BIT(DDRC,Copy_u8PinNumber);
			}
			else
			{
				//invalid pin direction
			}
			break;
		case MDIO_PORTD:
			if(Copy_u8PinDirection == PIN_OUTPUT)
			{
				SET_BIT(DDRD,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection == PIN_INPUT)
			{
				CLR_BIT(DDRD,Copy_u8PinNumber);
			}
			else
			{
				//invalid pin direction
			}
			break;
		default :
			break;
		}
	}
	else
	{
		//wrong pin number
	}
}

void MDIO_SetPortValue(u8 Copy_u8PortNumber, u8 Copy_u8PortValue)
{
	if((Copy_u8PortValue <= PORT_HIGH)&&(Copy_u8PortValue >= PORT_LOW))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA :
			PORTA = Copy_u8PortValue;
			break;
		case MDIO_PORTB :
			PORTB = Copy_u8PortValue;
			break;
		case MDIO_PORTC :
			PORTC = Copy_u8PortValue;
			break;
		case MDIO_PORTD :
			PORTD = Copy_u8PortValue;
			break;
		default :
			break;
		}
	}
	else
	{
		//Invalid Port value
	}
}

void MDIO_SetPinValue(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 Copy_u8PinValue)
{
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			if(Copy_u8PinValue == PIN_HIGH)
			{
				SET_BIT(PORTA,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue == PIN_LOW)
			{
				CLR_BIT(PORTA,Copy_u8PinNumber);
			}
			else
			{
				//invalid pin direction
			}
			break;
		case MDIO_PORTB:
			if(Copy_u8PinValue == PIN_HIGH)
			{
				SET_BIT(PORTB,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue == PIN_LOW)
			{
				CLR_BIT(PORTB,Copy_u8PinNumber);
			}
			else
			{
				//invalid pin direction
			}
			break;
		case MDIO_PORTC:
			if(Copy_u8PinValue == PIN_HIGH)
			{
				SET_BIT(PORTC,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue == PIN_LOW)
			{
				CLR_BIT(PORTC,Copy_u8PinNumber);
			}
			else
			{
				//invalid pin direction
			}
			break;
		case MDIO_PORTD:
			if(Copy_u8PinValue == PIN_HIGH)
			{
				SET_BIT(PORTD,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue == PIN_LOW)
			{
				CLR_BIT(PORTD,Copy_u8PinNumber);
			}
			else
			{
				//invalid pin direction
			}
			break;
		}
	}
	else
	{
		//Invalid pin number
	}
}

void MDIO_ReadPortValue(u8 Copy_u8PortNumber, u8 * P_u8PortReading)
{
	if(P_u8PortReading != NULL)
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			*P_u8PortReading = PINA;
			break;
		case MDIO_PORTB:
			*P_u8PortReading = PINB;
			break;
		case MDIO_PORTC:
			*P_u8PortReading = PINC;
			break;
		case MDIO_PORTD:
			*P_u8PortReading = PIND;
			break;
		default :
			break;
		}
	}
	else
	{
		//Invalid address
	}
}

void MDIO_ReadPinValue(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 * P_u8PinReading)
{
	if(P_u8PinReading != NULL)
	{
		if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
		{
			switch(Copy_u8PortNumber)
			{
			case MDIO_PORTA :
				*P_u8PinReading = GET_BIT(PINA,Copy_u8PinNumber);
				break;
			case MDIO_PORTB :
				*P_u8PinReading = GET_BIT(PINB,Copy_u8PinNumber);
				break;
			case MDIO_PORTC :
				*P_u8PinReading = GET_BIT(PINC,Copy_u8PinNumber);
				break;
			case MDIO_PORTD :
				*P_u8PinReading = GET_BIT(PIND,Copy_u8PinNumber);
				break;
			default :
				break;
			}
		}
		else
		{
			//Invalid pin number
		}
	}
	else
	{
		//Invalid Address
	}
}

void MDIO_TogglePin(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber)
{
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA :
			TOGGLE_BIT(PORTA,Copy_u8PinNumber);
			break;
		case MDIO_PORTB :
			TOGGLE_BIT(PORTB,Copy_u8PinNumber);
			break;
		case MDIO_PORTC :
			TOGGLE_BIT(PORTC,Copy_u8PinNumber);
			break;
		case MDIO_PORTD :
			TOGGLE_BIT(PORTD,Copy_u8PinNumber);
			break;
		default :
			break;
		}
	}
	else
	{
		//Invalid pin number
	}
}

void MDIO_SetNibbleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber,u8 Copy_u8Value)
{
	u8 Loc_u8Value = 0;
	Loc_u8Value = Copy_u8Value;

	//handling the value
	Loc_u8Value = ((Loc_u8Value & (0x0F)) << Copy_u8PinStart);

	if((Copy_u8PinStart <= 4)&&(Copy_u8PinStart >0))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			//Mask PORT A
			PORTA &= (~((0x0F)<<Copy_u8PinStart));
			PORTA |= Loc_u8Value;
			break;

		case MDIO_PORTB:
			PORTB &= (~((0x0F)<<Copy_u8PinStart));
			PORTB |= Loc_u8Value;
			break;

		case MDIO_PORTC:
			PORTC &= (~((0x0F)<<Copy_u8PinStart));
			PORTC |= Loc_u8Value;
			break;

		case MDIO_PORTD:
			PORTD &= (~((0x0F)<<Copy_u8PinStart));
			PORTD |= Loc_u8Value;
			break;
		default:
			break;
		}
	}
	else
	{

	}
}
