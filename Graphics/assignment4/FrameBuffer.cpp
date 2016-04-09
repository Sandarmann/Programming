//
//Aleksandar Straumann
//CS5721
//Assigenment 3
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Vector3D.h"
#include "Vector2D.h"
#include "FrameBuffer.h"
#include <math.h>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

FrameBuffer::FrameBuffer(int width, int height){
	this->height = height;
	this->width = width * 3;
	this->ppm = new int[this->width*this->height];
	for (int i=0; i<this->width * this->height; i++){
		this->ppm[i] = 0;
	}
}

FrameBuffer::FrameBuffer(int width, int height, int R, int G, int B){
	this->height = height;
	this->width = width * 3;
	this->ppm = new int[this->width * this->height];
	for(int i=0; i< this->width*this->height; i++){
		if(i%3==0){
			this->ppm[i] = R;
		}
		else if (i%3 == 1){
			this->ppm[i] = G;
		}
		else if(i%3 == 2){
			this->ppm[i] = B;
		}
	}

}

void FrameBuffer::display(){
	for(int i=0; i<this->height; i++){
		for(int j=0; j<this->width; j++){
			cout << this->ppm[this->width * i + j] << " ";
		}
		cout << endl;
	}
}

int* FrameBuffer::bufferData(){
	int* returnBuffer = new int[this->width*this->height];
	//cout << this->width * this->height << endl;
	for(int i=0; i<this->height; i++){
		for(int j=0; j<this->width; j++){
			int index = ((this->height-i-1)*this->width) + j;
			returnBuffer[j + (i*this->width)] = this->ppm[index];
		}
	}

	return returnBuffer;
}
/**
 * [FrameBuffer::setPixel Main function for use with setting pixel colors
 * @param width x value
 * @param height y valie
 * @param R      [description]
 * @param G      [description]
 * @param B      [description]
 */
void FrameBuffer::setPixel(int width, int height, int R, int G, int B){
	try{
		setPixelLogic(height, width, R, G, B);
	}
	catch(const out_of_range &oor){
		cout << "Not in bounds of image x: " << width << " y: " << height << ", will not change any data" << endl;
	}
}

void FrameBuffer::setPixel(int width, int height, Vector3D v){
	try{
		setPixelLogic(height, width, v.getx(), v.gety(), v.getz());
	}
	catch(const out_of_range &oor){
		cout << "Not in bounds of image x: " << width << " y: " << height << ", will not change any data" << endl;
	}
}

/*
   This determines if the slope of the line is greater in the y than the x
   */
const bool isSteep(const Vector2D& p0,  const Vector2D& p1) {
	double dy = p1.gety() - p0.gety();
	double dx = p1.getx()-p0.getx();
	return (fabs(dy) > fabs(dx));
}

/*
   f(x,y)≡(y0 −y1)x+(x1 −x0)y+x0y1 −x1y0 =0. (8.1)
   helper funciton for finding the implicit value
   */
double implicit(Vector2D* p0,   Vector2D* p1, double x, double y){
	double dy = p0->gety() - p1->gety();
	double dx = p1->getx() - p0->getx();
	double xfye = p0->getx() * p1->gety();
	double xeyf = p1->getx() * p0->gety();

	return ((dy * x) + (dx * y) + xfye - xeyf);
}

void FrameBuffer::rasterizeline_implicit( const Vector2D& p0, const Vector2D &p1, const Vector3D& c) {
	/*
	   shit was wrong...do it again
	   */
	Vector2D* origin = new Vector2D(p0.getx(), p0.gety());
	Vector2D* end = new Vector2D(p1.getx(), p1.gety());
	bool steep = isSteep(p0, p1);
	if(steep){
		origin->swap();
		end->swap();
	}

	if(origin->getx() > end->getx()){
		Vector2D* tmp = NULL;
		tmp = end;
		end = origin;
		origin = tmp;
	}

	double deltaX = fabs(end->getx() - origin->getx());
	double deltaY = fabs(end->gety() - origin->gety());
	/*
	   The error is a representation of the steps needed before incrementing a value. For example:
	   if we have origin 0,0
	   end 10,5
	   dx = 10
	   dy = 5 

	   so for every 1 increment of y we need to do 2 increments of x. 

	   This is a much clearer way of representing the line error values...
	   Tried using the implicit equation with no luck
	   */
	double error = ::implicit(origin,end, origin->getx() + 1, origin->gety());//= deltaX/2.0;
	int iY = (origin->gety() < end->gety()) ? 1 : -1; //without this you do not get the right slope on a line if going in reverse

	int y = origin->gety();
	for(int x = origin->getx(); x != end->getx(); x++){
		if(steep){
			this->setPixel(y, x, c.getx(), c.gety(), c.getz());
		}
		else{
			this->setPixel(x, y, c.getx(), c.gety(), c.getz());         
		}
		error -= deltaY; //(this replaces the (y0-y1) in the rasterization algorithm)
		if(error < 0){
			y += iY;
			//error = ::implicit(origin,end, x, y); //-= deltaY;    
			error += deltaX;//(this replaces the (x1-x0) in the rasterization algorithm)
		}
	}
}

