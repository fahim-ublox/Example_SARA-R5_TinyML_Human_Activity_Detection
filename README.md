* Build either using STM32CubeIDE or generate build configuration using CMake.
*Use following commands to build. 
- cmake -S . -B build/debug --warn-uninitialized -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_TOOLCHAIN_FILE=toolchain-STM32F407.cmake -GNinja
- cmake --build build/debug
