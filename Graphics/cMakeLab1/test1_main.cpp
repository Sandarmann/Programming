#include <iostream>
#include "class1.h"
using namespace std;

int main(){
	class1* c = new class1(10);
	cout << c->get() << endl;
}
