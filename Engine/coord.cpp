// Solar Exploration Sim
// Developed for DirectX Coursework for Abertay University, based on tutorials from http://www.rastertek.com
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Coord
//		Simple struct-like class containing an x, y, and z float coordinate


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Coord.h"


// |----------------------------------------------------------------------------|
// |						   Default Constructor								|
// |----------------------------------------------------------------------------|
Coord::Coord() :
	x(0), y(0)
{
}

	
// |----------------------------------------------------------------------------|
// |						    Copy Constructor								|
// |----------------------------------------------------------------------------|
Coord::Coord(const Coord& other)
	: x(other.x), y(other.y)
{
}


// |----------------------------------------------------------------------------|
// |						     Deconstructor									|
// |----------------------------------------------------------------------------|
Coord::~Coord()
{
}


// |----------------------------------------------------------------------------|
// |							Other Constructors								|
// |----------------------------------------------------------------------------|
Coord::Coord(float new_x, float new_y) :
	x(new_x), y(new_y)
{
}
	

// |----------------------------------------------------------------------------|
// |							  Operator =									|
// |----------------------------------------------------------------------------|
Coord Coord::operator= (const Coord& other)
{
	x = other.x; y = other.y;
	return Coord(other);
}
Coord Coord::operator= (const float uniform_value)
{
	return Coord(uniform_value, uniform_value);
}