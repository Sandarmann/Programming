//Aleksandar Straumann
//Homework 1


#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#include "Vectors/Vector2D.h"
#include "Vector3D.h"
#include "Object3D.h"
#include "Light.h"
#include <vector>
using namespace std;
/*
 *Fucking apparently you just need a list of ints and the width is 3 times the actual to accomadate for the stupid ass pairings.....
 */
class FrameBuffer{
	public:
		FrameBuffer(int width, int height);
		FrameBuffer(int width, int height, int R, int G, int B);
		void display();
		int* bufferData();
		int getWidth();
		int getHeight();
		void setPixel(int height, int width, int R, int G, int B);
		void setPixel(int width, int height, Vector3D v);
		void reset(int R, int G, int B);
		void rasterizeline_implicit( const Vector2D& p0, const Vector2D &p1, const Vector3D& c)  ;
		void rasterizeline_parametric( const Vector2D& p0, const Vector2D& p1, const Vector3D& c0, const Vector3D& c1) ;
		void rasterizeTriangle(Vector2D* p0, Vector2D* p1, Vector2D* p2, Vector3D* c0, Vector3D* c1, Vector3D* c2);
		void rayTrace();
		void addObject(Object3D* o);
		void addLight(Light* l);
		void reset();
		void writePPM(const string& filename);
		void setMode(bool pers){
			this->perspective = pers;
		}
	private:
		void setPixelLogic(int height, int width, int R, int G, int B);
		int* ppm;
		int* data;
		int height;
		int width;
		bool perspective;
		std::vector<Light*> lights;
		std::vector<Object3D*> objects;
		const static int MAX = 255;
};
#endif
