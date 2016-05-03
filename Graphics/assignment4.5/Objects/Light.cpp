#include "Light.h"

Light::Light(Vector3D* dir){
	this->dir = dir;
	this->color = new Vector3D(1, 1, 1);
}

Light::Light(Vector3D* dir, Vector3D* col){
	this->dir = dir;
	this->color = col;
}