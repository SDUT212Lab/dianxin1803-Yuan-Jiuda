#include "Battery_Test.h"  
#include "bsp_usart.h"
#include "./key/bsp_key.h"  
#include "bsp_led.h"
#include "bsp_adc.h"
#include "bsp_SysTick.h"

// ADC1ת���ĵ�ѹֵͨ��DMA��ʽ����SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC3_ConvertedValue[NOFCHANEL];

float I_charge;										 //���������ֵ    
float I_discharge;								 //����ŵ����ֵ    
float V; 													 //�����ѹֵ


uint16_t temp0=0 ,temp1=0;
u8 i=0;


void Battery_Charge_Test(void)
{
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON )
		{
						
				printf("\r\n\r\n ������KEY1�����״̬��⿪ʼ\r\n\r\n");		
								ADC1_Beginning();
								ADC3_Beginning();			
								for(i=0;i<=Test_Number;i++)
							{

								SysTick_Delay_Ms(Test_Delay/2);
								temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2ͨ��һ��ת������
								temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
								I_charge =(float) temp1/4096*3.3;
								I_discharge =(float) temp0/4096*3.3;
								V =(float) ADC3_ConvertedValue[0]/4096*3.3;
								printf("\r\n %d:��ǰ������ֵΪ  %f V \r\n",i,I_charge);
								printf("\r\n ��ǰ��ѹֵΪ = %f V \r\n\r\n",V);		
								SysTick_Delay_Ms(Test_Delay/2);

							}
								ADC3_Stop();	
								ADC1_Stop();	

		}

}

void Battery_Discharge_Test(void)
{
		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) ==KEY_ON )
		{
				printf("\r\n\r\n ������KEY2���ŵ�״̬��⿪ʼ\r\n\r\n");		 
								ADC2_Beginning();
								ADC3_Beginning();
								for(i=0;i<=Test_Number;i++)
							{

								SysTick_Delay_Ms(Test_Delay/2);
								temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2ͨ��һ��ת������
								temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
								I_charge =(float) temp1/4096*3.3;
								I_discharge =(float) temp0/4096*3.3;
								V =(float) ADC3_ConvertedValue[0]/4096*3.3;
								printf("\r\n %d:��ǰ�ŵ����ֵΪ  %f V \r\n",i,I_discharge);
								printf("\r\n ��ǰ��ѹֵΪ = %f V \r\n\r\n",V);		
								SysTick_Delay_Ms(Test_Delay/2);

							}	
								ADC3_Stop();	
								ADC2_Stop();	
		}	 
}
































/*********************************************END OF FILE**********************/
