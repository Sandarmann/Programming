#include <stdio.h>
#include <stdlib.h>
typedef struct node{

	int val;
	struct node * next;
} node_t;

int getLength(node_t* node){
	int i = 0;
	while(node != NULL){
		i++;
		node = node->next;
	}
	return i;
}

int main(){
	node_t * head = NULL;
	head = malloc(sizeof(node_t));
	if(head == NULL){
		return 1;
	}

	head->val = 1;
	head->next = NULL;
	printf("Length of node: %d", getLength(head));	
}
