#include "Battery_Test.h"  
#include "bsp_usart.h"
#include "./key/bsp_key.h"  



void Battery_Charge_Test(void)
{
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON )
		{
						
 						printf("\r\n ������KEY1�����״̬��⿪ʼ\r\n");				 

	
//										ADC1_Beginning();
//										ADC3_Beginning();
//										temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2ͨ��һ��ת������
//										temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
//										I_charge =(float) temp1/4096*3.3;
//										I_discharge =(float) temp0/4096*3.3;
//										V =(float) ADC3_ConvertedValue[0]/4096*3.3;
//										printf("\r\n ��ǰ������ֵΪ  %f V \r\n",I_charge);
//										printf("\r\n ��ǰ��ѹֵΪ = %f V \r\n",V);		
//									Cdelay_ms(2000);
//										ADC3_Stop();	
//										ADC1_Stop();	
		}

}

void Battery_Discharge_Test(void)
{
		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) ==KEY_ON )
		{
 						printf("\r\n ������KEY2���ŵ�״̬��⿪ʼ\r\n");		 
				
			
//										ADC2_Beginning();
//										ADC3_Beginning();
//										temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2ͨ��һ��ת������
//										temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
//										I_charge =(float) temp1/4096*3.3;
//										I_discharge =(float) temp0/4096*3.3;
//										V =(float) ADC3_ConvertedValue[0]/4096*3.3;
//										printf("\r\n ��ǰ�ŵ����ֵΪ  %f V \r\n",I_discharge);
//										printf("\r\n ��ǰ��ѹֵΪ = %f V \r\n",V);		
//									Cdelay_ms(2000);
//										ADC3_Stop();	
//										ADC2_Stop();													 
		}	 
}
































/*********************************************END OF FILE**********************/
