#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "PointMass.h"
#include ".\Vector.h"
#

typedef vector<double> (*ForceFunction)(PointMass*,PointMass*);

vector<double> UniversalGravityForce(PointMass* mass1, PointMass* mass2);


class PhysicsEngine
{
public:
    PhysicsEngine();
    void AddForce(ForceFunction force);

    vector<double> gforce;
    PointMass* mass1,mass2;
    ForceFunction force;
    gforce = (*force)(mass1,mass2);
};

PhysicsEngine e;
e.AddForce(&UniversalGravityForce);

#endif // PHYSICSENGINE_H


