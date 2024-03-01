/*
 ================================================================================================
 Name        : Main_app.c
 Author      : Ahmed El-Askary.
 Description : State of Motor CW and ACW.
 Date        : 24/10/2023.
 ================================================================================================
 */

#include "DIO.h"
#include "EXT_Interrupt.h"
#include "dc_motor.h"

volatile DcMotor_State motorState = STOP;

void Func_INT0 (void)
{
    static u8 buttonState = 0;
    buttonState++;

    if (buttonState % 2 == 1)
    {
        DcMotor_Rotate(CW);
        motorState = CW;
    }
    else
    {
        DcMotor_Rotate(ACW);
        motorState = ACW;
    }
}
int main(void)
{

	DIO_setupPinDirection(PORTB_ID, PIN0, PIN_OUTPUT);
	DIO_setupPinDirection(PORTB_ID, PIN1, PIN_OUTPUT);


	DIO_setupPinDirection(PORTC_ID, PIN0, PIN_OUTPUT);
	DIO_setupPinDirection(PORTC_ID, PIN1, PIN_OUTPUT);
	DIO_setupPinDirection(PORTC_ID, PIN2, PIN_OUTPUT);

	EXI_TriggerEdge(EX_INT0, RISING);
	EXI_Enable(EX_INT0);
	GIE_Enable();
	EXI_SetCallBack(EX_INT0,Func_INT0);

	while (1) {
		switch (motorState)
		{
		case STOP:
			DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_LOW);
			DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_LOW);

			CLEAR_BIT(PORTC , PIN0);
			CLEAR_BIT(PORTC , PIN1);

			SET_BIT(PORTC , PIN2);
			break;

		case CW:
			DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_HIGH);
			DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_LOW);

			CLEAR_BIT(PORTC , PIN0);
			CLEAR_BIT(PORTC , PIN2);

			SET_BIT(PORTC , PIN1);

			break;
		case ACW:

			DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN0_ID, LOGIC_LOW);
			DIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID, LOGIC_HIGH);

			CLEAR_BIT(PORTC , PIN1);
			CLEAR_BIT(PORTC , PIN2);

			SET_BIT(PORTC , PIN0);

			break;
		}
	}
}
