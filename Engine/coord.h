// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Coord
//		Simple struct-like class containing an x, y float coordinate
#pragma once


// |----------------------------------------------------------------------------|
// |							 Class: Coord									|
// |----------------------------------------------------------------------------|
class Coord
{
public:
	//|-------------------------------Public Functions--------------------------|

	// Constrcutors and Deconstructors
	Coord();
	Coord(const Coord&);
	~Coord();
	
	// Argument Constructors and Operator Overloading
	Coord(const float new_x, const float new_y);
	Coord operator= (const Coord& other);
	Coord operator= (const float uniform_value);
	
	//|-----------------------------Public Data Members-------------------------|

	// floats holding coordinate values
	float x, y;
};