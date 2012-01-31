#include "OdeRungeKutta4.h"

using namespace Rigid2D;

OdeRungeKutta4::OdeRungeKutta4(unsigned int dimension, Real step, OdeSolver::DerivFunction dxdt, void* optionalData)
    : OdeSolver(dimension, step, dxdt, optionalData) {

  oneHalfStep_ = 0.5*stepSize_;
  oneSixthStep_ = stepSize_/6.0;

  try{
    kn1_ = new Real[dimension_];
    kn2_ = new Real[dimension_];
    kn3_ = new Real[dimension_];
    kn4_ = new Real[dimension_];
    tmp_ = new Real[dimension_];
  }
  catch (std::bad_alloc error){
    throw InternalErrorException(__LINE__, __FUNCTION__, __FILE__,
      "Memory Allocation Failure");
  }
}

OdeRungeKutta4::~OdeRungeKutta4(){
  delete [] kn1_;
  delete [] kn2_;
  delete [] kn3_;
  delete [] kn4_;
  delete [] tmp_;
}


void OdeRungeKutta4::processNextStep (Real tIn, Real* xIn, Real& tOut, Real* xOut){
  assert(xIn != 0);
  assert(xOut != 0);
  assert(tIn == tIn);  // check for NaN

  unsigned int i;
  // Step 1
  //kn1_ = f_(tIn, xIn);
  f_(tIn, xIn, kn1_);

  // Step 2
  // kn2_ = f_(tIn + oneHalfStep_, xIn + oneHalfStep*kn1_);
  for(i = 0; i < dimension_; ++i){
    tmp_[i] = xIn[i] + oneHalfStep_*kn1_[i];
  }
  f_(tIn + oneHalfStep_, tmp_, kn2_);

  // Step 3
  //kn3_ = f_(t + oneHalfStep_, x + oneHalfStep*kn2_);
  for(i = 0; i < dimension_; ++i){
    tmp_[i] = xIn[i] + oneHalfStep_*kn2_[i];
  }
  f_(tIn + oneHalfStep_, tmp_, kn3_);

  // Step 4
  for(i = 0; i < dimension_; ++i){
    tmp_[i] = xIn[i] + stepSize_*kn3_[i];
  }
  f_(tIn + stepSize_, tmp_, kn4_);

  //xOut = xIn + (stepSize/6)*(kn1_ + 2*(kn2_ + kn3_) + kn4_);
  for(i = 0; i < dimension_; ++i){
    xOut[i] = xIn[i] + oneSixthStep_*(kn1_[i] + 2*(kn2_[i] + kn3_[i]) + kn4_[i]);
  }

  tOut = tIn + stepSize_;
}

void OdeRungeKutta4::processNextStep (Real& t, Real* x){
  processNextStep (t, x, t, x);
}

void OdeRungeKutta4::setDimension(unsigned int newDim){
  delete [] kn1_;
  delete [] kn2_;
  delete [] kn3_;
  delete [] kn4_;
  delete [] tmp_;

  try{
    kn1_ = new Real[newDim];
    kn2_ = new Real[newDim];
    kn3_ = new Real[newDim];
    kn4_ = new Real[newDim];
    tmp_ = new Real[newDim];
  }
  catch (std::bad_alloc error){
    throw InternalErrorException(__LINE__, __FUNCTION__, __FILE__,
      "Memory Allocation Failure");
  }

  dimension_ = newDim;
}
