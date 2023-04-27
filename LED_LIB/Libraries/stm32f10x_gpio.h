#ifndef __STM32F10X_H__
	#include "stm32f10x.h"
#endif

#define GPIO_Pin_0 ((uint16_t)0x0001)
#define GPIO_Pin_1 ((uint16_t)0x0002)
#define GPIO_Pin_2 ((uint16_t)0x0004)
#define GPIO_Pin_3 ((uint16_t)0x0008)
#define GPIO_Pin_4 ((uint16_t)0x0010)
#define GPIO_Pin_5 ((uint16_t)0x0020)
#define GPIO_Pin_6 ((uint16_t)0x0040)
#define GPIO_Pin_7 ((uint16_t)0x0080)
#define GPIO_Pin_8 ((uint16_t)0x0100)
#define GPIO_Pin_9 ((uint16_t)0x0200)
#define GPIO_Pin_10 ((uint16_t)0x0400)
#define GPIO_Pin_11 ((uint16_t)0x0800)
#define GPIO_Pin_12 ((uint16_t)0x1000)
#define GPIO_Pin_13 ((uint16_t)0x2000)
#define GPIO_Pin_14 ((uint16_t)0x4000)
#define GPIO_Pin_15 ((uint16_t)0x8000)
#define GPIO_Pin_All ((uint16_t)0xFFFF)

typedef enum {
    GPIO_Speed_10MHz = 0x01, // 01
    GPIO_Speed_2MHz = 0x02,  // 10
    GPIO_Speed_50MHz = 0x03, // 11

} GPIOSpeed_TypeDef;

typedef enum
{
    GPIO_Mode_AIN = 0x00, // 0000 0000
    GPIO_Mode_IN_FLOATING = 0x04, // 0000 0100
    GPIO_Mode_IPD = 0x28, // 0010 1000
    GPIO_Mode_IPU = 0x48, // 0100 1000

    GPIO_Mode_Out_OD = 0x14, // 0001 0100
    GPIO_Mode_Out_PP = 0x10, // 0001 0000
    GPIO_Mode_AF_OD = 0x1C, // 0001 1100
    GPIO_Mode_AF_PP = 0x18, // 0001 1000

} GPIOMode_TypeDef; // b3b2

typedef struct
{
    uint16_t GPIO_Pin;

    // uint16_t GPIO_Speed;
    GPIOSpeed_TypeDef GPIO_Speed;

    // uint16_t GPIO_Mode;
    GPIOMode_TypeDef GPIO_Mode;

} GPIO_InitTypeDef;


void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);
