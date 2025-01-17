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
	int32_t num_a , num_b;
	uint32_t temp = 0;
	printf("Insert the smallest and the largest number of the rage for finding the even number in between them: ");
	scanf("%d %d", &num_a, &num_b);

	if(!(num_a < num_b)){
		printf("The starting number should be grater than the ending number!");
		wait_for_the_user_input();
		return 0;
	}

	printf("The even numbers are: \n");
	while ( num_a <= num_b ){
		if (num_a % 2 == 0){
			printf ("%4d ", num_a);
			++temp;
		}
		++num_a;
	}
	printf("\nThe total amount of even numbers between %d and %d is %u\n", num_a, num_b, temp);

	wait_for_the_user_input();

	return 0;
}

void wait_for_the_user_input(void){
	printf("Please press enter to end the program\n");

	while(getchar()!= '\n'){

	}
	getchar();
}
