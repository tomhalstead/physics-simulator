#ifndef GLPOINTMASS_H
#define GLPOINTMASS_H

#include "PointMass.h"
#include <GL/glu.h>

typedef Vectors::Vector3D<GLfloat> glVector3D;

class glPointMass: public PhysicsEngine::PointMass<GLfloat>
{
public:
    glPointMass(GLfloat newMass = 0,
              const glVector3D &newPosition = glVector3D(),
              const glVector3D &newVelocity = glVector3D());
    glPointMass(const glVector3D &newPosition);

    glPointMass(const glPointMass &other);
    virtual ~glPointMass();

    virtual void draw();

};

#endif // GLPOINTMASS_H
