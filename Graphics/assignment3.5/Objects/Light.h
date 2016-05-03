#ifndef LIGHT_H
#define LIGHT_H
#include "Vector3D.h"
class Light{
public:
	Light();
	Light(Vector3D* dir);
	Light(Vector3D* dir, Vector3D* col);
	Vector3D* dir;
	Vector3D* color;

};

#endif