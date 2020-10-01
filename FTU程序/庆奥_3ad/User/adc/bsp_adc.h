#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"

// 双模式时，ADC1和ADC2转换的数据都存放在ADC1的数据寄存器，
// ADC1的在低十六位，ADC2的在高十六位
// 双ADC模式的第一个ADC，必须是ADC1
#define    ADCx_1                           ADC1
#define    ADCx_1_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADCx_1_CLK                       RCC_APB2Periph_ADC1

#define    ADCx_1_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADCx_1_GPIO_CLK                  RCC_APB2Periph_GPIOC  
#define    ADCx_1_PORT                      GPIOC
#define    ADCx_1_PIN                       GPIO_Pin_1
#define    ADCx_1_CHANNEL                   ADC_Channel_11

// 双ADC模式的第二个ADC，必须是ADC2
#define    ADCx_2                           ADC2
#define    ADCx_2_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADCx_2_CLK                       RCC_APB2Periph_ADC2

#define    ADCx_2_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADCx_2_GPIO_CLK                  RCC_APB2Periph_GPIOC  
#define    ADCx_2_PORT                      GPIOC
#define    ADCx_2_PIN                       GPIO_Pin_2
#define    ADCx_2_CHANNEL                 ADC_Channel_12


#define    NOFCHANEL                        1

// ADC1 对应 DMA1通道1，ADC3对应DMA2通道5，ADC2没有DMA功能
#define    ADC_DMA_CHANNEL               DMA1_Channel1




// 双ADC模式的第二个ADC，必须是ADC2
#define    ADCx_3                           ADC3
#define    ADCx_3_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADCx_3_CLK                       RCC_APB2Periph_ADC3

#define    ADCx_3_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADCx_3_GPIO_CLK                  RCC_APB2Periph_GPIOC  
#define    ADCx_3_PORT                      GPIOC
#define    ADCx_3_PIN                       GPIO_Pin_3
#define    ADCx_3_CHANNEL                		ADC_Channel_13

// ADC1 对应 DMA1通道1，ADC3对应DMA2通道5，ADC2没有DMA功能
#define    ADC3_DMA_CHANNEL               DMA2_Channel5


void ADCx_Init(void);


#endif /* __ADC_H */

