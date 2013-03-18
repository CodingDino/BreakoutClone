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
#include "Util.h"
#include "Screen.h"
#include "graphicsclass.h"
#include "Player.h"
#include "Ball.h"
#include "Block.h"
#include "inputclass.h"
#include "SoundClass.h"
#include <iostream>
#include <fstream>
using namespace std;

// |----------------------------------------------------------------------------|
// |						  Class Definition: LevelScreen						|
// |----------------------------------------------------------------------------|
class LevelScreen : public Screen {

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	LevelScreen();
	LevelScreen(const LevelScreen&);
	~LevelScreen();

    // Initialization and shutdown
	bool virtual Initialize();
	bool virtual Shutdown();
    
	// The logic function, which will be called by the main game loop.
	bool virtual Logic();
    
	// The draw function, which will be called by the main game loop.
	bool virtual Draw();
    
	// Called when the screen is loaded.
	bool virtual OnLoad();
    
	// Called when switching to a different screen
	bool virtual OnExit();
    
	// File loading and saving
	void LoadFromFile(const char* fileName, int* levelInfo);
	void LoadNext();
	void LoadScoresFromFile();
	void SaveScoresToFile();
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Background
	BitmapClass* m_background;

	// Objects
	Player* m_player;
	Ball* m_ball;
	RectangleClass* m_top;
	RectangleClass* m_left;
	RectangleClass* m_right;
	RectangleClass* m_bottom;

	// Blocks
	int m_numBlocks;
	int m_activeBlocks;
	Block** m_blocks;
	int* m_level1;
	int* m_level2;
	int* m_level3;

	// Level info
	bool m_dialogue;
	BitmapClass* m_dialogueBackground;
	int m_levelNumber;
	BitmapClass** m_numbers;

	// Lives
	int m_lives;
	BitmapClass* m_livesImage;
	bool m_gameOver;
	BitmapClass* m_gameOverDialogue;

    // Score
    int m_score;
	BitmapClass* m_scoreImage;
    int* m_highScores;
	BitmapClass* m_highScoreImage;
    bool m_highScoreGet;

};