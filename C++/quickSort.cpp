#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void print(int A[], int size){
  for(int i=0; i<size; i++){
    cout << A[i] << " ";
        
  }

}

void swap(int *a, int *b){
  int tmp;
  *a = *b;
  *b = tmp;

}

int partition(int A[], int p, int r){
  int x = A[r];
  int i = p-1;
  for( int j = p; j < r; j++){
    if(A[j] <= x){
      i = i + 1;
      swap(A[i], A[j]);

    }

  }
  swap(A[i+1], A[r]);
  return i+1;

}

void quickSort(int A[], int p, int r){
  if(p<r){
    int q = partition(A,p,r);
    quickSort(A,p, q-1);
    quickSort(A,q+1, r);

  }

}

int main() {
  int n;
  cin >> n;
  int a[n];

  for(int i =0; i<n; i++){
    cin >> a[i];
        
  }

  quickSort(a,0,n-1);

  //print(a, sizeof(a)/sizeof(*a));

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  return 0;

}
