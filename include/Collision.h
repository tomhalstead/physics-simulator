#ifndef COLLISION_H
#define COLLISION_H

#include <vector>
#include "pointmass.h"
#include "iterator.h"

class Collision;
typedef void (*CRF)(Collision*);  //Collision Resolution Function - passed the collision object it created

class CBase  //base for CollisionEngine AND Connections - the basics needed for collision resolution
{
public:
	class Collision;
	CBase() {}
	~CBase() {}
	virtual void ResolveCollision(Collision* ResolveMe) {}  //this is how collisions get resolved
	virtual Collision* Detect(Iterator<PointMass>& PointMasses) {return NULL;} //returns a collision object if one needed - the soonest to occur collision
		//in the case of Connections, if the Connection is "connected" at t=0 then do not generate a collision, go ahead and modify the PointMasses involved.
};

class CBase::Collision  //base class for Collisions, each CollisionEngine or Connection can put whatever data in their child they need.
{
public:
	Collision(double TimeToCollision, CRF WhoResolvesMe=NULL); //in case of a Connection just set the TimeToCollision, CollisionEngines need to send CRF and set PMinvolved
	void Resolve(); //send us back to our maker to resolve the collision - objects will be advanced to collision time beforehand.
	bool operator < (const Collision& Rhs)const; //used in sorting
	bool operator > (const Collision& Rhs)const;
	
	double timeToCollision;  //as it says
	std::vector<PointMass*> pmInvolved; //the dynamic array that holds the PointMass pointers
private:
	CRF whoResolvesMe; //function pointer
};

#endif // COLLISION_H
