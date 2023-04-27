#include "adc.h"

#ifdef __ADC_FIRST

static void ADCx_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    ADC_GPIO_APBxClock_FUN(ADC_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = ADC_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;

    GPIO_Init(ADC_PORT, &GPIO_InitStructure);
}

static void ADCx_Mode_Config(void)
{
    ADC_InitTypeDef ADC_InitStructure;

    ADC_APBxClock_FUN(ADC_CLK, ENABLE);

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;

    ADC_Init(ADCx, &ADC_InitStructure);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);
    ADC_RegularChannelConfig(ADCx, ADC_CHANNEL, 1, ADC_SampleTime_55Cycles5);
    ADC_ITConfig(ADCx, ADC_IT_EOC, ENABLE);
    ADC_Cmd(ADCx, ENABLE);

    ADC_ResetCalibration(ADCx);
    while(ADC_GetResetCalibrationStatus(ADCx));
    ADC_StartCalibration(ADCx);
    while(ADC_GetCalibrationStatus(ADCx));

    ADC_SoftwareStartConvCmd(ADCx, ENABLE);
}

static void ADC_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}

#endif // __ADC_FIRST

#ifdef __ADC_SECOND

static void ADCx_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    ADC_GPIO_APBxClock_FUN(ADC_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = ADC_PIN1 |
                                    ADC_PIN2 |
                                    ADC_PIN3 |
                                    ADC_PIN4 |
                                    ADC_PIN5 |
                                    ADC_PIN6;
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;

    GPIO_Init(ADC_PORT, &GPIO_InitStructure);
}

static void ADCx_Mode_Config(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;

    RCC_AHBPeriphClockCmd(ADC_DMA_CLK, ENABLE);
    ADC_APBxClock_FUN(ADC_CLK, ENABLE);

    DMA_DeInit(ADC_DMA_CHANNEL);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32) (&(ADC_x->DR));
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32) ADC_ConvertedValue;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = NOFCHANNEL;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

    DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructure);
    DMA_Cmd(ADC_DMA_CHANNEL, ENABLE);

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_NbrOfChannel = NOFCHANNEL;

    ADC_Init(ADC_x, &ADC_InitStructure);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL1, 1, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL2, 2, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL3, 3, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL4, 4, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL5, 5, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC_x, ADC_CHANNEL6, 6, ADC_SampleTime_55Cycles5);

    ADC_DMACmd(ADC_x, ENABLE);
    ADC_Cmd(ADC_x, ENABLE);

    ADC_ResetCalibration(ADC_x);
    while(ADC_GetResetCalibrationStatus(ADC_x));
    ADC_StartCalibration(ADC_x);
    while(ADC_GetCalibrationStatus(ADC_x));

    ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
}

#endif // __ADC_SECOND

#ifdef __ADC_THIRD

static void ADCx_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    ADCx_1_GPIO_APBxClock_FUN(ADCx_1_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = ADCx_1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(ADCx_1_PORT, &GPIO_InitStructure);

    ADCx_1_GPIO_APBxClock_FUN(ADCx_2_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = ADCx_2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(ADCx_2_PORT, &GPIO_InitStructure);
}

static void ADCx_Mode_Config(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    ADCx_1_APBxClock_FUN(ADCX_1_CLK, ENABLE);
    ADCx_2_APBxClock_FUN(ADCx_2_CLK, ENABLE);

    DMA_DeInit(ADC_DMA_CHANNEL);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&(ADCx_1->DR));
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADC_ConvertedValue;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = NOFCHANNEL;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

    DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructure);
    DMA_Cmd(ADC_DMA_CHANNEL, ENABLE);

    ADC_InitStructure.ADC_Mode = ADC_Mode_RegSimult;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = NOFCHANNEL;

    ADC_Init(ADCx_1, &ADC_InitStructure);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);
    ADC_RegularChannelConfig(ADCx_1, ADCx_1_CHANNEL, 1, ADC_SampleTime_239Cycles5);

    ADC_DMACmd(ADCx_1, ENABLE);

    ADC_InitStructure.ADC_Mode = ADC_Mode_RegSimult;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = NOFCHANNEL;

    ADC_Init(ADCx_2, &ADC_InitStructure);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);
    ADC_RegularChannelConfig(ADCx_2, ADCx_2_CHANNEL, 1, ADC_SampleTime_239Cycles5);

    ADC_ExternalTrigConvCmd(ADCx_2, ENABLE);

    ADC_Cmd(ADCx_1, ENABLE);
    ADC_ResetCalibration(ADCx_1);
    while (ADC_GetResetCalibrationStatus(ADCx_1));
    ADC_StartCalibration(ADCx_1);
    while (ADC_GetCalibrationStatus(ADCx_1));

    ADC_Cmd(ADCx_2, ENABLE);
    ADC_ResetCalibration(ADCx_2);
    while(ADC_GetResetCalibrationStatus(ADCx_2));
    ADC_StartCalibration(ADCx_2);
    while(ADC_GetCalibrationStatus(ADCx_2));

    ADC_SoftwareStartConvCmd(ADCx_1, ENABLE);
}

#endif // __ADC_THIRD

void ADCx_Init(void)
{
    ADCx_GPIO_Config();
    ADCx_Mode_Config();
    // ADC_NVIC_Config();
}
