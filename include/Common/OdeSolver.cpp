#include "OdeSolver.h"

using namespace Rigid2D;

inline OdeSolver::OdeSolver (unsigned int dimension, Real* x, OdeSolver::Function function,
            Real stepSize, void* optionalData) {
	dimension_ = dimension;
	xValue_ = x;
	f_ = function;
	stepSize_ = stepSize;
	optionalData_ = optionalData;
}

inline Real OdeSolver::GetStepSize() const {
  return stepSize_;
}

inline void OdeSolver::SetStepSize(const Real stepSize){
  stepSize_ = stepSize;	
}