// 0 <= stepNumber <= lastStepNumber
int interpolate(int color1, int color2, double fraction){
	return (double) (((color2 - color1) * fraction) + color1);
}

/*
http://stackoverflow.com/questions/13488957/interpolate-from-one-color-to-another
Colors the output from point 1 being the most intense with the second color to the second point being the most intense with the first color
*/
void FrameBuffer::rasterizeline_parametric( const Vector2D& p0, const Vector2D& p1, const Vector3D& c0, const Vector3D& c1){
	Vector2D* origin = new Vector2D(p0.getx(), p0.gety());
	Vector2D* end = new Vector2D(p1.getx(), p1.gety());
	bool steep = isSteep(p0, p1);
	if(steep){
		origin->swap();
		end->swap();
	}

	if(origin->getx() > end->getx()){
		Vector2D* tmp = NULL;
		tmp = end;
		end = origin;
		origin = tmp;
	}

	double deltaX = fabs(end->getx() - origin->getx());
	double deltaY = fabs(end->gety() - origin->gety());
	double error = ::implicit(origin,end, origin->getx() + 1, origin->gety());//= deltaX/2.0;
	int iY = (origin->gety() < end->gety()) ? 1 : -1; //without this you do not get the right slope on a line if going in reverse
	int y = origin->gety();
	for(int x = origin->getx(); x != end->getx(); x++){
		double frac = (x-origin->getx())/deltaX ;
		if(steep){
			int r = interpolate(c1.getx(), c0.getx(), frac);
			int g = interpolate(c1.gety(), c0.gety(), frac);
			int b = interpolate(c1.getz(), c0.getz(), frac);
			this->setPixel(y, x, r, g, b);
		}
		else{
			int r = interpolate(c0.getx(), c1.getx(), frac);
			int g = interpolate(c0.gety(), c1.gety(), frac);
			int b = interpolate(c0.getz(), c1.getz(), frac);
			this->setPixel(x, y, r, g, b);          
		}
		error -= deltaY; //(this replaces the (y0-y1) in the rasterization algorithm)
		if(error < 0){
			y += iY;
			//error = ::implicit(origin,end, x, y); //-= deltaY;    
			error += deltaX;//(this replaces the (x1-x0) in the rasterization algorithm)
		}
	}
}   

void FrameBuffer::rasterizeTriangle(Vector2D* p0, Vector2D* p1,Vector2D*  p2, Vector3D* c0, Vector3D* c1, Vector3D* c2){
	int xmax = max(p0->getx(), max(p1->getx(), p2->getx())) ;
	int ymax = max(p0->gety(), max(p1->gety(), p2->gety()));
	int xmin = min(p0->getx(), min(p1->getx(), p2->getx()));
	int ymin = min(p0->gety(), min(p1->gety(), p2->gety()));

	for(int y = ymin; y <= ymax; y++){
		for(int x = xmin; x <= xmax; x++){
			double alpha = ::implicit(p1, p2, x, y) / :: implicit(p1, p2, p0->getx(), p0->gety());
			double beta =  ::implicit(p2, p0, x, y) / :: implicit(p2, p0, p1->getx(), p1->gety());
			double gamma =  ::implicit(p0, p1, x, y) / :: implicit(p0, p1, p2->getx(), p2->gety());

			if(alpha > 0 && beta > 0 && gamma > 0){
				Vector3D* c = new Vector3D(((*c0*alpha) + (*c1 * beta) + (*c2 * gamma)));
				this->setPixel(x,y, c->getx(), c->gety(), c->getz());
			}
		}
	}
}
/**
 * [FrameBuffer::rayTrace iterates through all the pixels on the screen and will determine if the line drawn from 
 * the origin will connect with an object in the list of objects. It will then set the color of the pixel at that location.
 */
