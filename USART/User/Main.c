#include "stm32f10x.h"
#include "usart.h"
#include "led.h"
#include "systick.h"
#include "dma.h"
#include "adc.h"

// float ADC_ConvertedValueLocal;
// float ADC_ConvertedValueLocal[NOFCHANNEL];
float ADC_ConvertedValueLocal[NOFCHANNEL*2];

static void Show_Message(void)
{
    // printf("\r\n 通过串口通信指令控制RGB彩灯 \n");
    // printf("使用  USART  参数为：%d 8-N-1 \n", DEBUG_USART_BAUDRATE);
    // printf("1 - LD, 2 - DL \n");

    // printf("\r\n ADC单通道中断读取 \r\n");

    // printf("\r\n ADC多通道DMA读取 \r\n");

    printf("\r\n 双重ADC读取 \r\n");
}

int main(void)
{
    // USART_Config();

    // Usart_SendString(DEBUG_USARTx, "串口中断接收回显实验\n");

    LED_GPIO_Config();

    // Show_Message();

    // while (1);

    // char ch;
    // while(1)
    // {
    //     ch = getchar();
    //     printf("接收到字符：%c\n", ch);

    //     switch (ch)
    //     {
    //     case '1':
    //         LED_LD;
    //         break;

    //     case '2':
    //         LED_DL;
    //         break;

    //     default:
    //         Show_Message();
    //         break;
    //     }
    // }


    // uint8_t TransferStatus;

    // LED_LL;
    // SysTick_Delay_Ms(1000);

    // DMA_Config();

    // while(DMA_GetFlagStatus(DMA_FLAG_TC) == RESET);

    // TransferStatus = Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);

    // if(TransferStatus == 0)
    // {
    //     LED_LD;
    // } else
    // {
    //     LED_DL;
    // }

    // while(1);


    // uint16_t i;

    // USART_Config();
    // USARTx_DMA_Config();

    // for(i = 0; i < SENDBUFF_SIZE; i++)
    // {
    //     SendBuff[i] = 'P';
    // }

    // USART_DMACmd(DEBUG_USARTx, USART_DMAReq_Tx, ENABLE);

    // while(1)
    // {
    //     LED1_TOGGLE;
    //     SysTick_Delay_Ms(1000);
    // }


    // USART_Config();

    // ADCx_Init();

    // Show_Message();

    // while(1)
    // {
    //     ADC_ConvertedValueLocal = (float) ADC_ConvertedValue / 4096 * 3.3;

    //     printf("\r\n The current AD value = 0x%04X, %f \r\n\r\n\r\n", ADC_ConvertedValue, ADC_ConvertedValueLocal);

    //     SysTick_Delay_Ms(1000);
    // }


    // USART_Config();
    // ADCx_Init();

    // Show_Message();

    // while(1)
    // {
    //     ADC_ConvertedValueLocal[0] = (float)ADC_ConvertedValue[0] / 4096 * 3.3;
    //     ADC_ConvertedValueLocal[1] = (float)ADC_ConvertedValue[1] / 4096 * 3.3;
    //     ADC_ConvertedValueLocal[2] = (float)ADC_ConvertedValue[2] / 4096 * 3.3;
    //     ADC_ConvertedValueLocal[3] = (float)ADC_ConvertedValue[3] / 4096 * 3.3;
    //     ADC_ConvertedValueLocal[4] = (float)ADC_ConvertedValue[4] / 4096 * 3.3;
    //     ADC_ConvertedValueLocal[5] = (float)ADC_ConvertedValue[5] / 4096 * 3.3;

    //     printf(
    //         "\r\n CH0 value = %f V \r\n"
    //         "\r\n CH1 value = %f V \r\n"
    //         "\r\n CH2 value = %f V \r\n"
    //         "\r\n CH3 value = %f V \r\n"
    //         "\r\n CH4 value = %f V \r\n"
    //         "\r\n CH5 value = %f V \r\n\r\n\r\n",
    //         ADC_ConvertedValueLocal[0],
    //         ADC_ConvertedValueLocal[1],
    //         ADC_ConvertedValueLocal[1],
    //         ADC_ConvertedValueLocal[3],
    //         ADC_ConvertedValueLocal[4],
    //         ADC_ConvertedValueLocal[5]);
        
    //     SysTick_Delay_Ms(1000);
    // }


    uint16_t temp0 = 0, temp1 = 0;

    USART_Config();

    ADCx_Init();

    Show_Message();

    while(1)
    {
        temp0 = (ADC_ConvertedValue[0] & 0xFFFF0000) >> 16;
        temp1 = (ADC_ConvertedValue[0] & 0xFFFF);

        ADC_ConvertedValueLocal[0] = (float) temp0 / 4096 * 3.3;
        ADC_ConvertedValueLocal[1] = (float) temp1 / 4096 * 3.3;

        printf
        (
            "\r\n ADCx_1 value = %f V \r\n"
            "\r\n ADCx_2 value = %f V \r\n\r\n\r\n", 
            ADC_ConvertedValueLocal[1], 
            ADC_ConvertedValueLocal[0]
        );

        SysTick_Delay_Ms(1000);
    }
}
