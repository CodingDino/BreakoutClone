// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Ball
//		Ball which can be fired by the player, and which bounces and hits 
//		objects 
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"
#include "Rectangle.h"
#include "Screen.h"
#include "InputClass.h"
#include "Player.h"

// |----------------------------------------------------------------------------|
// |					      Class Definition: Ball							|
// |----------------------------------------------------------------------------|
class Ball : public Rectangle {
	
public:

	Ball ();
	// Constructor

	~Ball ();
	// De-constructor

	int virtual logic();
	// Performs logic functions for the object

	bool isAttached();

	// Getter/Setter
	void SetPlayer(Player* player) { m_player = player; }
	
protected:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	double m_speed;
	bool m_attached;
	Player* m_player;

	// Ball sprites
	BitmapClass* m_green;	// Graphic
	BitmapClass* m_blue;	// Graphic
	BitmapClass* m_red;		// Graphic
	BitmapClass* m_orange;	// Graphic
	BitmapClass* m_yellow;	// Graphic
};
