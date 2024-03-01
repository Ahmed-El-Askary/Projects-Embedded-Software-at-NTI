/*
 ============================================================================
 Module      : DIO
 File Name   : DIO.h
 Description : Header file for the AVR DIO driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */

#ifndef DIO_H_
#define DIO_H_


#include "std_types.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "common_macros.h"


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}DIO_PinDirection;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0XFF
}DIO_PortDirection;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void DIO_setupPinDirection(u8 port_num , u8 pin_num , DIO_PinDirection direction ) ;
void DIO_writePin(u8 port_num , u8 pin_num , u8 value);
u8   DIO_readPin (u8 port_num , u8 pin_num);

void DIO_setupPortDirection(u8 port_num , DIO_PortDirection direction ) ;
void DIO_writePort(u8 port_num , u8 value);
u8   DIO_readPort (u8 port_num , u8 pin_num);


#endif /* DIO_H_ */

















