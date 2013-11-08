#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>

#include "Vectors.h"
#include "PointMass.h"
#include "CollisionEngine.h"
#include "Connection.h"

typedef Vector3D<double> (*PairForce)(PointMass*,PointMass*);
typedef void (*BaseForce)(PointMass*);

template <class T>
class Iterator      //put outside PhysicsEngine class so it can be used outside the class to navigate objects held within.
{
	friend class PhysicsEngine;
	Iterator();
	Iterator(Iterator<T>& CopyThis)
	void Add(T AddThis);
	void Remove(T RemoveThis);
	T operator = (Iterator<T>& Rhs);
	T operator [] (int Element); //set to Element'th object, if out of range we return NULL
	T operator ++ ();    //returns Null if moved past last element
	T operator ++ (int);
	T operator -- ();    //returns Null if moved before first element
	T operator -- (int);
	T First();
	T Last();
	operator T();  //returns a pointer to the currently selected object
private:
	std::vector<T>* myObject;
	std::vector<T>::iterator i;
	void setmyObject(std::vector<T>* MyObject);
};


class PhysicsEngine
{
public:
	PhysicsEngine();  //must be loaded with objects and functions after initialization
	void Advance(double TimeSlice);
	void SetBaseForce(BaseForce* BaseForceFunction);

	Iterator<PointMass*> PointMasses;
	Iterator<Connection*> Connections;
	Iterator<PairForce*> PairForces;
	Iterator<CollisionEngine*> CollisionEngines;
	Iterator<Collision*> Collisions;

 private:
	std::vector<PointMass*> pointMasses;
	std::vector<Connection*> connections;
	std::vector<PairForce*> pairForces; 
	std::vector<CollisionEngine*> collisionEngines;
	std::vector<Collision*> collisions;
	BaseForce* baseForceFunction;
	double timeSlice;

	//CollisionEngine* CurrCollisionEngine;   //will we ever have more than one collision engine running at once?
	//I contend we don't *IF* connections return a Collision* - which would be more efficient
	
//private functions
	void updatePairForces();
	void updateConnections();
	void findCollisions();
	void resolveCollisions(); //advanceing time frame to the first collision, resolving it, then advancing to the next...
	void movePointMasses(double timeToAdvance); //used by resolveCollisions() to advance the time frame
};



#endif // PHYSICSENGINE_H

/*
//Vector<double> UniversalGravityForce(PointMass* mass1, PointMass* mass2);
PhysicsEngine e;
e.AddForce(&UniversalGravityForce);

vector<double> gforce;
PointMass* mass1,mass2;
PairForce force;
gforce = (*force)(mass1,mass2);
*/


