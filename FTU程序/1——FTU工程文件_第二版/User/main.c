#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "./key/bsp_key.h"  
#include "bsp_SysTick.h"
#include "bsp_led.h"
#include "Battery_Test.h"  

/*
	注：
			ADC_1  检测充电电流
			ADC_2  检测放电电流
			ADC_3  检测电压
*/




int main(void)
{		

	USART_Config();
	Key_GPIO_Config();	
	ADCx_Init();
	
	printf("\r\n ---开始！请决策！---\r\n");
	printf("\r\n --按一次测AD1和AD3，再测AD2和AD3，再关上--\r\n");
	
	ADC1_Stop();
	ADC2_Stop();
	ADC3_Stop();
	while (1)
	{ 
			Battery_Charge_Test();							//按键KEY1按下，充电状态开始检测
			Battery_Discharge_Test();						//按键KEY2按下，放电状态开始检测

	}//while(1)
	
	
}//main















/*********************************************END OF FILE**********************/

