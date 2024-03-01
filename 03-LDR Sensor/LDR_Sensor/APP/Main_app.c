/*
 ================================================================================================
 Name        : Main_app.c
 Author      : Ahmed El-Askary
 Description : LDR Sensor
 Date        : 24/6/2023
 ================================================================================================
 */
#include "DIO.h"
#include "ADC.h"
#include "LCD.h"

int main(void)
{
	u16 ADC_value;
	LCD_init();

	DDRD = 0xFF ;
	PORTD = 0x00 ;

	ADC_ConfigType ConfigType;
	ConfigType.ref_volt = AVCC;
	ConfigType.prescaler = F_CPU_16;
	ADC_ConfigType *Config_Ptr = &ConfigType;
	ADC_init(Config_Ptr);

	LCD_displayString("ADC Value = ");
	while(1)
	{
		ADC_value = ADC_readChannel(PIN0);

		LCD_moveCursor(1,5);
		LCD_intgerToString(ADC_value);
		LCD_displayString("    ");


		if (ADC_value <= 30)
		{
			PORTD = 0xFF ;
		}
		else if (ADC_value <= 90)
		{
			PORTD = 0x7F ;
		}
		else if (ADC_value <= 150)
		{
			PORTD = 0x3F ;

		}
		else if (ADC_value <= 250)
		{
			PORTD = 0x1F ;

		}
		else if (ADC_value <= 450)
		{
			PORTD = 0x0F ;

		}
		else if (ADC_value <= 600)
		{
			PORTD = 0x07 ;
		}

		else if (ADC_value <= 700)
		{
			PORTD = 0x03 ;

		}
		else if (ADC_value <= 900)
		{
			PORTD = 0x01 ;

		}
		else if (ADC_value <= 1000)
		{
			PORTD = 0x00 ;
		}
	}
}
