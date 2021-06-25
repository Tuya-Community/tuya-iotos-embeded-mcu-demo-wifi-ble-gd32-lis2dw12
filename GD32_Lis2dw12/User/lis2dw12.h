/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LIS2DW12_H
#define LIS2DW12_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Exported types ------------------------------------------------------------*/
/*register address*/
#define LIS2DW12_OUT_T_L		  	(0x0DU)
#define LIS2DW12_OUT_T_H		  	(0x0EU)

#define LIS2DW12_REG_WHO_AM_I		(0x0FU)

#define LIS2DW12_CTRL1				(0x20U)
#define LIS2DW12_CTRL2				(0x21U)
#define LIS2DW12_CTRL3				(0x22U)
#define LIS2DW12_CTRL4				(0x23U)
#define LIS2DW12_CTRL5				(0x24U)
#define LIS2DW12_CTRL6				(0x25U)

#define LIS2DW12_OUT_T				(0x26U)

#define LIS2DW12_CFG_STATUS		(0x27U)

#define LIS2DW12_OUT_X_L			(0x28U)
#define LIS2DW12_OUT_X_H			(0x29U)
#define LIS2DW12_OUT_Y_L			(0x2AU)
#define LIS2DW12_OUT_Y_H			(0x2BU)
#define LIS2DW12_OUT_Z_L			(0x2CU)
#define LIS2DW12_OUT_Z_H			(0x2DU)

#define LIS2DW12_FIFO_CTRL			(0x2EU)
#define LIS2DW12_FIFO_SAMPLES		(0x2FU)

#define LIS2DW12_TAP_THS_X			(0x30U)
#define LIS2DW12_TAP_THS_Y			(0x31U)
#define LIS2DW12_TAP_THS_Z			(0x32U)
#define LIS2DW12_INT_DUR			(0x33U)

#define LIS2DW12_WAKE_UP_THS		(0x34U)
#define LIS2DW12_WAKE_UP_DUR		(0x35U)

#define LIS2DW12_FREE_FALL			(0x36U)
#define LIS2DW12_STATUS_DUP			(0x37U)
#define LIS2DW12_WAKE_UP_SRC		(0x38U)
#define LIS2DW12_TAP_SRC			(0x39U)
#define LIS2DW12_SIXD_SRC			(0x3AU)

#define LIS2DW12_ALL_INT_SRC		(0x3BU)

#define LIS2DW12_X_OFS_USR			(0x3CU)
#define LIS2DW12_Y_OFS_USR			(0x3DU)
#define LIS2DW12_Z_OFS_USR			(0x3EU)

#define LIS2DW12_CTRL7				(0x3FU)

	
/*IIC slave address write and read*/
/*SD0 connect to power supply*/
#define LIS2DW12_ADDR_W_1			0x32U
#define LIS2DW12_ADDR_R_1			0x33U


/* Exported Functions --------------------------------------------------------*/
extern int Set_Reg_LIS2DW12(uint8_t add, uint8_t reg, uint8_t dat);
extern int Get_Reg_LIS2DW12(uint8_t add, uint8_t reg);
extern int Get_WHO_AM_I_LIS2DW12(void);
extern int Get_Status_LIS2DW12(void);
extern int Get_Status_LIS2DW12(void);
extern float Get_Temp_1_LIS2DW12(void);
extern signed char Get_Temp_2_LIS2DW12(void);
extern short Get_X_LIS2DW12(void);
extern short Get_Y_LIS2DW12(void);
extern short Get_Z_LIS2DW12(void);
extern void Init_LIS2DW12(void);

extern void Send_Uart_LIS2DW12(void);
extern void Read_Data_Deal(void);


#endif /* LIS2DW12_H */
