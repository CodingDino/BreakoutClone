// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Block
//		Block which collides with ball and knocks it away, getting hurt or 
//		destroyed in the process.


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Block.h"
#include <cmath>

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Block::Block()
{
	// Hit Points
	m_hp = 1;

	// Set dimmensions
	m_dimmensions.x = 50*SCALE_X;
	m_dimmensions.y = 20*SCALE_Y;
	
	// Loading graphics into Image objects
	m_graphic = new BitmapClass();
	m_graphic->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/yellow.png", m_dimmensions.x, m_dimmensions.y);

	// Set location
	m_position.x = (SCREEN_WIDTH - m_dimmensions.x)/2;
	m_position.y = SCREEN_HEIGHT-SCREEN_HEIGHT*0.3;

	debug ("Block: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Block::~Block() {
	debug ("Block: instance destroyed.");
}


// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int Block::logic() {
	debug ("Block: logic() called.", 10);

	return m_error;
}


// |----------------------------------------------------------------------------|
// |						    HandleCollision()								|
// |----------------------------------------------------------------------------|
bool Block::HandleCollision(RectangleClass* collider)
{
	
	if (m_hp > 0 ) --m_hp;

	// TODO: Increment score if dead;

	return true;
}