#include <iostream>

using namespace std;

int main(){

	int* a = new int[1];
	a[0] = 2;

	int j = 10;

	int* temp = new int[2];
	copy(a, a+1, temp);
	delete [] a;
	a = temp;

	for( int& i : a){
		cout << *i << endl;
	}
}
