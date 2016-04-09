#include <iostream>

using namespace std;

void replaceString(string& s){
	int i = s.length() - 1;
	int endCharsPos = 0;
	int count = 0;
	for(;i>0; i--){
		if(s[i] == ' '){
			count++;
		}else if(s[i] != ' ' && i >endCharsPos){
			endCharsPos = i;
		}
	}
	if(count%3 != 0){
		cout << "This will not work" << endl;
		return;
	}
	//cout << "count: " << count << endl;
	//cout << "end char Pos " << endCharsPos << endl;
	int end = s.length() - 1;
	for(int i=s.length()-1; i>0; i--){
		//cout << "i : " << i << endl;
		//cout << "s[i] : " << s[i] << endl;
		if(s[i] != ' ' && i<=endCharsPos){
		//	cout << s[end] << s[i] << endl;
			s[end] = s[i];
			if(end != i)
				s[i] = ' ';
			end--;
		}
		else if(s[i] == ' ' && i < end && i<=endCharsPos){
			s[end--] = '0';
			s[end--] = '2';
			s[end--] = '%';
		}
		//cout << "new string " << s << endl;
	}	
	cout << "new string " << s << endl;
}

int main(){
	string test = "Mr Smith Jones    ";
	if(test[1] != ' '){
		cout << "TRUE" << endl;
	}
	
	replaceString(test);	
	test = "Aleksandar Napolean Straumann    ";
	replaceString(test);	
	test = "Kimberly Wichmann  ";
	replaceString(test);
}
