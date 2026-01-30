#include "stm32f10x.h"                  // Device header


void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	// GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	// GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=100-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler=720-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitstructure;
	TIM_OCStructInit(&TIM_OCInitstructure);
	
	TIM_OCInitstructure.TIM_OCMode=TIM_OCMode_PWM1 ;
	TIM_OCInitstructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitstructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitstructure.TIM_Pulse=0;
	TIM_OC1Init(TIM2,&TIM_OCInitstructure);
	
	TIM_Cmd(TIM2,ENABLE);
}

void PWM_SetCompare(uint16_t Compare)
{
	TIM_SetCompare1(TIM2,Compare);
}

void PWM_SetPrescaler(uint16_t Prescaler)
{
	TIM_PrescalerConfig(TIM2,Prescaler,TIM_PSCReloadMode_Immediate);
}


