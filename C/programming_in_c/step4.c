//Loops and repetition

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
	/*int i;
	while(1){
		printf("Number to compute the factorial of: ");
		scanf("%d", &i);
		if(i < 0)
			exit(1);
		else{
			printf("%d! = ", i);
			int res = 1;
			while(i > 0)
				res *= i--;
			printf("%d\n", res);
		}
	}*/
	double angle, sinVal;
	int numSteps;
	do{
		printf("Input the number of steps: ");
		scanf("%d", &numSteps);
	}while(numSteps < 2);
	double maxAngle = M_PI * 2;
	int i;
	for(i = 0;i <= numSteps; i++){
		angle = (double)i / (double)numSteps * maxAngle;
		sinVal = sin(angle);
		double width = 30 * (1 + sinVal);
		printf("%3d: %5.2lf", i, angle);
		while(width-- > 0)
			printf(" ");
		if(cos(angle) > 0)
			printf("\\\n");
		else if(cos(angle) < 0)
			printf("/\n");
		else
			printf("*\n");
	}
return 0;
}
