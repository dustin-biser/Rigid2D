#include "Force.h"

namespace Rigid2D {

  Force::Force(ForceFunctionPtr forceFunction, RigidBody * rigidBodyArray,
      unsigned int numBodies, void * userData)
    : rigidBodies_(rigidBodyArray),
      numBodies_(numBodies),
      userData_(userData),
      enabled_(true),
      forceFunction_(forceFunction) 
  {

    forceVector_.x = 0.0;
    forceVector_.y = 0.0;
  }

  void Force::applyForce(){
    // Iterate through the set of RigidBodies.  Force each RigidBody call
    //
    // forceFunction(currentRigidBody, forceVector_, userData_).
    //
    // This will update forceVector_ with the computed force using any userData_
    // that was given.  Then add forceVector_ to the currentRigidBody's
    // forceAccumulator field.
    for (unordered_set<RigidBody*>::iterator it = rigidBodies_.begin();
        it != rigidBodies_.end(); ++it) 
    {
      forceFunction(*it, forceVector_, userData_);
      *it.addToForceAccum(forceVector_);
    }
  }

  void Force::addRigidBody(RigidBody *rigidBody)
  {
    rigidBodies_.insert(rigidBody);
  }

  void Force::addRigidBodies(RigidBody * rigidBodyArray, unsigned count)
  {
    for (int i = 0; i < count; i++) {
      rigidBodies_.insert(rigidBodyArray[i]);
    }
  }

  void Force::removeRigidBody(RigidBody *rigidBody)
  {
    rigidBodies_.erase(rigidBody);
  }

  void Force::removeRigidBodies(RigidBody * rigidBodyArray, unsigned count)
  {
    for (int i = 0; i < count; i++) {
      rigidBodies_.erase(rigidBodyArray[i]);
    }
  }

  void Force::clearRigidBodies()
  {
    rigidBodies_.clear();
  }

}
