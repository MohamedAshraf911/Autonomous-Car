/*
 * MGIE_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: DELL
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "MGIE_Interface.h"
#include "MGIE_Private.h"

void MGIE_Enable(void)
{
	SET_BIT(SREG,7);
}
void MGIE_Disable(void)
{
	CLR_BIT(SREG,7);
}
