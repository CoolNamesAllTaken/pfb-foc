################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/DSP/Source/ComplexMathFunctions/ComplexMathFunctions.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c 

C_DEPS += \
./CMSIS/DSP/Source/ComplexMathFunctions/ComplexMathFunctions.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.d \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.d 

OBJS += \
./CMSIS/DSP/Source/ComplexMathFunctions/ComplexMathFunctions.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.o \
./CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.o 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/DSP/Source/ComplexMathFunctions/ComplexMathFunctions.o: ../CMSIS/DSP/Source/ComplexMathFunctions/ComplexMathFunctions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/ComplexMathFunctions.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.o: ../CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F722xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/DSP/PrivateInclude/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

