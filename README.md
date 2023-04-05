# Human Activity Detection using Machine Learning Cascade Architecure by using TensorFlow lite for microcontrolers, u-blox cellular product and libraries. 
## Description
You can use detect human activity using TensorFlow lite for microcontroller. By using u-blox cellular products & libraries, you can send data from remote devices to your server where a bigger model is deployed, hence human activity can be detected in better way in this **ML Cascade Architecture**. This project is being added to help u-blox customers for rapid prototyping and evaluating u-blox products. This repository is tested using C030-R412M board and Sparkfun's Asset tracker Micromod setup using STM32F405 microcontroller.

This repo uses Git submodules: make sure that once it has been cloned you do something like:
```sh
git submodule update --init --recursive
```

**Note-1** : You may need to add servers details or set your own URI, if you want to transfer data to cloud.
**Note-2** : If you want to add your own accelerometer then remove +20 test data of accelerometer and feed accelerometer data to Model at 20 Hz to get inference.
**Note-3** : By default only classified accelerometer test data are being feed to model in this firmware.  

### Build using build configuration through CMake.
Use following two commands to build the firmware.

```sh
cmake -S . -B build/debug --warn-uninitialized -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_TOOLCHAIN_FILE=toolchain-STM32F405.cmake -GNinja
```
```sh
cmake --build build/debug
```
Flash the hex file & start executing the firmware. It is a ready to build and execute example. 
**You should build and run this example firmware in 10 minutes if you are not doing something wrong!** 

### Hardware requirements
| HW type | Name |
| ------ | ------ |
| Carrier Board | SparkFun MicroMod Asset Tracker |
| Application board | MicroMod_STM32_Processor |
| Cellular | SARA-R5 Module |
| Microcontroller | STM32F405RGT6 |

### Build requirements
| Toolchain or Build Software | Version |
| ------ | ------ |
| CMake | 3.25.1 |
| Ninja | 1.11.1 |
| GNU Tools for ARM Embedded Processors | 6-2017-q2-update |

### Memory requirements of Firmware
| Memory region |  Used Size   |	Region Size 	|	%age Used |
| ------ | ------ | ------ |  ------  | 
| CCMRAM        |  36 B        |		64 KB      	|	0.05%     |
| RAM       	  |  80320 B     |  	128 KB     	|	61.28%   |
| FLASH      	  |  497560 B    |  	1 MB     	|	47.45%    |


