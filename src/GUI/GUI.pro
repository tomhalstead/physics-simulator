#-------------------------------------------------
#
# Project created by QtCreator 2014-11-18T14:36:56
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glPhysicsScene.cpp \
    glSystem.cpp \
    glPointMass.cpp \
    glCamera.cpp

INCLUDEPATH += ../../include/

HEADERS  += mainwindow.h \
    ../../include/Collection.h \
    ../../include/CollectionIterators.h \
    ../../include/CollisionEngine.h \
    ../../include/Connection.h \
    ../../include/PhysicsEngine.h \
    ../../include/Vector.h \
    ../../include/Vector2D.h \
    ../../include/Vector3D.h \
    ../../include/Vectors.h \
    glPhysicsScene.h \
    glSystem.h \
    glPointMass.h \
    ../../include/PointMass.h \
    glCamera.h

FORMS    += mainwindow.ui
