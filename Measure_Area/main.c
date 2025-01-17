/*
 * main.c
 *
 *  Created on: Sep 23, 2024
 *      Author: shazz
 */

#include <stdio.h>
#include <stdint.h>

void wait_for_user_input (void);
void wait_before_closing (void);


int main(void)
{
	float area;
	float base, height;
	float parallel1, parallel2;
	float radius;
	float side;
	float width, length;

	while(1){
	printf("Chose the geometric shape you want to measure the area of.\n "
			"Insert the corresponding letter for the shape or x to quit.\n "
			"Shape     - insert letter\n "
			"Triangle  -  t\n "
			"circle    -  c\n "
			"Trapezoid -  z\n "
			"Square    -  s\n "
			"Rectangle -  r\n "
			"exit program - x\n "
			"Insert your choice: ");
	uint8_t choice;
	scanf("%c",&choice);

	if (choice != 'x'){
	switch(choice){
	case 't':
		printf("Insert base length:");
		scanf("%f", &base);
		printf("Insert height:");
		scanf("%f", &height);
		if (height <0 || base<0){
			area = -1;
			printf("base or height of a triangle can not be negative\n");
		}else{
			area = 0.5 * base * height;
			printf("Area of the Triangle is %f", area);
		}
		break;
	case 'c':
		printf("Insert radius: ");
		scanf("%f", &radius);
		if (radius <0){
			area = -1;
			printf("Radius of a circle can not be negative!\n");
		}else{
			area = 3.1416 * radius * radius;
			printf("Area of the Circle is %f\n", area);
		}
		break;
	case 'z':
		printf("Insert the lengths of the parallel sides: \n");
		scanf("\%f %f", &parallel1, &parallel2);
		printf("Insert height: \n");
		scanf("%f", &height);
		if (parallel1<0 || parallel2<0 || height<0){
			area = -1;
			printf("length of any sides or height of a Trapezoid can not be zero\n");
		}else{
			area = (parallel1 + parallel2) * height/2;
			printf("Area of the Trapezoid is %f\n", area);
		}
		break;
	case 's':
		printf("Insert sides: ");
		scanf("%f", &side);
		if (side<0){
			area = -1;
			printf("Size length can't be negative\n");
		}else{
			area = side * side;
			printf("Area of the Square is %f\n", area);
		}
		break;
	case 'r':
		printf("Insert length and width: \n");
		scanf("%f %f", &length, &width);
		if (length<0||width<0){
			area = -1;
			printf("length or width can not be negative\n");
		}else{
			area = length * width;
			printf("Area of the Rectangle is %f\n", area);
		}
		break;
	default:
		printf("\nInvalid input. Please insert a valid letter from the list\n");
		area = -1;
		break;
	}
	}else{
		area = -1;
		//printf("Program is closing!\n");
		wait_before_closing();
		break;
	}

	if ( !(area < 0 ))
	{
		printf("Area %f \n", area);
	}
	wait_for_user_input();
	}

}

void wait_before_closing (void)
{
	printf("Press enter to end the program\n");

		while (getchar()!= '\n')
		{

		}
		getchar();
}

void wait_for_user_input (void)
{

	printf("Press enter to continue the program\n");

	while (getchar()!= '\n')
	{

	}
	getchar();
}


