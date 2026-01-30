#include "stm32f10x.h"
#include "Led.h"
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"

uint8_t KeyNum;
float angle;

int main(void)
{
	OLED_Init();
	Servo_Init();
	Key_Init();
	OLED_ShowString(1,1,"Angle:");
	while(1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			angle+=30;
			if(angle>180)
			{
				angle=0;
			}
		}
		Servo_SetAngle(angle);
		OLED_ShowNum(1,7,angle,4);
	}
}
