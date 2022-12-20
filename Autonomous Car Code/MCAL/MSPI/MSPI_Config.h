/*
 * MSPI_Config.h
 *
 *  Created on: Nov 26, 2022
 *      Author: DELL
 */

#ifndef MCAL_MSPI_MSPI_CONFIG_H_
#define MCAL_MSPI_MSPI_CONFIG_H_

#include "MSPI_Private.h"
/*
 * Options for SPI Mode:
 * 1-MSPI_MASTER_MODE
 * 2-MSPI_SLAVE_MODE
 */

#define MSPI_SET_MODE MSPI_MASTER_MODE

/*
 * Options for Interrupt:
 * 1-MSPI_INTERRUPT_ON
 * 2-MSPI_INTERRUPT_OFF
 */

#define MSPI_INTERRUPT_MODE MSPI_INTERRUPT_OFF

/*
 * Options for Polarity:
 * 1-MSPI_POL_ACTIVE_HIGH
 * 2-MSPI_POL_ACTIVE_LOW
 */

#define MSPI_POLARITY_MODE MSPI_POL_ACTIVE_LOW

/*
 * Options for Phase:
 * 1-MSPI_PHASE_SAMPLE_AT_LEADING
 * 2-MSPI_PHASE_SAMPLE_AT_TRAILING
 */

#define MSPI_PHASE_MODE MSPI_PHASE_SAMPLE_AT_LEADING

/*
 * Options for DATA ORDERED:
 * 1-MSPI_DORD_MSB_FIRST
 * 2-MSPI_DORD_LSB_FIRST
 */

#define MSPI_DORD_MODE MSPI_DORD_MSB_FIRST

/*
 * Options for CLOCK
 * 1-MSPI_CLOCK_FCPU_4
 * 2-MSPI_CLOCK_FCPU_16
 * 3-MSPI_CLOCK_FCPU_64
 * 4-MSPI_CLOCK_FCPU_128
 * 5-MSPI_CLOCK_FCPU_2
 * 6-MSPI_CLOCK_FCPU_8
 * 7-MSPI_CLOCK_FCPU_32
 * 8-MSPI_CLOCK_FCPU_64x2
 */

#define MSPI_CLOCK_MODE MSPI_CLOCK_FCPU_128


#endif /* MCAL_MSPI_MSPI_CONFIG_H_ */
