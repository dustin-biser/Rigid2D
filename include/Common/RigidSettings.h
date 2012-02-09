#ifndef RIGID_SETTINGS_H
#define RIGID_SETTINGS_H

// Uncomment next line to compile out asserts from all source files.
//#define NDEBUG
#include <cassert>

#ifndef NULL
#define NULL 0
#endif

// Place all global library settings and constants in this file.
namespace Rigid2D{
	
	typedef float Real;
	typedef double PreciseReal;

	const PreciseReal tau = 6.283185307;

	// Starting step size for the OdeSolver.
	const Real StartingStepSize = 0.01;


}

#endif
