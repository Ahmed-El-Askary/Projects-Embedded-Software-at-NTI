################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/main_HMI.c 

OBJS += \
./APP/main_HMI.o 

C_DEPS += \
./APP/main_HMI.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\APP" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\HAL" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\HAL\KEYPAD_Driver" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\HAL\LCD_Driver" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\MCAL\TIMER_Driver" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\HMI_ECU\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


