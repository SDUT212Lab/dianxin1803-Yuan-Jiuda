#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

#define LED1_GPIO_PIN              GPIO_Pin_10
#define LED1_GPIO_PORT             GPIOA
#define LED1_GPIO_CLK              RCC_APB2Periph_GPIOA

#define LED2_GPIO_PIN              GPIO_Pin_8
#define LED2_GPIO_PORT             GPIOB
#define LED2_GPIO_CLK              RCC_APB2Periph_GPIOB

#define LED3_GPIO_PIN              GPIO_Pin_7
#define LED3_GPIO_PORT             GPIOB
#define LED3_GPIO_CLK              RCC_APB2Periph_GPIOB


#define    ON        1
#define    OFF       0

// \  C语言里面叫续行符，后面不能有任何的东西

#define   LED1(a)   if(a) \
	                       GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN); \
                     else  GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
#define   LED2(a)   if(a) \
	                       GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN); \
                     else  GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
#define   LED3(a)   if(a) \
	                       GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN); \
                     else  GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);

void LED_GPIO_Config(void);

#endif /* __BSP_LED_H */

