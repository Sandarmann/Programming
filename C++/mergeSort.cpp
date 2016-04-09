/*mergeSort.cpp 1/2 main programs for Assignment 1
Aleksandar Straumann
CS 5521 
Assignment 1
*/
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

//Subpart A from assignment 2. Creation of mergeSort for comparison with insertionSort algorithm. 
void merge(int  input[], int p, int q, int r, int A[], int B[]){ 
  int index1 = q - p + 1;
  int index2 = r - q;

  //indexes for left and right arrays
  for(int i=0; i < index1; i++){
    A[i] = input[p + i];
  }
  for(int j=0; j < index2; j++){
    B[j] = input[q + j+1];
  }

  int i = 0; //keep track of left array
  int j = 0; //keep track of right array
  int k = p; //keep track of overall size of initial array
  while(i < index1 && j < index2){  //While i and j are less than the length of the left and right array compare each value in arrays
    if(A[i] <= B[j]){
      input[k] = A[i++];
    }
    else{
      input[k] = B[j++];
    }
    k++;
  }

  while (i < index1){                 //If values are left over they are greater than the values in the above array so append it to the end
    input[k++] = A[i++];
  }

  while(j < index2){                  //Same as above while
    input[k++] = B[j++];
  }
}

void mergeSort(int inputArray[], int p, int r, int A[], int B[]){
  if(p < r){
    int q = floor((p + r)/2);               //Floors value. Should be floored regardless but just in case
    mergeSort(inputArray, p, q, A, B);      //Recursive call for the left half of array 
    mergeSort(inputArray, q+1, r, A, B);    //Recursive call for the right half of array
    merge(inputArray, p, q, r, A, B);       //merges the results of the mergeSort at completion. Works from the bottom u
  }
}

int main(){
  int arraySize;
  cout << "Enter size of array: ";
  cin >> arraySize;
  int A[arraySize/2 + 1];       //creates left array with the value of half the total array plus one just in case we are left with an off array
  int B[arraySize/2 + 1];       //creates left array with the value of half the total array plus one
  int array[arraySize];
  int testArray[arraySize];
  // for(int i = 0; i<arraySize; i++){
  //   if(i%2 == 1){
  //     array[i] = arraySize - i;
  //   }else
  //     array[i] = i;
  // }
  for( int i=0; i<arraySize; i++){
    array[i] = arraySize-i;
  }


  clock_t tstart, tend, ttotal; 
  double copyTime;
  tstart = clock() ;
    
  for(int i=0; i<10000; i++){
    for(int j = 0; j< arraySize; j++){
      testArray[j] = array[j];
    } 
  }

  tend = clock();
  copyTime = (tend - tstart)/CLOCKS_PER_SEC;

  tstart = clock();

  for(int i=0; i<10000; i++){

    for(int j = 0; j< arraySize; j++){
      testArray[j] = array[j];
    } 

    mergeSort(testArray,0, arraySize, A, B);
  }
  tend = clock() ;
  ttotal = tend - tstart ;
  cout << (((float)ttotal/CLOCKS_PER_SEC)- copyTime)/10000 << " seconds (ran 10000 times)" << endl;
 
}
