/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the ATmega16 PWM driver
 *
 * Author: Ahmed El-Askary
 *
 *******************************************************************************/

#include "pwm.h"
#include <avr/io.h>
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0=0;

	if(duty_cycle != 100)
		OCR0  = (uint8)((duty_cycle*256)/100);
	else
		OCR0 = 255;

	TCCR0 |= (1<<WGM00) |(1<<WGM01) | (1<<COM01) | (1<<CS01) ;
	GPIO_setupPinDirection( 1 , 3 , PIN_OUTPUT);
}




