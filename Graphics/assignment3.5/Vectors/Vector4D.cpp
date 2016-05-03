#include "Vector4D.h"


Vector4D::Vector4D(Vector3D vec){
	this->x = vec.getx();
	this->y = vec.gety();
	this->z = vec.getz();
	this->a = 0;
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

const double Vector4D::getx() const{
	return x;
}
const double Vector4D::gety() const{
	return y;
}
const double Vector4D::getz() const{
	return z;
}
const double Vector4D::geta() const{
	return a;
}