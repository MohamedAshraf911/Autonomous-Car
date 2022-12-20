/*
 * MTIMER_Interface.h
 *
 *  Created on: Oct 28, 2022
 *      Author: DELL
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "../MDIO/MDIO_Interface.h"
#include "MTIMER_Config.h"


void MTIMER0_Init();
void MTIMER0_SetPreload(u8 Copy_u8Preload);
void MTIMER0_SetCTC(u8 Copy_u8OCR);
void MTIMER0_OVERFLOW_CALLBACK(void(*Ptr_OverflowApp)(void));
void MTIMER0_CTC_CALLBACK(void(*Ptr_CTCApp)(void));
void MTIMER0_SetDutyCycle(u8 Copy_u8DutyCycle);
void MTIMER0_STOP();
#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
