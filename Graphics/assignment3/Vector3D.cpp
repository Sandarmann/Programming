//
//Aleksandar Straumann
//CS5721
//Assigenment 3
//

#include <sstream>
#include "Vector3D.h"
#include <cmath>

using namespace std;

Vector3D::Vector3D(double a, double b, double c){
	this->x = a;
	this->y = b;
	this->z = c;
}

Vector3D::Vector3D(const Vector3D& v){
  this->x = v.getx();
  this->y = v.gety();
  this->z = v.getz();
}

Vector3D Vector3D::operator+(Vector3D v){
	return Vector3D(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector3D Vector3D::operator-(Vector3D v){
	return Vector3D(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vector3D Vector3D::operator*(double scale){
	return Vector3D(this->x*scale, this->y * scale, this->z * scale);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vec)
{
	os << "[" << vec.x << ", " <<vec.y << ", " << vec.z <<  "]";
	return os;
}

double Vector3D::dot(Vector3D vec){
	return ((this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z));
}

Vector3D Vector3D::cross(Vector3D vec){
	double i = (this->y * vec.z) - (this->z * vec.y);
	double j = (this->z * vec.x) - (this->x * vec.z);
	double k = (this->x * vec.y) - (this->y * vec.x);

	return Vector3D(i,j,k);
}

double Vector3D::length(){
	return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));	
}

void Vector3D::normalize(){
	double len = this->length();
	this->x = this->x / len;
	this->y = this->y / len;	
	this->z = this->z / len;
}

float* Vector3D::vecfData(){
	float* arr = new float[3];
	arr[0] = this->x;
	arr[1] = this->y;
	arr[2] = this->z;
	return arr;
}

void Vector3D::set(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

const double Vector3D::getx()const{
	return this->x;
}

const double Vector3D::gety()const{
	return this->y;
}

const double Vector3D::getz()const{
	return this->z;
}

