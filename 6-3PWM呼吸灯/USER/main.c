#include "stm32f10x.h"
#include "Led.h"
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "PWM.h"

uint16_t i;

int main(void)
{
	OLED_Init();
	PWM_Init();
	while(1)
	{
		for(i=0;i<=100;i++)
		{
			TIM_SetCompare1(TIM2,i);
			Delay_ms(10);
		}
		for(i=0;i<=100;i++)
		{
			TIM_SetCompare1(TIM2,100-i);
			Delay_ms(10);
		}
		
	}
}
