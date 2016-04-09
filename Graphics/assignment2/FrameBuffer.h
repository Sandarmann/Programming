//Aleksandar Straumann
//Homework 1


#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#include "Vector2D.h"
#include "Vector3D.h"
using namespace std;
/*
 *Fucking apparently you just need a list of ints and the width is 3 times the actual to accomadate for the stupid ass pairings.....
 */
class FrameBuffer{
	public:
		FrameBuffer(int height, int width);
		FrameBuffer(int height, int width, int R, int G, int B);
		void display();
		int* bufferData();
		int getWidth();
		int getHeight();
		void setPixel(int height, int width, int R, int G, int B);
		void reset(int R, int G, int B);
		void rasterizeline_implicit( const Vector2D& p0, const Vector2D &p1, const Vector3D& c)  ;
		void rasterizeline_parametric( const Vector2D& p0, const Vector2D& p1, const Vector3D& c0, const Vector3D& c1) ;
		
		void reset();
		void writePPM(const string& filename);
	private:
		void setPixelLogic(int height, int width, int R, int G, int B);
		int* ppm;
		int* data;
		int height;
		int width;
		const static int MAX = 255;
};
#endif
