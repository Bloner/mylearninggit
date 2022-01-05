//Dynamic Memory Allocation

#include <stdio.h>
#include <stdlib.h>

#include "step14_RobotLib.h"

typedef struct Request{
	int machine;
	struct Request *next;
}Request;

void OnMachineRequest(int machine);
int CountRequests();

int request = 0;
Request *firstInLine = NULL;
Request *lastInLine = NULL;

int main(){
    printf("Robot System Startup\n");
    SimulatorStartup();

    SetMachineRequestHandler(OnMachineRequest);

    while(IsSimulatorRunning()){
		if(!IsRobotBusy() && firstInline != NULL){
            RobotGoTo(firstInline->machine);
			Request *wasFirst = firstInLine;
            firstInLine = firstInLine->next;
			if(firstInLine == NULL)
                lastInLine = NULL;
			free(wasFirst);
		}
		else if(!IsRobotBusy() && firstInline == NULL){
			if(GetTimer()>=3)
				RobotGoTo(0);
		}
		else if(IsRobotBusy())
			ResetTimer();
	}
    printf("Robot System Shutdown\n");
    SimulatorShutdown();
    return 0;
}

void OnMachineRequest(int machine){
    printf("Robot request from machine %d\n", machine);
	Request *newRequest = malloc(sizeof(Request));
	newRequest->machine = machine;
	newRequest->next = NULL;
	if(lastInline != NULL){
		lastInLine->next = newRequest;
        lastInLine = newRequest;
    }
    else{
        firstInLine = newRequest;
		lastInline = newRequest;
	}
	printf("There are %d pending requests\n", CountRequests());
}

int CountRequests(){
	int cnt = 0;
    Request *request = firstInline;
	while(*request != NULL){
		cnt++;
		request = request->next;
	}
    return cnt;
}
