/*
 * main.c
 *
 *  Created on: Sep 30, 2024
 *      Author: shazz
 */

#include <stdio.h>
#include <stdint.h>

void wait_for_the_user_input(void);

int main (void){
	int32_t height;
	printf("Please enter the height of the pyramid: ");
	scanf("%d",&height);

	if(height<0){
		printf("Height of a pyramid can't be negative!");
		wait_for_the_user_input();
		return 0;
	}

	for(uint32_t i=1;i<=height; i++){
		for (uint32_t j = i ; j>0; j--){
			printf("%4u ", j);
		}

		printf("\n");
	}

	wait_for_the_user_input();
	return 0;
}

void wait_for_the_user_input(void){
	printf("Please press enter to end the program\n");

	while(getchar()!= '\n'){

	}
	getchar();
}
