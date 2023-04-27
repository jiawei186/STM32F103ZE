#include "tim.h"

#if defined(__TIM_F)

static void BASIC_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}

static void BASIC_TIM_Mode_Config(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);

    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period;
    TIM_TimeBaseStructure.TIM_Prescaler = BASIC_TIM_Prescaler;

    TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);

    TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);

    TIM_ITConfig(BASIC_TIM, TIM_IT_Update, ENABLE);

    TIM_Cmd(BASIC_TIM, ENABLE);
}

void BASIC_TIM_Init(void)
{
    BASIC_TIM_NVIC_Config();
    BASIC_TIM_Mode_Config();
}

#elif defined(__TIM_G_F)

static void ADVANCE_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

    NVIC_InitStructure.NVIC_IRQChannel = ADVANCE_TIM_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}

static void ADVANCE_TIM_Mode_Config(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK, ENABLE);

    TIM_TimeBaseStructure.TIM_Period = ADVANCE_TIM_Period;
    TIM_TimeBaseStructure.TIM_Prescaler = ADVANCE_TIM_Prescaler;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

    TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);

    TIM_ClearFlag(ADVANCE_TIM, TIM_FLAG_Update);

    TIM_ITConfig(ADVANCE_TIM, TIM_IT_Update, ENABLE);

    TIM_Cmd(ADVANCE_TIM, ENABLE);
}

void ADVANCE_TIM_Init(void)
{
    ADVANCE_TIM_NVIC_Config();
    ADVANCE_TIM_Mode_Config();
}

#elif defined(__TIM_G_S)

static void ADVANCE_TIM_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH1_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = ADVANCE_TIM_CH1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADVANCE_TIM_CH1_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH1N_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = ADVANCE_TIM_CH1N_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADVANCE_TIM_CH1N_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(ADVANCE_TIM_BKIN_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = ADVANCE_TIM_BKIN_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(ADVANCE_TIM_BKIN_PORT, &GPIO_InitStructure);
    GPIO_ResetBits(ADVANCE_TIM_BKIN_PORT, ADVANCE_TIM_BKIN_PIN);
}

static void ADVANCE_TIM_Mode_Config(void)
{
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    TIM_TimeBaseStructure.TIM_Period = ADVANCE_TIM_PERIOD;
    TIM_TimeBaseStructure.TIM_Prescaler = ADVANCE_TIM_PSC;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);

    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    TIM_OCInitStructure.TIM_Pulse = ADVANCE_TIM_PULSE;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
    TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);

    TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
    TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
    TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
    TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_1;
    TIM_BDTRInitStructure.TIM_DeadTime = 11;
    TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
    TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;
    TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;
    TIM_BDTRConfig(ADVANCE_TIM, &TIM_BDTRInitStructure);

    TIM_Cmd(ADVANCE_TIM, ENABLE);
    TIM_CtrlPWMOutputs(ADVANCE_TIM, ENABLE);
}

void ADVANCE_TIM_Init(void)
{
    ADVANCE_TIM_GPIO_Config();
    ADVANCE_TIM_Mode_Config();
}

#elif defined(__TIM_T_F)

TIM_ICUserValueTypeDef TIM_ICUserValueStructure = {0, 0, 0, 0};

static void GENERAL_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    NVIC_InitStructure.NVIC_IRQChannel = GENERAL_TIM_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void GENERAL_TIM_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GENERAL_TIM_CH1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GENERAL_TIM_CH1_PORT, &GPIO_InitStructure);
}

