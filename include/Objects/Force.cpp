#include "Force.h"

using namespace Rigid2D;

Force::Force(ForceFunctionPtr forceFunction, RigidBody * rigidBodyArray,
    unsigned int numBodies, void * userData)
  : rigidBodies_(rigidBodyArray),
    numBodies_(numBodies),
    userData_(userData),
    enabled_(true),
    forceFunction_(forceFunction) {

    forceVector_.x = 0.0;
    forceVector_.y = 0.0;

}

Force::applyForce(){
  // Iterate through the set of RigidBodies.  Force each RigidBody call
  //
  // forceFunction(currentRigidBody, forceVector_, userData_).
  //
  // This will update forceVector_ with the computed force using any userData_
  // that was given.  Then add forceVector_ to the currentRigidBody's
  // forceAccumulator field.

}
