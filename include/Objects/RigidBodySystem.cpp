#include "RigidBodySystem.h"
#include "Common/RungeKutta4RigidBodySolver.h"
#include "Common/RigidException.h"
#include <new>
#include <cstring> // for memcpy()

using namespace std;

namespace Rigid2D {

  RigidBodySystem::RigidBodySystem( ) {
    time_ = 0.0;

    // Initially, the system has no RigidBodies, so set dimension to zero.
    systemDimension_ = 0;

    // TODO: Set to 2 for now.  Once we handle RigidBody orientation and angular momentum,
    // change this to 4.
    statesPerRigidBody_ = 2;

    // Set the starting allocation size for S_.
    allocationSize_ = 10 * statesPerRigidBody_;

    // NULL solver_ and S_ so that delete is not called during
    // intializeSandSolver().
    solver_ = NULL;
    S_ = NULL;

    // Initialize system state array S_, SLength_, and OdeSolver solver_.
    initializeSAndSolver();
  }

  RigidBodySystem::~RigidBodySystem() {
    if (solver_ != NULL)
      delete solver_;

    if (S_ != NULL)
      delete [] S_;
  }

  void RigidBodySystem::update() {
    if (systemDimension_ == 0) return;

    // Update the system time_, and system state array S_
    solver_->processNextStep(time_, S_);

    // Disperse state information within S_ to all RigidBodies
    updateRigidBodies();
  }

  // Append state information to end of S_ and re-allocate memory if needed.
  void RigidBodySystem::addRigidBody(RigidBody *rigidBody) {
    assert(rigidBody != NULL);

    // Insertion was successful if second field is true
    if (rigidBodies_.insert(rigidBody).second){
      // Update systemDimension_
      systemDimension_ += statesPerRigidBody_;

      if (systemDimension_ > SLength_) {
        // Double the size of S_, SLength_, and dimension of OdeSolver.
        initializeSAndSolver();
      }
    }
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
  void RigidBodySystem::computeStateDeriv(Real, const Real * S, Real * dSdt) {
    // Check if input S is the same as the system state array S_.  This will be
    // true for the first step of RungeKutta4 Method, allowing us to skip one
    // process cycle.
    if (S != S_){
      // Need to update all RigidBody state information using state array S, then
      // recalculate all force accumulator fields for the RigidBodies.

      // Copy elements of S into S_.
      memcpy(S_, S, systemDimension_*sizeof(Real));

      // Disperse state array S to all RigidBodies.
      updateRigidBodies();

      // Set each RigidBody's force accumulator field to zero.
      clearForceAccumulators();

      // Loop through each Force object calling their applyForce() function.
      // This will update the RigidBody forceAccumulator fields needed for dSdt.
      applyAllForces();
    }

    // Loop through each RigidBody and build the state derivative array
    // dSdt = (p_1\m_1, F_1,..., p_n\m_n, F_n)
    buildDerivStateArray(dSdt);
  }

  void RigidBodySystem::applyAllForces(){
    unordered_set<Force *>::iterator it;
    for(it = forces_.begin(); it != forces_.end(); ++it) {
      (*it)->applyForce();
    }
  }

  void RigidBodySystem::buildSystemStateArray() {
    Real *S_temp = S_;

    unordered_set<RigidBody*>::iterator it;
    for(it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it) {
      // Store the current RigidBody's position, momentum, orientation, and
      // angular momentum information in the next 4 elements of S_.
      (*it)->getState(S_temp);
      S_temp += statesPerRigidBody_;
    }
  }

  void RigidBodySystem::buildDerivStateArray(Real * dSdt){
    assert(dSdt != NULL);

    Real *dSdt_temp = dSdt;

    unordered_set<RigidBody*>::iterator it;
    for(it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it) {
      // Store the current RigidBody's position, momentum, orientation, and
      // angular momentum information in the next 4 elements of S_.
      (*it)->getStateDeriv(dSdt_temp);
      dSdt_temp += statesPerRigidBody_;
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
      // Copy state information from S_ into the current RigidBody, thus
      // updating its position, momentum, orientation, and angular momentum.
      (*it)->setState(S_temp);
      S_temp += statesPerRigidBody_;
    }
  }

  // To be called only from within initializeSndSolver().  This is to make sure
  // that the dimension of OdeSolver is always equal to SLength_.
  void RigidBodySystem::initializeSolver(){
    if (solver_ != NULL)
      delete solver_;

    try {
       solver_ = new RungeKutta4RigidBodySolver(SLength_, this);
    }
    catch (std::bad_alloc error){
      throw InternalErrorException(__LINE__, __FUNCTION__, __FILE__,
        "Memory Allocation Failure");
    }
  }

  void RigidBodySystem::initializeSAndSolver(){
    if (S_ != NULL)
      delete S_;

    try {
      S_ = new Real [allocationSize_];
    }
    catch (std::bad_alloc error){
      throw InternalErrorException(__LINE__, __FUNCTION__, __FILE__,
        "Memory Allocation Failure");
    }

    // Update the length of S_.
    SLength_ = allocationSize_;

    // Initialize all non-used elements of S_ to zero
    for(unsigned int i = systemDimension_; i < SLength_; ++i){
      S_[i] = 0.0;
    }

    // Copy all RigidBody state information into S_.
    buildSystemStateArray();

    // Delete current OdeSolver, and reallocate a new one with dimension
    // equal to SLength_.
    initializeSolver();

    // Next time initalizeSAndSolver() is called we will double the size of S_
    // and the dimension of solver_.
    allocationSize_ *= 2;
  }

} // namespace Rigid2D
