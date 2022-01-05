//Functions
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void PrintCard(int, int);
int PrintResult(int, int, int, int);
int main()
{
    int suit1, suit2;
    int card1, card2;
	int result = 0;
	do{
		if(!result){
			srand(time(NULL));
			suit1 = rand() % 4;
			card1 = rand() % 13 + 1;
			suit2 = rand() % 4;
			card2 = rand() % 13 + 1;
		}
		else{
			int shift = (rand()%2)*2-1;
			if(shift+card1==0)
				card1 = 13;
			else if(shift + card1 == 14)
				card1 = 1;
			else
				card1 += shift;
		}
		printf("Player 1: ");
		PrintCard(card1, suit1); 
		printf("\n");
		printf("Player 2: ");
		PrintCard(card2, suit2); 
		printf("\n");
		result = PrintResult(card1, suit1, card2, suit2);
	}while(result);
}

void PrintCard(int card, int suit){
    switch(card){
    case 1:
        printf("Ace");
        break;        
    case 11:
        printf("Jack");
        break;
    case 12:
        printf("Queen");
        break;
    case 13:
        printf("King");
        break;
    default:
        printf("%d", card);
        break;
    }
    printf(" of ");
    switch(suit){
    case 0:
        printf("Hearts");
        break;
    case 1:
        printf("Diamonds");
        break;
    case 2:
        printf("Spades");
        break;
    case 3:
        printf("Clubs");
        break;
    }
}

int PrintResult(int card1, int suit1, int card2, int suit2){
	if(card1 == 1)
		card1 += 13;
	if(card2 == 1)
		card2 += 13;
	if(card1 > card2)
		printf("Player 1 wins\n");
	else if(card1 < card2)
		printf("Player 2 wins\n");
	else if(suit1 < suit2)
		printf("Player 1 wins\n");
	else if(suit1 > suit2)
		printf("Player 2 wins\n");
	else{
		printf("There is a tie\n");
		return 1;
	}
	return 0;
}
