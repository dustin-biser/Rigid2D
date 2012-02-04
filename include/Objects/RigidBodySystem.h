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

      void buildSystemStateArray();

    public:
      RigidBodySystem(Real stepSize = 0.01);  // starting stepSize for the OdeSolver
      ~RigidBodySystem();


      // Uses OdeSolver to update state information for each RigidBody
      void updateRigidBodies();

      bool addRigidBodies (RigidBody * rigidBodies);
      bool removeRigidBodies (RigidBody * rigidBodies);
      bool addForces (Force * forces);
      bool removeForces (Force * forces);
      unsigned int getDimension();

    private:
      RigidBody * rigidBodies_;   // Collection of all rigid bodies
      unsigned long numBodies_;   // Number of rigid bodies within the system
      Force * forces_;            // Collection of all forces
      unsigned long numForces_;   // Number of forces within the system
      Real * S_                   // state array S, representing collection of
                                  // all RigidBody states

      PreciseReal time_;          // Simulation clock
      OdeSolver solver_;          // Used to solve the system dS/dt = f(t,S)
  };
} // end namespace Rigid2D

#endif
