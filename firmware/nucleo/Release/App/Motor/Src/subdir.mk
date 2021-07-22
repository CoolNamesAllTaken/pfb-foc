################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../App/Motor/Src/current_sensor.cc \
../App/Motor/Src/half_bridge.cc \
../App/Motor/Src/motor.cc \
../App/Motor/Src/motor_driver.cc \
../App/Motor/Src/stspin830.cc 

CC_DEPS += \
./App/Motor/Src/current_sensor.d \
./App/Motor/Src/half_bridge.d \
./App/Motor/Src/motor.d \
./App/Motor/Src/motor_driver.d \
./App/Motor/Src/stspin830.d 

OBJS += \
./App/Motor/Src/current_sensor.o \
./App/Motor/Src/half_bridge.o \
./App/Motor/Src/motor.o \
./App/Motor/Src/motor_driver.o \
./App/Motor/Src/stspin830.o 


# Each subdirectory must supply rules for building sources it contributes
App/Motor/Src/current_sensor.o: ../App/Motor/Src/current_sensor.cc App/Motor/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Motor/Src/current_sensor.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Motor/Src/half_bridge.o: ../App/Motor/Src/half_bridge.cc App/Motor/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Motor/Src/half_bridge.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Motor/Src/motor.o: ../App/Motor/Src/motor.cc App/Motor/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Motor/Src/motor.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Motor/Src/motor_driver.o: ../App/Motor/Src/motor_driver.cc App/Motor/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Motor/Src/motor_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Motor/Src/stspin830.o: ../App/Motor/Src/stspin830.cc App/Motor/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Motor/Src/stspin830.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

