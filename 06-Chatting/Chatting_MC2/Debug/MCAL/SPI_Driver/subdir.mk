################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SPI_Driver/SPI.c 

OBJS += \
./MCAL/SPI_Driver/SPI.o 

C_DEPS += \
./MCAL/SPI_Driver/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SPI_Driver/%.o: ../MCAL/SPI_Driver/%.c MCAL/SPI_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\HAL\LCD_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\APP" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\HAL" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\MCAL\SPI_Driver" -I"G:\Yarab\NTI G10\Projects NTI\06-Chatting\Chatting_MC2\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


