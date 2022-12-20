/*
 * HSERVO_Private.h
 *
 *  Created on: Dec 9, 2022
 *      Author: DELL
 */

#ifndef HAL_HSERVO_HSERVO_PRIVATE_H_
#define HAL_HSERVO_HSERVO_PRIVATE_H_

//// SERVO ANGLES
//#define ANGLE_ZERO 1
//#define ANGLE_45   1.25
//#define ANGLE_90   1.5
//#define ANGLE_135  1.75
//#define ANGLE_180  2
//
//#define CONTROL_PIN 7


#define TCCR1A        *((volatile u8*)0x4F)
#define TCCR1B        *((volatile u8*)0x4E)

#define ICR1          *((volatile u16*)0x46)
#define OCR1A         *((volatile u16*)0x4A)

#endif /* HAL_HSERVO_HSERVO_PRIVATE_H_ */
