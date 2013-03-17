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
	m_blocks(0),
	m_activeBlocks(0),
	m_levelNumber(1),
	m_dialogue(true),
	m_dialogueBackground(0)
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

	// Dialogue
	m_dialogueBackground = new BitmapClass();
	result = m_dialogueBackground->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/level_message.png", 481*SCALE_X, 275*SCALE_Y);
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

	// Blocks
	// TODO: Blocks from file (probably should go in OnLoad instead)
	m_numBlocks = 17*21;
	m_blocks = new Block*[m_numBlocks];
	for (int i=0; i<m_numBlocks; ++i)
	{
		m_blocks[i] = 0;
	}

	debug ("LevelScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
LevelScreen::~LevelScreen() {

	// Clean up all dynamic objects
	delete m_background; m_background = 0;
	delete m_dialogueBackground; m_dialogueBackground = 0;
	delete m_player; m_player = 0;
	delete m_ball; m_ball = 0;
	delete m_top; m_top = 0;
	delete m_left; m_left = 0;
	delete m_right; m_right = 0;
	delete m_bottom; m_bottom = 0;

	for (int i=0; i<m_numBlocks; ++i)
	{
		if(m_blocks[i])
			delete m_blocks[i];
	}
	delete m_blocks; m_blocks = 0;
	m_numBlocks = 0;
	

	debug ("LevelScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int LevelScreen::logic() {
	debug ("LevelScreen: logic() called.", 10);

	// Check if it's time to load the next level
	if(m_activeBlocks <= 0)
	{
		// Load next level
		loadNext();

		// Increase speed of ball
		m_ball->IncreaseSpeed();

		// Reset ball location
		m_ball->Respawn();

		return error;
	}
	
	if (m_dialogue)
	{
		// Check for click
		if((InputClass::GetInstance())->IsMouseButtonPressed(0))
			m_dialogue = false;
		return error;
	}

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

	// Block Collisions
	for (int i=0; i<m_numBlocks; ++i)
	{
		if (m_blocks[i])
		{
			m_ball->Collision(m_blocks[i]);
			if(m_blocks[i]->IsDead())
			{
				delete m_blocks[i];
				m_blocks[i] = 0;
				--m_activeBlocks;
				// TODO: Increment score
			}
		}
	}
	if(m_activeBlocks <= 0)
	{
		m_dialogue = true;
	}

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

	if(m_dialogue)
	{
		// Display level dialogue
		GraphicsClass::GetInstance()->BitmapRender(*m_dialogueBackground, (SCREEN_WIDTH-481*SCALE_X)/2, (SCREEN_HEIGHT-275*SCALE_Y)/2);
	}
	else
	{
		// Draw blocks
		for (int i=0; i<m_numBlocks; ++i)
		{
			if(m_blocks[i])
				m_blocks[i]->draw();
		}

		// Draw player and ball
		if (m_player)
			m_player->draw();
		if (m_ball)
			m_ball->draw();
	}

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
int LevelScreen::onLoad() {
	debug ("LevelScreen: onLoad called.");

	// Screen is not done
	done = false;

	// Load the first level from file
	loadFromFile("../Engine/data/level_test.txt");

	// Set up the ball
	m_ball->Respawn();
	m_ball->ResetSpeed();
	
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
// |							  loadFromFile()								|
// |----------------------------------------------------------------------------|
void LevelScreen::loadFromFile(const char* fileName)
{
	debug ("LevelScreen: loadFromFile called.");
	int block (0);
	int i (0), x(0), y(0);
	const int PADDING(5);
	const int XUNIT(50*SCALE_X	+ PADDING*SCALE_X), YUNIT(20*SCALE_Y	+ PADDING*SCALE_Y);
	const int XSTART( (SCREEN_WIDTH - 50*SCALE_X)/2		- 8  * XUNIT );
	const int YSTART( (SCREEN_HEIGHT-SCREEN_HEIGHT*0.3)	- 20 * YUNIT );
	
	ifstream inFile;  // object for reading from a file
	inFile.open(fileName, ios::in);
	if (!inFile) {
		debug("LevelScreen: can't open level file.");
		return;
	}

	while (!inFile.eof()) 
	{
		// read in this block
		inFile >> block;

		// Set up the block if there is one
		if(block)
		{
			m_blocks[i] = new Block();
			m_blocks[i]->Initialize();
			x = XSTART+(i%17)*XUNIT;
			y = YSTART+(floor(((float)i)/17))*YUNIT;
			m_blocks[i]->SetPosition(Coord(x,y));
			m_blocks[i]->SetType((BLOCK)(block-1));
			++m_activeBlocks;
		}

		// increment
		++i;
	}


}

// |----------------------------------------------------------------------------|
// |							  loadFromFile()								|
// |----------------------------------------------------------------------------|
void LevelScreen::loadNext()
{
	++m_levelNumber;

	int index = (m_levelNumber-1)%3;

	if (index == 0)
		loadFromFile("../Engine/data/level_1.txt");
	else if (index == 1)
		loadFromFile("../Engine/data/level_2.txt");
	else if (index == 2)
		loadFromFile("../Engine/data/level_3.txt");

}