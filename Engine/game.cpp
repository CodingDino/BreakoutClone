// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Game
//		Holds game-wide variables and methods. Holds asset managers, screens,
//		and game-wide logic and draw loops (calls screen-specific loops).

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Game.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Game::Game() :
	// Initiallization List
	redraw (true),
	quit(false),
	error(0),
	current_screen(NULL),
	screens(NULL) 
{
	debug ("Game: object instantiated.");
}
	
// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Game::~Game() {

	// Screen Cleanup
	if (screens) {
		for (int i = 0 ; i < NUM_SCREENS; ++i) {
			delete screens[i];
		}
		delete screens;
	}

	debug ("Game: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							  Initialize()									|
// |----------------------------------------------------------------------------|
int Game::Initialize() {

	// Create screens - set first screen to TITLE
	if (!error)
	{
		screens = new Screen* [NUM_SCREENS];
		for (int i = 0 ; i < NUM_SCREENS; ++i) {
			screens[i] = NULL;
		}
		screens[MENU] = new MenuScreen();
		screens[LEVEL] = new LevelScreen();
		screens[SCORES] = new ScoreScreen();
		//screens[QUITSCREEN] = new QuitScreen();
		current_screen = screens[MENU];
		error = error || current_screen->onLoad();
	}
	
	if (!error) debug("Game: object initialised.");
	else debug("Game: initialisation failed.");
	return (!error);
}

// |----------------------------------------------------------------------------|
// |								 run()										|
// |----------------------------------------------------------------------------|
int Game::Frame() {

	// Game logic (pass in mouse coordinates)
	error = error || current_screen->logic();

	// If it's time to redraw and there are no other events waiting  
	error = error || current_screen->draw();

	// If the current screen is done, switch to the new screen
	if (current_screen->isDone()) {
		debug("Game: current screen done");

		// Perform onExit functions for the old screen
		error = error || current_screen->onExit();

		// Check if the screen is telling the game to quit.
		if (current_screen->getNextScreen() == QUIT) {
			debug("Game: quitting");
			// If so, quit.
			return false;
		}

		// If the screen is NOT telling the game to quit, load the next screen
		else {
			debug("Game: moving to next screen");
			// Set the new screen as current
			current_screen = screens[current_screen->getNextScreen()];
			// Perform onLoad functions for the new screen
			error = error || current_screen->onLoad();
		}

	}

	//if(error) return false;
	return true;
}