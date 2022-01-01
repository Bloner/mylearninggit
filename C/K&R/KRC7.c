// K&R Chapter 7 Input and output

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int a, b, c;
	printf("plz enter three numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	printf("%d, %d, %d", a, b, c);
	//int c;
	//while((c = getchar()) != EOF)
	//	printf("%c ", c);
	return 0;
}

