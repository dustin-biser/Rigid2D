#ifndef RIGID_BODY_SYSTEM_H
#define RIGID_BODY_SYSTEM_H

#include "Rigid2D/RigidSettings.h"
#include "Rigid2D/include/Common/OdeSolver.h"

namespace Rigid2D{
  class RigidBodySystem{
    public:
      // Computes the derivative dS/dt of the system state array S
      OdeSolver::DerivFunc stateDeriv(Real t, const Real* S, Real* dSdt);

      // Uses OdeSolver to update state information for each RigidBody
      void updateRigidBodies();

    private:
      RigidBody * rigidBodies_;   // Collection of all rigid bodies
      Force * forces_;            // Collection of all forces
      Real * state_               // S
      unsigned long numBodies_;   // Number of rigid bodies within collection
      unsigned long numForces_;   // Number of forces within collction
      PreciseReal time_;          // Simulation clock
      OdeSolver solver_;          // Used to solve the system dS/dt = f(t,S)
  };
} // end namespace Rigid2D

#endif
