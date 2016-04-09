#ifndef LIGHT_H
#define LIGHT_H
#include "Object3D.h"
#include "Vector3D.h"
class Light : public Object3D{
public:
	Light();
	Light(Vector3D* loc);
	virtual bool intersect(const Ray& r);
	virtual bool intersect(const Ray& r, const float tmin, float &tmax);
	virtual void setColor(Vector3D& color);
	virtual Vector3D getColor();
	virtual Vector3D calculateNormal();
private:
	Vector3D p;
	Vector3D color;
};

#endif