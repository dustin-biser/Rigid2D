#ifndef RIGID_VECTOR3_H
#define RIGID_VECTOR3_H
#include "RigidSettings.h"
#include <cassert>
#include <cmath>
#include "feq.h"

namespace Rigid2D {

  /* Standard vector for 3D Reals */
  class Vector3 {
    public:
      Real x, y, z;

    public:
      Vector3() {}

      Vector3(const Real X, const Real Y, const Real Z) {
        x = X;
        y = Y;
        z = Z;
      }

      Vector3(const Real arr[3]) {
        x = arr[0];
        y = arr[1];
        z = arr[2];
      }

      Vector3(const Vector3 & vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
      }

      void operator=(const Vector3 &vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
      }

      Vector3 operator + (const Vector3 & r) const {
        return Vector3(x + r.x, y + r.y, z + r.z);
      }

      Vector3 operator - (const Vector3 & r) const {
        return Vector3(x - r.x, y - r.y, z - r.z);
      }

      void operator += (const Vector3 & vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
      }

      void operator -= (const Vector3 & vector) {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
      }

      void operator *= (Real scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
      }

      Vector3 operator * (const Real scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
      }

      friend Vector3 operator * (const Real scalar, const Vector3 & vec) {
        return vec * scalar;
      }

      Vector3 operator / (const Real scalar) const {
        assert(feq(scalar, 0.0) == false);
        return Vector3(x / scalar, y / scalar, z / scalar);
      }

      void operator /= (const Real scalar) {
        assert(feq(scalar, 0.0) == false);
        x /= scalar;
        y /= scalar;
        z /= scalar;
      }

      bool operator == (const Vector3 & vec) const {
        return (feq(x, vec.x) && feq(y, vec.y) && feq(z, vec.z));
      }

      // getter
      Real operator [] (const unsigned int i) const { 
        assert( i < 3 );
        return *(&x+i);
      }

      // setter
      Real& operator [] (const unsigned int i) {
        assert( i < 3 );
        return *(&x+i);
      }

      Real getLengthSquared() const {
        return x * x + y * y + z * z;
      }

      Real getLength() const {
        return sqrt(x * x + y * y + z * z);
      }

      Real dot(const Vector3 & vec) const {
        return x * vec.x + y * vec.y + z * vec.z;
      }

      Vector3 cross(const Vector3 & rhsVector) const {
        return Vector3(
            y * rhsVector.z - z * rhsVector.y,
            z * rhsVector.x - x * rhsVector.z,
            x * rhsVector.y - y * rhsVector.x
            );
      }

      void normalize() {
        Real length = getLength();
        assert(feq(length, 0.0) == false);
        x /= length;
        y /= length;
        z /= length;
      }
  };
}
#endif
