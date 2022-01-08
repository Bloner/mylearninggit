#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char buffer[2048];

int main(int argc, char **argv){
	puts("Lispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1){
		fputs("Lisp>", stdout);

		fgets(buffer, 2048, stdin);

		printf("No you're a %s\n", buffer);
		
	}
	return 0;
}
