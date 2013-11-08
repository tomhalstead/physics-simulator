#include "physicsengine.h"
#include <algorithm>  // for sort

void PhysicsEngine::Advance(double TimeSlice)
{
	updateForces();
	//updateConnections();
	findCollisions();
	resolveCollisions();  
}


void PhysicsEngine::updateForces()
{
	std::vector<PointMass*>::iterator PM1, PM2,
		firstPM = pointMasses.begin(),  //i make these so we don't have to do a function call each time we check these
		endPM = pointMasses.end();
	std::vector<PairForce*>::iterator PF,
		firstPF = pairForces.begin(),
		endPF = pairForces.end();
	Vector3D<double> force;


	for (PM1 = firstPM; PM1 < endPM; ++PM1)
		(**PM1).SetForce(baseForce);   //set all PointMasses to the baseForce

	for (PM1 = firstPM; PM1 < endPM; ++PM1) //cycle through all point masses
	{
		for (PM2 = PM1 + 1; PM2 < endPM; ++PM2)  //cycle thrugh where pm1 is to the end
		{
			for (PF = firstPF; PF < endPF; ++PF)  //cycle through all the PairForces and apply these forces to the selected two PointMasses
			{
				force = (**PF)(*PM1,*PM2);
				(**PM1).ApplyForce(force);
				force *= -1;
				(**PM2).ApplyForce(force);
			}			
		}
	}
}

void PhysicsEngine::findCollisions()
{
	std::vector<PointMass*>::iterator PM1, PM2,
		firstPM = pointMasses.begin(),  //i make these so we don't have to do a function call each time we check these
		endPM = pointMasses.end();
	std::vector<CollisionEngine*>::iterator CF,
		firstCF = collisionEngines.begin(),
		endCF = collisionEngines.end();
	Collision* C;


	for (PM1 = firstPM; PM1 < endPM; ++PM1)
		(**PM1).CalculateVelocity();   //update velocity (by position and velocity we find trajectory)

	for (PM1 = firstPM; PM1 < endPM; ++PM1) //cycle through all point masses
	{
		for (PM2 = PM1 + 1; PM2 < endPM; ++PM2)  //from one after pm1 to the end
		{
			for (CF = firstCF; CF < endCF; ++CF)  //cycle through all the ColissionEngines and check for collisions for this pair
			{
				C = (**CF).Detect(*PM1,*PM2);
				collisions.push_back(C);  //add this collision to the list
			}			
		}
	}
	std::sort ( collisions.begin(),collisions.end() );   //sort by which happens first
}

void PhysicsEngine::resolveCollisions()
{
	std::vector<Collision*>::iterator 
		C = collisions.begin(),
		endC = collisions.end();

	for (;C < endC; ++C) //cycle through the list of collisions
	{
		movePointMasses( (**C).time );  //move all point masses to the point of first impact
		timeSlice -= (**C).time;   //subract this move from our timeslice

		//******issue here that needs to be resolved*********
		//need a way to set forces on the two point masses as a result of the collision (or delete one and change the other's mass)

		//then update velocity on these point masses
		//check for collisions again for these two PM's and all other objects

	}

	if (timeSlice)
		movePointMasses(timeSlice);

	collisions.clear();  //who deletes these objects?
}

void PhysicsEngine::movePointMasses(double timeToAdvance)
{
	std::vector<PointMass*>::iterator 
		PM = pointMasses.begin(),  
		endPM = pointMasses.end();
	for (;PM < endPM; ++PM)
		(**PM).Move(timeToAdvance);
}
