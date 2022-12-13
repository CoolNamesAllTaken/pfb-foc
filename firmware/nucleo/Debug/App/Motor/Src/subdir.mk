################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../App/Motor/Src/current_sensor.cc \
../App/Motor/Src/motor.cc \
../App/Motor/Src/motor_driver.cc 

CC_DEPS += \
./App/Motor/Src/current_sensor.d \
./App/Motor/Src/motor.d \
./App/Motor/Src/motor_driver.d 

OBJS += \
./App/Motor/Src/current_sensor.o \
./App/Motor/Src/motor.o \
./App/Motor/Src/motor_driver.o 


# Each subdirectory must supply rules for building sources it contributes
App/Motor/Src/%.o App/Motor/Src/%.su: ../App/Motor/Src/%.cc App/Motor/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DARM_MATH_CM7 -DDEBUG -c -I../App/Inc -I../App/Encoder/Inc -I../App/Motor/Inc -I../App/PIDController/Inc -I../App/Test/Inc -I../CMSIS/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Motor-2f-Src

clean-App-2f-Motor-2f-Src:
	-$(RM) ./App/Motor/Src/current_sensor.d ./App/Motor/Src/current_sensor.o ./App/Motor/Src/current_sensor.su ./App/Motor/Src/motor.d ./App/Motor/Src/motor.o ./App/Motor/Src/motor.su ./App/Motor/Src/motor_driver.d ./App/Motor/Src/motor_driver.o ./App/Motor/Src/motor_driver.su

.PHONY: clean-App-2f-Motor-2f-Src

