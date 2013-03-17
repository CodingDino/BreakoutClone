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
	m_livesImage(0),
	m_player(0),
	m_ball(0),
	m_top(0),
	m_left(0),
	m_right(0),
	m_bottom(0),
	m_blocks(0),
	m_level1(0),
	m_level2(0),
	m_level3(0),
	m_activeBlocks(0),
	m_levelNumber(0),
	m_dialogue(false),
	m_dialogueBackground(0),
	m_lives(3),
	m_gameOver(false),
	m_gameOverDialogue(0)
{

	// Set MENU as the next screen after this one
	setNextScreen(MENU); 

	// Background
	m_background = new BitmapClass();
	m_background->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/level_background.png", 1024*SCALE_X, 768*SCALE_Y);

	// Dialogue
	m_dialogueBackground = new BitmapClass();
	m_dialogueBackground->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/level_message.png", 481*SCALE_X, 275*SCALE_Y);
	
	m_gameOverDialogue = new BitmapClass();
	m_gameOverDialogue->Initialize(D3DClass::GetInstance()->GetDevice(), 
		SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/game_over.png", 
		481*SCALE_X, 275*SCALE_Y);

	// Lives
	m_livesImage = new BitmapClass();
	m_livesImage->Initialize(D3DClass::GetInstance()->GetDevice(), 
		SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_lives.png", 150*SCALE_X, 35*SCALE_Y);

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
	m_numBlocks = 17*21;
	m_blocks = new Block*[m_numBlocks];
	for (int i=0; i<m_numBlocks; ++i)
	{
		m_blocks[i] = 0;
	}
	m_level1 = new int[m_numBlocks];
	for (int i=0; i<m_numBlocks; ++i)
	{
		m_level1[i] = 0;
	}
	m_level2 = new int[m_numBlocks];
	for (int i=0; i<m_numBlocks; ++i)
	{
		m_level2[i] = 0;
	}
	m_level3 = new int[m_numBlocks];
	for (int i=0; i<m_numBlocks; ++i)
	{
		m_level3[i] = 0;
	}

	// Load level info from file
	loadFromFile("../Engine/data/level_1.txt", m_level1);
	loadFromFile("../Engine/data/level_2.txt", m_level2);
	loadFromFile("../Engine/data/level_3.txt", m_level3);

	debug ("LevelScreen: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
LevelScreen::~LevelScreen() {

	// Clean up all dynamic objects
	delete m_background; m_background = 0;
	delete m_dialogueBackground; m_dialogueBackground = 0;
	delete m_gameOverDialogue; m_gameOverDialogue = 0;
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
	delete[] m_level1; m_level1 = 0;
	delete[] m_level2; m_level2 = 0;
	delete[] m_level3; m_level3 = 0;
	m_numBlocks = 0;
	

	debug ("LevelScreen: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
int LevelScreen::logic() {
	debug ("LevelScreen: logic() called.", 10);
    
	// Check if it's game over
	if (m_gameOver)
	{
		// Check for click
		if((InputClass::GetInstance())->IsMouseButtonPressed(0))
			done = true;
		return error;
	}

	// Check if it's time to load the next level
	if(m_activeBlocks <= 0)
	{
		// Display the dialogue
		if (!m_dialogue)
		{
			++m_levelNumber;
			m_dialogue = true;
			return error;
		}

		// Load next level
		loadNext();

		// Increase speed of ball
		m_ball->IncreaseSpeed();

		// Reset ball location
		m_ball->Respawn();
	}

	// Once the new level is loaded, check for mouse click to close dialogue
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
	{
		m_ball->Respawn();
		--m_lives;
	}

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

	// Check if we've used up all our lives
	if (m_lives <= 0)
	{
		m_gameOver = true;
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
    
	// Check if it's game over
	if (m_gameOver)
	{
		// Display level dialogue
		GraphicsClass::GetInstance()->BitmapRender(*m_gameOverDialogue, (SCREEN_WIDTH-481*SCALE_X)/2, (SCREEN_HEIGHT-275*SCALE_Y)/2);

		return error;
	}

	if(m_dialogue)
	{
		// Display level dialogue
		GraphicsClass::GetInstance()->BitmapRender(*m_dialogueBackground, (SCREEN_WIDTH-481*SCALE_X)/2, (SCREEN_HEIGHT-275*SCALE_Y)/2);

		// Determine level to display
		int level = m_levelNumber;
		int hundreds = ((int)floor((float)level/100))%10;
		int tens = ((int)floor((float)level/10))%10;
		int ones = level%10;

		// Display numbers
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundreds]), 
			(SCREEN_WIDTH-26*SCALE_X)/2-26*SCALE_X-5*SCALE_X, (SCREEN_HEIGHT-35*SCALE_Y)/2);
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tens]), 
			(SCREEN_WIDTH-26*SCALE_X)/2, (SCREEN_HEIGHT-35*SCALE_Y)/2);
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[ones]), 
			(SCREEN_WIDTH-26*SCALE_X)/2+26*SCALE_X+5*SCALE_X, (SCREEN_HEIGHT-35*SCALE_Y)/2);
	}
	else if(m_dialogue)
	{
		// Display level dialogue
		GraphicsClass::GetInstance()->BitmapRender(*m_gameOverDialogue, (SCREEN_WIDTH-481*SCALE_X)/2, (SCREEN_HEIGHT-275*SCALE_Y)/2);
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

		// Draw UI
		GraphicsClass::GetInstance()->BitmapRender(*(m_livesImage), 
			(SCREEN_WIDTH-400*SCALE_X), 0);
		if (m_lives < 0) m_lives = 0;
		if (m_lives > 9) m_lives = 9;
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[m_lives]), 
			(SCREEN_WIDTH-400*SCALE_X)+150*SCALE_X, 0);

		
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

	// Set up the ball
	m_ball->Respawn();
	m_ball->ResetSpeed();

	// Reset lives
	m_lives = 3;

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
void LevelScreen::loadFromFile(const char* fileName, int* levelInfo)
{
	debug ("LevelScreen: loadFromFile called.");
	int i (0);
	
	ifstream inFile;  // object for reading from a file
	inFile.open(fileName, ios::in);
	if (!inFile) {
		debug("LevelScreen: can't open level file.");
		return;
	}

	while (!inFile.eof()) 
	{
		// read in this block
		inFile >> levelInfo[i];

		// increment
		++i;
	}


}

