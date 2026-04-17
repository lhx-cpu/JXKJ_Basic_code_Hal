#include "IC.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"
#include "stm32f1xx_hal.h"
#include "stm32f103xb.h"
#include "stm32f1xx_hal_def.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>
#include <sys/_intsup.h>

double period, pulseWidth, duty;

/**
  * 函    数：获取输入捕获的频率
  * 参    数：无
  * 返 回 值：
  * 注    意：这个要放在定时器初始化之后调用，且要在主循环内调用，好更新数据
  */
void IC_Run(void)
{
	//1.清楚CC1标志位
	__HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_CC1);
	//启动定时器
	HAL_TIM_IC_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_IC_Start(&htim2, TIM_CHANNEL_2);
	//等待CC1标志位并再次清除
	while(__HAL_TIM_GET_FLAG(&htim2, TIM_FLAG_CC1) == 0);
	__HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_CC1);
	//再次等待CC1标志位
	while(__HAL_TIM_GET_FLAG(&htim2, TIM_FLAG_CC1) == 0);
	//停止定时器
	HAL_TIM_IC_Stop(&htim2, TIM_CHANNEL_1);
	HAL_TIM_IC_Stop(&htim2, TIM_CHANNEL_2);
	//计算测量结果
	uint16_t ccr1 = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_1);
	uint16_t ccr2 = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_2);

	period = (ccr2 - ccr1) * 1e-6f;		//计算周期，单位为秒
	pulseWidth = ccr2 * 1e-6f;						//计算脉冲宽度，单位为秒
	duty = pulseWidth / period;						//计算占空比
}


