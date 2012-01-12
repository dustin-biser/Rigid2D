/*
 *	Author: Michail Denchev
 */

#ifndef VEC3F_HPP
#define VEC3F_HPP

#include <cassert>
#include <cstdlib>
#include <cmath>

namespace Rigid2D {

  class Vector2 {
    public:
      float x, y;

    public:
      Vector2() {}

      Vector2(const float X, const float Y) { 
        x = X; 
        y = Y; 
      }

      Vector2(const float arr[2]) { 
        x = arr[0]; 
        y = arr[1]; 
      }

      void operator=(const Vector2 &vector) { 
        x = vector.x; 
        y = vector.y; 
      }

      void operator+=(const Vector2 &vector) { 
        x += vector.x; 
        y += vector.y; 
      }

      void operator*=(float scalar) { 
        x *= scalar; 
        y *= scalar; 
      }

      void operator/=(float scalar) { 
        x /= scalar; 
        y /= scalar; 
      }

      bool operator==(const Vector2 & vec) const {
        return (feq(x, vec.x) && feq(y, vec.y));
      }

      float operator[](const size_t i) const {
        assert(i < 3);
        return *(&x + i); 
      }


      float getLengthSquared() const {
        return x * x + y * y + z * z;
      }

      float getLength() const {
        return sqrt(getLengthSquared());
      }

      float dotProduct(const Vector2 & vec) const {
        return x * vec.x + y * vec.y + z * vec.z;
      }

      void normalize() {
        float length = getLength();
        x /= length;
        y /= length;
      }


  };

}
#
