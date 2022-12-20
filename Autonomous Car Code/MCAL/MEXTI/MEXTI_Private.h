/*
 * MEXTI_Private.h
 *
 *  Created on: Oct 21, 2022
 *      Author: DELL
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

#define MEXTI_LOW_LEVEL					0
#define MEXTI_ANY_LOGICAL_CHANGE		1
#define MEXTI_RISING_EDGE				2
#define MEXTI_FALLING_EDGE				3

#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR *((volatile u8*)0x5B)


#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
