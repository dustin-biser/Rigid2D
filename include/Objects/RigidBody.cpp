#include "RigidBody.h"

namespace Rigid2D {

  RigidBody::RigidBody(Vector2 position, Real mass, Real *vertex_array,
      int vertex_count, Vector2 momentum)
  {
    position_ = position;
    mass_ = mass;
    vertex_count_ = vertex_count;
    vertex_array_ = vertex_array;
    momentum_ = momentum;
    force_ = Vector2(0, 0);
  }

  Vector2 RigidBody::getPosition() const
  {
    return position_;
  }

  Vector2 RigidBody::getMomentum() const
  {
    return momentum_;
  }

  Real RigidBody::getMass() const
  {
    return mass_;
  }

  int RigidBody::getVertexCount() const
  {
    return vertex_count_;
  }

  Real* RigidBody::getVertexArray()
  {
    return vertex_array_;
  }

  void RigidBody::getState(Real *sub_s, Real *sub_dsdt)
  {
    sub_s[0] = position_[0];
    sub_s[1] = position_[1];
    sub_s[2] = momentum_[0];
    sub_s[3] = momentum_[1];
    sub_dsdt[0] = momentum_[0] / mass_;
    sub_dsdt[1] = momentum_[1] / mass_;
    sub_dsdt[2] = force_[0] / mass_;
    sub_dsdt[3] = force_[1] / mass_;
  }

  void RigidBody::setPosition(const Vector2 &position)
  {
    position_ = position;
  }

  void RigidBody::setMomentum(const Vector2 &momentum)
  {
    momentum_ = momentum;
  }

  void RigidBody::setMass(const Real &mass)
  {
    mass_ = mass;
  }


  bool RigidBody::pointIsInterior(Real x, Real y)
  {
    // Go through all the edges calculating or2d(Mouse, pt1, pt2)
    Vector2 pt1, pt2, pt3;
    pt1.x = x;
    pt1.y = y;

    for (int i = 0; i < vertex_count_ - 1; i++)
    {
      pt2.x = vertex_array_[i*2];
      pt2.y = vertex_array_[i*2 + 1];
      pt3.x = vertex_array_[i*2 + 2];
      pt3.y = vertex_array_[i*2 + 3];
      if (or2d(pt1, pt2, pt3) != -1)
        return false;
    }
    // special check for last edge
    pt2.x = vertex_array_[2 * vertex_count_ - 2];
    pt2.y = vertex_array_[2 * vertex_count_ - 1];
    pt3.x = vertex_array_[0];
    pt3.y = vertex_array_[1];
    if (or2d(pt1, pt2, pt3) != -1)
      return false;
    return true;
  }
}
