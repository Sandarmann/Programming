//
//Aleksandar Straumann
//CS5721
//Assigenment 2
//

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D{
	
	public:
		Vector2D(double a, double b);
		Vector2D operator+(Vector2D v);
		Vector2D operator-(Vector2D v);
		Vector2D operator*(double scale);
		double dot(Vector2D vec);
		double cross(Vector2D vec);
		double length();
		float* vecfData();
		void normalize();
		void set(double x, double y);
		void swap();
		const double getx() const;
		const double gety() const;
	private:
		double x;
		double y;
};

#endif
