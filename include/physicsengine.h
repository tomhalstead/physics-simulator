#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>

#include "Vectors.h"
#include "CollisionEngine.h"
#include "Connection.h"

typedef Vector3D<double> (*PairForce)(PointMass*,PointMass*);
typedef void (*BaseForce)(PointMass*);

class PhysicsEngine
{
public:
	PhysicsEngine();  //must be loaded with objects and functions after initialization

	void Advance(double TimeSlice);  //advance a sent time slice recalculating forces, trajectory and resolving any collisions
	void SetBaseForce(BaseForce BaseForceFunction); //set the function that sets the base force in our system
	void SetCollisionEngine(CollisionEngine* CollisionEngineObj); //set the collision engine (class) we use

	template <class T> Iterator<PointMass> PointMasses;  //look at Iterator class declarations for how to use these Iterators
	template <class T> Iterator<Connection> Connections;
	template <class T> Iterator<PairForce> PairForces;

 private:
	std::vector<PointMass*> pointMasses;  //our dynamic arrays of pointers
	std::vector<Connection*> connections;
	std::vector<PairForce> pairForces;


	Collision* firstCollision;  //the first collision that happens
	CollisionEngine* collisionEngine;  //the engine we use
	BaseForce baseForceFunction;  //the base force function we use
	double timeSlice;  //the timeslice we work through
	
//private functions used in Advance()
	void updatePairForces();
	void updateConnections();
	void findCollisions();
	void resolveCollisions(); //advanceing time frame to the first collision, resolving it, then advancing to the next...
	void movePointMasses(double timeToAdvance); //used by resolveCollisions() to advance the time frame to the next collision
};



#endif // PHYSICSENGINE_H