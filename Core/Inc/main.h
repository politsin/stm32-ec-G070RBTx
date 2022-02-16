/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32g070xx.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void trans_to_usart1(char *buf);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_EC_Pin GPIO_PIN_0
#define ADC_EC_GPIO_Port GPIOA
#define ADC_NTC_Pin GPIO_PIN_1
#define ADC_NTC_GPIO_Port GPIOA
#define ADC_25_Pin GPIO_PIN_2
#define ADC_25_GPIO_Port GPIOA
#define ADC_33_Pin GPIO_PIN_3
#define ADC_33_GPIO_Port GPIOA
#define ADC_LiPo_Pin GPIO_PIN_4
#define ADC_LiPo_GPIO_Port GPIOA
#define PWR_EC_Pin GPIO_PIN_12
#define PWR_EC_GPIO_Port GPIOB
#define PWR_V25_Pin GPIO_PIN_14
#define PWR_V25_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOC
#define PWR_BTN_Pin GPIO_PIN_7
#define PWR_BTN_GPIO_Port GPIOC
#define sw1_Pin GPIO_PIN_8
#define sw1_GPIO_Port GPIOD
#define sw2_Pin GPIO_PIN_9
#define sw2_GPIO_Port GPIOD
#define sw3_Pin GPIO_PIN_10
#define sw3_GPIO_Port GPIOA
#define PWR_ESP_Pin GPIO_PIN_9
#define PWR_ESP_GPIO_Port GPIOC
#define PWR_LED_Pin GPIO_PIN_0
#define PWR_LED_GPIO_Port GPIOD
#define X_SCL_Pin GPIO_PIN_1
#define X_SCL_GPIO_Port GPIOD
#define X_SDA_Pin GPIO_PIN_2
#define X_SDA_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
