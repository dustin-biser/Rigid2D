#include "ForceFunctions.h"
#include <cassert>

using Rigid2D::Real;

// 2-dim system dx/dt = f(t,x) describing oscialling mass on a spring
// with angular frequency w = 2.  In one-dim it is x'' = -w^2*x.  The vector x
// has elements x[0] = x(t), x[1] = v(t).
void Rigid2D::springForce(Real, const Real* xValue, Real* fValue){
	assert(fValue != 0);
	assert(xValue != 0);

	fValue[0] = xValue[1];
	fValue[1] = -4*xValue[0];
}

