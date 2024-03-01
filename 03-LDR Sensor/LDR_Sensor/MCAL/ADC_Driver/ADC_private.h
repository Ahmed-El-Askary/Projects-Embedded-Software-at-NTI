/*
 ============================================================================
 Module      : ADC Driver
 File Name   : ADC_private.h
 Description : Header file for ADC DIO driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */

#ifndef ADC_DRIVER_ADC_PRIVATE_H_
#define ADC_DRIVER_ADC_PRIVATE_H_

#define ADMUX (*(volatile unsigned char*)0x27)

#define ADLAR     5
#define REFS0     6
#define REFS1     7


#define ADCSRA   (*(volatile unsigned char*)0x26)
#define ADPS0     0
#define ADPS1     1
#define ADPS2     2
#define ADIE      3
#define ADIF      4
#define ADATE     5
#define ADSC      6
#define ADEN      7

#define ADCL     (*(volatile unsigned char*)0x24)
#define ADCH     (*(volatile unsigned char*)0x25)

#define ADC      (*(volatile unsigned short*)0x24)

#endif /* ADC_DRIVER_ADC_PRIVATE_H_ */
