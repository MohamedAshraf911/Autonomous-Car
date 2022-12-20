/*
 * MSPI_Interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: DELL
 */

#ifndef MCAL_MSPI_MSPI_INTERFACE_H_
#define MCAL_MSPI_MSPI_INTERFACE_H_

#include "../MDIO/MDIO_Interface.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"

/*Function Prototypes*/
void MSPI_MasterInit();
void MSPI_SlaveInit();

u8 MSPI_SendReceive(u8 Copy_u8TransmittedValue);

#endif /* MCAL_MSPI_MSPI_INTERFACE_H_ */
