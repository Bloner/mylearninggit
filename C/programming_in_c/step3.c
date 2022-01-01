#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
	double income;
	printf("Please enter your annual income: ");
	scanf("%lf", &income);
	if(income < 9350){
		printf("The tax is 0\n");
		exit(0);
	}
	printf("What is your filing status?\n1) single\n2) married filing jointly\n3) married filing separately\nPlease enter a number: ");
	int dependents, sd;
	scanf("%d", &dependents);
	switch(dependents){
	case 1:
		sd = 5700;
		break;
	case 3:
		sd = 5700;
		dependents = 1;
		break;
	case 2:
		sd = 11400;
		printf("How many children do you have? ");
		int children;
		scanf("%d", &children);
		dependents += children;
		break;
	default:
		printf("error");
		exit(1);
	}
	double ti = income - (3650 * dependents + sd);
	double tax;
	if(ti<0)
		tax = 0;
	else if(ti < 16750)
		tax = 0.1 * ti;
	else if(ti < 68000)
		tax = 1675 + 0.15 * (ti - 16750);
	else if(ti < 137300)
		tax = 9362.5 + 0.25 * (ti - 68000);
	else
		tax= 26687.5 + 0.28 * (ti - 137300);
	printf("%.2lf", tax);
	return 0;
}
