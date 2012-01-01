#ifndef FEQ_H
#define FEQ_H
#include <cassert>
#include <cstdlib>

namespace Rigid2D {
  // Compare two floats for equality using an almost equals two's complement approach.
  // Each float is covereted to an integer.  Then the number of integers between both
  // input values is computed. If this distance is less than maxUlps - 1 then they are
  // considered equal and feq returns true, otherwise feq returns false.  By default,
  // maxUlps is set to 5 meaning that floats A and B are considered equal if one is
  // within a range of the next 4 floats from the other.
  // Credit goes to Bruce Dawson of Cygnus-Software.
  bool feq(float A, float B, int maxUlps = 5)
  {
      // Make sure maxUlps is non-negative and small enough that the
      // default NAN won't compare as equal to anything.
      assert(maxUlps > 0 && maxUlps < 4 * 1024 * 1024);
      int aInt = *(int*)&A;
      // Make aInt lexicographically ordered as a twos-complement int
      if (aInt < 0)
          aInt = 0x80000000 - aInt;
      // Make bInt lexicographically ordered as a twos-complement int
      int bInt = *(int*)&B;
      if (bInt < 0)
          bInt = 0x80000000 - bInt;
      int intDiff = abs(aInt - bInt);
      if (intDiff <= maxUlps)
          return true;
      return false;
  }
}

#endif
