#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

typedef struct stack{
	int size;
	node arr  [];
	node* head;
}stack;

void push(node* node, stack* stack){
	node->next = stack->head;
	stack->head = node;
}

node* pop(stack* stack){
	node* n = stack->head;
	stack->head = n->next;
	return n;
}	

int main(){
	struct stack* sta =  malloc(sizeof(node) * 10);	
	sta->size = 10;
	for(int i=0; i<sta->size; i++){
		sta->array[i] = NULL;
	}
	node* new = malloc(sizeof(node));
	new->val = 5;
	new->next = NULL;

	push(new, sta);
}
