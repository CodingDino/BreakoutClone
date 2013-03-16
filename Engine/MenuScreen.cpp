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
#include "MenuScreen.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
MenuScreen::MenuScreen() :
	m_D3D(0),
	m_graphics(0),
	m_background (0),
	m_backgroundX(0),
	m_backgroundY(0),
	m_player(0)
	//music (NULL),
	//button_exit(assets, this, QUIT, "QUIT"),
	//button_zen(assets, this, ZEN, "ZEN MODE"),
	//button_adventure(assets, this, ADVENTURE, "ADVENTURE MODE"),
	//button_time(assets, this, TIME, "TIME MODE"),
	//button_survival(assets, this, SURVIVAL, "SURVIVAL MODE"),
	//button_score(assets, this, SCORE, "HIGH SCORES"),
	//button_options(assets, this, OPTIONS, "OPTIONS") 
	{

	// Set next screen to QUIT - it will be updated by the buttons.
	setNextScreen(QUIT);

	// Get handles for Singleton managers
	m_D3D = D3DClass::GetInstance();
	m_graphics = GraphicsClass::GetInstance();

	// Loading graphics into bitmap objects

	// Determine proper scaling for background
	int bitmapWidth(0), bitmapHeight(0);
	bitmapHeight = SCREEN_HEIGHT;
	bitmapWidth = min(SCREEN_WIDTH,1024*SCREEN_HEIGHT/768);
	SCALE_X = ((float)bitmapHeight)/768;
	SCALE_Y = ((float)bitmapWidth)/1024;
	m_backgroundX = (SCREEN_WIDTH-min(SCREEN_WIDTH,1024*SCREEN_HEIGHT/768))/2;
	m_backgroundY = 0;
	m_background = new BitmapClass();
	bool result = m_background->Initialize(m_D3D->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/titleImage.png", bitmapWidth, bitmapHeight);
	if(!result)
	{
		debug("Could not initialize the m_titleScreen object.");
		error=1;
		return;
	}

	//// Loading music into Sound object
	//music = new Sound(assets.audio.victory);

	//// Set button locations
	//button_zen.setAnchor(Coord(250,100));
	//button_adventure.setAnchor(Coord(550,100));
	//button_time.setAnchor(Coord(150,300));
	//button_survival.setAnchor(Coord(650,300));
	//button_score.setAnchor(Coord(50,550));
	//button_options.setAnchor(Coord(400,550));
	//button_exit.setAnchor(Coord(750,550));

	//// Temporarily disable buttons
	//button_adventure.setEnabled(false);
	//button_time.setEnabled(false);
	//button_survival.setEnabled(false);
	//button_score.setEnabled(false);
	//button_options.setEnabled(false);

	// Player Object
	m_player = new Player();
	m_player->Initialize();

	debug ("MenuScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
MenuScreen::~MenuScreen() {

	// Release Bitmaps
	m_background->Shutdown();
	delete m_background;

	// Release player
	delete m_player;

	debug ("MenuScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int MenuScreen::logic() {
	debug ("MenuScreen: logic() called.", 10);
	
	//// Logic Buttons
	//button_exit.logic(mouse_x, mouse_y);
	//button_zen.logic(mouse_x, mouse_y);
	//button_adventure.logic(mouse_x, mouse_y);
	//button_time.logic(mouse_x, mouse_y);
	//button_survival.logic(mouse_x, mouse_y);
	//button_score.logic(mouse_x, mouse_y);
	//button_options.logic(mouse_x, mouse_y);
	
	// Player logic
	if (m_player)
		m_player->logic();


	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int MenuScreen::draw() {
	debug ("MenuScreen: draw() called.", 10);

	// Draw Background
	if (m_background)
		m_graphics->BitmapRender(*m_background, m_backgroundX, m_backgroundY);

	//// Draw Buttons
	//button_exit.draw();
	//button_zen.draw();
	//button_adventure.draw();
	//button_time.draw();
	//button_survival.draw();
	//button_score.draw();
	//button_options.draw();

	// Draw player
	if (m_player)
		m_player->draw();

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int MenuScreen::onLoad() {
	debug("MenuScreen: onLoad called");
	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int MenuScreen::onExit() {
	debug ("MenuScreen: onExit called.");

	//if (music) music->stop_all();

	return (!error);
}

// |----------------------------------------------------------------------------|
// |							  onMouseDown()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is pressed down
int MenuScreen::onMouseDown(int button) {
	debug ("MenuScreen: onMouseDown called.");
	
	//// Call button functions
	//button_exit.onMouseDown(button);
	//button_zen.onMouseDown(button);
	//button_adventure.onMouseDown(button);
	//button_time.onMouseDown(button);
	//button_survival.onMouseDown(button);
	//button_score.onMouseDown(button);
	//button_options.onMouseDown(button);

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onMouseUp()									|
// |----------------------------------------------------------------------------|
// Called when a mouse button is released
int MenuScreen::onMouseUp(int button) {
	debug ("MenuScreen: onMouseUp called.");
	
	//// Call button functions
	//button_exit.onMouseUp(button);
	//button_zen.onMouseUp(button);
	//button_adventure.onMouseUp(button);
	//button_time.onMouseUp(button);
	//button_survival.onMouseUp(button);
	//button_score.onMouseUp(button);
	//button_options.onMouseUp(button);

	return error;
}

// |----------------------------------------------------------------------------|
// |							  onKeyDown()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is pressed down
int MenuScreen::onKeyDown(int button) {
	debug ("MenuScreen: onKeyDown called.");
	
	//// Call button functions
	//button_exit.onKeyDown(button);
	//button_zen.onKeyDown(button);
	//button_adventure.onKeyDown(button);
	//button_time.onKeyDown(button);
	//button_survival.onKeyDown(button);
	//button_score.onKeyDown(button);
	//button_options.onKeyDown(button);

	return error;
}

// |----------------------------------------------------------------------------|
// |							   onKeyUp()									|
// |----------------------------------------------------------------------------|
// Called when a keyboard button is released
int MenuScreen::onKeyUp(int button) {
	debug ("MenuScreen: onKeyUp called.");
	
	//// Call button functions
	//button_exit.onKeyUp(button);
	//button_zen.onKeyUp(button);
	//button_adventure.onKeyUp(button);
	//button_time.onKeyUp(button);
	//button_survival.onKeyUp(button);
	//button_score.onKeyUp(button);
	//button_options.onKeyUp(button);

	return error;
}