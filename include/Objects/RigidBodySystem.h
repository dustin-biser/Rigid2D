#ifndef RIGID2D_RIGID_BODY_SYSTEM_H
#define RIGID2D_RIGID_BODY_SYSTEM_H

#include "RigidSettings.h"
#include "Common/OdeSolver.h"
#include "RigidBody.h"
#include "Force.h"

namespace Rigid2D{
  class RigidBodySystem{
    private:
      // Computes the derivative dS/dt given inputs t and S
      void computStateDeriv(Real t, const Real* S, Real* dSdt);

      // Iterates through each RigidBody 
      void buildSystemStateArray();

    public:
      RigidBodySystem();
      ~RigidBodySystem();

      /** Uses OdeSolver to update state information for each RigidBody associated
       * with the current RigidBodySystem.
       */
      void updateRigidBodies();

      /**
       * Iterates through each pointer of rigidBodyArray checking that it is
       * not currently stored within the RigidBodySystem, and adds it to the
       * system if not found.
       *
       * @param rigidBodyArray memory location to beginning of array of
       *  RigidBody objects.
       * @param numBodies number of RigidBodies pointed to by rigidBodyArray.
       *
       * @return true if all pointers are added to the RigidBodySystem, or false
       *  otherwise.
       */
      bool addRigidBodies (RigidBody * rigidBodyArray, unsigned int numBodies);

      /**
       * Iterates through each pointer of rigidBodyArray and removes it from
       * the current RigidBodySystem.
       *
       * @param rigidBodyArray memory location to beginning of array of
       *  RigidBody objects.
       * @param numBodies number of RigidBodies pointed to by rigidBodyArray.
       *
       * @return true if all RigidBodies were found and removed from the current
       * RigidBodySystem, or false otherwise.
       */
      bool removeRigidBodies (RigidBody * rigidBodyArray, unsigned int numBodies);

      /**
       * Iterates through current list of RigidBody pointers and adds rigidBody
       * to the list if it is unique.
       *
       * @param rigidBody memory location for a RigidBody object.
       *
       * @return true if pointer was added to the RigidBodySystem, or false
       *  otherwise.
       */
      bool addRigidBody(RigidBody * rigidBody);

      bool removeRigidBody(RigidBody * rigidBody);

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
      RigidBody * rigidBodies_;   // Collection of all rigid bodies
      unsigned long numBodies_;   // Number of rigid bodies within the system
      Force * forces_;            // Collection of all forces
      unsigned long numForces_;   // Number of forces within the system
      Real * S_                   // state array S, representing collection of
                                  // all RigidBody states

      PreciseReal time_;          // Simulation clock
      OdeSolver solver_;          // Used to solve the system dS/dt = G(t,S)
  };
} // end namespace Rigid2D

#endif
