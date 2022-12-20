/*
 * PORTS.h
 *
 *  Created on: Sep 24, 2022
 *      Author: DELL
 */

#ifndef PORTS_H_
#define PORTS_H_

#define PORTA *((volatile u8*)0x3B)
#define DDRA *((volatile u8*)0x3A)
#define PINA *((volatile u8*)0x39)

#define PORTB *((volatile u8*)0x38)
#define DDRB *((volatile u8*)0x37)
#define PINB *((volatile u8*)0x36)

#define PORTC *((volatile u8*)0x35)
#define DDRC *((volatile u8*)0x34)
#define PINC *((volatile u8*)0x33)

#define PORTD *((volatile u8*)0x32)
#define DDRD *((volatile u8*)0x31)
#define PIND *((volatile u8*)0x30)

#endif /* PORTS_H_ */
