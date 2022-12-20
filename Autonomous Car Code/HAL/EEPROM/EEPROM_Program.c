/*
 * EEPROM_Program.c
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#include "EEPROM_Interface.h"
#include "EEPROM_Config.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "../../MCAL/MTWI/MTWI_Interface.h"


void EEPROM_WriteByte(u8 Copy_u8BlockNo, u8 Copy_u8ByteAddress, u8 Copy_u8Data )
{
	u8 Loc_u8SlaveAdd;
	/*Send Start Condition*/
	MTWI_SendStartCondition();

	/*Send SLA+W
	 * SLA = 1010 XXX 0 ===> for write
	 * xxx = Copy_u8BlockNo*/
	Loc_u8SlaveAdd = EEPROM_FIXED_SLAVE_ADDRESS|(Copy_u8BlockNo);

	MTWI_SendSlaveAddress_WithWrite(Loc_u8SlaveAdd);

	/*Send the remainder Byte address as a data byte*/
	MTWI_MasterSlaveWriteData(Copy_u8ByteAddress);

	/*Send the real data needed to be saved at the previous Address*/
	MTWI_MasterSlaveWriteData(Copy_u8Data);

	/*Send Stop Condition*/
	MTWI_SendStopCondtition();
}


u8 EEPROM_ReadByte(u8 Copy_u8BlockNo, u8 Copy_u8ByteAddress)
{
	u8 Loc_u8ReturnedValue;
	u8 Loc_u8SlaveAdd;
	/*Send Start Condition*/
	MTWI_SendStartCondition();

	/*Send SLA+W
	 * SLA = 1010 XXX 0 ===> for write
	 * xxx = Copy_u8BlockNo*/
	Loc_u8SlaveAdd = EEPROM_FIXED_SLAVE_ADDRESS|(Copy_u8BlockNo);

	MTWI_SendSlaveAddress_WithWrite(Loc_u8SlaveAdd);

	/*Send the remainder Byte address as a data byte*/
	MTWI_MasterSlaveWriteData(Copy_u8ByteAddress);

	/*Send Repeated Start*/
	MTWI_SendStartCondition();

	/*Send Slave Address with Read*/
	/*Same Slave Address Adjusted before
	 * But with changing the LSB from 0 ==> 1
	 * to signal read request*/
	Loc_u8SlaveAdd|=0x01;

	/*Read Data*/
	MTWI_MasterSlaveReadData(&Loc_u8ReturnedValue);

	/*Send Stop Condition*/
	MTWI_SendStopCondtition();

	return Loc_u8ReturnedValue;
}
