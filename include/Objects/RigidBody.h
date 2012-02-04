#ifndef RIGID_RIGID_BODY_H
#define RIGID_RIGID_BODY_H

#include "RigidSettings.h"
#include "Common/MathUtils.h"
#include "Common/Vector2.h"

namespace Rigid2D
{
  class RigidBody
  {
    public:
      RigidBody(Vector2 position, Real mass, Real *vertex_array, int vertex_count, Vector2 momentum);
      ~RigidBody(){}
      Vector2 getPosition() const;
      Vector2 getMomentum() const;
      Real getMass() const;
      int getVertexCount() const;
      Real* getVertexArray();
      void getState(Real *sub_s, Real *sub_dsdt);

      void setPosition(const Vector2 &);
      void setMomentum(const Vector2 &);
      void setMass(const Real &);

      bool pointIsInterior(Real x, Real y);

    protected:
      Vector2 position_;
      Vector2 momentum_;
      Vector2 force_;
      Real mass_;
      int vertex_count_;
      Real *vertex_array_;

  };
}

#endif
