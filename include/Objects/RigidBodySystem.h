#ifndef RIGID2D_RIGID_BODY_SYSTEM_H
#define RIGID2D_RIGID_BODY_SYSTEM_H

#include "Common/RigidSettings.h"
#include "Common/OdeSolver.h"
#include "RigidBody.h"
#include "Force.h"

namespace Rigid2D{
  class RigidBodySystem{
    private:
      // Computes the derivative dS/dt given inputs t and S
      void computeStateDeriv(Real t, const Real* S, Real* dSdt);

      // Iterates through each RigidBody collecting state information and appending
			// it to S_
      void buildSystemStateArray();

    public:
      RigidBodySystem();
      ~RigidBodySystem();

      /** Uses OdeSolver to update state information for each RigidBody associated
       * with the current RigidBodySystem.
       */
      void updateRigidBodies();

      /**
       * Tells RigidBodySystem to keep track of a RigidBody. If the body (pointer) 
       * was previously added, it does not get added a second time.
       *
       * @param rigidBody pointer to a RigidBody object.
       * @see addRigidBodies()
       * @see removeRigidBody()
       * @see removeRigidBodies()
       */
      void addRigidBody(RigidBody * rigidBody);

      /**
       * Same as addRigidBody() but for multiple bodies.
       *
       * @param rigidBodyArray array of RigidBody's.
       * @param numBodies length of rigidBodyArray.
       * @see addRigidBody()
       * @see removeRigidBody()
       * @see removeRigidBodies()
       */
      void addRigidBodies(RigidBody * rigidBodyArray, unsigned int numBodies);

      /** Tells RigidBodySystem to not keep track of a RigidBody. If the body
       * (pointer) was not previously added, it does nothing.
       *
       * @param rigidBody pointer to a RigidBody object.
       * @see addRigidBody()
       * @see addRigidBodies()
       * @see removeRigidBodies()
       */
      void removeRigidBody(RigidBody * rigidBody);
      
      /**
       * Same as removeRigidBody() but for multiple bodies.
       *
       * @param rigidBodyArray array of RigidBody's.
       * @param numBodies length of rigidBodyArray.
       * @see addRigidBody()
       * @see addRigidBodies()
       * @see removeRigidBody()
       */
      void removeRigidBodies (RigidBody * rigidBodyArray, unsigned int numBodies);



      /**
       * Iterates through each pointer of forceArray checking that it is
       * not currently stored within the RigidBodySystem, and adds it to the
       * system if not found.
       *
       * @param forceArray memory location to beginning of array of Force objects.
       * @param numForces number of Force objects pointed to by forceArray.
       *
       * @return true if all pointers are added to the RigidBodySystem, or false
       *  otherwise.
       */
      bool addForces (Force * forceArray, unsigned int numForces);
      bool removeForces (Force * forces, unsigned int numForces);
      bool addForce(Force * force);
      bool removeForce(Force * force);

      unsigned int getDimension();

    private:
      unordered_set<RigidBody*> rigidBodies_;   // Collection of all tracked rigid bodies
      unsigned long numBodies_;                 // Number of rigid bodies within the system
      unordered_set<Force*> forces_;            // Collection of all forces
      unsigned long numForces_;                 // Number of forces within the system
      Real * S_                                 // state array S, representing collection of
                                                // all RigidBody states

      PreciseReal time_;                        // Simulation clock
      OdeSolver solver_;                        // Used to solve the system dS/dt = G(t,S)

} // end namespace Rigid2D

#endif
