#include "MathUtils.h"

namespace Rigid2D
{
  int or2d(Vector2 & pt1, Vector2 & pt2, Vector2 & pt3)
  {
    Real det = det3(1.0, 1.0, 1.0,
              pt1.x, pt2.x, pt3.x,
              pt1.y, pt2.y, pt3.y);
    if (feq(det,0))
      return 0;
    else if (det < 0)
      return -1;
    else
      return 1;
  }

  Real det3(Real a0, Real a1, Real a2, Real b0, Real b1, Real b2, Real c0, Real c1, Real c2)
  {
    return ((a0 * b1 * c2) + (a1 * b2 * c0) + (a2 * b0 * c1)
      - (a2 * b1 * c0) - (a1 * b0 * c2) - (a0 * b2 * c1));
  }

}
