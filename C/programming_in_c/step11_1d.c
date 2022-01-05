//Pointers, Arrays, Multidimensional Arrays

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Empty 0
#define Wumpus 1
#define End 2
#define CaveSize 20
#define ArraySize (CaveSize + 2)

#define Left 0
#define Right 1

void CreateWorld(int []);
int *GetEmptyRoom(int []);
void DisplayWorld(int [], int *, int);
int DifferenceByDirection(int);
bool DisplayStatus(int [], int *);
void fire(int [], int *, int);

int main(){
	int cave[ArraySize];
	int *agentRoom, *room;
	int agentDirection;
	char command[20];
	int direction;

	srand(time(NULL));
	CreateWorld(cave);
	agentRoom = GetEmptyRoom(cave);
	agentDirection = rand()%2;

	while(true){
		if(DisplayStatus(cave, agentRoom))
			break;
		DisplayWorld(cave, agentRoom, agentDirection);
		printf("Command: ");
		scanf("%20s", command);
		if(strcmp(command , "quit") == 0)
			break;
		else if(strcmp(command, "move") == 0){
			direction = DifferenceByDirection(agentDirection);
			if(*(agentRoom + direction) != End)
				agentRoom += direction;
		}
		else if(strcmp(command, "turn") == 0)
			agentDirection = !agentDirection;
		else if(strcmp(command, "fire") == 0)
			fire(cave, agentRoom, agentDirection);
		else
			printf("I don't know what you are talking about\n");
	}
	return 0;
}

void CreateWorld(int cave[]){
	int i;
	int *room;
	for(i = 0;i < ArraySize;i++)
		cave[i] = Empty;
	cave[0] = End;
	cave[ArraySize-1] = End;
	room = GetEmptyRoom(cave);
	*room = Wumpus;
}

void DisplayWorld(int cave[], int *agent, int agentDir){
	int *room;
	for(room = cave + 1;*room != End; room++){
		if(room == agent){
			switch(agentDir){
				case Left:
					printf("<A  ");
					break;
				case Right:
					printf(">A  ");
					break;
			}
			continue;
		}
		switch(*room){
		case Wumpus:
			printf("-W-");
			break;
		default:
			printf(" .  ");
			break;
		}
	}
	printf("\n");
}

int *GetEmptyRoom(int cave[]){
	int room;
	do{
		room = rand() % ArraySize;
	}while(cave[room] != Empty);
	return &cave[room];
}

int DifferenceByDirection(int dir){
	if(dir == Left)
		return -1;
	else
		return 1;
}

bool DisplayStatus(int cave[], int *agent){
	int i;
	for(i = 0;i < ArraySize;i++){
		if(cave[i] == Wumpus){
			if(*agent == Wumpus){
				printf("You have been eaten by the Wumpus\n");
				return true;
			}
			if(*(agent-1) == Wumpus || *(agent+1) == Wumpus)
				printf("I smell a Wumpus\n");
			return false;
		}
	}
	printf("You have killed the Wumpus successfully!\n");
	return true;
}

void fire(int cave[], int *agent, int dir){
	int i;
	int sign = DifferenceByDirection(dir);
	for(i = 1;i < 4 && (*(agent + sign * i) != End);i++){
		*(agent + sign * i) = Empty;
	}
}
