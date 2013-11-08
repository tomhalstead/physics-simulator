#ifndef POINTMASS_H
#define POINTMASS_H
#include "Vectors.h"


class PointMass
{
public:
    PointMass(double M=0, const Vector3D<double>& pos = Vector3D<double>({0,0,0}), const Vector3D<double>& velocity=Vector3D<double>({0,0,0}));//
    ~PointMass();//
    PointMass(const PointMass& A);//
    void setMass(double M);//
    void setVelocity(const Vector3D<double>& velocity);//
    void Move(const Vector3D<double>& Pos);//
    double getMass() const;//
    Vector3D<double>& getVelocity() const;//
    Vector3D<double>& Position() const;//
    Vector3D<double>& CalculateTrajectory(float time);//
    Vector3D<double>&Advance(float time);//
    Vector3D<double>& getTrajectory() const;//
    void ApplyForce(const Vector3D<double>& extra);//
    Vector3D<double>& NetForce() const;//
    void setForce(const Vector3D<double>& newForce);//
private:

};

#endif // POINTMASS_H

