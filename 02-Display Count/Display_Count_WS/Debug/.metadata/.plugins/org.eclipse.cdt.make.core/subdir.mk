################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.make.core/specs.c 

OBJS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 

C_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 


# Each subdirectory must supply rules for building sources it contributes
.metadata/.plugins/org.eclipse.cdt.make.core/%.o: ../.metadata/.plugins/org.eclipse.cdt.make.core/%.c .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Yarab\NTI G10\Projects NTI\Display Count\Display_Count_WS" -I"G:\Yarab\NTI G10\Projects NTI\Display Count\Display_Count_WS\APP" -I"G:\Yarab\NTI G10\Projects NTI\Display Count\Display_Count_WS\HAL" -I"G:\Yarab\NTI G10\Projects NTI\Display Count\Display_Count_WS\LIBRARY" -I"G:\Yarab\NTI G10\Projects NTI\Display Count\Display_Count_WS\MCAL" -I"G:\Yarab\NTI G10\Projects NTI\Display Count\Display_Count_WS\MCAL\DIO_Driver" -I"G:\Yarab\NTI G10\Projects NTI\Display Count\Display_Count_WS\MCAL\EXT_Interrupt_Driver" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

