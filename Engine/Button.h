// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Button
//		Defines the screen change button's location, text, image, and function. 
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "Block.h"
#include "Screen.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: Button							|
// |----------------------------------------------------------------------------|
class Button : public Block {
	
public:

	Button ();
	// Constructor

	~Button ();
	// De-constructor

	bool virtual Initialize(Screen* parent, SCREEN nextScreen, WCHAR* textureFilename);
	// Sets up the rectangle
	
	// Collision
	bool virtual HandleCollision(RectangleClass* collider);
	
protected:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Screen* m_parent;		// Pointer to the parent screen
	SCREEN m_nextScreen;	// Screen to change to
};
