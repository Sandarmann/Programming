#include "class1.h"
#include <iostream>

using namespace std;

class1::class1(int val){
	this->value = val;
}

int class1::get(){
	return this->value;
}
