#include "systick.h"
#include "core_cm3.h"
#include "misc.h"

static __IO u32 TimingDelay;

void SysTick_Init(void)
{
    if (SysTick_Config(SystemCoreClock / 100000))
    {
        while (1);
    }
}

void Delay_10us(__IO u32 nTime)
{
    TimingDelay = nTime;

    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

    while (TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    {
        TimingDelay--;
    }
}


void SysTick_Delay_Us(__IO uint32_t us)
{
    uint32_t i;
    if (SysTick_Config(SystemCoreClock / 1000000))
    {
        while (1);
    }

    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

    for (i = 0; i < us; i++)
    {
        while ( !((SysTick->CTRL) & (1 << 16)) );
    }

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void SysTick_Delay_Ms(__IO uint32_t ms)
{
    uint32_t i;
    if (SysTick_Config(SystemCoreClock / 1000))
    {
        while (1);
    }

    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

    for (i = 0; i < ms; i++)
    {
        while ( !((SysTick->CTRL) & (1 << 16)) );
    }

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
