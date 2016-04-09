#include "Sphere.h"
#include <math.h>
Sphere::Sphere(){
	
}

Sphere::Sphere(Vector3D* center, double radius){
	this->center = *center;
	this->radius = radius;
}

Sphere::Sphere(Vector3D* center, double radius, Vector3D* color){
	this->center = *center;
	this->radius = radius;
	this->color = *color;
}

bool Sphere::intersect(const Ray& r){
	return false;
}

bool solveQuadratic(const float &a, const float &b, const float &c, float &x0, float &x1)
{
    float discr = (b * b) - 4 * (a * c);
    if (discr < 0) return false;
    else if (discr == 0) x0 = x1 = - 0.5 * b / a;
    else {
        float q = (b > 0) ?
        -0.5 * (b + sqrt(discr)) :
        -0.5 * (b - sqrt(discr));
        x0 = q / a;
        x1 = c / q;
    }
    if (x0 > x1) std::swap(x0, x1);
    //std::cout << "DFADA " << discr << std::endl;
    
    return true;
}

//(r⃗ ·r⃗)t2 +2r⃗ ·(r⃗o −cen⃗ter)t+(r⃗o −cen⃗ter)·(r⃗o −cen⃗ter)−R2 =0
bool Sphere::intersect(const Ray& r, const float tmin, float &t_max){
	float t0, t1; // solutions for t if the ray intersects

    // analytic solution
	Vector3D L = r.getOrigin() - center;
	// std::cout << "L " << L << std::endl;
	float a = r.getDir().dot(r.getDir());
	// std::cout << "a " << a << std::endl;
	float b = 2 * r.getDir().dot(L);
	// std::cout << "b " << b << std::endl;
	float c = L.dot(L) - (radius * radius ) ;
	// std::cout << "c " << c << std::endl;

	if (!solveQuadratic(a, b, c, t0, t1)) return false;

	if (t0 > t1) std::swap(t0, t1);
	if (t0 < 0) {
	    t0 = t1; // if t0 is negative, let's use t1 instead
	    if (t0 < 0) 
	    	return false; // both t0 and t1 are negative
	}
	// std::cout << t0 << std::endl;
	t_max = t0;

	return true;
	// double A = (r.getDir().dot(r.getDir()) );
	// double B = (r.getDir() * 2).dot(r.getOrigin() - center);
	// double C = (r.getOrigin() - center).dot(r.getOrigin() - center) - radius * radius;
	// //std::cout << "r.getOrigin " << r.getOrigin() << " center " << center << " radius " << radius << std::endl;
	// //std::cout << "A " << A << " B " << B << " C " << C << std::endl;
	// double tplus  =(B * -1) + sqrt(pow(B, 2) - (4*A*C));
	// tplus /= 2*A;
	// double tminus  =(B * -1) - sqrt(pow(B, 2) - (4*A*C));
	// tminus /= 2*A;
	
	// //std::cout <<"tplus " << tplus << " tminus " << tminus << std::endl;
	
	// if(tplus > 0 && tplus > tminus){
	// 	t_near = tplus	;
	// 	return true;
	// }

	// if(tminus > 0 ){
	// 	t_near = tminus;
	// 	return true;
	// }


	// return false;
}

void Sphere::setColor(Vector3D& color){
	this->color = color;
}

Vector3D Sphere::getColor(){
	return color;
}

Vector3D Sphere::getNormalToSurface(Vector3D* v){
	Vector3D n = *v - center;
	n.normalize();
	//std::cout << n << std::endl;
	return n;
}