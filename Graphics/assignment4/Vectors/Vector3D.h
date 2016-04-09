//
//Aleksandar Straumann
//CS5721
//Assigenment 3
//

#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iostream>	
class Vector3D{

	public:
		Vector3D(){
			x = 0;
			y = 0;
			z = 0;
		};
    		Vector3D(const Vector3D& v); 
		Vector3D(double a, double b, double c);
		Vector3D operator+(Vector3D v);
		Vector3D operator-(Vector3D v);
		Vector3D operator*(double scale);
		Vector3D operator=(Vector3D* v);
		friend std::ostream & operator<<(std::ostream &os, const Vector3D& vec);
		double dot(Vector3D vec);
		Vector3D cross(Vector3D vec);
		double length();
		float* vecfData();
		void normalize();
		void set(double x, double y, double z);
		const double getx() const;
		const double gety() const;
		const double getz() const;
	private:
		double x;
		double y;
		double z;

};

#endif
