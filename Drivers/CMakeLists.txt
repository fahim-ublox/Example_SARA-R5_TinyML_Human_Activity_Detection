cmake_minimum_required(VERSION 3.16)
project(target-Drivers LANGUAGES C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(Drivers OBJECT 
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
)

target_include_directories(Drivers INTERFACE
    ${PROJECT_SOURCE_DIR}/CMSIS/Include
	${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32F4xx/Include
    ${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Inc
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Inc/Legacy
)

target_include_directories(Drivers PRIVATE
    ${PROJECT_SOURCE_DIR}/CMSIS/Include
	${PROJECT_SOURCE_DIR}/CMSIS/Device/ST/STM32F4xx/Include
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Inc
	${PROJECT_SOURCE_DIR}/STM32F4xx_HAL_Driver/Inc/Legacy
	${PROJECT_SOURCE_DIR}/../Core/Inc
)
