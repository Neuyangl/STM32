#include "stm32f10x.h"
#include "Led.h"
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
int16_t Speed;

int main(void)
{
	OLED_Init();
	Encoder_Init();
	OLED_ShowString(1,1,"speed:");
	
	Timer_Init();
	
	while(1)
	{
		OLED_ShowSignedNum(1,7,Encoder_Get(),5);
		Delay_ms(1000);
		
	}
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update))
	{
		Speed=Encoder_Get();
		
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
