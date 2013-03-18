// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
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

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	Button();
	Button(const Button&);
	~Button();

    // Initialization and shutdown
	bool virtual Initialize(Screen* parent, SCREEN nextScreen, WCHAR* textureFilename);
	bool virtual Shutdown();
	
	// Collision
	bool virtual HandleCollision(RectangleClass* collider);
	
protected:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Screen* m_parent;		// Pointer to the parent screen
	SCREEN m_nextScreen;	// Screen to change to
};
