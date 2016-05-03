//
//Aleksandar Straumann
//CS5721
//Assigenment 3
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Vector3D.h"
#include "Matrix4.h"
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
	this->perspective = false;
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

double implicit(Vector4D* p0,   Vector4D* p1, double x, double y){
	double dy = p0->y - p1->y;
	double dx = p1->x - p0->x;
	double xfye = p0->x * p1->y;
	double xeyf = p1->x * p0->y;

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

void FrameBuffer::rasterizeTriangle(Vector4D* p0, Vector4D* p1,Vector4D*  p2, Triangle* tri){
	int xmax = max(p0->x, max(p1->x, p2->x)) ;
	int ymax = max(p0->y, max(p1->y, p2->y));
	int xmin = min(p0->x, min(p1->x, p2->x));
	int ymin = min(p0->y, min(p1->y, p2->y));

	for(int y = ymin; y <= ymax; y++){
		for(int x = xmin; x <= xmax; x++){
			double alpha = ::implicit(p1, p2, x, y) / :: implicit(p1, p2, p0->x, p0->y);
			double beta =  ::implicit(p2, p0, x, y) / :: implicit(p2, p0, p1->x, p1->y);
			double gamma =  ::implicit(p0, p1, x, y) / :: implicit(p0, p1, p2->x, p2->y);
			if(alpha > 0 && beta > 0 && gamma > 0){
				Vector3D* c = new Vector3D(((tri->getColor()*alpha) + (tri->getColor() * beta) + (tri->getColor() * gamma)));
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
	//For the values below this just sets it relative to the origin which is the center of the screen.
	// I am changing it now to be based off the bottom left where 0,0 equals that and 1,1 is top right
	double l = 0.0;//n_x / 2 * -1;
	double r = 1.0; //n_x / 2;
	double t = 1.0; //n_y /2;
	double b = 0.0 ; //n_y/2 * -1;
	// cout << "nx " << n_x << endl;
	// cout << "ny " << n_y << endl;
	Vector3D U =  Vector3D(1, 0, 0);
	Vector3D V =  Vector3D(0, 1, 0);
	Vector3D W = Vector3D(0, 0, 1); // Pointing away
	// cout << "U : " << U.getx() << " " << U.gety() << " " << U.getz() << endl;
	// cout << "V : " << V.getx() << " " << V.gety() << " " << V.getz() << endl;
	
	if(perspective){
		l = -1;
		b = -1;
	}

	Object3D* closest = NULL;	

	//iterate through all pixels
	for(int y = 0; y<n_y; y++){
		//Divide by 3 cause it's da image ppm res
		for(int x=0; x<n_x; x++){
			float t_near = -9999;
			float t_max = 9999;
			bool hit = false;
			float t_cur = t_near;
			
			double u = l + (r-l) * (x + 0.5)/n_x;
		            // v = b + (t − b)(j + 0.5)/ny
		           	double v = b + (t - b) * (y + 0.5)/n_y;
			Ray ray = Ray();	
			if(perspective){
				ray.setOrigin( Vector3D(0,0,0) );
				ray.setDir((W * -5 )  + (U * u) + (V * v));
			} else {
				ray.setDir( (W * -1));
				ray.setOrigin(W  + (U * u) + (V * v));
			}
			//w * (-1 * 1000) + u * lu + v * lv;
			//\cout << "ray : " << ray.getDir() << endl;
			for(int i=0; i<objects.size(); i++){

				if(objects.at(i)->intersect(ray, t_near, t_cur)){ //t_near should update on call
					if(t_cur  > t_near && t_cur < t_max){
						// cout << "x " << x << " y " << y << endl;
						hit = true;			
						// cout << "t_prev" << t_prev << endl;
						// cout << "t_max" << t_max << endl;
						t_max = t_cur;
						closest = objects.at(i);			
						// cout << closest->getColor() << endl;
					} 
					// else {
					// 	//t_max = t_prev;
					// }
				}
			}
			if(hit){
				float L[3] = {0};
				for(int i=0; i<lights.size(); i++){
					Vector3D* l = lights.at(i)->dir;
					Vector3D* c = lights.at(i)->color;
					l->normalize();
					Vector3D h  = Vector3D(0, 0, 1) + *l;
					h = h * (1 / h.length());
					double k_a = 0.9;
					double l_a = 0.3;
					double k_d = 0.9;
					double k_s = 1.0;
					Vector3D normal = closest->getNormalToSurface(new Vector3D (ray.getOrigin() + ray.getDir() * t_max) );
					double intensity = 1.0;
					double dot = normal.dot(*l);
					L[0] += k_a * l_a + k_d * c->getx() * max(0.0, normal.dot(*l)) + k_s* c->getx() * pow(max(0.0, normal.dot(h)), 1000);
					L[1] += k_a * l_a + k_d * c->gety() * max(0.0, normal.dot(*l)) + k_s* c->gety() * pow(max(0.0, normal.dot(h)), 1000);
					L[2] += k_a * l_a + k_d * c->getz() * max(0.0, normal.dot(*l)) + k_s* c->getz() * pow(max(0.0, normal.dot(h)), 1000);
				}
				for(int i =0; i<3; i++){
					if ( L[i] > 1){
						L[i] = 1;
					}
				}
				this->setPixel(x, y, closest->getColor() * Vector3D( L[0],L[1] ,L[2]));
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
*
*
*/
void FrameBuffer::addTriangle(Triangle* t){
	triangles.push_back(t);
}

/**
 * [FrameBuffer::addLight adds a light to the list of lights
 * @param l [description]
 */
void FrameBuffer::addLight(Light* l){
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


void FrameBuffer::zBufferTrace(bool orth_mode){
	double n_y = this->height;
	double n_x = this->width / 3;
	//For the values below this just sets it relative to the origin which is the center of the screen.
	// I am changing it now to be based off the bottom left where 0,0 equals that and 1,1 is top right
	double l = -10.0;//n_x / 2 * -1;
	double r = 10.0; //n_x / 2;
	double t = 10.0; //n_y /2;
	double b = -10.0 ; //n_y/2 * -1;
	/*
		NEED TO CHANGE AFTER IT WORKS
	*/
	
	double n = -5.0;
	double f = -25.0;
	
	Matrix4* m_vp = new Matrix4((n_x/2),0,0,(n_x - 1)/2,
									0,(n_y/2),0,(n_y - 1)/2,
									0,0,1,0,
									0,0,0,1);
    
	// m_vp->print();
	Matrix4* m_proj = new Matrix4();
		Vector3D* E ;
		Vector3D* G ;
		Vector3D* T ;
		Vector3D W ;
		Vector3D U ;
		Vector3D V ;
	m_proj->makeOrtho(l, r, b, t, n, f);
	// m_proj->print();
	E = new Vector3D(1.0, 1.0, 10.0);
	G = new Vector3D(0.0, 0.0, -1.0);
	T = new Vector3D(0.1, 1.0, 0.0);
	W = *G * (1 / G->length()) * -1;
	U = T->cross(W) * (T->cross(W)).length();
	V = W.cross(U);
	if(!orth_mode){
		Matrix4* P = new Matrix4(n,0,0,0,
									0, n, 0, 0,
									0, 0, n+f, -1 * f * n,
									0, 0, 1, 0);
		m_proj = *m_proj * P;
		// m_proj->print();
		E = new Vector3D(0.0, 0.0, 0.0);
		G = new Vector3D(0.0, 0.0, -1.0);
		T = new Vector3D(0.0, 1.0, 0.0);
		W = *G * (1 / G->length()) * -1;
		U = T->cross(W) * (T->cross(W)).length();
		V = W.cross(U);
	}
	// std::cout << std::endl << "MATRIX PROJ" << std::endl;
	
	Matrix4* view = new Matrix4(U.getx(), U.gety(), U.getz(), 0,
								V.getx(), V.gety(), V.getz(), 0,
								W.getx(), W.gety(), W.getz(), 0,
								0,0,0,1);
	Matrix4* view2 = new Matrix4(1, 0, 0, -E->getx(), 
									0,1,0, -E->gety(),
									0,0,1,-E->getz(),
									0,0,0,1);
	Matrix4* cam = (*view) * view2;
	
	
	Matrix4* M = *((*m_vp) * (m_proj)) * cam;
	
	// M->print();
	
	double z_buffer[(int)n_x][(int)n_y];
	memset(z_buffer, f, sizeof(z_buffer));	
	
	
	for(int i = 0; i < triangles.size(); i++){
		Triangle* tri = triangles.at(i);
		Vector4D* p0_prime = (*M) * new Vector4D(tri->getp0());
				
		// p0_prime->print();
		p0_prime->homogonize();
		Vector4D* p1_prime = (*M) * new Vector4D(tri->getp1());
		p1_prime->homogonize();
		// p1_prime->print();
		Vector4D* p2_prime = (*M) * new Vector4D(tri->getp2());
		p2_prime->homogonize();
		// p2_prime->print();
		// std::cout << "HEREREJKHRE" << std::endl;
		// p0_prime
		int xmax = max(p0_prime->x, max(p1_prime->x, p2_prime->x)) ;
		int ymax = max(p0_prime->y, max(p1_prime->y, p2_prime->y));
		int xmin = min(p0_prime->x, min(p1_prime->x, p2_prime->x));
		int ymin = min(p0_prime->y, min(p1_prime->y, p2_prime->y));

		// std::cout << "X: " << xmax << " Y: " << ymax << std::endl;


		for(int y = ymin; y <= ymax; y++){
			for(int x = xmin; x <= xmax; x++){
				double alpha = ::implicit(p1_prime, p2_prime, x, y) / :: implicit(p1_prime, p2_prime, p0_prime->x, p0_prime->y);
				double beta =  ::implicit(p2_prime, p0_prime, x, y) / :: implicit(p2_prime, p0_prime, p1_prime->x, p1_prime->y);
				double gamma =  ::implicit(p0_prime, p1_prime, x, y) / :: implicit(p0_prime, p1_prime, p2_prime->x, p2_prime->y);
				
				if(alpha > 0 && beta > 0 && gamma > 0){
				double z = alpha * p0_prime->z + beta * p1_prime->z + gamma * p2_prime->z;
					if( z > z_buffer[x][y]){
						for(int j = 0; j < lights.size(); j++){
							Vector3D* l_dir = lights.at(j)->dir;
							Vector3D* l_col = lights.at(j)->color;
							
							l_dir->normalize();		
								
							Vector3D h  = Vector3D(0, 0, 1) + *l_dir;
							h = h * (1 / h.length());
							float L[3] = {0};							
							double k_a = 0.9;
							double l_a = 0.3;
							double k_d = 0.9;
							double k_s = 1.0;	
							double intensity = 1.0;
							
							Vector3D normal = tri->getNormalToSurface(l_dir);
							L[0] += k_a * intensity + k_d * l_col->getx() * max(0.0, normal.dot(*l_dir)) + k_s* l_col->getx() * pow(max(0.0, normal.dot(h)), 1000);
							L[1] += k_a * intensity + k_d * l_col->gety() * max(0.0, normal.dot(*l_dir)) + k_s* l_col->gety() * pow(max(0.0, normal.dot(h)), 1000);
							L[2] += k_a * intensity + k_d * l_col->getz() * max(0.0, normal.dot(*l_dir)) + k_s* l_col->getz() * pow(max(0.0, normal.dot(h)), 1000);
							
							
							for(int i =0; i<3; i++){
								if ( L[i] > 1){
									L[i] = 1;
								}
							}
										
							z_buffer[x][y] = z;
							//Vector3D* c = new Vector3D(((tri->getColor()*alpha) + (tri->getColor() * beta) + (tri->getColor() * gamma)));
							this->setPixel(x,y, tri->getColor() * Vector3D( L[0],L[1] ,L[2]));
						}					
					}
				}
			}
		}
	}
	
}