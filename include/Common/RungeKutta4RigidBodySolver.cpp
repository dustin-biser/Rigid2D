#include "RungeKutta4RigidBodySolver.h"

using namespace Rigid2D;

RungeKutta4RigidBodySolver::RungeKutta4RigidBodySolver(unsigned int dimension,
          RigidBodySystem * rigidBodySystem, Real stepSize = 0.01)
    : OdeSolver(dimension, step, NULL),                   // Set pointer to DerivFunction to NULL
      rigidBodySystem_(rigidBodySystem) {

}

void RungeKutta4RigidBodySolver::processNextStep (Real tIn, Real* xIn, Real& tOut, Real* xOut){
  assert(xIn != 0);
  assert(xOut != 0);
  assert(tIn == tIn);  // check for NaN

  unsigned int i;
  // Step 1
  //kn1_ = f_(tIn, xIn)
  rigidBodySystem_->computeStateDeriv(tIn, xIn, kn1_);

  // Step 2
  // kn2_ = f_(tIn + oneHalfStep_, xIn + oneHalfStep*kn1_)
  for(i = 0; i < dimension_; ++i){
    tmp_[i] = xIn[i] + oneHalfStep_*kn1_[i];
  }
  rigidBodySystem_->computeStateDeriv(tIn + oneHalfStep_, tmp_, kn2_);

  // Step 3
  // kn3_ = f_(t + oneHalfStep_, x + oneHalfStep*kn2_)
  for(i = 0; i < dimension_; ++i){
    tmp_[i] = xIn[i] + oneHalfStep_*kn2_[i];
  }
  rigidBodySystem_->computeStateDeriv(tIn + oneHalfStep_, tmp_, kn3_);

  // Step 4
  // kn4_ = f_(t + stepSize_, xIn + stepSize_*kn3_)
  for(i = 0; i < dimension_; ++i){
    tmp_[i] = xIn[i] + stepSize_*kn3_[i];
  }
  rigidBodySystem_->computeStateDeriv(tIn + stepSize_, tmp_, kn4_);

  //xOut = xIn + (stepSize/6)*(kn1_ + 2*(kn2_ + kn3_) + kn4_)
  for(i = 0; i < dimension_; ++i){
    xOut[i] = xIn[i] + oneSixthStep_*(kn1_[i] + 2*(kn2_[i] + kn3_[i]) + kn4_[i]);
  }

  tOut = tIn + stepSize_;
}

void RungeKutta4RigidBodySolver::processNextStep (Real& t, Real* x){
  processNextStep(t, x, t, x);
}
