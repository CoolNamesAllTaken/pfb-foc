################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
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
App/Encoder/Src/as5048a.o: ../App/Encoder/Src/as5048a.cc App/Encoder/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Encoder/Src/as5048a.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Encoder/Src/encoder.o: ../App/Encoder/Src/encoder.cc App/Encoder/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Encoder/Src/encoder.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

