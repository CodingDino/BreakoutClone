// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// MenuScreen
//		Controls the image, music, and buttons for the main menu of the game. It 
//		will set up the onClick functions for each of the buttons.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Screen.h"
#include "graphicsclass.h"
#include "Util.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: MenuScreen						|
// |----------------------------------------------------------------------------|
class MenuScreen : public Screen {

public:

	MenuScreen (GraphicsClass* graphics);
	// Constructor

	~MenuScreen();
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
	BitmapClass* m_background;
	//Image* background;
	//Sound* music;

	//ScreenChangeButton button_exit;
	//ScreenChangeButton button_zen;
	//ScreenChangeButton button_adventure;
	//ScreenChangeButton button_time;
	//ScreenChangeButton button_survival;
	//ScreenChangeButton button_score;
	//ScreenChangeButton button_options;

};