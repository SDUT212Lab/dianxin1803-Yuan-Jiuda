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

// ADC1转换的电压值通过DMA方式传到SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC3_ConvertedValue[NOFCHANEL];

float I_charge;										 //储存充电电流值    
float I_discharge;								 //储存放电电流值    
float V; 													 //储存电压值



int main(void)
{		
//	uint16_t temp0=0 ,temp1=0;
//	u8 i=0;
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

