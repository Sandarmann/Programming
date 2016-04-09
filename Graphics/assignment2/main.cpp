//
//Aleksandar Straumann
//CS5721
//Assigenment 2
//


#include <iostream>
#include <string>
#include "FrameBuffer.h"
#include <math.h>
using namespace std;

void test2D();
void test3D();
void testFrameBuffer();
void testRasterization();
void colorInterpolation();
void colorCreative();
int main(){
	cout << "Testing FrameBuffer \n";
	testRasterization();
	colorInterpolation();
	colorCreative();
	return 0;
}

void testRasterization(){
	FrameBuffer* line = new FrameBuffer(408, 725);
	// const Vector2D* p0 = new Vector2D(362,204); //always will be origin point
	// int theta = 90 * 3.14 / 180;
	// int x = p0->getx() + 150 * cos(theta);
	// int y = p0->gety() + 150 * sin(theta);
	// const Vector2D* p1 = new Vector2D(x,y); //this will be dependant on the x and y from angles
	// const Vector3D c(123,123,123);	
	// line->rasterizeline_implicit(*p0, *p1, c);
	// line->writePPM("circle.ppm");
	/*
		x and y = 
			origin x + radius * cos(degrees)
			swap for y
	 */
	const Vector3D c(123,123,123);		
	const Vector2D* p0 = NULL;
	const Vector2D* p1 = NULL;
	for(int theta = 0; theta < 360; theta+=12){
		double radians = theta * 3.14 / 180;
		p0 = new Vector2D(362,204); //always will be origin point
		int x = p0->getx() + 150 * cos(radians);
		int y = p0->gety() + 150 * sin(radians);
		cout << " X: " << x << " Y " << y << endl;
		p1 = new Vector2D(x,y); //this will be dependant on the x and y from angles
		line->rasterizeline_implicit(*p0, *p1, c);
	}
	// p1 = new Vector2D(225,265); //this will be dependant on the x and y from angles
	// line->rasterizeline_implicit(*p0, *p1, c);

	line->writePPM("circle.ppm");
}

void colorCreative(){
	FrameBuffer* line = new FrameBuffer(480, 640);
	const Vector3D* c = new Vector3D(0,0,0);		
	const Vector3D* c1 = new Vector3D(220,100,100);		
	const Vector2D* p0 = NULL;
	const Vector2D* p1 = NULL;

	for(int i = 170; i < 470; i+=20){
		p0 = new Vector2D(320, 0);
		p1 = new Vector2D(i, 100);
		line->rasterizeline_parametric(*p0, *p1, *c, *c1);
	}

	for(int i = 305; i > 290; i-=5){
		p0 = new Vector2D(305, 200);
		p1 = new Vector2D(i, 150);
		line->rasterizeline_parametric(*p0, *p1, *c, *c1);
	}

	for(int i = 335; i < 350; i+=5){
		p0 = new Vector2D(335, 200);
		p1 = new Vector2D(i, 150);
		line->rasterizeline_parametric(*p0, *p1, *c, *c1);
	}

	for(int i = 120; i < 240; i+=10){
		p0 = new Vector2D(120, 350);
		p1 = new Vector2D(i, 250);
		line->rasterizeline_parametric(*p0, *p1, *c, *c1);
	}

	for(int i = 520; i > 400; i-=10){
		p0 = new Vector2D(530, 350);
		p1 = new Vector2D(i, 250);
		line->rasterizeline_parametric(*p0, *p1, *c, *c1);
	}

	for(int i=0; i<640; i+= 40){
		c = new Vector3D(50, 50, 255);
		c1 = new Vector3D( 255,255,255);
		p0 = new Vector2D(0,480);
		p1 = new Vector2D(i, 0);
		line->rasterizeline_parametric(*p0, *p1, *c, *c1);
	}

	for(int i=640; i>0; i-= 40){
		c = new Vector3D(50, 255, 55);
		c1 = new Vector3D( 255,255,255);
		p0 = new Vector2D(640,470);
		p1 = new Vector2D(i, 0);
		line->rasterizeline_parametric(*p0, *p1, *c, *c1);
	}

	line->writePPM("colorCreative.ppm");
}

void colorInterpolation(){
	FrameBuffer* line = new FrameBuffer(480, 640);
	const Vector3D c(0,0,0);		
	const Vector3D c1(220,100,100);		
	const Vector2D* p0 = new Vector2D(320, 240);
	const Vector2D* p1 = NULL;

	for(int i = 220; i < 420; i+=20){
		p1 = new Vector2D(i, 340);
		line->rasterizeline_parametric(*p0, *p1, c, c1);
	}
	for(int i = 220; i < 420; i+=20){
		p1 = new Vector2D(i, 140);
		line->rasterizeline_parametric(*p0, *p1, c1, c);
	}
	for(int i = 140; i < 320; i+=20){
		p1 = new Vector2D(220, i);
		line->rasterizeline_parametric(*p0, *p1, c, c1); 
	}
	for(int i = 140; i < 320; i+=20){
		p1 = new Vector2D(420, i);
		line->rasterizeline_parametric(*p0, *p1, c1, c); // reverse color for this because the points for the x will get swapped and color drawn from the left to right
	}
		line->writePPM("colorSquare.ppm");
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
