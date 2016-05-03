#include "Triangle.h"


Triangle::Triangle(Vector3D* pt0, Vector3D* pt1, Vector3D* pt2){
	this->p0 = *pt0;
	this->p1 = *pt1;
	this->p2 = *pt2;
}

Triangle::Triangle(Vector3D* pt0, Vector3D* pt1, Vector3D* pt2, Vector3D* color){
	this->p0 = *pt0;
	this->p1 = *pt1;
	this->p2 = *pt2;
	this->c = *color;
}

void Triangle::set(Vector3D* pt0, Vector3D* pt1, Vector3D* pt2){
	this->p0 = *pt0;
	this->p1 = *pt1;
	this->p2 = *pt2;	
}
bool Triangle::intersect(const Ray& r){
	return false;
}

bool Triangle::intersect(const Ray& r, const float tmin, float &t_max){
	double a = p0.getx() - p1.getx(); // a - l are these assignments
	double b = p0.gety() - p1.gety();
	double c = p0.getz() - p1.getz();
	double d = p0.getx() - p2.getx();
	double e = p0.gety() - p2.gety();
	double f = p0.getz() - p2.getz();
	double g = r.getDir().getx();
	double h = r.getDir().gety();
	double i = r.getDir().getz();
	double j = p0.getx() - r.getOrigin().getx();
	double k = p0.gety() - r.getOrigin().gety();
	double l = p0.getz() - r.getOrigin().getz();

	double m = a*(e*i-h*f)+b*(g*f-d*i)+c*(d*h-e*g);
	double t = -1*(f*(a*k-j*b)+e*(j*c-a*l)+d*(b*l-k*c))/m;
	if(t  < tmin  || t > t_max){
	    return false;
	}
	double gamma = (i*(a*k-j*b)+h*(j*c-a*l)+g*(b*l-k*c))/m;
	if(gamma < 0 || gamma > 1)
	    return false;

	double beta = (j*(e*i-h*f)+k*(g*f-d*i)+l*(d*h-e*g))/m;
	if(beta < 0 || beta > (1-gamma))
	    return false;

	// std::cout << t << std::endl;
	t_max = t;

	return true;
}

void Triangle::setColor(Vector3D& color){
	c.set(color.getx(), color.gety(), color.getz());
}

Vector3D Triangle::getColor(){
	return c;
}

Vector3D Triangle::getNormalToSurface(Vector3D* v){
	Vector3D n = (p1 - p0).cross(p2-p0);
	n.normalize();
	return n;
};

void Triangle::fillMatrix(const Ray & r, double (&m)[4][3] ){
	double a = p0.getx() - p1.getx(); // a - l are these assignments
	double b = p0.gety() - p1.gety();
	double c = p0.getz() - p1.getz();
	double d = p0.getx() - p2.getx();
	double e = p0.gety() - p2.gety();
	double f = p0.getz() - p2.getz();
	double g = r.getDir().getx();
	double h = r.getDir().gety();
	double i = r.getDir().getz();
	double j = p0.getx() - r.getOrigin().getx();
	double k = p0.gety() - r.getOrigin().gety();
	double l = p0.getz() - r.getOrigin().getz();
	// std::cout << "f " << f << "a " << a << " d " << d  << std::endl;
	m[0][0] = j * ( (e * i ) - ( h * f));
	m[0][1] = k * ( (g*f) - ( d * i));
	m[0][2] = l * ( (d*h) - (e * g ));
	m[1][0] = i * ((a * k ) - (j * b));
	m[1][1] = h * ( (j * c) - (a * l));
	m[1][2] = g * ((b * l) - (k*c));
	m[2][0] = f * ( ( a * k) - (j * b));
	m[2][1] = e * ( ( j*c) - (a * l ));
	m[2][2] = d * ((b * l) - ( k*c ));

	// std::cout << "f " << f << "a " << a << " k " << k << " j " << j << " b " << b << std::endl;
	// std::cout << "equations " << f * ( ( a * k) - (j * b)) << std::endl;

	//these next three represent the M values a(ei−hf)+b(gf−di)+c(dh−eg)
	m[3][0] = a * ( (e * i) - (h * f));
	m[3][1] = b * ( (g * f) - (d * i));
	m[3][2] = c *  ( (c*d) - (e *g));
}

Vector3D Triangle::getp0(){
	return p0;
}
Vector3D Triangle::getp1(){
	return p1;
}
Vector3D Triangle::getp2(){
	return p2;
}
