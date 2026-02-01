#include "stm32f10x.h"

void IC_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=65536-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler=72-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);

    TIM_ICInitTypeDef Tim_ICInitstructure;
    Tim_ICInitstructure.TIM_Channel=TIM_Channel_1;
    Tim_ICInitstructure.TIM_ICPolarity=TIM_ICPolarity_Rising;
    Tim_ICInitstructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
    Tim_ICInitstructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;
    Tim_ICInitstructure.TIM_ICFilter=0xF;
    TIM_ICInit(TIM3,&Tim_ICInitstructure);

    TIM_SelectInputTrigger(TIM3,TIM_TS_TI1FP1);
    TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_Reset);

    TIM_Cmd(TIM3,ENABLE);
}

uint32_t IC_GetFreq(void)
{
	uint32_t freq=0;
	uint16_t capture=TIM_GetCapture1(TIM3);
	if(capture!=0)
	{
		freq=1000000/(capture);
	}
	return freq;
}
/*
uint32_t IC_GetFreq()
{
    return 1000000/(TIM_GetCapture1(TIM3));
}
*/
