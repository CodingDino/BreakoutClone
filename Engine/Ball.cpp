// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Ball
//		Ball which can be fired by the player, and which bounces and hits 
//		objects 


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Ball.h"
#include <cmath>

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Ball::Ball()
{
	// Set player settings
	m_player = NULL;
	m_attached = true;

	// Set dimmensions
	m_dimmensions.x = 12*SCALE_X;
	m_dimmensions.y = 12*SCALE_Y;
	
	// Loading graphics into Image objects
	m_green = new BitmapClass();
	m_green->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_green.png", (int)m_dimmensions.x, (int)m_dimmensions.y);
	m_blue = new BitmapClass();
	m_blue->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_blue.png", (int)m_dimmensions.x, (int)m_dimmensions.y);
	m_red = new BitmapClass();
	m_red->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_red.png", (int)m_dimmensions.x, (int)m_dimmensions.y);
	m_orange = new BitmapClass();
	m_orange->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_orange.png", (int)m_dimmensions.x, (int)m_dimmensions.y);
	m_yellow = new BitmapClass();
	m_yellow->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_yellow.png", (int)m_dimmensions.x, (int)m_dimmensions.y);
	m_graphic = m_green;

	// Set location
	m_position.x = (float)(SCREEN_WIDTH -  (float)m_dimmensions.x)/2;
	m_position.y = (float)SCREEN_HEIGHT-SCREEN_HEIGHT*0.2;

	// Set speed
	m_speed = 7;

	debug ("Ball: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Ball::~Ball() {
	debug ("Ball: instance destroyed.");
}


// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int Ball::logic() {
	debug ("Ball: logic() called.", 10);

	// Fire ball if mouse button is pressed
	if (m_attached && m_player && (InputClass::GetInstance())->IsMouseButtonDown(0))
	{
		m_attached = false;
		m_velocity.y = (float)-1*m_speed*SCALE_Y;
	}

	// Move with paddle if attached
	if (m_attached && m_player)
	{
		m_position.x = (m_player->GetPosition()).x+((m_player->GetDimmensions()).x-m_dimmensions.x)/2;
		m_position.y = (m_player->GetPosition()).y-m_dimmensions.y;
	}
	else // Move based on velocity
	{
		m_position.x = m_position.x + m_velocity.x;
		m_position.y = m_position.y + m_velocity.y;
	}

	return m_error;
}

// |----------------------------------------------------------------------------|
// |						    HandleCollision()								|
// |----------------------------------------------------------------------------|
bool Ball::HandleCollision(RectangleClass* collider)
{
	Coord collider_position = collider->GetPosition();
	Coord collider_dimmensions = collider->GetDimmensions();

	// Determine side of collision and reverse proper direction
	//if ( (m_position.y < (collider_position.y+collider_dimmensions.y) )
	//		||( (m_position.y+m_dimmensions.y) > collider_position.y ) )
		m_velocity.y = -1 * m_velocity.y;
	//else
	//	m_velocity.x = -1 * m_velocity.x;

	return true;
}
