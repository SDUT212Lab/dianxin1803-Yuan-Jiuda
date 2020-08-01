 
#include "bsp_hongwai.h"   
 static  void EXTI_NVIC_Config(void)    //3.2
{
	NVIC_InitTypeDef NVIC_InitStructure;   									 //定义一个NVIC结构体，准备开始配置
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1 );   			 //首先配置优先级
																													 //再配置NVIC
	NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;    		 //配置中断源
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//配置主优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			 //配置子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;          //使能，开总中断
	NVIC_Init(&NVIC_InitStructure);
	//------------------------------------------key2中断源配置
	NVIC_InitStructure.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;
	NVIC_Init(&NVIC_InitStructure);
	//------------------------------------------key3中断源配置

	NVIC_InitStructure.NVIC_IRQChannel = KEY3_INT_EXTI_IRQ;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	//3.1配置中断优先级
	
	EXTI_NVIC_Config();
	//  1.  初始化GPIO
	RCC_APB2PeriphClockCmd(KEY1_INT_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = KEY1_INT_PIN;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;     // 下拉输入2.
	GPIO_Init(KEY1_INT_PORT, &GPIO_InitStructure);
	//  2.  初始化EXTI
	 
	GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE,\
																					KEY1_INT_EXTI_PINSOURCE);
	
	EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;//1.
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	//*************key2配置
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
	//----key3配置  ( 光照)
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
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LED2_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
	/******************-*//////////////////////////////////////////LED3      	 PD11--LED3--光照继电器
		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LED3_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;	

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);	
}
	 void hongwai_smoke_Config(void)
	 {
			LED_GPIO_Config();	
			EXTI_Key_Config()	;
	 }

/*********************************************END OF FILE**********************/
