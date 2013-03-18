// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// MenuScreen
//		Controls the image and buttons for the main menu of the game.
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
	debug ("MenuScreen: object instantiated.");
}
     

// |----------------------------------------------------------------------------|
// |							  Copy Constructor								|
// |----------------------------------------------------------------------------|
MenuScreen::MenuScreen(const MenuScreen&) {
	debug ("MenuScreen: object copied.");
}


// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
MenuScreen::~MenuScreen() {
	debug ("MenuScreen: object destroyed.");
}


// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool MenuScreen::Initialize() {
    // Set next screen to QUIT - it will be updated by the buttons.
	SetNextScreen(QUIT);

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
		return false;
	}

	// Objects
	m_player = new Player();
	m_player->Initialize();

	m_ball = new Ball();
	m_ball->Initialize();
	m_ball->SetPlayer(m_player);

	m_top = new RectangleClass();
	m_top->Initialize();
	m_top->SetDimmensions(Coord((float)SCREEN_WIDTH,(float)35*SCALE_Y));
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
	m_bottom->SetDimmensions(Coord((float)SCREEN_WIDTH,35*SCALE_Y));
	m_bottom->SetPosition(Coord(0,(float)SCREEN_HEIGHT+20));

	m_start = new Button();
	m_start->Initialize(this, LEVEL, L"../Engine/data/button_start.png");
	m_start->SetPosition(Coord((float)((SCREEN_WIDTH - 178*SCALE_X)/2-178*SCALE_X*1.5),(float)(SCREEN_HEIGHT-SCREEN_HEIGHT*0.3)));

	m_scores = new Button();
	m_scores->Initialize(this, SCORES, L"../Engine/data/button_score.png");
	m_scores->SetPosition(Coord((float)((SCREEN_WIDTH - 178*SCALE_X)/2),(float)(SCREEN_HEIGHT-SCREEN_HEIGHT*0.3)));

	m_quit = new Button();
	m_quit->Initialize(this, QUIT, L"../Engine/data/button_quit.png");
	m_quit->SetPosition(Coord((float)((SCREEN_WIDTH - 178*SCALE_X)/2+178*SCALE_X*1.5),(float)(SCREEN_HEIGHT-SCREEN_HEIGHT*0.3)));

	debug ("MenuScreen: object initialized.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							    Shutdown									|
// |----------------------------------------------------------------------------|
bool MenuScreen::Shutdown() {

    // Cleanup dynamic data members
    if (m_background)
    {
        m_background->Shutdown();
        delete m_background;
        m_background = 0;
    }
    if (m_player)
    {
        m_player->Shutdown();
        delete m_player;
        m_player = 0;
    }
    if (m_ball)
    {
        m_ball->Shutdown();
        delete m_ball;
        m_ball = 0;
    }
    if (m_top)
    {
        m_top->Shutdown();
        delete m_top;
        m_top = 0;
    }
    if (m_left)
    {
        m_left->Shutdown();
        delete m_left;
        m_left = 0;
    }
    if (m_right)
    {
        m_right->Shutdown();
        delete m_right;
        m_right = 0;
    }
    if (m_bottom)
    {
        m_bottom->Shutdown();
        delete m_bottom;
        m_bottom = 0;
    }
    if (m_start)
    {
        m_start->Shutdown();
        delete m_start;
        m_start = 0;
    }
    if (m_scores)
    {
        m_scores->Shutdown();
        delete m_scores;
        m_scores = 0;
    }
    if (m_quit)
    {
        m_quit->Shutdown();
        delete m_quit;
        m_quit = 0;
    }

	debug ("MenuScreen: object shutdown.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							     Logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
bool MenuScreen::Logic() {
	debug ("MenuScreen: Logic() called.", 10);
	
	// Player and ball logic
	if (m_player)
		m_player->Logic();
	if (m_ball)
		m_ball->Logic();
    
	// Border Collisions
	if(m_ball->Collision(m_top))
        SoundClass::GetInstance()->PlayBounce();
	if(m_ball->Collision(m_left))
        SoundClass::GetInstance()->PlayBounce();
	if(m_ball->Collision(m_right))
        SoundClass::GetInstance()->PlayBounce();
	if(m_ball->CheckCollision(m_bottom))
		m_ball->Respawn();

	// Player Collisions
	if(m_ball->Collision(m_player))
    {
		m_ball->PlayerCollide(m_player);
        SoundClass::GetInstance()->PlayBounce();
    }
	
	// Buttons
	if(m_ball->Collision(m_start))
        SoundClass::GetInstance()->PlayBreak();
	if(m_ball->Collision(m_scores))
        SoundClass::GetInstance()->PlayBreak();
	if(m_ball->Collision(m_quit))
        SoundClass::GetInstance()->PlayBreak();

	return true;
}

// |----------------------------------------------------------------------------|
// |							     Draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
bool MenuScreen::Draw() {
	debug ("MenuScreen: Draw() called.", 10);

	// Draw Background
	if (m_background)
		m_graphics->BitmapRender(*m_background, m_backgroundX, m_backgroundY);

	// Draw objects
	if (m_player)
		m_player->Draw();
	if (m_ball)
		m_ball->Draw();
	if (m_start)
		m_start->Draw();
	if (m_scores)
		m_scores->Draw();
	if (m_quit)
		m_quit->Draw();

	return true;
}

// |----------------------------------------------------------------------------|
// |							    OnLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
bool MenuScreen::OnLoad() {
	debug("MenuScreen: OnLoad called");

	m_done = false;
	m_ball->Respawn();

	return true;
}

// |----------------------------------------------------------------------------|
// |							    OnExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
bool MenuScreen::OnExit() {
	debug ("MenuScreen: OnExit called.");

	return true;
}