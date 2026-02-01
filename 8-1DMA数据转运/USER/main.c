#include "stm32f10x.h"
#include "Led.h"
#include "Delay.h"
#include "Key.h"
#include "OLED.h"

uint8_t DataA[]={0x01,0x02,0x03,0x04};
uint8_t DataB[]={0,0,0,0};

int main(void)
{
	OLED_Init();
	

	
	OLED_ShowHexNum(2,1,(uint32_t)&ADC1->DR,8);
	while(1)
	{
		
	}
}
