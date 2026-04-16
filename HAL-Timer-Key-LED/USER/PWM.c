#include "PWM.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "stm32f1xx_hal.h"
#include "stm32f103xb.h"
#include "stm32f1xx_hal_def.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>
#include <sys/_intsup.h>

void PWM_Init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
}

void PWM_SetCompare1(uint32_t Compare)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, Compare);
} 

void PWM_SetCompare2(uint32_t Compare)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, Compare);
} 

void PWM_SetCompare3(uint32_t Compare)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, Compare);
} 

