#ifndef __TIM_H
#define __TIM_H

#define STM32F10X_HD

#include "stm32f10x.h"
#include "stm32f10x_conf.h"

// #define __TIM_F
// #define __TIM_G_F
// #define __TIM_G_S
// #define __TIM_T_F

#define __TIM_PWM_IN

#if defined(__TIM_F)

#define BASIC_TIM TIM6
#define BASIC_TIM_APBxClock_FUN RCC_APB1PeriphClockCmd
#define BASIC_TIM_CLK RCC_APB1Periph_TIM6
#define BASIC_TIM_Period 1000-1
#define BASIC_TIM_Prescaler 71
#define BASIC_TIM_IRQ TIM6_IRQn
#define BASIC_TIM_IRQHandler TIM6_IRQHandler

void BASIC_TIM_Init(void);

#elif defined(__TIM_G_F)

#define ADVANCE_TIM TIM1
#define ADVANCE_TIM_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADVANCE_TIM_CLK RCC_APB2Periph_TIM11
#define ADVANCE_TIM_Period (1000-1)
#define ADVANCE_TIM_Prescaler 71
#define ADVANCE_TIM_IRQ TIM1_UP_IRQn
#define ADVANCE_TIM_IRQHandler TIM1_UP_IRQHandler

#elif defined(__TIM_G_S)

#define ADVANCE_TIM TIM1
#define ADVANCE_TIM_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADVANCE_TIM_CLK RCC_APB2Periph_TIM1

#define ADVANCE_TIM_PERIOD (8 - 1)
#define ADVANCE_TIM_PSC (9 - 1)
#define ADVANCE_TIM_PULSE 4

#define ADVANCE_TIM_IRQ TIM1_UP_IRQn
#define ADVANCE_TIM_IRQHandler TIM1_UP_IRQHandler

#define ADVANCE_TIM_CH1_GPIO_CLK RCC_APB2Periph_GPIOA
#define ADVANCE_TIM_CH1_PORT GPIOA
#define ADVANCE_TIM_CH1_PIN GPIO_Pin_8

#define ADVANCE_TIM_CH1N_GPIO_CLK RCC_APB2Periph_GPIOB
#define ADVANCE_TIM_CH1N_PORT GPIOB
#define ADVANCE_TIM_CH1N_PIN GPIO_Pin_13

#define ADVANCE_TIM_BKIN_GPIO_CLK RCC_APB2Periph_GPIOB
#define ADVANCE_TIM_BKIN_PORT GPIOB
#define ADVANCE_TIM_BKIN_PIN GPIO_Pin_12

void ADVANCE_TIM_Init(void);

#elif defined(__TIM_T_F)

#define GENERAL_TIM TIM5
#define GENERAL_TIM_APBxClock_FUN RCC_APB1PeriphClockCmd
#define GENERAL_TIM_CLK RCC_APB1Periph_TIM5
#define GENERAL_TIM_PERIOD 0XFFFF
#define GENERAL_TIM_PSC (72 - 1)

#define GENERAL_TIM_CH1_GPIO_CLK RCC_APB2Periph_GPIOA
#define GENERAL_TIM_CH1_PORT GPIOA
#define GENERAL_TIM_CH1_PIN GPIO_Pin_0
#define GENERAL_TIM_CHANNEL_x TIM_Channel_1

#define GENERAL_TIM_IT_CCx TIM_IT_CC1
#define GENERAL_TIM_IRQ TIM5_IRQn
#define GENERAL_TIM_INT_FUN TIM5_IRQHandler

#define GENERAL_TIM_GetCapturex_FUN TIM_GetCapture1
#define GENERAL_TIM_OCxPolarityConfig_FUN TIM_OC1PolarityConfig

#define GENERAL_TIM_STRAT_ICPolarity TIM_ICPolarity_Rising
#define GENERAL_TIM_END_ICPolarity TIM_ICPolarity_Falling

typedef struct
{
    uint8_t Capture_FinishFlag;
    uint8_t Capture_StartFlag;
    uint16_t Capture_CcrValue;
    uint16_t Capture_Period;
} TIM_ICUserValueTypeDef;

extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;

void GENERAL_TIM_Init(void);

#endif

#ifdef __TIM_PWM_IN

#define GENERAL_TIM TIM3
#define GENERAL_TIM_APBxClock_FUN RCC_APB1PeriphClockCmd
#define GENERAL_TIM_CLK RCC_APB1Periph_TIM3
#define GENERAL_TIM_PERIOD (10 - 1)
#define GENERAL_TIM_PSC (72 - 1)

#define GENERAL_TIM_CCR1 5
#define GENERAL_TIM_CCR2 4
#define GENERAL_TIM_CCR3 3
#define GENERAL_TIM_CCR4 2

#define GENERAL_TIM_CH1_GPIO_CLK RCC_APB2Periph_GPIOA
#define GENERAL_TIM_CH1_PORT GPIOA
#define GENERAL_TIM_CH1_PIN GPIO_Pin_6

#define GENERAL_TIM_CH2_GPIO_CLK RCC_APB2Periph_GPIOA
#define GENERAL_TIM_CH2_PORT GPIOA
#define GENERAL_TIM_CH2_PIN GPIO_Pin_7

#define GENERAL_TIM_CH3_GPIO_CLK RCC_APB2Periph_GPIOB
#define GENERAL_TIM_CH3_PORT GPIOB
#define GENERAL_TIM_CH3_PIN GPIO_Pin_0

#define GENERAL_TIM_CH4_GPIO_CLK RCC_APB2Periph_GPIOB
#define GENERAL_TIM_CH4_PORT GPIOB
#define GENERAL_TIM_CH4_PIN GPIO_Pin_1

void GENERAL_TIM_Init(void);

#define ADVANCE_TIM TIM1
#define ADVANCE_TIM_APBxClock_FUN RCC_APB2PeriphClockCmd
#define ADVANCE_TIM_CLK RCC_APB2Periph_TIM1

#define ADVANCE_TIM_PERIOD (1000 - 1)
#define ADVANCE_TIM_PSC (72 - 1)

#define ADVANCE_TIM_IRQ TIM1_CC_IRQn
#define ADVANCE_TIM_IRQHandler TIM1_CC_IRQHandler

#define ADVANCE_TIM_CH1_GPIO_CLK RCC_APB2Periph_GPIOA
#define ADVANCE_TIM_CH1_PORT GPIOA
#define ADVANCE_TIM_CH1_PIN GPIO_Pin_8

#define ADVANCE_TIM_IC1PWM_CHANNEL TIM_Channel_1
#define ADVANCE_TIM_IC2PWM_CHANNEL TIM_Channel_2

void ADVANCE_TIM_Init(void);

#endif

#endif /* __TIM_H */
