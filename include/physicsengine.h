#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>

#include "Vectors.h"
#include "PointMass.h"
#include "CollisionEngine.h"
#include "Connection.h"

typedef Vector3D<double> (*PairForce)(PointMass*,PointMass*);
typedef void (*BaseForce)(PointMass*);

//put outside PhysicsEngine class so outside the class there can be instances of this to navigate objects held within.
template <class T>  
class Iterator       //built for vectors filled with pointers 
{
	friend class PhysicsEngine;
	Iterator();
	Iterator(Iterator<T>& CopyThis)
	Iterator(std::vector<T>& Myvector);
	void SetMyvector(std::vector<T>& Myvector);
	void Add(T& AddThis);
	T Remove(T& RemoveThis);
	T Remove(Iterator<T>& RemoveThis);
	void Delete(T& DeleteThis);
	void Delete(Iterator<T>& DeleteThis);
	T operator = (Iterator<T>& Rhs);  //set to the same as another Iterator (of same type)
	T operator [] (int Element); //returns the Element'th element without changing our internal pointer, if out of range we return NULL
	T operator ++ ();    //returns Null if moved past last element (this is true everywhere)
	T operator ++ (int);
	T operator -- ();    //returns Null if moved before first element (this is true everywhere)
	T operator -- (int);
	T operator += (int Rhs);
	T operator -= (int Rhs);
	T operator + (int Rhs);
	T operator - (int Rhs);
	T First();  //set to first element
	T Last();  //set to last element
	T Item(int Element); //sets our internal pointer to the passed element
	operator T();  //returns the currently selected element or NULL if out of range
private:
	std::vector<T>* myvector;
	int i; 
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


