/*
 ============================================================================
 Module      : External Interrupt
 File Name   : EXT_Interrupt.h
 Description : Header file for the External Interrupt driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */

#ifndef EXT_INTERRUPT_DRIVER_EXT_INTERRUPT_H_
#define EXT_INTERRUPT_DRIVER_EXT_INTERRUPT_H_

#include "std_types.h"
#include "common_macros.h"
#include "EXT_Interrupt_config.h"
#include "EXT_Interrupt_praivte.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	LOW_LEVEL=0,
	LOGIC_CHANGE,
	FALLING,
	RISING,
}Edge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}InterruptSource_types;


/*******************************************************************************
 *                         Functions Prototypes                                   *
 *******************************************************************************/
void EXI_Init(void);
void EXI_Enable(InterruptSource_types Interrupt);
void EXI_Disable(InterruptSource_types Interrupt);
void EXI_TriggerEdge(InterruptSource_types Interrupt,Edge_type Edge);
void EXI_SetCallBack(InterruptSource_types Interrupt,void(*LocalPtr)(void));


void GIE_Enable(void);
void GIE_Disable(void);


#endif /* EXT_INTERRUPT_DRIVER_EXT_INTERRUPT_H_ */
