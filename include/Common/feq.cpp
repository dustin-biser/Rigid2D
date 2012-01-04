#include <cassert>
#include <cstdlib>

namespace Rigid2D {
  // Compare two floats for equality using an almost equals two's complement approach.
  // First each float is covereted to an integer, then the number of integers between both
  // input values is computed. If this distance is less than maxUlp - 1 then they are
  // considered equal and feq returns true, otherwise feq returns false.  By default,
  // maxUlp (maximum units in the last place) is set to 5 meaning that floats A and B
  // are considered equal if one is within a range of the next 4 floats from the other.
  //
  // Credit goes to Bruce Dawson of Cygnus-Software.
	bool feq(float A, float B, int maxUlp = 5)
	{
			// Make sure maxUlp is non-negative and small enough that the
			// default NAN won't compare as equal to anything.
			assert(maxUlp > 0 && maxUlp < 4 * 1024 * 1024);
			int aInt = *(int*)&A;
			// Make aInt lexicographically ordered as a twos-complement int
			if (aInt < 0)
					aInt = 0x80000000 - aInt;
			// Make bInt lexicographically ordered as a twos-complement int
			int bInt = *(int*)&B;
			if (bInt < 0)
					bInt = 0x80000000 - bInt;
			int intDiff = abs(aInt - bInt);
			if (intDiff <= maxUlp)
					return true;
			return false;
	}
}
