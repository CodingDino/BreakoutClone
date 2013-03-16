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
#include "LevelScreen.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
LevelScreen::LevelScreen(GraphicsClass* graphics)
	//background (NULL),
	//music (NULL),
	//player (NULL)
{

	// Set QUIT as the next screen after this one
	setNextScreen(QUIT); 

	//// Loading graphics into Image objects
	//background = new Image(assets.graphics.grass);

	//// Loading music into Sound object
	//music = new Sound(assets.audio.meadow);

	//// Creating player object
	//player = new Player(assets);

	debug ("LevelScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
LevelScreen::~LevelScreen() {
	//delete background;
	//delete music;
	//delete player;
	debug ("LevelScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int LevelScreen::logic(int mouse_x, int mouse_y) {
	debug ("LevelScreen: logic() called.", 10);

	//if (player) player->logic(mouse_x, mouse_y);

	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int LevelScreen::draw() {
	debug ("LevelScreen: draw() called.", 10);

	//if (background) background->draw();
	//if (player) player->draw();

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int LevelScreen::onLoad() {
	debug ("LevelScreen: onLoad called.");
	
	//if (music) music->loop();

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int LevelScreen::onExit() {
	debug ("LevelScreen: onExit called.");

	//if (music) music->stop();

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseDown()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is pressed down
int LevelScreen::onMouseDown(int button) {
	debug ("LevelScreen: onMouseDown called.");
	
	//if (player) player->onMouseDown(button);

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseUp()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is released
int LevelScreen::onMouseUp(int button) {
	debug ("LevelScreen: onMouseUp called.");
	
	//if (player) player->onMouseUp(button);

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onKeyDown()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is pressed down
int LevelScreen::onKeyDown(int button) {
	debug ("LevelScreen: onKeyDown called.");
	
	//if (player) player->onKeyDown(button);

	return error;
}

// |----------------------------------------------------------------------------|
// |							   onKeyUp()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is released
int LevelScreen::onKeyUp(int button) {
	debug ("LevelScreen: onKeyUp called.");
	
	//if (player) player->onKeyUp(button);

	return error;
}