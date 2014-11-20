#ifndef GLSYSTEM_H
#define GLSYSTEM_H

#include "glPointMass.h"
#include "PhysicsEngine.h"

class glPhysicsScene;

class glSystem: public PhysicsEngine::System<GLfloat>
{
public:
    glSystem(glPhysicsScene *initParent = NULL, PhysicsEngine::CollisionHandler<GLfloat> *initHandler = NULL);
    virtual ~glSystem();
    virtual void draw();
private:
    virtual bool ItemAdded(Collection<GLfloat>* origin, const GLfloat &item);
    virtual bool ItemRemoved(Collection<GLfloat>* origin, const Collection_iterator<GLfloat>& position);
    glPhysicsScene* parent;
};

#endif // GLSYSTEM_H
