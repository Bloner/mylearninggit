// Review and Practice
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//simple lunar lander program

int main(){
	#if 0
	int fn1 = 1;
	int fn2 = 0;
	int f;
	int i;
	printf("F(0) = 0\n");
	printf("F(1) = 1\n");

	for(i = 0; i < 10; i++){
		printf("F(%d) = ", i+2);
		f = fn1 + fn2;
		printf("%d\n", f);
		fn2 = fn1;
		fn1 = f;
	}
	#endif
	printf("Lunar Lander - (c) 2012, by Leon\n");
	double altitude = 100;
	double velocity = 0;
	double fuel = 100;
	double power = 1.5;
	double g = -1.63;
	double burn;
	int time = 0;
	while(altitude > 0){
		printf("Altitude: %.2f\n", altitude);
		printf("Velocity: %.2f\n", velocity);
		printf("You have %.1f kilograms of fuel\n", fuel);
		bool valid = false;
		do{
			printf("How much fuel would you like to burn: ");
			scanf("%lf", &burn);
			if(burn < 0)
				printf("You can't burn negative fuel\n");
			else if(burn > fuel)
				printf("You can't burn fuel you don't have\n");
			else if(burn > 5)
				printf("You can burn no more than 5 kilograms per second\n");
			else{
				printf("Burning %.1f kilograms of fuel\n", burn);
				valid = true;
			}
		}while(!valid);
		velocity = velocity + g + power * burn;
		altitude += velocity;
		fuel -= burn;
		++time;
	}
	printf("You landed with a velocity of %.2f\n", velocity);
	printf("You landed in %d seconds\n", time);
	printf("The amount of fuel remaining is %.1lf kilograms\n", fuel);
	if(fabs(velocity) > 3)
		printf("Your next of kin have been notified\n");
	return 0;
}