static void GENERAL_TIM_Mode_Config(void)
{
    GENERAL_TIM_APBxClock_FUN(GENERAL_TIM_CLK, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = GENERAL_TIM_PERIOD;
    TIM_TimeBaseStructure.TIM_Prescaler = GENERAL_TIM_PSC;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(GENERAL_TIM, &TIM_TimeBaseStructure);

    TIM_ICInitTypeDef TIM_ICInitStructure;
    TIM_ICInitStructure.TIM_Channel = GENERAL_TIM_CHANNEL_x;
    TIM_ICInitStructure.TIM_ICPolarity = GENERAL_TIM_STRAT_ICPolarity;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0;
    TIM_ICInit(GENERAL_TIM, &TIM_ICInitStructure);

    TIM_ClearFlag(GENERAL_TIM, TIM_FLAG_Update | GENERAL_TIM_IT_CCx);
    TIM_ITConfig(GENERAL_TIM, TIM_IT_Update | GENERAL_TIM_IT_CCx, ENABLE);

    TIM_Cmd(GENERAL_TIM, ENABLE);
}

void GENERAL_TIM_Init(void)
{
    GENERAL_TIM_GPIO_Config();
    GENERAL_TIM_NVIC_Config();
    GENERAL_TIM_Mode_Config();
}

#endif

#ifdef __TIM_PWM_IN

static void GENERAL_TIM_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GENERAL_TIM_CH1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GENERAL_TIM_CH1_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GENERAL_TIM_CH2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GENERAL_TIM_CH2_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GENERAL_TIM_CH3_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GENERAL_TIM_CH3_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GENERAL_TIM_CH3_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GENERAL_TIM_CH3_PORT, &GPIO_InitStructure);
}

static void GENERAL_TIM_Mode_Config(void)
{
    GENERAL_TIM_APBxClock_FUN(GENERAL_TIM_CLK, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = GENERAL_TIM_PERIOD;
    TIM_TimeBaseStructure.TIM_Prescaler = GENERAL_TIM_PSC;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(GENERAL_TIM, &TIM_TimeBaseStructure);

    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

    TIM_OCInitStructure.TIM_Pulse = GENERAL_TIM_CCR1;
    TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = GENERAL_TIM_CCR2;
    TIM_OC2Init(GENERAL_TIM, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = GENERAL_TIM_CCR3;
    TIM_OC3Init(GENERAL_TIM, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);

    TIM_OCInitStructure.TIM_Pulse = GENERAL_TIM_CCR4;
    TIM_OC4Init(GENERAL_TIM, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);

    TIM_Cmd(GENERAL_TIM, ENABLE);
}

void GENERAL_TIM_Init(void)
{
    GENERAL_TIM_GPIO_Config();
    GENERAL_TIM_Mode_Config();
}

static void ADVANCE_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    NVIC_InitStructure.NVIC_IRQChannel = ADVANCE_TIM_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void ADVANCE_TIM_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH1_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = ADVANCE_TIM_CH1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(ADVANCE_TIM_CH1_PORT, &GPIO_InitStructure);
}

static void ADVANCE_TIM_Mode_Config(void)
{
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = ADVANCE_TIM_PERIOD;
    TIM_TimeBaseStructure.TIM_Prescaler = ADVANCE_TIM_PSC;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);

    TIM_ICInitTypeDef TIM_ICInitStructure;
    TIM_ICInitStructure.TIM_Channel = ADVANCE_TIM_IC1PWM_CHANNEL;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    TIM_PWMIConfig(ADVANCE_TIM, &TIM_ICInitStructure);

    TIM_SelectInputTrigger(ADVANCE_TIM, TIM_TS_TI1FP1);

    TIM_SelectSlaveMode(ADVANCE_TIM, TIM_SlaveMode_Reset);
    TIM_SelectMasterSlaveMode(ADVANCE_TIM, TIM_MasterSlaveMode_Enable);

    TIM_ITConfig(ADVANCE_TIM, TIM_IT_CC1, ENABLE);
    TIM_ClearITPendingBit(ADVANCE_TIM, TIM_IT_CC1);

    TIM_Cmd(ADVANCE_TIM, ENABLE);
}

void ADVANCE_TIM_Init(void)
{
    ADVANCE_TIM_GPIO_Config();
    ADVANCE_TIM_NVIC_Config();
    ADVANCE_TIM_Mode_Config();
}

#endif
