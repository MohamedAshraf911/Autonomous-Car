/*
 * MTWI_Program.c
 *
 *  Created on: Dec 2, 2022
 *      Author: medo
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../MDIO/MDIO_Interface.h"
#include"MTWI_Config.h"
#include"MTWI_Private.h"
#include "MTWI_Interface.h"

TWI_ErrorState MTWI_MasterInit(u8 Copy_u8SelfSlaveAddress)
{
	u8 ReturnedErrorState = NoError;
	/*Enable the ACK [TWEA]*/
	SET_BIT(TWCR,6);

	/*Set Interrupt Mode*/
#if MTWI_INTERRUPT_MODE==MTWI_INTERRUPT_DISABLED
	CLR_BIT(TWCR,0);
#elif MTWI_INTERRUPT_MODE==MTWI_INTERRUPT_ENABLED
	SET_BIT(TWCR,0);
#else
#error"Wrong Interrupt Mode chosen"
#endif

	/*Set Bit Rate of the TWI Bus */
	/*1-Write on TWPS(1,0)*/
#if MTWI_PRESCALAR_MODE==MTWI_PRESCALAR_BY_1
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
#elif MTWI_PRESCALAR_MODE==MTWI_PRESCALAR_BY_4
	SET_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
#elif MTWI_PRESCALAR_MODE==MTWI_PRESCALAR_BY_16
	CLR_BIT(TWSR,0);
	SET_BIT(TWSR,1);
#elif MTWI_PRESCALAR_MODE==MTWI_PRESCALAR_BY_64
	SET_BIT(TWSR,0);
	SET_BIT(TWSR,1);
#endif

	/*2-Write the Value of TWBR
	 * Solve this Equation for TWBR
	 * SCL_Freq=(FCPU_FREQ)/(16+2*TWBR*4^(TWPS))
	 * Desired SCL_FREQ=400 KHZ @ Maximum */
	TWBR=12;


	/*Check Address Sent is */
	if(Copy_u8SelfSlaveAddress!=0)
	{
		//Put Slave Address in the Register

		/*Clear the LSB of The TWAR*/
		TWAR&=MTWI_TWAR_ADD_MASK;

		/*Putting the Slave Address shifted by one inside the TWAR*/
		TWAR|=(Copy_u8SelfSlaveAddress<<1);
	}
	else
	{
		ReturnedErrorState = WrongAddressPassed;
		return ReturnedErrorState;
	}
	/*enable the TWI*/
	SET_BIT(TWCR,2);

	return ReturnedErrorState;

}

TWI_ErrorState MTWI_SlaveInit(u8 Copy_u8SelfSlaveAddress)
{
	u8 ReturnedErrorState = NoError;

	/*Enable the ACK [TWEA]*/
	SET_BIT(TWCR,6);

	/*Set Interrupt Mode*/
#if MTWI_INTERRUPT_MODE==MTWI_INTERRUPT_DISABLED
	CLR_BIT(TWCR,0);
#elif MTWI_INTERRUPT_MODE==MTWI_INTERRUPT_ENABLED
	SET_BIT(TWCR,0);
#else
#error"Wrong Interrupt Mode chosen"
#endif

	/*2-Write the Value of TWBR
	 * Solve this Equation for TWBR
	 * SCL_Freq=(FCPU_FREQ)/(16+2*TWBR*4^(TWPS))
	 * Desired SCL_FREQ=400 KHZ @ Maximum */
	TWBR=12;


	/*Check Address Sent is */
	if(Copy_u8SelfSlaveAddress!=0)
	{
		//Put Slave Address in the Register

		/*Clear the LSB of The TWAR*/
		TWAR&=MTWI_TWAR_ADD_MASK;

		/*Putting the Slave Address shifted by one inside the TWAR*/
		TWAR|=(Copy_u8SelfSlaveAddress<<1);
	}
	else
	{
		ReturnedErrorState = WrongAddressPassed;
		return ReturnedErrorState;
	}

	/*enable the TWI*/
	SET_BIT(TWCR,2);

	return ReturnedErrorState;
}

TWI_ErrorState MTWI_SendStartCondition()
{
	u8 ReturnedErrorState = NoError;

	//Send Start Condition
	//Note: In the Next operation, you should clear it by software
	SET_BIT(TWCR,5);

	//Clear the TWINT Flag So the TWI performs the last ordered operation
	SET_BIT(TWCR,7);

	//Wait on flag to be high
	while(GET_BIT(TWCR,7)==0);

	//Check Status Code
	if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!= MTWI_STATUS_CODE_START_COND_ACK)
	{
		//Start Condition Error Happens
		ReturnedErrorState = StartConditionFailed;
	}
	else
	{
		//Start Condition Sent Successfully
		ReturnedErrorState = NoError;
	}
	return ReturnedErrorState;
}

