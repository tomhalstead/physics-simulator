#ifndef POINTMASS_H
#define POINTMASS_H
#include "Vectors.h"


class PointMass
{
public:
    PointMass();
    PointMass(double M); // take only mass and set position to (0,0,0)
    PointMass(const Vector3D<double>& pos);
    PointMass(const Vector3D<double>& velocity);
    PointMass(double M, const Vector3D<double>& pos, const Vector3D<double>& velocity);
    ~PointMass();
    PointMass(const PointMass& A);
    void setMass(double M); //
    void setVelocity(const Vector3D<double>& velocity);// take a double type vector and set as the the velocity
    void Move(const Vector3D<double>& Pos);// change the position, get a new position;
    double getMass() const;// return the mass of the Masspoint
    Vector3D<double>& getVelocity() const;// return velocity of the pointmass in a vector
    Vector3D<double>& Position() const;// return position of the Pointmass in a vector
    Vector3D<double>& CalculateTrajectory(float time);// calculate the pass in a specific time; calculate the collision between different Pointmasses
    Vector3D<double>&Advance(float time);//  ???
    Vector3D<double>& getTrajectory() const;// return the pass in a vector
    void ApplyForce(const Vector3D<double>& extra);// put a extra force on PointMass;
    Vector3D<double>& NetForce() const;// return the NetForce which relate from other PointMasses
    void setForce(const Vector3D<double>& newForce);// set a new force on the Pointmasses.
private:

};

#endif // POINTMASS_H

