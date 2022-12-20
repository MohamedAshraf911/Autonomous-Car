/*
 * HCLCD_Interface.h
 *
 *  Created on: Oct 1, 2022
 *      Author: DELL
 */

#ifndef HAL_HCLCD_HCLCD_INTERFACE_H_
#define HAL_HCLCD_HCLCD_INTERFACE_H_

#include "../../MCAL/MDIO/MDIO_Interface.h"

#define RS 1
#define RW 2
#define E 3

#define HCLCD_PIN_START 4

#define CONTROL_PORT MDIO_PORTB
#define DATA_PORT MDIO_PORTA

#define HCLCD_LINE_0 0
#define HCLCD_LINE_1 1

void HCLCD_Init4Bit();
void HCLCD_WriteCommand4Bit(u8 Copy_u8Command);
void HCLCD_WriteChar4Bit(u8 Copy_u8Data);
void HCLCD_SetCursorPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber);
void HCLCD_WriteString(u8* P_u8Data);
void HCLCD_WriteIntegerValue(u32 Copy_u32Value);

#endif /* HAL_HCLCD_HCLCD_INTERFACE_H_ */
