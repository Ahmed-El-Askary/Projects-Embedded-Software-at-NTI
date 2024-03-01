################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Main_app.c 

OBJS += \
./APP/Main_app.o 

C_DEPS += \
./APP/Main_app.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws" -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws\MCAL\EXT_Interrupt_Driver" -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws\HAL\Motor_Driver" -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws\APP" -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws\MCAL\EXT_Interrupt_Driver" -I"G:\Yarab\NTI G10\Projects NTI\State Motor\State_Motor_ws\MCAL\EXT_Interrupt_Driver" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


