#ifndef FEQ_H
#define FEQ_H

namespace Rigid2D {
  // Compare two floats for equality using an almost equals two's complement approach.
  // First each float is covereted to an integer, then the number of integers between both
  // input values is computed. If this distance is less than maxUlp - 1 then they are
  // considered equal and feq returns true, otherwise feq returns false.  By default,
  // maxUlp (maximum units in the last place) is set to 5 meaning that floats A and B
  // are considered equal if one is within a range of the next 4 floats from the other.
  //
  // Credit goes to Bruce Dawson of Cygnus-Software.
  bool feq(float A, float B, int maxUlp = 5);
}

#endif
