#include "RigidBodySystem.h"
#include "Common/RungeKutta4RigidBodySolver.h"
#include "Common/RigidException.h"
#include <new>

using namespace std;

namespace Rigid2D {

  RigidBodySystem::RigidBodySystem( ) {
    time_ = 0.0;
    S_ = NULL;
    dimension_ = 0;   // Initially, the system has no RigidBodies, so set dimention to zero.

    try {
       solver_ = new RungeKutta4RigidBodySolver( dimension_,

                                                 this);  // Pointer to this RigidBodySystem
    }
    catch (std::bad_alloc error){
      throw InternalErrorException(__LINE__, __FUNCTION__, __FILE__,
        "Memory Allocation Failure");
    }

  }

  RigidBodySystem::~RigidBodySystem() {
    delete solver_;
  }

  void RigidBodySystem::update() {
    // If S_ is NULL, construct it from the state information of each RigidBody
    if (S_ == NULL)
      buildSystemStateArray();

    // Clear the forceAccumulator field for each RigidBody in the system.
    clearForceAccumulators();

    // Update the system clock t, and system state array S_
    solver_->processNextStep(time_, S_);

    // Disperse state information within S_ to all RigidBodies
    updateRigidBodies();
  }

  //TODO update dimension of OdeSolver and S_
  void RigidBodySystem::addRigidBody(RigidBody *rigidBody) {
    rigidBodies_.insert(rigidBody);
  }

  //TODO update dimension of OdeSolver and S_
  void RigidBodySystem::addRigidBodies(RigidBody **rigidBodyArray, unsigned int numBodies) {
    for (unsigned int i = 0; i < numBodies; ++i)
    {
      rigidBodies_.insert(rigidBodyArray[i]);
    }
  }

  //TODO update dimension of OdeSolver and S_
  void RigidBodySystem::removeRigidBody(RigidBody *rigidBody) {
    rigidBodies_.erase(rigidBody);
  }

  //TODO update dimension of OdeSolver and S_
  void RigidBodySystem::removeRigidBodies(RigidBody **rigidBodyArray, unsigned int numBodies) {
    for (unsigned int i = 0; i < numBodies; ++i) {
      rigidBodies_.erase(rigidBodyArray[i]);
    }
  }

  void RigidBodySystem::addForce(Force *force) {
    forces_.insert(force);
  }

  void RigidBodySystem::addForces(Force **forces, unsigned int numForces) {
    for (unsigned i = 0; i < numForces; ++i) {
      forces_.insert(forces[i]);
    }
  }

  void RigidBodySystem::removeForce(Force *force) {
    forces_.erase(force);
  }

  void RigidBodySystem::removeForces(Force **forces, unsigned int numForces) {
    for (unsigned int i = 0; i < numForces; ++i) {
      forces_.erase(forces[i]);
    }
  }

  // TODO implement
  void RigidBodySystem::computeStateDeriv(Real /*t*/, const Real /**S*/, Real * /*dSdt*/) {

  }

  void RigidBodySystem::buildSystemStateArray() {
    // TODO: Make more robust (don't use 4 as vec dimension)
    Real *S_temp = S_;

    unordered_set<RigidBody*>::iterator it;
    for(it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it) {
      // Store the current RigidBody's position, momentum, orientation, and
      // angular momentum information in the next 4 elemnts of S_
      (*it)->copyState(S_temp);
      S_temp += 4; // 4 is the number of elements copies each time
    }
  }

  void RigidBodySystem::clearForceAccumulators() {
    unordered_set<RigidBody*>::iterator it;
    for(it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it) {
      (*it)->zeroForceAccum();
    }
  }

  void RigidBodySystem::updateRigidBodies() {
    Real * S_temp = S_;

    // Update the x and y components of position and momentum for each RigidBody.
    unordered_set<RigidBody*>::iterator it;
    for(it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it) {
      (*it)->setPosition(*S_temp++, *S_temp++);
      (*it)->setMomentum(*S_temp++, *S_temp++);
    }
  }

} // namespace Rigid2D
