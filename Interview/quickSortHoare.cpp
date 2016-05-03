#include <iostream>
#include <cmath>
using namespace std;

void quickSort(int *A,int lo,int hi);
int partition(int *A,int lo,int hi);

int main(){
	int A[10] = {1, 5, 6, 2,9, 10, 11, 2, 3, 6};
	int *p = A;
	quickSort(p, 0, 9);
	for(int i=0; i<10; i++){
		cout << "index: " << i << " " << A[i] << endl;
	}
}

void quickSort(int *A,int  lo,int  hi){
	if(lo < hi){
		int p = partition(A, lo, hi);
		quickSort(A, lo, p);
		quickSort(A, p+1, hi);
	}
}

int partition(int *A,int  lo,int  hi){
	int pivot = A[lo]; // + ( hi - lo) / 2];
	int i = lo; 
	int j = hi;
	while (true){

		while(A[i] < pivot){
			i++;
		}
		while(A[j] > pivot){
			j--;
		}
		if(i < j){
			swap(A[i], A[j]);
			i++;
			j--;
		}else{
			return j;
		}	
	}
		//	return 0;
}
