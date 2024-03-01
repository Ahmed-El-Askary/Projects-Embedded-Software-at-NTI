/******************************************************************************
 *
 * Module: DC-MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the ATmega16 DC-MOTOR driver
 *
 * Author: Ahmed El-Askary
 *
 *******************************************************************************/
#include "std_types.h"
#include "DIO.h"
#include "dc_motor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void DcMotor_init(void)
{
	DIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN0_ID, PIN_OUTPUT);
	DIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN1_ID, PIN_OUTPUT);

	DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_LOW);
	DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state)
{
	if(state == CW)
	{
		DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_HIGH);
		DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_LOW);
	}
	else if( state == ACW)
	{
		DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_LOW);
		DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_HIGH);
	}
	else if(state == STOP)
	{
		DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_LOW);
		DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_LOW);
	}
}
