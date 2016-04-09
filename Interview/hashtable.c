#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Structures that will set up the linked hashtable 
 */
typedef struct node{
	int val;
	struct node * next;
}node;

typedef struct hash{
	int size;
	struct node* array[];
}hash;


void insert(node* node, hash* hash){
	int pos = node->val % hash->size;
//	perror("POS: \n");// , pos);
	struct node* hashNode = hash->array[pos];
	if(hashNode == NULL){
//		perror("IF");
		hash->array[pos] = node;
//		printf("Value at pos: %d", hash->array[pos]->val);
	}
	else{
//		perror("ELSE");
		while(hashNode->next != NULL){
			hashNode = hashNode->next;
		}
		hashNode->next = node;
	}
//	perror("FINISH");

}

/*
 *This function iterates through all nodes and prints out data when available
 *
 */
void listAllNodes(hash* table){
	printf("SIZE: %d\n", table->size);
	for(int i=0; i<table->size; i++){
		if(table->array[i] != NULL){
			printf("Value %d", table->array[i]->val);
		}

		/*if(&table->array[i] != NULL){
			struct node* n = table->array[i];
			while(n!=NULL){
				printf("Value: %d", n->val);
				n = n->next;
			}
		}*/
	}
}

void listNodes(node* node){
	while(node != NULL){
		printf("Value %d: ", node->val);
		node = node->next;
	}
}


/*
 * This main function will instantiate my structure for the hashtable 
 *	In order to instantiate this you must mallow the structure of the objects you want the array to hold
 *	Then you must instantiate each object at the size of the array to NULL
 */
int main(){
	struct hash* table = malloc(sizeof(struct node) * 10 );
	table->size = 10;
	for(int i=0; i<table->size; i++){
		table->array[i] = NULL;
	}
	//perror("HEY");
	node* new = malloc(sizeof(node));
	new->val = 5;
	new->next = NULL;
	insert(new, table);

	node* n = malloc(sizeof(node));
	n->val = 8;
	n->next = NULL;
	insert(n, table);

	listAllNodes(table);	
//	printf("Value: %d", table->array[5]->val);
//	printf("Value: %d", table->array[8]->val);

}
