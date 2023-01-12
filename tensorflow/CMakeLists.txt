cmake_minimum_required(VERSION 3.16)
project(target-tensorflow LANGUAGES C CXX)

add_library(tensorflow STATIC "")

set (TF_INC
	  ${CMAKE_CURRENT_LIST_DIR}/
	  ${CMAKE_CURRENT_LIST_DIR}/../third_party/gemmlowp
	  ${CMAKE_CURRENT_LIST_DIR}/../third_party/flatbuffers/include
	  ${CMAKE_CURRENT_LIST_DIR}/../third_party/ruy
	  ${CMAKE_CURRENT_LIST_DIR}/../third_party/kissfft
	  ${CMAKE_CURRENT_LIST_DIR}/../third_party/cmsis
	  ${CMAKE_CURRENT_LIST_DIR}/../third_party/cmsis/CMSIS/NN/Include
	  ${CMAKE_CURRENT_LIST_DIR}/../third_party/cmsis/CMSIS/DSP/Include
)

target_include_directories(tensorflow 
  PUBLIC
  ${TF_INC}
)

target_include_directories(tensorflow PRIVATE
    ${TF_INC}
)

target_compile_definitions(
  tensorflow
  PUBLIC
  COMPILE_DEFINITIONS TF_LITE_STATIC_MEMORY
  # COMPILE_DEFINITIONS LINUX
  COMPILE_DEFINITIONS TF_LITE_USE_CTIME
)

set_target_properties(
  tensorflow
  PROPERTIES
  COMPILE_FLAGS -fno-rtti
  COMPILE_FLAGS -fno-exceptions
  COMPILE_FLAGS -fno-threadsafe-statics
  # COMPILE_FLAGS -nostdlib
  COMPILE_FLAGS -fno-unwind-tables
  COMPILE_FLAGS -ffunction-sections
  COMPILE_FLAGS -fdata-sections
  COMPILE_FLAGS -fmessage-length=0
)


file(GLOB_RECURSE SRC ${CMAKE_CURRENT_LIST_DIR}/*.c ${CMAKE_CURRENT_LIST_DIR}/*.cpp ${CMAKE_CURRENT_LIST_DIR}/*.cc ${CMAKE_CURRENT_LIST_DIR}/*.cxx ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.hpp ${CMAKE_CURRENT_LIST_DIR}/../third_party/*.c ${CMAKE_CURRENT_LIST_DIR}/../third_party/*.cpp ${CMAKE_CURRENT_LIST_DIR}/../third_party/*.cc ${CMAKE_CURRENT_LIST_DIR}/../third_party/*.cxx ${CMAKE_CURRENT_LIST_DIR}/../third_party/*.h ${CMAKE_CURRENT_LIST_DIR}/../third_party/*.hpp)
target_sources(tensorflow
  PRIVATE
  ${SRC}
)

target_link_libraries(tensorflow PRIVATE Drivers)
