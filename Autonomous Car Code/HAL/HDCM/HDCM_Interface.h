/*
 * HDCM_Interface.h
 *
 * Created: 12/16/2022 2:28:25 PM
 *  Author: Hisham Elbadry
 */ 

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "HDCM_Private.h"

#ifndef HDCM_INTERFACE_H_
#define HDCM_INTERFACE_H_

void HDCM_Init(void);
void HDCM_Forward_M_Left(void);
void HDCM_Backward_M_Left(void);
void HDCM_Forward_M_Right(void);
void HDCM_Backward_M_Right(void);


void HDCM_Stop(void);
void HDCM_Forward(void);
void HDCM_Back(void);
void HDCM_Right(void);
void HDCM_Left(void);


#endif /* HDCM_INTERFACE_H_ */
