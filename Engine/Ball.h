// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
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

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Methods   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	// Constructors and Destructors
	Ball();
	Ball(const Ball&);
	~Ball();

    // Initialization and shutdown
	bool virtual Initialize();
	bool virtual Shutdown();
    
	// Performs logic functions for the object
	bool virtual Logic();
    
	// Changes to next color
	void virtual ColorChange();
    
	// Checks if ball is attached to the paddle
	bool isAttached();
    
	// Attaches the ball back to the paddle
	void Respawn();
    
	// Increases the speed
	void IncreaseSpeed() {m_speed += 1;}
    
	// Return speed to start speed
	void ResetSpeed() {m_speed = START_SPEED;}

    // Collision
	bool virtual HandleCollision(RectangleClass* collider);
	bool virtual PlayerCollide(Player* collider);

	// Setter functions
	void SetPlayer(Player* player) { m_player = player; }

	
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
