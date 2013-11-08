#ifndef POINTMASS_H
#define POINTMASS_H
#include "Vectors.h"


class PointMass
{
public:
    PointMass(const Vector3D<double>& velocity, const Vector3D<double>& pos, double M);
    ~PointMass();
    PointMass(const PointMass& A);
    void setMass(double M);
    void setVelocity(const Vector3D<double>& velocity);
    void Move(const Vector3D<double>& Pos);
    double getMass() const;
    Vector3D<double>& getVelocity() const;
    Vector3D<double>& Position() const;
    void Move(double TimeSlice); 
    void ApplyForce(const Vector3D<double>& extra);
    Vector3D<double>& NetForce() const;
    void SetForce(const Vector3D<double>& newForce);
	//need this added
	void CalculateVelocity(); //relculates velocity based on momentum and applied froce
private:
	
};

#endif // POINTMASS_H

