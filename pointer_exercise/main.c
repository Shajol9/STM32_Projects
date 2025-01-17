/*
 * main.c
 *
 *  Created on: Sep 23, 2024
 *      Author: shazz
 */

#include <stdio.h>

long long data = 0x0F85E47D889CF8A01;

int main(void)
{
	char c1 = 100;
	printf("Address of c1 is %p", &c1);
	char* p_c1 = &c1;
	char value_c1 = *p_c1;
	printf("\nValue of c1 is %d", value_c1);
	*p_c1 = 65;
	char new_value_c1 = *p_c1;
	printf("\nValue of c1 after changing it by addressing with pointer p_c1 is %d", new_value_c1);

	printf("\nThe address of data variable is %p", &data);
	char *p_address;
	p_address = (char*) &data;
	printf("\nValue at the address %p is %x",p_address, *p_address);// p_address should yeald in the address where the data variable is stored and *p_address is dereferencing the pointer to get the value of data variable

	int *p_address_1;
	p_address_1 = (int*) &data;
	printf("\nValue at the address %p is %x",&p_address_1, *p_address_1);// here &p_address yelds in the address where the pointer p_address is stored.

	long long *p_address_2;
	p_address_2 = (long long*) &data;
	printf("\nValue at the address %p is %llx\n",p_address_2, *p_address_2);

	while(getchar()!='\n')
	{

	}
	//getchar();
}
