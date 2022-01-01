#include <stdio.h>
#include <math.h>
//this is my first CSE 251 C program.

int main(){
	double radius = 7.88;
	double height = 12.231;
	printf("The cylinder has a radius of %+.2f and a height of %+.2f\n", radius, height);
	
	int wins = 11;
	int losses = 2;
	printf("MSU had an %d-%d season in 2010!\n", wins, losses);
	
	double volume, hypot;
	int games;
	games = wins + losses;
	volume = radius * radius * M_PI * height;
	double near = 10;
	double far = 22.5;
	hypot = sqrt(near * near + far * far);

	double bottleVolume = 1700;
	double cupVolume = 350;
	int numCups;
	numCups =(int) bottleVolume / cupVolume;
	printf("Number of cups: %d\n", numCups);

	double capa, induc;
	printf("Input Capacitance (microfarads): ");
	scanf("%lf", &capa);
	printf("Input Inductance (millihenrys): ");
	scanf("%lf", &induc);
	printf("Resonant Frequency is %.3lf\n", 1000/(sqrt(0.001*capa*induc)*2*M_PI));

	//There are two levels of libraries in C. There are those that are already available, like the standard input/output library, and those that have to be linked to your program. 
}
