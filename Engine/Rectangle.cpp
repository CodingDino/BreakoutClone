// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Circle
//		Governs movement, collision detection, and drawing for a 
//      circle object. 

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Rectangle.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
RectangleClass::RectangleClass() :
	m_position(0,0),
	m_velocity(0,0),
	m_dimmensions(0,0),
	m_graphic(0),
	m_error(0)
{		
	debug ("RectangleClass: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
RectangleClass::~RectangleClass() {
	delete m_graphic;	
	debug ("RectangleClass: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool RectangleClass::Initialize() {

	debug ("RectangleClass: object initialized.");

	return true;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the screen or level.
int RectangleClass::draw() {
	debug ("RectangleClass: draw() called.", 10);

	// Draw the rectangle's image
	if (m_graphic)
		(GraphicsClass::GetInstance())->BitmapRender(*m_graphic, (int)m_position.x, (int)m_position.y);

	return m_error;
}


// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int RectangleClass::logic(int mouse_x, int mouse_y) {
	debug ("RectangleClass: logic() called.", 10);

	// Move based on velocity
	//if(m_velocity.x || m_velocity.y) setPosition(m_position+m_velocity);

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							    onMouseDown()								|
// |----------------------------------------------------------------------------|
int RectangleClass::onMouseDown(int button) {
	debug ("RectangleClass: onMouseDown() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							     onMouseUp()								|
// |----------------------------------------------------------------------------|
int RectangleClass::onMouseUp(int button) {
	debug ("RectangleClass: onMouseUp() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							     onKeyDown()								|
// |----------------------------------------------------------------------------|
int RectangleClass::onKeyDown(int button) {
	debug ("RectangleClass: onKeyDown() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							      onKeyUp() 		 						|
// |----------------------------------------------------------------------------|
int RectangleClass::onKeyUp(int button) {
	debug ("RectangleClass: onKeyUp() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							    Collide()									|
// |----------------------------------------------------------------------------|
bool RectangleClass::Collision(RectangleClass* collider)
{

	if(CheckCollision(collider))
	{
		debug("COLLISION!");
		collider->HandleCollision(this);
		HandleCollision(collider);
		return true;
	}

	return false;
}

// |----------------------------------------------------------------------------|
// |						    CheckCollision()								|
// |----------------------------------------------------------------------------|
bool RectangleClass::CheckCollision(RectangleClass* collider)
{
	return !(	((m_position.y+m_dimmensions.y) < collider->m_position.y) || 
				((m_position.x+m_dimmensions.x) < collider->m_position.x) || 
				(m_position.y > (collider->m_position.y+collider->m_dimmensions.y)) || 
				(m_position.x > (collider->m_position.x+collider->m_dimmensions.x)) 
			);
}

// |----------------------------------------------------------------------------|
// |						    HandleCollision()								|
// |----------------------------------------------------------------------------|
bool RectangleClass::HandleCollision(RectangleClass* collider)
{
	return true;
}

