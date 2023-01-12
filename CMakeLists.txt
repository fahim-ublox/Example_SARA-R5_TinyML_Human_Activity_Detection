cmake_minimum_required(VERSION 3.16)
project(target-cortexm LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

option(USE_RTOS "Enable RTOS support" OFF)

message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

add_compile_options(
    -Wall
    -Wextra
    -Wconversion
    -Wsign-conversion
    $<$<CONFIG:DEBUG>:-g3>
    $<$<CONFIG:DEBUG>:-Og>
    $<$<CONFIG:RELEASE>:-O3>  
)

add_compile_definitions(
  $<$<CONFIG:DEBUG>:DEBUG>
  $<$<BOOL:${USE_RTOS}>:RTOS>
)

add_executable(Application 
    ${CMAKE_SOURCE_DIR}/Core/Src/main.cpp
    ${CMAKE_SOURCE_DIR}/Core/Src/model_tflite.cc
	${CMAKE_SOURCE_DIR}/Core/Src/debug_log.c
    ${CMAKE_SOURCE_DIR}/Core/Src/stm32f4xx_hal_msp.c
    ${CMAKE_SOURCE_DIR}/Core/Src/stm32f4xx_it.c
    ${CMAKE_SOURCE_DIR}/Core/Src/syscalls.c
    ${CMAKE_SOURCE_DIR}/Core/Src/sysmem.c
    ${CMAKE_SOURCE_DIR}/Core/Src/system_stm32f4xx.c
    ${CMAKE_SOURCE_DIR}/Core/Startup/startup_stm32f437vgtx.s
)

target_include_directories(Application PRIVATE
  ${CMAKE_SOURCE_DIR}/Core/Src
  ${CMAKE_SOURCE_DIR}/Core/Inc
)

set(LINKER_SCRIPTS 
    ${CMAKE_SOURCE_DIR}/STM32F437VGTX_FLASH.ld
    #${CMAKE_SOURCE_DIR}/STM32F437VGTX_RAM.ld
)

set_target_properties(Application PROPERTIES
    SUFFIX .elf
    LINK_DEPENDS "${LINKER_SCRIPTS}"
)

target_link_options(Application PRIVATE
  -T${CMAKE_SOURCE_DIR}/STM32F437VGTX_FLASH.ld
  #-T${CMAKE_SOURCE_DIR}/STM32F437VGTX_RAM.ld
  LINKER:--print-memory-usage
  LINKER:-Map,${CMAKE_CURRENT_BINARY_DIR}/Application.map
)

if (IS_DIRECTORY ${CMAKE_SOURCE_DIR}/Drivers)
  add_subdirectory(${CMAKE_SOURCE_DIR}/Drivers)
  target_link_libraries(Application PRIVATE Drivers)
endif()

if (IS_DIRECTORY ${CMAKE_SOURCE_DIR}/tensorflow)
  add_subdirectory(${CMAKE_SOURCE_DIR}/tensorflow)
  target_link_libraries(Application PRIVATE tensorflow)
endif()

if (EXISTS ${TOOLCHAIN_COPY})
  add_custom_command(
    TARGET Application
    POST_BUILD
    COMMAND ${TOOLCHAIN_COPY} -O ihex $<TARGET_FILE:Application> 
            ${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:Application>.hex
  )
else()
  message(STATUS "'objcopy' not found: cannot generate .hex file")
endif()

if (EXISTS ${TOOLCHAIN_SIZE})
  add_custom_command(
    TARGET Application
    POST_BUILD
    COMMAND ${TOOLCHAIN_SIZE} $<TARGET_FILE:Application> 
  )
else()
  message(STATUS "'objcopy' not found: cannot generate .hex file")
endif()

if (EXISTS "${TOOLCHAIN_SIZE}")
  add_custom_command(
    TARGET Application
    POST_BUILD
    COMMAND ${TOOLCHAIN_SIZE} --format=berkeley $<TARGET_FILE:Application> 
            >${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:Application>.bsz
  )

  add_custom_command(
    TARGET Application
    POST_BUILD
    COMMAND ${TOOLCHAIN_SIZE} --format=sysv -x $<TARGET_FILE:Application> 
            >${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:Application>.ssz
  )
else()
  message(STATUS "'size' not found: cannot generate .[bs]sz files")
endif()
