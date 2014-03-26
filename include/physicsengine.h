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
    void SetBaseForce(BaseForce BaseForceFunction); //set the function that sets the base force in our system
    void SetPairForce(PairForce PairForceFunction); // set Function that calculates the force between a pair of PointMasses
    void SetCollisionEngine(CollisionEngine* CollisionEngineObj); //set the collision engine (class) we use

    Iterator<PointMass> PointMasses;  //look at Iterator class declaration for how to use these
    Iterator<Connection> Connections;
    Iterator<Collision> Collisions;

 private:
    std::vector<PointMass*> pointMasses;  //our dynamic arrays of object pointers
    std::vector<Connection*> connections;
    std::vector<Collision*> collisions;

    CollisionEngine* collisionEngine;  //the engine we use
    PairForce pairForces; // The pair force function
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
