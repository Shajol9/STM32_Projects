/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "main.h"


void delay(void){
	for (int i=0; i<1000000; i++);
}

int main(void)
{
	// creating a pointer variable of RCC_AHBENR_t structure
	RCC_AHBENR_t 	volatile *const	p_gpioclockEnReg = (RCC_AHBENR_t *) 0x40021014; // sorting the base address of the RCC_AHBENR register in the pointer.
	// creating a pointer variable of GPIOx_MODER_t structure
	GPIOx_MODER_t 	volatile *const	p_gpioPinModeReg = (GPIOx_MODER_t *) 0x48001000; // sorting the base address of the GPIOx_MODER register in the pointer.
	// creating a pointer variable of GPIOx_ODR_t structure
	GPIOx_ODR_t  	volatile *const	p_gpioPinOutReg = (GPIOx_ODR_t *) 0x48001014; // sorting the base address of the GPIOx_ODR register in the pointer.


	p_gpioclockEnReg->GPIOE_EN 		= 1; // this commend is converted to *(0x40021014)|= (1<<21) by the compiler;
	p_gpioPinModeReg->MODER_PIN09 	= 0; // clearing the pin, compiler converts this to *(0x48001000)|= (0<18)
	p_gpioPinModeReg->MODER_PIN09 	= 1; // sets the pin, compiler converts this to *(0x48001000)|= (1<18)

	while(1){
		p_gpioPinOutReg->ODR_PIN09 = 1;
		delay();
		p_gpioPinOutReg->ODR_PIN09 = 0;
		delay();
	}

}