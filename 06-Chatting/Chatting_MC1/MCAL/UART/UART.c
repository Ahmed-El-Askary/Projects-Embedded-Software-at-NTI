/*
 * UART.c
 *
 *  Created on: Oct 30, 2023
 *      Author: DELL
 */
#include "UART.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void UART_init(const UART_ConfigType * Config_Ptr)
{
	u16 ubrr_value = 0;

	UCSRA = (1<<U2X);


	UCSRB = (1<<RXEN) | (1<<TXEN);

	/************************** UCSRC Description Configuration ************/
	UCSRC = (1<<URSEL);
	UCSRC = (UCSRC & 0xCF)|((Config_Ptr->parity)<< 4);
	UCSRC = (UCSRC & 0xF7)|((Config_Ptr->stop_bit)<< 3);
	UCSRC = (UCSRC & 0xF9)|((Config_Ptr->bit_data)<< 1);
	/* Calculate the UBRR register value */
	ubrr_value = (u16)(((1000000UL / (Config_Ptr->baud_rate * 8UL))) - 1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = ubrr_value>>8;
	UBRRL = ubrr_value;
}


void UART_sendByte(const u8 data)
{

	while(BIT_IS_CLEAR(UCSRA,UDRE)){}


	UDR = data;
}


u8 UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
    return UDR;
}

void UART_sendString(const u8 *Str)
{
	u8 i = 0;

	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}

}


void UART_receiveString(u8 *Str)
{
	u8 i = 0;

	Str[i] = UART_recieveByte();

	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

	Str[i] = '#';
	Str[i+1] = '\0';
}
