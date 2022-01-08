#include <stdio.h>
#include <stdlib.h>

void Insert();

void DisplayEvents();

void DisplayCurrentEvents();

void DeleteExpired();

int main(){

	while(1){
		int option;
		printf("1 - Insert a new event\n");
		printf("2 - Display all events\n");
		printf("3 - Now?\n");
		printf("4 - Delete expired\n");
		printf("0 - Exit\n");
		int flag = 1;
		while(flag){
			printf("Please select an option: ");
			scanf("%d", &option);
			flag = 0;
			switch(option){
				case 0:
					exit(0);
				case 1:
					Insert();
					break;
				case 2:
					DisplayEvents();
					break;
				case 3:
					DisplayCurrentEvents();
					break;
				case 4:
					DeleteExpired();
					break;
				default:
					flag = 1;
					break;
			}
		}
	}
}	

void Insert(){
	printf("Insert!\n");
}

void DisplayEvents(){
	printf("DisplayAllEvents\n");
}

void DisplayCurrentEvents(){
	printf("DisplayCurrentEvent!\n");
}

void DeleteExpired(){
	printf("DeleteExpired!\n");
}

