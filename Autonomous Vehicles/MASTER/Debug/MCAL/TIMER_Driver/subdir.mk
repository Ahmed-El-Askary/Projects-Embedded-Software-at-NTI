################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER_Driver/pwm.c \
../MCAL/TIMER_Driver/timer1.c 

OBJS += \
./MCAL/TIMER_Driver/pwm.o \
./MCAL/TIMER_Driver/timer1.o 

C_DEPS += \
./MCAL/TIMER_Driver/pwm.d \
./MCAL/TIMER_Driver/timer1.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER_Driver/%.o: ../MCAL/TIMER_Driver/%.c MCAL/TIMER_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\APP" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\HAL" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\HAL\Motor_Driver" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\HAL" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\MCAL\external_eeprom" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\MCAL\TIMER_Driver" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\MCAL\twi" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\MCAL\UART" -I"G:\Yarab\NTI G10\Projects NTI\07-CAR\CONTROL_ECU\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


