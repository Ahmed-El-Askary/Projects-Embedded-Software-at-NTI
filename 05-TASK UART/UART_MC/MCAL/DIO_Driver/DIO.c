/*
 ============================================================================
 Module      : DIO
 File Name   : DIO.c
 Description : Source file for the AVR DIO driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */

#include "DIO.h"

void DIO_setupPinDirection(u8 port_num , u8 pin_num , DIO_PinDirection direction )
{
	if((pin_num >= NUM_OF_PINS_PORT) || (port_num >= NUM_OF_PORTS))
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if (direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if (direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if (direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if (direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}

void DIO_writePin(u8 port_num , u8 pin_num , u8 value)
{
	if((pin_num >= NUM_OF_PINS_PORT) || (port_num >= NUM_OF_PORTS))
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}
u8   DIO_readPin (u8 port_num , u8 pin_num)
{
	u8 pin_value = LOGIC_LOW ;
	if((pin_num >= NUM_OF_PINS_PORT) || (port_num >= NUM_OF_PORTS))
	{
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}

	return pin_value ;

}





void DIO_setupPortDirection(u8 port_num , DIO_PortDirection direction )
{

	if (port_num >= NUM_OF_PORTS)
	{

	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID :
			DDRA = direction ;
			break ;
		case PORTB_ID :
			DDRB = direction ;
			break ;
		case PORTC_ID :
			DDRC = direction ;
			break ;
		case PORTD_ID :
			DDRD = direction ;
			break ;
		}
	}
}

void DIO_writePort(u8 port_num , u8 value)
{
	if(port_num >= NUM_OF_PORTS)
	{
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}


u8   DIO_readPort (u8 port_num , u8 pin_num)
{
	u8 value = LOGIC_LOW ;
	if(port_num >= NUM_OF_PORTS)
	{
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			value = PINA;
			break;
		case PORTB_ID:
			value = PINB;
			break;
		case PORTC_ID:
			value = PINC;
			break;
		case PORTD_ID:
			value = PIND;
			break;
		}
	}

	return value;
}
