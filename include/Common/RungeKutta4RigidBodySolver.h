#ifndef RIGID2D_RUNGE_KUTTA4_RIGID_BODY_SOLVER_H
#define RIGID2D_RUNGE_KUTTA4_RIGID_BODY_SOLVER_H

#include "RigidSettings.h"
#include "Objects/RigidBodySystem.h"
#include "OdeRungeKutta4.h"

namespace Rigid2D{
  class RungeKutta4RigidBodySolver : public OdeRungeKutta4 {
    public:
      RungeKutta4RigidBodySolver(unsigned int dimension, Real step, DerivFunction dxdt, void* optionalData = 0);

    private:
      RigidBodySystem * rigidBodySystem_;
  };
} // end namespace Rigid2D

#endif
