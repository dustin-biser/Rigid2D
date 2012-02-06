#include "RigidBodySystem.h"
#include "Common/RungeKutta4RigidBodySolver.h"
#include "Common/RigidException.h"
#include <new>

using namespace Rigid2D;

RigidBodySystem::RigidBodySystem(Real step){
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
