//Pointers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void InputQuadraticEquation(double *a, double *b, double *c);
void QuadraticEquation(double, double, double, double *, double *, double *, double *);

int main()
{
    double a, b, c;
    double z1r, z1i;
    double z2r, z2i;
    
	InputQuadraticEquation(&a, &b, &c);
	QuadraticEquation(a, b, c, &z1r, &z1i, &z2r, &z2i);
    printf("Zero 1: %f + %fj\n", z1r, z1i);
    printf("Zero 2: %f + %fj\n", z2r, z2i);
}

void InputQuadraticEquation(double *a, double *b, double *c)
{
    printf("Input a: ");
    scanf("%lf", a);
    printf("Input b: ");
    scanf("%lf", b);
    printf("Input c: ");
    scanf("%lf", c);
}

void QuadraticEquation(double a, double b, double c, double *pZ1r, double *pZ1i, double *pZ2r, double *pZ2i){
	double discriminant = b * b - 4 * a * c;
    if(discriminant >= 0)
    {
        *pZ1r = (-b + sqrt(discriminant)) / (2 * a);
        *pZ2r = (-b - sqrt(discriminant)) / (2 * a);
        *pZ1i = 0;
        *pZ2i = 0;
    }
    else
    {
        *pZ1r = -b / (2 * a);
        *pZ2r = *pZ1r;
        *pZ1i = sqrt(-discriminant) / (2 * a);
        *pZ2i = -sqrt(-discriminant) / (2 * a);
    }
}
