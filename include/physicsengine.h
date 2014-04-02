#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>

#include "Vectors.h"
#include "PointMass.h"
#include "PhysicsGui.h"
//#include "CollisionEngine.h"


class PhysicsEngine
// A 'PhysicsEngine' object, is a universe, that contains 'PointMass' objects or their descendents. The 'PhysicsEngine'
// object starts with no 'PointMass's. 'PointMass' objects are added with the addPointMass() function and can also be
// removed if needed. Each time the 'PhysicsEngine' advance() function is called, all the pointMasses are updated
// (particularly their positions and velocities) in accordance with the laws of physics (at this time just gravitational
// force). By default there is no collision detection or reaction to collisions. But if a collision engine is set,
// depending on the collision engine used, collisions can be detected and affect the properties of the 'PointMass' objects.
// In order for the 'PhysicsEngine' object to be able to send messages to a GUI object, a 'PhysicsGui' object can be
// set.
//
// A gravity field can be set for the physics engine, which applies to all 'PointMass' objects. The gravity field represents
// an acceleration applied to each object. Acceleration is used rather than force, so that all objects experience the same acceleration
// due to gravity from this force (like a baseball and bowling ball would near the surface of the earth).
{
public:
PhysicsEngine();

void setGravityField(const Vector3D<double> &newGravityField);

const Vector3D<double>& getGravityField();
// The gravity field is a universal acceleration due to gravity (represented by 'gravityField' internally).
// This acceleration is applied to all pointMasses.

void setCollisionEngine(CollisionEngine *newCollisionEngine);
// When calling the advance() function, the collision engine determines if collisions occur, and if they
// do, alters appropriate 'PointMass' data. Two examples of what the collision engine might do (depending
// on conditions and that particular collision engine's rules):
// 1) Change the velocity vectors of the colliding 'PointMass' objects according to conservation of momentum.
// 2) Combine the colliding 'PointMass' objects into a single 'PointMass' object with the combined mass of the
// first 2. Remove the first 2 from the 'pointMasses' vector and insert the new object to the 'pointMasses'
// vector. Give the new object a new velocity based on the original object's velocities according to
// conservation of momentum.
//
// The default behavior if no collision engine is set (i.e. 'collisionEngine' is NULL), is for no collision detection
// to occur, allowing pointMasses to move through eachother.
//
// This function takes a 'CollisionEngine' pointer as an argument, setting the pointed to collision engine as this
// 'PhysicsEngine''s collision engine. When a collision engine is set, the collision engine is given direct access to
// 'pointMasses' vector (in order to fulfill it's duties).

void setGui(PhysicsGui *newPhysicsGui);
// Setting the gui allows the physics engine to send messages to the GUI (such as when a problem occurs, or when
// a collision occurs, if such notifications are written).

const PointMass& operator[](unsigned int index) const;
// Returns a const reference to the 'PointMass' object at index 'index' in the 'pointMasses' vector. This function is
// read only access to the vector, allowing the GUI to display the point masses, or debugging code to show positions, etc.

void addPointMass(PointMass *newPointMass);
// Add a point mass to the universe / Physics Engine
PointMass* removePointMass(unsigned int index);
// Remove a point mass from the universe / Physics Engine. DOES NOT DELETE THE POINT MASS!!! Instead, returns a pointer
// to the removed point mass, just in case the caller of this function has to do something with the point mass before
// it is deleted. If you want the point mass to be deleted... call the deletePointMass() function.
void deletePointMass(unsigned int index);
// Deletes the point mass at index 'index' from the universe / physics engine.

void advance(double timeSlice);
// Updates all pointMass positions, velocities, forces etc; based on 'timeSlice' time elapsing

private:
std::vector<PointMass*> pointMasses;
Vector3D<double> gravityField;
CollisionEngine *collisionEngine;
PhysicsGui *physicsGui;
};




#endif // PHYSICSENGINE_H
