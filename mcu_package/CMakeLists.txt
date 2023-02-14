cmake_minimum_required(VERSION 3.16)
project(target-mcu-package LANGUAGES C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(mcu_package OBJECT 
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.c
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c
)

target_include_directories(mcu_package INTERFACE
    ${PROJECT_SOURCE_DIR}/Inc
    ${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/CMSIS/Include
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/CMSIS/Device/ST/STM32F4xx/Include
    ${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Inc
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
)

target_include_directories(mcu_package PRIVATE
    ${PROJECT_SOURCE_DIR}/Inc
    ${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/CMSIS/Include
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/CMSIS/Device/ST/STM32F4xx/Include
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Inc
	${PROJECT_SOURCE_DIR}/../STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
	${PROJECT_SOURCE_DIR}/../Core/Inc
)
