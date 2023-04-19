#include "key.h"
#include "Delay.h"

void Key_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(KEY0_GPIO_CLK | KEY1_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin = KEY0_GPIO_PIN;
    GPIO_Init(KEY0_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
    GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
}

// uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
// {
//     if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
//     {
//         while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);
//         return KEY_ON;
//     } else
//     {
//         return KEY_OFF;
//     }
// }

uint8_t Key_Scan(void)
{
    uint8_t KeyNum = 0;

    if (GPIO_ReadInputDataBit(KEY0_GPIO_PORT, KEY0_GPIO_PIN) == KEY_ON)
    {
        Delay_ms(10);
        while (GPIO_ReadInputDataBit(KEY0_GPIO_PORT, KEY0_GPIO_PIN) == KEY_ON);
        Delay_ms(10);

        KeyNum = 1;
    }

    if (GPIO_ReadInputDataBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
    {
        Delay_ms(10);
        while (GPIO_ReadInputDataBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON);
        Delay_ms(10);

        KeyNum = 2;
    }

    return KeyNum;
}
