

#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_SysTick.h"

// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC3_ConvertedValue[NOFCHANEL];

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[3];        


void Cdelay_ms(u16 nms)
{
 u32 temp;
 SysTick->LOAD = 9000*nms;
 SysTick->VAL=0X00;//清空计数器
 SysTick->CTRL=0X01;//使能，减到零是无动作，采用外部时钟源
 do
 {
  temp=SysTick->CTRL;//读取当前倒计数值
 }while((temp&0x01)&&(!(temp&(1<<16))));//等待时间到达
    SysTick->CTRL=0x00; //关闭计数器
    SysTick->VAL =0X00; //清空计数器
}




//ADC开关函数


void ADC1_Stop(void)
{
	RCC_APB2PeriphClockCmd(ADCx_1_CLK, DISABLE);	

}
void ADC1_Beginning(void)
{
	RCC_APB2PeriphClockCmd(ADCx_1_CLK, ENABLE);	
	
}

void ADC2_Stop(void)
{
	RCC_APB2PeriphClockCmd(ADCx_2_CLK, DISABLE);	
	
}
void ADC2_Beginning(void)
{
	RCC_APB2PeriphClockCmd(ADCx_2_CLK, ENABLE);	
	
}

void ADC3_Stop(void)
{
	RCC_APB2PeriphClockCmd(ADCx_3_CLK, DISABLE);	

}
void ADC3_Beginning(void)
{
	RCC_APB2PeriphClockCmd(ADCx_3_CLK, ENABLE);	
	
}





/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{		
	uint16_t temp0=0 ,temp1=0;
	// 配置串口
	USART_Config();
	
	// ADC 初始化
	ADCx_Init();
	
	printf("\r\n ----这是一个双ADC规则同步采集实验----\r\n");
	printf("欢迎使用野火STM32开发板\n");
	
	while (1)
	{	
    // 取出ADC1数据寄存器的高16位，这个是ADC2通道一的转换数据
		temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;
		// 取出ADC1数据寄存器的低16位，这个是ADC1的转换数据
		temp1 = (ADC_ConvertedValue[0]&0XFFFF);	
		
		
		ADC_ConvertedValueLocal[2] =(float) ADC3_ConvertedValue[0]/4096*3.3;
		
		
		ADC_ConvertedValueLocal[0] =(float) temp0/4096*3.3;
		ADC_ConvertedValueLocal[1] =(float) temp1/4096*3.3;
	
		
		printf("\r\n ADCx_1 value = %f V \r\n",
		        ADC_ConvertedValueLocal[1]);
		printf("\r\n ADCx_2 value = %f V \r\n",
		        ADC_ConvertedValueLocal[0]);
		printf("\r\n ADCx_3 value = %f V \r\n",
		        ADC_ConvertedValueLocal[2]);
		
		printf("\r\n\r\n");
		Cdelay_ms(6000);
		
		 
	}
}















/*********************************************END OF FILE**********************/

