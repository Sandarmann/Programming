##
#Aleksandar Straumann
#Homework 1
##

#include <iostream>
#include <fstream>
#include "FrameBuffer.h"
using namespace std;

FrameBuffer::FrameBuffer(int height, int width){
	this->height = height;
	this->width = width * 3;
	this->ppm = new int[this->width*this->height];
	for (int i=0; i<this->width * this->height; i++){
		this->ppm[i] = 0;
	}
}

FrameBuffer::FrameBuffer(int height, int width, int R, int G, int B){
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

int FrameBuffer::getWidth(){
	return this->width/3;
}	

int FrameBuffer::getHeight(){
	return this->height;
}

void FrameBuffer::setPixel(int height, int width, int R, int G, int B){
	try{
		setPixelLogic(height, width, R, G, B);
	}
	catch(const out_of_range &oor){
		cout << "Not in bounds of image, will not change any data" << endl;
	}
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

void FrameBuffer::reset(){
	for(int i=0; i<this->width * this->height; i++){
		this->ppm[i] = 0;
	}
}


void FrameBuffer::writePPM(const string& filename){
	int* writeBuffer = bufferData();
	ofstream myfile;
	try{
		myfile.open(filename);
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
