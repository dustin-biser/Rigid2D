#include "RungeKutta4RigidBodySolver.h"

using namespace Rigid2D;

// When RigidBodySystem creates an instance of RungeKutta4RigidBodySolver it
// will pass 'this' to 'optionalData'.  The pointer to RigidBodySystem will
// be stored in the member variable rigidBodySystem_.
RungeKutta4RigidBodySolver::RungeKutta4RigidBodySolver(unsigned int dimension,
    Real step, DerivFunction dxdt, void* optionalData)
    : OdeSolver(dimension, step, NULL),
      rigidBodySystem_((RigidBodySystem*)optionalData) {

}
