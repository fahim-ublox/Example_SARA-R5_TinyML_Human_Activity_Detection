* Build either using STM32CubeIDE or generate build configuration using CMake.
* Use following commands to build the firmware. 

->  cmake -S . -B build/debug --warn-uninitialized -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_TOOLCHAIN_FILE=toolchain-STM32F437.cmake -GNinja
->  cmake --build build/debug
