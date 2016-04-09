#ifndef MATRIX3_H
#define MATRIX3_H

#include "Vector3D.h"
class Matrix3{
	public:

		Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);
		Matrix3(Vector3D& p1, Vector3D& p2, Vector3D& p3);

		static double det(const Matrix3& m);

		double getVal(int x, int y) const;
	private:
		double values[3][3] ;

};	

#endif