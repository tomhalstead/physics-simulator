#ifndef POINTMASS_H
#define POINTMASS_H
#include "/Vector.h"


class PointMass
{
public:
    PointMass(Vec vel, Vec pos, double M);
    ~PointMass();
    PointMass(const PointMass& A);
    void setMass(double M);
    void setVel(const Vec& Vel);
    void Move(const Vec& Pos);
    double getMass() const;
    Vec getVel() const;
    Vec Position() const;
    void Move(float time);
    void ApplyForce(const Vec& extra);
    Vec NetForce() const;
    void Restore(const Vec& newForce);
private:

};

#endif // POINTMASS_H
