#include "stm32f10x.h"
#include "led.h"

#define SOFT_DELAY Delay(0xFFFFFF);

void Delay(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount--);
}

int main(void)
{
    LED_GPIO_Config();

    while(1)
    {
//        LED1_ON;
//        SOFT_DELAY;
//        LED1_OFF;

//        LED2_ON;
//        SOFT_DELAY;
//        LED2_OFF;

        LED_DD;
        SOFT_DELAY;

        LED_DL;
        SOFT_DELAY;

        LED_LD;
        SOFT_DELAY;

        LED_LL;
        SOFT_DELAY;
    }
}
