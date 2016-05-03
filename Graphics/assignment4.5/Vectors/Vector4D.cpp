#include "Vector4D.h"


Vector4D::Vector4D(Vector3D vec){
	this->x = vec.getx();
	this->y = vec.gety();
	this->z = vec.getz();
	this->a = 1.0;
}

Vector4D::Vector4D(double x, double y, double z, double a){
	this->x = x;
	this->y = y;
	this->z = z;
	this->a = a;
}

void Vector4D::set(double x, double y, double z, double a){
	this->x = x;
	this->y = y;
	this->z = z;
	this->a = a;	
}

void Vector4D::homogonize(){
	this->x = x/a;
	this->y = y/a;
	this->z = z/a;
}

void Vector4D::print(){
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;
	std::cout << "a: " << a << std::endl;
}