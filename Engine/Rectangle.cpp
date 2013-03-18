// Breakout - Or A Clone Thereof
// Developed for Ninja Kiwi
// Author: Sarah Herzog
//
// Rectangle
//		Governs movement, collision detection, and drawing for a 
//      Rectangle object. 

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
	m_graphic(0)
{		
	debug ("RectangleClass: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							  Copy Constructor								|
// |----------------------------------------------------------------------------|
RectangleClass::RectangleClass(const RectangleClass&) {
	debug ("RectangleClass: object copied.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
RectangleClass::~RectangleClass() {
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
// |							    Shutdown									|
// |----------------------------------------------------------------------------|
bool RectangleClass::Shutdown() {

    // Cleanup dynamic data members
    if (m_graphic)
    {
        m_graphic->Shutdown();
        delete m_graphic;
        m_graphic = 0;
    }

	debug ("RectangleClass: object shutdown.");
	return true;
}


// |----------------------------------------------------------------------------|
// |							     Draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the screen or level.
bool RectangleClass::Draw() {
	debug ("RectangleClass: draw() called.", 10);

	// Draw the rectangle's image
	if (m_graphic)
		(GraphicsClass::GetInstance())->BitmapRender(*m_graphic, (int)m_position.x, (int)m_position.y);

	return true;
}


// |----------------------------------------------------------------------------|
// |							    Logic()										|
// |----------------------------------------------------------------------------|
bool RectangleClass::Logic() {
	debug ("RectangleClass: Logic() called.", 10);

	return true;
}


// |----------------------------------------------------------------------------|
// |							   Collision()									|
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
	return !(	((m_position.y+m_dimmensions.y+m_velocity.y) < collider->m_position.y+collider->m_velocity.y) || 
				((m_position.x+m_dimmensions.x+m_velocity.x) < collider->m_position.x+collider->m_velocity.x) || 
				(m_position.y+m_velocity.y > (collider->m_position.y+collider->m_dimmensions.y+collider->m_velocity.y)) || 
				(m_position.x+m_velocity.x > (collider->m_position.x+collider->m_dimmensions.x+collider->m_velocity.x)) 
			);
}


// |----------------------------------------------------------------------------|
// |						    HandleCollision()								|
// |----------------------------------------------------------------------------|
bool RectangleClass::HandleCollision(RectangleClass* collider)
{
	return true;
}

