/*
 * HSERVO_Interface.h
 *
 *  Created on: Dec 9, 2022
 *      Author: DELL
 */

#ifndef HAL_HSERVO_HSERVO_INTERFACE_H_
#define HAL_HSERVO_HSERVO_INTERFACE_H_

#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"

#include "util/delay.h"

#define SERVO_PORT MDIO_PORTD

/**************FUNCTION PROTOTYPES ****************/
void HSERVO_Init(void);
void HSERVO_Rotate(void);
void HSERVO_Rotate_Middle(void);
void HSERVO_Rotate_Right(void);
void HSERVO_Rotate_Left(void);
#endif /* HAL_HSERVO_HSERVO_INTERFACE_H_ */
