#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>

#include "Vectors.h"
#include "PointMass.h"
#include "CollisionEngine.h"
#include "Connection.h"

typedef Vector3D<double> (*PairForce)(PointMass*,PointMass*);
typedef void (*BaseForce)(PointMass*);

class PhysicsEngine
{
public:
	PhysicsEngine();  //must be loaded with objects and functions after initialization
	template <class T> class Iterator;

	void Advance(double TimeSlice);  //advance a sent time slice recalculating forces, trajectory and resolving any collisions
	void SetBaseForce(BaseForce* BaseForceFunction); //set the function that sets the base force in our system
	void SetCollisionEngine(CollisionEngine* CollisionEngineObj); //set the collision engine (class) we use

	template <class T> Iterator<PointMass> PointMasses;  //look at Iterator class declaration for how to use these
	template <class T> Iterator<Connection> Connections;
	template <class T> Iterator<PairForce> PairForces;
	template <class T> Iterator<Collision> Collisions;

 private:
	std::vector<PointMass*> pointMasses;  //our dynamic arrays of object pointers
	std::vector<Connection*> connections;
	std::vector<PairForce*> pairForces; 
	std::vector<Collision*> collisions;

	CollisionEngine* collisionEngine;  //the engine we use
	BaseForce* baseForceFunction;  //the base force function we use
	double timeSlice;  //the timeslice we work through
	
//private functions used in Advance()
	void updatePairForces();
	void updateConnections();
	void findCollisions();
	void resolveCollisions(); //advanceing time frame to the first collision, resolving it, then advancing to the next...
	void movePointMasses(double timeToAdvance); //used by resolveCollisions() to advance the time frame to the first collision
};


template <class T>  
class PhysicsEngine::Iterator       //built for vectors filled with pointers 
{
	Iterator();
	Iterator(Iterator<T>& CopyThis);
	Iterator(std::vector<T>& Myvector);

//these add or remove items to our vector
	void Append(const T* AddThis); //append AddThis to the end of the vector  
	T* Remove(T* const RemoveThis) const;  //remove the object from our vector and return it - shifts the following elements to fill any "holes" (non-const objects, const pointers)
	T* Remove(Iterator<T>& RemoveThis) const;
	T* Remove(int Element) const;
	void Delete(T* const DeleteThis);   //remove the object and delete the memory allocation to it.
	void Delete(Iterator<T>& DeleteThis);
	void Delete(int Element);

//these access the object we hold - as the vector holds pointers a further dereference(*) is needed to access the actual object (the pointers returned are const, but the object they point to are not)
	T* operator * ()const;  //dereference to currently selected element - returns a pointer or NULL if out of range
	T* operator [] (int Element)const; //returns the Element'th element without changing our internal pointing, if out of range we return NULL

//these change the interal pointing of this iterator but do not modify the vector (if dereferenced, the items pointed to in returned pointers to can however be modified):
	Iterator<T>& operator = (const Iterator<T>& Rhs);  //set to the same as another Iterator (of same type) 
	Iterator<T>& SetTo(int Element); //sets our internal pointer to the number of passed element
	Iterator<T>& operator ++ ();    //increment our internal pointing
	Iterator<T> operator ++ (int);
	Iterator<T>& operator -- ();    //decrement our internal pointing
	Iterator<T> operator -- (int);
	Iterator<T>& operator += (int Rhs); //change our pointing by the int sent
	Iterator<T>& operator -= (int Rhs);

//these do not change the internal pointing of this Iterator , nor the vector itself (if derefrenced, the items pointed to in returned pointers to can however be modified):
	Iterator<T> operator + (int Rhs)const;  //returns
	Iterator<T> operator - (int Rhs)const;
	Iterator<T> First()const;  //returns a Iterator<t> set to first element 
	Iterator<T> Last()const;  //returns a Iterator<t> set to last element 

private:
	std::vector<T*>* myvector;
	int i; //never allowed to go below -1 or more than one past last last element(*myvector.size +1)
};


#endif // PHYSICSENGINE_H