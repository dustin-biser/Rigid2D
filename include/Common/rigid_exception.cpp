#include "rigid_exception.h"
using std::string;
using std::stringstream;

namespace Rigid2D{
  Exception::Exception ( long line, const char * function, const char * file,
          const char * description) throw(){
		line_ = line;
		function_ = string(function);
		file_ = string(file);
		description_ = string(description);
	}

	const char * Exception::what() const throw(){
		//Build up result by appending line_, function_, file_, and
		//description_ into a c-string and return it.
		string result;
		stringstream ss;

		ss << line_;

		result =  file_ + ":" + ss.str() + " Exception occured in function '" + function_ + "'";

		if (description_ != "")
			result += " : " + description_;

		return result.c_str();
	}

	const char * InternalErrorException::what() const throw(){
		//Build up result by appending line_, function_, file_, and
		//description_ into a c-string and return it.
		string result;
		stringstream ss;

		ss << line_;

		result =  file_ + ":" + ss.str() + " InternalErrorException occured in function '" + function_ + "'";

		if (description_ != "")
			result += " : " + description_;

		return result.c_str();
	}

	const char * InvalidParameterException::what() const throw(){
		//Build up result by appending line_, function_, file_, and
		//description_ into a c-string and return it.
		string result;
		stringstream ss;

		ss << line_;

		result =  file_ + ":" + ss.str() + " InvalidParameterException occured in function '" + function_ + "'";

		if (description_ != "")
			result += " : " + description_;

		return result.c_str();
	}
}
