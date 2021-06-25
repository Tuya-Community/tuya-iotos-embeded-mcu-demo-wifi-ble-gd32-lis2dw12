/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "lis2dw12.h"
#include "myiic.h"
#include "usart.h"
#include "protocol.h"
#include "mcu_api.h"
 
#define SENSITIVITY_2g    (0.244) /* mg */
static short acceleration[3]={0,0,0};

static int IIC_WrDat_LIS2DW12(uint8_t IIC_Add, uint8_t IIC_Reg, uint8_t IIC_Data);
static int IIC_Read_LIS2DW12(uint8_t IIC_Add, uint8_t IIC_Reg);


//LIS2DW12写
static int IIC_WrDat_LIS2DW12(uint8_t IIC_Add, uint8_t IIC_Reg, uint8_t IIC_Data)
{
	uint8_t ret_suc = 1;
	
	IIC_Start();
	IIC_Send_Byte(IIC_Add & 0xfe);
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}
	
	IIC_Send_Byte(IIC_Reg);			//write data
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}
	
	IIC_Send_Byte(IIC_Data);
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}	
	
	IIC_Stop();
	
	return 0;
}


//LIS2DW12读
static int IIC_Read_LIS2DW12(uint8_t IIC_Add, uint8_t IIC_Reg)
{
	int ret;
	uint8_t ret_suc = 1;
	
	IIC_Start();
	IIC_Send_Byte(IIC_Add & 0xfe);
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}
		
	IIC_Send_Byte(IIC_Reg);
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}
		
	IIC_Start();
	IIC_Send_Byte(IIC_Add | 0x01);
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}
	
    ret=IIC_Read_Byte(1);
	IIC_Stop();

	return ret;
}

//LIS2DW12读2个寄存器
static int IIC_Read2_LIS2DW12(uint8_t IIC_Add, uint8_t IIC_Reg)
{
	int ret;
	uint8_t ret_suc = 1;
	
	IIC_Start();
	IIC_Send_Byte(IIC_Add & 0xfe);
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}
		
	IIC_Send_Byte(IIC_Reg);
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}
		
	IIC_Start();
	IIC_Send_Byte(IIC_Add | 0x01);
	ret_suc = IIC_Wait_Ack();
	if(ret_suc == 1)	{IIC_Stop();return -1;}
	
    ret=IIC_Read_Byte(1);
	ret=(IIC_Read_Byte(0)<<8)|ret;
	
	IIC_Stop();

	return ret;
}

//设置寄存器
int Set_Reg_LIS2DW12(uint8_t add, uint8_t reg, uint8_t dat)
{
	int ret_succ = -1;
	uint8_t i = 20u;		//失败之后尝试的次数
	
	do{
		if(0 == IIC_WrDat_LIS2DW12(add, reg, dat))
		{
			ret_succ = 0;		//设置成功
			break;
		}
		else
		{
			i--;				//获取失败，再次尝试
		}
	}while(i>0u);
	
	return ret_succ;
}

//读取寄存器
int Get_Reg_LIS2DW12(uint8_t add, uint8_t reg)
{
	uint8_t i = 20u;
	int ret_get = -1;
	
	do{
		ret_get = IIC_Read_LIS2DW12(add, reg);
		if(-1 != ret_get)
		{
			break;				//获取数据成功
		}
		else
		{
			i--;				//获取失败，再次尝试
		}
	}while(i>0u);
	
	return ret_get;
}

//读取我是谁
int Get_WHO_AM_I_LIS2DW12(void)
{
	return Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_REG_WHO_AM_I);	
}


//获取状态寄存器
int Get_Status_LIS2DW12(void)
{
	return Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_CFG_STATUS);	
}

float Get_Temp_1_LIS2DW12(void)
{
	short temp_reg = (Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_T_H)<<8)|Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_T_L);
	float temp_cal = 0.0f;
	
	temp_cal = 25.0+temp_reg/16.0/16.0;
	
	return temp_cal;
}

signed char Get_Temp_2_LIS2DW12(void)
{
	return (25+(Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_T)));
}

short Get_X_LIS2DW12(void)
{
	return ((Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_X_H)<<8)|Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_X_L));
}

short Get_Y_LIS2DW12(void)
{
	return ((Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_Y_H)<<8)|Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_Y_L));
}

short Get_Z_LIS2DW12(void)
{
	return ((Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_Z_H)<<8)|Get_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_OUT_Z_L));
}

void Init_LIS2DW12(void)
{
	if(0 == Set_Reg_LIS2DW12(LIS2DW12_ADDR_W_1, LIS2DW12_CTRL1, 0x16))
	{
		printf("%s","IF_CTRL set successful\r\n");
	}
	else
	{
		printf("%s","IF_CTRL set fail\r\n");
	}
}

 void Read_Data_Deal(void)
  {		
    
		 float temp=0.0f;
		 temp=Get_Temp_1_LIS2DW12()*10;
		
		 /* Transorm LSB into mg @ 14 bit resolution*/
     acceleration[0] = (short)((Get_X_LIS2DW12()>>2)*SENSITIVITY_2g);
     acceleration[1] = (short )((Get_Y_LIS2DW12()>>2)*SENSITIVITY_2g);
     acceleration[2] = (short)((Get_Z_LIS2DW12()>>2)*SENSITIVITY_2g);
		
	   mcu_dp_value_update(DPID_TEMP_CURRENT,temp); //加速度计数据上报;
     mcu_dp_value_update(DPID_X_VALUE,acceleration[0]); //X轴加速度上报;
     mcu_dp_value_update(DPID_Y_VALUE,acceleration[1]); //Y轴加速度上报;
     mcu_dp_value_update(DPID_Z_VALUE,acceleration[2]); //Z轴加速度上报;
	}
//发送数据到串口
void Send_Uart_LIS2DW12(void)
{
	Read_Data_Deal();
	printf("%s","<-----------LIS2DW12--------->\r\n");		
	printf("X:%d | Y:%d | Z:%d\r\n",acceleration[0],acceleration[1],acceleration[2]);	
	printf("Temp:%.2f℃ | %d℃\r\n",Get_Temp_1_LIS2DW12(),Get_Temp_2_LIS2DW12());
	printf("Status:0x%X\r\n",Get_Status_LIS2DW12());				
	printf("Who_am_i:%X\r\n",Get_WHO_AM_I_LIS2DW12());			
	printf("%s","<--------LIS2DW12-END------->\r\n\n");			
}
