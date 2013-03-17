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

#define START_SPEED 7

// |----------------------------------------------------------------------------|
// |					      Class Definition: Ball							|
// |----------------------------------------------------------------------------|
class Ball : public RectangleClass {
	
public:

	Ball ();
	// Constructor

	~Ball ();
	// De-constructor

	bool virtual Initialize();
	// Sets up the rectangle

	int virtual logic();
	// Performs logic functions for the object

	bool isAttached();
	// Checks if ball is attached to the paddle

	void Respawn();
	// Attaches the ball back to the paddle

	void ColorChange();
	// Changes to next color

	void IncreaseSpeed() {m_speed += 1;}
	// Increases the speed

	void ResetSpeed() {m_speed = START_SPEED;}
	// Return speed to start speed

	// Getter/Setter
	void SetPlayer(Player* player) { m_player = player; }

	bool virtual HandleCollision(RectangleClass* collider);
	bool virtual PlayerCollide(Player* collider);
	
protected:
	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	double m_speed;
	bool m_attached;
	Player* m_player;

	// Ball sprites
	int m_spriteIndex;
	BitmapClass* m_green;	
	BitmapClass* m_blue;	
	BitmapClass* m_red;		
	BitmapClass* m_orange;	
	BitmapClass* m_yellow;	
};
