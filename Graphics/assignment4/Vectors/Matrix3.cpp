#include "Matrix3.h"


Matrix3::Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33){
	//double v[3][3] = 
	values[0][0] = a11;
	values[0][1] = a12;
	values[0][2] = a13;
	
	values[1][0] = a21;
	values[1][1] = a22;
	values[1][2] = a23;
	
	values[2][0] = a31;
	values[2][1] = a32;
	values[2][2] = a33;
				
}

Matrix3::Matrix3(Vector3D& p1, Vector3D& p2, Vector3D& p3){
	values[0][0] = p1.getx();
	values[0][1] = p1.gety();
	values[0][2] = p1.getz();
	
	values[1][0] = p2.getx();
	values[1][1] = p2.gety();
	values[1][2] = p2.getz();
	
	values[2][0] = p3.getx();
	values[2][1] = p3.gety();
	values[2][2] = p3.getz();
}

double Matrix3::getVal(int x, int y) const {
	return values[y][x];
}

double Matrix3::det(const Matrix3& m){
	double det00 = (m.getVal(1, 1) * m.getVal(2,2)) - (m.getVal(1,2) * m.getVal(2,1));
	det00 *= m.getVal(0,0);

	double det01 = (m.getVal(1, 0) * m.getVal(2,2)) - (m.getVal(1,2) * m.getVal(2,0));
	det01 *= m.getVal(0,1);

	double det02 = (m.getVal(1, 0) * m.getVal(2,1)) - (m.getVal(1,1) * m.getVal(2,0));
	det02 *= m.getVal(0,2);

	return (det00 - det01 + det02);
}
