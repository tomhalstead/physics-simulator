#ifndef POINTMASS_H
#define POINTMASS_H
#include "Vectors.h"


class PointMass
{
public:
    PointMass(Vector velocity, Vector pos, double M);
    ~PointMass();
    PointMass(const PointMass& A);
    void setMass(double M);
    void setVelocity(const Vector& velocity);
    void Move(const Vector& Pos);
    double getMass() const;
    Vector& getVelocity() const;
    Vector& Position() const;
    void Move(float time);
    void ApplyForce(const Vector& extra);
    Vector& NetForce() const;
    void SetForce(const Vector& newForce);
private:

};

#endif // POINTMASS_H
