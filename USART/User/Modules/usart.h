#ifndef __UART_H
#define __UART_H

#define STM32F10X_HD

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include <stdio.h>

// #define __USART_SECOND
#define __USART_DMA

#ifdef __USART_FIRST

#define DEBUG_USARTx UART4
#define DEBUG_USART_CLK RCC_APB1Periph_UART4
#define DEBUG_USART_APBxClkCmd RCC_APB1PeriphClockCmd
#define DEBUG_USART_BAUDRATE 115200


#define DEBUG_USART_GPIO_CLK (RCC_APB2Periph_GPIOC)
#define DEBUG_USART_GPIO_APBxClkCmd RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT GPIOC
#define DEBUG_USART_TX_GPIO_PIN GPIO_Pin_10
#define DEBUG_USART_RX_GPIO_PORT GPIOC
#define DEBUG_USART_RX_GPIO_PIN GPIO_Pin_11

#define DEBUG_USART_IRQ UART4_IRQn
#define DEBUG_USART_IRQHandler UART4_IRQHandler

#endif

#ifdef __USART_SECOND

#define DEBUG_USARTx USART1
#define DEBUG_USART_CLK RCC_APB2Periph_USART1
#define DEBUG_USART_APBxClkCmd RCC_APB2PeriphClockCmd
#define DEBUG_USART_BAUDRATE 115200


#define DEBUG_USART_GPIO_CLK (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_GPIO_APBxClkCmd RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT GPIOA
#define DEBUG_USART_TX_GPIO_PIN GPIO_Pin_9
#define DEBUG_USART_RX_GPIO_PORT GPIOA
#define DEBUG_USART_RX_GPIO_PIN GPIO_Pin_10

#define DEBUG_USART_IRQ USART1_IRQn
#define DEBUG_USART_IRQHandler USART1_IRQHandler

#endif

#ifdef __USART_DMA

#define DEBUG_USARTx USART1
#define DEBUG_USART_CLK RCC_APB2Periph_USART1
#define DEBUG_USART_APBxClkCmd RCC_APB2PeriphClockCmd
#define DEBUG_USART_BAUDRATE 115200

#define DEBUG_USART_GPIO_CLK (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_GPIO_APBxClkCmd RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT GPIOA
#define DEBUG_USART_TX_GPIO_PIN GPIO_Pin_9
#define DEBUG_USART_RX_GPIO_PORT GPIOA
#define DEBUG_USART_RX_GPIO_PIN GPIO_Pin_10

#define DEBUG_USART_IRQ USART1_IRQn
#define DEBUG_USART_IRQHandler USART1_IRQHandler

#define USART_TX_DMA_CHANNEL DMA1_Channel4
#define USART_DR_ADDRESS (USART1_BASE + 0x04)
#define SENDBUFF_SIZE 5000

#endif

void USART_Config(void);
void Usart_SendByte(USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString(USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord(USART_TypeDef * pUSARTx, uint16_t ch);
void USARTx_DMA_Config(void);

uint8_t SendBuff[SENDBUFF_SIZE];

#endif
