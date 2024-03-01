################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/UART.c 

OBJS += \
./MCAL/UART/UART.o 

C_DEPS += \
./MCAL/UART/UART.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/%.o: ../MCAL/UART/%.c MCAL/UART/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\HAL\LCD_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\APP" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\HAL" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\MCAL\SPI_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


