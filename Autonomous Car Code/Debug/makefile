################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MUSART/subdir.mk
-include MCAL/MTWI/subdir.mk
-include MCAL/MTIMER/subdir.mk
-include MCAL/MSPI/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HUS/subdir.mk
-include HAL/HSEVEN_SEG/subdir.mk
-include HAL/HSERVO/subdir.mk
-include HAL/HKPD/subdir.mk
-include HAL/HDCM/subdir.mk
-include HAL/HCLCD/subdir.mk
-include HAL/EEPROM/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Autonomous_Car_AMIT.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Autonomous_Car_AMIT.elf secondary-outputs

# Tool invocations
Autonomous_Car_AMIT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Autonomous_Car_AMIT.map -mmcu=atmega32 -o "Autonomous_Car_AMIT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Autonomous_Car_AMIT.lss: Autonomous_Car_AMIT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Autonomous_Car_AMIT.elf  >"Autonomous_Car_AMIT.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Autonomous_Car_AMIT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Autonomous_Car_AMIT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Autonomous_Car_AMIT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
