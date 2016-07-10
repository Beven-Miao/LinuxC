/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define RANG 100
#define N 6

void printf_item(link p)
{
	printf("%d", p->item);
}

int main()
{
	int i,key;
	link root = NULL;
	srand(time(NULL));
	for(i = 0; i<N; i++)
		root = insert(root,rand()%RANG);
	printf("\t\\tree");
	print_tree(root);
	printf("\n\n");
	while(root){
		key = rand()%RANG;
		if(search(root,key)){
			printf("delete %d in tree\n", key);
			root = delete(root,key);
			printf("\t\\tree");
			print_tree(root);
			printf("\n\n");
		}
	}
}
