#ifndef RIGID_EXCEPTION_H
#define RIGID_EXCEPTION_H
#include <exception>
#include <sstream>
#include <string>
using std::string;

namespace Rigid2D {
  class Exception : public std::exception {
    protected:
      long line_;
      string function_;
      string file_;
      string description_;
      string exceptionType_;
    public:
      Exception ( long line, const char * function, const char * file,
          const char * description = "") throw();

      virtual ~Exception () throw() { }

      // Returns the line number where the error occured.
      long getLine ( ) const throw() { return line_; }

      // Returns a string representing the function name where error occured.
      const string getFunction () const throw() { return function_; }

      // Returns a string representing the file where error occured.
      const string getFile () const throw() { return file_; }

      // Returns a string representing a description of error.
      const string getDescription () const throw () { return description_; }

      // Returns a c-string representing the full description of exception
      // including line number, function, file, and, if available, a further
      // specified description.
      virtual const char * what() const throw();
  };

  class InternalErrorException : public Exception {
    public:
      InternalErrorException ( long line, const char * function, const char * file,
          const char * description = "") throw() : Exception (line, function, file, description) { exceptionType_ = "InternalErrorException"; }
  };

  class InvalidParameterException : public Exception {
    public:
      InvalidParameterException ( long line, const char * function, const char * file,
          const char * description = "") throw() : Exception (line, function, file, description) { exceptionType_ = "InvalidParameterException"; }
  };

  class FileNotFoundException : public Exception {
    public:
      FileNotFoundException ( long line, const char * function, const char * file,
          const char * description = "") throw() : Exception (line, function, file, description) { exceptionType_ = "FileNotFoundException"; }
  };

  class IOException : public Exception {
    public:
      IOException ( long line, const char * function, const char * file,
          const char * description = "") throw() : Exception (line, function, file, description) { exceptionType_ = "IOException"; }
  };
}
#endif
