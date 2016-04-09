#ifndef VECTOR4D_H
#define VECTOR4D_H
#include "Vector3D.h"

class Vector4D{
	public:
		Vector4D(){ x=0; y=0; z=0; a=0;};
		Vector4D(Vector3D vec);
		Vector4D(double x, double y, double z, double a);

		void set(double x, double y, double z, double a);
		const double getx() const;
		const double gety() const;
		const double getz() const;
		const double geta() const;

	private:
		double x,y,z,a;
};

#endif