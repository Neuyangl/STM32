/**
******************************************************************************
  * @file        main.c
  * @author      YangLei
  * @version     v1.0.0
  * @date        2026-01-26
  * @brief       This file provides all the ... functions.
  * @attention   
  * None
 ******************************************************************************
 */
   
#include "stm32f10x.h"
//#include "Led.h"
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
//#include "PWM.h"
#include "Motor.h"

uint8_t KeyNum;

int8_t speed;
 

int main(void)
{
	OLED_Init();
	Motor_Init();
	Key_Init();
	OLED_ShowString(1,1,"speed:");
	while(1)
	{
        
		KeyNum=Key_GetNum();
       
		if(KeyNum==1)
		{
            
			speed+=20;
           
			if(speed>100)
			{
				speed=-100;
			}
		}
		Motor_SetSpeed(speed);
		OLED_ShowSignedNum(1,7,speed,3);
	}
}
