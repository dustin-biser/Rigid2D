#ifndef RIGID_RIGID_BODY_H
#define RIGID_RIGID_BODY_H

#include "Common/Vector2.h"
#include "RigidSetting.h"

namespace Rigid2D
{
  class RigidBody
  {
    public:
      RigidBody(Vector2 &position, Real &mass, Real *vertex_array, Real &vertex_count, Vector2 &momentum);
      ~RigidBody();

      Vector2 getPosition() const;
      Vector2 getMomentum() const;
      Real getMass() const;
      Real getVertexCount() const;
      Real* getVertexArray() const;

      void setPosition(const Vector2 &);
      void setMomentum(const Vector2 &);
      void setMass(const Real &);

    protected:
      Vector2 position_;
      Vector2 momentum_;
      Real mass_;
      Real vertex_count_;
      Real *vertex_array_;

  };
}

#endif
