#ifndef __SYSTICK_H
#define __SYSTICK_H



#include "stm32f10x.h"



#define Delay_ms(x)                             Delay_us(1000*x)	 //单位ms

#define Delay_s(x)                                Delay_ms(1000*x)	 //单位ms

#define Delay_minute(x)                             Delay_s(60*x)	 //单位ms

#define Delay_h(x)                             Delay_minute(60*x)	 //单位ms
void SysTick_Init( void );
void TimingDelay_Decrement( void );
void Delay_us ( __IO u32 nTime );


#endif /* __SYSTICK_H */
