/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-01-xx
  * @brief   WF-ESP8266 WiFiģ�����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "bsp_SysTick.h"
#include "bsp_esp8266.h"
#include "test.h"

 
 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
			char *yjd="yuan";
			char *valuee="999";
int main ( void )
{

	/* ��ʼ�� */
		USARTx_Config ();                                                              //��ʼ������1(printf)
		SysTick_Init ();                                                               //Ӳ����ʱ
		ESP8266_Init ();                             	//��ʼ��WiFiģ��ʹ�õĽӿں�����	
	  ESP8266_update ();
while(1)
{

}
	
	
	
}


/*********************************************END OF FILE**********************/
