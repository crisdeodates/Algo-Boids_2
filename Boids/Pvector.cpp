#include <string>
#include <iostream>
#include <math.h>
#include "Pvector.h"
using namespace std;

// ==================================================== //
// ======== Pvector Functions from Pvector.h ========= //
// ==================================================== //

//Sets values fo x and y for Pvector
void Pvector::set(float x, float y)
{
	x= x;
	y = y;
}

//Sets the values of Pvector as x and y
void Pvector::setV(Pvector v)
{
	x = v.x;
	y = v.y;
}

//Calculates the distance between the first Pvector and second Pvector
float Pvector::distance(Pvector v1, Pvector v2)
{
	float dx = v1.x - v2.x;
	float dy = v1.y - v2.y;
	float dist = sqrt(dx*dx + dy*dy);
	return dist;
}

//calculates the dot product of a vector
float Pvector::dotProduct(Pvector v1, Pvector v2)
{
	float dot = v1.x * v2.x + v1.y * v2.y;

	return dot;
}

//calculates the magnitude of a vector
float Pvector::magnitude(Pvector v)
{
	float mag = sqrt(v.x * v.x + v.y * v.y);

	return mag;
}
//Calculates magnitude of referenced object
float Pvector::magnitude()
{
	float mag = sqrt(x * x + y * y);

	return mag;
}

//Calculate the angle between Pvector 1 and Pvector 2
float Pvector::angleBetween(Pvector v1, Pvector v2)
{
	float pi = 3.141592635;
	if (v1.x == 0 && v1.y == 0) return 0.0f;
	if (v2.x == 0 && v2.y == 0) return 0.0f;

	double dot = v1.x * v2.x + v1.y * v2.y;
	double v1mag = sqrt(v1.x * v1.x + v1.y * v1.y); 
	double v2mag = sqrt(v2.x * v2.x + v2.y * v2.y);
	double amt = dot / (v1mag * v2mag); //Based of definition

	if (amt <= -1) {
		return pi; //PConstants equivalent in C++ ?
	}
	else if (amt >= 1) {
		return 0;
	}
	float tmp = acos(amt);
	return tmp;
}

//Returns X value of Pvector
float Pvector::getX()
{
	return x;
}

//Returns Y value of Pvector
float Pvector::getY()
{
	return y;
}

//Creates and returns a copy of the Pvector used as a parameter
Pvector Pvector::copy(Pvector v)
{
	Pvector copy(v.x, v.y);

	return copy;
}
//Adds 2 vectors
void Pvector::addVector(Pvector v, Pvector v2)
{
	v2.x += v.x;
	v2.y += v.y;
}
//Subtracts 2 vectors
void Pvector::subVector(Pvector v, Pvector v2)
{
	v2.x -= v.x;
	v2.y -= v.y;
}
//Multiplies 2 vectors
void Pvector::mulVector(Pvector v, Pvector v2)
{
	v2.x *= v.x;
	v2.y *= v.y;
}
//Divides 2 vectors
void Pvector::divVector(Pvector v, Pvector v2)
{
	v2.x /= v.x;
	v2.y /= v.y;
}

//Adds to a Pvector by a constant number
void Pvector::addScaler(Pvector v, float s)
{
	v.x += s;
	v.y += s;
}
//Adds to a Pvector by a constant number
void Pvector::subScaler(Pvector v, float s)
{
	v.x -= s;
	v.y -= s;
}
//Adds to a Pvector by a constant number
void Pvector::mulScaler(Pvector v, float s)
{
	v.x *= s;
	v.y *= s;
}
//Adds to a Pvector by a constant number
void Pvector::divScaler(Pvector v, float s)
{
	v.x /= s;
	v.y /= s;
}

Pvector Pvector::Normalize(Pvector v)
{
	float m = magnitude();

	if (m > 0)
	{
		v.set(x / m, y / m);
	}
	else
	{
		v.set(x, y);
	}
	return v;
}
