#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>

#include ".\Vectors.h"
#include ".\PointMass.h"
#include ".\CollisionEngine.h"
#include ".\Connection.h"


typedef Vector3D<double> (*ForceFunction)(PointMass*,PointMass*);


//Vector<double> UniversalGravityForce(PointMass* mass1, PointMass* mass2);


class PhysicsEngine
{
public:
    PhysicsEngine();
    void Advance(double TimeSlice);

    /*
    void AddForce(ForceFunction AddThis);
    void RemoveForce(ForceFunction RemoveThis);

    void AddConnection(Connection* AddThis);
    void RemoveConnection(Connection* RemoveThis);

    void AddPointMass(PointMass* AddThis);
    void RemovePointMass(PointMass* RemoveThis);

    void SetCollisionEngine(CollisionEngine* Engine);

    void SetBaseForece(Vector3D* BaseForce);
    */ 

    std::vector<PointMass> pointMasses;
    std::vector<Connection> conections;
    std::vector<Collision> collisions;
    //std::vector<ForceFunction> pairForces; this doesn't work - "use of a class template requires a template arguement list" how is that a template?
    ForceFunction* PairForce;   //for now one (Universal Gravitation) will suffice
    CollisionEngine* CurrCollisionEngine;   //will we ever have more than one collision engine running at once?
    Vector3D<double> baseForce;
private:
    double timeSlice;
};


/*
PhysicsEngine e;
e.AddForce(&UniversalGravityForce);

vector<double> gforce;
PointMass* mass1,mass2;
ForceFunction force;
gforce = (*force)(mass1,mass2);
*/

#endif // PHYSICSENGINE_H
