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
class PhysicsEngine::Iterator       //built for vectors filled with pointers 
{
	friend class PhysicsEngine;
	Iterator();
	Iterator(Iterator<T>& CopyThis)
	Iterator(std::vector<T>& Myvector);
	void Add(T* AddThis);
	T* Remove(T* RemoveThis);
	T* Remove(Iterator<T>& RemoveThis);
	void Delete(T* DeleteThis);
	void Delete(Iterator<T>& DeleteThis);
	T* operator = (Iterator<T>& Rhs);  //set to the same as another Iterator (of same type)
	T* operator [] (int Element); //returns the Element'th element without changing our internal pointer, if out of range we return NULL
	T* operator ++ ();    //returns Null if moved past last element (this is true everywhere)
	T* operator ++ (int);
	T* operator -- ();    //returns Null if moved before first element (this is true everywhere)
	T* operator -- (int);
	T* operator += (int Rhs);
	T* operator -= (int Rhs);
	T* operator + (int Rhs);
	T* operator - (int Rhs);
	T* First();  //set to first element
	T* Last();  //set to last element
	T* Item(int Element); //sets our internal pointer to the passed element
	operator T*();  //returns the currently selected element or NULL if out of range
private:
	std::vector<T*>* myvector;
	int i; 
};


class PhysicsEngine
{
public:
	PhysicsEngine();  //must be loaded with objects and functions after initialization
	void Advance(double TimeSlice);
	void SetBaseForce(BaseForce* BaseForceFunction);

	template <class T> class Iterator;

	template <class T> Iterator<PointMass> PointMasses;
	template <class T> Iterator<Connection> Connections;
	template <class T> Iterator<PairForce> PairForces;
	template <class T> Iterator<CollisionEngine> CollisionEngines;
	template <class T> Iterator<Collision> Collisions;

 private:
	std::vector<PointMass*> pointMasses;
	std::vector<Connection*> connections;
	std::vector<PairForce*> pairForces; 
	std::vector<Collision*> collisions;

	CollisionEngine* collisionEngine;
	BaseForce* baseForceFunction;
	double timeSlice;
	
//private functions
	void updatePairForces();
	void updateConnections();
	void findCollisions();
	void resolveCollisions(); //advanceing time frame to the first collision, resolving it, then advancing to the next...
	void movePointMasses(double timeToAdvance); //used by resolveCollisions() to advance the time frame
};



#endif // PHYSICSENGINE_H