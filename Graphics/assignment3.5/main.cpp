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

void stage1();
void stage2();
void stage3();
void stage41();
void stage42();
void stage43();
void stage5();
void stage6();
void stage7();

int main(){
	cout << "Testing FrameBuffer \n";
	// stage1();
	// stage2();
	// stage3();
	// stage41();
	// stage42();
	// stage43();
	// stage5();
	// stage6();
	stage7();
  return 0;
}

void stage1(){
	FrameBuffer* fb = new FrameBuffer(10, 10);

	Light* light = new Light(new Vector3D(1, 1, 1));
	Vector3D* color = new Vector3D(255, 100, 0);
	Vector3D* center = new Vector3D(0.5, 0.5, -2.0);
	double radius = .25;
	Sphere* s = new Sphere(center, radius, color);

	fb->addLight(light);
	fb->addObject(s);
	fb->rayTrace();

	fb->writePPM("10x10.ppm");

}

void stage2(){
	FrameBuffer* fb = new FrameBuffer(100, 100);

	Light* light = new Light(new Vector3D(1, 1, 1));
	Vector3D* color = new Vector3D(255, 100, 0);
	Vector3D* center = new Vector3D(0.5, 0.5, -2.0);
	double radius = .25;
	Sphere* s = new Sphere(center, radius, color);

	fb->addLight(light);

	fb->addObject(s);
	fb->rayTrace();

	fb->writePPM("100x100.ppm");

}

void stage3(){
	FrameBuffer* fb = new FrameBuffer(500, 500);

	Light* light = new Light(new Vector3D(-1, 1, 1));
	Vector3D* color = new Vector3D(255, 255, 255);
	Vector3D* center = new Vector3D(0.5, 0.5, -2.0);
	double radius = .25;
	Sphere* s = new Sphere(center, radius, color);

	fb->addLight(light);

	fb->addObject(s);
	fb->rayTrace();

	fb->writePPM("500x500.ppm");

}

void stage41(){
	FrameBuffer* fb = new FrameBuffer(500, 500);
	Vector3D* color = new Vector3D(1, 1, 1);
	Light* light = new Light(new Vector3D(-1, 1, 1));

	fb->addLight(light);
	color = new Vector3D(255, 0, 0);

	Vector3D* center = new Vector3D(0.5, 0.5, -2.0);
	double radius = .25;
	Sphere* s = new Sphere(center, radius, color);

	fb->addObject(s);


	fb->rayTrace();

	fb->writePPM("colorR.ppm");

}
void stage42(){
	FrameBuffer* fb = new FrameBuffer(500, 500);

	Vector3D* color = new Vector3D(1, 1, 1);
	Light* light = new Light(new Vector3D(-1, 1, 1));

	fb->addLight(light);
	color = new Vector3D(0, 255, 0);

	Vector3D* center = new Vector3D(0.5, 0.5, -2.0);
	double radius = .25;
	Sphere* s = new Sphere(center, radius, color);

	fb->addObject(s);


	fb->rayTrace();

	fb->writePPM("colorG.ppm");

}
void stage43(){
	FrameBuffer* fb = new FrameBuffer(500, 500);

	Vector3D* color = new Vector3D(1, 1, 1);
	Light* light = new Light(new Vector3D(-1, 1, 1));

	fb->addLight(light);

	color = new Vector3D(0, 0, 255);

	Vector3D* center = new Vector3D(0.5, 0.5, -2.0);
	double radius = .25;
	Sphere* s = new Sphere(center, radius, color);

	fb->addObject(s);


	fb->rayTrace();

	fb->writePPM("colorB.ppm");

}

void stage5(){
	FrameBuffer* fb = new FrameBuffer(500, 500);

	Vector3D* color = new Vector3D(0, 0, 1);
	Light* light = new Light(new Vector3D(-1, 1, 1), color);

	fb->addLight(light);
	Vector3D* center = new Vector3D(0.5, 0.5, -2.0);
	double radius = .25;
	Sphere* s = new Sphere(center, radius);

	fb->addObject(s);

	center = new Vector3D(0.75, 0.75, -5.0);
	color = new Vector3D(10, 255, 100);
	s = new Sphere(center, radius, color);

	fb->addObject(s);

	fb->rayTrace();

	fb->writePPM("stage5.ppm");

}

void stage6(){
	FrameBuffer* fb = new FrameBuffer(500, 500);
	fb->setMode(true);
	
	Vector3D* color = new Vector3D(0, 0, 1);
	Light* light = new Light(new Vector3D(-1, 1, 1), color);

	fb->addLight(light);
	Vector3D* center = new Vector3D(0.0, 0.0, -2.0);
	double radius = .25;
	Sphere* s = new Sphere(center, radius);

	fb->addObject(s);

	center = new Vector3D(0.5, 0.5, -5.0);
	color = new Vector3D(10, 255, 100);
	s = new Sphere(center, radius, color);

	fb->addObject(s);

	fb->rayTrace();
	fb->writePPM("stage6.ppm");

}

void stage7(){
	FrameBuffer* fb = new FrameBuffer(500, 500);
	fb->setMode(true);
	Light* light = new Light(new Vector3D(1, 1, 1));

	fb->addLight(light);

	Vector3D* v1 = new Vector3D(0, 0, -7);
	Vector3D* v2 = new Vector3D(0.0330127, 0.94282, -5);
	Vector3D* v3 = new Vector3D(0.45, 0.779423, -5);
	Triangle* t = new Triangle(v1, v2, v3, new Vector3D(255, 255, 255));


	fb->addObject(t);
	
	fb->rayTrace();
	fb->writePPM("stage7.ppm");
}