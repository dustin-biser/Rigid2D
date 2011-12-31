#ifndef R2_ERROR_H
#define R2_ERROR_H

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

#endif
