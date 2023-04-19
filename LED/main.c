#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"

#define SOFT_DELAY Delay(0xFFFFFF);

void Delay(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount--);
}


#define BITBAND(addr, bitnum) ((addr & 0xF0000000) + 0x02000000 + ((addr & 0x00FFFFFF) << 5) + (bitnum << 2))

#define MEM_ADDR(addr) *((volatile unsigned long *)(addr))

#define BIT_ADDR(addr, bitnum) MEM_ADDR(BITBAND(addr, bitnum))

#define GPIOA_ODR_Addr (GPIOA_BASE + 0x0C)
#define GPIOB_ODR_Addr (GPIOB_BASE + 0x0C)
#define GPIOC_ODR_Addr (GPIOC_BASE + 0x0C)
#define GPIOD_ODR_Addr (GPIOD_BASE + 0x0C)
#define GPIOE_ODR_Addr (GPIOE_BASE + 0x0C)
#define GPIOF_ODR_Addr (GPIOF_BASE + 0x0C)
#define GPIOG_ODR_Addr (GPIOG_BASE + 0x0C)

#define GPIOA_IDR_Addr (GPIOA_BASE + 0x08)
#define GPIOB_IDR_Addr (GPIOB_BASE + 0x08)
#define GPIOC_IDR_Addr (GPIOC_BASE + 0x08)
#define GPIOD_IDR_Addr (GPIOD_BASE + 0x08)
#define GPIOE_IDR_Addr (GPIOE_BASE + 0x08)
#define GPIOF_IDR_Addr (GPIOF_BASE + 0x08)
#define GPIOG_IDR_Addr (GPIOG_BASE + 0x08)

#define PAout(n) BIT_ADDR(GPIOA_ODR_Addr, n)
#define PAin(n) BIT_ADDR(GPIOA_IDR_Addr, n)

#define PBout(n) BIT_ADDR(GPIOB_ODR_Addr, n)
#define PBin(n) BIT_ADDR(GPIOB_IDR_Addr, n)

#define PCout(n) BIT_ADDR(GPIOC_ODR_Addr, n)
#define PCin(n) BIT_ADDR(GPIOC_IDR_Addr, n)

#define PDout(n) BIT_ADDR(GPIOD_ODR_Addr, n)
#define PDin(n) BIT_ADDR(GPIOD_IDR_Addr, n)

#define PEout(n) BIT_ADDR(GPIOE_ODR_Addr, n)
#define PEin(n) BIT_ADDR(GPIOE_IDR_Addr, n)

#define PFout(n) BIT_ADDR(GPIOF_ODR_Addr, n)
#define PFin(n) BIT_ADDR(GPIOF_IDR_Addr, n)

#define PGout(n) BIT_ADDR(GPIOG_ODR_Addr, n)
#define PGin(n) BIT_ADDR(GPIOG_IDR_Addr, n)


int main(void)
{
    LED_GPIO_Config();
    Key_GPIO_Config();

    // LED1_ON;
    // LED2_ON;

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


        // if (Key_Scan() == 1)
        // {
        //     LED1_TOGGLE;
        // } else if (Key_Scan() == 2)
        // {
        //     LED2_TOGGLE;
        // }

        PBout(5) = 0;
        Delay_s(2);

        PBout(5) = 1;
        Delay_s(2);

        PEout(5) = 0;
        Delay_s(2);

        PEout(5) = 1;
        Delay_s(2);
    }
}
