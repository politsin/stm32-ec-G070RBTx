/*
 * delay_micros.c
 *
 *  Created on: 29 сент. 2019 г.
 *      Author: dima
 */
#include "main.h"
#include "tim.h"
#include "delay_micros.h"

#define DWT_CONTROL *(volatile unsigned long *)0xE0001000
#define SCB_DEMCR *(volatile unsigned long *)0xE000EDFC

void DWT_Init(void) {
  // SCB_DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; // разрешаем использовать счётчик
  // DWT_CONTROL |= DWT_CTRL_CYCCNTENA_Msk; // запускаем счётчик
}

void delay_us(uint32_t us) {
  __HAL_TIM_SET_COUNTER(&htim3, 0); // set the counter value a 0
  while (__HAL_TIM_GET_COUNTER(&htim3) < us)
    ;
}
