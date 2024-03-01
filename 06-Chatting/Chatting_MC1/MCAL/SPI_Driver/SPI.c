/*
 * SPI.c
 *
 *  Created on: Oct 31, 2023
 *      Author: DELL
 */

#include "SPI.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void SPI_initMaster(void)
{

	DIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
	DIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_OUTPUT);


	SPCR = (1<<SPE) | (1<<MSTR);

//	SPCR |= (1<<SPR0);
}


void SPI_initSlave(void)
{

	DIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_OUTPUT);
	DIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_INPUT);

	SPCR = (1<<SPE);

//	SPCR |= (1<<SPR0);
}


u8 SPI_sendReceiveByte(u8 data)
{
	SPDR = data;
	while(BIT_IS_CLEAR(SPSR,SPIF)){}
	return SPDR;
}

void SPI_sendString(const u8 *str)
{
	u8 i = 0;
	u8 received_data = 0;

	while(str[i] != '\0')
	{
		received_data = SPI_sendReceiveByte(str[i]);
		i++;
	}
}

void SPI_receiveString(u8 *str)
{
	u8 i = 0;
	str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}
	str[i] = '\0';
}
