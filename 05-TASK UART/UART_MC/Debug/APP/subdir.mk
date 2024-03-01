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
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\05-TASK UART\UART_MC" -I"G:\Yarab\NTI G10\Projects NTI\05-TASK UART\UART_MC\MCAL\UART" -I"G:\Yarab\NTI G10\Projects NTI\05-TASK UART\UART_MC\APP" -I"G:\Yarab\NTI G10\Projects NTI\05-TASK UART\UART_MC\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\05-TASK UART\UART_MC\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\05-TASK UART\UART_MC\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\05-TASK UART\UART_MC\MCAL\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


