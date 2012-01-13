/* Rigid2D */

#ifndef LOG_H
#define LOG_H

#include <cstdlib>
#include <iostream>
#include <string>

namespace Rigid2D {

  /* Log can be used to record and save data or messages. */
  class Log {
    protected:
      unsigned int maxlines_;
      string filename_;
      ofstream file_;

    public:
      Log(string filename, unsigned int maxlines = 0);
      ~Log();
      void write(string text);
  };

}
#endif
