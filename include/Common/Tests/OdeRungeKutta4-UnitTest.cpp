#include "gtest/gtest.h"
#include "OdeRungeKutta4.h"
#include "RigidSettings.h"
#include "ForceFunctions.h"
#include "feq.h"

using namespace Rigid2D;

TEST(OdeRungeKutta4Test, GetStepSize){
  Real x[2] = {1.0/10.0, 0.0/0.0};
  Real stepSize = 0.1;
  OdeRungeKutta4 solver(2, x, springForce, stepSize);

  EXPECT_TRUE( feq(stepSize, solver.stepSize()) );
}

//TEST(OdeRungeKutta4Test, SetStepSize){
  //Real x[2] = {1.0/10.0, 0.0/0.0};
  //Real stepSize = 0.1;
  //OdeRungeKutta4 solver(2, x, springForce, stepSize);
  //solver.SetStepSize(0.2);

  //EXPECT_TRUE( feq(0.2, solver.stepSize()) );
//}
