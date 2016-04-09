/*
This problem was to find the next greatest string in lexigraphical order. 
With a being the smallest and z being the greatest.

My algorithm was to basically take the input into an array of strings
    Go through each cell in array and copy the values from strings to ascii value in another array,
    Then I went through the array of ascii values and found the position of the Next greatest number .... IE [1,2,3,4] -> [1,2,4,3]
    Then after the new found position for the example above, I sorted everything after pos[3] in ascending order...
    This took me a stupid long time...should have thought of this faster
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int sortAscending(int arr[], int pos, int size){
    int next, i, j;
    next = -1;
    for (i=pos; i<size; i++)
    {
        for (j = i+1; j<size; j++)
        {
            if (arr[i] > arr[j])
            {
                next = j;
                break;
            }
        }
    }
    return next;
}

int posNext(int arr[], int n){
    int i, j;
 
    // I) Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
    for (i = n-1; i > 0; i--)
        if (arr[i] > arr[i-1])
           break;
 
    // If no such digit is found, then all digits are in descending order
    // means there cannot be a greater number with same set of digits
    if (i==0)
    {
        return -1;
    }
 
    // II) Find the smallest digit on right side of (i-1)'th digit that is
    // greater than number[i-1]
    int x = arr[i-1], smallest = i;
    for (j = i+1; j < n; j++) // This check will catch if i+1 is equal to the size, so if largest is rightmost
        if (arr[j] > x && arr[j] < arr[smallest])
            smallest = j;
 
    // III) Swap the above found smallest digit with number[i-1]
    swap(arr[smallest], arr[i-1]);
 
    //Sort ascending...
    std::sort(arr+i, arr+n);
    return 0;
}


int reorder(int arr[], int size){
    //Was dumb and made wrong assumption.... need to rework the find next
    int n = posNext(arr, size); //posNextSmallest(arr, i, size);
    if(n != -1){
        return 1;
    } 
    return -1;
}
void determintLexi(string str[], int pos){
    string newString = "";
    int vals[str[pos].length()];
    for(int i=0; i < str[pos].length(); i++){
        vals[i] = int(str[pos].at(i));
    }
    
    int ret = reorder(vals, str[pos].length());
    
    for(int i=0; i<str[pos].length(); i++){
        newString += char(vals[i]);
    }
    if(ret != -1){
        str[pos] = newString;
    }else{
        str[pos] = "no answer";
    }
}

void lexigr(string str[], int size){
    for(int i=0; i<size; i++){
        determintLexi(str, i);
    }
}
/*
Use the ascii value then subtract 'a' from the value to determine it's number
*/
int main() {
    int n = 0;
    cin >> n;
    string str[n];
    string initial[n];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    for(int i =0; i<n; i++){
        cin >> str[i];
        initial[i] = str[i];
    }
    /*int val[3];
    val[0] = 1;
    val[1] = 2;
    val[2] = 3;
    int x = posNext(val, 3);
    for(int i=0; i<3; i++){
        cout << val[i] << " " ;
    }*/
    lexigr(str, n);
    for(int i=0; i<n; i++){
         cout << str[i] << endl;
    }
    return 0;
}
