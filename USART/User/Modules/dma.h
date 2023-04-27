#ifndef __DMA_H
#define __DMA_H

#define STM32F10X_HD

#include "stm32f10x.h"
#include "stm32f10x_conf.h"

#define DMA_CHANNEL DMA1_Channel6
#define DMA_CLOCK RCC_AHBPeriph_DMA1

#define DMA_FLAG_TC DMA1_FLAG_TC6

#define BUFFER_SIZE 32

const uint32_t aSRC_Const_Buffer[BUFFER_SIZE] =
{
    0x01020304, 0x05060708, 0x090A0B0C, 0x0D0E0F10,
    0x11121314, 0x15161718, 0x191A1B1C, 0x1D1E1F20,
    0x21222324, 0x25262728, 0x292A2B2C, 0x2D2E2F30,
    0x31323334, 0x35363738, 0x393A3B3C, 0x3D3E3F40,
    0x41424344, 0x45464748, 0x494A4B4C, 0x4D4E4F50,
    0x51525354, 0x55565758, 0x595A5B5C, 0x5D5E5F60,
    0x61626364, 0x65666768, 0x696A6B6C, 0x6D6E6F70,
    0x71727374, 0x75767778, 0x797A7B7C, 0x7D7E7F80
};

uint32_t aDST_Buffer[BUFFER_SIZE];
uint8_t Buffercmp(const uint32_t* pBuffer, uint32_t* pBuffer1, uint16_t BufferLength);
void DMA_Config(void);

#endif
