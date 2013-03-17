// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Block
//		Block which collides with ball and knocks it away, getting hurt or 
//		destroyed in the process.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "Rectangle.h"
#include "Screen.h"

// |----------------------------------------------------------------------------|
// |					      Class Definition: Ball							|
// |----------------------------------------------------------------------------|
class Block : public RectangleClass {
	
public:

	Block ();
	// Constructor

	~Block ();
	// De-constructor

	int virtual logic();
	// Performs logic functions for the object

	bool virtual HandleCollision(RectangleClass* collider);

	// TODO: Function to check if dead
	
protected:
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int m_hp;

	// Block sprites
	BitmapClass* m_normal;	// Graphic
};
