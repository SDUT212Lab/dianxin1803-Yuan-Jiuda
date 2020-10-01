#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

void SysTick_Init(void);
void Delay_us(__IO u32 nTime);
#define Delay_ms(x) Delay_us(100*x)	 //��λms
void TimingDelay_Decrement(void);
void SysTick_Delay_Us( __IO uint32_t us);
void SysTick_Delay_Ms( __IO uint32_t ms);
void Software_Delay_Ms(u16 Number);
void Cdelay_ms(u16 nms);


#endif /* __SYSTICK_H */
