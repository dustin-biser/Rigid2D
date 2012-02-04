#include "RungeKutta4RigidBodySolver.h"

using namespace Rigid2D;

RungeKutta4RigidBodySolver::RungeKutta4RigidBodySolver(unsigned int dimension, Real step, DerivFunction dxdt, void* optionalData)
    : OdeSolver(dimension, step, 0), rigidBodySystem_((RigidBodySystem*)rbSystem) {

}
