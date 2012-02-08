#ifndef RIGID2D_RUNGE_KUTTA4_RIGID_BODY_SOLVER_H
#define RIGID2D_RUNGE_KUTTA4_RIGID_BODY_SOLVER_H

#include "RigidSettings.h"
#include "Objects/RigidBodySystem.h"
#include "OdeRungeKutta4.h"

namespace Rigid2D{
  class RungeKutta4RigidBodySolver : public OdeRungeKutta4 {
    public:
      // dimension corresponds to the dimension of the system dSdt = G(t, S).
      // This should be number of RigidBodies * the number of states stored
      // per RigidBody.  rigidBodySystem should be the address of the
      // RigidBodySystem that keeps track of all Force and RigidBody objects.
      // stepSize is the beginning stepSize for the OdeSolver.
      RungeKutta4RigidBodySolver(unsigned int dimension,
          RigidBodySystem * rigidBodySystem, Real stepSize = 0.01);

      // Advances tOut and xOut by one step from tIn and xIn, respectively
      virtual void processNextStep (Real tIn, Real* xIn, Real& tOut, Real* xOut);

      // A simplier way to call processNextStep
      virtual void processNextStep (Real& t, Real* x);

    private:
      RigidBodySystem * rigidBodySystem_;
  };
} // end namespace Rigid2D

#endif
