//
//Aleksandar Straumann
//CS5721
//Assigenment 2
//


#include <iostream>
#include <string>
#include "FrameBuffer.h"
#include "Matrix3.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Vector3D.h"
#include <math.h>
using namespace std;

void testSpheres();
void testTriangleSphere();
void testSphereUnderTri();
int main(){
	cout << "Testing FrameBuffer \n";
	//testSpheres();
	testTriangleSphere();
	// testSphereUnderTri();
  return 0;
}

void testTriangleSphere(){
	FrameBuffer* fb  = new FrameBuffer(500, 500);
	Vector3D* j0 = new Vector3D(0,0,-1);
	Vector3D* j1 = new Vector3D(50,50,-10);
	Vector3D *j2 = new Vector3D(200,100,100);
	Vector3D* color = new Vector3D(255, 0, 0);
	Triangle *t2 = new Triangle(j0, j1, j2, color);
	fb->addObject(t2);

	

	// j0 = new Vector3D(-1,-1,-2);
	// j1 = new Vector3D(-2,-2,-2);
	// j2 = new Vector3D(-1,0,-2);
	//  color = new Vector3D(255, 0, 0);
	// Triangle *t2 = new Triangle(j0, j1, j2, color);
	// fb->addObject(t2);


	Vector3D* c1 = new Vector3D(0, 0, -20);
	double radius = 100;
	Vector3D* color2 = new Vector3D(200,100,0);
	Sphere* s1 = new Sphere(c1, radius, color2);
	fb->addObject(s1);

	fb->rayTrace();

	fb->writePPM("triangles.ppm");
}

void testSphereUnderTri(){
	FrameBuffer* fb  = new FrameBuffer(500,500);

	Vector3D* j0 = new Vector3D(100, 100, -10);
	Vector3D* j1 = new Vector3D(250, 300, -5);
	Vector3D *j2 = new Vector3D(300, 0, -15);
	Vector3D* color = new Vector3D(255, 0, 0);
	Triangle *t2 = new Triangle(j0, j1, j2, color);
	fb->addObject(t2);

	Vector3D* c1 = new Vector3D(300, 300, -3);
	double radius = 100;
	Vector3D* color2 = new Vector3D(200,100,0);
	Sphere* s1 = new Sphere(c1, radius, color2);
	fb->addObject(s1);

	fb->rayTrace();

	fb->writePPM("sphereOvertrii.ppm");
}

void testSpheres(){
	FrameBuffer* fb  = new FrameBuffer(1280, 1024);
	// Vector3D* p0 = new Vector3D(0, 0, -20);
	// Vector3D* p1 = new Vector3D(200, 300, -10);
	// Vector3D* p2 = new Vector3D(400, 10, -333);
	// Vector3D* c3 = new Vector3D(255, 0, 0);
	// Triangle* t = new Triangle(p0, p1, p2, c3);
	// fb->addObject(t);

	// Vector3D* a0 = new Vector3D(200, 200, -5);
	// Vector3D* a1 = new Vector3D(300, 500, -2);
	// Vector3D* a2 = new Vector3D(500, 400, -20);
	// Vector3D* c1 = new Vector3D(0, 255, 0);
	// t = new Triangle(a0, a1, a2, c1);
	// fb->addObject(t);
	
	Vector3D* c = new Vector3D(-5, 0, -20);
	double radius = 10;
	Vector3D* color = new Vector3D(255, 0, 0);
	Sphere* s = new Sphere(c, radius, color);
	fb->addObject(s);

	// Vector3D* c1 = new Vector3D(300, 300, -10);
	// radius = 100;
	// Vector3D* color2 = new Vector3D(200,100,0);
	// Sphere* s1 = new Sphere(c1, radius, color2);
	// fb->addObject(s1);
	fb->rayTrace();

	fb->writePPM("spheres.ppm");
	// Ray r;
	// Vector3D W = Vector3D(0, 0, -1);
	// W.normalize(); // this just does the division to form the basis
	// Vector3D U = Vector3D(Vector3D(0, 1, 0).cross(W));
	// U.normalize();
	// Vector3D V = Vector3D(W.cross(U));
	// r.setOrigin(Vector3D(400, 400,0) +  (U * 50) + (V * 100));

	// r.setDir(W * -1);

	// float f = 9999;
	// cout << "Intersect ?? " << t->intersect(r, 0.0f, f) << endl;

	//fb->addObject(t);
}

