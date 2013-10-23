#ifndef COLLISIONENGINE_H
#define COLLISIONENGINE_H
#include "PointMass.h"




typedef double (*PairCollision)(PointMass*,PointMass*);
typedef double (*Collision)(void);

class CollisionEngine
{
public:
    CollisionEngine();

    float t;
    PointMass* A;
    PointMass* B;
private:
    struct Collision {
        double time;
        PointMass* a;
        PointMass* b;
        bool operator<(const Collision& RHS);
        bool operator>(const Collision& RHS);
    };
};

#endif // COLLISIONENGINE_H
