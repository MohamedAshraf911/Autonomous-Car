/*
 * HCLCD_Program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: DELL
 */

#include <util/delay.h>
#include "HCLCD_Interface.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "HCLCD_Config.h"

void HCLCD_WriteCommand4Bit(u8 Copy_u8Command)
{
	//Set RW to Zero
	MDIO_SetPinValue(RW,CONTROL_PORT,PIN_LOW);

	//Set RS to zero
	MDIO_SetPinValue(RS,CONTROL_PORT,PIN_LOW);

	//Set High Nibble Value of the command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Command>>4);

	//Set E to 1 then wait for 2 ms then set it to 0(sending the falling edge)
	MDIO_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E,CONTROL_PORT,PIN_LOW);

	//Set Low Nibble Value of the command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Command);

	//Set E to 1 then wait for 2 ms then set it to 0(sending the falling edge)
		MDIO_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
		_delay_ms(2);
		MDIO_SetPinValue(E,CONTROL_PORT,PIN_LOW);
}

void HCLCD_Init4Bit()
{
	_delay_ms(35);

	// Set direction of the 4 data pins
	u8 Loc_u8Counter = 0;
	for(Loc_u8Counter = HCLCD_PIN_START;Loc_u8Counter<(HCLCD_PIN_START+4);Loc_u8Counter++)
	{
		MDIO_SetPinDirection(Loc_u8Counter,DATA_PORT,PIN_OUTPUT);
	}

	// Set direction of the 3 Control pins
	for(Loc_u8Counter = RS;Loc_u8Counter<(RS+3);Loc_u8Counter++)
	{
		MDIO_SetPinDirection(Loc_u8Counter,CONTROL_PORT,PIN_OUTPUT);
	}

	/*
	 * Start of the initialization sequence
	 */

	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,FUNCTION_SET_MODE_COMMAND>>4);

	MDIO_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E,CONTROL_PORT,PIN_LOW);
	//Send Function Set Command
	HCLCD_WriteCommand4Bit(FUNCTION_SET_MODE_COMMAND);

	//Send Display On/Off Command
	_delay_ms(1);
	HCLCD_WriteCommand4Bit(DISPLAY_ON_OFF_COMMAND);

	//Display Clear Mode
	HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);

	//Entry Mode
	_delay_ms(2);
	HCLCD_WriteCommand4Bit(ENTRY_MODE_COMMAND);
}

void HCLCD_WriteChar4Bit(u8 Copy_u8Data)
{
	//Set RW to Zero
	MDIO_SetPinValue(RW,CONTROL_PORT,PIN_LOW);

	//Set RS to One
	MDIO_SetPinValue(RS,CONTROL_PORT,PIN_HIGH);

	//Set High Nibble Value of the command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Data>>4);

	//Set E to 1 then wait for 2 ms then set it to 0(sending the falling edge)
	MDIO_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E,CONTROL_PORT,PIN_LOW);

	//Set Low Nibble Value of the command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Data);

	//Set E to 1 then wait for 2 ms then set it to 0(sending the falling edge)
	MDIO_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E,CONTROL_PORT,PIN_LOW);
}

void HCLCD_SetCursorPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{
	if((Copy_u8LineNumber == HCLCD_LINE_0)||(Copy_u8LineNumber == HCLCD_LINE_1))
	{
		if(Copy_u8PositionNumber<16)
		{
			if(Copy_u8LineNumber== HCLCD_LINE_0)
			{
				HCLCD_WriteCommand4Bit(Copy_u8PositionNumber + HCLCD_LINE0_OFFSET);
			}
			else
			{
				HCLCD_WriteCommand4Bit(Copy_u8PositionNumber + HCLCD_LINE1_OFFSET);
			}
		}
		else
		{

		}
	}
	else
	{
		//Wrong line chosen
	}
}

void HCLCD_WriteString(u8* P_u8Data)
{
	u8 Loc_u8Counter = 0;
	while(P_u8Data[Loc_u8Counter] != '\0')
	{
		HCLCD_WriteChar4Bit(P_u8Data[Loc_u8Counter]);
		Loc_u8Counter++;
	}
}

void HCLCD_WriteIntegerValue(u32 Copy_u32Value)
{
	if(Copy_u32Value == 0)
	{
		HCLCD_WriteChar4Bit((Copy_u32Value + 48));
	}
	else
	{
		u32 Loc_u8TempValue = Copy_u32Value;
		u8 Loc_u8CharArray[20] = {0},Loc_u8Count = 0, Loc_u8Index = 0;
		while(Loc_u8TempValue != 0)
		{
			Loc_u8CharArray[Loc_u8Count] = ((Loc_u8TempValue % 10) + 48);
			Loc_u8TempValue /= 10;
			Loc_u8Count++;
		}

		for(Loc_u8Index = 0; Loc_u8Index < Loc_u8Count; Loc_u8Index++)
		{
			HCLCD_WriteChar4Bit(Loc_u8CharArray[Loc_u8Count - Loc_u8Index - 1]);
		}
	}
}
