#include "binheap.h"
#include <iostream>
#include <iomanip>
#include <time.h>

#define DEBUG 0
#define RELEASE 1 
#ifndef MODE
	#define MODE DEBUG
#endif

// Utility routines used to implement binary heaps and heapSort

int parent ( int i ) { return i/2 ; }

int left ( int i ) { return 2*i ; }

int right ( int i ) { return 2*i + 1 ; }

void BinHeap :: minHeapify ( int i )
{
  int l, r, smallestloc ;
  KeyType temp ;

  l = left( i ) ;
  r = right( i ) ;
	
	if(DEBUG){
		cout << "Left is: " << l << endl;
		cout << "Right is: " << r << endl;
		cout << "Size of heap " << heapSize << endl; 
	}

	if(l <= heapSize && A[l] <= A[i]){
		smallestloc = l;
	} else{
		smallestloc = i;
	}

	if(r <= heapSize && A[r] <= A[smallestloc]){
		smallestloc = r;
	}

	if(smallestloc != i){
		
		if(DEBUG){
			cout << "the swapped values before are "<< A[i] << " " << A[smallestloc] << endl;
		}

		exchange(i, smallestloc);

		if(DEBUG){
			cout << "the swapped values after are " << A[i] << " " << A[smallestloc] << endl;
		}

		minHeapify(smallestloc);

	}

}

void BinHeap :: buildMinHeap( )
{
	heapSize = 1000;
	length = 1000;

	for(int i = heapSize/2; i>0; i--){
		int temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		minHeapify(i);
	}
	// You implement this for heapSort in Assignment # 5
}


// Constructors, Destructor

BinHeap :: BinHeap() {
  heapSize = 0 ; length = 1000 ; A = new KeyType[1001] ;
}
BinHeap :: BinHeap( int arrayLength ) {
  heapSize = 0 ; length = arrayLength ; A = new KeyType[arrayLength+1] ;
}
BinHeap :: ~BinHeap() { delete[] A ; }


// Min-heap, min priority queue operations 
void BinHeap :: insert( KeyType key )
{
  heapSize++ ;
  A[heapSize] = key ;  // <-- This seems to work.
  decreaseKey( heapSize, key ) ;
}

KeyType BinHeap :: minimum( )
{
  return A[1] ;    // Assumes heap is not empty!
}

KeyType BinHeap :: extractMin( )
{
  KeyType min ;

  if ( heapSize < 1 ) {
    cout << "\nHeap underflow in extractMin()\n\n" ; return 0 ;
  }

  min = A[1] ;
	A[1] = A[heapSize];
	heapSize--;
	minHeapify(1);

  return min ;
}

void BinHeap :: decreaseKey( int i, KeyType key )
{
  KeyType temp ;

  if ( key > A[i] ) {
    cout << "\nKey larger than A[i] in decreaseKey()\n\n" ; return ;
  }

	A[i] = key;

	// This is probably wrong
	while (i > 1 && A[parent(i)] > A[i]){
		temp = A[i];
		A[i] = A[parent(i)];
		A[parent(i)] = temp;
		i=parent(i);
	}

}


// Auxiliary operations

// Shows the structure of the binary heap
void BinHeap :: ShowHeap( int i, int depth )
{
  if ( i <= heapSize ) {
    ShowHeap( right(i), depth+1 ) ;
    cout << setw( depth*6 +4 ) << A[i] << endl ;
    ShowHeap( left(i), depth+1 ) ;
  }
}

// Just prints A[] as a horizontal array; may be used for debugging
void BinHeap :: PrintHeap()
{
  cout << "Heap elements in the array:\n" ;
  for ( int i = 1 ; i <= heapSize ; i++ )
    cout << A[i] << " " ;
  cout << endl ;
}

// A routine that is useful for testing decreaseKey()
int BinHeap :: search( KeyType key )
{
  for ( int i = 1 ; i <= heapSize ; i++ )
    if ( A[i] == key ) return i ;
  return 0 ;
}


// For Assignment # 5
void BinHeap :: minHeapSort( )
{	
	int origA[1000];
	for(int i=0; i<1000; i++){
		origA[i] = 1000 - i;
		heapSize++;
	}
	clock_t tstart, tend, ttotal; 
	double copyTime;
	tstart = clock() ;

	    
	for(int i=0; i<10000; i++){
		for(int j = 0; j< 1000; j++){
			A[j] = origA[j];
		} 
	}


	tend = clock();
	copyTime = (tend - tstart)/CLOCKS_PER_SEC;



	tstart = clock();

	for(int i=0; i<10000; i++){

		for(int j = 0; j< 1000; j++){
	  		A[j] = origA[j];
		} 
		buildMinHeap();
	}
	tend = clock() ;
	ttotal = tend - tstart ;
	cout << (((float)ttotal/CLOCKS_PER_SEC)- copyTime)/10000 << " seconds (ran 10000 times)" << endl;


}

void BinHeap :: exchange(int i, int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
