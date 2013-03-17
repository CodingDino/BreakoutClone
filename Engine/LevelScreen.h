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
#include "Util.h"
#include "Screen.h"
#include "graphicsclass.h"
#include "Player.h"
#include "Ball.h"
#include "Block.h"
#include "inputclass.h"
#include <iostream>
#include <fstream>
using namespace std;

// |----------------------------------------------------------------------------|
// |						  Class Definition: LevelScreen						|
// |----------------------------------------------------------------------------|
class LevelScreen : public Screen {

public:

	LevelScreen ();
	// Constructor

	~LevelScreen();
	// Destructor

	int virtual logic();
	// The logic function, which will be called by the main game loop.

	int virtual draw();
	// The draw function, which will be called by the main game loop.

	int virtual onLoad();
	// Called when the screen is loaded.

	int virtual onExit();
	// Called when switching to a different screen

	void loadFromFile(const char* fileName, int* levelInfo);
	// Loads a level from file

	void loadNext();
	// Loads the next level
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Images
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
};