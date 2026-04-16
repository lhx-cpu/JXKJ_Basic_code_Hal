#include "Motor.h"
#include "PWM.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "stm32f1xx_hal.h"
#include "stm32f103xb.h"
#include "stm32f1xx_hal_def.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>
#include <sys/_intsup.h>

//前面就声明了PWM了，这里就不用，后面需要时再改
// Motor_Init(void)
// {
//     PWM_Init();
// }

void Motor_SetSpeed(int16_t Speed)
{
	//正转
	if (Speed >= 0)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		
		PWM_SetCompare1(Speed);
	}
	//反转
	if (Speed < 0)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
		
		PWM_SetCompare1(-Speed);
	}
}