void FrameBuffer::rayTrace(){ 
	double n_y = this->height;
	double n_x = this->width / 3;
	double l = n_x / 2 * -1;
	double r = n_x / 2;
	double t = n_y /2;
	double b = n_y/2 * -1;
	// cout << "nx " << n_x << endl;
	// cout << "ny " << n_y << endl;
	Vector3D U =  Vector3D(1, 0, 0);
	Vector3D V =  Vector3D(0, 1, 0);
	Vector3D W = Vector3D(0, 0, -1); // Pointing away
	// cout << "U : " << U.getx() << " " << U.gety() << " " << U.getz() << endl;
	// cout << "V : " << V.getx() << " " << V.gety() << " " << V.getz() << endl;

	//iterate through all pixels
	for(int y = 0; y<n_y; y++){
		//Divide by 3 cause it's da image ppm res
		for(int x=0; x<n_x; x++){
			float t_near = -9999;
			float t_max = 9999;
			bool hit = false;
			float t_prev = t_max;
			
			double u = l + (r-l) * (x + 0.5)/n_x;
		            // v = b + (t − b)(j + 0.5)/ny
		           double v = b + (t - b) * (y + 0.5)/n_y;
			Ray ray = Ray();	
			ray.setDir( (W * -1));
			ray.setOrigin((U * u) + (V * v));
			//w * (-1 * 1000) + u * lu + v * lv;
			//\cout << "ray : " << ray.getDir() << endl;
			Object3D* closest = NULL;
			for(int i=0; i<objects.size(); i++){

				if(objects.at(i)->intersect(ray, t_near, t_max)){ //t_near should update on call
					if(t_max < t_prev){
						hit = true;
						t_prev = t_max;
						closest = objects.at(i);
						//cout << "t_max" << endl;
					}
				}
			}
			if(hit){
				Vector3D l = Vector3D(-1.0,1.0,1.0);
				l.normalize();
				//L=kaIa +kdImax(0,n·l)+ksImax(0,n·h)n,
				Vector3D h  = Vector3D(0, 0, 1) + l;
				h = h * (1 / h.length());
				double k_a = 0.9;
				double l_a = 0.3;
				double k_d = 0.9;
				double k_s = 0.5;
				Vector3D normal = closest->getNormalToSurface(new Vector3D (ray.getOrigin() + ray.getDir() * t_max) );
				double intensity = 1.0;
				double dot = normal.dot(l);
				float L = k_a * l_a + k_d * max(0.0, normal.dot(l)) + k_s* intensity * max(0.0, normal.dot(h));
				if(L > 1){
					L = 1;
				}
				this->setPixel(x, y, closest->getColor() * L);
				//cout << "x: " << x << " Y: " << y << endl;
			}else{
				this->setPixel(x, y, 128, 128, 128);
			}
		}
	}
}


/**
 * [FrameBuffer::addObject adds an object to the list of objects
 * @param o an object of type OBJECT3D
 */
void FrameBuffer::addObject(Object3D* o){
	objects.push_back(o); 
}

/**
 * [FrameBuffer::addLight adds a light to the list of lights
 * @param l [description]
 */
void FrameBuffer::addLight(Vector3D* l){
	lights.push_back(l);
}

void FrameBuffer::reset(){
	for(int i=0; i<this->width * this->height; i++){
		this->ppm[i] = 0;
	}
}


void FrameBuffer::writePPM(const string& filename){
	int* writeBuffer = bufferData();
	ofstream myfile;
	try{
		myfile.open(filename.c_str());
		myfile << "P3\n";
		myfile << this->width/3 << " " << this->height << " " << 255 << "\n";
		for(int i = 0; i <this->height; i++){
			for(int j=0; j < this->width; j++){
				//cout << "index: " << j + (i * this->width) << endl;
				//cout << writeBuffer[j + (i*this->width)] << endl;
				myfile<<writeBuffer[(i * this->width) + j] << " ";
			}
			myfile << "\n";
		}
	}
	catch(ofstream::failure e){
		cout << "Could not open and write to file, quitting current operation \n";
	}

	myfile.close();
}


int FrameBuffer::getWidth(){
	return this->width/3;
}   

int FrameBuffer::getHeight(){
	return this->height;
}

void FrameBuffer::reset(int R, int G, int B){
	for(int i=0; i<this->width * this->height; i++){
		if(i%3==0){
			this->ppm[i] = R;
		}
		else if (i%3 == 1){
			this->ppm[i] = G;
		}
		else if(i%3 == 2){
			this->ppm[i] = B;
		}
	}
}

void FrameBuffer::setPixelLogic(int height, int width, int R, int G, int B){
	if(height < 0 || height > this->height || width < 0 || width > (this->width/3)){
		throw out_of_range("Bad height/width"); 
	}
	else{
		//cout << "width , height: " << width << " : " << height << endl;
		//cout << "Max: " << this->height * this->width << endl;
		int i = width*3 + (height*this->width);
		//cout << "index " << i; 
		this->ppm[i]=R;
		this->ppm[i+1]=G;
		this->ppm[i+2]=B;
	}
}
