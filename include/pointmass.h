#ifndef POINTMASS_H
#define POINTMASS_H



#include "Vectors.h"

namespace PhysicsEngine {
    template <typename PointType = double, typename MassType = double, typename TimeType = double>
    class PointMass
            // 'PointMass' objects are designed to model objects in the physics simulation. Since they have no geometry (shape)
            // data, they are intended to be inherited from, so that PointMass objects of different shapes (i.e. spheres or cubes)
            // can be represented in the physics simulation.
            //
            // Should this class be made abstract, so that only children of this class can be instantiated?
    {
    public:
        PointMass(MassType newMass = 0,
                  const Vectors::Vector3D<PointType> &newPosition = Vectors::Vector3D<PointType>(0.),
                  const Vectors::Vector3D<PointType> &newVelocity = Vectors::Vector3D<PointType>(0.));
        PointMass(const Vectors::Vector3D<PointType>& newPosition);

        PointMass(const PointMass<PointType> &other);
        virtual ~PointMass();

        void setPosition(const Vectors::Vector3D<PointType> &newPosition);
        void setVelocity(const Vectors::Vector3D<PointType> &newVelocity);
        void setMass(MassType newMass);
        void setNetForce(const Vectors::Vector3D<PointType> &newNetForce);
        void addForce(const Vectors::Vector3D<PointType> &extraForce);

        const Vectors::Vector3D<PointType>& getPosition() const;
        const Vectors::Vector3D<PointType>& getVelocity() const;
        const Vectors::Vector3D<PointType>& getNetForce() const;
        MassType getMass() const;

        Vectors::Vector3D<PointType> getTrajectory(TimeType time) const;
        // This function returns a 'Vector3D' representing the new position of the calling 'PointMass' object after
        // 'time' seconds, given a constant force ('netForce') applied over that time period.
        //
        // Perhaps should be called 'calculateTrajectory' to indicate that the returned object is not representing internal
        // data, but rather is computed every time the function is called. Perhaps should be called 'calculateNewPosition'
        // or 'calculateNextPosition' to more clearly show what is being represented by the returned value.

        void advance(TimeType time);
        // Updates position and velocity of the point mass to what they should be after having 'netForce' force
        // applied for 'time' seconds.

    private:
        Vectors::Vector3D<PointType> position;
        Vectors::Vector3D<PointType> velocity;
        Vectors::Vector3D<PointType> netForce;
        MassType mass;
    };
}
#endif // POINTMASS_H

