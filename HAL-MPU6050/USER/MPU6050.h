#ifndef __MPU6050_H
#define __MPU6050_H

#include "stm32f1xx_hal.h"

uint8_t MPU6050_IsReady(void);
void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data);
void MPU6050_WriteRegs(uint8_t RegAddress, uint8_t *Data, uint16_t Size );  //注意不和JKD兼容
uint8_t MPU6050_ReadReg(uint8_t RegAddress);
uint8_t MPU6050_GetID(void);

void MPU6050_Init(void);
uint8_t MPU6050_GetID(void);
void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ, 
						int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ);

#endif
