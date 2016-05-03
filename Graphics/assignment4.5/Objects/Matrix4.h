#ifndef MATRIX_H
#define MATRIX_H
#include "Vector3D.h"
#include "Vector4D.h"
class Matrix4{
    public:
        Matrix4();
        Matrix4(double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31, double m32, double m33, double m34, double m41, double m42, double m43, double m44);
        void set( double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31, double m32, double m33, double m34, double m41, double m42, double m43, double m44 ); // sets the 16 values in the matrix 
        void makeTranslate( Vector3D* v );  // sets the matrix to the translation matrix
        void makeScale( Vector3D* v ); // creates the scale matrix
        void makeOrtho(double l, double r, double b, double t, double n, double f); // creates the orthographic viewing matrix
        void makePerspective(double l, double r, double b, double t, double n, double f); //creates the perspective viewing matrix
        double get(int i, int j);
        Vector4D* operator*(Vector4D* v);
        Matrix4* operator*(Matrix4* om);
        void print();
        double m[16];
};

#endif