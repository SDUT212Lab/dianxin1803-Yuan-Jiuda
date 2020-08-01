/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-01-xx
  * @brief   WF-ESP8266 WiFi模块测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "bsp_SysTick.h"
#include "bsp_esp8266.h"
#include "test.h"

 
 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
			char *yjd="yuan";
			char *valuee="999";
int main ( void )
{

	/* 初始化 */
		USARTx_Config ();                                                              //初始化串口1(printf)
		SysTick_Init ();                                                               //硬件延时
		ESP8266_Init ();                             	//初始化WiFi模块使用的接口和外设	
	  ESP8266_update ();
while(1)
{

}
	
	
	
}


/*********************************************END OF FILE**********************/
