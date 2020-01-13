#include "tick.h"


static uint32_t fac_us = 0;


/*!
 * @brief Tick timer init
 *
 * The function init tick clock
 *
 * @param system clock (MHz)
 * */
void tick_delay_init(uint8_t SYSCLK)
{

	  SysTick->CTRL  |= 0x00000004 | SysTick_CTRL_TICKINT_Msk;
	  fac_us = SYSCLK;
}


/*!
 * @brief Tick delay us
 *
 * The function delay us.
 *
 * @param delay us
 * */
void delay_us(uint32_t nus)
{
	uint32_t ticks = nus*fac_us;

	SysTick->CTRL = 0;
	SysTick->LOAD = (uint32_t)(ticks - 1UL);
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	while( (SysTick->CTRL&0x00010000)==0 );
	SysTick->CTRL = 0;

}

void delay_ms(uint16_t nms)
{
	uint32_t i;
	for(i=0;i<nms;i++) delay_us(1000);
}




