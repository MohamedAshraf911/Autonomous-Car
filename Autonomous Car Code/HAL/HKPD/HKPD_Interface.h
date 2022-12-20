/*
 * HKPD_Interface.h
 *
 *  Created on: Oct 14, 2022
 *      Author: DELL
 */

#ifndef HAL_HKPD_HKPD_INTERFACE_H_
#define HAL_HKPD_HKPD_INTERFACE_H_

#include "../../LIB/STD_TYPES.H"
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "../HCLCD/HCLCD_Config.h"
#include "../HCLCD/HCLCD_Private.h"
#include "../HCLCD/HCLCD_Interface.h"

#define HKPD_COLUMN_PORT 	MDIO_PORTD
#define HKPD_ROW_PORT 	MDIO_PORTC

#define HKPD_NOT_PRESSED 255

#define HKPD_COL_START 0
#define HKPD_COL_END 4 //ADD ONE TO THE REAL PIN NUMBER

#define HKPD_ROW_START	4
#define HKPD_ROW_END 8 //ADD ONE TO THE REAL PIN NUMBER


typedef enum
{
	HKPD_COLUMN_0_PIN,
	HKPD_COLUMN_1_PIN,
	HKPD_COLUMN_2_PIN,
	HKPD_COLUMN_3_PIN,

	HKPD_ROW_0_PIN,
	HKPD_ROW_1_PIN,
	HKPD_ROW_2_PIN,
	HKPD_ROW_3_PIN
}HKPD_t;

void HKPD_Init();
u8 HKPD_GetPressedButton();

#endif /* HAL_HKPD_HKPD_INTERFACE_H_ */
