/*
 * HSEVEN_SEG_Interface.h
 *
 *  Created on: Sep 30, 2022
 *      Author: DELL
 */

#ifndef HAL_HSEVEN_SEG_HSEVEN_SEG_INTERFACE_H_
#define HAL_HSEVEN_SEG_HSEVEN_SEG_INTERFACE_H_

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"


typedef struct{
	u8 PinEnPort;
	u8 PinEn;

	u8 PinAPort;
	u8 PinA;

	u8 PinBPort;
	u8 PinB;

	u8 PinCPort;
	u8 PinC;

	u8 PinDPort;
	u8 PinD;
}SevenSeg_t;

#define SEVEN_SEG_ON 1
#define SEVEN_SEG_OFF 0

void HSEVEN_SEG_Init(SevenSeg_t* Ptr_SevenSegObj);

void HSEVEN_SEG_SetMode(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegMode);

void HSEVEN_SEG_Display(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegValue);

#endif /* HAL_HSEVEN_SEG_HSEVEN_SEG_INTERFACE_H_ */
