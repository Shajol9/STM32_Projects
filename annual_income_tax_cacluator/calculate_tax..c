/*
 * calculate_tax..c
 *
 *  Created on: Sep 26, 2024
 *      Author: shazz
 */
#include<stdio.h>
#include<stdint.h>

float get_income();
void wait_for_user_input();

int main(void)
{
	uint64_t income, income_tax;

	float income_temp = get_income();
	if(income_temp < 0)
	{
		printf("Income can not be negative!\n");
		income_temp =  get_income();
	}
	income = (uint64_t) income_temp;

	if(income<=9525)
	{
		income_tax = 0 ;
	}else if((9525<income) && (income<=38700)){
		income_tax = income * 0.12;
	}else if ((38700<income) && (income<=82500)){
		income_tax = income * 0.22;
	}else {
		income_tax = (income * 0.32)+ 1000;
	}

	printf("Total Income Tax:$ %lld\n", income_tax);

	wait_for_user_input();
}

float get_income()
{
	float x = 0;
	printf("Input your annual in dollars:$");
	scanf("%f",&x);

	return x;
}

void wait_for_user_input(void){
	printf("Press enter to terminate the program!\n");
	while(getchar()!='\n'){

	}
	getchar();
}
