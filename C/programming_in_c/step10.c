//state and state machines
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "step10_GarageLib.h"

#define DoorClosed 1
#define DoorOpening 2
#define DoorOpen 3
#define DoorClosing 4
#define DoorHeight 100
#define DoorTolerance 0

void StateDoorClosed(int *);
void StateDoorOpening(int *);
void StateDoorOpen(int *);
void StateDoorClosing(int *);
int IsGarageRunning();
void SetMotorPower(int);
int WasButtonPressed();
double GetDoorPosition();
int IsBeamBroken();
void ResetTimer();
double GetTimer();

int main(){
	int state = DoorClosed;
	while(IsGarageRunning()){
		switch(state){
		case DoorClosed:
			StateDoorClosed(&state);
			break;
	
		case DoorOpening:
			StateDoorOpening(&state);
			break;

		case DoorOpen:
			StateDoorOpen(&state);
			break;

		case DoorClosing:
			StateDoorClosing(&state);
			break;
		}
	}
	return 0;
}

void StateDoorClosed(int *state){
	if(WasButtonPressed()){
		SetMotorPower(1);
		*state = DoorOpening;
	}
}

void StateDoorOpening(int *state){
	if(GetDoorPosition() >= (DoorHeight - DoorTolerance)){
		SetMotorPower(0);
		*state = DoorOpen;
		ResetTimer();
	}
	else if(WasButtonPressed()){
		SetMotorPower(-1);
		*state = DoorClosing;
	}
}

void StateDoorOpen(int *state){
	if(GetTimer() > 10 || (WasButtonPressed() && !IsBeamBroken())){
		SetMotorPower(-1);
		*state = DoorClosing;
	}
}

void StateDoorClosing(int *state){
	if(IsBeamBroken){
		SetMotorPower(1);
		*state = DoorOpening;
		exit(0);
	}
	if(GetDoorPosition() < DoorTolerance){
		SetMotorPower(0);
		*state = DoorClosed;
	}
	else if(WasButtonPressed()){
		SetMotorPower(1);
		*state = DoorOpening;
	}
}
