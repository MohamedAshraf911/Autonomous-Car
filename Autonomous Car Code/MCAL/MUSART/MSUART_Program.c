/*
 * MSUART_Program.c
 *
 *  Created on: Nov 25, 2022
 *      Author: DELL
 */

#include "MSUART_Interface.h"

void MSUART_Init()
{
	u8 Loc_UCSRC=0;

	/*Set Mode*/

#if MUSART_OPERATING_MODE==MUSART_ASYNCHRONOUS_MODE
	CLR_BIT(Loc_UCSRC,6);
#elif MUSART_OPERATING_MODE==MUSART_SYNCHRONOUS_MODE
	SET_BIT(Loc_UCSRC,6);
#endif

	/*Set Parity*/
#if MUSART_PARITY_MODE==MUSART_PARITY_DISABLED
	CLR_BIT(Loc_UCSRC,4);
	CLR_BIT(Loc_UCSRC,5);
#elif MUSART_PARITY_MODE==MUSART_PARITY_EVEN
	CLR_BIT(Loc_UCSRC,4);
	SET_BIT(Loc_UCSRC,5);
#elif MUSART_PARITY_MODE==MUSART_PARITY_ODD
	SET_BIT(Loc_UCSRC,4);
	SET_BIT(Loc_UCSRC,5);
#endif

	/*Set Stop Bits*/
#if MUSART_STOP_MODE==MUSART_ONE_STOP_BIT
	CLR_BIT(Loc_UCSRC,3);
#elif MUSART_STOP_MODE==MUSART_TWO_STOP_BIT
	SET_BIT(Loc_UCSRC,3);
#endif

	/*Set Data Bits Length */
#if MUSART_DATA_SIZE==MUSART_FIVE_DATA_BITS
	CLR_BIT(Loc_UCSRC,1);
	CLR_BIT(Loc_UCSRC,2);
	CLR_BIT(UCSRB,2);
#elif MUSART_DATA_SIZE==MUSART_SIX_DATA_BITS
	SET_BIT(Loc_UCSRC,1);
	CLR_BIT(Loc_UCSRC,2);
	CLR_BIT(UCSRB,2);
#elif MUSART_DATA_SIZE==MUSART_SEVEN_DATA_BITS
	CLR_BIT(Loc_UCSRC,1);
	SET_BIT(Loc_UCSRC,2);
	CLR_BIT(UCSRB,2);
#elif MUSART_DATA_SIZE==MUSART_EIGHT_DATA_BITS
	SET_BIT(Loc_UCSRC,1);
	SET_BIT(Loc_UCSRC,2);
	CLR_BIT(UCSRB,2);
#elif MUSART_DATA_SIZE==MUSART_NINE_DATA_BITS
	SET_BIT(Loc_UCSRC,1);
	SET_BIT(Loc_UCSRC,2);
	SET_BIT(UCSRB,2);
#endif

	/*Set Bit 7 in Local Variable*/
	SET_BIT(Loc_UCSRC,7);

	UCSRC=Loc_UCSRC;

	/*Set Baud Rate*/
	u16 LocBaud=MUSART_BAUD_RATE;

	//UBRRL=LocBaud&(0x0FF);
	//UBRRH=LocBaud>>8;
	UBRRL=MUSART_BAUD_RATE;

	/*Enable RXEN and TXEN*/
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
}

void MSUART_SendChar(u8 TransmitValue)
{
	/*Poll on UDRE Flag*/
	while(GET_BIT(UCSRA,5)==0)
	{
		//Do Nothing
	}
	//Send Value to UDR
	UDR = TransmitValue;
}

u8 MSUART_RecieveChar()
{
	/*Poll on RXC Flag*/
	while(GET_BIT(UCSRA,7)==0)
	{
		//Do Nothing
	}
	//Save UDR Content
	return UDR;
}

void MUSART_SendString(u8* P_TransmitString)
{
	u8 Loc_TransmitCounter=0;

	while(P_TransmitString[Loc_TransmitCounter]!=NULL)
	{
		MSUART_SendChar(P_TransmitString[Loc_TransmitCounter]);
		Loc_TransmitCounter++;
	}
}

/*Implementation is Changed instead of Checking On the Received element
 *a While(1) is used instead and its Exit Condition is when
 *the Received Element is ('\n')*/
void MUSART_ReceiveString(u8* P_ReceiveString)
{
	u8 Loc_ReceiveCounter=0;

	while(1)
		{
			//Receive
		P_ReceiveString[Loc_ReceiveCounter]= MSUART_RecieveChar();

		if(P_ReceiveString[Loc_ReceiveCounter]=='\n')
		{
			break;
		}
		Loc_ReceiveCounter++;
		}
}
