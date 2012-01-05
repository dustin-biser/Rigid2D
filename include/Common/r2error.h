#ifndef R2_ERROR_H
#define R2_ERROR_H
namespace Rigid2D {
  // List all known errorTypes here.
  enum errorType { MatrixIndexOutOfBoundsError,
                   VectorIndexOutOfBoundsError };


  class R2Error {
    errorType error_id;
    const char *description;
    public:
    R2Error(errorType id, const char *str = ""){
      description = str;
      error_id = id;
    }
    const char * describe(){ return description; }
    errorType type(){ return error_id; }
  };

  class DivideByZeroError {};
}

#endif
