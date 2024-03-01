/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the AVR BUZZER driver
 *
 * Author: Ahmed El-Askary
 *
 *******************************************************************************/

#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */
#include "buzzer.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description :
 * Setup the direction for the buzzer pin as output pin through the GPIO driver.
 * Turn off the buzzer through the GPIO.
 * Inputs: None
 * Return: None
 *
 */
void Buzzer_init()
{
	GPIO_setupPinDirection( BUZZER_PORT_ID ,BUZZER_PIN_ID ,PIN_OUTPUT);
	GPIO_writePin( BUZZER_PORT_ID,BUZZER_PIN_ID , LOGIC_LOW);
}

/*
 * Description :
 * Function to enable the Buzzer through the GPIO.
 * Inputs: None
 * Return: None
 *
 */
void Buzzer_on(void)
{
	GPIO_writePin( BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}

/*
 * Description :
 * Function to disable the Buzzer through the GPIO.
 * Inputs: None
 * Return: None
 *
 */

void Buzzer_off(void)
{
	GPIO_writePin( BUZZER_PORT_ID,BUZZER_PIN_ID , LOGIC_LOW);
}
