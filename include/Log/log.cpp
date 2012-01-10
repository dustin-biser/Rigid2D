/* Rigid2D */

#include "Rigid2D"

namespace Rigid2D {
  
  Log::Log(string filename, unsigned int maxlines = 0) {
    filename_ = filename;
    maxlines_ = maxlines;
    file_.open(filename);
    if (file_.good() == false) {
      fprintf(stderr, "Log file %s was unable to open for writting\n", filename_);
      // throw some exception here
    }
  }

  Log::~Log() {
    file_.close();
  }

  void Log::write(string text) {
    // will switch to boost.format once i learn what it is >.>
    file_ << text;
  }
}

