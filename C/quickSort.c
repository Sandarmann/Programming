#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define DEBUG 0
#define RELEASE 1
#ifndef MODE
	#define MODE DEBUG
#endif

void quickSort(int A[], int p, int r);
int partition(int A[], int p, int r);

int main(int argc, char *argv[]){\
	int A[1000];
	int test[1000];
	for(int i=0; i<1000; i++){
		A[i] = 1000 - i;
	}
	clock_t tstart, tend, ttotal; 
	double copyTime;
	tstart = clock() ;

	    
	for(int i=0; i<10000; i++){
		for(int j = 0; j< 1000; j++){
			test[j] = A[j];
		} 
	}


	tend = clock();
	copyTime = (tend - tstart)/CLOCKS_PER_SEC;

	tstart = clock();

	for(int i=0; i<10000; i++){

		for(int j = 0; j< 1000; j++){
			test[j] = A[j];
		} 

		quickSort(test, 1, 1000);
	}
	tend = clock() ;
	ttotal = tend - tstart ;
	printf( "time = %f\n", (((double)ttotal/CLOCKS_PER_SEC)- copyTime)/10000 ) ;
}

void quickSort(int A[], int p, int r){
	if(p<r){
		int q = partition(A,p,r);
		quickSort(A,p, q-1);
		quickSort(A,q+1, r);
	}
}


int partition(int A[], int p, int r){
	int x = A[r];
	int i = p-1;
	for( int j = p; j < r; j++){
		if(A[j] <= x){
			i = i + 1;
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	int temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	return i+1;
}
