/*
 * main.c
 *
 *  Created on: Sep 23, 2024
 *      Author: shazz
 */
#include <stdio.h>

int main(void)
{
	char a, b, c, d, e, f;
	printf("Enter 6 characters of your choice : ");
	fflush(stdout);
	//scanf("%c %c %c %c %c %c", &a,&b,&c,&d,&e,&f);
	a = getchar();
	getchar(); // this is for taking an extra space between the characters
	b = getchar();
	getchar(); // this is for taking an extra space between the characters
	c = getchar();
	getchar(); // this is for taking an extra space between the characters
	d = getchar();
	getchar(); // this is for taking an extra space between the characters
	e = getchar();
	getchar(); // this is for taking an extra space between the characters
	f = getchar();

	printf("\nThe ASCII code of the input characters are %c=%d - %c=%d - %c=%d - %c=%d - %c=%d - %c=%d", a,a,b,b,c,c,d,d,e,e,f,f);
	fflush(stdout);

	printf("\nPress any key to exit the program");
	fflush(stdout);
	while (getchar() != '\n')
	{
		//this loop is just for keeping the console from shutting down unexpectedly.
	}
	getchar();
}

