/*
 * main.c
 *
 *  Created on: Sep 23, 2024
 *      Author: shazz
 */
#include <stdio.h>


int main()
{
	    float a;
		float b;
		float c;
		float average;

		printf("Enter the first number a = ");
		fflush(stdout);
		scanf("%f", &a);

		printf("\nEnter the second number b = ");
		fflush(stdout);
		scanf("%f", &b);

		printf("\nEnter the third number c = ");
		fflush(stdout);
		scanf("%f", &c);


		average = (a+b+c)/3;
		printf("\nThe average of the 3 numbers that you entered is: %f", average);
		fflush(stdout);

		printf("\nPress any key to exit the program");
		while (getchar() !='\n')
		{

		}
		getchar();

}

