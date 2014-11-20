#ifndef GLPHYSICSSCENE_H
#define GLPHYSICSSCENE_H

#include <QGLWidget>
#include "glSystem.h"
#include "glCamera.h"

class glPhysicsScene : public QGLWidget
{
    Q_OBJECT
public:
    explicit glPhysicsScene(QWidget *parent = 0);
    virtual ~glPhysicsScene();
    void Start();
    void Stop();
protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void paintGL();
    virtual void resizeGL(int w, int h);
private:
    virtual void initializeGL();
    QTimer *calcTimer, *drawTimer;
    float glWidth, glHeight;
    glCamera camera;
    glSystem system;
signals:
public slots:
    virtual void updateGL();
};

#endif // GLPHYSICSSCENE_H
