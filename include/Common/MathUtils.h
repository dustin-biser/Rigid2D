#ifndef RIGID2D_MATH_UTILS_H
#define RIGID2D_MATH_UTILS_H

#include "RigidSettings.h"
#include "Vector2.h"

// Class for common math functions.
// Functions:
// *or2d - finds the orientation of a triangle given three points
// *det3 - determinant of a 3x3 matrix

namespace Rigid2D
{
  int or2d(Vector2 & pt1, Vector2 & pt2, Vector2 & pt3);
  Real det3(Real a0, Real a1, Real a2, Real b0, Real b1, Real b2, Real c0, Real c1, Real c2);
}

#endif
