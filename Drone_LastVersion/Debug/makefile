################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
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
Drone_LastVersion.lss \

FLASH_IMAGE += \
Drone_LastVersion.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Drone_LastVersion.elf secondary-outputs

# Tool invocations
Drone_LastVersion.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Drone_LastVersion.map -mmcu=atmega128 -o "Drone_LastVersion.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Drone_LastVersion.lss: Drone_LastVersion.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Drone_LastVersion.elf  >"Drone_LastVersion.lss"
	@echo 'Finished building: $@'
	@echo ' '

Drone_LastVersion.hex: Drone_LastVersion.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Drone_LastVersion.elf  "Drone_LastVersion.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Drone_LastVersion.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 Drone_LastVersion.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Drone_LastVersion.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
