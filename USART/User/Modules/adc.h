#ifndef __ADC_H
#define __ADC_H

#define STM32F10X_HD

#include "stm32f10x.h"
#include "stm32f10x_conf.h"

#define __ADC_THIRD

#ifdef __ADC_FIRST

#define ADC_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADCx ADC2
#define ADC_CLK RCC_APB2Periph_ADC2

#define ADC_GPIO_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADC_GPIO_CLK RCC_APB2Periph_GPIOC
#define ADC_PORT GPIOC
#define ADC_PIN GPIO_Pin_1

#define ADC_CHANNEL ADC_Channel_11

#define ADC_IRQ ADC1_2_IRQn
#define ADC_IRQHandler ADC1_2_IRQHandler

#endif // __ADC_FIRST


#ifdef __ADC_SECOND

#define ADC_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADC_CLK RCC_APB2Periph_ADC1

#define ADC_GPIO_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADC_GPIO_CLK RCC_APB2Periph_GPIOC
#define ADC_PORT GPIOC

#define NOFCHANNEL 6

#define ADC_PIN1 GPIO_Pin_0
#define ADC_CHANNEL1 ADC_Channel_10

#define ADC_PIN2 GPIO_Pin_1
#define ADC_CHANNEL2 ADC_Channel_11

#define ADC_PIN3 GPIO_Pin_2
#define ADC_CHANNEL3 ADC_Channel_12

#define ADC_PIN4 GPIO_Pin_3
#define ADC_CHANNEL4 ADC_Channel_13

#define ADC_PIN5 GPIO_Pin_4
#define ADC_CHANNEL5 ADC_Channel_14

#define ADC_PIN6 GPIO_Pin_5
#define ADC_CHANNEL6 ADC_Channel_15

#define ADC_x ADC1
#define ADC_DMA_CHANNEL DMA1_Channel1
#define ADC_DMA_CLK RCC_AHBPeriph_DMA1

#endif // __ADC_SECOND

#ifdef __ADC_THIRD

#define ADCx_1 ADC1
#define ADCx_1_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADCX_1_CLK RCC_APB2Periph_ADC1

#define ADCx_1_GPIO_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADCx_1_GPIO_CLK RCC_APB2Periph_GPIOC
#define ADCx_1_PORT GPIOC
#define ADCx_1_PIN GPIO_Pin_1
#define ADCx_1_CHANNEL ADC_Channel_11

#define ADCx_2 ADC2
#define ADCx_2_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADCx_2_CLK RCC_APB2Periph_ADC2

#define ADCx_2_GPIO_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADCx_2_GPIO_CLK RCC_APB2Periph_GPIOC
#define ADCx_2_PORT GPIOC
#define ADCx_2_PIN GPIO_Pin_4
#define ADCx_2_CHANNEL ADC_Channel_14

#define NOFCHANNEL 1

#define ADC_DMA_CHANNEL DMA1_Channel1

#endif // __ADC_THIRD

void ADCx_Init(void);

// __IO uint16_t ADC_ConvertedValue;
// __IO uint16_t ADC_ConvertedValue[NOFCHANNEL] = {0, 0, 0, 0};
__IO uint16_t ADC_ConvertedValue[NOFCHANNEL] = {0};

#endif
