#include "stm32f10x.h"
//#include "Led.h"
//#include "Delay.h"
//#include "Key.h"
#include "OLED.h"
#include "CounterSenser.h"

uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	CounterSenser_Init();
	OLED_ShowString(1,1,"count:");
	
	while(1)
	{
		OLED_ShowNum(1,7,CounterSenser_Get(),5);
	}
}
