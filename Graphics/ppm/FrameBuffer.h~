//Aleksandar Straumann
//Homework 1


#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
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
