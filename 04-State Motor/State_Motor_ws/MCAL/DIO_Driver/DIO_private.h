/*
 ============================================================================
 Module      : DIO
 File Name   : DIO_private.h
 Description : Header file private for the AVR DIO driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#define PORTA  *((volatile u8*) 0x3B)
#define DDRA   *((volatile u8*) 0x3A)
#define PINA   *((volatile u8*) 0x39)

#define PORTB  *((volatile u8*) 0x38)
#define DDRB   *((volatile u8*) 0x37)
#define PINB   *((volatile u8*) 0x36)

#define PORTC  *((volatile u8*) 0x35)
#define DDRC   *((volatile u8*) 0x34)
#define PINC   *((volatile u8*) 0x33)

#define PORTD  *((volatile u8*) 0x32)
#define DDRD   *((volatile u8*) 0x31)
#define PIND   *((volatile u8*) 0x30)



#define PIN0 (u8)(0x00)
#define PIN1 (u8)(0x01)
#define PIN2 (u8)(0x02)
#define PIN3 (u8)(0x03)
#define PIN4 (u8)(0x04)
#define PIN5 (u8)(0x05)
#define PIN6 (u8)(0x06)
#define PIN7 (u8)(0x07)


#endif /* DIO_PRIVATE_H_ */
