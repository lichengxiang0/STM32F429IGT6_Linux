#include "led.h"


void LED_Init(void)
{
	/* PB0 :LED1
	 * PB1 :LED0
	 *
	 *	 * */
	GPIO_InitTypeDef GPIO_Initure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);

	GPIO_Initure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	GPIO_Initure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Initure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Initure.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOB,&GPIO_Initure);

	GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_SET);	//PB0置1，默认初始化后灯灭
	GPIO_WriteBit(GPIOB,GPIO_Pin_1,Bit_SET);	//PB1置1，默认初始化后灯灭


}







