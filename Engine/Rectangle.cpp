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
Rectangle::Rectangle() :
	m_position(0,0),
	m_velocity(0,0),
	m_dimmensions(0,0),
	m_graphic(0),
	m_error(0)
{		
	debug ("Rectangle: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Rectangle::~Rectangle() {
	delete m_graphic;	
	debug ("Rectangle: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool Rectangle::Initialize() {

	debug ("Rectangle: object initialized.");

	return true;
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the screen or level.
int Rectangle::draw() {
	debug ("Rectangle: draw() called.", 10);

	// Draw the rectangle's image
	if (m_graphic)
		(GraphicsClass::GetInstance())->BitmapRender(*m_graphic, m_position.x, m_position.y);

	return m_error;
}


// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int Rectangle::logic(int mouse_x, int mouse_y) {
	debug ("Rectangle: logic() called.", 10);

	// Move based on velocity
	//if(m_velocity.x || m_velocity.y) setPosition(m_position+m_velocity);

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							    onMouseDown()								|
// |----------------------------------------------------------------------------|
int Rectangle::onMouseDown(int button) {
	debug ("Rectangle: onMouseDown() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							     onMouseUp()								|
// |----------------------------------------------------------------------------|
int Rectangle::onMouseUp(int button) {
	debug ("Rectangle: onMouseUp() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							     onKeyDown()								|
// |----------------------------------------------------------------------------|
int Rectangle::onKeyDown(int button) {
	debug ("Rectangle: onKeyDown() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							      onKeyUp() 		 						|
// |----------------------------------------------------------------------------|
int Rectangle::onKeyUp(int button) {
	debug ("Rectangle: onKeyUp() called.");

	return m_error;
}

// |----------------------------------------------------------------------------|
// |							    setPosition() 		 						|
// |----------------------------------------------------------------------------|
void Rectangle::setPosition(Coord new_position) {
	debug ("Rectangle: setPosition() called.");

	m_position = new_position;

}