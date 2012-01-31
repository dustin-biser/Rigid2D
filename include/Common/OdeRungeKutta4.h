#ifndef RIGID_ODE_RUNGE_KUTTA_4_H
#define RIGID_ODE_RUNGE_KUTTA_4_H
#include "RigidSettings.h"
#include "OdeSolver.h"
#include "RigidException.h"
#include <vector>
using std::vector;

namespace Rigid2D{
  // Implementation of a 4th order 4 stage Runge Kutta method for approximating
  // solutions to the system dx/dt = f(t,x), where x and f are m-dimensional vectors.
  class OdeRungeKutta4 : public OdeSolver {
    public:
      OdeRungeKutta4(unsigned int dimension, Real step, DerivFunction dxdt, void* optionalData = 0);

      ~OdeRungeKutta4() { }

      // Advances tOut and xOut by one step from tIn and xIn, respectively
      virtual void processNextStep (Real tIn, Real* xIn, Real& tOut, Real* xOut);

      // A simplier way to call processNextStep
      virtual void processNextStep (Real t, Real* x);

      virtual void setDimension (unsigned int newDim);
    private:
      Real oneHalfStep_;
      Real oneSixthStep_;
      vector<Real> kn1_;
      vector<Real> kn2_;
      vector<Real> kn3_;
      vector<Real> kn4_;
      vector<Real> tmp_;
  };
}
#endif
