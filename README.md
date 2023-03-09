# TinyML firmware using u-blox product and libraries
## Description
You can use tensorflow lite for microcontroller using u-blox products. This project is being added to help u-blox customers for rapid prototyping and evaluating u-blox products. This repository is tested using C030-R412M board and Sparkfun's Asset tracker Micromod setup using STM32F405 microcontroller.

* Build using build configuration through CMake.
* Use following commands to build the firmware. 

- cmake -S . -B build/debug --warn-uninitialized -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_TOOLCHAIN_FILE=toolchain-STM32F405.cmake -GNinja
- cmake --build build/debug

Drag and drop hex file.

