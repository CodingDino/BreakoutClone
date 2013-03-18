// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Game
//		Holds game-wide variables and methods. Holds screens
//		and game-wide logic and draw loops (calls screen-specific loops).
//		Governs game-wide options and switching between screens.


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Game.h"


// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Game::Game() :
	m_currentScreen(NULL),
	m_screens(NULL)
{
	debug ("Game: object instantiated.");
}
   

// |----------------------------------------------------------------------------|
// |							  Copy Constructor								|
// |----------------------------------------------------------------------------|
Game::Game(const Game&) {
	debug ("Game: object copied.");
}
	

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Game::~Game() {
	debug ("Game: object destroyed.");
}


// |----------------------------------------------------------------------------|
// |							  Initialize()									|
// |----------------------------------------------------------------------------|
bool Game::Initialize() {

	// Create screens - set first screen to TITLE
	m_screens = new Screen* [NUM_SCREENS];
	for (int i = 0 ; i < NUM_SCREENS; ++i) {
		m_screens[i] = NULL;
	}
	m_screens[MENU] = new MenuScreen();
    m_screens[MENU]->Initialize();
	m_screens[LEVEL] = new LevelScreen();
    m_screens[LEVEL]->Initialize();
	m_screens[SCORES] = new ScoreScreen();
    m_screens[SCORES]->Initialize();
	m_currentScreen = m_screens[MENU];
	bool result = m_currentScreen->OnLoad();
	
	if (result) debug("Game: initialisation failed.");
	else debug("Game: object initialised.");
	return (result);
}


// |----------------------------------------------------------------------------|
// |							    Shutdown									|
// |----------------------------------------------------------------------------|
bool Game::Shutdown() {

	// Screen Cleanup
	if (m_screens) {
		for (int i = 0 ; i < NUM_SCREENS; ++i) {
            if (m_screens[i])
            {
                m_screens[i]->Shutdown();
                delete m_screens[i];
                m_screens[i] = 0;
            }
		}
		delete[] m_screens;
        m_screens = 0;
	}

	debug ("Game: object shutdown.");
	return true;
}


// |----------------------------------------------------------------------------|
// |								 run()										|
// |----------------------------------------------------------------------------|
bool Game::Frame() {
    bool result;

	// Game logic (pass in mouse coordinates)
	result = m_currentScreen->Logic();
    if (!result) return false;

	// If it's time to redraw and there are no other events waiting  
	result = m_currentScreen->Draw();
    if (!result) return false;

	// If the current screen is done, switch to the new screen
	if (m_currentScreen->IsDone()) {
		debug("Game: current screen done");

		// Perform onExit functions for the old screen
		result = m_currentScreen->OnExit();
        if (!result) return false;

		// Check if the screen is telling the game to quit.
		if (m_currentScreen->GetNextScreen() == QUIT) {
			debug("Game: quitting");
			// If so, quit.
			return false;
		}

		// If the screen is NOT telling the game to quit, load the next screen
		else {
			debug("Game: moving to next screen");
			// Set the new screen as current
			m_currentScreen = m_screens[m_currentScreen->GetNextScreen()];
			// Perform onLoad functions for the new screen
			result = m_currentScreen->OnLoad();
            if (!result) return false;
		}

	}

	return true;
}