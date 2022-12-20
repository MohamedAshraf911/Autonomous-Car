/*
 * HKPD_Program.c
 *
 *  Created on: Oct 14, 2022
 *      Author: DELL
 */

#include "HKPD_Interface.h"
#include "HKPD_Private.h"
#include "util/delay.h"

u8 CursorPosition = 0;

void HKPD_Init()
{
	//Set column pins direction output
	MDIO_SetPinDirection(PIN0,HKPD_COLUMN_PORT,PIN_OUTPUT);
	MDIO_SetPinDirection(PIN1,HKPD_COLUMN_PORT,PIN_OUTPUT);
	MDIO_SetPinDirection(PIN4,HKPD_COLUMN_PORT,PIN_OUTPUT);
	MDIO_SetPinDirection(PIN5,HKPD_COLUMN_PORT,PIN_OUTPUT);

	//Set row pins direction input
	MDIO_SetPinDirection(PIN3,HKPD_ROW_PORT,PIN_INPUT);
	MDIO_SetPinDirection(PIN4,HKPD_ROW_PORT,PIN_INPUT);
	MDIO_SetPinDirection(PIN5,HKPD_ROW_PORT,PIN_INPUT);
	MDIO_SetPinDirection(PIN6,HKPD_ROW_PORT,PIN_INPUT);

	//Activate pull up resistor
	MDIO_SetPinValue(PIN3,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN4,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN5,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN6,HKPD_ROW_PORT,PIN_HIGH);

	//Deactivate Columns
	MDIO_SetPinValue(PIN0,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN1,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN4,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN5,HKPD_COLUMN_PORT,PIN_HIGH);
}


u8 HKPD_GetPressedButton()
{
	u8 Loc_u8ColumnCounter = 0;
	u8 Loc_u8RowCounter = 0;
	u8 Loc_u8ReturnValue = HKPD_NOT_PRESSED;
	u8 Loc_u8PinState = 0;
	u8 Loc_u8PinArray[8] = {PIN0,PIN1,PIN4,PIN5,PIN3,PIN4,PIN5,PIN6};

	if(CursorPosition == 16)
	{
		HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
	}
	for(Loc_u8ColumnCounter = HKPD_COL_START;Loc_u8ColumnCounter<HKPD_COL_END;Loc_u8ColumnCounter++)
	{
		MDIO_SetPinValue(Loc_u8PinArray[Loc_u8ColumnCounter],HKPD_COLUMN_PORT,PIN_LOW);

		for(Loc_u8RowCounter = HKPD_ROW_START;Loc_u8RowCounter<HKPD_ROW_END;Loc_u8RowCounter++)
		{
			MDIO_ReadPinValue(Loc_u8PinArray[Loc_u8RowCounter],HKPD_ROW_PORT,&Loc_u8PinState);

			if(Loc_u8PinState == 0)
			{
				Loc_u8ReturnValue = HKPD_SwitchValues[Loc_u8ColumnCounter-HKPD_COL_START][Loc_u8RowCounter-HKPD_ROW_START];
				CursorPosition++;
				while(Loc_u8PinState == 0)
				{
					MDIO_ReadPinValue(Loc_u8PinArray[Loc_u8RowCounter],HKPD_ROW_PORT,&Loc_u8PinState);
				}
				_delay_ms(10);
			}
			else
			{

			}
		}
		MDIO_SetPinValue(Loc_u8PinArray[Loc_u8ColumnCounter],HKPD_COLUMN_PORT,PIN_HIGH);
	}
	return Loc_u8ReturnValue;
}
