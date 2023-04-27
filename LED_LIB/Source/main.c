#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"

void SystemInit(void)
{
}

int main(void)
{
    // RCC->APB2ENR |= (1 << 3);

    // GPIOB->CRL &= ~(0x0F << (4 * 5));
    // GPIOB->CRL |= (0x01 << (4 * 5));

    // GPIOB->ODR &= ~(0x01 << 5);

    // while (1);


    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2ENR |= (0x01 << 3);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;

    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOB, GPIO_Pin_5);


    RCC_APB2ENR |= (0x01 << 6);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;

    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOE, GPIO_Pin_5);

    while (1);


    // while (1)
    // {
    //     GPIO_ResetBits(GPIOB, GPIO_Pin_5);

    //     Delay(0xFFFF);

    //     GPIO_SetBits(GPIOB, GPIO_Pin_5);

    //     Delay(0xFFFF);
    // }
}
