/*
 * MSPI_Private.h
 *
 *  Created on: Nov 26, 2022
 *      Author: DELL
 */

#ifndef MCAL_MSPI_MSPI_PRIVATE_H_
#define MCAL_MSPI_MSPI_PRIVATE_H_

#define SPCR *((volatile u8*)0x2D)
#define SPSR *((volatile u8*)0x2E)
#define SPDR *((volatile u8*)0x2F)

#define MSPI_MASTER_MODE 0
#define MSPI_SLAVE_MODE  1

#define MSPI_INTERRUPT_ON	0
#define MSPI_INTERRUPT_OFF	1

#define MSPI_POL_ACTIVE_HIGH	0
#define MSPI_POL_ACTIVE_LOW		1

#define MSPI_PHASE_SAMPLE_AT_LEADING	0
#define MSPI_PHASE_SAMPLE_AT_TRAILING	1

#define MSPI_DORD_MSB_FIRST		0
#define MSPI_DORD_LSB_FIRST		1


#define MSPI_CLOCK_FCPU_4		0
#define MSPI_CLOCK_FCPU_16		1
#define MSPI_CLOCK_FCPU_64		2
#define MSPI_CLOCK_FCPU_128		3
#define MSPI_CLOCK_FCPU_2		4
#define MSPI_CLOCK_FCPU_8		5
#define MSPI_CLOCK_FCPU_32		6
#define MSPI_CLOCK_FCPU_64x2		7

#endif /* MCAL_MSPI_MSPI_PRIVATE_H_ */
