################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/MC1.c 

OBJS += \
./APP/MC1.o 

C_DEPS += \
./APP/MC1.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\APP" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\HAL" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\HAL\LCD_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\MCAL\EXT_Interrupt_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\MCAL\SPI_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\MCAL\UART" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC1\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


