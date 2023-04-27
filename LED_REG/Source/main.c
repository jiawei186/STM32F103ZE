#include "stm32f10x.h"                  // Device header

void SystemInit(void)
{
}
	
int main(void)
{
//	RCC_APB2ENR |= (1 << 3);
//	
//	GPIOB_CRL &= ~(0x0F << (4*0));
//	GPIOB_CRL |= (1 << (4*0));
//	
//	GPIOB_ODR |= (0 << 0);
	
	RCC_APB2ENR |= (0x01 << 3);
	
	GPIOB_CRL &= ~(0x0F << (4 * 5));
	GPIOB_CRL |= (0x01 << (4 * 5));
	
	GPIOB_ODR &= ~(0x20);
	
	
	RCC_APB2ENR |= (0x01 << 6);
	
	GPIOE_CRL &= ~(0x0F << (4 * 5));
	GPIOE_CRL |= (0x01 << (4 * 5));
	
	GPIOE_ODR &= ~(0x20);
	
	while(1);
}
