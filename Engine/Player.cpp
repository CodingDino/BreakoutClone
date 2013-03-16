// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Player
//		Controls the player object's position, movement, image, and actions. 


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Player.h"
#include <cmath>

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Player::Player()
{
	// Set dimmensions
	m_dimmensions.x = 101*SCALE_X;
	m_dimmensions.y = 20*SCALE_Y;
	
	// Loading graphics into Image objects
	m_graphic = new BitmapClass();
	m_graphic->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/paddle.png", m_dimmensions.x, m_dimmensions.y);

	// Set location
	m_position.x = SCREEN_WIDTH/2- m_dimmensions.x/2;
	m_position.y = SCREEN_HEIGHT-SCREEN_HEIGHT*0.1;

	debug ("Player: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Player::~Player() {
	debug ("Player: instance destroyed.");
}


// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int Player::logic(int mouse_x, int mouse_y) {
	debug ("Player: logic() called.", 10);

	//// Record mouse location
	//mouse_position = Coord(mouse_x, mouse_y);

	//// Move based on velocity
	//if(has_target) {
	//	Coord new_position = Coord(position+velocity);

	//	// Keep player in screen
	//	if (new_position.x+radius > SCREEN_W) new_position.x = SCREEN_W - radius;
	//	if (new_position.y+radius > SCREEN_H) new_position.y = SCREEN_H - radius;
	//	if (new_position.x-radius < 0) new_position.x = radius;
	//	if (new_position.y-radius < 0) new_position.y = radius;

	//	// See if we've reached destination
	//	if (abs(target.x - position.x) < abs(velocity.x)) new_position.x = target.x;
	//	if (abs(target.y - position.y) < abs(velocity.y)) new_position.y = target.y;
	//	if (target.x == new_position.x && target.y == new_position.y) has_target = false;

	//	setPosition(new_position);
	//}

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							    onMouseDown()								|
// |----------------------------------------------------------------------------|
int Player::onMouseDown(int button) {
	debug ("Player: onMouseDown() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							     onMouseUp()								|
// |----------------------------------------------------------------------------|
int Player::onMouseUp(int button) {
	debug ("Player: onMouseUp() called.");

	//has_target = true;
	//target = mouse_position;

	//// Set velocity to move towards mouse
	//// Get direction from target and position
	//velocity = target - position;
	//// Normalize to a magnitude of 1
	//double magnitude = sqrt(pow(velocity.x,2)+pow(velocity.y,2));
	//velocity /= magnitude;
	//// Scale by speed
	//velocity *= speed;

	return m_error;
}