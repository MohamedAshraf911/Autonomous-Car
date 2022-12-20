/*
 * MSUART_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: DELL
 */

#ifndef MCAL_MUSART_MSUART_INTERFACE_H_
#define MCAL_MUSART_MSUART_INTERFACE_H_

#include "../MDIO/MDIO_Interface.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "MSUART_Config.h"

/*Functions Prototypes*/
void MSUART_Init();

void MSUART_SendChar(u8 TransmitValue);
u8 MSUART_RecieveChar();

void MSUART_SendString(u8* P_TransmitString);
void MSUART_RecieveString(u8* P_ReceiveString);

#endif /* MCAL_MUSART_MSUART_INTERFACE_H_ */
