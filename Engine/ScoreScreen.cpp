// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// ScoreScreen
//		Contains all objects pertaining to the zen mode. Manages the
//		logic and draw loops for that screen.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "ScoreScreen.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
ScoreScreen::ScoreScreen() :
	m_background(0),
	m_player(0),
	m_ball(0),
	m_top(0),
	m_left(0),
	m_right(0),
	m_bottom(0),
	m_menu(0),
    m_numbers(0),
    m_colon(0),
    m_highScoresTitle(0),
    m_highScores(0)
{

	// Set MENU as the next screen after this one
	setNextScreen(MENU); 

	// Background
	m_background = new BitmapClass();
	bool result = m_background->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/score_background.png", 1024*SCALE_X, 768*SCALE_Y);
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

	// Button
	m_menu = new Button();
	m_menu->Initialize(this, MENU, L"../Engine/data/button_menu.png");
	m_menu->SetPosition(Coord((SCREEN_WIDTH - 178*SCALE_X)/2,SCREEN_HEIGHT-SCREEN_HEIGHT*0.3));
    
	// Numbers
	m_numbers = new BitmapClass*[10];
	m_numbers[0] = new BitmapClass();
	m_numbers[0]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_0.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[1] = new BitmapClass();
	m_numbers[1]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_1.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[2] = new BitmapClass();
	m_numbers[2]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_2.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[3] = new BitmapClass();
	m_numbers[3]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_3.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[4] = new BitmapClass();
	m_numbers[4]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_4.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[5] = new BitmapClass();
	m_numbers[5]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_5.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[6] = new BitmapClass();
	m_numbers[6]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_6.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[7] = new BitmapClass();
	m_numbers[7]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_7.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[8] = new BitmapClass();
	m_numbers[8]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_8.png", 26*SCALE_X, 35*SCALE_Y);
	m_numbers[9] = new BitmapClass();
	m_numbers[9]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_9.png", 26*SCALE_X, 35*SCALE_Y);
	m_colon = new BitmapClass();
	m_colon->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_colon.png", 26*SCALE_X, 35*SCALE_Y);

    // High Scores Title
	m_highScoresTitle = new BitmapClass();
	m_highScoresTitle->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_high_scores.png", 495*SCALE_X, 62*SCALE_Y);

    // High Scores
    m_highScores = new int[20];
    for (int i(0); i<20; ++i)
    {
        m_highScores[i] = 0;
    }

	debug ("ScoreScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
ScoreScreen::~ScoreScreen() {

	// Clean up all dynamic objects
    delete m_highScoresTitle;
	delete m_background;
	delete m_player;
	delete m_ball;
	delete m_top;
	delete m_left;
	delete m_right;
	delete m_bottom;
	delete m_menu;

	debug ("ScoreScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int ScoreScreen::logic() {
	debug ("ScoreScreen: logic() called.", 10);
	
	// Player and ball logic
	if (m_player)
		m_player->logic();
	if (m_ball)
		m_ball->logic();

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

	// Button
	if(m_ball->Collision(m_menu))
        SoundClass::GetInstance()->PlayBreak();

	return error;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
int ScoreScreen::draw() {
	debug ("ScoreScreen: draw() called.", 10);
	
	// Draw Background
	if (m_background)
		GraphicsClass::GetInstance()->BitmapRender(*m_background, (SCREEN_WIDTH-min(SCREEN_WIDTH,1024*SCREEN_HEIGHT/768))/2, 0);
    
	// Draw High Score Title
	if (m_highScoresTitle)
		GraphicsClass::GetInstance()->BitmapRender(*m_highScoresTitle, 
            (SCREEN_WIDTH-495*SCALE_X)/2, 50*SCALE_Y);
    
    int START_X = 300*SCALE_X;
    int START_Y = (50+62+10)*SCALE_Y;

    // Draw High Scores
    for (int i(0); i<10; ++i)
    {
		int tens = ((int)floor((float)(i+1)/10))%10;
		int ones = (i+1)%10;
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tens]), 
			START_X+0*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[ones]), 
			START_X+1*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_colon), 
			START_X+2*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		int millions = ((int)floor((float)m_highScores[i]/1000000))%10;
		int hundredthousands = ((int)floor((float)m_highScores[i]/100000))%10;
		int tenthousands = ((int)floor((float)m_highScores[i]/10000))%10;
		int thousands = ((int)floor((float)m_highScores[i]/1000))%10;
		int hundreds = ((int)floor((float)m_highScores[i]/100))%10;
		tens = ((int)floor((float)m_highScores[i]/10))%10;
		ones = m_highScores[i]%10;
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[millions]), 
			START_X+4*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundredthousands]), 
			START_X+5*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tenthousands]),  
			START_X+6*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[thousands]),
			START_X+7*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundreds]), 
			START_X+8*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tens]),  
			START_X+9*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[ones]),  
			START_X+10*(26*SCALE_X), START_Y+i*(35*SCALE_Y));
    }

    START_X = SCREEN_WIDTH - 300*SCALE_X - 11*(26*SCALE_X);

    for (int i(10); i<20; ++i)
    {
		int tens = ((int)floor((float)(i+1)/10))%10;
		int ones = (i+1)%10;
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tens]), 
			START_X+0*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[ones]), 
			START_X+1*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_colon), 
			START_X+2*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		int millions = ((int)floor((float)m_highScores[i]/1000000))%10;
		int hundredthousands = ((int)floor((float)m_highScores[i]/100000))%10;
		int tenthousands = ((int)floor((float)m_highScores[i]/10000))%10;
		int thousands = ((int)floor((float)m_highScores[i]/1000))%10;
		int hundreds = ((int)floor((float)m_highScores[i]/100))%10;
		tens = ((int)floor((float)m_highScores[i]/10))%10;
		ones = m_highScores[i]%10;
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[millions]), 
			START_X+4*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundredthousands]), 
			START_X+5*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tenthousands]),  
			START_X+6*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[thousands]),
			START_X+7*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundreds]), 
			START_X+8*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tens]),  
			START_X+9*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[ones]),  
			START_X+10*(26*SCALE_X), START_Y+(i-10)*(35*SCALE_Y));
    }

	// Draw Buttons
	if (m_menu)
		m_menu->draw();

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
int ScoreScreen::onLoad() {
	debug ("ScoreScreen: onLoad called.");

	done = false;
	m_ball->Respawn();
    loadScoresFromFile();

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
int ScoreScreen::onExit() {
	debug ("ScoreScreen: onExit called.");

	//if (music) music->stop();

	return error;
}


// |----------------------------------------------------------------------------|
// |							loadScoresFromFile()							|
// |----------------------------------------------------------------------------|
void ScoreScreen::loadScoresFromFile()
{
	debug ("ScoreScreen: loadScoresFromFile called.");
	int i (0);
	
	ifstream inFile;  // object for reading from a file
	inFile.open("../Engine/data/high_scores.txt", ios::in);
	if (!inFile) {
		debug("ScoreScreen: can't open level file.");
		return;
	}

	while (!inFile.eof()) 
	{
		// read in this block
		inFile >> m_highScores[i];

		// increment
		++i;
	}


}
