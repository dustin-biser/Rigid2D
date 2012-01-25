#include "gnuplot_i.hpp"
#include "RigidSettings.h"
#include "OdeRungeKutta4.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using namespace Rigid2D;


#define TAU 6.2831853071
#define STEP_SIZE 0.01

// 2-dim system dx/dt = f(t,x) describing oscialling mass on a spring
// with angular frequency w = 2.  In one-dim it is x'' = -w^2*x.  The vector x
// has elements x[0] = x(t), x[1] = v(t).
void f(Real, const Real* xValue, Real* fValue){
	assert(fValue != 0);
	assert(xValue != 0);

	fValue[0] = xValue[1];
	fValue[1] = -4*xValue[0];
}

void wait_for_key(){
  cout << endl << "Press ENTER to continue..." << endl;

  cin.clear();
  cin.ignore(cin.rdbuf()->in_avail());
  cin.get();
  return;
}

int main(){
  Gnuplot g1("lines");
	g1.cmd("set terminal wx");
	g1.set_yrange(-2.0/10.0, 2.0/10.0);
	g1.set_title("4th order Runge-Kutta Method");
	g1.plot_equation("1.0/10.0*cos(2*x)","(1/10)cos(2*x)");

  vector<double> vecX;  // Store position values x[0] of state vector
  vector<double> vecTime;  // Store time values
	vector<double>::iterator iterateX = vecX.begin();
	vector<double>::iterator iterateT = vecTime.begin();

  Real stateVector[] = {1.0/10.0, 0.0}; // Initial conditions

  OdeRungeKutta4 * solver = new OdeRungeKutta4(2, STEP_SIZE, f);

  // Insert initial values into corresponding vectors
  iterateX = vecX.insert(iterateX, stateVector[0]);
  iterateT = vecTime.insert(iterateT, 0.0);	

	for(Real t = 0; t <= 2*TAU;){
    // Update t and stateVector with new values
    solver->ProcessNextStep(t, stateVector);
    iterateX = vecX.insert(iterateX, stateVector[0]);
    iterateT = vecTime.insert(iterateT, t);	
	}

  g1.plot_xy(vecTime, vecX, "RungeKutta4");

  wait_for_key();

  delete solver;

  return 0;
	g1.cmd("set pointsize 10");
}
