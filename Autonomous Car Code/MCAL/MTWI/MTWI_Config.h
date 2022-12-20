/*
 * MTWI_Config.h
 *
 *  Created on: Dec 2, 2022
 *      Author: medo
 */

#ifndef MCAL_MTWI_MTWI_CONFIG_H_
#define MCAL_MTWI_MTWI_CONFIG_H_

/*Options For Interrupt:
 *1-MTWI_INTERRUPT_DISABLED
 *2-MTWI_INTERRUPT_ENABLED*/

#define MTWI_INTERRUPT_MODE MTWI_INTERRUPT_DISABLED

/*Options for Prescalar
 *1-MTWI_PRESCALAR_BY_1
 *1-MTWI_PRESCALAR_BY_4
 *1-MTWI_PRESCALAR_BY_16
 *1-MTWI_PRESCALAR_BY_64*/

#define MTWI_PRESCALAR_MODE MTWI_PRESCALAR_BY_1

#endif /* MCAL_MTWI_MTWI_CONFIG_H_ */