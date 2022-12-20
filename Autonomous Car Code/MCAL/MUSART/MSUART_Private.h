/*
 * MSUART_Private.h
 *
 *  Created on: Nov 25, 2022
 *      Author: DELL
 */

#ifndef MCAL_MUSART_MSUART_PRIVATE_H_
#define MCAL_MUSART_MSUART_PRIVATE_H_

#define UDR   *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)

#define MUSART_ASYNCHRONOUS_MODE 0
#define MUSART_SYNCHRONOUS_MODE 1

#define MUSART_PARITY_DISABLED 0
#define MUSART_PARITY_EVEN     1
#define MUSART_PARITY_ODD      2

#define MUSART_ONE_STOP_BIT  0
#define MUSART_TWO_STOP_BIT  1

#define MUSART_FIVE_DATA_BITS  		0
#define MUSART_SIX_DATA_BITS   		1
#define MUSART_SEVEN_DATA_BITS 		2
#define MUSART_EIGHT_DATA_BITS 		3
#define MUSART_NINE_DATA_BITS  		4

#define MUSART_2400  	416
#define MUSART_4800  	208
#define MUSART_9600  	104
#define MUSART_19200 	52
#define MUSART_38400 	26

#endif /* MCAL_MUSART_MSUART_PRIVATE_H_ */
