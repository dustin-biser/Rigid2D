#include "RigidBody.h"
#include <cassert>
#include <cstring>

namespace Rigid2D {

  RigidBody::RigidBody(Vector2 position, Real mass, Real *vertex_array,
      int vertex_count, Vector2 velocity)
  {
    position_ = position;
    mass_ = mass;
    vertex_count_ = vertex_count;
    vertex_array_ = new Real[2 * vertex_count];
    memcpy(vertex_array_, vertex_array, 2 * vertex_count * sizeof(Real));
    momentum_ = mass * velocity;
    forceAccumulator_ = Vector2(0, 0);
  }

  RigidBody::~RigidBody()
  {
    delete vertex_array_;
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

  Real* RigidBody::getVertexArray() const
  {
    return vertex_array_;
  }

  void RigidBody::copyState(Real *sub_S) const
  {
    assert(sub_S != 0);

    sub_S[0] = position_.x;
    sub_S[1] = position_.y;
    sub_S[2] = momentum_.x;
    sub_S[3] = momentum_.y;
  }

  void RigidBody::copyStateDeriv(Real *sub_dSdt) const
  {
    assert(sub_dSdt != 0);

    sub_dSdt[0] = momentum_.x / mass_;
    sub_dSdt[1] = momentum_.y / mass_;
    sub_dSdt[2] = forceAccumulator_.x / mass_;
    sub_dSdt[3] = forceAccumulator_.y / mass_;
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
   
  void RigidBody::addToForceAccum(const Vector2 &force)
  {
    forceAccumulator_ += force;
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
