#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "led.h"
#include "tick.h"
#include "sys.h"
void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 500000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

int main(void)
{
	LED_Init();

//	GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_RESET);	//PB0置1，默认初始化后灯灭
//	GPIO_WriteBit(GPIOB,GPIO_Pin_1,Bit_SET);	//PB1置1，默认初始化后灯灭


	while(1)
	{
#if 0
		GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_SET);	//PB0置1，默认初始化后灯灭
		GPIO_WriteBit(GPIOB,GPIO_Pin_1,Bit_SET);	//PB1置1，默认初始化后灯灭
		delay();
		GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_RESET);	//PB0置1，默认初始化后灯灭
		GPIO_WriteBit(GPIOB,GPIO_Pin_1,Bit_RESET);	//PB1置1，默认初始化后灯灭
		delay();
#endif
		LED0 = !LED0;
		LED1 = !LED1;
		delay();

	}
	return 0;
}






