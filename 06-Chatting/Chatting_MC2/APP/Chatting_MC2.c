/*
 ================================================================================================
 Name        : MCU2.c
 Author      : Ahmed El-Askary.
 Description : Chatting SPI UART Slave
 Date        : 24/10/2023.
 ================================================================================================
 */

#include "uart.h"
#include "lcd.h"
#include "SPI.h"
#include <util/delay.h>


u8 virtual_terminal_input[20];
volatile u8 send_flag ;

void uart_function(void)
{
	static u8 counter;
	virtual_terminal_input[counter] = UART_ReceiveNoBlock();
	if ( virtual_terminal_input[counter] == 0x0D )
	{
		virtual_terminal_input[counter] = 0 ;
		send_flag = 1 ;
		counter = 0 ;
	}
	else if ( virtual_terminal_input[counter] == 127 || virtual_terminal_input[counter] == '\b' )
	{
		virtual_terminal_input[counter] = 0 ;

		virtual_terminal_input[counter-1] = 0 ;
		counter-- ;
	}
	else if( virtual_terminal_input[counter] != 0x0D )
	{
		counter++;
	}

}




int main(void)
{
	DIO_Init();
	SPI_Init();
	UART_ConfigType UART_Config ={BIT_8 ,DISABLED_PARITY ,STOP_ONE_BIT ,9600 };
	UART_init( &UART_Config );
	LCD_Init();
	SPI_SetCallBack(SPI_function);
	UART_RX_SetCallBack(uart_function);
	UART_RX_InterruptEnable();

	DIO_WritePin(PINB,LOGIC_LOW);
	sei();


	u8 string[20] = {0};
	u8 counter1 = 0 ;
	u8 counter2 = 0 ;
	u8 flag = 1;
	u8 garbage = 0 ;
	while (1)
	{

		if ( SPI_ReceivePeriodic(string+counter1) )
		{
			if ( string[counter1] == 5 && send_flag && virtual_terminal_input[counter2] != 0 )
			{
				SPI_sendNoblock(virtual_terminal_input[counter2]) ;
				counter2++ ;
				DIO_WritePin(PINB,LOGIC_LOW);
				DIO_WritePin(PINB,LOGIC_HIGH);
			}
			else if ( string[counter1] != 0 )
			{
				counter1++ ;
			}
			else if ( string[counter1] == 0 )
			{
				counter1 = 0 ;
				LCD_Clear();
				LCD_WriteString(string);
			}


		}

		if ( send_flag )
		{
			garbage = SPI_Receive() ;
			result_flag = 1 ;
			garbage = SPI_SendReceive(virtual_terminal_input[0]);
			DIO_WritePin(PINB,LOGIC_LOW);
			//_delay_ms(1);
			DIO_WritePin(PINB,LOGIC_HIGH);

			send_flag = 0 ;
			for (u8 i=1;flag;i++)
			{
				garbage = SPI_SendReceive(virtual_terminal_input[i]);
				if ( virtual_terminal_input[i] == 0 )
				{
					flag = 0 ;
				}

			}

		}
	}
}
