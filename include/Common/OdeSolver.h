#ifndef RIGID_ODE_SOLVER_H
#define RIGID_ODE_SOLVER_H
#include "RigidSettings.h"

namespace Rigid2D{
  // Abstract base class representing an ODE Solver that computes approximations to
  // the solution of the system dx/dt = f(t,x), where x and f are m-dimensional vectors.
  class OdeSolver{
    public:
        typedef void (*Function)(
            Real,          // Time t

            const Real*,   // State vector x.  Constant because various
                           // algorithms will need the current value of x at
                           // different steps.

            Real*          // Memory location for storing the value of f(t,x)
            );

    protected:
        OdeSolver (unsigned int dimension, Real* x, Function function,
            Real step, void* optionalData = 0);

    public:
        virtual ~OdeSolver (){ }
        virtual void ProcessNextStep (Real tIn, Real* xIn, Real& tOut, Real* xOut) = 0;
        Real stepSize() const;
        void SetStepSize(Real stepSize);

    protected:
      unsigned int dimension_;       // dimension size of system

      Real* xValue_;                 // x

      Real* fValue_;                 // f(t,x)

      Real stepSize_;                // dt, difference between two adjancent time steps

      Function f_;                   // function used for updating t, x, and f(t,x)

      void* optionalData_;           // storage for implmentation of specific
                                     // data (e.g. error tolerance, stepSize
                                     // factors for adaptive schemes, ect.)
  };

  inline OdeSolver::OdeSolver (unsigned int dimension, Real* x, OdeSolver::Function function,
      Real step, void* optionalData)
      : dimension_(dimension),
        xValue_(x),
        stepSize_(step),
        f_(function),
        optionalData_(optionalData) { }

  inline Real OdeSolver::stepSize() const {
    return stepSize_;
  }

  inline void OdeSolver::SetStepSize(Real stepSize){
    stepSize_ = stepSize;	
  }

} //end namespace Rigid2D

#endif
