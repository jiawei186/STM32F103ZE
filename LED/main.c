#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"

#define SOFT_DELAY Delay(0xFFFFFF);

void Delay(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount--);
}

int main(void)
{
    LED_GPIO_Config();
    Key_GPIO_Config();

    LED1_ON;
    LED2_ON;

    while(1)
    {
        // LED1_ON;
        // SOFT_DELAY;
        // LED1_OFF;

        // LED2_ON;
        // SOFT_DELAY;
        // LED2_OFF;

        // LED_DD;
        // SOFT_DELAY;

        // LED_DL;
        // SOFT_DELAY;

        // LED_LD;
        // SOFT_DELAY;

        // LED_LL;
        // SOFT_DELAY;

        // if (Key_Scan(KEY0_GPIO_PORT, KEY0_GPIO_PIN) == KEY_ON)
        // {
        //     LED1_TOGGLE;
        // }

        // if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
        // {
        //     LED2_TOGGLE;
        // }

        if (Key_Scan() == 1)
        {
            LED1_TOGGLE;
        } else if (Key_Scan() == 2)
        {
            LED2_TOGGLE;
        }
    }
}
