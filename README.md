# Tuya IoTOS Embedded Wi-Fi & Bluetooth LE Accelerometer

[English](./README.md) | [中文](./README_zh.md)

## Overview

In this demo, we will show you how to develop with the MCU SDK to enable an LIS2DW12 accelerometer to connect to the Tuya IoT Cloud with the Tuya Smart app.

Feature:

+ Collect acceleration




## Get started

### Compile and flash
+ Download Tuya IoTOS embedded code.

+ Run `Project.uvprojx`

+ Click **Compile** on the software to download the code.


### File introduction

```
├── Application
│   ├── main.c
│   ├── gd32e23x_it.c
│   ├── systick.c
│   ├── gd32e23x_it.h
│   ├── systick.h
│   ├── gd32e23x_libopt.h
├── GD32E23x_Firmware_Library
│   ├── CMSIS
        ├── Include
           │   ├──gd32e23x.h
           │   ├──system_gd32e23x.h
        ├── Source
           │   ├──startup_gd32e23x.s
           │   ├──system_gd32e23x.h        
│   ├── GD32E23x_standard_peripheral
        ├── Include
        ├── Source
├──User
│   ├── connect_wifi.c
│   ├── delay.c
│   ├── delay.h
│   ├── led.c
│   ├── led.h
│   ├── lis2dw12.c
│   ├── lis2dw12.h
│   ├── myiic.c
│   ├── myiic.h
│   ├── usart.c
│   ├── usart.h
└── MCU_SDK
    ├── mcu_api.c
    ├── mcu_api.h
    ├── protocol.c
    ├── protocol.h
    ├── system.c
    ├── system.h
    └── wifi.h

```



### Demo entry

Entry file: `main.c`

Main function: `main()`

+ Initialize the USART and I2C of the MCU as well as the LIS2DW12 accelerometer. All events are polled in `while(1)`.



### Data point (DP)

+ Process DP data: `mcu_dp_value_update()`

| Function name | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------ | ------------------------------------------------------------ |
| dpid | DP ID |
| value | DP data |
| Return | SUCCESS: DP data reporting succeeded. ERROR: DP data reporting failed. |



### Pin configuration

| LIS2DW12 | UASRT0 | UASRT1 |
| :---------: | :------: | :-----: |
| PB0 IIC_SCL | PA9 TXD | PA2 TXD |
| PB1 IIC_SDA | PA10 RXD | PA3 RXD |

## Reference

[Tuya Project Hub](https://developer.tuya.com/demo)



## Technical Support

You can get support from Tuya with the following methods:

- [Tuya IoT Developer Platform](https://developer.tuya.com/en/)
- [Help Center](https://support.tuya.com/en/help)
- [Service & Support](https://service.console.tuya.com)[](https://service.console.tuya.com/)
