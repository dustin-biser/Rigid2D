#include "Force.h"

using namespace Rigid2D;

Force::Force(ForceFunction f, RigidBody * rigidBodyArray, void * userData)
  : forceFunction_(f), rigidBodyArray_(rigidBodyArray), userData_(userData){

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
