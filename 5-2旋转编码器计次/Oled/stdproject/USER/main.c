#include "stm32f10x.h"

int main(void)
{
	//GPIOA Enable
	RCC->APB2ENR=0X0000004;
	GPIOA->CRL=0X00000003;
	//GPIOA outputs low level
	GPIOA->ODR=0X00000000;
	while(1)
	{
	}
}
