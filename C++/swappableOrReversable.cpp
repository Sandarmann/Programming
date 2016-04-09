/*
Problem to determine if given array can be sorted into ascending order using either one swap operation or one reverse operation.

Return the indices of swap/reverse starting at 1

 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int reversable1, reversable2, swappable1, swappable2;
bool wayToSort(int i, int j){return i<j;} // to be used reverse array like so:
// std::sort(begin,end, function);
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int determineSwappable(int arr[], int size){
    int index1, index2;
    for(int i=0; i<size; i++){
        if(arr[i] > arr[i+1]){
            index1 = i;
            break; // found index of first out of order break
        }
    }
    int index1Value = arr[index1];
    int i;
    for(i=index1+1; i<size-1; i++){
        if(arr[i+1] > index1Value){
            i;
          //  cout << "arr i" << arr[i] << " arr i+1 " << arr[i+1] << endl; 
            break; // found second index break
        }
    }
    if(i >= size-1){
        index2 = size-1;
    }else{
        index2 = i; //this could be the whole array so cool
    }
    //cout << "i1 " << index1 << " i2 " << index2 <<endl;
    swap(arr[index1], arr[index2]);
    
 /*   
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    } */
    //cout << endl;
    for (int i = 0; i < size-1; i++) {
        //cout << "arr i" << arr[i] << " arr i+1 " << arr[i+1] << endl;
        if (arr[i] > arr[i + 1]) {
            return -1; // It is proven that the array is not sorted.
        }
    }
    
    if(index1 == index2){
        return -1;
    }
    
    swappable1 = index1;
    swappable2 = index2;
    return 1;
}

bool determineIfReverse(int arr[], int size){
    int index1, index2;
    for(int i=0; i<size; i++){
        if(arr[i] > arr[i+1]){
            index1 = i;
            break; // found index of first out of order break
        }
    }
    int i;
    for(i=index1; i<size; i++){
        if(arr[i] < arr[i+1]){
            break; // found second index break
        }
    }
    index2 = i; //this could be the whole array so cool
  //  cout << "i1 " << index1 << " i2 " << index2 <<endl;

    std::sort(arr+index1, arr+index2+1);
    
    for (int i = 0; i < size-1; i++) {
       // cout << "arr i" << arr[i] << " arr i+1 " << arr[i+1] << endl;
        if (arr[i] > arr[i + 1]) {
            return 0; // It is proven that the array is not sorted.
        }
    }
    if(index1 == index2){
        return -1;
    }
    reversable1 = index1;
    reversable2 = index2;
    return 1;
}
int main() {
    
    int n = 0;
    cin >> n;
    int arr[n];
    int arr2[n];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    for(int i =0; i<n; i++){
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    //cout << "Size " << n << endl;
    int reverse = determineIfReverse(arr, n);
    int swappable = determineSwappable(arr2, n);
  //  cout << "reverse " << reverse << endl;
    //cout << "swappable " << swappable << endl;;
    if(reverse == 1 && swappable == 1|| swappable == 1){
        cout << "yes" << endl;
        cout << "swap " << swappable1+1 << " " << swappable2+1 << endl;
    }
    else if(reverse == 1){
        cout << "yes" << endl;
        cout << "reverse " << reversable1+1 << " "  << reversable2+1 << endl;
    } 
    else if(reverse == -1 && swappable == -1){
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
 /*   for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for(int i=0; i<n; i++){
        cout << arr2[i] << " ";
    } */
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
