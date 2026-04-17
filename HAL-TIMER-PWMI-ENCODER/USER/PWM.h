#ifndef __PWM_H
#define __PWM_H
#include "stm32f1xx_hal.h"



void PWM_Init(void);
void PWM_SetCompare1(uint32_t Compare);

#endif /* __PWM_H */