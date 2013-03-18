// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// MenuScreen
//		Controls the image and buttons for the main menu of the game.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Screen.h"
#include "Util.h"
#include "Player.h"
#include "Ball.h"
#include "Rectangle.h"
#include "Block.h"
#include "Button.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: MenuScreen						|
// |----------------------------------------------------------------------------|
class MenuScreen : public Screen {

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	MenuScreen();
	MenuScreen(const MenuScreen&);
	~MenuScreen();

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
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Handles to Singleton Managers
	D3DClass* m_D3D;
	GraphicsClass* m_graphics;

	// Images
	BitmapClass* m_background;
	int m_backgroundX, m_backgroundY;

	// Objects
	Player* m_player;
	Ball* m_ball;
	RectangleClass* m_top;
	RectangleClass* m_left;
	RectangleClass* m_right;
	RectangleClass* m_bottom;

	// Buttons
	Button* m_start;
	Button* m_scores;
	Button* m_quit;

};