#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#define SENTINEL -9999999999
#define DEBUG 0
#define OFFICIAL 1
#ifndef MODE
	#define MODE DEBUG
#endif

void maxHeapify(int A[], int i);
int left(int i);
int right(int i);
int parent(int i);
void exchange(int A[], int i, int j);
int heapMax(int A[]);
int heapExtract(int A[]);
int arraySize(int A[]);
void buildMaxHeap(int A[]);
void heapsort(int A[]);
void heapIncrease(int A[], int i, int key);
void heapInsert(int A[], int key);
void showBinaryHeap(i, depth);
int heapSize;


int main(int argc, char *argv[]){
	
	
}

int maxHeapify(int A[], int i){
	int l = Left(i);
	int r = Right(i);
	int largest;
	if(DEBUG){
		printf("Left is: '%d'", l);
		printf("Right is: '%d'", r);
		printf("Size of array is: '%d'", ArraySize(A));
	}
	
	if(l <= heapSize && A[l]>A[i]){
		largest = l;
	}else{
		largest = i;
	}
	
	if(r <= heapSize && A[r]>[largest]){
		largest = r;
	}

	if(largest != i){
		
		if(DEBUG){
			printf("the swapped values before are, '%d', '%d' ", A[i], A[largest]);
		}
		
		Exchange(A, i, largest);
		if(DEBUG){
			printf("the swapped values are now, '%d', '%d' ", A[i], A[largest]);
		}
		MaxHeapify(A, largest);
	}
	
}

int left(int i){
	return 2i;
}


int right(int i){
	return 2i+1;
}

int parent(int i){
	return [i/2];
}

void exchange(int A[], int i, int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int heapMax(int A[]){
	return A[1];
}

int arraySize(int A[]){
	return sizeof(A)/sizeof(A[0]); 
}

int heapExtract(int A[]){
	if(heapSize < 1){
		printf("Heap Underflow errno: $d\n", errno);
	}
	int max = A[1];
	A[1] = A[heapSize];
	heapSize--;
	maxHeapify(A, 1);
	return max;
}

void buildMaxHeap(int A[]){
	heapSize = ArraySize(A);
	for(int i = ArraySize(A)/2; i>1; i--){
		MaxHeapify(A, i);
	}
}

void heapsort(int A[]){
	BuildMaxHeap(A);
	for(int i = ArraySize(A); i>2; i--){
		exchange(A, A[1], A[i]);
		heapSize--;
		maxHeapify(A, 1);
	}
}

void heapIncrease(int A[], int i, int key){
	if(key < A[i]){
		printf("New key is smaller than the current key $d\n", errno);
	}
	A[i] = key;
	while(i>1 && A[Parent(i)] < A[i]){
		exchange(A, A[i], A[Parent(i)]);
		i=Parent(i);
	}
}

void heapInsert(int A[], int key){
	heapSize++;
	A[heapSize] = SENTINEL;
	heapIncrease(A, heapSize, key);
}

void showBinaryHeap(int i, int depth){
	if(i <= heapSize){
		showBinaryHeap(Right(i), depth+1);
		printf(A[i]);

	}
}	
