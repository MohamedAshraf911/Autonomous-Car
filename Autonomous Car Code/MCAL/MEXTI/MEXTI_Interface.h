/*
 * MEXTI_Interface.h
 *
 *  Created on: Oct 21, 2022
 *      Author: DELL
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "../MDIO/MDIO_Interface.h"


#define ISR(vectNum) void vectNum (void)__attribute__((signal));\
					 void vectNum (void)

#define VECT_INT0 __vector_1
#define VECT_INT1 __vector_2



void MEXTII0_Init();
void MEXTII1_Init();
void MEXTII2_Init();
void MEXTI_Callback1(void(*ptr)(void));
void MEXTI_Callback2(void(*ptr)(void));

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
