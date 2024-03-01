/*
 ============================================================================
 Module      : ADC Driver
 File Name   : ADC.c
 Description : Header file for ADC DIO driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */
#include "std_types.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "common_macros.h"
#include "ADC.h"



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType *config_ptr)
{
	ADMUX=((config_ptr->ref_volt)<<6);
	ADCSRA=(1<<ADEN) |(config_ptr->prescaler);
}

u16 ADC_readChannel(u8 channel_num)
{
	ADMUX = (ADMUX &= 0xE0) | (channel_num &= 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
