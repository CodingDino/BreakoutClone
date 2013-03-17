// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Screen
//		Contains all objects pertaining to a particular screen. Manages the
//		logic and draw loops for that screen. A screen is a superclass,
//		intended to be inherited by subclasses.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "graphicsclass.h"
#include "D3DClass.h"

// |----------------------------------------------------------------------------|
// |								enum SCREEN									|
// |----------------------------------------------------------------------------|
enum SCREEN {MENU, LEVEL, SCORES, NUM_SCREENS, QUIT};

// |----------------------------------------------------------------------------|
// |						  Class Definition: Screen							|
// |----------------------------------------------------------------------------|
class Screen {

public:

	Screen () : error(0), done(false) {}
	// Default constructor

	// ~Screen();
	// Destructor

	int virtual logic() = 0;
	// The logic function, which will be called by the main game loop.
	// TO BE IMPLEMENTED BY SUB CLASS

	int virtual draw() = 0;
	// The draw function, which will be called by the main game loop.
	// TO BE IMPLEMENTED BY SUB CLASS

	int virtual onLoad() = 0;
	// Called when the screen is loaded.
	// TO BE IMPLEMENTED BY SUB CLASS

	int virtual onExit() = 0;
	// Called when switching to a different screen
	// TO BE IMPLEMENTED BY SUB CLASS

	bool virtual isDone() { return done; }
	// Returns whether the screen is done (ready to close) or not.

	SCREEN virtual getNextScreen()  { return next_screen; }
	// Tells the game class what screen to load after this one

	void virtual setNextScreen(SCREEN new_next) { next_screen= new_next; }
	// Sets the screen that will be loaded after this one

	void virtual setDone(bool new_done) { done = new_done; }
	// Sets whether the screen will quit or not
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int error;
	bool done;
	SCREEN next_screen;

};