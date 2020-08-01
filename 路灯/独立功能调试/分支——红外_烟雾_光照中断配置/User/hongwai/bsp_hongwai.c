 
#include "bsp_hongwai.h"   
 static  void EXTI_NVIC_Config(void)    //3.2
{
	NVIC_InitTypeDef NVIC_InitStructure;   									 //����һ��NVIC�ṹ�壬׼����ʼ����
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1 );   			 //�����������ȼ�
																													 //������NVIC
	NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;    		 //�����ж�Դ
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//���������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			 //���������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;          //ʹ�ܣ������ж�
	NVIC_Init(&NVIC_InitStructure);
	//------------------------------------------key2�ж�Դ����
	NVIC_InitStructure.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;
	NVIC_Init(&NVIC_InitStructure);
	//------------------------------------------key3�ж�Դ����

	NVIC_InitStructure.NVIC_IRQChannel = KEY3_INT_EXTI_IRQ;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	//3.1�����ж����ȼ�
	
	EXTI_NVIC_Config();
	//  1.  ��ʼ��GPIO
	RCC_APB2PeriphClockCmd(KEY1_INT_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = KEY1_INT_PIN;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;     // ��������2.
	GPIO_Init(KEY1_INT_PORT, &GPIO_InitStructure);
	//  2.  ��ʼ��EXTI
	 
	GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE,\
																					KEY1_INT_EXTI_PINSOURCE);
	
	EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;//1.
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	//*************key2����
	GPIO_InitStructure.GPIO_Pin = KEY2_INT_PIN	;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(KEY2_INT_PORT, &GPIO_InitStructure);
	GPIO_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE,\
																					KEY2_INT_EXTI_PINSOURCE);
	EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	//----key3����  ( ����)
	GPIO_InitStructure.GPIO_Pin = KEY3_INT_PIN;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;      
	GPIO_Init(KEY3_INT_PORT, &GPIO_InitStructure);
	GPIO_EXTILineConfig(KEY3_INT_EXTI_PORTSOURCE,\
																					KEY3_INT_EXTI_PINSOURCE);
	EXTI_InitStructure.EXTI_Line = KEY3_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; 
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}
//1
void LED_GPIO_Config(void)
{		
	///////////////////////////////LED2////////////////////////////////////
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LED2_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
	/******************-*//////////////////////////////////////////LED3      	 PD11--LED3--���ռ̵���
		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LED3_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;	

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);	
}
	 void hongwai_smoke_Config(void)
	 {
			LED_GPIO_Config();	
			EXTI_Key_Config()	;
	 }

/*********************************************END OF FILE**********************/
