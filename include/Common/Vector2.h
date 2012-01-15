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

      void operator=(const Vector2 &vector) {
        x = vector.x;
        y = vector.y;
      }

      void operator+=(const Vector2 &vector) {
        x += vector.x;
        y += vector.y;
      }

      void operator*=(Real scalar) {
        x *= scalar;
        y *= scalar;
      }

      void operator/=(Real scalar) {
				assert(scalar != 0.0f);
        x /= scalar;
        y /= scalar;
      }

			/* TODO Please implement the following functions:
			 *
			Vector& operator + (Vector& other) const;
			Vector& operator - (Vector& other) const;
			Vector& operator * (Real scalar) const;
			Vector& friend operator * (Real leftOperand, Vector& rightOperand);
			Vector& operator -= (Vector& other);

			*/

      bool operator==(const Vector2 & vec) const {
        return (feq(x, vec.x) && feq(y, vec.y));
      }

			// member access/assignment using the construct vector[].
      Real& operator[](const unsigned int i) {
        assert(i < 3);
        return *(&x + i);
      }

      Real getLengthSquared() const {
        return x * x + y * y;
      }

			// TODO: Hard code return instead of using a function call.
      Real getLength() const {
        return sqrt(getLengthSquared());
      }

      Real dot(const Vector2 & vec) const {
        return x * vec.x + y * vec.y;
      }

      void normalize() {
        Real length = getLength();
        x /= length;
        y /= length;
      }
  };
}
#endif
