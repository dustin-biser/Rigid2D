#include "RigidBody.h"

namespace Rigid2D {

  RigidBody::RigidBody(Vector2 &position, Vector2 &mass, Real *vertex_array, Vector2 &momentum)
  {
    position_ = position;
    mass_ = mass;
    vertex_array_ = vertex_array;
    momentum_ = momentum;
  }

  ~RigidBody::RigidBody() 
  {
    delete [] vertex_array_;
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

  Real RigidBody::getVertexCount() const
  {
    return vertex_count_;
  }

  Real* RigidBody::getVertexArray() const
  {
    return vertex_array_;
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


}
