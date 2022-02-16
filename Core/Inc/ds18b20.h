/*
 * ds18b20.h
 *
 *  Created on: 5 мая 2019 г.
 *      Author: dima
 */

#ifndef DS18B20_H_
#define DS18B20_H_

#include "main.h"

#define DB18B20_PORT          GPIOA
#define DB18B20_PIN           GPIO_PIN_11


#define DELAY_RESET           500
#define DELAY_WRITE_0         60
#define DELAY_WRITE_0_PAUSE   10
#define DELAY_WRITE_1         10
#define DELAY_WRITE_1_PAUSE   60
#define DELAY_READ_SLOT       10
#define DELAY_BUS_RELAX       10
#define DELAY_READ_PAUSE      50
#define DELAY_T_CONVERT       7600
#define DELAT_PROTECTION      5

typedef enum {
	SKIP_ROM = 0xCC,
	CONVERT_T = 0x44,
	READ_SCRATCHPAD = 0xBE,
	WRITE_SCRATCHPAD = 0x4E,
	TH_REGISTER = 0x4B,
	TL_REGISTER = 0x46,
} COMMANDS;

typedef enum {
	DS18B20_Resolution_9_bit 	= 0x1F,
	DS18B20_Resolution_10_bit 	= 0x3F,
	DS18B20_Resolution_11_bit 	= 0x5F,
	DS18B20_Resolution_12_bit 	= 0x7F
} DS18B20_Resolution;


void setResolution(DS18B20_Resolution resolution);
void ds18b20_getTemperature();
int16_t resTemperature();

void writeByte(uint8_t data);
uint8_t readBit();

#endif /* DS18B20_H_ */
