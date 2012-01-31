#ifndef RIGID_VECTOR2_H
#define RIGID_VECTOR2_H
#include "RigidSettings.h"
#include <cassert>
#include <cmath>
#include "feq.h"

namespace Rigid2D {

  class Vector2 {
    public:
      Real x, y;

    public:
      Vector2() {}

      Vector2(const Real X, const Real Y) {
        x = X;
        y = Y;
      }

      Vector2(const Real arr[2]) {
        x = arr[0];
        y = arr[1];
      }

      Vector2(const Vector2 & vector) {
        x = vector.x;
        y = vector.y;
      }

      void operator = (const Vector2 &vector) {
        x = vector.x;
        y = vector.y;
      }

      Vector2 operator + (const Vector2 & r) const {
        return Vector2(x + r.x, y + r.y);
      }

      Vector2 operator - (const Vector2 & r) const {
        return Vector2(x - r.x, y - r.y);
      }

      void operator += (const Vector2 & vector) {
        x += vector.x;
        y += vector.y;
      }

      void operator -= (const Vector2 & vector) {
        x -= vector.x;
        y -= vector.y;
      }

      void operator *= (Real scalar) {
        x *= scalar;
        y *= scalar;
      }

      Vector2 operator * (const Real scalar) const {
        return Vector2(x * scalar, y * scalar);
      }

      friend Vector2 operator * (const Real scalar, const Vector2 & vec) {
        return vec * scalar;
      }

      Vector2 operator / (const Real scalar) const {
        assert(feq(scalar, 0.0) == false);
        return Vector2(x / scalar, y / scalar);
      }

      void operator /= (const Real scalar) {
        assert(feq(scalar, 0.0) == false);
        x /= scalar;
        y /= scalar;
      }

      bool operator == (const Vector2 & vec) const {
        return (feq(x, vec.x) && feq(y, vec.y));
      }

      // getter
      Real operator [] (const unsigned int i) const { 
        assert( i < 2 );
        return *(&x+i);
      }

      // setter
      Real& operator [] (const unsigned int i) {
        assert( i < 2 );
        return *(&x+i);
      }

      Real getLengthSquared() const {
        return x * x + y * y;
      }

      Real getLength() const {
        return sqrt(x * x + y * y);
      }

      Real dot(const Vector2 & vec) const {
        return x * vec.x + y * vec.y;
      }

      void normalize() {
        Real length = getLength();
        assert(feq(length, 0.0) == false);
        x /= length;
        y /= length;
      }
  };
}
#endif
