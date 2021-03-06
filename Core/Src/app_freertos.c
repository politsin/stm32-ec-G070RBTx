/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "delay_micros.h"
#include "ds18b20.h"
#include "tim.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for blinkTask */
osThreadId_t blinkTaskHandle;
const osThreadAttr_t blinkTask_attributes = {
  .name = "blinkTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for ds18b20Task */
osThreadId_t ds18b20TaskHandle;
const osThreadAttr_t ds18b20Task_attributes = {
  .name = "ds18b20Task",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for ntcTask */
osThreadId_t ntcTaskHandle;
const osThreadAttr_t ntcTask_attributes = {
  .name = "ntcTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for numDisplayTask */
osThreadId_t numDisplayTaskHandle;
const osThreadAttr_t numDisplayTask_attributes = {
  .name = "numDisplayTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for uartTask */
osThreadId_t uartTaskHandle;
const osThreadAttr_t uartTask_attributes = {
  .name = "uartTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for ecTask */
osThreadId_t ecTaskHandle;
const osThreadAttr_t ecTask_attributes = {
  .name = "ecTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void startBlinkTask(void *argument);
void startDs18b20Task(void *argument);
void startNtcTask(void *argument);
void startNumDisplayTask(void *argument);
void startUartTask(void *argument);
void startEcTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of blinkTask */
  blinkTaskHandle = osThreadNew(startBlinkTask, NULL, &blinkTask_attributes);

  /* creation of ds18b20Task */
  // ds18b20TaskHandle = osThreadNew(startDs18b20Task, NULL, &ds18b20Task_attributes);

  /* creation of ntcTask */
  // ntcTaskHandle = osThreadNew(startNtcTask, NULL, &ntcTask_attributes);

  /* creation of numDisplayTask */
  // numDisplayTaskHandle = osThreadNew(startNumDisplayTask, NULL, &numDisplayTask_attributes);

  /* creation of uartTask */
  // uartTaskHandle = osThreadNew(startUartTask, NULL, &uartTask_attributes);

  /* creation of ecTask */
  ecTaskHandle = osThreadNew(startEcTask, NULL, &ecTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  HAL_GPIO_WritePin(PWR_ESP_GPIO_Port, PWR_ESP_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(PWR_ESP_GPIO_Port, PWR_ESP_Pin, GPIO_PIN_RESET);
  for(;;)
  {
    HAL_GPIO_WritePin(PWR_LED_GPIO_Port, PWR_LED_Pin, GPIO_PIN_SET);
    osDelay(950);
    HAL_GPIO_WritePin(PWR_LED_GPIO_Port, PWR_LED_Pin, GPIO_PIN_RESET);
    osDelay(50);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_startBlinkTask */
/**
* @brief Function implementing the blinkTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startBlinkTask */
void startBlinkTask(void *argument)
{
  /* USER CODE BEGIN startBlinkTask */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
    HAL_Delay(80);
    osDelay(1);
  }
  /* USER CODE END startBlinkTask */
}

/* USER CODE BEGIN Header_startDs18b20Task */
/**
* @brief Function implementing the ds18b20Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startDs18b20Task */
void startDs18b20Task(void *argument)
{
  /* USER CODE BEGIN startDs18b20Task */
  int16_t temp_ds18 = 0;
  setResolution(DS18B20_Resolution_12_bit);
  /* Infinite loop */
  for(;;)
  {
    // // flag_ds18b20 = 0;

    DB18B20_PORT->BSRR = (uint32_t)DB18B20_PIN << 16u;
    delay_us(DELAY_RESET);
    DB18B20_PORT->BSRR = DB18B20_PIN;
    delay_us(DELAY_RESET);

    writeByte(SKIP_ROM);
    writeByte(CONVERT_T);

    osDelay(750);
    DB18B20_PORT->BSRR = (uint32_t)DB18B20_PIN << 16u;
    delay_us(DELAY_RESET);
    DB18B20_PORT->BSRR = DB18B20_PIN;
    delay_us(DELAY_RESET);

    writeByte(SKIP_ROM);
    writeByte(READ_SCRATCHPAD);

    temp_ds18 = 0;

    for (uint8_t i = 0; i < 16; i++)
      temp_ds18 += (int16_t)readBit() << i;

    // temp_ds18 = (1000 * temp_ds18 / 16);
    osDelay(1);
  }
  /* USER CODE END startDs18b20Task */
}

/* USER CODE BEGIN Header_startNtcTask */
/**
* @brief Function implementing the ntcTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startNtcTask */
void startNtcTask(void *argument)
{
  /* USER CODE BEGIN startNtcTask */
  HAL_GPIO_WritePin(PWR_V25_GPIO_Port, PWR_V25_Pin, GPIO_PIN_RESET);
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startNtcTask */
}

/* USER CODE BEGIN Header_startNumDisplayTask */
/**
* @brief Function implementing the numDisplayTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startNumDisplayTask */
void startNumDisplayTask(void *argument)
{
  /* USER CODE BEGIN startNumDisplayTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startNumDisplayTask */
}

/* USER CODE BEGIN Header_startUartTask */
/**
* @brief Function implementing the uartTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startUartTask */
void startUartTask(void *argument)
{
  /* USER CODE BEGIN startUartTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startUartTask */
}

/* USER CODE BEGIN Header_startEcTask */
/**
* @brief Function implementing the ecTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startEcTask */
void startEcTask(void *argument)
{
  /* USER CODE BEGIN startEcTask */
  /* Infinite loop */
  HAL_GPIO_WritePin(PWR_EC_GPIO_Port, PWR_EC_Pin, GPIO_PIN_SET);
  // ?????????????????? PWM, ?? ???????????????? ?????????????? ?????? ?????????????? ??????3
  HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_1); 
  HAL_TIMEx_OCN_Start(&htim1, TIM_CHANNEL_1);
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startEcTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

