/******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: timer1.c
 *
 * Description: Source file for the AVR TIMER driver
 *
 * Author: Ahmed El-Askary
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the IO Ports Registers */
#include <avr/interrupt.h> /* For ICU ISR */
#include "timer1.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER1_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}


ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * 1.Function to initialize the Timer1 driver
 * 2.Inputs: pointer to the configuration structure with type Timer1_ConfigType.
 * 3.Return: None
 *
 */
void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	TCCR1A = (1 << FOC1A) | ((TCCR1A & 0xFC) | (Config_Ptr->mode & 0x03));
	TCCR1B = ((TCCR1B & 0xF8) | (Config_Ptr->prescaler & 0x07)) | ((TCCR1B & 0xE7) | ((Config_Ptr->mode & 0x0C)<<1));
	TCNT1 = Config_Ptr->initial_value;

	if(Config_Ptr->mode == CompareMode)
	{
		OCR1A = Config_Ptr->compare_value;
	}
	TIMSK |= (1<<OCIE1A) ;
}
/*
 * Description :
 * Function to disable the Timer1.
 * Inputs: None
 * Return: None
 *
 */
void Timer1_deInit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	OCR1A = 0;
}

/*
 * Description :
 * Function to set the Call Back function address.
 * Inputs:pointer to Call Back function.
 * Return: None
 *
 */
void Timer1_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr=a_ptr;
}


