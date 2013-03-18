// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// LevelScreen
//		Contains all objects pertaining to the main game level. Manages the
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
    m_numBlocks(0),
	m_activeBlocks(0),
	m_blocks(0),
	m_level1(0),
	m_level2(0),
	m_level3(0),
	m_dialogue(false),
	m_dialogueBackground(0),
	m_levelNumber(0),
    m_numbers(0),
	m_lives(3),
	m_livesImage(0),
	m_gameOver(false),
	m_gameOverDialogue(0),
    m_score(0),
	m_scoreImage(0),
    m_highScores(0),
    m_highScoreImage(0),
    m_highScoreGet(false)
{
	debug ("LevelScreen: object instantiated.");
}
    

// |----------------------------------------------------------------------------|
// |							  Copy Constructor								|
// |----------------------------------------------------------------------------|
LevelScreen::LevelScreen(const LevelScreen&) {
	debug ("LevelScreen: object copied.");
}


// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
LevelScreen::~LevelScreen() {
	debug ("LevelScreen: object destroyed.");
}


// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool LevelScreen::Initialize() {

	// Set MENU as the next screen after this one
	SetNextScreen(MENU); 

	// Background
	m_background = new BitmapClass();
	m_background->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/level_background.png", (int)(1024*SCALE_X), (int)(768*SCALE_Y));

	// Dialogue
	m_dialogueBackground = new BitmapClass();
	m_dialogueBackground->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/level_message.png", (int)(481*SCALE_X), (int)(275*SCALE_Y));
	
	m_gameOverDialogue = new BitmapClass();
	m_gameOverDialogue->Initialize(D3DClass::GetInstance()->GetDevice(), 
		SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/game_over.png", 
		(int)(481*SCALE_X), (int)(275*SCALE_Y));

	// Lives
	m_livesImage = new BitmapClass();
	m_livesImage->Initialize(D3DClass::GetInstance()->GetDevice(), 
		SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_lives.png",
		(int)(150*SCALE_X), (int)(35*SCALE_Y));

    // Score
	m_scoreImage = new BitmapClass();
	m_scoreImage->Initialize(D3DClass::GetInstance()->GetDevice(), 
		SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_score.png",
		(int)(150*SCALE_X), (int)(35*SCALE_Y));
	m_highScoreImage = new BitmapClass();
	m_highScoreImage->Initialize(D3DClass::GetInstance()->GetDevice(), 
		SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/high_score.png",
		(int)(481*SCALE_X), (int)(275*SCALE_Y));

	// Numbers
	m_numbers = new BitmapClass*[10];
	m_numbers[0] = new BitmapClass();
	m_numbers[0]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_0.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[1] = new BitmapClass();
	m_numbers[1]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_1.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[2] = new BitmapClass();
	m_numbers[2]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_2.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[3] = new BitmapClass();
	m_numbers[3]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_3.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[4] = new BitmapClass();
	m_numbers[4]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_4.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[5] = new BitmapClass();
	m_numbers[5]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_5.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[6] = new BitmapClass();
	m_numbers[6]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_6.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[7] = new BitmapClass();
	m_numbers[7]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_7.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[8] = new BitmapClass();
	m_numbers[8]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_8.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));
	m_numbers[9] = new BitmapClass();
	m_numbers[9]->Initialize(D3DClass::GetInstance()->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, 
		L"../Engine/data/font_9.png", (int)(26*SCALE_X), (int)(35*SCALE_Y));

	// Player and Ball
	m_player = new Player();
	m_player->Initialize();

	m_ball = new Ball();
	m_ball->Initialize();
	m_ball->SetPlayer(m_player);

	// Stage borders
	m_top = new RectangleClass();
	m_top->Initialize();
	m_top->SetDimmensions(Coord((float)SCREEN_WIDTH,(float)35*SCALE_Y));
	m_top->SetPosition(Coord(0,0));

	m_left = new RectangleClass();
	m_left->Initialize();
	m_left->SetDimmensions(Coord(35*SCALE_X,(float)768*SCALE_Y));
	m_left->SetPosition(Coord((SCREEN_WIDTH-1024*SCALE_X)/2,0));

	m_right = new RectangleClass();
	m_right->Initialize();
	m_right->SetDimmensions(Coord(35*SCALE_X,768*SCALE_Y));
	m_right->SetPosition(Coord(SCREEN_WIDTH-(SCREEN_WIDTH-1024*SCALE_X)/2-35*SCALE_X,0));

	m_bottom = new RectangleClass();
	m_bottom->Initialize();
	m_bottom->SetDimmensions(Coord((float)SCREEN_WIDTH,(float)35*SCALE_Y));
	m_bottom->SetPosition(Coord(0.0f,(float)(SCREEN_HEIGHT+20)));

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
	LoadFromFile("../Engine/data/level_1.txt", m_level1);
	LoadFromFile("../Engine/data/level_2.txt", m_level2);
	LoadFromFile("../Engine/data/level_3.txt", m_level3);

    // High Scores
    m_highScores = new int[20];
    for (int i(0); i<20; ++i)
    {
        m_highScores[i] = 0;
    }
    
	debug ("LevelScreen: object initialized.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							    Shutdown									|
// |----------------------------------------------------------------------------|
bool LevelScreen::Shutdown() {

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
    if (m_dialogueBackground)
    {
        m_dialogueBackground->Shutdown();
        delete m_dialogueBackground;
        m_dialogueBackground = 0;
    }
    if (m_livesImage)
    {
        m_livesImage->Shutdown();
        delete m_livesImage;
        m_livesImage = 0;
    }
    if (m_gameOverDialogue)
    {
        m_gameOverDialogue->Shutdown();
        delete m_gameOverDialogue;
        m_gameOverDialogue = 0;
    }
    if (m_scoreImage)
    {
        m_scoreImage->Shutdown();
        delete m_scoreImage;
        m_scoreImage = 0;
    }
    if (m_highScoreImage)
    {
        m_highScoreImage->Shutdown();
        delete m_highScoreImage;
        m_highScoreImage = 0;
    }


	// Array Cleanup
	if (m_blocks) {
		for (int i = 0 ; i < m_numBlocks; ++i) {
            if (m_blocks[i])
            {
                m_blocks[i]->Shutdown();
                delete m_blocks[i];
                m_blocks[i] = 0;
            }
		}
		delete[] m_blocks;
        m_blocks = 0;
	}
	if (m_level1) {
		delete[] m_level1;
        m_level1 = 0;
	}
	if (m_level2) {
		delete[] m_level2;
        m_level2 = 0;
	}
	if (m_level3) {
		delete[] m_level3;
        m_level3 = 0;
	}
	if (m_numbers) {
		for (int i = 0 ; i < 9; ++i) {
            if (m_numbers[i])
            {
                m_numbers[i]->Shutdown();
                delete m_numbers[i];
                m_numbers[i] = 0;
            }
		}
		delete[] m_numbers;
        m_numbers = 0;
	}
	if (m_highScores) {
		delete[] m_highScores;
        m_highScores = 0;
	}

	debug ("LevelScreen: object shutdown.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							     Logic()									|
// |----------------------------------------------------------------------------|
// The logic function, which will be called by the main game loop.
bool LevelScreen::Logic() {
	debug ("LevelScreen: Logic() called.", 10);
    
	// Check if it's game over
	if (m_gameOver)
	{
		// Check for click
		if((InputClass::GetInstance())->IsMouseButtonPressed(0))
			m_done = true;
		return true;
	}

	// Check if it's time to load the next level
	if(m_activeBlocks <= 0)
	{
		// Display the dialogue
		if (!m_dialogue)
		{
			++m_levelNumber;
			m_dialogue = true;
			return true;
		}

		// Load next level
		LoadNext();

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
		return true;
	}

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
	{
		m_ball->Respawn();
		--m_lives;
	}

	// Player Collisions
	if(m_ball->Collision(m_player))
    {
		m_ball->PlayerCollide(m_player);
        SoundClass::GetInstance()->PlayBounce();
    }

	// Block Collisions
	for (int i=0; i<m_numBlocks; ++i)
	{
		if (m_blocks[i])
		{
			if(m_ball->Collision(m_blocks[i]))
            {
                m_score += 50;
			    if(m_blocks[i]->IsDead())
			    {
				    delete m_blocks[i];
				    m_blocks[i] = 0;
				    --m_activeBlocks;
                    m_score += 50;
                    SoundClass::GetInstance()->PlayBreak();
			    }
                else
                {
                    SoundClass::GetInstance()->PlayBounce();
                }
            }
		}
	}

	// Check if we've used up all our lives
	if (m_lives <= 0)
	{
		m_gameOver = true;

        // Check for high score
        if (m_score > m_highScores[19])
        {
            m_highScoreGet = true;
            int prev_score = m_score;
            int next_score = m_score;
            for (int i=0; i<20; ++i)
            {
                if (prev_score >= m_highScores[i])
                {
                    next_score = m_highScores[i];
                    m_highScores[i] = prev_score;
                    prev_score = next_score;
                }
            }
            SaveScoresToFile();
        }
	}

	return true;
}

// |----------------------------------------------------------------------------|
// |							     Draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the main game loop.
bool LevelScreen::Draw() {
	debug ("LevelScreen: Draw() called.", 10);
	
	// Draw Background
	if (m_background)
		GraphicsClass::GetInstance()->BitmapRender(*m_background, (SCREEN_WIDTH-min(SCREEN_WIDTH,1024*SCREEN_HEIGHT/768))/2, 0);
    
	// Check if it's game over
	if (m_gameOver)
	{
        if (m_highScoreGet)
        {
		    GraphicsClass::GetInstance()->BitmapRender(*m_highScoreImage, 
                (int)((SCREEN_WIDTH-481*SCALE_X)/2), (int)((SCREEN_HEIGHT-275*SCALE_Y)/2));

            int START_X = (int)((SCREEN_WIDTH-7*(26*SCALE_X))/2);
            int START_Y = (int)((SCREEN_HEIGHT-275*SCALE_Y)/2+275*SCALE_Y*0.6);
            
		    int millions = ((int)floor((float)m_score/1000000))%10;
		    int hundredthousands = ((int)floor((float)m_score/100000))%10;
		    int tenthousands = ((int)floor((float)m_score/10000))%10;
		    int thousands = ((int)floor((float)m_score/1000))%10;
		    int hundreds = ((int)floor((float)m_score/100))%10;
		    int tens = ((int)floor((float)m_score/10))%10;
		    int ones = m_score%10;
		    GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[millions]), 
			    (int)(START_X+0*(26*SCALE_X)), START_Y);
		    GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundredthousands]), 
			    (int)(START_X+1*(26*SCALE_X)), START_Y);
		    GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tenthousands]),  
			    (int)(START_X+2*(26*SCALE_X)), START_Y);
		    GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[thousands]),
			    (int)(START_X+3*(26*SCALE_X)), START_Y);
		    GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundreds]), 
			    (int)(START_X+4*(26*SCALE_X)), START_Y);
		    GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tens]), 
			    (int)(START_X+5*(26*SCALE_X)), START_Y);
		    GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[ones]), 
			    (int)(START_X+6*(26*SCALE_X)), START_Y);

        }
        else
		    GraphicsClass::GetInstance()->BitmapRender(*m_gameOverDialogue, 
                (int)((SCREEN_WIDTH-481*SCALE_X)/2), (int)((SCREEN_HEIGHT-275*SCALE_Y)/2));

		return true;
	}

	if(m_dialogue)
	{
		// Display level dialogue
		GraphicsClass::GetInstance()->BitmapRender(*m_dialogueBackground, (int)((SCREEN_WIDTH-481*SCALE_X)/2), (int)((SCREEN_HEIGHT-275*SCALE_Y)/2));

		// Determine level to display
		int level = m_levelNumber;
		int hundreds = ((int)floor((float)level/100))%10;
		int tens = ((int)floor((float)level/10))%10;
		int ones = level%10;

		// Display numbers
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundreds]), 
			(int)((SCREEN_WIDTH-26*SCALE_X)/2-26*SCALE_X-5*SCALE_X), (int)((SCREEN_HEIGHT-35*SCALE_Y)/2));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tens]), 
			(int)((SCREEN_WIDTH-26*SCALE_X)/2), (int)((SCREEN_HEIGHT-35*SCALE_Y)/2));
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[ones]), 
			(int)((SCREEN_WIDTH-26*SCALE_X)/2+26*SCALE_X+5*SCALE_X), (int)((SCREEN_HEIGHT-35*SCALE_Y)/2));
	}
	else if(m_dialogue)
	{
		// Display level dialogue
		GraphicsClass::GetInstance()->BitmapRender(*m_gameOverDialogue, (int)((SCREEN_WIDTH-481*SCALE_X)/2), (int)((SCREEN_HEIGHT-275*SCALE_Y)/2));
	}
	else
	{
		// Draw blocks
		for (int i=0; i<m_numBlocks; ++i)
		{
			if(m_blocks[i])
				m_blocks[i]->Draw();
		}

		// Draw player and ball
		if (m_player)
			m_player->Draw();
		if (m_ball)
			m_ball->Draw();

		// Draw UI
		GraphicsClass::GetInstance()->BitmapRender(*(m_livesImage), 
			(int)(SCREEN_WIDTH-400*SCALE_X), 0);
		if (m_lives < 0) m_lives = 0;
		if (m_lives > 9) m_lives = 9;
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[m_lives]), 
			(int)((SCREEN_WIDTH-400*SCALE_X)+150*SCALE_X), 0);
        
		GraphicsClass::GetInstance()->BitmapRender(*(m_scoreImage), 
			(int)(220*SCALE_X), 0);
		int millions = ((int)floor((float)m_score/1000000))%10;
		int hundredthousands = ((int)floor((float)m_score/100000))%10;
		int tenthousands = ((int)floor((float)m_score/10000))%10;
		int thousands = ((int)floor((float)m_score/1000))%10;
		int hundreds = ((int)floor((float)m_score/100))%10;
		int tens = ((int)floor((float)m_score/10))%10;
		int ones = m_score%10;
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[millions]), 
			(int)((220*SCALE_X+150*SCALE_X)+0*(26*SCALE_X)), 0);
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundredthousands]), 
			(int)((220*SCALE_X+150*SCALE_X)+1*(26*SCALE_X)), 0);
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tenthousands]),  
			(int)((220*SCALE_X+150*SCALE_X)+2*(26*SCALE_X)), 0);
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[thousands]),  
			(int)((220*SCALE_X+150*SCALE_X)+3*(26*SCALE_X)), 0);
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[hundreds]),  
			(int)((220*SCALE_X+150*SCALE_X)+4*(26*SCALE_X)), 0);
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[tens]),  
			(int)((220*SCALE_X+150*SCALE_X)+5*(26*SCALE_X)), 0);
		GraphicsClass::GetInstance()->BitmapRender(*(m_numbers[ones]),  
			(int)((220*SCALE_X+150*SCALE_X)+6*(26*SCALE_X)), 0);
		
	}

	return true;
}

