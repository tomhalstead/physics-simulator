#ifndef COLLISIONENGINE_H
#define COLLISIONENGINE_H


#include "pointmass.h"
#include "Collection.h"
namespace PhysicsEngine {

    template <typename T = double>
    class Collision;

    template <typename T = double>
    class CollisionHandler
    {
    public:
        CollisionHandler() {}
        virtual void ResolveCollision(Collision<T>& collision, Collection<PointMass<T>*>* container)=0; //Function which handles collision
        virtual std::vector< Collision<T> > DetectCollisions(const Collection<PointMass<T>*>& objects) const =0; //returns a vector of projected collisions
    };



    template <typename T>
    class Collision
    {
        friend class CollisionHandler<T>;
    public:
        void Resolve() { handler->ResolveCollision(*this,container); }
        bool operator < (const Collision& RHS)const;
        bool operator > (const Collision& RHS)const;
        std::vector<PointMass<T>*> PointMasses; //the dynamic array that holds the PointMass pointers
    private:
        Collision(T timeToCollision, CollisionHandler<T> initHandler, Collection<PointMass<T>*>* initContainer);
        CollisionHandler<T>* handler; //function pointer
        Collection<PointMass<T>*>* container;
        double timeToCollision;
    };
}

#endif // COLLISIONENGINE_H
