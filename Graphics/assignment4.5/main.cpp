//
//Aleksandar Straumann
//CS5721
//Assigenment 2
//


#include <iostream>
#include <string>
#include "FrameBuffer.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Vector3D.h"
#include <math.h>
using namespace std;

void orth();
void persp();

int main(){
	cout << "Testing FrameBuffer \n";
	orth();
	persp();
  return 0;
}

void orth(){
	FrameBuffer* fb = new FrameBuffer(500, 500, 128, 128, 128);
	
	Light* light = new Light(new Vector3D(-1, 1, 1));

	fb->addLight(light);

	/*
		Since the near and far are set to -5 and -25
		you will notice that the max width the triangle can go is 20, since that is what it is relative to
		for some reason...
		
		Fixed this when adding camera and correct matrix multiplication
	*/
	Vector3D* v1 = new Vector3D(0, 0, -5);
	Vector3D* v2 = new Vector3D(.5, 1.1, -5);
	Vector3D* v3 = new Vector3D(1,.4, -5); 
	Triangle* t = new Triangle(v1, v2, v3, new Vector3D(0, 255, 255));


	fb->addTriangle(t);
	
	v1 = new Vector3D(0, 0, -6);
	v2 = new Vector3D(0, 5, -6);
	v3 = new Vector3D(4, 5, -6); 
	t = new Triangle(v1, v2, v3, new Vector3D(10, 0, 238));


	fb->addTriangle(t);
	
		
	v1 = new Vector3D(-10, 0, -6);
	v2 = new Vector3D(2, 6, -6);
	v3 = new Vector3D(1, -2, -6); 
	t = new Triangle(v1, v2, v3, new Vector3D(38, 128, 0));


	fb->addTriangle(t);
	
	fb->zBufferTrace(true); //True puts it in orth mode
	
	fb->writePPM("orth.ppm");
}

void persp(){
	FrameBuffer* fb = new FrameBuffer(500, 500, 128, 128, 128);
	
	Light* light = new Light(new Vector3D(-1, 1, 1));

	fb->addLight(light);

	/*
		Since the near and far are set to -5 and -25
		you will notice that the max width the triangle can go is 20, since that is what it is relative to
		for some reason...
	*/
	Vector3D* v1 = new Vector3D(0, 0, -10);
	Vector3D* v2 = new Vector3D(1, 3, -7);
	Vector3D* v3 = new Vector3D(-5, 0, -5); 
	Triangle* t = new Triangle(v1, v2, v3, new Vector3D(255, 0, 25));


	fb->addTriangle(t);
	
	v1 = new Vector3D(3, 3, -5);
	v2 = new Vector3D(-6, -7, -7);
	v3 = new Vector3D(-2, 4, -6); 
	t = new Triangle(v1, v2, v3, new Vector3D(0, 255, 0));


	fb->addTriangle(t);
	
	v1 = new Vector3D(5, 3, -5);
	v2 = new Vector3D(-2, -10, -19);
	v3 = new Vector3D(-10, 4, -8); 
	t = new Triangle(v1, v2, v3, new Vector3D(0, 0, 255));


	fb->addTriangle(t);
	
	fb->zBufferTrace(false); //False puts it in persp
	
	fb->writePPM("persp.ppm");
}