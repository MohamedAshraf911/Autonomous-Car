################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HDCM/HDCM_Program.c 

OBJS += \
./HAL/HDCM/HDCM_Program.o 

C_DEPS += \
./HAL/HDCM/HDCM_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HDCM/%.o: ../HAL/HDCM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


