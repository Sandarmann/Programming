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

void testTriangle();
void makePolygon();
void makeDimension();
int main(){
	cout << "Testing FrameBuffer \n";
  testTriangle();
  makePolygon();
  makeDimension();
  return 0;
}

void makeDimension(){
  int width = 800;
  int height = 600;
  const Vector2D* line1 = NULL;
  const Vector2D* line2 = NULL;
  const Vector3D c(255,255,255);
  FrameBuffer* tri = new FrameBuffer(width, height);
  Vector2D* p0 = new Vector2D(300,300);
  Vector2D* p1 = new Vector2D(300,400);
  Vector2D* p2 = new Vector2D(400,300);
  Vector3D* c0 = new Vector3D(255, 0, 0);
  Vector3D* c1 = new Vector3D(0, 255, 0);
  Vector3D* c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(300,400);
  p1 = new Vector2D(400,400);
  p2 = new Vector2D(400,300);
  c0 = new Vector3D(255, 255, 255);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
	tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(400,300);
  p1 = new Vector2D(440,330);
  p2 = new Vector2D(400,400);
  c0 = new Vector3D(255, 255, 255);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
	tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);


  p0 = new Vector2D(440,413);
  p1 = new Vector2D(400,400);
  p2 = new Vector2D(440,330);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
	tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(352,415);
  p1 = new Vector2D(300,400);
  p2 = new Vector2D(440,413);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(255, 255, 0);
  c2 = new Vector3D(0, 0, 255);
	tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(440,413);
  p1 = new Vector2D(400,400);
  p2 = new Vector2D(300,400);
  c0 = new Vector3D(255, 255, 255);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
	tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

	tri->writePPM("dimensional.ppm");
}

void testTriangle(){
  int width = 800;
  int height = 600;
  FrameBuffer* tri = new FrameBuffer(width, height);
  Vector2D* p0 = new Vector2D(0,0);
  Vector2D* p1 = new Vector2D(width-1,0);
  Vector2D* p2 = new Vector2D(width-1,height-1);
  Vector3D* c0 = new Vector3D(255, 0, 0);
  Vector3D* c1 = new Vector3D(0, 255, 0);
  Vector3D* c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //tri->writePPM("tri.ppm");

  //FrameBuffer* tri2 = new FrameBuffer(height, width);
  p0 = new Vector2D(width-1, height-1);
  p1 = new Vector2D(0, height-1);
  p2 = new Vector2D(0,0);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //tri->writePPM("tri.ppm");

  FrameBuffer* tri2 = new FrameBuffer(width, height);
  p0 = new Vector2D(200, 0);
  p1 = new Vector2D(200, 200);
  p2 = new Vector2D(0,200);
  c0 = new Vector3D(255, 255, 0);
  c1 = new Vector3D(0, 255, 255);
  c2 = new Vector3D(255, 0, 255);
  tri2->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //tri->writePPM("tri3.ppm");
  
  //FrameBuffer* tri = new FrameBuffer(height, width);
  p0 = new Vector2D(200, 0);
  p1 = new Vector2D(width-1, 200);
  p2 = new Vector2D(200,200);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(255, 0, 0);
  c2 = new Vector3D(0, 0, 255);
  tri2->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //tri4->writePPM("tri4.ppm");

  //FrameBuffer* tri = new FrameBuffer(height, width);
  p0 = new Vector2D(200, height-1);
  p1 = new Vector2D(200, 200);
  p2 = new Vector2D(width-1,200);
  c0 = new Vector3D(0, 255, 0);
  c1 = new Vector3D(0, 0, 0);
  c2 = new Vector3D(0, 0, 255);
  tri2->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //tri5->writePPM("tri5.ppm");

  //FrameBuffer* tri = new FrameBuffer(height, width);
  p0 = new Vector2D(200, 200);
  p1 = new Vector2D(200, height-1);
  p2 = new Vector2D(0,200);
  c0 = new Vector3D(0, 255, 0);
  c1 = new Vector3D(255, 255, 0);
  c2 = new Vector3D(255, 255, 255);
  tri2->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  tri2->writePPM("tri2.ppm");

}


void makePolygon(){
	int width = 1280;
  int height = 1024;
  FrameBuffer* tri = new FrameBuffer(width, height);

  //Square
  Vector2D* p0 = new Vector2D(0,0);
  Vector2D* p1 = new Vector2D(100,0);
  Vector2D* p2 = new Vector2D(0,100);
  Vector3D* c0 = new Vector3D(255, 0, 0);
  Vector3D* c1 = new Vector3D(0, 255, 0);
  Vector3D* c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);


  p0 = new Vector2D(100,0);
  p1 = new Vector2D(100,100);
  p2 = new Vector2D(0,100);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //End Square 
  
  // Shitty Pentagon
  p0 = new Vector2D(500,500);
  p1 = new Vector2D(600,500);
  p2 = new Vector2D(500,400);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(500,400);
  p1 = new Vector2D(600,400);
  p2 = new Vector2D(600,500);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(500,500);
  p1 = new Vector2D(600,500);
  p2 = new Vector2D(550,550);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(500,500);
  p1 = new Vector2D(500,400);
  p2 = new Vector2D(450,450);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(600,500);
  p1 = new Vector2D(600,400);
  p2 = new Vector2D(650,450);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //End  Shitty Pentagon
  
  // Pentagon New
  
  p0 = new Vector2D(400,100);
  p1 = new Vector2D(500,100);
  p2 = new Vector2D(450,200);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(450,300);
  p1 = new Vector2D(550,200);
  p2 = new Vector2D(450,200);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(450,300);
  p1 = new Vector2D(350,200);
  p2 = new Vector2D(450,200);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(350,200);
  p1 = new Vector2D(400,100);
  p2 = new Vector2D(450,200);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(550,200);
  p1 = new Vector2D(500,100);
  p2 = new Vector2D(450,200);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //End Pentagon New
  
  //Trapezoid
  

  p0 = new Vector2D(800,800);
  p1 = new Vector2D(900,800);
  p2 = new Vector2D(850,700);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);


  p0 = new Vector2D(850,700);
  p1 = new Vector2D(950,700);
  p2 = new Vector2D(900,800);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(900,800);
  p1 = new Vector2D(1000,800);
  p2 = new Vector2D(950,700);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(950,700);
  p1 = new Vector2D(1050,700);
  p2 = new Vector2D(1000,800);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);

  p0 = new Vector2D(1000,800);
  p1 = new Vector2D(1100,800);
  p2 = new Vector2D(1050,700);
  c0 = new Vector3D(255, 0, 0);
  c1 = new Vector3D(0, 255, 0);
  c2 = new Vector3D(0, 0, 255);
  tri->rasterizeTriangle(p0, p1, p2, c0, c1, c2);
  //End Trap
  tri->writePPM("polygons.ppm");


}
