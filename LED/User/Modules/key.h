#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"

#define KEY0_GPIO_CLK RCC_APB2Periph_GPIOE
#define KEY0_GPIO_PORT GPIOE
#define KEY0_GPIO_PIN GPIO_Pin_4

#define KEY1_GPIO_CLK RCC_APB2Periph_GPIOE
#define KEY1_GPIO_PORT GPIOE
#define KEY1_GPIO_PIN GPIO_Pin_3

#define KEY_ON 0
#define KEY_OFF 1

void Key_GPIO_Config(void);
// uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint8_t Key_Scan(void);

#endif /* __KEY_H */
