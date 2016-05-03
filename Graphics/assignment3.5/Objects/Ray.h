#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"
class Ray{
	public:
		Ray(){
			origin = Vector3D();
			direction = Vector3D();
		}
		
		Ray(Vector3D& origin, Vector3D& direction){
			this->origin = origin;
			this->direction = direction;
		}

		Vector3D getOrigin() const{ 
			return origin;
		}

		void setOrigin(Vector3D v){
			origin = v;
		}

		Vector3D getDir() const{
			return direction;
		}

		void setDir(Vector3D v){
			direction = v;
		}
	private:
		Vector3D origin;
		Vector3D direction;
};

#endif