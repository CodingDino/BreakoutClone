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
LevelScreen::LevelScreen() :
	m_background(0),
	m_player(0),
	m_ball(0),
	m_top(0),
	m_left(0),
	m_right(0),
	m_bottom(0),
	m_blocks(0)
{

	// Set MENU as the next screen after this one
	setNextScreen(MENU); 

	// Background
	m_background = new BitmapClass();
	bool result = m_background->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/level_background.png", 1024*SCALE_X, 768*SCALE_Y);
	if(!result)
	{
		debug("Could not initialize the m_background image.");
		error=1;
		return;
	}

	// Player and Ball
	m_player = new Player();
	m_player->Initialize();

	m_ball = new Ball();
	m_ball->Initialize();
	m_ball->SetPlayer(m_player);

	// Stage borders
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

	// TODO: Blocks

	debug ("LevelScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
LevelScreen::~LevelScreen() {

	// Clean up all dynamic objects
	delete m_background;
	delete m_player;
	delete m_ball;
	delete m_top;
	delete m_left;
	delete m_right;
	delete m_bottom;
	delete m_blocks; // TODO: Delete each object in array

	debug ("LevelScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int LevelScreen::logic() {
	debug ("LevelScreen: logic() called.", 10);
	
	// Player and ball logic
	if (m_player)
		m_player->logic();
	if (m_ball)
		m_ball->logic();

	// Border Collisions
	m_ball->Collision(m_top);
	m_ball->Collision(m_left);
	m_ball->Collision(m_right);
	if(m_ball->CheckCollision(m_bottom))
		m_ball->Respawn();

	// Player Collisions
	if(m_ball->Collision(m_player))
		m_ball->PlayerCollide(m_player);

	// TODO: Block Collisions

	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int LevelScreen::draw() {
	debug ("LevelScreen: draw() called.", 10);
	
	// Draw Background
	if (m_background)
		GraphicsClass::GetInstance()->BitmapRender(*m_background, (SCREEN_WIDTH-min(SCREEN_WIDTH,1024*SCREEN_HEIGHT/768))/2, 0);

	// TODO: Draw blocks

	// Draw player and ball
	if (m_player)
		m_player->draw();
	if (m_ball)
		m_ball->draw();

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
