#include "stm32f10x.h"
#include "Led.h"
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "Encoder.h"

uint8_t Num;

int main(void)
{
	OLED_Init();
	
	OLED_ShowString(1,1,"Num:");
	
	while(1)
	{
		Num+=Encoder_Get();
		OLED_ShowSignedNum(1,5,Num,5);
	}
}
