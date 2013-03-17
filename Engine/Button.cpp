// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Button
//		Defines the screen change button's location, text, image, and function. 


// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Button.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Button::Button() 
{
	

	debug ("Button: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Button::~Button() {
	debug ("ScreenChangeButton: instance destroyed.");
}

// |----------------------------------------------------------------------------|
// |							   Initialize									|
// |----------------------------------------------------------------------------|
bool Button::Initialize(Screen* parent, SCREEN nextScreen, WCHAR* textureFilename) {

	// Record parent
	m_parent = parent;

	// Set dimmensions
	m_dimmensions.x = 178*SCALE_X;
	m_dimmensions.y = 76*SCALE_Y;

	// Set click to screen
	m_nextScreen = nextScreen;
	
	// Loading graphics into Image objects
	m_graphic = new BitmapClass();
	m_graphic->Initialize((D3DClass::GetInstance())->GetDevice(), SCREEN_WIDTH, SCREEN_HEIGHT, textureFilename, m_dimmensions.x, m_dimmensions.y);
	
	debug ("Button: object initialized.");

	return true;
}


// |----------------------------------------------------------------------------|
// |						    HandleCollision()								|
// |----------------------------------------------------------------------------|
bool Button::HandleCollision(RectangleClass* collider)
{
	
	if (m_hp > 0 ) --m_hp;

	// TODO: Increment score if dead;
	if (m_hp <= 0)
	{
		// Change the next screen to this button's target screen
		m_parent->setNextScreen(m_nextScreen);
		m_parent->setDone(true);
	}

	return true;
}