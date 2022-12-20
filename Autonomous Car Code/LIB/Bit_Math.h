/*
 * Bit_Math.h
 *
 *  Created on: Sep 23, 2022
 *      Author: DELL
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

#endif /* BIT_MATH_H_ */
