################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../App/Test/Src/test_current_sensor.cc \
../App/Test/Src/test_encoder.cc \
../App/Test/Src/test_foc_utils.cc \
../App/Test/Src/test_half_bridge.cc \
../App/Test/Src/test_motor_driver.cc \
../App/Test/Src/test_pid_controller.cc 

CC_DEPS += \
./App/Test/Src/test_current_sensor.d \
./App/Test/Src/test_encoder.d \
./App/Test/Src/test_foc_utils.d \
./App/Test/Src/test_half_bridge.d \
./App/Test/Src/test_motor_driver.d \
./App/Test/Src/test_pid_controller.d 

OBJS += \
./App/Test/Src/test_current_sensor.o \
./App/Test/Src/test_encoder.o \
./App/Test/Src/test_foc_utils.o \
./App/Test/Src/test_half_bridge.o \
./App/Test/Src/test_motor_driver.o \
./App/Test/Src/test_pid_controller.o 


# Each subdirectory must supply rules for building sources it contributes
App/Test/Src/test_current_sensor.o: ../App/Test/Src/test_current_sensor.cc App/Test/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Test/Src/test_current_sensor.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Test/Src/test_encoder.o: ../App/Test/Src/test_encoder.cc App/Test/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Test/Src/test_encoder.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Test/Src/test_foc_utils.o: ../App/Test/Src/test_foc_utils.cc App/Test/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Test/Src/test_foc_utils.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Test/Src/test_half_bridge.o: ../App/Test/Src/test_half_bridge.cc App/Test/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Test/Src/test_half_bridge.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Test/Src/test_motor_driver.o: ../App/Test/Src/test_motor_driver.cc App/Test/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Test/Src/test_motor_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Test/Src/test_pid_controller.o: ../App/Test/Src/test_pid_controller.cc App/Test/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F722xx '-D__FPU_PRESENT=1' '-D__FPU_USED=1' -c -I"/Users/jkailimcnelly/Box Sync/Projects/pfb-foc/firmware/nucleo/App" -I../App/Motor/Inc -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -I"Y:/git-checkouts/pfb-foc/firmware/nucleo/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/Test/Src/test_pid_controller.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

