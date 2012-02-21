#include "RigidBody.h"
#include <cassert>
#include <cstring>

namespace Rigid2D {

  RigidBody::RigidBody(Vector2 position, Real mass, Real *vertex_array,
      int vertex_count, Vector2 velocity)
    : position_(position),
      velocity_(velocity),
      momentum_(velocity*mass),
      mass_(mass),
      vertex_count_(vertex_count)
  {
    vertex_array_ = new Real[2 * vertex_count];
    memcpy(vertex_array_, vertex_array, 2 * vertex_count * sizeof(Real));
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

  Vector2 RigidBody::getVelocity() const
  {
    return velocity_;
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

  void RigidBody::getState(Real *dst) const
  {
    assert(dst != NULL);

    dst[0] = position_.x;
    dst[1] = position_.y;
    dst[2] = mass_ * velocity_.x;
    dst[3] = mass_ * velocity_.y;
  }

	void RigidBody::setState(Real *source){
		assert(source != NULL);

		position_.x = source[0];
		position_.y = source[1];
		momentum_.x = source[2];
		momentum_.y = source[3];
	}

  void RigidBody::getStateDeriv(Real *dst) const
  {
    assert(dst != NULL);

    dst[0] = velocity_.x;
    dst[1] = velocity_.y;
    dst[2] = forceAccumulator_.x;
    dst[3] = forceAccumulator_.y;
  }

  void RigidBody::setPosition(const Vector2 & position)
  {
    position_ = position;
  }

  void RigidBody::setPosition (Real xPos, Real yPos)
  {
    position_.x = xPos;
    position_.y = yPos;
  }

  void RigidBody::setVelocity(const Vector2 & velocity)
  {
    velocity_ = velocity;
    momentum_ = velocity_ * mass_;
  }

  void RigidBody::setVelocity (Real xComponent, Real yComponent)
  {
    velocity_.x = xComponent;
    velocity_.y = yComponent;

    momentum_ = velocity_ * mass_;
  }

  void RigidBody::setMass(const Real &mass)
  {
    mass_ = mass;
    momentum_ = mass_ * velocity_;
  }

  void RigidBody::addToForceAccum(const Vector2 &force)
  {
    forceAccumulator_ += force;
  }

  void RigidBody::zeroForceAccum()
  {
    forceAccumulator_.x = 0;
    forceAccumulator_.y = 0;

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
