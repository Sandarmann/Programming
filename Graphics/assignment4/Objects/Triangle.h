#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vector3D.h"
#include "Vector4D.h"
#include "Object3D.h"
class Triangle : public Object3D{
public:
	Triangle();
	Triangle(Vector3D* pt0, Vector3D* pt1, Vector3D* pt2);
	Triangle(Vector3D* pt0, Vector3D* pt1, Vector3D* pt2, Vector3D* color);
	void set(Vector3D* pt0, Vector3D* pt1, Vector3D* pt2);
	virtual bool intersect(const Ray& r);
	virtual bool intersect(const Ray& r, const float tmin, float &t_near);
	virtual void setColor(Vector3D& color);
	virtual Vector3D getColor();
	virtual Vector3D getNormalToSurface(Vector3D* v);

	void fillMatrix(const Ray & r, double (&m)[4][3] );
	Vector3D getp0();
	Vector3D getp1();
	Vector3D getp2();
private:
	Vector3D p0;
	Vector3D p1;
	Vector3D p2;
	Vector3D c;
};


#endif