#ifndef RIGID2D_FORCE_H
#define RIGID2D_FORCE_H
#include "Common/RigidSettings.h"
#include "Common/Vector2.h"
#include "Objects/RigidBody.h"
#include <unordered_set>

namespace Rigid2D {
  using namespace std;
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
      void (*ForceFunctionPtr)(RigidBody * const rigidBody,    // Memory location for a particular
                                                               // RigidBody that the force is acting
                                                               // upon.

                               Vector2 * dst,                  // Destination for storing force
                                                               // components.

                               void * userData);               // User specific data which can be
                                                               // used in computing forces.

      Force(ForceFunctionPtr forceFunction, RigidBody **rigidBodyArray, unsigned int numBodies, void * userData = 0);

      //TODO Force(ForceFunctionPtr forceFunction, void * userData = 0);
      //TODO Force();

      ~Force();

      // Calculates forces on each RigidBody by calling the given ForceFunctionPtr associated
      // with this Force object.  After a force is calculated for a given RigidBody it is
      // added to the RigidBodies forceAccumulator field.
      void applyForce();

      // ??Iterates through each pointer of rigidBodyArray checking that it is not
      // contained in rigidBodies_, and adds it to the array if not found.  If
      // all pointers in rigidBodyArray are added to the array rigidBodies_,
      // then addRigidBody returns True.  Returns false otherwise.??
      void addRigidBody(RigidBody *rigidBody);
      void addRigidBodies(RigidBody **rigidBodyArray, unsigned count);

      // ??Iterates through each pointer of rigidBodyArray and compares it to the
      // pointers found in rigidBodies_.  If the pointer is found, it is removed
      // from rigidBodies_.  If all pointers in rigidBodyArray are found and
      // removed from rigidBodies_ in this way, then removeRigidBodies returns
      // true.  Returns false otherwise.??
      void removeRigidBody(RigidBody *rigidBody);
      void removeRigidBodies(RigidBody **rigidBodyArray, unsigned count);
      void clearRigidBodies();

      // Set funct as the new ForceFunctionPtr
      void setForceFunction(ForceFunctionPtr funct);

      // Returns true if force is enabled.  False otherwise.
      bool isEnabled();

      // Enable current Force object by passing true, or disable it by passing false.
      // If the Force object is diabled, it will not act upon its current list of
      // RigidBodies until it is enabled again.
      void setEnabled(bool trueOrFlase);


      //TODO void setUserData(void * userData);

    protected:
      Vector2 forceVector_;
      unordered_set<RigidBody*> rigidBodies_;
      unsigned int numBodies_;
      void * userData_;
      bool enabled_;
      ForceFunctionPtr forceFunction_;
  };
} // end namespace Rigid2D

#endif
