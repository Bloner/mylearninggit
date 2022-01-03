#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "step13_transistors.h"

void DisplayTransistor(Transistor tran);
Transistor InputTransistor(void);
void InputString(char *, int);
double InputPositiveValue(char *);
int InputTransistorType(char *);
int InputTransistorCaseStyle(char *);

int main()
{
	int i;
	Transistor *trans;
	int numTrans = 0;
    printf("transistors!\n");
	trans= malloc(sizeof(Transistor));
	numTrans = 0;
	char enter;
	do{
		trans = realloc(trans, sizeof(Transistor) * (numTrans++ + 1));
		trans[numTrans - 1] = InputTransistor();
		printf("Would you like to enter another transistor (Y/N)?");
		scanf("%c", &enter);
	}while(enter == 'Y' || enter == 'y');
	printf("\nThe transistors:\n");
	for(i = 0;i < numTrans;i++)
		DisplayTransistor(trans[i]);
	free(trans);
	return 0;
}

void DisplayTransistor(Transistor tran){
	printf("Number: %s\n", tran.number);
	switch(tran.type){
	case NPN:
		printf("Type: NPN\n");
		break;
	
	case PNP:
		printf("Type: PNP\n");
		break;
	}
	switch(tran.caseStyle){
	case TO18:
		printf("caseStyle: TO18\n");
		break;

	case TO92A:
		printf("caseStyle: TO92A\n");
		break;

	case TO92C:
		printf("caseStyle: TO92C\n");
		break;
	
	case TO220:
		printf("caseStyle: TO220\n");
		break;
	
	case TO39:
		printf("caseStyle: TO39\n");
		break;
	}

	printf("pMax: %.3f\n", tran.pmax);
	printf("icMax: %.3f\n", tran.icmax);
}

Transistor InputTransistor(void){
	Transistor t1;
	InputString(t1.number, sizeof t1.number);
	t1.type = InputTransistorType("Input type: ");
	t1.caseStyle = InputTransistorCaseStyle("Input case style: ");
	t1.icmax = InputPositiveValue("Input icMax: ");
	t1.pmax = InputPositiveValue("Input pMax: ");
	return t1;
}

void InputString(char *str, int max)
{
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);
    if(strlen(buffer) > 0)
        buffer[strlen(buffer)-1] = '\0';
    strncpy(str, buffer, max);
    str[max-1] = '\0';
}

double InputPositiveValue(char *prompt)
{
    char buffer[100];
    double value = 0;
    do
    {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';
        sscanf(buffer, "%lf", &value);
    } while(value <= 0);
    return value;
}

int InputTransistorType(char *prompt){
	int value;
	char buffer[100];
	do{
		printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';
        sscanf(buffer, "%d", &value);
	}while(value != 1 && value != 2);
	return value;
}

int InputTransistorCaseStyle(char *prompt){
	char buffer[100];
	int value;
	do{
		printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';
        sscanf(buffer, "%d", &value);
	}while(value < 1 || value > 5);
	return value;
}
