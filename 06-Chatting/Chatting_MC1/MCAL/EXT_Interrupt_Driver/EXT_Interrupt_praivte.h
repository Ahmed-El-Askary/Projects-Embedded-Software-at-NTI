/*
 ============================================================================
 Module      : External Interrupt
 File Name   : EXT_Interrupt_praivte.h
 Description : Header file for the AVR External Interrupt driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */
#ifndef EXT_INTERRUPT_DRIVER_EXT_INTERRUPT_PRAIVTE_H_
#define EXT_INTERRUPT_DRIVER_EXT_INTERRUPT_PRAIVTE_H_

#define  SREG       *((volatile unsigned char*)0x5F)


#define MCUCSR      (*(volatile unsigned char*)0x54)
#define ISC2         6

#define MCUCR       (*(volatile unsigned char*)0x55)
#define ISC00        0
#define ISC01        1
#define ISC10        2
#define ISC11        3

#define GICR        (*(volatile unsigned char*)0x5B)
#define INT1         7
#define INT0         6
#define INT2         5

#define GIFR        (*(volatile unsigned char*)0x5A)
#define INTF1        7
#define INTF0        6
#define INTF2        5


#define INT0_vect		     	__vector_1
#define INT1_vect		    	__vector_2
#define INT2_vect		    	__vector_3
#define TIMER2_COMP_vect		__vector_4
#define TIMER2_OVF_vect			__vector_5
#define TIMER1_ICU_vect		    __vector_6
#define TIMER1_OCA_vect		    __vector_7
#define TIMER1_OCB_vect		    __vector_8
#define TIMER1_OVF_vect			__vector_9
#define TIMER0_OC_vect		    __vector_10
#define TIMER0_OVF_vect			__vector_11
#define SPI_STC_vect			__vector_12
#define UART_RX_vect			__vector_13
#define UART_UDRE_vect			__vector_14
#define UART_TX_vect			__vector_15
#define ADC_vect			    __vector_16
#define EE_RDY_vect		 	    __vector_17
#define ANA_COMP_vect			__vector_18
#define TWI_vect			    __vector_19
#define SPM_RDY_vect			__vector_20
#  define BAD_vect        __vector_default


#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)





#endif /* EXT_INTERRUPT_DRIVER_EXT_INTERRUPT_PRAIVTE_H_ */
