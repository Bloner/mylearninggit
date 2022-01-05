#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Empty 0
#define Wumpus 1
#define End 2
#define Pit 3

#define CaveSize 10
#define ArraySize (CaveSize + 2)

#define Left 0
#define Up 1
#define Right 2
#define Down 3
 
void CreateWorld(int [][ArraySize]);
int *GetEmptyRoom(int [][ArraySize]);
void DisplayWorld(int [][ArraySize], int *, int);
bool DisplayStatus(int [][ArraySize], int *, bool *);
int DifferenceByDirection(int);
void fire(int [][ArraySize], int *, int, bool *);

int main()
{
    int *agentRoom;
    int agentDirection;
	int d;
    char command[20];
	int cave[ArraySize][ArraySize];
	bool *hvKilled;
	*hvKilled = false;
    srand(time(NULL));
    
	CreateWorld(cave);
	agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 4;
    while(true){
		if(DisplayStatus(cave, agentRoom, hvKilled))
			break;
		DisplayWorld(cave, agentRoom, agentDirection);
        printf("Command: ");
        scanf("%20s", command);
        if(strcmp(command, "quit") == 0)
        {
            break;
        }
        else if(strcmp(command, "move") == 0){
			d = DifferenceByDirection(agentDirection);
            if(*(agentRoom + d) != End)
                agentRoom += d;
        }
        else if(strcmp(command, "turn") == 0){
			agentDirection ++;
            if(agentDirection > Down)
                agentDirection = Left;
        }
        else if(strcmp(command, "fire") == 0){
			fire(cave, agentRoom, agentDirection, hvKilled);
        }
        else{
            printf("I don't know what you are talking about\n");
        }
    }
    
}

void CreateWorld(int cave[ArraySize][ArraySize]){
	int i, j;
	int *room;
    for(i = 0;  i<ArraySize;  i++){
        for(j = 0;  j<ArraySize;  j++){
            if(i == 0 || j == 0 || i == ArraySize-1 || j == ArraySize-1)
                cave[i][j] = End;
            else
                cave[i][j] = Empty;
        }
    }
	room = GetEmptyRoom(cave);
	*room = Wumpus;
	for(i = 0;i < 10;i++){
		room = GetEmptyRoom(cave);
		*room = Pit;
	}
}

int *GetEmptyRoom(int cave[ArraySize][ArraySize]){
    int row, col;
    int *room;
    do{
        row = rand() % ArraySize;
        col = rand() % ArraySize;
        room = &cave[row][col];
    } while(*room != Empty);
    return room;
}

void DisplayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir){
    int row, col;
    int *room;
    
	for(row=1;  row <= CaveSize + 1;  row++){
        for(col=1; col<=CaveSize; col++){
            if(&cave[row][col] == agent && agentDir == Up)
                printf(" ^  ");
            else if(&cave[row-1][col] == agent && agentDir == Down)
                printf(" v  ");
            else
                printf("    ");
        }
        printf("\n");
        if(row > CaveSize)
            break;

        for(col=1; col<=CaveSize; col++){
            room = &cave[row][col];
            if(room == agent){
                switch(agentDir){
                case Left:
                    printf("<A  ");
                    break;
                case Right:
                    printf(" A> ");
                    break;
                default:
                    printf(" A  ");
                    break;
                }
                continue;
            }
            switch(*room){
            case Wumpus:
                printf("-W- ");
                break;
			case Pit:
				printf("-X- ");
				break;
            default:
                printf(" .  ");
                break;
            }
        }
		printf("\n");
    }
}

int DifferenceByDirection(int dir){
    switch(dir){
    case Up:
        return -ArraySize;
    case Down:
        return ArraySize;
    case Left:
        return -1;
    case Right:
        return 1;
    }
	return 0;
}

bool DisplayStatus(int cave[][ArraySize], int *agent, bool *k){
	if(*k){
		printf("You have killed the Wumpus successfully!\n");
		return true;
	}
	if(*agent == Wumpus){
		printf("You have been eaten by the Wumpus\n");
		return true;
	}
	if(*agent == Pit){
		printf("You fell into a pit\n");
		return true;
	}
	if(*(agent-1) == Wumpus || *(agent+1) == Wumpus || *(agent-ArraySize) == Wumpus || *(agent+ArraySize) == Wumpus){
		printf("I smell a Wumpus\n");
	}
	if(*(agent-1) == Pit || *(agent+1) == Pit || *(agent-ArraySize) == Pit || *(agent+ArraySize) == Pit){
		printf("I feel a draft\n");
	}
	return false;
}

void fire(int cave[][ArraySize], int *agent, int dir, bool *k){
	int *room;
	room = agent;
	int i;
	for(i = 1;i < 4;i++){
		room += DifferenceByDirection(dir);
		if(*room == End)
			break;
		else if(*room == Wumpus){
			*room = Empty;
			*k = true;
		}
	}
}
