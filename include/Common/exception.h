//#include "num_digits.h"
//#include <new>

namespace Rigid2D {
  class Exception {
    // True only if memory for description_ is allocated via new.
    //bool trigger_description_deletion;

    protected:
      const long line_;
      const char * function_;
      const char * file_;
      const char * description_;
    public:
      Exception ( long line, const char * const function, const char * const file,
          const char * description = "" ) : line_(line),
                                            function_(function),
                                            file_(file),
                                            description_(description) {
        //trigger_description_deletion = false;

        //if (description == ""){
          //// fill out description using supplied parameters
          //int length = strlen("Exception ocurred in file:  ,  function:  , line:  .")
          //length += numberOfDigits(line) + strlen(function) + strlen(file);
          //try{
            //description_ = new char [length + 1];
          //}
          //catch (bad_alloc error){

          //}
        //}
      }

      ~Exception(){
        if (trigger_description_deletion)
          delete [] description_;
      }

      // Returns the line number where the error occured.
      long getLine ( ) { return line_; }

      // Returns a string representing the function name where error occured.
      const char * getFunction () { return function_; }

      // Returns a string representing the file where error occured.
      const char * getFile () { return file_; }

      // Returns a string representing a description of error.
      const char * getDescription () { return description_; }
  };

  class UnimplementedException : public Exception {
    public:
      UnimplementedException (long line, const char * const function, const char * const file, const char * description = "") :
          Exception (line, function, file, description) {}
  };
}
