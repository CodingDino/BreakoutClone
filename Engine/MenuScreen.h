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
#include "Util.h"
#include "Player.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: MenuScreen						|
// |----------------------------------------------------------------------------|
class MenuScreen : public Screen {

public:

	MenuScreen ();
	// Constructor

	~MenuScreen();
	// Destructor

	int virtual logic();
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

	// Handles to Singleton Managers
	D3DClass* m_D3D;
	GraphicsClass* m_graphics;

	// Images
	BitmapClass* m_background;
	int m_backgroundX, m_backgroundY;

	// Sound
	//Sound* music;

	// Player
	Player* m_player;

	//ScreenChangeButton button_exit;
	//ScreenChangeButton button_zen;
	//ScreenChangeButton button_adventure;
	//ScreenChangeButton button_time;
	//ScreenChangeButton button_survival;
	//ScreenChangeButton button_score;
	//ScreenChangeButton button_options;

};