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
	m_green->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_green.png", m_dimmensions.x, m_dimmensions.y);
	m_blue = new BitmapClass();
	m_blue->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_blue.png", m_dimmensions.x, m_dimmensions.y);
	m_red = new BitmapClass();
	m_red->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_red.png", m_dimmensions.x, m_dimmensions.y);
	m_orange = new BitmapClass();
	m_orange->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_orange.png", m_dimmensions.x, m_dimmensions.y);
	m_yellow = new BitmapClass();
	m_yellow->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, L"../Engine/data/ball_yellow.png", m_dimmensions.x, m_dimmensions.y);
	m_graphic = m_green;

	// Set location
	m_position.x = (SCREEN_WIDTH - m_dimmensions.x)/2;
	m_position.y = SCREEN_HEIGHT-SCREEN_HEIGHT*0.2;

	// Set speed
	m_speed = 10;

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
		m_velocity.y = -1*m_speed;
	}

	// Move with paddle if attached
	if (m_attached && m_player)
	{
		m_position.x = (m_player->GetPosition()).x+((m_player->GetDimmensions()).x-m_dimmensions.x)/2;
		m_position.y = (m_player->GetPosition()).y-m_dimmensions.y;
	}
	else
	{
		m_position.x = m_position.x + m_velocity.x;
		m_position.y = m_position.y + m_velocity.y;
	}

	return m_error;
}