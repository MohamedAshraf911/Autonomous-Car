/*
 * MADC_Program.c
 *
 *  Created on: Nov 4, 2022
 *      Author: DELL
 */

#include "MADC_Interface.h"

/**
 * Init:
 * 1-Select Vreference
 * 2-Set Prescalar
 * 3-Select Left/Right Adjust
 * 4-Enable ADC
 *
 * Start Conversion:
 * 1-Set Channel
 * 2-Start Conversion
 * 3-Poll on ADIF
 * 4-Return ADC value
 */

void MADC_Init(void)
{
	//Set Vreference
#if MADC_SET_VREF == VREF_AREF_PIN
	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif MADC_SET_VREF == VREF_AVCC_PIN
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif MADC_SET_VREF == VREF_2_56V_INTERNAL
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
	#error "Wrong Voltage reference Chosen"
#endif

	//Set Prescalar
#if MADC_SET_PRESCALAR == PRESCALER_DIVIDE_BY_2
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);

#elif MADC_SET_PRESCALAR == PRESCALER_DIVIDE_BY_4
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif MADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_8
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif MADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_16
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif MADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_32
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif MADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif MADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#else
	#error"Wrong prescalar Chosen"
#endif

//Level/Adjust
#if MADC_SET_ADJUST_LEVEL==MADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#elif MADC_SET_ADJUST_LEVEL==MADC_LEFT_ADJUST
	SET_BIT(ADMUX,5);
#endif

/*Enable ADC*/
SET_BIT(ADCSRA,7);
}

u16 MADC_StartConversion(u8 Copy_u8ADC_Channel)
{
	//Set Channel
	u8 Loc_u8ADC_Channel =Copy_u8ADC_Channel&MADC_CHANNEL_INPUT_MASK;
	ADMUX&=MADC_ADMUX_REG_MASK;
	ADMUX|=Loc_u8ADC_Channel;

	//Start Conversion
	SET_BIT(ADCSRA,6);

	//Poll on the Flag
	while(GET_BIT(ADCSRA,4)==0);

	//Conversion finished
	return ADC;
}
