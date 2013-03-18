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
Ball::Ball() :
	m_spriteIndex(0),
	m_green(0),
	m_blue(0),
	m_red(0),
	m_orange(0),
	m_yellow(0)
{

	debug ("Ball: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool Ball::Initialize() {
	
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
	m_speed = START_SPEED;

	debug ("Ball: object initialized.");

	return true;
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
	if (m_attached && m_player && (InputClass::GetInstance())->IsMouseButtonPressed(0))
	{
		m_attached = false;
		m_velocity.y = (float)-1*m_speed;
		m_velocity.x = 0;
        SoundClass::GetInstance()->PlayFire();
	}

	// Move with paddle if attached
	if (m_attached && m_player)
	{
		m_position.x = (m_player->GetPosition()).x+((m_player->GetDimmensions()).x-m_dimmensions.x)/2;
		m_position.y = (m_player->GetPosition()).y-m_dimmensions.y-1;
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
	Coord y_position = collider->GetPosition();
	Coord y_dimmensions = collider->GetDimmensions();
	//Coord y_velocity = collider->GetDimmensions();
	int me_top(m_position.y), me_bottom(m_position.y+m_dimmensions.y), me_left(m_position.x), me_right(m_position.x+m_dimmensions.x);
	int yu_top(y_position.y), yu_bottom(y_position.y+y_dimmensions.y), yu_left(y_position.x), yu_right(y_position.x+y_dimmensions.x);

	// Determine side of collision and reverse proper direction

	// If the side is not CURRENTLY overlapping, but will be next frame, that's the collision side
	if (me_bottom < yu_top && me_bottom+m_velocity.y >= yu_top)
		m_velocity.y = -1 * m_velocity.y;
	else if (me_top > yu_bottom && me_top+m_velocity.y <= yu_bottom)
		m_velocity.y = -1 * m_velocity.y;
	else if (me_left > yu_right && me_left+m_velocity.x <= yu_right)
		m_velocity.x = -1 * m_velocity.x;
	else if (me_right < yu_left && me_right+m_velocity.x >= yu_left)
		m_velocity.x = -1 * m_velocity.x;
	else  // Sometimes phases through, add some extra checking to make sure all cases are covered
	{
		if ( me_bottom+m_velocity.y > yu_bottom )
			m_velocity.y = -1 * m_velocity.y;
		else if ( me_top+m_velocity.y < yu_top )
			m_velocity.y = -1 * m_velocity.y;
		else if ( me_right+m_velocity.x > yu_right )
			m_velocity.x = -1 * m_velocity.x;
		else if ( me_left+m_velocity.x < yu_left )
			m_velocity.x = -1 * m_velocity.x;
		else  // No matter what, if there was a collision, we're changing directions.
		{
			m_velocity.y = -1 * m_velocity.y;
			m_velocity.x = -1 * m_velocity.x;
		}
	}

	// TODO: Play sound

	return true;
}

// |----------------------------------------------------------------------------|
// |						     PlayerCollide()								|
// |----------------------------------------------------------------------------|
bool Ball::PlayerCollide(Player* collider)
{
	debug("PLAYER COLLISION!");

	Coord collider_position = collider->GetPosition();
	Coord collider_dimmensions = collider->GetDimmensions();

	float direction = (m_position.x+m_dimmensions.x/2)-(collider_position.x+collider_dimmensions.x/2);
	direction /= collider_dimmensions.x;

	m_velocity.x = direction*m_speed;
	m_velocity.y = -1*sqrt(m_speed*m_speed - m_velocity.x*m_velocity.x);

	return true;
}


// |----------------------------------------------------------------------------|
// |								Respawn()									|
// |----------------------------------------------------------------------------|
void Ball::Respawn()
{
	
	m_attached = true;

	return;
}


// |----------------------------------------------------------------------------|
// |						      ColorChange()									|
// |----------------------------------------------------------------------------|
void Ball::ColorChange()
{
	++m_spriteIndex;	
	m_spriteIndex = m_spriteIndex%5;

	if (m_spriteIndex == 0)
		m_graphic = m_green;
	else if (m_spriteIndex == 1)
		m_graphic = m_blue;
	else if (m_spriteIndex == 2)
		m_graphic = m_red;
	else if (m_spriteIndex == 3)
		m_graphic = m_orange;
	else if (m_spriteIndex == 4)
		m_graphic = m_yellow;

	return;
}

