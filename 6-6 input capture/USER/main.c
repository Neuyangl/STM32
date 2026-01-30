#include "stm32f10x.h"
#include "Led.h"
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"

uint16_t i;

int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	PWM_SetPrescaler(720-1);
	PWM_SetCompare1(50);

	while(1)
	{
		OLED_ShowNum(1,6,IC_GetFreq(),5);
	}
}
