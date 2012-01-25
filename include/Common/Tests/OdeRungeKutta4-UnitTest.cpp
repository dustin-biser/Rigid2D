#include "gtest/gtest.h"
#include "OdeRungeKutta4.h"
#include "RigidSettings.h"
#include "ForceFunctions.h"
#include "feq.h"

using namespace Rigid2D;

class OdeRungeKutta4Test : public ::testing::Test {
  protected:
    OdeRungeKutta4 * solver;
    Real stepSize;

    virtual void SetUp(){
      int systemDimension = 2;
      stepSize = 0.1;
      OdeSolver::Function function = springForce;

      solver = new OdeRungeKutta4 (systemDimension, stepSize, function);
    }

    virtual void TearDown(){
      delete solver;
    }

};

TEST_F(OdeRungeKutta4Test, StepSize){
  EXPECT_TRUE ( feq(stepSize, solver->stepSize()) );
}

TEST_F(OdeRungeKutta4Test, SetStepSize){
  solver->SetStepSize(0.2);
  EXPECT_FLOAT_EQ ( 0.2, solver->stepSize() );
}

// Test first step to the solution x'' = -w^2*x, where w = 2 and initial
// conditions are x(0) = 0.1, x'(0) = 0.  Transform 2nd order equation into
// a system of two first order equations dy/dt = f(t,y) where y and f are
// 2-dimensional vectors.
TEST_F(OdeRungeKutta4Test, SimpleHarmonicMotion_1Step){
  Real x[2] = {0.1, 0};
  Real t = 0.0;

  solver->ProcessNextStep(t, x);
  EXPECT_FLOAT_EQ ( 0.1, t);
  EXPECT_FLOAT_EQ ( 0.098006666, x[0]);
  EXPECT_FLOAT_EQ (-0.039733335, x[1]);
}
