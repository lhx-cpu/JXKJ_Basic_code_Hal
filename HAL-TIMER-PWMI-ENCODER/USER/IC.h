#ifndef __IC_H
#define __IC_H
#include "stm32f1xx_hal.h"

extern double period, pulseWidth, duty;

void IC_Run(void);

#endif
