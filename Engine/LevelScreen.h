// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// LevelScreen
//		Contains all objects pertaining to the zen mode. Manages the
//		logic and draw loops for that screen.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "Screen.h"
#include "graphicsclass.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: LevelScreen						|
// |----------------------------------------------------------------------------|
class LevelScreen : public Screen {

public:

	LevelScreen (GraphicsClass* graphics);
	// Constructor

	~LevelScreen();
	// Destructor

	int virtual logic(int mouse_x, int mouse_y);
	// The logic function, which will be called by the main game loop.

	int virtual draw();
	// The draw function, which will be called by the main game loop.

	int virtual onLoad();
	// Called when the screen is loaded.

	int virtual onExit();
	// Called when switching to a different screen

	// Input functions
	int onMouseDown(int button);
	int onMouseUp(int button);
	int onKeyDown(int button);
	int onKeyUp(int button);
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	//Image* background;
	//Sound* music;
	//Player* player;
};