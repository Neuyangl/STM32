#include "stm32f10x.h"


//初始化PA0，高电平点亮
void Led_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}

//打开led
void Led_On(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
}


//关闭led
void Led_Off(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}
