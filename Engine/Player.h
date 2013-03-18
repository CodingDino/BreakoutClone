// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
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
class Player : public RectangleClass {
	
public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	Player();
	Player(const Player&);
	~Player();

    // Initialization and shutdown
	bool virtual Initialize();
	bool virtual Shutdown();
    
	// Performs logic functions for the object
	bool virtual Logic();

};
