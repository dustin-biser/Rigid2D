// matrix2x2.cpp
#include "Matrix2.h"

namespace Rigid2D {

  Matrix2::Matrix2(Matrix2& other){
    data_[0][0] = other.data_[0][0];
    data_[0][1] = other.data_[0][1];
    data_[1][0] = other.data_[1][0];
    data_[1][1] = other.data_[1][1];
  }

  Real & Matrix2::operator () (unsigned int row, unsigned int col){
		assert (row < 2);
		assert (col < 2);

    return data_[row][col];
  }

  Matrix2 Matrix2::operator + (const Matrix2 &other) const {
    Matrix2 result;

    result.data_[0][0] = data_[0][0] + other.data_[0][0];
    result.data_[0][1] = data_[0][1] + other.data_[0][1];
    result.data_[1][0] = data_[1][0] + other.data_[1][0];
    result.data_[1][1] = data_[1][1] + other.data_[1][1];

    return result;
  }

  Matrix2 Matrix2::operator - (const Matrix2 &other) const {
    Matrix2 result;

    result.data_[0][0] = data_[0][0] - other.data_[0][0];
    result.data_[0][1] = data_[0][1] - other.data_[0][1];
    result.data_[1][0] = data_[1][0] - other.data_[1][0];
    result.data_[1][1] = data_[1][1] - other.data_[1][1];

			return result;
		}

		Matrix2 Matrix2::operator = (const Matrix2 &other){
			data_[0][0] = other.data_[0][0];
			data_[0][1] = other.data_[0][1];
			data_[1][0] = other.data_[1][0];
			data_[1][1] = other.data_[1][1];

			return *this;
		}

		/* Returns true if calling object and other have the same memory address or if
		 * all corresponding matrix elements are the same.  Otherwise, == returns false.
		 */
		bool Matrix2::operator == (const Matrix2 &other) const {
			// Check if addresses are equal
			if (this == &other)
				return true;

			// Check if all matrix elements are equal.
			else if ((feq(data_[0][0], other.data_[0][0])) &&
							 (feq(data_[0][1], other.data_[0][1])) &&
							 (feq(data_[1][0], other.data_[1][0])) &&
							 (feq(data_[1][1], other.data_[1][1])))
				return true;
			else
				return false;
		}

		void Matrix2::setZeros(){
			data_[0][0] = 0.0f;
			data_[0][1] = 0.0f;
			data_[1][0] = 0.0f;
			data_[1][1] = 0.0f;
		}

		Matrix2 Matrix2::operator * (const Matrix2 &other) const {
			Matrix2 result;

			result(0,0) = (data_[0][0] * other.data_[0][0]) + (data_[0][1] * other.data_[1][0]);
			result(0,1) = (data_[0][0] * other.data_[0][1]) + (data_[0][1] * other.data_[1][1]);
			result(1,0) = (data_[1][0] * other.data_[0][0]) + (data_[1][1] * other.data_[1][0]);
			result(1,1) = (data_[1][0] * other.data_[0][1]) + (data_[1][1] * other.data_[1][1]);

			return result;
		}

		Matrix2 Matrix2::setIdentity(){
			data_[0][0] = data_[1][1] = 1.0f;
			data_[0][1] = data_[1][0] = 0.0f;

			return *this;
		}

    //=== Matrix-Scalar operators =============================================
		Matrix2 operator * (Real leftOperand, Matrix2& rightOperand){
			Matrix2 result;

			result.data_[0][0] = rightOperand.data_[0][0] * leftOperand;
			result.data_[0][1] = rightOperand.data_[0][1] * leftOperand;
			result.data_[1][0] = rightOperand.data_[1][0] * leftOperand;
			result.data_[1][1] = rightOperand.data_[1][1] * leftOperand;

			return result;
		}

		Matrix2 operator * (Matrix2& leftOperand, Real rightOperand){
			Matrix2 result;

			result.data_[0][0] = leftOperand.data_[0][0] * rightOperand;
			result.data_[0][1] = leftOperand.data_[0][1] * rightOperand;
			result.data_[1][0] = leftOperand.data_[1][0] * rightOperand;
			result.data_[1][1] = leftOperand.data_[1][1] * rightOperand;

			return result;
		}
    //=========================================================================

		Real * Matrix2::operator [] (unsigned int row){
			assert ( row < 2 );
			return data_[row];
		}

  bool Matrix2::hasInverse(int maxUlp) const{
    if (feq(this->det(), 0.0f, maxUlp))
      return false;
    else
      return true;
  }

  bool Matrix2::inv(Matrix2& invMatrix, int maxUlp) const{
    Real det = this->det();

    // Check if determinant is within maxUlp-1 floating-point values from zero.
    if (feq(det, 0.0f, maxUlp)){
      invMatrix.setZeros();
      return false;
    }

    invMatrix.data_[0][0] =  data_[1][1] / det;
    invMatrix.data_[0][1] = -data_[0][1] / det;
    invMatrix.data_[1][0] = -data_[1][0] / det;
    invMatrix.data_[1][1] =  data_[0][0] / det;

    return true;
  }
  
  Matrix2 Matrix2::transpose() const {
    Matrix2 result;

    result.data_[0][0] = data_[0][0];
    result.data_[0][1] = data_[1][0];
    result.data_[1][0] = data_[0][1];
    result.data_[1][1] = data_[1][1];

    return result;
  }

} // end namespace Rigid2D.
