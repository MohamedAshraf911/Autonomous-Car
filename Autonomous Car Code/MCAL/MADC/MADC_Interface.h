/*
 * MADC_Interface.h
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */

#ifndef MCAL_MADC_MADC_INTERFACE_H_
#define MCAL_MADC_MADC_INTERFACE_H_

#include "../../LIB/STD_TYPES.H"
#include "../../LIB/Bit_Math.h"
#include "../MDIO/MDIO_Interface.h"
#include "MADC_Config.h"


#define MADC_CHANNEL_0 0
#define MADC_CHANNEL_1 1
#define MADC_CHANNEL_2 2
#define MADC_CHANNEL_3 3
#define MADC_CHANNEL_4 4
#define MADC_CHANNEL_5 5
#define MADC_CHANNEL_6 6
#define MADC_CHANNEL_7 7

void MADC_Init(void);
u16 MADC_StartConversion(u8 Copy_u8ADC_Channel);

#endif /* MCAL_MADC_MADC_INTERFACE_H_ */
