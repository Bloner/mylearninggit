#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
	int val;
	struct LinkedList *next;
}LinkedList;

LinkedList *Create(int);

void pL(LinkedList*);

int main(){
	int i;
	scanf("%d", &i);
	LinkedList *head = Create(i);
	pL(head);
	return 0;
}

LinkedList *Create(int n){
	LinkedList *head, *node, *end;
	head = (LinkedList*)malloc(sizeof(LinkedList));
	end = head;

	for(int i = 0; i < n; i++){
		node = (LinkedList*)malloc(sizeof(LinkedList));
		scanf("%d", &end->val);
		if(i != n-1){
			end->next = node;
			end = node;
		}
		else{
			end->next = NULL;
			free(node);
		}
	}
	return head;
}

void pL(LinkedList *nd){
	LinkedList *head = nd;
	while(head != NULL){
		printf("%d",head->val);
		head = head->next;
	}
}
