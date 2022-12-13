################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../App/Encoder/Src/as5048a.cc \
../App/Encoder/Src/encoder.cc 

CC_DEPS += \
./App/Encoder/Src/as5048a.d \
./App/Encoder/Src/encoder.d 

OBJS += \
./App/Encoder/Src/as5048a.o \
./App/Encoder/Src/encoder.o 


# Each subdirectory must supply rules for building sources it contributes
App/Encoder/Src/%.o App/Encoder/Src/%.su: ../App/Encoder/Src/%.cc App/Encoder/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DARM_MATH_CM7 -DDEBUG -c -I../App/Inc -I../App/Encoder/Inc -I../App/Motor/Inc -I../App/PIDController/Inc -I../App/Test/Inc -I../CMSIS/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Encoder-2f-Src

clean-App-2f-Encoder-2f-Src:
	-$(RM) ./App/Encoder/Src/as5048a.d ./App/Encoder/Src/as5048a.o ./App/Encoder/Src/as5048a.su ./App/Encoder/Src/encoder.d ./App/Encoder/Src/encoder.o ./App/Encoder/Src/encoder.su

.PHONY: clean-App-2f-Encoder-2f-Src

