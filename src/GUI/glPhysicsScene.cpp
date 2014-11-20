#include "glPhysicsScene.h"

glPhysicsScene::glPhysicsScene(QWidget *parent) :
    QGLWidget(parent)
{


}

void glPhysicsScene::updateGL()
{
    paintGL();
}
