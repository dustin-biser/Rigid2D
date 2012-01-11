#include "RigidException.h"
using std::string;
using std::stringstream;

namespace Rigid2D{
  Exception::Exception ( long line, const char * function, const char * file,
          const char * description) throw(){
		line_ = line;
		function_ = string(function);
		file_ = string(file);
		description_ = string(description);
    exceptionType_ = "Exception";
	}

	const char * Exception::what() const throw(){
		//Build up result by appending line_, function_, file_, and
		//description_ into a c-string and return it.
		string result;
		stringstream ss;

		ss << line_;

		result =  file_ + ":" + ss.str() + " " +  exceptionType_ + " occured in function '" + function_ + "'";

		if (description_ != "")
			result += " : " + description_;

		return result.c_str();
	}
}
