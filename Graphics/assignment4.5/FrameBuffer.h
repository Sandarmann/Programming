//Aleksandar Straumann
//Homework 1


#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#include "Vectors/Vector2D.h"
#include "Vector3D.h"
#include "Object3D.h"
#include "Light.h"
#include "Triangle.h"
#include "Vector4D.h"
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
		void rasterizeTriangle(Vector4D* p0, Vector4D* p1, Vector4D* p2, Triangle* tri);
		void rayTrace();
		void addObject(Object3D* o);
		void addTriangle(Triangle* t);
		void addLight(Light* l);
		void reset();
		void writePPM(const string& filename);
		void setMode(bool pers){
			this->perspective = pers;
		}
		void zBufferTrace(bool orth_mode); //Will extend to allow input of view volume
	private:
		void setPixelLogic(int height, int width, int R, int G, int B);
		int* ppm;
		int* data;
		int height;
		int width;
		bool perspective;
		std::vector<Light*> lights;
		std::vector<Object3D*> objects;
		std::vector<Triangle*> triangles;
		const static int MAX = 255;
};
#endif
