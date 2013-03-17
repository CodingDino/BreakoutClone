// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Game
//		Holds game-wide variables and methods. Holds asset managers, screens,
//		and game-wide logic and draw loops (calls screen-specific loops).
//		Governs game-wide options and switching between screens.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "MenuScreen.h"
#include "LevelScreen.h"


// |----------------------------------------------------------------------------|
// |						  Class Definition: Game							|
// |----------------------------------------------------------------------------|
class Game {

public:

	Game ();
	// Constructor

	~Game();
	// Destructor

	int Initialize();
	// Sets up the game.

	int Frame();
	// Runs input, logic and draw in game loop.

	int changeScreen(SCREEN next_screen);
	// Sets the current screen to the supplied screen index.
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Screens
	Screen* current_screen;
	Screen** screens;

	// Input Management
	//Input input;

	// Miscellaneous
	bool redraw;
	bool quit;
	int error;

};