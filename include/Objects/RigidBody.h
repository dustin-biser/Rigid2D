#ifndef RIGID2D_RIGID_BODY_H
#define RIGID2D_RIGID_BODY_H

#include "Common/RigidSettings.h"
#include "Common/MathUtils.h"
#include "Common/Vector2.h"

namespace Rigid2D
{
  class RigidBody
  {
    public:
      /* @vertex_array should be an array of tuples in the form of (x,y). It will get deep-copied
       * @vertex_count is the number of tuples, not the number of Reals. */
      RigidBody(Vector2 position, Real mass, Real *vertex_array, int vertex_count, Vector2 velocity);
      /* Deletes vertex_array_. */
      ~RigidBody();

      // returns position of center of mass for RigidBody
      Vector2 getPosition() const;

      Vector2 getVelocity() const;

      Vector2 getMomentum() const;

      Real getMass() const;

      int getVertexCount() const;

      Real* getVertexArray() const;

      //TODO Add comments
      void copyState(Real *sub_S) const;

      //TODO Add comments
      void copyStateDeriv(Real *sub_dsdt) const;

      void setPosition(const Vector2 & position);
      void setVelocity(const Vector2 & velocity);
      void setMass(const Real &);

      void addToForceAccum(const Vector2 &);

      /* Given a point in graphics coordinate space, this function returns true if
       * the point lies within the convex polygon defined by vertex_array_.*/
      bool pointIsInterior(Real x, Real y);

    protected:
      Vector2 position_;  // position of center of mass
      Vector2 velocity_;  // velocity of center of mass
      Vector2 forceAccumulator_;
      Real mass_;
      int vertex_count_;
      Real *vertex_array_;

  };
}

#endif
