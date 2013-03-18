// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// ScoreScreen
//		Contains all objects pertaining to the score screen. Manages the
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
#include "Button.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: ScoreScreen						|
// |----------------------------------------------------------------------------|
class ScoreScreen : public Screen {

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	ScoreScreen();
	ScoreScreen(const ScoreScreen&);
	~ScoreScreen();

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
	void LoadScoresFromFile();
	
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

	// Button
	Button* m_menu;

    // Score
	BitmapClass** m_numbers;
	BitmapClass* m_colon;
	BitmapClass* m_highScoresTitle;
    int* m_highScores;
};