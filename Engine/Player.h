// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Player
//		Controls the player object's position, movement, image, and actions. 
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "Rectangle.h"
#include "Screen.h"
#include "InputClass.h"

// |----------------------------------------------------------------------------|
// |					      Class Definition: Player							|
// |----------------------------------------------------------------------------|
class Player : public Rectangle {
	
public:

	Player ();
	// Constructor

	~Player ();
	// De-constructor

	int virtual logic();
	// Performs logic functions for the object
	
	// Input functions
	int virtual onMouseDown(int button);
	int virtual onMouseUp(int button);
	
protected:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	double speed;
};
