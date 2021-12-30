//K&R Chapter 6 Structures
#include <stdio.h>

// 6.5 self-referential structures
// binary search tree
struct tnode {
	char *word;
	int count;
	struct tnode *left; // you can't include the structure itself but you can do with the poiter to the structure.
	struct tnode *right;
int main(){
	return 0;
}

