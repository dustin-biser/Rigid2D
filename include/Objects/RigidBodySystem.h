#ifndef RIGID2D_RIGID_BODY_SYSTEM_H
#define RIGID2D_RIGID_BODY_SYSTEM_H

#include "Common/RigidSettings.h"
#include "Common/OdeSolver.h"
#include "RigidBody.h"
#include "Force.h"

/*
 *  The system state array S_ is a collection of states for all Rigid Bodies known
 *  to the system.  S_ = (x_1, p_1, q_1, F_1,...,x_n, p_n, q_n, F_n), where for the
 *  i-th Rigid Body
 *  x_i, position of center of mass
 *  p_i, momentum
 *  q_i, orientation
 *  F_i, sum of forces acting on center of mass
 *
 *  After calling the RigidBodySystem constructor, a specific amount of memory will
 *  be allocated for S_.  It will always be the case that SLength_ >= systemDimension_,
 *  where SLength_ is the maximum number of entries that can be stored in S_, and
 *  systemDimension_ is equal to the number of RigidBodies times statesPerRigdiBody_,
 *  the number of states stored per RigidBody.  Currently, there are four states stored
 *  per RigidBody, specifically position x, momentum p, orientation q, and sum of forces F.
 *
 *  Whenever a user calls RigidBodySystem::addRigidBodies, systemDimension_ will be
 *  incremented by the number of RigidBodies times statesPerRigidBody_.  The OdeSolver
 *  will also be notified of the system dimension change, and will automatically take
 *  necassary actions to adjust for the new dimension size.  If adding RigidBodies to
 *  the system causes systemDimension to be greater than SLength_, then the size of S_
 *  will be realloced.
 */
namespace Rigid2D
{
  class RigidBodySystem
	{
    public:
      RigidBodySystem();
      ~RigidBodySystem();

      /** Uses OdeSolver to update state information for each RigidBody associated
       * with the current RigidBodySystem.
       */
      void update();

      /**
       * Tells RigidBodySystem to keep track of a RigidBody. If the body (pointer)
       * was previously added, it does not get added a second time.
       *
       * @param rigidBody pointer to a RigidBody object.
       * @see addRigidBodies()
       * @see removeRigidBody()
       * @see removeRigidBodies()
       */
      void addRigidBody(RigidBody * rigidBody);

      /**
       * Same as addRigidBody() but for multiple bodies.
       *
       * @param rigidBodyArray array of RigidBody object pointers.
       * @param numBodies length of rigidBodyArray.
       * @see addRigidBody()
       * @see removeRigidBody()
       * @see removeRigidBodies()
       */
      void addRigidBodies(RigidBody ** rigidBodyArray, unsigned int numBodies);

      /** Tells RigidBodySystem to not keep track of a RigidBody. If the body
       * (pointer) was not previously added, it does nothing.
       *
       * @param rigidBody pointer to a RigidBody object.
       * @see addRigidBody()
       * @see addRigidBodies()
       * @see removeRigidBodies()
       */
      void removeRigidBody(RigidBody * rigidBody);

      /**
       * Same as removeRigidBody() but for multiple bodies.
       *
       * @param rigidBodyArray array of RigidBody object pointers.
       * @param numBodies length of rigidBodyArray.
       * @see addRigidBody()
       * @see addRigidBodies()
       * @see removeRigidBody()
       */
      void removeRigidBodies (RigidBody **rigidBodyArray, unsigned int numBodies);

      /** Tells RigidBodySystem to apply the given force from here on out.
			 * If the force was already previously given, it does not apply it a
			 * second time.
       *
       * @param force pointer to a Force object.
       * @see addForces()
       * @see removeForce()
       * @see removeForces()
       */
      void addForce(Force *force);

      /** Same as addForce() but for multiple forces.
			 *
       * @param forces array of Force object pointers.
			 * @param numForces length of forces.
       * @see addForce()
       * @see removeForce()
       * @see removeForces()
       */
			void addForces(Force **forces, unsigned int numForces);

      /** Tells RigidBodySystem to remove the force from the list of forces
			 * being applied. If the force was not being applied, it does nothing.
       *
       * @param force pointer to a Force object.
       * @see addForces()
       * @see addForces()
       * @see removeForces()
       */
			void removeForce(Force *force);

      /** Same as removeForce() but for multiple forces.
			 *
       * @param forces array of Force object pointers.
			 * @param numForces length of forces.
       * @see addForce()
       * @see addForces()
       * @see removeForce()
       */
			void removeForces (Force **forces, unsigned int numForces);

      unsigned int getDimension();

      // Computes the derivative dS/dt, from the given inputs:
      // t - simulation time
      // S - system state array
      void computeStateDeriv(Real t, const Real * S, Real * dSdt);
    private:

      // Iterates through each RigidBody collecting state information and appending
			// it to S_
      void buildSystemStateArray();


      // TODO after demo1, change this to 4 states per RigidBody.
      // Loop through each RigidBody and build the state derivative array
      // dSdt = (p_1\m_1, F_1,..., p_n\m_n, F_n)
      void buildDerivStateArray(Real * dSdt);

      // Set the forceAccumulator field for each RigidBody in the system to zero.
      void clearForceAccumulators();

      // Update each RigidBody in this system with the state information contained in
      // the system state array S_.
      void updateRigidBodies();

      // Loop through all Force objects within forces_, calling their applyForce()
      // method.  This updates each RigidBody's forceAccumulator field
      // by the Force objects that are currently acting on those bodies.
      void applyAllForces();

      // To be called only from within initializeSAndSolver().  This is to make sure
      // SLength_ and the dimension of OdeSolver stay the same.
      //
      // Delete current OdeSolver if one has already been alocated, then allocate a
      // new OdeSolver and set its dimension to SLength_.
      void initializeSolver();

      // Allocates memory for the system state array S_, and OdeSolver solver_. Copies
      // all RigidBody state information into S_.  Makes call to initializeSolver() and
      // sets the dimension of OdeSolver to SLength_.  Each time initializeSAndSolver()
      // is called, the size of S_, the size of SLength_, and dimension of solver_ are
      // doubled.
      void initializeSAndSolver();

      unordered_set<RigidBody*> rigidBodies_;   // Collection of all tracked rigid bodies
      unordered_set<Force*> forces_;            // Collection of all forces
      Real * S_;                                // State array representing a collection of
                                                // all RigidBody state information.

      unsigned int SLength_;                    // Length of S_.

      Real time_;                               // Simulation clock
      OdeSolver *solver_;                       // Used to solve the system dS/dt = G(t,S)

      unsigned int systemDimension_;            // Dimension of the system.  This is the
                                                // number of RigidBodies times the number of
                                                // states per RigidBody.

      unsigned int statesPerRigidBody_;         // Number of states we store per Rigid Body.

      unsigned int allocationSize_;             // Keep track of how much memory to allocate when resizing S_.
                                                // Each time initializeSAndSolver() is called, allocationSize_
                                                // will be doubled.
	};

} // end namespace Rigid2D

#endif
