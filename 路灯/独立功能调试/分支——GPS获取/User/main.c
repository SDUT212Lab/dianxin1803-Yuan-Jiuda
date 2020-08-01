/**
  ******************************************************************************

  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_gps_usart.h"
#include "stm32f10x_it.h"
#include "stdio.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
	
	uint8_t gps_data[26];



int main(void)
{	

  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_GPS_Config();
	get_gps();
}


/*********************************************END OF FILE**********************/