TWI_ErrorState MTWI_SendSlaveAddress_WithWrite(u8 Copy_u8SlaveAddress)
{
	/*Make this for further operations*/
	u8 Loc_u8SlaveAddress = Copy_u8SlaveAddress;
	u8 ReturnedErrorState = NoError;

	//Clear TWSTA ==> Start Condition Bit
	CLR_BIT(TWCR,5);

	/*Shift the Address Sent one bit to the left - Automatically a zero
	 * added to the LSB in the variable which indicates a Write Request*/
	TWDR = Loc_u8SlaveAddress<<1;

	//Clear the TWINT Flag so the last Ordered operation is performed
	SET_BIT(TWCR,7);

	//wait on the flag so that the operation is completed
	while(GET_BIT(TWCR,7)==0);

	//Check Status Code
	if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!= MTWI_STATUS_CODE_SLAVE_ADD_WR_ACK)
	{
		//Start Condition Error Happens
		ReturnedErrorState = SlaveAddressWithWriteFailed;
	}
	else
	{
		//Start Condition Sent Successfully
		ReturnedErrorState = NoError;
	}
	return ReturnedErrorState;
}

TWI_ErrorState MTWI_SendSlaveAddress_WithRead(u8 Copy_u8SlaveAddress)
{
	/*Make this for further operations*/
	u8 Loc_u8SlaveAddress = Copy_u8SlaveAddress;
	u8 ReturnedErrorState = NoError;

	//Clear TWSTA ==> Start Condition Bit
	CLR_BIT(TWCR,5);

	/*Shift the Address Sent one bit to the left -
	 * And add a one to the local variable at its LSB to indicate a read request*/
	TWDR = (Loc_u8SlaveAddress<<1)|1;

	//Clear the TWINT Flag so the last Ordered operation is performed
	SET_BIT(TWCR,7);

	//wait on the flag so that the operation is completed
	while(GET_BIT(TWCR,7)==0);

	//Check Status Code
	if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!= MTWI_STATUS_CODE_SLAVE_ADD_R_ACK)
	{
		//Start Condition Error Happens
		ReturnedErrorState = SlaveAddressWithReadFailed;
	}
	else
	{
		//Start Condition Sent Successfully
		ReturnedErrorState = NoError;
	}
	return ReturnedErrorState;
}

TWI_ErrorState MTWI_MasterSlaveWriteData(u8 Copy_u8DataToWrite)
{
	u8 ReturnedErrorState = NoError;

	TWDR = Copy_u8DataToWrite;

	//Clear the TWINT Flag so the last Ordered operation is performed
	SET_BIT(TWCR,7);

	//wait on the flag so that the operation is completed
	while(GET_BIT(TWCR,7)==0);

	//Check Status Code
	if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!= MTWI_STATUS_CODE_START_DATA_SENT_ACK)
	{
		//Start Condition Error Happens
		ReturnedErrorState = DataSendFailed;
	}
	else
	{
		//Start Condition Sent Successfully
		ReturnedErrorState = NoError;
	}
	return ReturnedErrorState;
}

TWI_ErrorState MTWI_MasterSlaveReadData(u8* Ptr_u8DataToRead)
{
	u8 ReturnedErrorState = NoError;


	//Clear the TWINT Flag so the last Ordered operation is performed
	SET_BIT(TWCR,7);

	//wait on the flag so that the operation is completed
	while(GET_BIT(TWCR,7)==0);


	//Check Status Code
	if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!= MTWI_STATUS_CODE_DATA_REC_ACK)
	{
		//Start Condition Error Happens
		ReturnedErrorState = DataReceptionFailed;
	}
	else
	{
		//Read the Data in the TWDR
		*Ptr_u8DataToRead = TWDR;
		//Start Condition Sent Successfully
		ReturnedErrorState = NoError;
	}


	return ReturnedErrorState;
}

TWI_ErrorState MTWI_SendStopCondtition()
{
	u8 ReturnedErrorState = NoError;

	//Set TWSTO ==> Stop Condition Bit
	SET_BIT(TWCR,4);

	//Clear the TWINT Flag so the last Ordered operation is performed
	SET_BIT(TWCR,7);

	//wait on the flag so that the operation is completed
	while(GET_BIT(TWCR,7)==0);

	return ReturnedErrorState;
}
