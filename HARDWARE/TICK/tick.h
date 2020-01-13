#ifndef __TICK_H__
#define __TICK_H__

#include "stm32f4xx.h"

void tick_delay_init(uint8_t SYSCLK);
void delay_us(uint32_t nus);
void delay_ms(uint16_t nms);



#endif




