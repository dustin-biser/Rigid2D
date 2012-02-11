#include "Force.h"

using namespace std;

namespace Rigid2D {

  Force::Force(ForceFunctionPtr forceFunction, RigidBody **rigidBodyArray,
      unsigned int numBodies, void * userData)
    : numBodies_(numBodies),
      userData_(userData),
      enabled_(true),
      forceFunction_(forceFunction)
  {
    addRigidBodies(rigidBodyArray, numBodies);

    forceVector_.x = 0.0;
    forceVector_.y = 0.0;
  }

  void Force::applyForce(){
    unordered_set<RigidBody*>::iterator it;
    for (it = rigidBodies_.begin(); it != rigidBodies_.end(); ++it) 
    {
      forceFunction_(*it, &forceVector_, userData_);
      (*it)->addToForceAccum(forceVector_);
    }
  }

  void Force::addRigidBody(RigidBody *rigidBody)
  {
    rigidBodies_.insert(rigidBody);
  }

  void Force::addRigidBodies(RigidBody **rigidBodyArray, unsigned count)
  {
    for (unsigned i = 0; i < count; i++) {
      rigidBodies_.insert(rigidBodyArray[i]);
    }
  }

  void Force::removeRigidBody(RigidBody *rigidBody)
  {
    rigidBodies_.erase(rigidBody);
  }

  void Force::removeRigidBodies(RigidBody **rigidBodyArray, unsigned count)
  {
    for (unsigned int i = 0; i < count; i++) {
      rigidBodies_.erase(rigidBodyArray[i]);
    }
  }

  void Force::clearRigidBodies()
  {
    rigidBodies_.clear();
  }

}
