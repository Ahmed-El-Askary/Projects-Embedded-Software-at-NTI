/*
 ============================================================================
 Module      : External Interrupt
 File Name   : EXT_Interruptr.c
 Description : Header file for the AVR External Interrupt driver
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */
#include "EXT_Interrupt.h"


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

static void (*INT0_ptr) (void)=NULL_PTR;
static void (*INT1_ptr) (void)=NULL_PTR;
static void (*INT2_ptr) (void)=NULL_PTR;


/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
void GIE_Enable(void)
{
	SET_BIT(SREG,7);
}


void GIE_Disable(void)
{
	CLEAR_BIT(SREG,7);
}

void EXI_Init(void)
{
	EXI_TriggerEdge(EX_INT0,RISING);
	EXI_TriggerEdge(EX_INT1,RISING);
	EXI_TriggerEdge(EX_INT2,RISING);
}

void EXI_Enable(InterruptSource_types Interrupt)
{
	switch(Interrupt)
	{
	case EX_INT0:
		SET_BIT(GICR,INT0);
		break;

	case EX_INT1:
		SET_BIT(GICR,INT1);
		break;

	case EX_INT2:
		SET_BIT(GICR,INT2);
		break;

	}
}




void EXI_Disable(InterruptSource_types Interrupt)
{
	switch(Interrupt)
	{
	case EX_INT0:
		CLEAR_BIT(GICR,INT0);
		break;

	case EX_INT1:
		CLEAR_BIT(GICR,INT1);
		break;

	case EX_INT2:
		CLEAR_BIT(GICR,INT2);
		break;

	}
}


void EXI_TriggerEdge(InterruptSource_types Interrupt,Edge_type Edge)
{
	switch(Interrupt)
	{
	case EX_INT0:

		switch(Edge)
		{
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;

		case LOGIC_CHANGE:
			CLEAR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;

		case FALLING:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;

		case RISING:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;

		}
		break;

		case EX_INT1:

			switch(Edge)
			{
			case LOW_LEVEL:
				CLEAR_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;

			case LOGIC_CHANGE:
				CLEAR_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;

			case FALLING:
				CLEAR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;

			case RISING:
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;

			}
			break;

			case EX_INT2:

				switch(Edge)
				{

				case FALLING:
					CLEAR_BIT(MCUCSR,ISC2);
					break;

				case RISING:
					SET_BIT(MCUCSR,ISC2);
					break;

				default:
					CLEAR_BIT(MCUCSR,ISC2);

				}
				break;

	}
}

void EXI_SetCallBack(InterruptSource_types Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt)
	{
       case EX_INT0:
	   INT0_ptr = LocalPtr ;
	   break;

	   case EX_INT1:
	   INT1_ptr = LocalPtr ;
	   break;

	   case EX_INT2:
	   INT2_ptr = LocalPtr ;
	   break;
	}
}



ISR(INT0_vect)
{
	if ( INT0_ptr != NULL_PTR )
	{
		INT0_ptr();
	}
}



ISR(INT1_vect)
{
	if ( INT1_ptr != NULL_PTR )
	{
		INT1_ptr();
	}
}


ISR(INT2_vect)
{
	if ( INT2_ptr != NULL_PTR )
	{
		INT2_ptr();
	}
}
