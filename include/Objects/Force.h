#ifndef RIGID2D_FORCE_H
#define RIGID2D_FORCE_H
#include "Common/RigidSettings.h"
#include "Objects/RigidBody.h"

namespace Rigid2D{
  /// Representation of a force that acts one or more RigidBodies.
  /** Each Force object will contain an associated ForceFunction, written by
   *  the user, that tells the Force class how to calculate forces for each of
   *  the RigidBodies it is acting upon.
   *
   *  The userData field, which is passed to the Force constructor, can be
   *  used to specify user specific data for the calculation of forces within
   *  the ForceFunction routine.  One example of this use, is storing mouse
   *  coordinates in the array mpos, and then passing the address of mpos to
   *  the userData parameter when calling the Force class constructor.  Then
   *  the user can write their ForceFunction by referencing the variable userData
   *  in order to access mouse coordinates when specifying the force calculations.
   *
  */
  class Force {
    public:
      typedef
      void (*ForceFunction)(RigidBodies * rigidBodies,   // Collection of RigidBodies
                                                         // that the force is acting upon.

                            Vector2 * dst,               // Destination for storing force
                                                         // vectors.

                            void * userData);            // User specific data which can be
                                                         // used in computing forces.

      Force(ForceFunction funct, RigidBody * rigidBodyArray = 0, void * userData = 0);
      Force(ForceFunction funct, void * userData = 0);
      ~Force();
      void applyForce();

      // Iterates through each pointer of rigidBodyArray checking that it is not
      // contained in rigidBodies_, and adds it to the array if not found.  If
      // all pointers in rigidBodyArray are added to the array rigidBodies_,
      // then addRigidBody returns True.  Returns false otherwise.
      bool addRigidBodies(RigidBody * rigidBodyArray);

      // Iterates through each pointer of rigidBodyArray and compares it to the
      // pointers found in rigidBodies_.  If the pointer is found, it is removed
      // from rigidBodies_.  If all pointers in rigidBodyArray are found and
      // removed from rigidBodies_ in this way, then removeRigidBodies returns
      // true.  Returns false otherwise.
      bool removeRigidBodies(RigidBody * rigidBodyArray);

      // Set funct as the new ForceFunction
      void setForceFunction(ForceFunction funct);

      // Returns true if force is enabled.  False otherwise.
      bool isEnabled();

      // Enable current Force object by passing true, or disable it by passing false.
      // If the Force object is diabled, it will not act upon its current list of
      // RigidBodies until it is enabled again.
      void setEnabled(bool trueOrFlase);

    protected:
      Vector2 * forceVectors_
      RigidBody * rigidBodies_
      unsigned int numBodies_
      void * userData_
      bool enabled_
      ForceFunction f_
  };
} // end namespace Rigid2D

#endif
