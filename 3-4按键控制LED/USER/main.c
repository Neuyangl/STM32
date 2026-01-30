#include "stm32f10x.h"
#include "Led.h"
#include "Delay.h"
#include "Key.h"

uint8_t KeyNum;

int main(void)
{
	Led_Init();
	Key_Init();
	while(1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			Led_On();
		}
		if(KeyNum==2)
		{
			Led_Off();
		}
	}
}
