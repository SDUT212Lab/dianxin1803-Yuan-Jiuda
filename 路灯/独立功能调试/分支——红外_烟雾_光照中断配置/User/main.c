#include "stm32f10x.h"
#include "bsp_hongwai.h"
 void delay_ms(u16 time);
int main(void)
{	
	 hongwai_smoke_Config();
	//LED2_ON;
	LED2_OFF
 
	while (1)
	{
	// LED2_OFF
	}
}

void delay_ms(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=12000;  //????
      while(i--) ;    
   }
}


