//Aleksandar Straumann
//Homework 1



#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D{

	public:
		Vector3D(){
			x = 0;
			y = 0;
			z = 0;
		}	
		Vector3D(double a, double b, double c);
		Vector3D operator+(Vector3D v);
		Vector3D operator-(Vector3D v);
		Vector3D operator*(double scale);
		friend std::ostream & operator<<(std::ostream &os, const Vector3D& vec);
		double dot(Vector3D vec);
		Vector3D cross(Vector3D vec);
		double length();
		float* vecfData();
		void normalize();
		void set(double x, double y, double z);
		double getx();
		double gety();
		double getz();
	private:
		double x;
		double y;
		double z;

};

#endif
