/*
 * HCLCD_Private.h
 *
 *  Created on: Oct 1, 2022
 *      Author: DELL
 */

#ifndef HAL_HCLCD_HCLCD_PRIVATE_H_
#define HAL_HCLCD_HCLCD_PRIVATE_H_

/*Options for FUNCTION SET COMMAND*/
#define FUNCTION_SET_4BIT_MODE_1LINE_5BY8_SIZE   0b00100000
#define FUNCTION_SET_4BIT_MODE_1LINE_5BY11_SIZE  0b00100100
#define FUNCTION_SET_4BIT_MODE_2LINE_5BY8_SIZE   0b00101000
#define FUNCTION_SET_4BIT_MODE_2LINE_5BY11_SIZE  0b00101100

/*Options for DISPLAY COMMAND*/
#define DISPLAY_OFF_COMMAND 					 0b00001000
#define DISPLAY_ON 								 0b00001100
#define DISPLAY_ON_CURSOR_ON   					 0b00001110
#define DISPLAY_ON_CURSOR_ON_BLINKING_ON   		 0b00001111

#define DISPLAY_CLEAR_COMMAND 0b00000001

/*Options for ENTRY MODE COMMAND*/
#define ENTRY_MODE_INCREASE_NO_SHIFT 			0b00000110
#define ENTRY_MODE_INCREASE_WITH_SHIFT 			0b00000111
#define ENTRY_MODE_DECREASE_NO_SHIFT 			0b00000100
#define ENTRY_MODE_DECREASE_WITH_SHIFT 			0b00000101

#define HCLCD_LINE0_OFFSET 128
#define HCLCD_LINE1_OFFSET 192

#endif /* HAL_HCLCD_HCLCD_PRIVATE_H_ */
