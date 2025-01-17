/*
 * main.h
 *
 *  Created on: Oct 9, 2024
 *      Author: shazz
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct {
	uint32_t DMA1_EN 	:1;
	uint32_t DMA2_EN 	:1;
	uint32_t SRAM_EN 	:1;
	uint32_t Reserved1 	:1;
	uint32_t FLITF_EN 	:1;
	uint32_t FMC_EN 	:1;
	uint32_t CRC_EN 	:1;
	uint32_t Reserved2 	:9;
	uint32_t GPIOH_EN 	:1;
	uint32_t GPIOA_EN 	:1;
	uint32_t GPIOB_EN 	:1;
	uint32_t GPIOC_EN 	:1;
	uint32_t GPIOD_EN 	:1;
	uint32_t GPIOE_EN 	:1;
	uint32_t GPIOF_EN 	:1;
	uint32_t GPIOG_EN 	:1;
	uint32_t TSC_EN 	:1;
	uint32_t Reserved3 	:3;
	uint32_t ADC12_EN 	:1;
	uint32_t ADC34_EN 	:1;
	uint32_t Reserved4 	:2;
}RCC_AHBENR_t;

typedef struct{
	uint32_t MODER_PIN00 	:2;
	uint32_t MODER_PIN01 	:2;
	uint32_t MODER_PIN02 	:2;
	uint32_t MODER_PIN03 	:2;
	uint32_t MODER_PIN04 	:2;
	uint32_t MODER_PIN05 	:2;
	uint32_t MODER_PIN06 	:2;
	uint32_t MODER_PIN07 	:2;
	uint32_t MODER_PIN08 	:2;
	uint32_t MODER_PIN09 	:2;
	uint32_t MODER_PIN10 	:2;
	uint32_t MODER_PIN11 	:2;
	uint32_t MODER_PIN12 	:2;
	uint32_t MODER_PIN13 	:2;
	uint32_t MODER_PIN14 	:2;
	uint32_t MODER_PIN15 	:2;
}GPIOx_MODER_t;

typedef struct{
	uint32_t ODR_PIN00 		:1;
	uint32_t ODR_PIN01 		:1;
	uint32_t ODR_PIN02 		:1;
	uint32_t ODR_PIN03 		:1;
	uint32_t ODR_PIN04 		:1;
	uint32_t ODR_PIN05 		:1;
	uint32_t ODR_PIN06 		:1;
	uint32_t ODR_PIN07 		:1;
	uint32_t ODR_PIN08 		:1;
	uint32_t ODR_PIN09		:1;
	uint32_t ODR_PIN10 		:1;
	uint32_t ODR_PIN11 		:1;
	uint32_t ODR_PIN12 		:1;
	uint32_t ODR_PIN13 		:1;
	uint32_t ODR_PIN14 		:1;
	uint32_t ODR_PIN15 		:1;
	uint32_t Researved		:16;
}GPIOx_ODR_t;

#endif /* MAIN_H_ */
