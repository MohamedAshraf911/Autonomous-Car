/*
 * MADC_Private.h
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */

#ifndef MCAL_MADC_MADC_PRIVATE_H_
#define MCAL_MADC_MADC_PRIVATE_H_

/*Registers */
#define ADMUX 		*((volatile u8*)0x27)
#define ADCSRA 		*((volatile u8*)0x26)
#define ADC 		*((volatile u16*)0x24)
#define SFIOR 		*((volatile u8*)0x50)

#define VREF_AREF_PIN   		0
#define VREF_AVCC_PIN   		1
#define VREF_2_56V_INTERNAL 	3


#define PRESCALER_DIVIDE_BY_2 		1
#define PRESCALER_DIVIDE_BY_4 		2
#define PRESCALER_DIVIDE_BY_8 		3
#define PRESCALER_DIVIDE_BY_16 		4
#define PRESCALER_DIVIDE_BY_32 		5
#define PRESCALER_DIVIDE_BY_64 		6
#define PRESCALER_DIVIDE_BY_128 	7



#define MADC_RIGHT_ADJUST  0
#define MADC_LEFT_ADJUST   1

#define MADC_CHANNEL_INPUT_MASK 0X1F
#define MADC_ADMUX_REG_MASK 0XE0

#endif /* MCAL_MADC_MADC_PRIVATE_H_ */
