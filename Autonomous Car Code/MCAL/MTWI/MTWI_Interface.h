/*
 * MTWI_Interface.h
 *
 *  Created on: Dec 2, 2022
 *      Author: medo
 */

#ifndef MCAL_MTWI_MTWI_INTERFACE_H_
#define MCAL_MTWI_MTWI_INTERFACE_H_


typedef enum
{
	NoError,
	WrongAddressPassed,
	StartConditionFailed,
	SlaveAddressWithWriteFailed,
	SlaveAddressWithReadFailed,
	DataSendFailed,
	DataReceptionFailed,
}
TWI_ErrorState;
/*Function Prototypes*/

TWI_ErrorState MTWI_MasterInit(u8 Copy_u8SelfSlaveAddress);

TWI_ErrorState MTWI_SlaveInit(u8 Copy_u8SelfSlaveAddress);
TWI_ErrorState MTWI_SendStartCondition();
TWI_ErrorState MTWI_SendSlaveAddress_WithWrite(u8 Copy_u8SlaveAddress);
TWI_ErrorState MTWI_SendSlaveAddress_WithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorState MTWI_MasterSlaveWriteData(u8 Copy_u8DataToWrite);
TWI_ErrorState MTWI_MasterSlaveReadData(u8* Ptr_u8DataToRead);

TWI_ErrorState MTWI_SendStopCondtition();

#endif /* MCAL_MTWI_MTWI_INTERFACE_H_ */
