
//Aleksandar Straumann
//Homework 1
#include <iostream>
#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(double a, double b){
	this->x = a;
	this->y = b;
}

Vector2D Vector2D::operator+(Vector2D v){
	return Vector2D(this->x + v.x, this->y + v.y);
}

Vector2D Vector2D::operator-(Vector2D v){
	return Vector2D(this->x - v.x, this->y - v.y);
}

Vector2D Vector2D::operator*(double scale){
	return Vector2D(this->x*scale, this->y * scale);
}

double Vector2D::dot(Vector2D vec){
	return ((this->x * vec.x) + (this->y * vec.y));
}

double Vector2D::cross(Vector2D vec){
	return ((this->x * vec.y) - (this->y * vec.x));
}

double Vector2D::length(){
	return sqrt((this->x * this->x) + (this->y * this->y));	
}

void Vector2D::normalize(){
	double len = this->length();
	this->x = this->x / len;
	this->y = this->y / len;	
}

float* Vector2D::vecfData(){
	float* arr = new float[2];
	arr[0] = this->x;
	arr[1] = this->y;
	return arr;
}

void Vector2D::set(double x, double y){
	this->x = x;
	this->y = y;
}

double Vector2D::getx(){
	return this->x;
}

double Vector2D::gety(){
	return this->y;
}
