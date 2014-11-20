#ifndef GLCAMERA_H
#define GLCAMERA_H

#include <GL/gl.h>
#include "vectors.h"

typedef Vectors::Vector3D<GLfloat> glVector3D;

class glCamera
{
public:
    glCamera();
    void Transform() const;
    void Rotate(GLfloat x, GLfloat y, GLfloat z);
    void Rotate(glVector3D xyz);
    void RotateX(GLfloat x);
    void RotateY(GLfloat y);
    void RotateZ(GLfloat z);
    void Translate(GLfloat x, GLfloat y, GLfloat z);
    void Translate(glVector3D xyz);
    void TranslateX(GLfloat x);
    void TranslateY(GLfloat y);
    void TranslateZ(GLfloat z);
private:
    glVector3D translation, rotation;
};

#endif // GLCAMERA_H
