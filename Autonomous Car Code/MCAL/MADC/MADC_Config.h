/*
 * MADC_Config.h
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */

#ifndef MCAL_MADC_MADC_CONFIG_H_
#define MCAL_MADC_MADC_CONFIG_H_

#include "MADC_Private.h"
/*
 * Options For Voltage References:
 * 1- VREF_AREF_PIN
 * 2-VREF_AVCC_PIN
 * 3-VREF_2_56V_INTERNAL
 */

#define MADC_SET_VREF VREF_AVCC_PIN

/*Options For Prescalar
 *1-PRESCALER_DIVIDE_BY_2
 *1-PRESCALER_DIVIDE_BY_4
 *1-PRESCALER_DIVIDE_BY_8
 *1-PRESCALER_DIVIDE_BY_16
 *1-PRESCALER_DIVIDE_BY_32
 *1-PRESCALER_DIVIDE_BY_64
 *1-PRESCALER_DIVIDE_BY_128*/

#define MADC_SET_PRESCALAR PRESCALER_DIVIDE_BY_16

/*Options For Adjusting the ADC Register Value
 *1-MADC_RIGHT_ADJUST
 *1-MADC_LEFT_ADJUST*/

#define MADC_SET_ADJUST_LEVEL MADC_RIGHT_ADJUST


#endif /* MCAL_MADC_MADC_CONFIG_H_ */
