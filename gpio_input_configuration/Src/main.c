/**
 ******************************************************************************
 * @file           : main.c
 * @author         : MSH
 * @brief          : Read GPIO input to control LED
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
#include <stdlib.h>

// pointer variables holding register address.
uint32_t	volatile		*const p_ClkCtrlReg			= (uint32_t*) 0x40021014; // RCC register address for enabling clock for GPIO peripheral.
uint32_t	volatile		*const p_gpioEModeReg		= (uint32_t*) 0x48001000; // Address for setting the PE mode as read.
uint32_t	volatile		*const p_gpioEPinOutReg		= (uint32_t*) 0x48001014; // Register address for writing to GPIO pin

uint32_t	volatile		*const p_gpioAModeReg		= (uint32_t*) 0x48000000; // Address for setting the PA mode as read.
uint32_t	const volatile	*const p_gpioAPinInputReg	= (uint32_t*) 0x48000010; // Register address for reading from GPIO pin

void delay1(void);
void delay2(void);
void gpio_initialization (void);


int main(void)
{
	gpio_initialization();
	while(1){

		// reading from the PA0 as input
		uint8_t pinState = (uint8_t) (*p_gpioAPinInputReg & 0x1);
		if (pinState){
			// configuring PE as output for blink all user LEDs with a delay
			*p_gpioEPinOutReg &= 0x0000;
			delay2();
			for (uint8_t i=9; i<16; i++){
				*p_gpioEPinOutReg |= (1<<i);//0x0200
				delay1();
				*p_gpioEPinOutReg &= 0x0000;
				delay1();
			}
			*p_gpioEPinOutReg |= 0x0100;
			delay1();
			*p_gpioEPinOutReg &= 0x0000;
			delay1();

			for(uint8_t i=0; i<3; i++){
				*p_gpioEPinOutReg |= 0xff00;
				delay2();
				*p_gpioEPinOutReg &= 0x0000;
				delay2();
			}

		}else{
			*p_gpioEPinOutReg |= 0xff00;
		}
	}

}

void delay1(void){
	for (int i=0; i<500000; i++);
}

void delay2(void){
	for (int i=0; i<100000; i++);
}

void gpio_initialization (void){
	// performing bitwise or operation to enable the
	// GPIO RCC clock for specific gpio.
	*p_ClkCtrlReg |= (1<<21); //mask value = 0x00200000
	*p_ClkCtrlReg |= (1<<17);

	// Set GPIO mode register as output
	// clear the 19th and 18th bit and then set them to 01,
	*p_gpioEModeReg &= ~(3<<24); // 0xfff3ffff;
	*p_gpioEModeReg |= 0x55550000;// (1<<18);

	// clear all 0th a 1st bit and keep it as it is
	// as 00 is configuration for input
	*p_gpioAModeReg &= ~(3<<0); // 0xfffffff3
}
