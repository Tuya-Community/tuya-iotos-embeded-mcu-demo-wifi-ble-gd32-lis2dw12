# Tuya IoTOS Embedded Mcu Demo Wifi Ble GD32_Lis2dw12

[English](./README.md) | [中文](./README_zh.md)

## Introduction  

This Demo uses the Tuya smart cloud platform, Tuya smart APP, LIS2DW12and IoTOS Embedded MCU SDK to realize a acceleration acquisition.

The implemented features include:

+ Acceleration Acquisition


## Quick start  

### Compile & Burn
+ Download [Tuya IoTOS Embeded MCU sdk](https://registry.code.tuya-inc.top/hardware_developer/tuya-iotos-embeded-mcu-demo-4g-vending-machine/tree/master) 
+ Execute the Project.uvprojx file
+ Click Compile in the software and complete the download


### File introduction 

```
├── Application
│   ├── main.c
│   ├── gd32e23x_it.c
│   ├── systick.c
│   ├── gd32e23x_it.h
│   ├── systick.h
│   ├── gd32e23x_libopt.h
├── GD32E23x_Firmware_Library
│   ├── CMSIS
        ├── Include
           │   ├──gd32e23x.h
           │   ├──system_gd32e23x.h
        ├── Source
           │   ├──startup_gd32e23x.s
           │   ├──system_gd32e23x.h        
│   ├── GD32E23x_standard_peripheral
        ├── Include
        ├── Source
├──User
│   ├── connect_wifi.c
│   ├── delay.c
│   ├── delay.h
│   ├── led.c
│   ├── led.h
│   ├── lis2dw12.c
│   ├── lis2dw12.h
│   ├── myiic.c
│   ├── myiic.h
│   ├── usart.c
│   ├── usart.h
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

Entry file：main.c

Important functions：main()

+ Initialize and configure MCU IIC,USART,LIS2DW12 acceleration sensor, etc. All events are polled and judged in while(1)。




### DataPoint related

+ DP point processing: mcu_dp_value_update()

| function name | unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value) |
| ------------- | ------------------------------------------------------------ |
| dpid          | DP ID number                                                 |
| value         | DP data                                                      |
| Return        | SUCCESS: Success ERROR: Failure                              |



### I/O List  

|  LIS2DW12   |  UASRT0  | UASRT1  |
| :---------: | :------: | :-----: |
| PB0 IIC_SCL | PA9 TXD  | PA2 TXD |
| PB1 IIC_SDA | PA10 RXD | PA3 RXD |



## Related Documents

  Tuya Demo Center: https://developer.tuya.com/cn/demo/



## Technical Support

  You can get support for Tuya by using the following methods:

- Developer Center: https://developer.tuya.com/cn/
- Help Center: https://support.tuya.com/en/help
- Technical Support Work Order Center: [https://service.console.tuya.com](https://service.console.tuya.com/) 
