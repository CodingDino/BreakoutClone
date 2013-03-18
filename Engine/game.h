// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Game
//		Holds game-wide variables and methods. Holds screens
//		and game-wide logic and draw loops (calls screen-specific loops).
//		Governs game-wide options and switching between screens.
#pragma once


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "MenuScreen.h"
#include "LevelScreen.h"
#include "ScoreScreen.h"


// |----------------------------------------------------------------------------|
// |						  Class Definition: Game							|
// |----------------------------------------------------------------------------|
class Game {

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	Game();
	Game(const Game&);
	~Game();

    // Initialization and shutdown
	bool virtual Initialize();
	bool virtual Shutdown();
    
	// Runs input, logic and draw in game loop.
	bool Frame();
    
	// Sets the current screen to the supplied screen index.
	bool ChangeScreen(SCREEN next_screen);
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Screens
	Screen* m_currentScreen;
	Screen** m_screens;

};