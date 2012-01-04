#ifndef FLOAT_CLASS_H
#define FLOAT_CLASS_H

namespace Rigid2d {
	class Float{
		float value_;

		public:
		Float(){};
		Float(const float value) : value_(value) { };

		// Allow converstion to other types.
		operator float() {return value_;}
		operator double() {return (double)value_;}
		operator int() {return (int)value_;}

		// overload prefix operator to increment calling object to the next largest float.
		inline Float& operator ++ () {
			// Increment calling object by one float value.
			++(*(int *)&value_);
			return *this;
		}

		// overload prefix operator to decrement calling object to the next smallest float.
		inline Float& operator -- () {
			// Decrement calling object by one float value.
			--(*(int *)&value_);
			return *this;
		}

		// overload postfix operator to increment calling object to the next largest float.
		inline Float operator ++ (int) {
			Float temp(value_);

			// Increment calling object by one float value.
			++(*(int *)&value_);

			// Return previous state of calling object.
			return temp;	
		}

		// overload postfix operator to decrement calling object to the next largest float.
		inline Float operator -- (int) {
			Float temp(value_);

			// Decrement calling object by one float value.
			--(*(int *)&value_);

			// Return previous state of calling object.
			return temp;	
	 	}

		inline float value(){ return value_; }
	};
}

#endif
