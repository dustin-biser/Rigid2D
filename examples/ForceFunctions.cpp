#include "ForceFunctions.h"
#include <cassert>

/**
 * Using the following damped spring force equation:
 * f = -[ks*norm(l) + kd*(l_dot*l)/norm(l)]*l/norm(l)
 *
 * f: vector representing force applied to center of mass of RigidBody
 *
 * l: vector representing distance between center of mass of RigidBody and mouse
 * position
 *
 * l_dot: vector representing differnce between velocity of center of mass of
 * RigidBody and velocity of mouse.  Assumes mouse is stationary for the
 * purposes of computing force.
 *
 * norm(l): length of vector l
 *
 * ks: spring force constant
 *
 * kd: damping constant
 *
*/
void mouseSpringForce(RigidBody * const rigidBody, Vector2 * dst, void * userData){
  assert(rigidBody != NULL);
  assert(dst != NULL);
  assert(userData != NULL);

  Vector2 mousePos ( ((Real*)userData)[0], ((Real*)userData)[1] );         // Store mouse coordinants
  Vector2 centerOfMassPos = rigidBody->getPosition(); // Center of mass of RigidBody
  Real ks = ((Real*)userData)[2];                        // Spring constant
  Real kd = ((Real*)userData)[3];                        // Damping constant

  // l; Distance between the RigidBody's center of mass, and mouse coordinates
  Vector2 deltaPosition(centerOfMassPos.x - mousePos.x,
      centerOfMassPos.y - mousePos.y);

  // l_dot; Assume mouse is not moving, and only factor-in velocity of RigidBody's center of mass.
  Vector2 deltaVelocity(rigidBody->getVelocity());

  // <l_dot, l> / norm(l)^2
  // l: deltaPosition
  // l_dot: deltaVelocity
  Real kdFactor = deltaVelocity.dot(deltaPosition) / deltaPosition.getLengthSquared();

  // Store computed force values
  dst->x = (ks + kd*kdFactor)*(-deltaPosition.x);  // x component of force
  dst->y = (ks + kd*kdFactor)*(-deltaPosition.y);  // y component of force
}
