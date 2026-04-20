/* Key.c 有一个Bug？只需要Key1的话，必须要注释掉Key2的判断语句，否则无法运行*/
/* 也就是说能配置的GPIO通道要和实际的按键连接一致 ！！！*/


#include "Key.h"

uint8_t Key_Num;

uint8_t Key_GetNum(void)
{
	uint8_t Temp;
	if (Key_Num)
	{
		Temp = Key_Num;
		Key_Num = 0;
		return Temp;
	}
	return 0;
}

uint8_t Key_GetState(void)
{
	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET)
	{
		return 1;
	}
	// 不需要，这里我就注释掉了，否则无法运行
	// if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == GPIO_PIN_RESET)
	// {
	// 	return 2;
	// }
	return 0;
}

void Key_Tick(void)
{
	static uint8_t Count;
	static uint8_t CurrState, PrevState;
	
	Count ++;
	if (Count >= 10)
	{
		Count = 0;
		
		PrevState = CurrState;
		CurrState = Key_GetState();
		
		if (CurrState == 0 && PrevState != 0)
		{
			Key_Num = PrevState;
		}
	}
}
