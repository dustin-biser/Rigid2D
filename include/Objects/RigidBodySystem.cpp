#include "RigidBodySystem.h"
#include "Common/RungeKutta4RigidBodySolver.h"
#include "Common/RigidException.h"
#include <new>

using namespace Rigid2D;

RigidBodySystem::RigidBodySystem(Real step){
  time_ = 0.0;

  try {
    solver_ = new RungeKutta4RigidBodySolver(0,     // dimension of system
                                             0.01,  // stepSize
                                             0,     // null pointer to DerivFunc

                                             this); // pass self to optionalData
                                                    // pointer so that OdeSolver
                                                    // can access RigidBodySystem
                                                    // state information
  }
  catch (std::bad_alloc error){
    throw InternalErrorException(__LINE__, __FUNCTION__, __FILE__,
      "Memory Allocation Failure");
  }

}

RigidBodySystem::~RigidBodySystem(){
  delete solver_;
}

void RigidBodySystem::updateRigidBodies(){
  // Build state array S_ and zero the forceAccumulator for each RigidBody
  unsigned int i;
  for(i = 0; i < num_bodies_; i++){

  }

}
