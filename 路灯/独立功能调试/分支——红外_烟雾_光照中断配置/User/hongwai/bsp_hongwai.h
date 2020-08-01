#ifndef __LED_H
#define	__LED_H

/*
ע��   Ӧ��ʱ���ѱ�ͷ�ļ��������ټ�������жϺ�����stm32f10x_it.c�У��磺
																																												void KEY1_IRQHandler  (void)
																																												{
																																														if (EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET)
																																														{ 
																																																LED1_TOGGLE;
																																														}
																																														EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);
																																												}
						Ȼ����������Ӧ�ж����ȼ����ɡ�
*/
#include "stm32f10x.h"
#include "stm32f10x_exti.h"
//ע��   ��������GPIO�����漴��  1Ϊ���⣬2Ϊ����
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//      ���ⲿ��		 
#define LED1_GPIO_PORT    																GPIOD			              /* GPIO�˿� */
#define LED1_GPIO_CLK 	   																  RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN																				GPIO_Pin_10		        /* ���ӵ�SCLʱ���ߵ�GPIO */

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
//   ������				 PD10--LED2--�������̵���
#define LED2_GPIO_PORT    																GPIOD			              /* GPIO�˿� */
#define LED2_GPIO_CLK 	   																  RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LED2_GPIO_PIN																				GPIO_Pin_10	        /* ���ӵ�SCLʱ���ߵ�GPIO */

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
//���ղ��֣�    	 PD11--LED3--���ռ̵���
#define LED3_GPIO_PORT    																GPIOD			              /* GPIO�˿� */
#define LED3_GPIO_CLK 	   																  RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LED3_GPIO_PIN																				GPIO_Pin_11		        /* ���ӵ�SCLʱ���ߵ�GPIO */

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
/* ʹ�ñ�׼�Ĺ̼������IO*/
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
/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬
/* �������IO�ĺ� */
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
