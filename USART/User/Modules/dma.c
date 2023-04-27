#include "dma.h"

void DMA_Config(void)
{
    DMA_InitTypeDef DMA_InitStructure;

    RCC_AHBPeriphClockCmd(DMA_CLOCK, ENABLE);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) aSRC_Const_Buffer;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t) aDST_Buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;
    
    DMA_Init(DMA_CHANNEL, &DMA_InitStructure);
    DMA_ClearFlag(DMA_FLAG_TC);
    DMA_Cmd(DMA_CHANNEL, ENABLE);
}

uint8_t Buffercmp(const uint32_t* pBuffer, uint32_t* pBuffer1, uint16_t BufferLength)
{
    while(BufferLength--)
    {
        if(*pBuffer != *pBuffer1)
        {
            return 0;
        }
        pBuffer++;
        pBuffer1++;
    }
    return 1;
}
