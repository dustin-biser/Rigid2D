/*
 *	Author: Michail Denchev
*/

#ifndef VEC3F_HPP
#define VEC3F_HPP

#include <assert.h>
#include <stdlib.h>

/* Standard vector for 3D floats */

class Vec3f {
  public:
    float x, y, z;

  public:
    Vec3f() {}
    
    Vec3f(const float X, const float Y, const float Z) { 
      x = X; 
      y = Y; 
      z = Z; 
    }
    
    Vec3f(const float arr[3]) { 
      x = arr[0]; 
      y = arr[1]; 
      z = arr[2]; 
    }
    
    Vec3f operator=(const Vec3f &vector) { 
      x = vector.x; 
      y = vector.y; 
      z = vector.z;
    }
    
    Vec3f operator+=(const Vec3f &vector) { 
      x += vector.x; 
      y += vector.y; 
      z += vector.z; 
    }

    Vec3f operator*=(float scalar) { 
      x *= scalar; 
      y *= scalar; 
      z *= scalar; 
    }

    Vec3f operator/=(float scalar) { 
      x /= scalar; 
      y /= scalar; 
      z /= scalar; 
    }

    float operator[](const size_t i) const {
      assert(i < 3);
      return *(&x + i); 
    }

    void normalizeTo(float value) {
      //// add later
    }
  
    void maxLength(float maxLength) {
      ///// add later
    }

};


#endif
