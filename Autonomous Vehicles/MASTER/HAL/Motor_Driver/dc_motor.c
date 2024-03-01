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
#include "pwm.h"
#include "gpio.h"
#include "dc_motor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void DcMotor_init(void)
{
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN1_ID, PIN_OUTPUT);

	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state == CW)
	{
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_LOW);
	}
	else if( state == ACW)
	{
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_HIGH);
	}
	else if(state == STOP)
	{
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_LOW);
	}
	PWM_Timer0_Start(speed);
}
