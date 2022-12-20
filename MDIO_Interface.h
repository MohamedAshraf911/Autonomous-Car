/*
 * MDIO_Interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: DELL
 */

#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.H"

#define MDIO_PORTA 0
#define MDIO_PORTB 1
#define MDIO_PORTC 2
#define MDIO_PORTD 3

#define PORT_OUTPUT 255
#define PORT_INPUT 0

#define PORT_HIGH 255
#define PORT_LOW 0

#define PIN_OUTPUT 1
#define PIN_INPUT 0

#define PIN_HIGH 1
#define PIN_LOW 0

#define NULL 0


typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Pin_t;

//Functions prototypes

void MDIO_SetPortDirection(u8 Copy_u8PortNumber, u8 Copy_u8PortDirection);
void MDIO_SetPinDirection(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 Copy_u8PinDirection);
void MDIO_SetPortValue(u8 Copy_u8PortNumber, u8 Copy_u8PortValue);
void MDIO_SetPinValue(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 Copy_u8PinValue);
void MDIO_ReadPortValue(u8 Copy_u8PortNumber, u8 * P_u8PortReading);
void MDIO_ReadPinValue(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 * P_u8PinReading);
void MDIO_TogglePin(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber);
void MDIO_SetNibbleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber,u8 Copy_u8Value);

#endif /* MDIO_INTERFACE_H_ */
