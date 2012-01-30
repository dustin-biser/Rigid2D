#ifndef RIGID_ODE_SOLVER_H
#define RIGID_ODE_SOLVER_H
#include "RigidSettings.h"

namespace Rigid2D{
  // Abstract base class representing an ODE Solver that computes approximations to
  // the solution of the system dx/dt = f(t,x), where x and f are m-dimensional vectors.
  class OdeSolver{
    public:
        // Given input values for t and array x, DerivFunction should compute the array dxdt.
        typedef Real * (*DerivFunction)(
            Real,          // Time t
            const Real*    // State array x
            );

    protected:
        OdeSolver (unsigned int dimension, Real step, DerivFunction dxdt, void* optionalData = 0);

    public:
        virtual ~OdeSolver (){ }

        // Advances tOut and xOut by one step from tIn and xIn, respectively
        virtual void ProcessNextStep (Real tIn, Real* xIn, Real& tOut, Real* xOut) = 0;

        // Simiplier way of calling method
        void ProcessNextStep(Real& t, Real* x);

        virtual void setDimension(unsigned int newDim) = 0;
        Real stepSize() const;
        void SetStepSize(Real stepSize);

    protected:
      unsigned int dimension_;       // length of the vectors that compose the system dx/dt = f(t,x)
      Real stepSize_;                // dt, difference between two adjancent time steps
      DerivFunction f_;              // function used for updating t, x, and dx/dt

      void* optionalData_;           // storage for implmentation of specific
                                     // data (e.g. error tolerance, stepSize
                                     // factors for adaptive schemes, ect.)
  };

  inline OdeSolver::OdeSolver (unsigned int dimension, Real step, OdeSolver::DerivFunction function, void* optionalData)
      : dimension_(dimension),
        stepSize_(step),
        f_(function),
        optionalData_(optionalData) { }

  inline Real OdeSolver::stepSize() const {
    return stepSize_;
  }

  inline void OdeSolver::SetStepSize(Real stepSize){
    stepSize_ = stepSize;	
  }

  inline void OdeSolver::ProcessNextStep(Real& t, Real* x){
    ProcessNextStep(t, x, t, x);
  }

} //end namespace Rigid2D

#endif
