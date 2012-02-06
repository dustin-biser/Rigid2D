#ifndef RIGID2D_FORCE_H
#define RIGID2D_FORCE_H
#include "Common/RigidSettings.h"

namespace Rigid2D{
  class Force {
    public:
      typedef
      void (*ForceFunction)(RigidBodies * rigidBodies,   // Collection of RigidBodies
                                                         // that the force is acting upon.

                            Vector2 * dst,               // Destination for storing force
                                                         // vectors.

                            void * optionalData);        // User specific data which can be
                                                         // used in computing forces.
      Force();
      ~Force();
      void applyForce();
      bool addRigidBodies(RigidBody * rigidBodyArray);
      bool removeRigidBodies(RigidBody * rigidBodyArray);
      bool isEnabled();
      void setEnabled();

    protected:
      Vector2 * forceVectors_
      RigidBody * rigidBodies_
      unsigned int numBodies_
      void * optionalData_
      bool enabled_
      ForceFunction f_
  };
} // end namespace Rigid2D

#endif
