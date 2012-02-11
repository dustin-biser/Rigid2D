#include "RigidBodySystem.h"
#include "../Common/RungeKutta4RigidBodySolver.h"
#include "../Common/RigidException.h"
#include <new>

using namespace std;
namespace Rigid2D
{
  RigidBodySystem::RigidBodySystem( )
  {
    time_ = 0.0;

    try {
       //solver_ = new RungeKutta4RigidBodySolver(0,                 // dimension of system
       //    StartingStepSize,  // stepSize
       //    0,                 // null pointer to DerivFunc

       //    this); // pass self to optionalData
      // pointer so that OdeSolver
      // can access RigidBodySystem
      // state information
    }
    catch (std::bad_alloc error){
      throw InternalErrorException(__LINE__, __FUNCTION__, __FILE__,
        "Memory Allocation Failure");
    }

  }

  RigidBodySystem::~RigidBodySystem()
  {
    delete solver_;
  }

  void RigidBodySystem::updateRigidBodies()
  {
    // Build state array S_ and zero the forceAccumulator for each RigidBody

  }

  void RigidBodySystem::addRigidBody(RigidBody *rigidBody)
  {
    rigidBodies_.insert(rigidBody);
  }

  void RigidBodySystem::addRigidBodies(RigidBody **rigidBodyArray, unsigned int numBodies)
  {
    for (unsigned int i = 0; i < numBodies; ++i)
    {
      rigidBodies_.insert(rigidBodyArray[i]);
    }
  }

  void RigidBodySystem::removeRigidBody(RigidBody *rigidBody)
  {
    rigidBodies_.erase(rigidBody);
  }

  void RigidBodySystem::removeRigidBodies(RigidBody **rigidBodyArray, unsigned int numBodies)
  {
    for (unsigned int i = 0; i < numBodies; ++i)
    {
      rigidBodies_.erase(rigidBodyArray[i]);
    }
  }

  void RigidBodySystem::addForce(Force *force)
  {
    forces_.insert(force);
  }

  void RigidBodySystem::addForces(Force **forces, unsigned int numForces)
  {
    for (unsigned i = 0; i < numForces; ++i)
    {
      forces_.insert(forces[i]);
    }
  }

  void RigidBodySystem::removeForce(Force *force)
  {
    forces_.erase(force);
  }

  void RigidBodySystem::removeForces(Force **forces, unsigned int numForces)
  {
    for (unsigned int i = 0; i < numForces; ++i)
    {
      forces_.erase(forces[i]);
    }
  }

  void RigidBodySystem::buildSystemStateArray()
  {
    // TODO: Make more robust (don't use 4 as vec dimension)
    Real *S_temp = S_;

    unordered_set<RigidBody*>::iterator it;
    for(it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it)
    {
      (*it)->copyState(S_temp);
      S_temp += 4; // 4 is the number of elements copies each time
    }
  }
}
