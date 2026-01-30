#include "stm32f10x.h"
#include "Led.h"
#include "Delay.h"
#include "Key.h"
#include "Buzzer.h"
#include "Lightsensor.h"

uint8_t KeyNum;

int main(void)
{
	
	Buzzer_Init();
	Lightsensor_Init();
	while(1)
	{
		if(Lightsensor_Get()==1)
		{
			Buzzer_On();
		}
		else
		{
			Buzzer_Off();
		}
	}
	
}
