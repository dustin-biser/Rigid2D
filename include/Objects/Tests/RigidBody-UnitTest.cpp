#include "gtest/gtest.h"
#include "../RigidBody.h"
#include "Common/Vector2.h"
#include "RigidSettings.h"

using namespace Rigid2D;

TEST(RigidBodyTest, Construction){
  Vector2 position(0, 0);
  Real mass = 1.0;
  Real vertex_array[] = {0, 0, 2, 2, 0, 2};
  int vertex_count = 3;
  Vector2 momentum(0, 0);
  RigidBody r(position, mass, vertex_array, vertex_count, momentum);

  EXPECT_FLOAT_EQ(mass, r.getMass());
  EXPECT_TRUE(position == r.getPosition());
  EXPECT_TRUE(vertex_count == r.getVertexCount());
  EXPECT_TRUE(momentum == r.getMomentum());
}
