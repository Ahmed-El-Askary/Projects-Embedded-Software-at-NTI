################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_Driver/LCD.c 

OBJS += \
./HAL/LCD_Driver/LCD.o 

C_DEPS += \
./HAL/LCD_Driver/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_Driver/%.o: ../HAL/LCD_Driver/%.c HAL/LCD_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\LDR Sensor\LDR_Sensor" -I"G:\Yarab\NTI G10\Projects NTI\LDR Sensor\LDR_Sensor\APP" -I"G:\Yarab\NTI G10\Projects NTI\LDR Sensor\LDR_Sensor\HAL" -I"G:\Yarab\NTI G10\Projects NTI\LDR Sensor\LDR_Sensor\HAL\LCD_Driver" -I"G:\Yarab\NTI G10\Projects NTI\LDR Sensor\LDR_Sensor\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\LDR Sensor\LDR_Sensor\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\LDR Sensor\LDR_Sensor\MCAL\ADC_Driver" -I"G:\Yarab\NTI G10\Projects NTI\LDR Sensor\LDR_Sensor\MCAL\DIO_Driver" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


