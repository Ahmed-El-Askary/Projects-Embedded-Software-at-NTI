/*
 ================================================================================================
 Name        : Main_app.c
 Author      : Ahmed El-Askary.
 Description : Battery System
 Date        : 24/10/2023.
 ================================================================================================
 */

#include "std_types.h"
#include "common_macros.h"
#include "ADC.h"
#include "LCD.h"
#include "DIO.h"
#include "util/delay.h"



u16 Mapping_u16Lcd(u16 x , u16 x1 , u16 x2 , u16 y1 , u16 y2)
{
	u16 y ;
	y = ((u32) ((x-x1)*(y2-y1)) / (x2-x1)) +y1 ;
	return y ;

}


int main(void)
{
	u16 ADC_value; u16 battery_level ; u16 Percetage ;
	LCD_init();
	DIO_setupPinDirection(PORTC_ID, PIN4, PIN_OUTPUT);
	DIO_setupPinDirection(PORTA_ID, PIN3, PIN_OUTPUT);


	ADC_ConfigType ConfigType;
	ConfigType.ref_volt = AVCC;
	ConfigType.prescaler = F_CPU_16;
	ADC_ConfigType *Config_Ptr = &ConfigType;
	ADC_init(Config_Ptr);

	while(1)
	{
		ADC_value = ADC_readChannel(0);
		battery_level = Mapping_u16Lcd (ADC_value , 0 , 1023 , 0 , 16);
		Percetage = Mapping_u16Lcd(battery_level , 0 , 16 , 0 , 100);
		LCD_moveCursor(0, 0);
		for ( u8 i = 0 ; i< battery_level ; i++)
		{
			LCD_displayCharacter(0xFF);

		}
		LCD_displayString("                ");
		LCD_moveCursor(1, 0);
		LCD_displayString("Battery = ");
		LCD_intgerToString(Percetage);
		LCD_displayString("%");
		LCD_displayString("                ");
		_delay_ms(500);

		if (battery_level == 0 )
		{
			SET_BIT(PORTC , PIN4);
		}
		else
		{
			CLEAR_BIT(PORTC, PIN4);
		}

		if (Percetage == 100 )
		{
			SET_BIT(PORTC , PIN3);
		}
		else
		{
			CLEAR_BIT(PORTC, PIN3);
		}

	}
}

