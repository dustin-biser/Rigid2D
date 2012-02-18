#include "RigidBodySystem.h"
#include "Common/RungeKutta4RigidBodySolver.h"
#include "Common/RigidException.h"
#include <new>

using namespace std;

namespace Rigid2D {

  RigidBodySystem::RigidBodySystem( ) {
    time_ = 0.0;

    // TODO Allocate some set amount of memory for S_
    S_ = NULL;

    // Initially, the system has no RigidBodies, so set dimention to zero.
    dimension_ = 0;

    // TODO: Set to 2 for now.  Once we handle RigidBody orientation and angular momentum,
    // change this to 4.
    statesPerRigidBody_ = 2;

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
    // TODO Redesign.  Only need to append state information to end of S_ each
    // time we add/remove rigid body.
    // If S_ is NULL, construct it from the state information of each RigidBody
    //if (S_ == NULL)
      //buildSystemStateArray();

    // Update the system time_, and system state array S_
    solver_->processNextStep(time_, S_);

    // Disperse state information within S_ to all RigidBodies
    updateRigidBodies();
  }

  //TODO update dimension of OdeSolver and S_.  Set force accumulator to zero
  // After insert check if rigidBodies_.length()*statesPerRigidBody_ != systemDimension_
  // Append state information to end of S_ and re-allocate memory if needed.
  void RigidBodySystem::addRigidBody(RigidBody *rigidBody) {
    rigidBodies_.insert(rigidBody);
  }

  //TODO update dimension of OdeSolver and S_.  Set force accumulator to zero
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

  // Computes the derivative dS/dt, from the given inputs:
  // t - simulation time
  // S - system state array
  void RigidBodySystem::computeStateDeriv(Real t, const Real * S, Real * dSdt) {
    // Check if input S is the same as the system state array S_
    // If not, then
    //    1) Disperse state array S_ to all RigidBodies.
    //    2) Clear force accumulators for each RigidBody.
    //    3) Loop through each Force object calling their applyForce() function.

    // Loop through each RigidBody and build the state derivative array
    // dSdt = (p_1\m_1, F_1,..., p_n\m_n, F_n)


  }

  // Use when we call removeRigidBodies()
  void RigidBodySystem::buildSystemStateArray() {
    Real *S_temp = S_;

    unordered_set<RigidBody*>::iterator it;
    for(it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it) {
      // Store the current RigidBody's position, momentum, orientation, and
      // angular momentum information in the next 4 elements of S_.
      (*it)->copyState(S_temp);
      S_temp += statesPerRigidBody_;
    }
  }

  void RigidBodySystem::clearForceAccumulators() {
    unordered_set<RigidBody*>::iterator it;
    for(it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it) {
      // Zero the forceAccumulator field for current RigidBody
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
