#ifndef POINTMASS_H
#define POINTMASS_H



#include "Vectors.h"

class PointMass
        // 'PointMass' objects are designed to model objects in the physics simulation. Since they have no geometry (shape)
        // data, they are intended to be inherited from, so that PointMass objects of different shapes (i.e. spheres or cubes)
        // can be represented in the physics simulation.
        //
        // Should this class be made abstract, so that only children of this class can be instantiated?
{
public:
    PointMass(double newMass = 0, const Vector3D<double> &newPosition = Vector3D<double>(0), const Vector3D<double> &newVelocity = Vector3D<double>(0));
    PointMass(const Vector3D<double>& newPosition);

    PointMass(const PointMass &other);
    virtual ~PointMass();
    // Do we want an assignment operator?? If not, do we really want to have copy constructor and destructor?

    void setPosition(const Vector3D<double> &newPosition);
    void setVelocity(const Vector3D<double> &newVelocity);
    void setMass(double newMass);
    void setNetForce(const Vector3D<double> &newNetForce);
    void addForce(const Vector3D<double> &extraForce);

    const Vector3D<double>& getPosition() const;
    const Vector3D<double>& getVelocity() const;
    double getMass() const;
    const Vector3D<double>& getNetForce() const;

    Vector3D<double> getTrajectory(double time) const;
    // This function returns a 'Vector3D' representing the new position of the calling 'PointMass' object after
    // 'time' seconds, given a constant force ('netForce') applied over that time period.
    //
    // Perhaps should be called 'calculateTrajectory' to indicate that the returned object is not representing internal
    // data, but rather is computed every time the function is called. Perhaps should be called 'calculateNewPosition'
    // or 'calculateNextPosition' to more clearly show what is being represented by the returned value.

    void advance(double time);
    // Updates position and velocity of the point mass to what they should be after having 'netForce' force
    // applied for 'time' seconds.

    virtual void draw();
    // In an OpenGL context, this function will draw the calling 'PointMass' object.
    //
    // Since this class is 'PointMass' and point masses have no geometry, this function perhaps should not be defined (or declared private)
    // since it is meaningless to draw() something that has no shape. However this function must exist so that children of this class
    // will behave properly when they are in 'PointMass' containers or pointed to by 'PointMass' pointers.

private:
    Vector3D<double> position;
    Vector3D<double> velocity;
    double mass;
    Vector3D<double> netForce;
};

#endif // POINTMASS_H

