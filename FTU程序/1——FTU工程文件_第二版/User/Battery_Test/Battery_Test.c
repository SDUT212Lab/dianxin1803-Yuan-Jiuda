#include "Battery_Test.h"  
#include "bsp_usart.h"
#include "./key/bsp_key.h"  
#include "bsp_led.h"
#include "bsp_adc.h"
#include "bsp_SysTick.h"

// ADC1转换的电压值通过DMA方式传到SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC3_ConvertedValue[NOFCHANEL];

float I_charge;										 //储存充电电流值    
float I_discharge;								 //储存放电电流值    
float V; 													 //储存电压值


uint16_t temp0=0 ,temp1=0;
u8 i=0;


void Battery_Charge_Test(void)
{
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON )
		{
						
				printf("\r\n\r\n 按下了KEY1，充电状态检测开始\r\n\r\n");		
								ADC1_Beginning();
								ADC3_Beginning();			
								for(i=0;i<=Test_Number;i++)
							{

								SysTick_Delay_Ms(Test_Delay/2);
								temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// 取出ADC1数据寄存器的高16位，这个是ADC2通道一的转换数据
								temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// 取出ADC1数据寄存器的低16位，这个是ADC1的转换数据
								I_charge =(float) temp1/4096*3.3;
								I_discharge =(float) temp0/4096*3.3;
								V =(float) ADC3_ConvertedValue[0]/4096*3.3;
								printf("\r\n %d:当前充电电流值为  %f V \r\n",i,I_charge);
								printf("\r\n 当前电压值为 = %f V \r\n\r\n",V);		
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
				printf("\r\n\r\n 按下了KEY2，放电状态检测开始\r\n\r\n");		 
								ADC2_Beginning();
								ADC3_Beginning();
								for(i=0;i<=Test_Number;i++)
							{

								SysTick_Delay_Ms(Test_Delay/2);
								temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// 取出ADC1数据寄存器的高16位，这个是ADC2通道一的转换数据
								temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// 取出ADC1数据寄存器的低16位，这个是ADC1的转换数据
								I_charge =(float) temp1/4096*3.3;
								I_discharge =(float) temp0/4096*3.3;
								V =(float) ADC3_ConvertedValue[0]/4096*3.3;
								printf("\r\n %d:当前放电电流值为  %f V \r\n",i,I_discharge);
								printf("\r\n 当前电压值为 = %f V \r\n\r\n",V);		
								SysTick_Delay_Ms(Test_Delay/2);

							}	
								ADC3_Stop();	
								ADC2_Stop();	
		}	 
}
































/*********************************************END OF FILE**********************/
