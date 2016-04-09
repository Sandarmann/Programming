#include <iostream>

using namespace std;


/*
 * So from this I have learned that character arrays in c++ are also null terminated, this allows us to find the length of a given character array by iterating through it.
 * So if I were to want ot reverse the string then I would just save the last spot as a null byte and reverse everything else.
 */
void reverse(char* str){
//	int size = 0;
//	while(str[size] != '\0'){
//		size++;
//	}
//
//	cout<< "Size == " << size << endl;

	cout << "Size using method == " << strlen(str) << endl;
	cout << "String before " << str << endl;
	int start = 0;
	int end = strlen(str) - 1; //Need to remove 1 off the end to protect against null byte

	while(start <  end){
		char tmp = str[end];

		str[end] = str[start];
		str[start] = tmp;

		start ++;
		end --;
	}

	cout << "String after " << strlen(str) << endl;	
	cout << "String after " << str << endl;	
}

int main(){
	char str[] = "hi";

	char* p = str;
	cout << p << endl;
	reverse(p);
}
