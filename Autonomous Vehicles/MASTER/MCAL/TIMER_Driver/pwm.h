/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Source file for the ATmega16 PWM driver
 *
 * Author: Ahmed El-Askary
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include"std_types.h"
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
#define PWM_OUTPUT_PORT_ID       PORTB_ID
#define PWM_OUTPUT_PIN_ID        PIN3_ID


void PWM_Timer0_Start( uint8 duty_cycle );

#endif /* PWM_H_ */
