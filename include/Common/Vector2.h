#ifndef RIGID_VECTOR2_H
#define RIGID_VECTOR2_H
#include "feq.h"
#include "RigidSettings.h"
#include <cassert>
#include <cmath>

namespace Rigid2D {

  class Vector2 {
    public:
      Real x, y;

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

      float operator[](const unsigned int i) const {
        assert(i < 3);
        return *(&x + i);
      }


      float getLengthSquared() const {
        return x * x + y * y;
      }

      float getLength() const {
        return sqrt(getLengthSquared());
      }

      float dotProduct(const Vector2 & vec) const {
        return x * vec.x + y * vec.y;
      }

      void normalize() {
        float length = getLength();
        x /= length;
        y /= length;
      }
  };
}
#endif
