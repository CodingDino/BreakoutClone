// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// ScoreScreen
//		Contains all objects pertaining to the zen mode. Manages the
//		logic and draw loops for that screen.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "Screen.h"
#include "graphicsclass.h"
#include "Player.h"
#include "Ball.h"
#include "Button.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: ScoreScreen						|
// |----------------------------------------------------------------------------|
class ScoreScreen : public Screen {

public:

	ScoreScreen ();
	// Constructor

	~ScoreScreen();
	// Destructor

	int virtual logic();
	// The logic function, which will be called by the main game loop.

	int virtual draw();
	// The draw function, which will be called by the main game loop.

	int virtual onLoad();
	// Called when the screen is loaded.

	int virtual onExit();
	// Called when switching to a different screen
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Images
	BitmapClass* m_background;

	// Objects
	Player* m_player;
	Ball* m_ball;
	RectangleClass* m_top;
	RectangleClass* m_left;
	RectangleClass* m_right;
	RectangleClass* m_bottom;

	// Button
	Button* m_menu;
};