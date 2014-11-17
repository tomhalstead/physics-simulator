#ifndef POINTMASS_H
#define POINTMASS_H



#include "Vectors.h"

namespace PhysicsEngine {
    template <typename T = double>
    class PointMass
            // 'PointMass' objects are designed to model objects in the physics simulation. Since they have no geometry (shape)
            // data, they are intended to be inherited from, so that PointMass objects of different shapes (i.e. spheres or cubes)
            // can be represented in the physics simulation.
            //
            // Should this class be made abstract, so that only children of this class can be instantiated?
    {
    public:
        PointMass(T newMass = 0,
                  const Vectors::Vector3D<T> &newPosition = Vectors::Vector3D<T>(),
                  const Vectors::Vector3D<T> &newVelocity = Vectors::Vector3D<T>());
        PointMass(const Vectors::Vector3D<T>& newPosition);

        PointMass(const PointMass<T> &other);
        virtual ~PointMass();

        void setPosition(const Vectors::Vector3D<T> &newPosition);
        void setVelocity(const Vectors::Vector3D<T> &newVelocity);
        void setMass(T newMass);
        void setNetForce(const Vectors::Vector3D<T> &newNetForce);
        void addForce(const Vectors::Vector3D<T> &extraForce);

        const Vectors::Vector3D<T>& getPosition() const;
        const Vectors::Vector3D<T>& getVelocity() const;
        const Vectors::Vector3D<T>& getNetForce() const;
        T getMass() const;

        Vectors::Vector3D<T> getDisplacement(T time) const;
        // Returns the final position of the point mass if it were to travel for 'time' units of time.

        void advance(T time);
        // Changes the position of the point mass by applying net force and velocity for 'time' units of time.

    private:
        Vectors::Vector3D<T> position;
        Vectors::Vector3D<T> velocity;
        Vectors::Vector3D<T> netForce;
        T mass;
    };
}
#endif // POINTMASS_H

