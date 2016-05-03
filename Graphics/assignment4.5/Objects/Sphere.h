#ifndef SPHERE_H
#define SPHERE_H
#include "Vector3D.h"
#include "Object3D.h"
class Sphere : public Object3D{
public:
	Sphere();
	Sphere(Vector3D* center, double radius);
	Sphere(Vector3D* center, double radius, Vector3D* color);

	virtual bool intersect(const Ray& r);
	virtual bool intersect(const Ray& r, const float tmin, float &t_max);
	virtual void setColor(Vector3D& color);
	virtual Vector3D getColor();
	virtual Vector3D getNormalToSurface(Vector3D* v);

private:
	Vector3D center;
	Vector3D color;
	double radius;
};


#endif