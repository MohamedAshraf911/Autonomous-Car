/*
 * HSERVO_Interface.h
 *
 *  Created on: Dec 9, 2022
 *      Author: DELL
 */

#ifndef HAL_HUS_HUS_INTERFACE_H_
#define HAL_HUS_HUS_INTERFACE_H_

//#define F_CPU 16000000
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "util/delay.h"
#include "../../MCAL/MTIMER/MTIMER_Interface.h"
#include "../../MCAL/MTIMER/MTIMER_Config.h"
#include "../../MCAL/MEXTI/MEXTI_Interface.h"
#include "HUS_Private.h"

void US_EXTI_RECEIVE(void);
void US_INIT(void);
void US_OverFlow_Counter(void);
void US_Trigger(void);
#endif /* HAL_HUS_HUS_INTERFACE_H_ */
