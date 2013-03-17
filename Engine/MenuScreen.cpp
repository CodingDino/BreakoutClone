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
	m_player(0),
	m_ball(0),
	m_top(0),
	m_left(0),
	m_right(0),
	m_bottom(0),
	m_start(0),
	m_scores(0),
	m_quit(0)
	{

	// Set next screen to QUIT - it will be updated by the buttons.
	setNextScreen(QUIT);

	// Get handles for Singleton managers
	m_D3D = D3DClass::GetInstance();
	m_graphics = GraphicsClass::GetInstance();

	// Background
	int bitmapWidth(0), bitmapHeight(0);
	bitmapHeight = SCREEN_HEIGHT;
	bitmapWidth = min(SCREEN_WIDTH,1024*SCREEN_HEIGHT/768);
	SCALE_X = ((float)bitmapHeight)/768;
	SCALE_Y = ((float)bitmapWidth)/1024;
	m_backgroundX = (SCREEN_WIDTH-min(SCREEN_WIDTH,1024*SCREEN_HEIGHT/768))/2;
	m_backgroundY = 0;
	m_background = new BitmapClass();
	bool result = m_background->Initialize(m_D3D->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/menu_background.png", bitmapWidth, bitmapHeight);
	if(!result)
	{
		debug("Could not initialize the m_titleScreen object.");
		error=1;
		return;
	}

	// Objects
	m_player = new Player();
	m_player->Initialize();

	m_ball = new Ball();
	m_ball->Initialize();
	m_ball->SetPlayer(m_player);

	m_top = new RectangleClass();
	m_top->Initialize();
	m_top->SetDimmensions(Coord(SCREEN_WIDTH,35*SCALE_Y));
	m_top->SetPosition(Coord(0,0));

	m_left = new RectangleClass();
	m_left->Initialize();
	m_left->SetDimmensions(Coord(35*SCALE_X,768*SCALE_Y));
	m_left->SetPosition(Coord((SCREEN_WIDTH-1024*SCALE_X)/2,0));

	m_right = new RectangleClass();
	m_right->Initialize();
	m_right->SetDimmensions(Coord(35*SCALE_X,768*SCALE_Y));
	m_right->SetPosition(Coord(SCREEN_WIDTH-(SCREEN_WIDTH-1024*SCALE_X)/2-35*SCALE_X,0));

	m_bottom = new RectangleClass();
	m_bottom->Initialize();
	m_bottom->SetDimmensions(Coord(SCREEN_WIDTH,35*SCALE_Y));
	m_bottom->SetPosition(Coord(0,SCREEN_HEIGHT+20));

	m_start = new Button();
	m_start->Initialize(this, LEVEL, L"../Engine/data/button_start.png");
	m_start->SetPosition(Coord((SCREEN_WIDTH - 178*SCALE_X)/2-178*SCALE_X*1.5,SCREEN_HEIGHT-SCREEN_HEIGHT*0.3));

	m_scores = new Button();
	m_scores->Initialize(this, SCORES, L"../Engine/data/button_score.png");
	m_scores->SetPosition(Coord((SCREEN_WIDTH - 178*SCALE_X)/2,SCREEN_HEIGHT-SCREEN_HEIGHT*0.3));

	m_quit = new Button();
	m_quit->Initialize(this, QUIT, L"../Engine/data/button_quit.png");
	m_quit->SetPosition(Coord((SCREEN_WIDTH - 178*SCALE_X)/2+178*SCALE_X*1.5,SCREEN_HEIGHT-SCREEN_HEIGHT*0.3));

	debug ("MenuScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
MenuScreen::~MenuScreen() {

	// Release Bitmaps
	m_background->Shutdown();
	delete m_background;

	// Release objects
	delete m_player;
	delete m_ball;
	delete m_top;
	delete m_left;
	delete m_right;
	delete m_bottom;
	delete m_start;
	delete m_scores;
	delete m_quit;

	debug ("MenuScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int MenuScreen::logic() {
	debug ("MenuScreen: logic() called.", 10);
	
	// Player and ball logic
	if (m_player)
		m_player->logic();
	if (m_ball)
		m_ball->logic();

	// Handle collisions
	m_ball->Collision(m_top);
	m_ball->Collision(m_left);
	m_ball->Collision(m_right);
	if(m_ball->Collision(m_player))
		m_ball->PlayerCollide(m_player);

	if(m_ball->CheckCollision(m_bottom))
		m_ball->Respawn();
	
	m_ball->Collision(m_start);
	m_ball->Collision(m_scores);
	m_ball->Collision(m_quit);

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

	// Draw objects
	if (m_player)
		m_player->draw();
	if (m_ball)
		m_ball->draw();
	if (m_start)
		m_start->draw();
	if (m_scores)
		m_scores->draw();
	if (m_quit)
		m_quit->draw();

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int MenuScreen::onLoad() {
	debug("MenuScreen: onLoad called");

	done = false;
	m_ball->Respawn();

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int MenuScreen::onExit() {
	debug ("MenuScreen: onExit called.");

	//if (music) music->stop_all();

	return error;
}