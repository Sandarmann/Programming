#include <iostream>
using namespace std;


int main(){
	int A[] = {1,2,3,4,5,6,7,8};

	for (int i=1; i<8; i++){
		int key = A[i];
		int j = i-1;
		while(j >= 0 && A[j] < key){
			cout << A[j] << " a_j" << endl;
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}

	for(int i=0; i<8; i++){
		cout << A[i] << " ";

	}

}
