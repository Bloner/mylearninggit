#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define pi M_PI

/*
∗ CSE 251 Project 1
∗ By: Leon
∗ Complete the following table:
∗     a    b     n     estimate
∗    −1    1  1883  1.178979838
∗     0   10  2028  0.489888070
∗ −1000 1000 18861  0.999796418
∗    10   15  1515  0.016860599
∗   0.1  0.2   138  0.096211811
*/

int main(){
	int n = 10;
	double a, b;

	printf("Enter a value for a: ");
	scanf("%lf", &a);
	printf("Enter a value for b: ");
	scanf("%lf", &b);
	printf("Integral evaluation\n");

	double step, I, pI;
	pI = -10000;
	while(n <= 100000){
		I = 0;
		step = (b - a) / n;

		for(int j = 1; j <= n; j++){
			double x = a + (j - 0.5) * step;
			double fx;
			if(x == 0)
				fx = 1;
			else
				fx = (sin(pi * x)) / (pi * x);
			I += fx * step;
		}
		printf("n: %d, %.9lf, %10.9e\n", n, I, fabs(I-pI));
		if(fabs(I-pI) <= 1e-10)
			break;
		n++;
		pI = I;
	}
	return 0;
}
