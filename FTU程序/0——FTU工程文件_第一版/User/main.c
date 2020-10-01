#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "./key/bsp_key.h"  
#include "bsp_SysTick.h"
#include "bsp_led.h"
#include "Battery_Test.h"  

/*
	ע��
			ADC_1  ��������
			ADC_2  ���ŵ����
			ADC_3  ����ѹ
*/

// ADC1ת���ĵ�ѹֵͨ��DMA��ʽ����SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC3_ConvertedValue[NOFCHANEL];

float I_charge;										 //���������ֵ    
float I_discharge;								 //����ŵ����ֵ    
float V; 													 //�����ѹֵ



int main(void)
{		
//	uint16_t temp0=0 ,temp1=0;
//	u8 i=0;
	USART_Config();
	Key_GPIO_Config();	
	ADCx_Init();
	
	printf("\r\n ---��ʼ������ߣ�---\r\n");
	printf("\r\n --��һ�β�AD1��AD3���ٲ�AD2��AD3���ٹ���--\r\n");
	
	ADC1_Stop();
	ADC2_Stop();
	ADC3_Stop();
	while (1)
	{ 
			Battery_Charge_Test();							//����KEY1���£����״̬��ʼ���
			Battery_Discharge_Test();						//����KEY2���£��ŵ�״̬��ʼ���

	}//while(1)
	
	
}//main















/*********************************************END OF FILE**********************/

