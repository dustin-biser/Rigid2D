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

			// Copies RigidBody state information, such as position, momentum,
			// orientation, and force accumulator, to the destination array dst.
      void getState(Real *dst) const;

			// Copies state information from source array, such as position, momentum,
			// orientation, and force accumulator, and stores within respective fields
			// for the current RigidBody.
			void setState(Real *source);

			// Builds the state derivative array dSdt from current RigidBody state
			// information and stores entries in destination array dst.
      void getStateDeriv(Real *dst) const;

      void setPosition (const Vector2 & position);

      void setPosition (Real xPos, Real yPos);

      void setVelocity (const Vector2 & velocity);

      void setVelocity (Real xComponent, Real yComponent);

      //void setMomentum (const Vector2 & momentum);

      //void setMomentum (Real xComponent, Real yComponent);

      void setMass(const Real &);

      void addToForceAccum(const Vector2 &);

      void zeroForceAccum();

      /* Given a point in graphics coordinate space, this function returns true if
       * the point lies within the convex polygon defined by vertex_array_.*/
      bool pointIsInterior(Real x, Real y);

    protected:
      Vector2 position_;          // Position of center of mass
      Vector2 velocity_;          // Velocity of center of mass
      Vector2 momentum_;          // Total momentum of RigidBody
      Vector2 forceAccumulator_;  // Sum of forces acting on the center of mass of RigidBody
      Real mass_;                 // Total mass
      int vertex_count_;
      Real *vertex_array_;

  };
}

#endif
