#include "gd32e23x.h"
#include "systick.h"
#include <stdio.h>

#include <led.h>
#include <delay.h>
#include <usart.h>
#include <wifi.h>

#include "myiic.h"
#include "lis2dw12.h"


uint32_t USART0_RECEIVE_Buf[100]; 
uint32_t USART1_RECEIVE_Buf[100]; 
extern void Connect_Wifi(void);

int main(void)
{
    systick_config();   
		LED_Init();  
	  wifi_protocol_init();//wifi协议初始化
		USART0_Init();
		USART1_Init();
	  IIC_Init();		
    Init_LIS2DW12(); 
	
 while(1)
		{
			Connect_Wifi(); //配网
			Read_Data_Deal();//加速度计数据处理
			wifi_uart_service();//wifi串口数据处理服务
    }
}
