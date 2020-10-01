#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_SysTick.h"
#include "bsp_led.h"
#include "bsp_key.h"

// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC3_ConvertedValue[NOFCHANEL];

float I_charge;										 //���������ֵ    
float I_discharge;								 //����ŵ����ֵ    
float V; 													 //�����ѹֵ


int main(void)
{		
	uint16_t temp0=0 ,temp1=0;
	u8 i=0;
	USART_Config();
	KEY_GPIO_Config();	
	ADCx_Init();
	
	printf("\r\n ---��ʼ������ߣ�---\r\n");
	printf("\r\n --��һ�β�AD1���ٲ�AD2���ٲ�AD3���ٹ���--\r\n");
	
	ADC1_Stop();
	ADC2_Stop();
	ADC3_Stop();
while (1)
	{ 
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) ==KEY_ON ) i++;
		if(i==4)	i=0;
		switch(i)
		{
			case 1:		
										ADC1_Beginning();
										temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2ͨ��һ��ת������
										temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
										I_charge =(float) temp1/4096*3.3;
										I_discharge =(float) temp0/4096*3.3;
										V =(float) ADC3_ConvertedValue[0]/4096*3.3;
										printf("\r\n ��ǰ������ֵΪ  %f V \r\n",I_charge);				Cdelay_ms(2000);
										ADC1_Stop();													break;
			case 2:		
										ADC2_Beginning();
										temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2ͨ��һ��ת������
										temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
										I_charge =(float) temp1/4096*3.3;
										I_discharge =(float) temp0/4096*3.3;
										V =(float) ADC3_ConvertedValue[0]/4096*3.3;
										printf("\r\n ��ǰ�ŵ����ֵΪ  %f V \r\n",I_discharge);			Cdelay_ms(2000);
										ADC2_Stop();													break;
			case 3:		
										ADC3_Beginning();
										temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2ͨ��һ��ת������
										temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
										I_charge =(float) temp1/4096*3.3;
										I_discharge =(float) temp0/4096*3.3;
										V =(float) ADC3_ConvertedValue[0]/4096*3.3;
										printf("\r\n ��ǰ��ѹֵΪ = %f V \r\n",V);			Cdelay_ms(2000);
										ADC3_Stop();													break;

			default:													
																													break;
		}
		
		 
	}
}















/*********************************************END OF FILE**********************/

