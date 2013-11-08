#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>

#include ".\Vectors.h"
#include ".\PointMass.h"
#include ".\CollisionEngine.h"
#include ".\Connection.h"


typedef Vector3D<double> (*PairForce)(PointMass*,PointMass*);


//Vector<double> UniversalGravityForce(PointMass* mass1, PointMass* mass2);


class PhysicsEngine
{
public:
	PhysicsEngine() {}  //must be loaded after initialization

	void Advance(double TimeSlice);

	/*
	void SetBaseForce(Vector3D<double>* BaseForce);

	void AddPointMass(PointMass* AddThis);
	void RemovePointMass(PointMass* RemoveThis);

	void AddForce(PairForce* AddThis);
	void RemoveForce(PairForce* RemoveThis);

	void AddConnection(Connection* AddThis);
	void RemoveConnection(Connection* RemoveThis);

	void AddCollisionEngine(CollisionEngine* AddThis);
	void RemoveCollisionEngine(CollisionEngine* RemoveThis);
	*/

	std::vector<PointMass*> pointMasses;
	std::vector<Connection*> conections;
	std::vector<Collision*> collisions;
	std::vector<PairForce*> pairForces; 
	std::vector<CollisionEngine*> collisionEngines;
	//PairForce* PairForce;   //for now one (Universal Gravitation) will suffice
	//CollisionEngine* CurrCollisionEngine;   //will we ever have more than one collision engine running at once?
	Vector3D<double> baseForce;
 private:
	double timeSlice;
//functions
	void updateForces();
	void findCollisions();
	void resolveCollisions(); //advanceing time frame to the first collision, resolving it, then advancing to the next...

	void movePointMasses(double timeToAdvance); //used by resolveCollisions() to advance the time frame
};


/*
PhysicsEngine e;
e.AddForce(&UniversalGravityForce);

vector<double> gforce;
PointMass* mass1,mass2;
PairForce force;
gforce = (*force)(mass1,mass2);
*/

#endif // PHYSICSENGINE_H
