/*insertionSort.cpp 1/2 main programs for Assignment 1
Aleksandar Straumann
CS 5521 
Assignment 1
*/
#include <iostream>

using namespace std;

/*insertion sort takes an array then uses nested loops to compare the index of an array
	to the value before it until it hits the beginning of the array. If it finds a value 
	bigger than itself it will swap positions. It does this for every index in the array.
*/
void insertionSort(int A[], int size){   //This method will contain all the logic for the insertion sort
	for(int i = 1; i< size; i++){
		int key = A[i];					//key value to compare index too
		int j = i -1;					//Copy the index - 1 to the holder j
		while(j > 0 && A[j] > key){		//Compare the key to the holder j in array A
			A[j+1] = A[j];
			j --;
		}
		A[j+1] = key;					//put the key where it is greater than the element in A[j]
	}
}

int main(){
	int size;
	cout << "Enter Size: ";
	cin >> size;
	int array[size];
	int copyArray[size];
	for(int i = 0; i<size; i++){			//Creates array with values {1, n-1, 2, n-2 .... n}
	// if(i%2 == 1){
	//   array[i] = size - i;
	// }else
	//   array[i] = i;
		array[i] = size - i;
	}

	clock_t tstart, tend, ttotal ;			//Start clock here so as not to count the creation of the array
	double copyTime;
	tstart = clock() ;

	for(int i=0; i<10000; i++){
		for(int j=0; j<size; j++){
			copyArray[j]= array[j];
		}
	}

	tend = clock();

	copyTime = (tend - tstart)/CLOCKS_PER_SEC;
	tstart = clock();	
	for(int i=0; i<10000; i++){
		for(int j=0; j<size; j++){
			copyArray[j]= array[j];
		}
		insertionSort(copyArray, size);
	}
	tend = clock() ;
	ttotal = tend - tstart ;
 	cout << (((double)ttotal/CLOCKS_PER_SEC)- copyTime)/10000 << " seconds (ran 10000 times)" << endl;
 }
