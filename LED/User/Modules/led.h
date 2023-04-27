#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"


#define LED1_GPIO_PORT GPIOB
#define LED1_GPIO_CLK RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN GPIO_Pin_5

#define LED2_GPIO_PORT GPIOE
#define LED2_GPIO_CLK RCC_APB2Periph_GPIOE
#define LED2_GPIO_PIN GPIO_Pin_5


#define digitalHi(p, i) {p->BSRR = i;}
#define digitalLo(p, i) {p->BRR = i;}
#define digitalToggle(p, i) {p->ODR ^= i;}

#define LED1_OFF digitalHi(LED1_GPIO_PORT, LED1_GPIO_PIN)
#define LED1_ON digitalLo(LED1_GPIO_PORT, LED1_GPIO_PIN)
#define LED1_TOGGLE digitalToggle(LED1_GPIO_PORT, LED1_GPIO_PIN)

#define LED2_OFF digitalHi(LED2_GPIO_PORT, LED2_GPIO_PIN)
#define LED2_ON digitalLo(LED2_GPIO_PORT, LED2_GPIO_PIN)
#define LED2_TOGGLE digitalToggle(LED2_GPIO_PORT, LED2_GPIO_PIN)


#define LED_DD \
    LED1_OFF \
    LED2_OFF 

#define LED_DL \
    LED1_OFF \
    LED2_ON

#define LED_LD \
    LED1_ON \
    LED2_OFF

#define LED_LL \
    LED1_ON \
    LED2_ON

void LED_GPIO_Config(void);

#endif
