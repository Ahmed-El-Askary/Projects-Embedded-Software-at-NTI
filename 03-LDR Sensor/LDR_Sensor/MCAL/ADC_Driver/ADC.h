/*
 ============================================================================
 Module      : ADC Driver
 File Name   : ADC.h
 Description : Header file for ADC DIO driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */

#ifndef ADC_DRIVER_ADC_H_
#define ADC_DRIVER_ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum {
	AREF,
	AVCC,
	RESERVED,
	INTERNAL
}ADC_ReferenceVolatge;


typedef enum
{
	F_CPU_1,
	F_CPU_2,
	F_CPU_4,
	F_CPU_8,
	F_CPU_16,
	F_CPU_32,
	F_CPU_64,
	F_CPU_128
}ADC_Prescaler;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType *Config_Ptr);

u16 ADC_readChannel(u8 channel_num);

#endif /* ADC_DRIVER_ADC_H_ */
