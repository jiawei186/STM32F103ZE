/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.6.0
  * @date    20-September-2021
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2011 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "stm32f10x_it.h"
#include "usart.h"
#include "adc.h"
#include "tim.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/* 
void DEBUG_USART_IRQHandler(void)
{
  uint8_t ucTemp;
  if (USART_GetITStatus(DEBUG_USARTx, USART_IT_RXNE) != RESET)
  {
    ucTemp = USART_ReceiveData(DEBUG_USARTx);
    USART_SendData(DEBUG_USARTx, ucTemp);
  }
}
 */

/* 
void ADC_IRQHandler(void)
{
  if(ADC_GetITStatus(ADCx, ADC_IT_EOC) == SET)
  {
    ADC_ConvertedValue = ADC_GetConversionValue(ADCx);
  }
  ADC_ClearITPendingBit(ADCx, ADC_IT_EOC);
}
 */

#if defined(__TIM_F)

extern volatile uint32_t time;

void BASIC_TIM_IRQHandler(void)
{
  if(TIM_GetITStatus(BASIC_TIM, TIM_IT_Update) != RESET)
  {
    time++;
    TIM_ClearITPendingBit(BASIC_TIM, TIM_FLAG_Update);
  }
}

#elif defined(__TIM_G_F)

extern volatile uint32_t time;

void ADVANCE_TIM_IRQHandler(void)
{
  if (TIM_GetITStatus(ADVANCE_TIM, TIM_IT_Update) != RESET)
  {
    time++;
    TIM_ClearITPendingBit(ADVANCE_TIM, TIM_FLAG_Update);
  }
}

#elif defined(__TIM_T_F)

void GENERAL_TIM_INT_FUN(void)
{
  if (TIM_GetITStatus(GENERAL_TIM, TIM_IT_Update) != RESET)
  {
    TIM_ICUserValueStructure.Capture_Period++;
    TIM_ClearITPendingBit(GENERAL_TIM, TIM_FLAG_Update);
  }

  if (TIM_GetITStatus(GENERAL_TIM, GENERAL_TIM_IT_CCx) != RESET)
  {
    if (TIM_ICUserValueStructure.Capture_StartFlag == 0)
    {
      TIM_SetCounter(GENERAL_TIM, 0);
      TIM_ICUserValueStructure.Capture_Period = 0;
      TIM_ICUserValueStructure.Capture_CcrValue = 0;

      GENERAL_TIM_OCxPolarityConfig_FUN(GENERAL_TIM, TIM_ICPolarity_Falling);
      TIM_ICUserValueStructure.Capture_StartFlag = 1;
    }
    else
    {
      TIM_ICUserValueStructure.Capture_CcrValue =
          GENERAL_TIM_GetCapturex_FUN(GENERAL_TIM);

      GENERAL_TIM_OCxPolarityConfig_FUN(GENERAL_TIM, TIM_ICPolarity_Rising);
      TIM_ICUserValueStructure.Capture_StartFlag = 0;
      TIM_ICUserValueStructure.Capture_FinishFlag = 1;
    }

    TIM_ClearITPendingBit(GENERAL_TIM, GENERAL_TIM_IT_CCx);
  }
}

#endif

#ifdef __TIM_PWM_IN

__IO uint16_t IC2Value = 0;
__IO uint16_t IC1Value = 0;
__IO float DutyCycle = 0;
__IO float Frequency = 0;

void ADVANCE_TIM_IRQHandler(void)
{
  TIM_ClearITPendingBit(ADVANCE_TIM, TIM_IT_CC1);

  IC1Value = TIM_GetCapture1(ADVANCE_TIM);
  IC2Value = TIM_GetCapture2(ADVANCE_TIM);

  if (IC1Value != 0)
  {
    DutyCycle = (float)((IC2Value + 1) * 100) / (IC1Value + 1);

    Frequency = (72000000 / (ADVANCE_TIM_PSC + 1)) / (float)(IC1Value + 1);
    printf("占空比：%0.2f%%   频率：%0.2fHz\n", DutyCycle, Frequency);
  }
  else
  {
    DutyCycle = 0;
    Frequency = 0;
  }
}

#endif

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


