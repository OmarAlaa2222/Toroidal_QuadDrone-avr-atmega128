################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC_program.c \
../MCAL/DIO_program.c \
../MCAL/I2C_Master_C_file.c \
../MCAL/Timer_program.c \
../MCAL/UART_Program.c 

OBJS += \
./MCAL/ADC_program.o \
./MCAL/DIO_program.o \
./MCAL/I2C_Master_C_file.o \
./MCAL/Timer_program.o \
./MCAL/UART_Program.o 

C_DEPS += \
./MCAL/ADC_program.d \
./MCAL/DIO_program.d \
./MCAL/I2C_Master_C_file.d \
./MCAL/Timer_program.d \
./MCAL/UART_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


