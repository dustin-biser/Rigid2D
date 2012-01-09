#include "num_digits.h"

namespace Rigid2D{
  unsigned int numberOfDigits (long value){
      // Flip the sign of value if negative.
      if (value < 0)
        value *= -1;

      unsigned int result = 1;
      int quotient = floor (value / 10);

      while (quotient > 0){
        quotient = floor (quotient / 10);
        result++;
      }

      return result;
  }
}
