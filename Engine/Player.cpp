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

	debug ("Player: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool Player::Initialize() {

	// Set dimmensions
	m_dimmensions.x = 101*SCALE_X;
	m_dimmensions.y = 20*SCALE_Y;
	
	// Loading graphics into Image objects
	m_graphic = new BitmapClass();
	m_graphic->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/paddle.png", m_dimmensions.x, m_dimmensions.y);

	// Set location
	m_position.x = (SCREEN_WIDTH - m_dimmensions.x)/2;
	m_position.y = SCREEN_HEIGHT-SCREEN_HEIGHT*0.1;

	debug ("Player: object initialized.");

	return true;
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
int Player::logic() {
	debug ("Player: logic() called.", 10);

	// Set X coordinate to mouse x, clamp to screen
	int mouseX, mouseY;
	InputClass::GetInstance()->GetMouseLocation(mouseX,mouseY);
	int leftLimit, rightLimit;
	leftLimit = (SCREEN_WIDTH - ((float)1024)*SCALE_X)/2+35*SCALE_X;
	rightLimit = SCREEN_WIDTH - leftLimit - m_dimmensions.x;
	m_position.x = min(max(mouseX,leftLimit),rightLimit);

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