#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void)
{
	PWM_Init();
}

void Servo_SetAngle(float angle)
{
	TIM_SetCompare2(TIM2,angle/180*2000+500);
}