// |----------------------------------------------------------------------------|
// |							     loadNext()									|
// |----------------------------------------------------------------------------|
void LevelScreen::loadNext()
{
	// Variables
	int index = (m_levelNumber-1)%3;
	int* levelInfo;
	int x(0), y(0);
	const int PADDING(5);
	const int XUNIT(50*SCALE_X	+ PADDING*SCALE_X), YUNIT(20*SCALE_Y	+ PADDING*SCALE_Y);
	const int XSTART( (SCREEN_WIDTH - 50*SCALE_X)/2		- 8  * XUNIT );
	const int YSTART( (SCREEN_HEIGHT-SCREEN_HEIGHT*0.3)	- 20 * YUNIT );

	// Determine which info contains this level
	if (index == 0)
		levelInfo=m_level1;
	else if (index == 1)
		levelInfo=m_level2;
	else if (index == 2)
		levelInfo=m_level3;

	// Set up the actual blocks based on this info
	for (int i=0; i<m_numBlocks;++i)
	{
		// Set up the block if there is one
		if(levelInfo[i])
		{
			m_blocks[i] = new Block();
			m_blocks[i]->Initialize();
			x = XSTART+(i%17)*XUNIT;
			y = YSTART+(floor(((float)i)/17))*YUNIT;
			m_blocks[i]->SetPosition(Coord(x,y));
			m_blocks[i]->SetType((BLOCK)(levelInfo[i]-1));
			++m_activeBlocks;
		}
	}
}