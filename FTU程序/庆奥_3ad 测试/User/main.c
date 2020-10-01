#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_SysTick.h"
#include "bsp_led.h"
#include "bsp_key.h"

// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC3_ConvertedValue[NOFCHANEL];

float I_charge;										 //储存充电电流值    
float I_discharge;								 //储存放电电流值    
float V; 													 //储存电压值


int main(void)
{		
	uint16_t temp0=0 ,temp1=0;
	u8 i=0;
	USART_Config();
	KEY_GPIO_Config();	
	ADCx_Init();
	
	printf("\r\n ---开始！请决策！---\r\n");
	printf("\r\n --按一次测AD1，再测AD2，再测AD3，再关上--\r\n");
	
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
										temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// 取出ADC1数据寄存器的高16位，这个是ADC2通道一的转换数据
										temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// 取出ADC1数据寄存器的低16位，这个是ADC1的转换数据
										I_charge =(float) temp1/4096*3.3;
										I_discharge =(float) temp0/4096*3.3;
										V =(float) ADC3_ConvertedValue[0]/4096*3.3;
										printf("\r\n 当前充电电流值为  %f V \r\n",I_charge);				Cdelay_ms(2000);
										ADC1_Stop();													break;
			case 2:		
										ADC2_Beginning();
										temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// 取出ADC1数据寄存器的高16位，这个是ADC2通道一的转换数据
										temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// 取出ADC1数据寄存器的低16位，这个是ADC1的转换数据
										I_charge =(float) temp1/4096*3.3;
										I_discharge =(float) temp0/4096*3.3;
										V =(float) ADC3_ConvertedValue[0]/4096*3.3;
										printf("\r\n 当前放电电流值为  %f V \r\n",I_discharge);			Cdelay_ms(2000);
										ADC2_Stop();													break;
			case 3:		
										ADC3_Beginning();
										temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;		// 取出ADC1数据寄存器的高16位，这个是ADC2通道一的转换数据
										temp1 = (ADC_ConvertedValue[0]&0XFFFF);							// 取出ADC1数据寄存器的低16位，这个是ADC1的转换数据
										I_charge =(float) temp1/4096*3.3;
										I_discharge =(float) temp0/4096*3.3;
										V =(float) ADC3_ConvertedValue[0]/4096*3.3;
										printf("\r\n 当前电压值为 = %f V \r\n",V);			Cdelay_ms(2000);
										ADC3_Stop();													break;

			default:													
																													break;
		}
		
		 
	}
}















/*********************************************END OF FILE**********************/

