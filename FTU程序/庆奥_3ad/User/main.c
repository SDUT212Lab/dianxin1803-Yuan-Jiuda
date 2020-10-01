

#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_SysTick.h"

// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];
extern __IO uint16_t ADC3_ConvertedValue[NOFCHANEL];

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal[3];        


void Cdelay_ms(u16 nms)
{
 u32 temp;
 SysTick->LOAD = 9000*nms;
 SysTick->VAL=0X00;//��ռ�����
 SysTick->CTRL=0X01;//ʹ�ܣ����������޶����������ⲿʱ��Դ
 do
 {
  temp=SysTick->CTRL;//��ȡ��ǰ������ֵ
 }while((temp&0x01)&&(!(temp&(1<<16))));//�ȴ�ʱ�䵽��
    SysTick->CTRL=0x00; //�رռ�����
    SysTick->VAL =0X00; //��ռ�����
}




//ADC���غ���


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
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{		
	uint16_t temp0=0 ,temp1=0;
	// ���ô���
	USART_Config();
	
	// ADC ��ʼ��
	ADCx_Init();
	
	printf("\r\n ----����һ��˫ADC����ͬ���ɼ�ʵ��----\r\n");
	printf("��ӭʹ��Ұ��STM32������\n");
	
	while (1)
	{	
    // ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2ͨ��һ��ת������
		temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;
		// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
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

