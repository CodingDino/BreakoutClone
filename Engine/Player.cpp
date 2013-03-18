// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
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
// |							  Copy Constructor								|
// |----------------------------------------------------------------------------|
Player::Player(const Player&) {
	debug ("Player: object copied.");
}


// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Player::~Player() {
	debug ("Player: object destroyed.");
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
	m_graphic->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/paddle.png", (int)m_dimmensions.x, (int)m_dimmensions.y);

	// Set location
	m_position.x = (SCREEN_WIDTH - m_dimmensions.x)/2;
	m_position.y = (float)(SCREEN_HEIGHT-SCREEN_HEIGHT*0.1);

	debug ("Player: object initialized.");

	return true;
}


// |----------------------------------------------------------------------------|
// |							    Shutdown									|
// |----------------------------------------------------------------------------|
bool Player::Shutdown() {

    // Shutdown parent data
    RectangleClass::Shutdown();

	debug ("Player: object shutdown.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							    Logic()										|
// |----------------------------------------------------------------------------|
bool Player::Logic() {
	debug ("Player: Logic() called.", 10);

	// Set X coordinate to mouse x, clamp to screen
	int mouseX, mouseY;
	InputClass::GetInstance()->GetMouseLocation(mouseX,mouseY);
	int leftLimit, rightLimit;
	leftLimit = (int)((SCREEN_WIDTH - ((float)1024)*SCALE_X)/2+35*SCALE_X);
	rightLimit = (int)(SCREEN_WIDTH - leftLimit - m_dimmensions.x);
	m_position.x = (float)min(max(mouseX,leftLimit),rightLimit);

	return true;
}