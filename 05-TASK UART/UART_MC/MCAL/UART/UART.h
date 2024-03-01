/*
 ============================================================================
 Module      : UART
 File Name   : UART_config.h
 Description : Header file configuration for the AVR UART driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */

#ifndef UART_UART_H_
#define UART_UART_H_

#include "std_types.h"
#include "common_macros.h"
#include "UART_config.h"
#include "UART_private.h"


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	BIT_5 , BIT_6 , BIT_7 , BIT_8 , BIT_9 = 7
}UART_BitData;

typedef enum{
	DISABLED_PARITY = 0 , EVEN_PARITY = 2 , ODD_PARITY
}UART_Parity;

typedef enum{
	STOP_ONE_BIT,STOP_TWO_BIT
}UART_StopBit;

typedef u16 UART_BaudRate;

typedef struct{
	UART_BitData bit_data;
	UART_Parity parity;
	UART_StopBit stop_bit;
	UART_BaudRate baud_rate;
}UART_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void UART_init(const UART_ConfigType * Config_Ptr);

void UART_sendByte(const u8 data);

u8 UART_recieveByte(void);


void UART_sendString(const u8 *Str);

void UART_receiveString(u8 *Str);

#endif /* UART_UART_H_ */
