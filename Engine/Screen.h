// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Screen
//		Contains all objects pertaining to a particular screen. Manages the
//		logic and draw loops for that screen. A screen is a superclass,
//		intended to be inherited by subclasses.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "graphicsclass.h"
#include "D3DClass.h"
#include "SoundClass.h"

// |----------------------------------------------------------------------------|
// |								enum SCREEN									|
// |----------------------------------------------------------------------------|
enum SCREEN {MENU, LEVEL, SCORES, NUM_SCREENS, QUIT};

// |----------------------------------------------------------------------------|
// |						  Class Definition: Screen							|
// |----------------------------------------------------------------------------|
class Screen {

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
    Screen() : m_done(0), m_nextScreen(QUIT) {}
    Screen(const Screen&) {}
    ~Screen() {}

    // Initialization and shutdown
	bool virtual Initialize() {return true;}
	bool virtual Shutdown() {return true;}
    
	// The logic function, which will be called by the main game loop.
	// TO BE IMPLEMENTED BY SUB CLASS
	bool virtual Logic() = 0;
    
	// The draw function, which will be called by the main game loop.
	// TO BE IMPLEMENTED BY SUB CLASS
	bool virtual Draw() = 0;
    
	// Called when the screen is loaded.
	// TO BE IMPLEMENTED BY SUB CLASS
	bool virtual OnLoad() = 0;
    
	// Called when switching to a different screen
	// TO BE IMPLEMENTED BY SUB CLASS
	bool virtual OnExit() = 0;
    
	// Returns whether the screen is done (ready to close) or not.
	bool virtual IsDone() { return m_done; }
    
	// Tells the game class what screen to load after this one
	SCREEN virtual GetNextScreen()  { return m_nextScreen; }
    
	// Sets the screen that will be loaded after this one
	void virtual SetNextScreen(SCREEN new_next) { m_nextScreen= new_next; }
    
	// Sets whether the screen will quit or not
	void virtual SetDone(bool new_done) { m_done = new_done; }
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	bool m_done;
	SCREEN m_nextScreen;

};