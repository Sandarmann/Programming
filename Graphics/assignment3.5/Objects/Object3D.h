
#ifndef OBJECT3D_H
#define OBJECT3D_H
#include "Ray.h"


class Object3D{
public:
	Object3D(){};
	virtual bool intersect(const Ray& r){return false;};
	virtual bool intersect(const Ray& r, const float tmin, float &tmax){std::cout << "PARENT" <<std::endl;return false;};
	virtual void setColor(Vector3D& color){};
	virtual Vector3D getColor(){return Vector3D(255, 255, 255);};
	virtual Vector3D getNormalToSurface(Vector3D* v)=0;
};

#endif