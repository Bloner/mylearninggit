//Strings and file I/O
#include <stdio.h>
#include <string.h>

int StringLength(char[]);
void PrintLength(char[]);
void Reverse(char[]);

int main(int argc, char* argv[]){
	if(argc < 3){
		printf("insufficient arguments\n");
		return 1;
	}
	printf("Copy from file: %s\n", argv[1]);
	printf("Copy to file: %s\n", argv[2]);
	FILE *inFile;
	FILE *outFile;
	inFile = fopen(argv[1], "r");
	if(inFile == NULL){
		printf("Unable to open file %s\n", argv[1]);
		return 1;
	}
	outFile = fopen(argv[2], "w");
	if(outFile == NULL){
		printf("Unable to open file %s\n", argv[2]);
		return 1;
	}
	char line[120];
	while(!feof(inFile)){
		fgets(line, sizeof(line), inFile);
		if(strlen(line) > 0)
			line[strlen(line)-1] = '\0';
		Reverse(line);
		fprintf(outFile, "%s\n", line);
	}
	fclose(inFile);
	fclose(outFile);
#if 0
	char mySentence[80];
	int len;
	printf("Enter a sentence: ");
	fgets(mySentence, 80, stdin);
	len = strlen(mySentence);
	mySentence[len-1] = '\0';
	printf("The entered sentence is: %s\n", mySentence);
	PrintLength(mySentence);
	Reverse(mySentence);
	printf("%s\n", mySentence);
#endif
	return 0;
}

int StringLength(char str[]){
	int numChars = 0;
	while(str[numChars] != '\0')
		numChars++;
	return numChars;
}

void PrintLength(char str[]){
	printf("The string %s is %d characters long\n", str, StringLength(str));
}

void Reverse(char str[]){
	int front = 0;
	int back = strlen(str) - 1;
	char t;
	while(front < back){
		t = str[front];
		str[front] = str[back];
		str[back] = t;
		front++;
		back--;
	}
}
