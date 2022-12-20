/*
 * EEPROM_Interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/*
typedef enum
{
	Block0,
	Block1,
	Block2,
	Block3,
	Block4,
	Block5,
	Block6,
	Block7
};
*/

/*Function Prototypes*/
void EEPROM_WriteByte(u8 Copy_u8BlockNo, u8 Copy_u8ByteAddress, u8 Copy_u8Data );
u8 EEPROM_ReadByte(u8 Copy_u8BlockNo, u8 Copy_u8ByteAddress);


#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