// |----------------------------------------------------------------------------|
// |							    OnLoad()									|
// |----------------------------------------------------------------------------|
// Called when the screen is loaded.
bool LevelScreen::OnLoad() {
	debug ("LevelScreen: OnLoad called.");

	// Screen is not done
	m_done = false;

	// Set up the ball
	m_ball->Respawn();
	m_ball->ResetSpeed();

	// Reset lives
	m_lives = 3;

    // Reset score
    m_score = 0;
    
    // Load high scores
    LoadScoresFromFile();
    m_highScoreGet = false;

	return true;
}

// |----------------------------------------------------------------------------|
// |							    OnExit()									|
// |----------------------------------------------------------------------------|
// Called when switching to a different screen
bool LevelScreen::OnExit() {
	debug ("LevelScreen: OnExit called.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							  LoadFromFile()								|
// |----------------------------------------------------------------------------|
void LevelScreen::LoadFromFile(const char* fileName, int* levelInfo)
{
	debug ("LevelScreen: LoadFromFile called.");
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
// |							     LoadNext()									|
// |----------------------------------------------------------------------------|
void LevelScreen::LoadNext()
{
	// Variables
	int index = (m_levelNumber-1)%3;
	int* levelInfo;
	int x(0), y(0);
	const int PADDING(5);
	const int XUNIT((int)(50*SCALE_X	+ PADDING*SCALE_X)), YUNIT((int)(20*SCALE_Y	+ PADDING*SCALE_Y));
	const int XSTART( (int)((SCREEN_WIDTH - 50*SCALE_X)/2		- 8  * XUNIT) );
	const int YSTART( (int)((SCREEN_HEIGHT-SCREEN_HEIGHT*0.3)	- 20 * YUNIT) );

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
			y = (int)(YSTART+(floor(((float)i)/17))*YUNIT);
			m_blocks[i]->SetPosition(Coord((float)x,(float)y));
			m_blocks[i]->SetType((BLOCK)(levelInfo[i]-1));
			++m_activeBlocks;
		}
	}
}


// |----------------------------------------------------------------------------|
// |							LoadScoresFromFile()							|
// |----------------------------------------------------------------------------|
void LevelScreen::LoadScoresFromFile()
{
	debug ("LevelScreen: LoadScoresFromFile called.");
	int i (0);
	
	ifstream inFile;  // object for reading from a file
	inFile.open("../Engine/data/high_scores.txt", ios::in);
	if (!inFile) {
		debug("LevelScreen: can't open score file.");
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


// |----------------------------------------------------------------------------|
// |							  SaveScoresToFile()							|
// |----------------------------------------------------------------------------|
void LevelScreen::SaveScoresToFile()
{
	debug ("LevelScreen: SaveScoresToFile called.");
	int i (0);
	
	ofstream outFile;  // object for reading from a file
	outFile.open("../Engine/data/high_scores.txt", ios::out);
	if (!outFile) {
		debug("LevelScreen: can't open score file.");
		return;
	}

    for (int i(0); i<20; ++i)
    {
        outFile << m_highScores[i] << " ";
    }

}