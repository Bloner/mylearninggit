#ifndef STEP13_TRANSISTORS_H
#define STEP13_TRANSISTORS_H

#define NPN 1
#define PNP 2

#define TO18 1
#define TO92A 2
#define TO92C 3
#define TO220 4
#define TO39 5

typedef struct Transistor{
	char number[10];
	int type;
	int caseStyle;
	double pmax;
	double icmax;
}Transistor;

#endif
