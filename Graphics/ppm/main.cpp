//
//Aleksandar Straumann
//CS5721
//Homework 1
//


#include <iostream>
#include <string>
#include "Vector2D.h"
#include "Vector3D.h"
#include "FrameBuffer.h"
using namespace std;

void test2D();
void test3D();
void testFrameBuffer();

int main(){
	test2D();
	test3D();
	cout << "Testing FrameBuffer \n";
	testFrameBuffer();
	return 0;
}


void testFrameBuffer(){
	FrameBuffer* allWhite = new FrameBuffer(89, 145, 255,255,255);
	allWhite->writePPM("white.ppm");

	FrameBuffer* black = new FrameBuffer(480, 48, 0, 0, 0);
	black->writePPM("black.ppm");
	FrameBuffer* allRed = new FrameBuffer(480, 600, 255,0,0);
	allRed->writePPM("red.ppm");


	FrameBuffer* allGreen = new FrameBuffer(10, 10, 0,255,0);
	allGreen->writePPM("green.ppm");

	FrameBuffer* part = new FrameBuffer(600,800);
	part->setPixel(0,0,0,255,0);	
	part->setPixel(part->getHeight() - 1, part->getWidth()-1 ,255,0,0);
	part->setPixel(0, part->getWidth()-1 ,255,255,0);
	part->writePPM("part.ppm");
}

void test3D(){

	float* z;
	Vector3D d(1.0, 3.0, 4.0), e(5.0, 3.2, 2.3), f(0.0, 0.0, 0.0);
	f = d + e;
	cout << "f = [" << f.getx() << ", " << f.gety() << ", " << f.getz() << "]" << endl << endl;
	cout << "d dot e = " << d.dot(e) << endl;
	cout << "d cross e = " << d.cross(e) << endl;
	cout << "e cross d = " << e.cross(d) << endl << endl;

	d.set(-2.32, 3.9, 7.1);
	e.set(14.2, 9.4, -3.6);
	cout << "d length = " << d.length() << endl;
	cout << "e length = " << e.length() << endl;

	double len = d.length();
	d.normalize();
	cout << "d = [" << d.getx() << ", " << d.gety() << ", " << d.getz() << "]" << endl;
	cout << "new d length = " << d.length() << ", old length = " << len << endl;

	d = d * len;
	cout << "d = [" << d.getx() << ", " << d.gety() << ", " << d.getz() << "]" << endl;

	z = d.vecfData();
	cout << "z = [" << z[0] << ", " << z[1] << ", " << z[2] << "]" << endl;
	cout << "\r\n";

}


void test2D(){
	Vector2D a(1.0, 3.0), b(5.0, 3.2), c(0.0, 0.0);
	c = a + b;
	cout << "c = [" << c.getx() << ", " << c.gety() << "]" << endl;

	std::cout << "a dot b = " << a.dot(b) << std::endl;
	std::cout << "a cross b = " << a.cross(b) << std::endl << std::endl;



	a.set(-4.0, 3.9);
	b.set(14.2, 9.4);
	cout << "a length = " << a.length() << endl;
	cout << "b length = " << b.length() << endl;

	double len = a.length();
	a.normalize();
	cout << "a = [" << a.getx() << ", " << a.gety() << "]" << endl;
	cout << "new a length = " << a.length() << ", old length = " << len << endl;

	a = a * len;
	cout << "a = [" << a.getx() << ", " << a.gety() << "]" << endl;
}
