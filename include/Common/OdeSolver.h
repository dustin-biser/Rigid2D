#ifndef RIGID_ODE_SOLVER_H
#define RIGID_ODE_SOLVER_H
#include "RigidSettings.h"

namespace Rigid2D{
  // Abstract base class representing an ODE Solver that computes approximations to
  // the solution of the system dx/dt = f(t,x), where x and f are m-dimensional vectors.
  class OdeSolver{
    public:
        // Given input values for t and array x, DerivFunction should compute the array dxdt.
        typedef void (*DerivFunction)(
            Real,          // time t
            const Real*,   // state array x
            Real *         // location to store dxdt
            );

    protected:
        OdeSolver (unsigned int dimension, Real step, DerivFunction dxdt, void* optionalData = 0);

    public:
        virtual ~OdeSolver (){ }

        // Advances tOut and xOut by one step from tIn and xIn, respectively
        virtual void processNextStep (Real tIn, Real* xIn, Real& tOut, Real* xOut) = 0;

        // A simiplier way of calling ProcessNextStep
        virtual void processNextStep(Real& t, Real* x) = 0;

        virtual void setDimension(unsigned int newDim) = 0;
        Real getStepSize() const;
        void setStepSize(Real stepSize);

    protected:
      unsigned int dimension_;   // length of the vectors that compose the system dx/dt = f(t,x)
      Real stepSize_;            // dt, difference between two adjancent time steps
      DerivFunction f_;          // function used for updating t, x, and dx/dt

      void* optionalData_;       // storage for implmentation of specific
                                 // data (e.g. error tolerance, stepSize
                                 // factors for adaptive schemes, ect.)
  };

  inline OdeSolver::OdeSolver (unsigned int dimension, Real step, OdeSolver::DerivFunction function, void* optionalData)
      : dimension_(dimension),
        stepSize_(step),
        f_(function),
        optionalData_(optionalData) { }

  inline Real OdeSolver::getStepSize() const {
    return stepSize_;
  }

  inline void OdeSolver::setStepSize(Real stepSize){
    stepSize_ = stepSize;	
  }

} //end namespace Rigid2D

#endif
