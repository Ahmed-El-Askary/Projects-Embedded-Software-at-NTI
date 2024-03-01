################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC_Driver/ADC.c 

OBJS += \
./MCAL/ADC_Driver/ADC.o 

C_DEPS += \
./MCAL/ADC_Driver/ADC.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/ADC_Driver/%.o: ../MCAL/ADC_Driver/%.c MCAL/ADC_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System" -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System\APP" -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System\HAL" -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System\HAL\LCD_Driver" -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System\MCAL\ADC_Driver" -I"G:\Yarab\NTI G10\Projects NTI\Battery System\Battery_System\MCAL\DIO_Driver" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


