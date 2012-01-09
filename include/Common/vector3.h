/*
 *	Author: Michail Denchev
 */

#ifndef VEC3F_HPP
#define VEC3F_HPP

#include <cassert>
#include <cstdlib>
#include <cmath>

/* Standard vector for 3D floats */

class Vector3 {
  public:
    float x, y, z;

  public:
    Vector3() {}

    Vector3(const float X, const float Y, const float Z) { 
      x = X; 
      y = Y; 
      z = Z; 
    }

    Vector3(const float arr[3]) { 
      x = arr[0]; 
      y = arr[1]; 
      z = arr[2]; 
    }

    Vector3 operator=(const Vector3 &vector) { 
      x = vector.x; 
      y = vector.y; 
      z = vector.z;
    }

    Vector3 operator+=(const Vector3 &vector) { 
      x += vector.x; 
      y += vector.y; 
      z += vector.z; 
    }

    Vector3 operator*=(float scalar) { 
      x *= scalar; 
      y *= scalar; 
      z *= scalar; 
    }

    Vector3 operator/=(float scalar) { 
      x /= scalar; 
      y /= scalar; 
      z /= scalar; 
    }

    float operator[](const size_t i) const {
      assert(i < 3);
      return *(&x + i); 
    }


    float lengthSquared() const {
      return x * x + y * y + z * z;
    }

    float getLength() const {
      return math.sqrt(getLength);
    {

    float dotProduct(const Vector3 & vec) const {
      return x * vec.x + y * vec.y + z * vex.z;
    }

    Vector3 crossProduct(const Vector3 & rhsVector) const {
      return Vector3(
        y * rhsVector.z - z * rhsVector.y,
        z * rhsVector.x - x * rhsVector.z,
        x * rhsVector.y - y * rhsVector.x,
      )
    }

    void normalize() {
      this /= this.dotProduct();
    }


};


#endif
