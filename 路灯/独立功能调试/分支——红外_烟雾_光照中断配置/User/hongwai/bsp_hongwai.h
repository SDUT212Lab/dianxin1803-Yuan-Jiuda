#ifndef __LED_H
#define	__LED_H

/*
注：   应用时，把本头文件声明后，再加入相关中断函数到stm32f10x_it.c中，如：
																																												void KEY1_IRQHandler  (void)
																																												{
																																														if (EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET)
																																														{ 
																																																LED1_TOGGLE;
																																														}
																																														EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);
																																												}
						然后再配置相应中断优先级即可。
*/
#include "stm32f10x.h"
#include "stm32f10x_exti.h"
//注：   更改其它GPIO改下面即可  1为红外，2为烟雾
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//      红外部分		 
#define LED1_GPIO_PORT    																GPIOD			              /* GPIO端口 */
#define LED1_GPIO_CLK 	   																  RCC_APB2Periph_GPIOD		/* GPIO端口时钟 */
#define LED1_GPIO_PIN																				GPIO_Pin_10		        /* 连接到SCL时钟线的GPIO */

#define KEY1_INT_PORT    																		GPIOG		              
#define KEY1_INT_CLK																					(RCC_APB2Periph_GPIOG\
																																										|RCC_APB2Periph_AFIO)
#define KEY1_INT_PIN	  																				GPIO_Pin_2			        
/**/
#define KEY1_INT_EXTI_PORTSOURCE 						GPIO_PortSourceGPIOG
#define KEY1_INT_EXTI_PINSOURCE 								GPIO_PinSource2
#define KEY1_INT_EXTI_LINE 															EXTI_Line2
#define KEY1_INT_EXTI_IRQ 																EXTI2_IRQn
#define KEY1_IRQHandler 																			EXTI2_IRQHandler
//---------------------------------------------------------------------------------------------------------------
//   烟雾部分				 PD10--LED2--烟雾报警继电器
#define LED2_GPIO_PORT    																GPIOD			              /* GPIO端口 */
#define LED2_GPIO_CLK 	   																  RCC_APB2Periph_GPIOD		/* GPIO端口时钟 */
#define LED2_GPIO_PIN																				GPIO_Pin_10	        /* 连接到SCL时钟线的GPIO */

#define KEY2_INT_PORT    																		GPIOG		              
#define KEY2_INT_CLK																					(RCC_APB2Periph_GPIOG\
																																										|RCC_APB2Periph_AFIO)
#define KEY2_INT_PIN	  																				GPIO_Pin_3			        
/**/
#define KEY2_INT_EXTI_PORTSOURCE 						GPIO_PortSourceGPIOG
#define KEY2_INT_EXTI_PINSOURCE 								GPIO_PinSource3
#define KEY2_INT_EXTI_LINE 															EXTI_Line3
#define KEY2_INT_EXTI_IRQ 																EXTI3_IRQn
#define KEY2_IRQHandler 																			EXTI3_IRQHandler
 
 //-----------------------------------------------------------------------------------------------------------------
//光照部分：    	 PD11--LED3--光照继电器
#define LED3_GPIO_PORT    																GPIOD			              /* GPIO端口 */
#define LED3_GPIO_CLK 	   																  RCC_APB2Periph_GPIOD		/* GPIO端口时钟 */
#define LED3_GPIO_PIN																				GPIO_Pin_11		        /* 连接到SCL时钟线的GPIO */

#define KEY3_INT_PORT    																		GPIOG		              
#define KEY3_INT_CLK																					(RCC_APB2Periph_GPIOG\
																																										|RCC_APB2Periph_AFIO)
#define KEY3_INT_PIN	  																				GPIO_Pin_4			        
/**/
#define KEY3_INT_EXTI_PORTSOURCE 						GPIO_PortSourceGPIOG
#define KEY3_INT_EXTI_PINSOURCE 								GPIO_PinSource4
#define KEY3_INT_EXTI_LINE 															EXTI_Line4
#define KEY3_INT_EXTI_IRQ 																EXTI4_IRQn
#define KEY3_IRQHandler 																			EXTI4_IRQHandler
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ON  0
#define OFF 1
/* 使用标准的固件库控制IO*/
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)
/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 //输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态
/* 定义控制IO的宏 */
#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED3_TOGGLE		 digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF		   digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON			   digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

//void LED_GPIO_Config(void);
//////////////////////////////////////////////////////////////////////////////////

//void EXTI_Key_Config(void);
	 void hongwai_smoke_Config(void);


#endif /* __LED_H */
