#include "Matrix4.h"
Matrix4::Matrix4(){
    this->m[0] = 0;
    this->m[1] = 0;
    this->m[2] = 0;
    this->m[3] = 0;
    this->m[4] = 0;
    this->m[5] = 0;
    this->m[6] = 0;
    this->m[7] = 0;
    this->m[8] = 0;
    this->m[9] = 0;
    this->m[10] = 0;
    this->m[11] = 0;
    this->m[12] = 0;
    this->m[13] = 0;
    this->m[14] = 0;
    this->m[15] = 0; 
}
Matrix4::Matrix4(double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31, double m32, double m33, double m34, double m41, double m42, double m43, double m44){
    this->m[0] = m11;
    this->m[1] = m12;
    this->m[2] = m13;
    this->m[3] = m14;
    this->m[4] = m21;
    this->m[5] = m22;
    this->m[6] = m23;
    this->m[7] = m24;
    this->m[8] = m31;
    this->m[9] = m32;
    this->m[10] = m33;
    this->m[11] = m34;
    this->m[12] = m41;
    this->m[13] = m42;
    this->m[14] = m43;
    this->m[15] = m44;  
} 
   
void Matrix4::set( double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31, double m32, double m33, double m34, double m41, double m42, double m43, double m44 ){
    this->m[0] = m11;
    this->m[1] = m12;
    this->m[2] = m13;
    this->m[3] = m14;
    this->m[4] = m21;
    this->m[5] = m22;
    this->m[6] = m23;
    this->m[7] = m24;
    this->m[8] = m31;
    this->m[9] = m32;
    this->m[10] = m33;
    this->m[11] = m34;
    this->m[12] = m41;
    this->m[13] = m42;
    this->m[14] = m43;
    this->m[15] = m44;  
}


void Matrix4::makeTranslate( Vector3D* v ){  // sets the matrix to the translation matrix
    this->m[0] = 1;
    this->m[1] = 0;
    this->m[2] = 0;
    this->m[3] = v->getx();
    this->m[4] = 1;
    this->m[5] = 0;
    this->m[6] = 0;
    this->m[7] = v->gety();
    this->m[8] = 1;
    this->m[9] = 0;
    this->m[10] = 0;
    this->m[11] = v->getz();
    this->m[12] = 1;
    this->m[13] = 0;
    this->m[14] = 0;
    this->m[15] = 1; 
}
void Matrix4::makeScale( Vector3D* v ){ // creates the scale matrix
    this->m[0] = v->getx();
    this->m[1] = 0;
    this->m[2] = 0;
    this->m[3] = 0;
    this->m[4] = 0;
    this->m[5] = v->gety();
    this->m[6] = 0;
    this->m[7] = 0;
    this->m[8] = 0;
    this->m[9] = 0;
    this->m[10] = v->getz();
    this->m[11] = 0;
    this->m[12] = 0;
    this->m[13] = 0;
    this->m[14] = 0;
    this->m[15] = 1; 
}
void Matrix4::makeOrtho(double l, double r, double b, double t, double n, double f){ // creates the orthographic viewing matrix
    m[0]  = 2 / (r - l);
    m[3] = -(r + l) / (r - l);
    m[5]  = 2 / (t - b);
    m[7] = -(t + b) / (t - b);
    m[10] = 2 / (n-f);
    m[11] = -(n + f) / (n - f);
    m[15] = 1;
}
void Matrix4::makePerspective(double l, double r, double b, double t, double n, double f){ //creates the perspective viewing matrix
    m[0] = (2*n) / (r - l);
    m[2] =  (l + r) / (l-r);
    m[5] = (2 * n) / (t-b);
    m[6] = (b+t)/(b-t);
    m[10] = (f+n) / (n-f);
    m[11] = ( 2 * f * n) / (f - n);
    m[14] = 1;
}
double Matrix4::get(int i, int j){
    if(i < 0 || i >= 4 || j < 0 || j >= 4){
        std::cout << "Index out of bounds" << std::endl;
        return 0.0;
    }
    else {
        int index = 4 * i;
        index += j;
        return m[index];
    }
}

Vector4D* Matrix4::operator*(Vector4D* v){
    Vector4D* vnew = new Vector4D();
    for(int i=0; i<4; i++){
        double ind = 0;
        ind += v->x * this->get(i, 0);
        ind += v->y * this->get(i, 1);
        ind += v->z * this->get(i, 2);
        ind += v->a * this->get(i, 3);
        if(i == 0){
            vnew->x = ind;
            // std::cout << "num : " << i << " "<< ind << std::endl;
        }
        else if(i == 1){
            vnew->y = ind;
            // std::cout << "num : "<< i << " " << ind << std::endl;
        }
        else if(i == 2){
            vnew->z = ind;
            // std::cout << "num : "<< i << " " << ind << std::endl;
        }
        else if(i == 3){
            vnew->a = ind;
            // std::cout << "num : "<< i << " " << ind << std::endl;
        }
    }
    return vnew;
}

Matrix4* Matrix4::operator*(Matrix4* om){
    Matrix4* newm = new Matrix4();
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k =0; k<4; k++){
                newm->m[(4*i) + j] += this->m[(4*i) + k] * om->m[(4*k) + j];
            }
        }
    }
    return (newm);
}

void Matrix4::print(){
    for(int i =0; i<16; i++){
        if(i%4 == 0){
            std::cout << std::endl;
        }
        std::cout << m[i] << " ";
    }
    std::cout << std::endl;
}
