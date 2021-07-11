################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f722zetx.s 

S_DEPS += \
./Core/Startup/startup_stm32f722zetx.d 

OBJS += \
./Core/Startup/startup_stm32f722zetx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/startup_stm32f722zetx.o: ../Core/Startup/startup_stm32f722zetx.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc -I../Drivers/CMSIS/Include -I/nucleo/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -x assembler-with-cpp -MMD -MP -MF"Core/Startup/startup_stm32f722zetx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

