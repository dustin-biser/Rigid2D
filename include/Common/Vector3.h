#ifndef RIGID_VECTOR_H
#define RIGID_VECTOR_H
#include <cassert>
#include <cmath>

namespace Rigid2D {

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

      void operator=(const Vector3 &vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
      }

      void operator+=(const Vector3 &vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
      }

      void operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
      }

      void operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
      }

      float operator[](const unsigned int i) const {
        assert(i < 3);
        return *(&x + i);
      }


      float getLengthSquared() const {
        return x * x + y * y + z * z;
      }

      float getLength() const {
        return sqrt(getLengthSquared());
      }

      float dotProduct(const Vector3 & vec) const {
        return x * vec.x + y * vec.y + z * vec.z;
      }

      Vector3 crossProduct(const Vector3 & rhsVector) const {
        return Vector3(
            y * rhsVector.z - z * rhsVector.y,
            z * rhsVector.x - x * rhsVector.z,
            x * rhsVector.y - y * rhsVector.x
            );
      }

      void normalize() {
        float length = getLength();
        x /= length;
        y /= length;
        z /= length;
      }


  };

}
#endif
