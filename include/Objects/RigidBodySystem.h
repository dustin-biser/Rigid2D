#ifndef RIGID2D_RIGID_BODY_SYSTEM_H
#define RIGID2D_RIGID_BODY_SYSTEM_H

#include "RigidSettings.h"
#include "Common/OdeSolver.h"
#include "RigidBody.h"
#include "Force.h"

namespace Rigid2D{
  class RigidBodySystem{
    public:
      RigidBodySystem(Real stepSize = 0.01);  // starting stepSize for the OdeSolver
      ~RigidBodySystem();

      // Computes the derivative dS/dt of the system state array S
      OdeSolver::DerivFunc stateDeriv(Real t, const Real* S, Real* dSdt);

      // Uses OdeSolver to update state information for each RigidBody
      void updateRigidBodies();

      void addRigidBodies (RigidBody * rigidBodies);
      void removeRigidBodies (RigidBody * rigidBodies);
      void addForces (Force * forces);
      void removeForces (Force * forces);

    private:
      RigidBody * rigidBodies_;   // Collection of all rigid bodies
      Force * forces_;            // Collection of all forces
      Real * state_               // state array S, representing collection of all RigidBody states
      unsigned long numBodies_;   // Number of rigid bodies within the system
      unsigned long numForces_;   // Number of forces within the system
      PreciseReal time_;          // Simulation clock
      OdeSolver solver_;          // Used to solve the system dS/dt = f(t,S)
  };
} // end namespace Rigid2D

#endif
